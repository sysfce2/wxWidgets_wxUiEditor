/////////////////////////////////////////////////////////////////////////////
// Purpose:   Generate C++ Base code files
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2024 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"

#include "file_codewriter.h"  // FileCodeWriter -- Classs to write code to disk
#include "gen_base.h"         // BaseCodeGenerator -- Generate Base class
#include "gen_results.h"      // Code generation file writing functions
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler class
#include "write_code.h"       // Write code to Scintilla or file

using namespace code;

struct GenData
{
    GenData(GenResults& results, std::vector<tt_string>* pClassList)
    {
        this->presults = &results;
        this->pClassList = pClassList;
    }

    GenResults* presults { nullptr };
    std::vector<tt_string>* pClassList { nullptr };
    tt_string source_ext;
    tt_string header_ext;

    void AddUpdateFilename(tt_string& path) { presults->updated_files.emplace_back(path); };

    void AddResultMsg(tt_string& msg) { presults->msgs.emplace_back(msg); };

    void UpdateFileCount() { presults->file_count += 1; };

    void AddClassName(const tt_string& class_name)
    {
        if (pClassList)
        {
            pClassList->emplace_back(class_name);
        }
    };
};

static void GenCppForm(GenData& gen_data, Node* form)
{
    // These are just defined for convenience.
    tt_string& source_ext = gen_data.source_ext;
    tt_string& header_ext = gen_data.header_ext;

    auto [path, has_base_file] = Project.GetOutputPath(form, GEN_LANG_CPLUSPLUS);
    if (!has_base_file)
    {
        tt_string msg("No filename specified for ");
        if (form->hasValue(prop_class_name))
            msg += form->as_string(prop_class_name);
        else
            msg += map_GenNames[form->getGenName()];
        msg += '\n';
        gen_data.AddResultMsg(msg);
        return;
    }

    BaseCodeGenerator codegen(GEN_LANG_CPLUSPLUS, form);

    path.replace_extension(header_ext);
    auto h_cw = std::make_unique<FileCodeWriter>(path);
    codegen.SetHdrWriteCode(h_cw.get());

    path.replace_extension(source_ext);
    auto cpp_cw = std::make_unique<FileCodeWriter>(path);
    codegen.SetSrcWriteCode(cpp_cw.get());

    codegen.GenerateCppClass();

    path.replace_extension(header_ext);

    int flags = flag_no_ui;
    if (gen_data.pClassList)
        flags |= flag_test_only;
    if (form->as_bool(prop_no_closing_brace))
        flags |= flag_add_closing_brace;
    auto retval = h_cw->WriteFile(GEN_LANG_CPLUSPLUS, flags);
    if (form->as_bool(prop_no_closing_brace))
        flags = flags & ~flag_add_closing_brace;

    if (retval > 0)
    {
        if (!gen_data.pClassList)
        {
            gen_data.AddUpdateFilename(path);
        }
        else
        {
            if (form->isGen(gen_Images))
            {
                // While technically this is a "form" it doesn't have the usual properties set
                gen_data.AddClassName(GenEnum::map_GenNames[gen_Images]);
            }
            else if (form->isGen(gen_Data))
            {
                gen_data.AddClassName(GenEnum::map_GenNames[gen_Data]);
            }
            else
            {
                gen_data.AddClassName(form->as_string(prop_class_name));
            }
            return;
        }
    }
    else if (retval < 0)
    {
        gen_data.AddResultMsg(tt_string() << "Cannot create or write to the file " << path << '\n');
    }
    else  // retval == result::exists)
    {
        gen_data.UpdateFileCount();
    }

    path.replace_extension(source_ext);
    retval = cpp_cw->WriteFile(GEN_LANG_CPLUSPLUS, flags);

    if (retval > 0)
    {
        if (!gen_data.pClassList)
        {
            gen_data.AddUpdateFilename(path);
        }
        else
        {
            if (form->isGen(gen_Images))
            {
                // While technically this is a "form" it doesn't have the usual properties set
                gen_data.AddClassName("Images List");
            }
            else if (form->isGen(gen_Data))
            {
                gen_data.AddClassName("Data List");
            }
            else
            {
                gen_data.AddClassName(form->as_string(prop_class_name));
            }
            return;
        }
    }

    else if (retval < 0)
    {
        gen_data.AddResultMsg(tt_string() << "Cannot create or write to the file " << path << '\n');
    }
    else  // retval == result::exists
    {
        gen_data.UpdateFileCount();
    }
}

