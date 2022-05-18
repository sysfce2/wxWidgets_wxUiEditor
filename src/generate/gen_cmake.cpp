//////////////////////////////////////////////////////////////////////////
// Purpose:   Auto-generate a .cmake file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2021-2022 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <fstream>

#include "ttcwd.h"       // cwd -- Class for storing and optionally restoring the current directory
#include "tttextfile.h"  // textfile -- Classes for reading and writing line-oriented files

#include "gen_base.h"  // BaseCodeGenerator -- Generate Src and Hdr files for Base Class
#include "mainapp.h"   // App -- Main application class
#include "node.h"      // Node class

int WriteCMakeFile(bool test_only)
{
    auto project = wxGetApp().GetProject();

    if (!project->prop_as_bool(prop_generate_cmake) || !project->HasValue(prop_cmake_file))
    {
        return result::exists;
    }

    ttSaveCwd cwd;

    // The generated files make be in a different directory then the project file, and if so, we
    // need to tread that directory as the root of the file.

    ttlib::cstr cmake_file = project->prop_as_string(prop_cmake_file);
    if (cmake_file.starts_with(".."))
    {
        ttlib::cstr new_dir(cmake_file);
        new_dir.remove_filename();
        ttlib::ChangeDir(new_dir);
    }
    else
    {
        ttlib::ChangeDir(wxGetApp().getProjectPath());
    }

    ttlib::cwd cur_dir;
    cur_dir.make_absolute();

    cmake_file.make_relative(cur_dir);

    ttlib::viewfile current;
    if (!current.ReadFile(cmake_file) && test_only)
    {
        return result::needs_writing;
    }

    ttlib::textfile out;
    out.emplace_back("# Generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/");
    out.emplace_back("#");
    out.emplace_back("# DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!");
    out.emplace_back();

    out.emplace_back();
    out.at(out.size() - 1) << "set (" << project->prop_as_string(prop_cmake_varname);
    out.emplace_back();

    std::set<ttlib::cstr> base_files;

    for (const auto& iter: project->GetChildNodePtrs())
    {
        if (!iter->HasValue(prop_base_file))
            continue;

        base_files.emplace(iter->prop_as_string(prop_base_file));
    }

    for (auto base_file: base_files)
    {
        base_file.make_relative(cur_dir);
        base_file.backslashestoforward();
        base_file.remove_extension();

        ttlib::cstr source_ext(".cpp");
        if (auto& extProp = project->prop_as_string(prop_source_ext); extProp.size())
        {
            source_ext = extProp;
        }
        base_file.replace_extension(source_ext);

        out.emplace_back();
        out.at(out.size() - 1) << "    ${CMAKE_CURRENT_LIST_DIR}/" << base_file;
    }

    out.emplace_back();
    out.emplace_back(")");

    if (out.is_sameas(current))
    {
        return result::exists;
    }

    if (test_only)
    {
        return result::needs_writing;
    }

    out.WriteFile(cmake_file);
    return result::created;
}
