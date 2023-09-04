///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/infobar.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

class NewRibbon : public wxDialog
{
public:
    NewRibbon() {}
    NewRibbon(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "New Ribbon Bar", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "New Ribbon Bar", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);

private:

    // Validator variables

    int m_num_pages { 3 };
    wxString m_base_class { "MyRibbonBarBase" };
    wxString m_panel_type;

    // Class member variables

    wxBoxSizer* m_class_sizer;
    wxComboBox* m_comboBox;
    wxInfoBar* m_infoBar;
    wxSpinCtrl* m_spinCtrlPages;
    wxStaticText* m_staticText;
    wxTextCtrl* m_classname;

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
    // clang-format on
    // ***********************************************

public:
    // Checks current selected node to see if it accepts a wxRibbonBar as a child
    bool IsCreatable(bool notify_user = true);

    void WantFormVersion() { m_is_form = true; }
    void createNode();
    void VerifyClassName();

private:
    bool m_is_form { false };
    bool m_is_info_shown { false };
};
