////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/toolbar.h>
#include <wx/stattext.h>
#include <wx/stc/stc.h>

class RibbonDlgBase : public wxDialog
{
public:
    RibbonDlgBase(wxWindow* parent);

protected:

    // Class member variables

    wxButton* m_btn;
    wxButton* m_btn_2;
    wxRibbonBar* m_rbnBar;
    wxStaticText* m_staticText;
    wxStaticText* m_staticText_2;
    wxStyledTextCtrl* m_scintilla;
};
