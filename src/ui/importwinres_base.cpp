////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/sizer.h>

#include "importwinres_base.h"

bool ImportWinRes::Create(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint&pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer4 = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer4, wxSizerFlags(1).Expand().Border(wxALL));

    m_staticResFile = new wxStaticText(this, wxID_ANY, "&Resource File:");
    box_sizer4->Add(m_staticResFile, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_fileResource = new wxFilePickerCtrl(this, wxID_ANY, wxEmptyString, wxFileSelectorPromptStr, 
        "Resource Files|*.rc;*.dlg||", wxDefaultPosition, wxDefaultSize,
        wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL);
    m_fileResource->SetMinSize(wxSize(240, -1));
    box_sizer4->Add(m_fileResource, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer5 = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer5, wxSizerFlags().Expand().Border(wxALL));

    m_staticText = new wxStaticText(this, wxID_ANY, "&Dialogs to Import");
    box_sizer5->Add(m_staticText, wxSizerFlags().Border(wxLEFT|wxRIGHT|wxTOP, wxSizerFlags::GetDefaultBorder()));

    m_checkListResUI = new wxCheckListBox(this, wxID_ANY);
    m_checkListResUI->SetMinSize(wxSize(-1, 160));
    m_checkListResUI->SetToolTip("Uncheck any resources you don't want converted.");
    box_sizer5->Add(m_checkListResUI, wxSizerFlags().Expand().Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);
    box_sizer5->Add(box_sizer, wxSizerFlags().Expand().Border(wxALL));

    m_btnSelectAll = new wxButton(this, wxID_ANY, "Select &All");
    box_sizer->Add(m_btnSelectAll, wxSizerFlags().Border(wxALL));

    m_btnClearAll = new wxButton(this, wxID_ANY, "&Clear All");
    box_sizer->Add(m_btnClearAll, wxSizerFlags().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &ImportWinRes::OnInit, this);
    m_fileResource->Bind(wxEVT_FILEPICKER_CHANGED, &ImportWinRes::OnResourceFile, this);
    m_btnSelectAll->Bind(wxEVT_BUTTON, &ImportWinRes::OnSelectAll, this);
    m_btnClearAll->Bind(wxEVT_BUTTON, &ImportWinRes::OnClearAll, this);
    Bind(wxEVT_BUTTON, &ImportWinRes::OnOk, this, wxID_OK);

    return true;
}