bool GenerateCodeFiles(GenResults& results, std::vector<tt_string>* pClassList)
{
    if (Project.getChildCount() == 0)
    {
        wxMessageBox("You cannot generate any code until you have added a top level form.", "Code Generation");
        return false;
    }
    tt_cwd cwd(true);
    Project.ChangeDir();

#if defined(_DEBUG) || defined(INTERNAL_TESTING)
    results.StartClock();
#endif

    if (Project.as_bool(prop_generate_cmake))
    {
        auto is_testing = pClassList ? 1 : 0;
        for (auto& iter: Project.getChildNodePtrs())
        {
            if (iter->isGen(gen_folder) && iter->hasValue(prop_folder_cmake_file))
            {
                auto result = WriteCMakeFile(iter.get(), results.updated_files, results.msgs, is_testing);
                if (result == result::created || result == result::needs_writing)
                {
                    ++results.file_count;
                    pClassList->emplace_back(iter.get()->as_string(prop_cmake_file));
                }
            }
        }
        if (Project.hasValue(prop_cmake_file))
        {
            auto result = WriteCMakeFile(Project.getProjectNode(), results.updated_files, results.msgs, is_testing);
            if (result == result::created || result == result::needs_writing)
            {
                ++results.file_count;
                if (is_testing)
                {
                    pClassList->emplace_back(Project.getProjectNode()->as_string(prop_cmake_file));
                }
            }
        }
    }

    tt_string path;

    tt_string source_ext(".cpp");
    tt_string header_ext(".h");

    if (auto& extProp = Project.as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto& extProp = Project.as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    std::vector<Node*> forms;
    Project.CollectForms(forms);
    Project.FindWxueFunctions(forms);

    GenData gen_data(results, pClassList);
    gen_data.source_ext = source_ext;
    gen_data.header_ext = header_ext;

    for (const auto& form: forms)
    {
        GenCppForm(gen_data, form);
    }

#if defined(_DEBUG) || defined(INTERNAL_TESTING)
    results.EndClock();
#endif

    if (pClassList)
        return pClassList->size() > 0;
    else
        return results.updated_files.size() > 0;
}

void GenInhertedClass(GenResults& results)
{
    tt_cwd cwd;
    Project.ChangeDir();
    tt_string path;

    tt_string source_ext(".cpp");
    tt_string header_ext(".h");

    if (auto& extProp = Project.as_string(prop_source_ext); extProp.size())
    {
        source_ext = extProp;
    }

    if (auto extProp = Project.as_string(prop_header_ext); extProp.size())
    {
        header_ext = extProp;
    }

    std::vector<Node*> forms;
    Project.CollectForms(forms);

    for (const auto& form: forms)
    {
        if (auto& file = form->as_string(prop_derived_file); file.size())
        {
            path = Project.getDerivedFilename(form);
            if (path.empty())
                continue;
            if (path.file_exists())
            {
                // Count both source and header file
                path.replace_extension(header_ext);
                if (path.file_exists())
                {
                    results.file_count += 2;
                    continue;
                }
                else
                {
                    ++results.file_count;
                }
            }
        }
        else
        {
            continue;
        }

        BaseCodeGenerator codegen(GEN_LANG_CPLUSPLUS, form);

        path.replace_extension(header_ext);
        auto h_cw = std::make_unique<FileCodeWriter>(path);
        codegen.SetHdrWriteCode(h_cw.get());

        path.replace_extension(source_ext);
        auto cpp_cw = std::make_unique<FileCodeWriter>(path);
        codegen.SetSrcWriteCode(cpp_cw.get());

        auto retval = codegen.GenerateDerivedClass(Project.getProjectNode(), form);
        if (retval == result::fail)
        {
            results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
            continue;
        }
        else if (retval == result::exists)
        {
            path.replace_extension(header_ext);
            if (path.file_exists())
            {
                ++results.file_count;
                continue;
            }

            // If we get here, the source file exists, but the header file does not.
            int flags = flag_no_ui;
            if (form->as_bool(prop_no_closing_brace))
                flags |= flag_add_closing_brace;
            retval = h_cw->WriteFile(GEN_LANG_CPLUSPLUS, flags);
            if (retval == result::fail)
            {
                results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
            }
            else if (retval == result::exists)
            {
                ++results.file_count;
            }
            else
            {
                results.updated_files.emplace_back(path);
            }
            continue;
        }
        else if (retval == result::ignored)
        {
            // Completely ignore this file
            continue;
        }

        path.replace_extension(header_ext);
        if (path.file_exists())
        {
            retval = result::exists;
        }
        else
        {
            int flags = flag_no_ui;
            if (form->as_bool(prop_no_closing_brace))
                flags |= flag_add_closing_brace;

            retval = h_cw->WriteFile(GEN_LANG_CPLUSPLUS, flags);
        }

        if (retval == result::fail)
        {
            results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
        }
        else if (retval == result::exists)
        {
            ++results.file_count;
        }
        else
        {
            results.updated_files.emplace_back(path);
        }

        path.replace_extension(source_ext);
        retval = cpp_cw->WriteFile(GEN_LANG_CPLUSPLUS, flag_no_ui);
        if (retval == result::fail)
        {
            results.msgs.emplace_back() << "Cannot create or write to the file " << path << '\n';
        }
        else if (retval == result::exists)
        {
            ++results.file_count;
        }
        else
        {
            results.updated_files.emplace_back(path);
        }
    }
}

#include "pugixml.hpp"

void GenerateTmpFiles(const std::vector<tt_string>& ClassList, pugi::xml_node root, int language)
{
    tt_cwd cwd(true);
    Project.ChangeDir();
    std::vector<tt_string> results;

    tt_string source_ext(".cpp");
    tt_string header_ext(".h");

    if (language == GEN_LANG_CPLUSPLUS)
    {
        if (auto& extProp = Project.as_string(prop_source_ext); extProp.size())
        {
            source_ext = extProp;
        }
        else
        {
            source_ext = ".cpp";
        }
        if (auto& extProp = Project.as_string(prop_header_ext); extProp.size())
        {
            header_ext = extProp;
        }
        else
        {
            header_ext = ".h";
        }
    }
    else if (language == GEN_LANG_PYTHON)
    {
        source_ext = ".py";
        header_ext = ".py";
    }
    else if (language == GEN_LANG_RUBY)
    {
        source_ext = ".rb";
        header_ext = ".rb";
    }

    std::vector<Node*> forms;
    if (ClassList.size())
    {
        if (ClassList[0].ends_with(".cmake"))
            forms.emplace_back(Project.getProjectNode());
    }

    Project.CollectForms(forms);

    for (auto& iter_class: ClassList)
    {
        for (const auto& form: forms)
        {
            // The Images class doesn't have a prop_class_name, so use "Images". Note that this will fail if there is a
            // real form where the user set the class name to "Images". If this wasn't an Internal function, then we
            // would need to store nodes rather than class names.

            tt_string class_name(form->as_string(prop_class_name));
            if (form->isGen(gen_Project))
            {
                if (language != GEN_LANG_CPLUSPLUS)
                    continue;
                tt_string path = Project.getProjectPath() + Project.getProjectNode()->as_string(prop_cmake_file);
                path.make_absolute();
                tt_string tmp_path(path);
                if (auto pos_file = path.find_filename(); tt::is_found(pos_file))
                {
                    tmp_path.insert(pos_file, "~wxue_");
                }
                else
                {
                    ASSERT(tmp_path.size())
                    tmp_path.insert(0, "~wxue_");
                }

                // We need to tweak the call to WriteCMakeFile() to get it to write to our temporary .cmake file.
                std::vector<tt_string> updated_files;
                std::vector<tt_string> dummy;
                updated_files.emplace_back(tmp_path);
                WriteCMakeFile(Project.getProjectNode(), updated_files, dummy, 2);

                auto paths = root.append_child("paths");

                // Use absolute path and leave the backslashes alone because WinMerge
                // doesn't understand forward slashes (even though Windows does).
                path.make_absolute();
                paths.append_child("left").text().set(path.c_str());
                paths.append_child("left-readonly").text().set("0");

                tmp_path.make_absolute();
                paths.append_child("right").text().set(tmp_path.c_str());
                paths.append_child("right-readonly").text().set("1");
                continue;
            }
            else if (form->isGen(gen_Images))
            {
                if (language != GEN_LANG_CPLUSPLUS)
                    continue;
                class_name = "Images List";
            }
            else if (form->isGen(gen_Data))
            {
                if (language != GEN_LANG_CPLUSPLUS)
                    continue;
                class_name = "Data List";
            }

            if (class_name.is_sameas(iter_class))
            {
                auto [path, has_base_file] = Project.GetOutputPath(form, language);
                if (!has_base_file)
                    continue;

                BaseCodeGenerator codegen(language, form);

                path.replace_extension(header_ext);
                auto h_cw = std::make_unique<FileCodeWriter>(path);
                codegen.SetHdrWriteCode(h_cw.get());

                path.replace_extension(source_ext);
                auto cpp_cw = std::make_unique<FileCodeWriter>(path);
                codegen.SetSrcWriteCode(cpp_cw.get());

                if (language == GEN_LANG_CPLUSPLUS)
                {
                    codegen.GenerateCppClass();
                }
                else if (language == GEN_LANG_PYTHON)
                {
                    codegen.GeneratePythonClass();
                }
                else if (language == GEN_LANG_RUBY)
                {
                    cpp_cw->SetTabToSpaces(2);
                    codegen.GenerateRubyClass();
                }

                bool new_hdr = false;
                if (language == GEN_LANG_CPLUSPLUS)
                {
                    // Currently, only C++ generates code from h_cw
                    new_hdr = (h_cw->WriteFile(GEN_LANG_CPLUSPLUS, flag_test_only) > 0);
                }

                bool new_src = (cpp_cw->WriteFile(language, flag_test_only) > 0);

                if (new_hdr || new_src)
                {
                    tt_string tmp_path(path);
                    if (auto pos_file = path.find_filename(); tt::is_found(pos_file))
                    {
                        tmp_path.insert(pos_file, "~wxue_");
                    }
                    else
                    {
                        ASSERT(tmp_path.size())
                        tmp_path.insert(0, "~wxue_");
                    }

                    BaseCodeGenerator new_codegen(language, form);

                    tmp_path.replace_extension(header_ext);
                    h_cw = std::make_unique<FileCodeWriter>(tmp_path);
                    new_codegen.SetHdrWriteCode(h_cw.get());

                    tmp_path.replace_extension(source_ext);
                    cpp_cw = std::make_unique<FileCodeWriter>(tmp_path);
                    new_codegen.SetSrcWriteCode(cpp_cw.get());

                    if (language == GEN_LANG_CPLUSPLUS)
                    {
                        new_codegen.GenerateCppClass();
                    }
                    else if (language == GEN_LANG_PYTHON)
                    {
                        new_codegen.GeneratePythonClass();
                    }
                    else if (language == GEN_LANG_RUBY)
                    {
                        cpp_cw->SetTabToSpaces(2);
                        new_codegen.GenerateRubyClass();
                    }

                    // WinMerge accepts an XML file the provides the left and right filenames
                    // to compare. After we write a file, we update the XML file with the
                    // name pair.

                    if (new_hdr)
                    {
                        auto paths = root.append_child("paths");
                        tmp_path.replace_extension(header_ext);
                        h_cw->WriteFile(language, flag_no_ui);
                        path.replace_extension(header_ext);

                        // Use absolute path and leave the backslashes alone because WinMerge
                        // doesn't understand forward slashes (even though Windows does).
                        path.make_absolute();
                        paths.append_child("left").text().set(path.c_str());
                        paths.append_child("left-readonly").text().set("0");

                        tmp_path.make_absolute();
                        paths.append_child("right").text().set(tmp_path.c_str());
                        paths.append_child("right-readonly").text().set("1");
                    }
                    if (new_src)
                    {
                        auto paths = root.append_child("paths");
                        tmp_path.replace_extension(source_ext);
                        cpp_cw->WriteFile(language, flag_no_ui);
                        path.replace_extension(source_ext);

                        // Use absolute path and leave the backslashes alone because WinMerge
                        // doesn't understand forward slashes (even though Windows does).
                        path.make_absolute();
                        paths.append_child("left").text().set(path.c_str());
                        paths.append_child("left-readonly").text().set("0");

                        tmp_path.make_relative(Project.getProjectPath());
                        tmp_path.make_absolute();
                        paths.append_child("right").text().set(tmp_path.c_str());
                        paths.append_child("right-readonly").text().set("1");
                    }
                }
            }
        }
    }
}
