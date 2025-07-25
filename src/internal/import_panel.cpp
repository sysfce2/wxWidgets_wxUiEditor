/////////////////////////////////////////////////////////////////////////////
// Purpose:   Panel to display original imported file
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022-2025 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/fdrepdlg.h>  // wxFindReplaceDialog class
#include <wx/scrolwin.h>  // wxScrolledWindow, wxScrolledControl and wxScrollHelper
#include <wx/sizer.h>     // provide wxSizer class for layout
#include <wx/stc/stc.h>   // A wxWidgets implementation of Scintilla.

#include "import_panel.h"

#include "cstm_event.h"  // CustomEvent -- Custom Event class
#include "mainapp.h"     // App -- Main application class
#include "mainframe.h"   // MainFrame -- Main window frame
#include "pugixml.hpp"   // xml read/write/create/process

#include "../panels/propgrid_panel.h"  // PropGridPanel -- PropertyGrid class for node properties and events
#include "node.h"                      // Node class
#include "utils.h"                     // Utility functions that work with properties

#ifndef SCI_SETKEYWORDS
    #define SCI_SETKEYWORDS 4005
#endif

// Keywords are defined in gen_xrc_utils.cpp so they can easily be updated as XRC generators
// support more XRC controls.
extern const char* g_xrc_keywords;

const int node_marker = 1;

ImportPanel::ImportPanel(wxWindow* parent) : wxScrolled<wxPanel>(parent)
{
    auto parent_sizer = new wxBoxSizer(wxVERTICAL);
    m_scintilla = new wxStyledTextCtrl(this, wxID_ANY);

    // TODO: [KeyWorks - 01-02-2022] We do this because currently font selection uses a facename
    // which is not cross-platform. See issue #597.
    wxFont font(10, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    m_scintilla->StyleSetFont(wxSTC_STYLE_DEFAULT, font);

    // These are settings used in codedisplay_base
    m_scintilla->SetWrapMode(wxSTC_WRAP_WHITESPACE);
    m_scintilla->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_END);
    m_scintilla->SetWrapVisualFlagsLocation(wxSTC_WRAPVISUALFLAGLOC_END_BY_TEXT);
    m_scintilla->SetWrapIndentMode(wxSTC_WRAPINDENT_INDENT);
    // Sets text margin scaled appropriately for the current DPI on Windows,
    // 5 on wxGTK or wxOSX
    m_scintilla->SetMarginLeft(wxSizerFlags::GetDefaultBorder());
    m_scintilla->SetMarginRight(wxSizerFlags::GetDefaultBorder());
    m_scintilla->SetMarginWidth(1, 0);  // Remove default margin
    m_scintilla->SetMarginWidth(0, 16);
    m_scintilla->SetMarginType(0, wxSTC_MARGIN_SYMBOL);
    m_scintilla->SetMarginMask(0, ~wxSTC_MASK_FOLDERS);
    m_scintilla->SetMarginSensitive(0, false);
    m_scintilla->SetIndentationGuides(wxSTC_IV_REAL);
    m_scintilla->SetUseTabs(false);
    m_scintilla->SetTabWidth(4);
    m_scintilla->SetBackSpaceUnIndents(true);

    SetStcColors(m_scintilla, GEN_LANG_XRC);

    m_scintilla->MarkerDefine(node_marker, wxSTC_MARK_BOOKMARK, wxNullColour, *wxGREEN);
    parent_sizer->Add(m_scintilla, wxSizerFlags(1).Expand().Border(wxALL));

    Bind(wxEVT_FIND, &ImportPanel::OnFind, this);
    Bind(wxEVT_FIND_NEXT, &ImportPanel::OnFind, this);

    SetSizerAndFit(parent_sizer);
}

