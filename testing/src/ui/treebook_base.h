////////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/dialog.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>
#include <wx/treebook.h>

class TreebookBase : public wxDialog
{
public:
    TreebookBase() {}
    TreebookBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Treebook",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Treebook",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Class member variables

    wxStaticText* m_staticText;
    wxTreebook* m_treebook;
};
