////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include "wizard_base.h"

WizardBase::WizardBase(wxWindow* parent, wxWindowID id, const wxString& title,
        const wxBitmap& bitmap, const wxPoint& pos, long style) :
    wxWizard(parent, id, title, bitmap, pos, style)
{
    SetSizeHints(wxDefaultSize);

    auto wizPage = new wxWizardPageSimple(this);

    auto box_sizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticText = new wxStaticText(wizPage, wxID_ANY, wxString::FromUTF8("This is the first Wizard page"));
    box_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    wizPage->SetSizerAndFit(box_sizer);

    auto m_wizPage2 = new wxWizardPageSimple(this);

    auto box_sizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText2 = new wxStaticText(m_wizPage2, wxID_ANY, wxString::FromUTF8("This is the second Wizard page"));
    box_sizer2->Add(m_staticText2, wxSizerFlags().Border(wxALL));

    m_wizPage2->SetSizerAndFit(box_sizer2);

    auto m_wizPage3 = new wxWizardPageSimple(this);

    auto box_sizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText3 = new wxStaticText(m_wizPage3, wxID_ANY, wxString::FromUTF8("This is the final Wizard page"));
    box_sizer3->Add(m_staticText3, wxSizerFlags().Border(wxALL));

    m_wizPage3->SetSizerAndFit(box_sizer3);

    wizPage->Chain(m_wizPage2).Chain(m_wizPage3);
    GetPageAreaSizer()->Add(wizPage);
    Center(wxBOTH);

    // Event handlers
    Bind(wxEVT_WIZARD_BEFORE_PAGE_CHANGED, &WizardBase::OnBeforeChange, this);
}
