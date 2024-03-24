///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/sizer.h>

// This is the base class for editing multiple-field properties

#include "grid_property_dlg.h"

bool GridPropertyDlg::Create(wxWindow* parent, wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto* dlg_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer = new wxBoxSizer(wxHORIZONTAL);

    m_prop_label = new wxStaticText(this, wxID_ANY, "property label");
    box_sizer->Add(m_prop_label, wxSizerFlags().Center().Border(wxALL));

    m_toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_NODIVIDER);
    m_toolBar->AddTool(id_NewRow, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_NEW, wxART_TOOLBAR));

    m_toolBar->AddTool(id_DeleteRow, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_DELETE, wxART_TOOLBAR));

    m_toolBar->AddTool(id_UndoDeleteRow, wxEmptyString, wxArtProvider::GetBitmapBundle(wxART_UNDO, wxART_TOOLBAR));

    m_toolBar->Realize();
    box_sizer->Add(m_toolBar, wxSizerFlags().Border(wxALL));

    dlg_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    m_grid = new wxGrid(this, wxID_ANY);
    {
        m_grid->CreateGrid(1, 2);
        m_grid->EnableDragGridSize(false);
        m_grid->SetMargins(0, 0);
        m_grid->SetSelectionMode(wxGrid::wxGridSelectRows);
        m_grid->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_CENTER);
        m_grid->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        m_grid->SetColLabelSize(wxGRID_AUTOSIZE);
        m_grid->SetColLabelValue(0, "name");
        m_grid->SetColLabelValue(1, "value");

        m_grid->EnableDragRowSize(false);
        m_grid->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);
        m_grid->SetRowLabelSize(wxGRID_AUTOSIZE);
    }
    dlg_sizer->Add(m_grid, wxSizerFlags(1).Expand().Border(wxALL));

    m_help_text = new wxStaticText(this, wxID_ANY, "Help text");
    m_help_text->Wrap(300);
    m_help_text->Hide();
    dlg_sizer->Add(m_help_text, wxSizerFlags().Border(wxALL));

    auto* stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    dlg_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(dlg_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_BUTTON, &GridPropertyDlg::OnCancel, this, wxID_CANCEL);
    Bind(wxEVT_BUTTON, &GridPropertyDlg::OnOK, this, wxID_OK);
    Bind(wxEVT_INIT_DIALOG, &GridPropertyDlg::OnInit, this);
    Bind(wxEVT_TOOL, &GridPropertyDlg::OnDeleteRow, this, id_DeleteRow);
    Bind(wxEVT_TOOL, &GridPropertyDlg::OnNewRow, this, id_NewRow);
    Bind(wxEVT_TOOL, &GridPropertyDlg::OnUndoDelete, this, id_UndoDeleteRow);
    Bind(wxEVT_UPDATE_UI, &GridPropertyDlg::OnUpdateUI, this);

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
