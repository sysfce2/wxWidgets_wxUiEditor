////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/valgen.h>
#include <wx/valtext.h>

#include "newdialog_base.h"

bool NewDialog::Create(wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint&pos, const wxSize& size, long style, const wxString &name)
{
    if (!wxDialog::Create(parent, id, title, pos, size, style, name))
        return false;

    auto parent_sizer = new wxBoxSizer(wxVERTICAL);

    auto box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto staticText_3 = new wxStaticText(this, wxID_ANY, "These are initial values -- all of them can be changed after the dialog is created.");
    staticText_3->Wrap(300);
    box_sizer_3->Add(staticText_3, wxSizerFlags().Border(wxALL));

    auto box_sizer__2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer__2, wxSizerFlags().Expand().Border(wxALL));

    auto staticText_2 = new wxStaticText(this, wxID_ANY, "&Title:");
    box_sizer__2->Add(staticText_2, wxSizerFlags().Center().Border(wxALL));

    m_textCtrl_title = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    m_textCtrl_title->SetValidator(wxTextValidator(wxFILTER_NONE, &m_title));
    box_sizer__2->Add(m_textCtrl_title, wxSizerFlags(1).Border(wxALL));

    auto box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    parent_sizer->Add(box_sizer_2, wxSizerFlags().Expand().Border(wxALL));

    auto staticText = new wxStaticText(this, wxID_ANY, "&Base class name:");
    box_sizer_2->Add(staticText, wxSizerFlags().Center().Border(wxALL));

    auto classname = new wxTextCtrl(this, wxID_ANY, "MyDialogBase");
    classname->SetValidator(wxTextValidator(wxFILTER_NONE, &m_base_class));
    box_sizer_2->Add(classname, wxSizerFlags(1).Border(wxALL));

    auto box_sizer = new wxBoxSizer(wxVERTICAL);
    parent_sizer->Add(box_sizer, wxSizerFlags().Border(wxALL));

    auto box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    box_sizer->Add(box_sizer_4, wxSizerFlags().Border(wxRIGHT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_check_tabs = new wxCheckBox(this, wxID_ANY, "Tabbed &Dialog");
    m_check_tabs->SetValidator(wxGenericValidator(&m_has_tabs));
    box_sizer_4->Add(m_check_tabs, wxSizerFlags().Border(wxALL));

    auto staticText_4 = new wxStaticText(this, wxID_ANY, "Tab&s:");
    box_sizer_4->Add(staticText_4, wxSizerFlags().Center().Border(wxLEFT|wxTOP|wxBOTTOM, wxSizerFlags::GetDefaultBorder()));

    m_spinCtrlTabs = new wxSpinCtrl(this, wxID_ANY, wxEmptyString,
            wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 7, 3);
    m_spinCtrlTabs->SetValidator(wxGenericValidator(&m_num_tabs));
    m_spinCtrlTabs->Enable(false);
    box_sizer_4->Add(m_spinCtrlTabs, wxSizerFlags().Border(wxALL));

    auto checkBox_2 = new wxCheckBox(this, wxID_ANY, "&Standard Buttons");
    checkBox_2->SetValue(true);
    checkBox_2->SetValidator(wxGenericValidator(&m_has_std_btns));
    box_sizer->Add(checkBox_2, wxSizerFlags().Border(wxALL));

    auto stdBtn = CreateStdDialogButtonSizer(wxOK|wxCANCEL);
    parent_sizer->Add(CreateSeparatedSizer(stdBtn), wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(parent_sizer);
    Centre(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &NewDialog::OnInit, this);
    m_check_tabs->Bind(wxEVT_CHECKBOX,
        [this](wxCommandEvent&)
        {
            m_spinCtrlTabs->Enable(m_check_tabs->GetValue());
        } );

    return true;
}
