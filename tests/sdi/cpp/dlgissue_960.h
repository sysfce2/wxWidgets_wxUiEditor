///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>

class DlgIssue_960 : public wxDialog
{
public:
    const int form_id = wxID_ANY;
    const int form_style = wxDEFAULT_DIALOG_STYLE;
    const wxPoint form_pos = wxDefaultPosition;
    const wxSize form_size = wxDefaultSize;
    static const wxString form_title() { return wxEmptyString; }

    DlgIssue_960() {}
    DlgIssue_960(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Class member variables

    wxStaticText* staticText;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