void ImportPanel::SetImportFile(const tt_string& file, int lexer)
{
    m_view.clear();
    m_view.GetBuffer().clear();
    if (!m_view.ReadFile(file) && !m_view.ReadFile(file.filename()))
    {
        FAIL_MSG(tt_string("Can't read ") << file);
        return;
    }

    m_lexer = lexer;
    m_scintilla->SetLexer(lexer);
    m_import_file = file;
    m_scintilla->SetTabWidth(4);

    switch (lexer)
    {
        case wxSTC_LEX_XML:
            // This uses the XRC keywords, which will generally be fine for XRC, wxSMith, and
            // wxGlade. wxFormBuilder could probably use some extra keywords...

            {
                pugi::xml_document doc;
                if (auto result = doc.load_file_string(file); result)
                {
                    std::set<tt_string> keywords;
                    auto root = doc.first_child();
                    keywords.insert(root.name());
                    for (auto& iter: root.attributes())
                    {
                        keywords.insert(iter.name());
                    }

                    auto add_keywords = [&](pugi::xml_node node, auto&& add_keywords) -> void
                    {
                        keywords.insert(node.name());
                        for (auto& iter: node.attributes())
                        {
                            keywords.insert(iter.name());
                        }
                        for (auto child: node.children())
                        {
                            add_keywords(child, add_keywords);
                        }
                    };

                    for (auto child: root.children())
                    {
                        add_keywords(child, add_keywords);
                    }

                    tt_string keywords_str;
                    for (auto& iter: keywords)
                    {
                        keywords_str << iter << " ";
                    }

                    m_scintilla->SendMsg(SCI_SETKEYWORDS, 0, (wxIntPtr) keywords_str.c_str());
                }
                else
                {
                    m_scintilla->SendMsg(SCI_SETKEYWORDS, 0, (wxIntPtr) g_xrc_keywords);
                }
            }

            m_scintilla->StyleSetBold(wxSTC_H_TAG, true);
            SetStcColors(m_scintilla, GEN_LANG_XML, false, false);
            break;

        case wxSTC_LEX_CPP:
            // TODO: [Randalphwa - 06-17-2022] wxSTC_LEX_CPP is used for Windows Resource files, so
            // RC keywords are needed...

            // On Windows, this saves converting the UTF8 to UTF16 and then back to ANSI.
            // m_scintilla->SendMsg(SCI_SETKEYWORDS, 0, (wxIntPtr) g_u8_cpp_keywords);

            m_scintilla->StyleSetBold(wxSTC_C_WORD, true);
            SetStcColors(m_scintilla, GEN_LANG_CPLUSPLUS, false, false);
            break;

        case wxSTC_LEX_JSON:
            // TODO: [Randalphwa - 06-17-2022] Keywords specific to wxCrafter would probably be
            // useful....

            // On Windows, this saves converting the UTF8 to UTF16 and then back to ANSI.
            m_scintilla->SendMsg(SCI_SETKEYWORDS, 0, (wxIntPtr) g_xrc_keywords);

            m_scintilla->StyleSetBold(wxSTC_H_TAG, true);
            SetStcColors(m_scintilla, GEN_LANG_XML, false, false);
            break;

        default:
            FAIL_MSG(tt_string("Unsupported lexer: ") << lexer);
            break;
    }

    m_scintilla->SetReadOnly(false);
    m_scintilla->ClearAll();
    m_scintilla->AddTextRaw(m_view.GetBuffer().data(), (to_int) m_view.GetBuffer().size());
    m_scintilla->SetReadOnly(true);

    // Find doesn't work correctly unless there's a selection to start the search from.
    m_scintilla->SetEmptySelection(0);
}

void ImportPanel::OnFind(wxFindDialogEvent& event)
{
    auto wxflags = event.GetFlags();
    int sciflags = 0;

    if (wxflags & wxFR_WHOLEWORD)
    {
        sciflags |= wxSTC_FIND_WHOLEWORD;
    }
    if (wxflags & wxFR_MATCHCASE)
    {
        sciflags |= wxSTC_FIND_MATCHCASE;
    }

    int result;
    if (wxflags & wxFR_DOWN)
    {
        m_scintilla->SetSelectionStart(m_scintilla->GetSelectionEnd());
        m_scintilla->SearchAnchor();
        result = m_scintilla->SearchNext(sciflags, event.GetFindString());
    }
    else
    {
        m_scintilla->SetSelectionEnd(m_scintilla->GetSelectionStart());
        m_scintilla->SearchAnchor();
        result = m_scintilla->SearchPrev(sciflags, event.GetFindString());
    }

    if (result == wxSTC_INVALID_POSITION)
    {
        wxMessageBox(wxString() << event.GetFindString() << " not found.", "Not Found",
                     wxICON_ERROR, wxStaticCast(event.GetClientData(), wxWindow));
    }
    else
    {
        m_scintilla->EnsureCaretVisible();
    }
}

void ImportPanel::Clear()
{
    m_view.clear();
    m_view.GetBuffer().clear();

    m_scintilla->SetReadOnly(false);
    m_scintilla->ClearAll();
}

void ImportPanel::OnNodeSelected(Node* node)
{
    // Find where the node is created.
    tt_string name(" ");
    name << node->as_string(prop_var_name);
    int line = 0;

    tt_string search;
    if (m_lexer == wxSTC_LEX_JSON || m_import_file.has_extension(".pjd"))
    {
        search = "\"";
    }
    else
    {
        search = "name=\"";
    }
    if (node->hasProp(prop_id) && node->as_string(prop_id) != "wxID_ANY")
    {
        search << node->as_string(prop_id);
        if (auto pos = search.find('='); tt::is_found(pos))
        {
            search.erase(pos - 1, search.size() - pos + 1);
        }
    }
    else if (node->hasValue(prop_var_name))
    {
        search << node->as_string(prop_var_name);
    }
    else
    {
        search << node->as_string(prop_class_name);
    }
    line = (to_int) m_view.FindLineContaining(search);

    if (!tt::is_found(line) && m_import_file.has_extension(".pjd") && node->hasValue(prop_var_name))
    {
        search = "\"" + node->as_string(prop_var_name);
        line = (to_int) m_view.FindLineContaining(search);
    }

    if (!tt::is_found(line) && m_import_file.has_extension(".pjd"))
    {
        search = node->getNodeDeclaration()->declName();
        // DialogBlocks uses wbClassName instead of the expected wxClassName
        if (search.size() > 1 && search[1] == 'x')
            search[1] = 'b';
        line = (to_int) m_view.FindLineContaining(search);
    }

    if (!tt::is_found(line))
    {
        return;
    }

    m_scintilla->MarkerDeleteAll(node_marker);
    m_scintilla->MarkerAdd(line, node_marker);

    // Unlike GetLineVisible(), this function does ensure that the line is visible.
    m_scintilla->ScrollToLine(line);
}
