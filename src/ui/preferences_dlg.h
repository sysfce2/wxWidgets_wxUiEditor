///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/font.h>
#include <wx/fontpicker.h>
#include <wx/gdicmn.h>

class PreferencesDlg : public wxDialog
{
public:
    PreferencesDlg() {}
    PreferencesDlg(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Preferences",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Preferences", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Event handlers

    void OnInit(wxInitDialogEvent& event);
    void OnOK(wxCommandEvent& event);

    // Validator variables

    bool m_isWakaTimeEnabled { true };
    wxString m_cpp_line_length;
    wxString m_python_line_length;
    wxString m_ruby_line_length;

    // Class member variables

    wxCheckBox* m_check_cpp_snake_case;
    wxCheckBox* m_check_dark_mode;
    wxCheckBox* m_check_load_last;
    wxCheckBox* m_check_right_propgrid;
    wxChoice* m_choice_cpp_version;
    wxColourPickerCtrl* m_colour_cpp;
    wxColourPickerCtrl* m_colour_python;
    wxColourPickerCtrl* m_colour_ruby;
    wxFontPickerCtrl* m_code_font_picker;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
