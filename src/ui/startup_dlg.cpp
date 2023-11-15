///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/bmpbndl.h>
#include <wx/button.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/statline.h>

#include "../wxui/ui_images.h"

#include "startup_dlg.h"

#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert compressed SVG string into a wxBitmapBundle
wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size);

namespace wxue_img
{
    extern const unsigned char import_svg[418];
    extern const unsigned char logo_svg[1943];
    // new-project.svg
    extern const unsigned char new_project_svg[921];
}

bool StartupDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    SetIcon(wxueBundleSVG(wxue_img::logo_svg, 1943, 7265, wxSize(16, 16)).GetIconFor(this));

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);

    auto* bmp_4 = new wxStaticBitmap(this, wxID_ANY, wxue_img::bundle_logo_svg(64, 64));
    box_sizer_6->Add(bmp_4, wxSizerFlags().Border(wxALL));

    box_sizer_6->AddSpacer(10 + wxSizerFlags::GetDefaultBorder());

    m_name_version = new wxStaticText(this, wxID_ANY, "wxUiEditor");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        m_name_version->SetFont(font);
    }
    box_sizer_6->Add(m_name_version, wxSizerFlags(1).Center().Border(wxALL));

    dlg_sizer->Add(box_sizer_6, wxSizerFlags(1).Expand().Border(wxALL));

    auto* box_sizer_8 = new wxBoxSizer(wxHORIZONTAL);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* staticText = new wxStaticText(this, wxID_ANY, "Recent");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
        staticText->SetFont(font);
    }
    box_sizer->Add(staticText, wxSizerFlags().Border(wxALL));

    m_staticTextRecentProjects = new wxStaticText(this, wxID_ANY, "Recent projects you have opened will appear here");
    m_staticTextRecentProjects->Wrap(200);
    box_sizer->Add(m_staticTextRecentProjects, wxSizerFlags().Border(wxALL));

    m_recent_flex_grid = new wxFlexGridSizer(2, 0, 0);
    {
        m_recent_flex_grid->AddGrowableCol(1, 1);
        m_recent_flex_grid->SetFlexibleDirection(wxHORIZONTAL);
    }

    box_sizer->Add(m_recent_flex_grid, wxSizerFlags().Border(wxALL));

    box_sizer_8->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto* static_line_2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
    box_sizer_8->Add(static_line_2, wxSizerFlags().Expand().Border(wxALL, FromDIP(wxSize(20, -1)).x));

    auto* box_sizer_2 = new wxBoxSizer(wxVERTICAL);

    auto* staticText_2 = new wxStaticText(this, wxID_ANY, "Start");
    {
        wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
        font.SetSymbolicSize(wxFONTSIZE_X_LARGE);
        font.SetWeight(wxFONTWEIGHT_SEMIBOLD);
        staticText_2->SetFont(font);
    }
    box_sizer_2->Add(staticText_2, wxSizerFlags().Border(wxALL));

    auto* box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);

    auto* bmp_2 = new wxStaticBitmap(this, wxID_ANY, wxArtProvider::GetBitmapBundle(wxART_FILE_OPEN, wxART_TOOLBAR));
    box_sizer_4->Add(bmp_2, wxSizerFlags().Border(wxALL));

    auto* hyperlink_2 = new wxGenericHyperlinkCtrl(this, wxID_ANY, "Open...", wxEmptyString);
    hyperlink_2->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    box_sizer_4->Add(hyperlink_2, wxSizerFlags().Center().Border(wxALL));

    box_sizer_2->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    auto* bmp = new wxStaticBitmap(this, wxID_ANY, wxue_img::bundle_import_svg(24, 24));
    box_sizer_3->Add(bmp, wxSizerFlags().Border(wxALL));

    auto* hyperlink = new wxGenericHyperlinkCtrl(this, wxID_ANY, "Import...", wxEmptyString);
    hyperlink->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    box_sizer_3->Add(hyperlink, wxSizerFlags().Center().Border(wxALL));

    box_sizer_2->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);

    auto* bmp_3 = new wxStaticBitmap(this, wxID_ANY, wxueBundleSVG(wxue_img::new_project_svg, 921, 2208, wxSize(24, 24)));
    box_sizer_5->Add(bmp_3, wxSizerFlags().Border(wxALL));

    auto* hyperlink_3 = new wxGenericHyperlinkCtrl(this, wxID_ANY, "New", wxEmptyString);
    hyperlink_3->SetFont(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
    box_sizer_5->Add(hyperlink_3, wxSizerFlags().Center().Border(wxALL));

    box_sizer_2->Add(box_sizer_5, wxSizerFlags().Border(wxALL));

    box_sizer_8->Add(box_sizer_2, wxSizerFlags().Border(wxLEFT|wxRIGHT, 15));

    dlg_sizer->Add(box_sizer_8, wxSizerFlags().Border(wxALL));

    auto* box_sizer_7 = new wxBoxSizer(wxVERTICAL);

    auto* static_line = new wxStaticLine(this);
    box_sizer_7->Add(static_line, wxSizerFlags().Expand().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxCANCEL|wxNO_DEFAULT);
    stdBtn->GetCancelButton()->SetDefault();
    box_sizer_7->Add(stdBtn, wxSizerFlags(1).Center().Border(wxALL));

    dlg_sizer->Add(box_sizer_7, wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    hyperlink_2->Bind(wxEVT_HYPERLINK, &StartupDlg::OnOpen, this);
    hyperlink->Bind(wxEVT_HYPERLINK, &StartupDlg::OnImport, this);
    hyperlink_3->Bind(wxEVT_HYPERLINK, &StartupDlg::OnNew, this);
    Bind(wxEVT_INIT_DIALOG, &StartupDlg::OnInit, this);

    return true;
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////////////////////////////////////////////////////////////////
// Purpose:   Dialog to display if wxUiEditor is launched with no arguments
// Author:    Ralph Walden
// Copyright: Copyright (c) 2022-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // MainFrame -- Main window frame

void StartupDlg::OnInit(wxInitDialogEvent& event)
{
    m_name_version->SetLabel(txtVersion);

    auto& history = wxGetMainFrame()->getFileHistory();
    bool file_added = false;
    for (size_t idx = 0; idx < history.GetCount(); ++idx)
    {
        tt_string project_file = history.GetHistoryFile(idx).utf8_string();
        if (project_file.file_exists())
        {
            tt_string shortname = project_file.filename();
            shortname.remove_extension();
            project_file.remove_filename();

            auto hyperlink = new wxGenericHyperlinkCtrl(this, wxID_ANY, shortname, wxEmptyString, wxDefaultPosition,
                                                        wxDefaultSize, wxHL_DEFAULT_STYLE);

            wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
            font.SetSymbolicSize(wxFONTSIZE_LARGE);
            hyperlink->SetFont(font);
            // wxRED is the default for the generic version of this control, but we want to be certain it stays that way in
            // case wxWidgets changes. The colour change makes it easier for the user to be certain they are over the link
            // they want in the vertical list of links.
            hyperlink->SetHoverColour(*wxRED);
            hyperlink->SetURL(history.GetHistoryFile(idx));
            hyperlink->Bind(wxEVT_HYPERLINK, &StartupDlg::OnHyperlink, this);

            m_recent_flex_grid->Add(hyperlink, wxSizerFlags().Border(wxRIGHT));

            auto path = new wxStaticText(this, wxID_ANY, project_file);
            m_recent_flex_grid->Add(path, wxSizerFlags().Border(wxALL));
            file_added = true;
        }
        else
        {
            // Assume that if the file doesn't exist now, it won't exist later either
            history.RemoveFileFromHistory(idx--);
        }
    }

#if defined(_DEBUG) || defined(INTERNAL_TESTING)
    auto append_history_ptr = wxGetFrame().GetAppendImportHistory();
    for (size_t idx = 0; idx < append_history_ptr->GetCount(); ++idx)
    {
        tt_string project_file = append_history_ptr->GetHistoryFile(idx).utf8_string();
        if (project_file.file_exists())
        {
            tt_string shortname = project_file.filename();
            project_file.remove_filename();

            auto hyperlink = new wxGenericHyperlinkCtrl(this, wxID_ANY, shortname.make_wxString(), wxEmptyString,
                                                        wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE);

            wxFont font(wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT));
            font.SetSymbolicSize(wxFONTSIZE_LARGE);
            hyperlink->SetFont(font);
            // Reverse the colours so that it's obvious which ones are the Debug build import files.
            hyperlink->SetNormalColour(*wxRED);
            hyperlink->SetHoverColour(*wxBLUE);
            hyperlink->SetURL(append_history_ptr->GetHistoryFile(idx));
            hyperlink->Bind(wxEVT_HYPERLINK, &StartupDlg::OnHyperlink, this);

            m_recent_flex_grid->Add(hyperlink, wxSizerFlags().Border(wxRIGHT));

            auto path = new wxStaticText(this, wxID_ANY, project_file);
            m_recent_flex_grid->Add(path, wxSizerFlags().Border(wxALL));
            file_added = true;
        }
    }
#endif

    if (file_added)
    {
        m_staticTextRecentProjects->Hide();
    }

    Fit();

    event.Skip();  // transfer all validator data to their windows and update UI
}

void StartupDlg::OnHyperlink(wxHyperlinkEvent& event)
{
    m_cmdType = START_MRU;
    m_value = event.GetURL();
    EndModal(wxID_OK);
}

void StartupDlg::OnImport(wxHyperlinkEvent& WXUNUSED(event))
{
    m_cmdType = START_CONVERT;
    EndModal(wxID_OK);
}

void StartupDlg::OnOpen(wxHyperlinkEvent& WXUNUSED(event))
{
    m_cmdType = START_OPEN;
    EndModal(wxID_OK);
}

void StartupDlg::OnNew(wxHyperlinkEvent& WXUNUSED(event))
{
    m_cmdType = START_EMPTY;
    EndModal(wxID_OK);
}
