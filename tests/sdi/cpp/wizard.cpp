///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/valgen.h>

#include "images.h"

#include "wizard.h"

namespace wxue_img
{
    extern const unsigned char wiztest2_png[6797];
    extern const unsigned char wiztest_png[1239];
}

Wizard::Wizard(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, long style) : wxWizard()
{
    if (!wxImage::FindHandler(wxBITMAP_TYPE_PNG))
        wxImage::AddHandler(new wxPNGHandler);

    SetExtraStyle(GetExtraStyle() | wxWIZARD_EX_HELPBUTTON);
    SetBorder(15);
    if (!Create(parent, id, title, wxue_img::bundle_wiztest_png(), pos, style))
        return;

    auto* wizPage = new wxWizardPageSimple(this);

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    m_staticText = new wxStaticText(wizPage, wxID_ANY, "This is the first Wizard page");
    box_sizer->Add(m_staticText, wxSizerFlags().Border(wxALL));

    m_calendar = new wxCalendarCtrl(wizPage, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize,
        wxCAL_SHOW_HOLIDAYS);
    box_sizer->Add(m_calendar, wxSizerFlags().Border(wxALL));
    wizPage->SetSizerAndFit(box_sizer);

    auto* m_wizPage2 = new wxWizardPageSimple(this);

    auto* box_sizer2 = new wxBoxSizer(wxVERTICAL);

    m_staticText2 = new wxStaticText(m_wizPage2, wxID_ANY, "This is the second Wizard page which is wider.");
    box_sizer2->Add(m_staticText2, wxSizerFlags().Border(wxALL));

    auto* parent_sizer3 = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer_2 = new wxBoxSizer(wxHORIZONTAL);

    staticText = new wxStaticText(m_wizPage2, wxID_ANY, "Scrollbar:");
    box_sizer_2->Add(staticText, wxSizerFlags().Border(wxALL));

    m_scrollBar = new wxScrollBar(m_wizPage2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL);
    m_scrollBar->SetScrollbar(0, 1, 100, 1);
    box_sizer_2->Add(m_scrollBar, wxSizerFlags(1).Expand().Border(wxALL));

    parent_sizer3->Add(box_sizer_2, wxSizerFlags().Border(wxALL));

    auto* box_sizer_3 = new wxBoxSizer(wxHORIZONTAL);

    staticText_2 = new wxStaticText(m_wizPage2, wxID_ANY, "Normal SpinCtrl");
    box_sizer_3->Add(staticText_2, wxSizerFlags().Border(wxALL));

    m_spinCtrl = new wxSpinCtrl(m_wizPage2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0,
        100, 4);
    m_spinCtrl->SetValidator(wxGenericValidator(&m_spinValidate));
    box_sizer_3->Add(m_spinCtrl, wxSizerFlags().Border(wxALL));

    parent_sizer3->Add(box_sizer_3, wxSizerFlags().Border(wxALL));

    auto* box_sizer_4 = new wxBoxSizer(wxHORIZONTAL);

    staticText_3 = new wxStaticText(m_wizPage2, wxID_ANY, "Double SpinCtrl");
    box_sizer_4->Add(staticText_3, wxSizerFlags().Border(wxALL));

    m_spinCtrlDouble = new wxSpinCtrlDouble(m_wizPage2);
    box_sizer_4->Add(m_spinCtrlDouble, wxSizerFlags().Border(wxALL));

    parent_sizer3->Add(box_sizer_4, wxSizerFlags().Border(wxALL));

    auto* box_sizer_5 = new wxBoxSizer(wxHORIZONTAL);

    staticText_4 = new wxStaticText(m_wizPage2, wxID_ANY, "Spin Button");
    box_sizer_5->Add(staticText_4, wxSizerFlags().Border(wxALL));

    m_spinBtn = new wxSpinButton(m_wizPage2);
    m_spinBtn->SetRange(0, 10);
    box_sizer_5->Add(m_spinBtn, wxSizerFlags().Border(wxALL));

    parent_sizer3->Add(box_sizer_5, wxSizerFlags().Border(wxALL));

    box_sizer2->Add(parent_sizer3, wxSizerFlags().Border(wxALL));
    m_wizPage2->SetSizerAndFit(box_sizer2);

    auto* m_wizPage3 = new wxWizardPageSimple(this, nullptr, nullptr, wxue_img::bundle_wiztest2_png());

    auto* box_sizer3 = new wxBoxSizer(wxVERTICAL);

    m_staticText3 = new wxStaticText(m_wizPage3, wxID_ANY, "This is the final Wizard page");
    box_sizer3->Add(m_staticText3, wxSizerFlags().Border(wxALL));

    auto* box_sizer_6 = new wxBoxSizer(wxHORIZONTAL);

    m_hyperlink = new wxHyperlinkCtrl(m_wizPage3, wxID_ANY, "Blank Page", "https://blank.page/");
    box_sizer_6->Add(m_hyperlink, wxSizerFlags().Center().Border(wxALL));

    m_searchCtrl = new wxSearchCtrl(m_wizPage3, wxID_ANY, wxEmptyString);
    m_searchCtrl->SetHint("Search for something...");
    m_searchCtrl->ShowSearchButton(true);
    m_searchCtrl->ShowCancelButton(true);
    box_sizer_6->Add(m_searchCtrl, wxSizerFlags(1).Border(wxALL));

    box_sizer3->Add(box_sizer_6, wxSizerFlags().Expand().Border(wxALL));
    m_wizPage3->SetSizerAndFit(box_sizer3);

    wizPage->Chain(m_wizPage2).Chain(m_wizPage3);
    GetPageAreaSizer()->Add(wizPage);
    Center(wxBOTH);

    // Event handlers
    Bind(wxEVT_INIT_DIALOG, &Wizard::OnInit, this);
    Bind(wxEVT_WIZARD_BEFORE_PAGE_CHANGED, &Wizard::OnBeforeChange, this);
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************

/////////////////// Non-generated Copyright/License Info ////////////////////
// Purpose:   Multiple Tests dialog
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "mainframe.h"  // MainFrame -- Main window

void MainFrame::OnWizard(wxCommandEvent& WXUNUSED(event))
{
    Wizard wizard(this);
    wizard.Run();
}

void Wizard::OnBeforeChange(wxWizardEvent& event)
{
    event.Skip();
}

void Wizard::OnInit(wxInitDialogEvent& event)
{
    event.Skip();  // transfer all validator data to their windows and update UI
}
