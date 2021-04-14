////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
//
// DO NOT EDIT THIS FILE! Your changes will be lost if it is re-generated!
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/gdicmn.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>

class NewProjectBase : public wxDialog
{
public:
    NewProjectBase(wxWindow* parent, wxWindowID id = wxID_ANY,
        const wxString& title = wxString::FromUTF8("New Project"),
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE);

protected:

    // Class member variables

    wxButton* m_btnAddFile;
    wxCheckBox* m_checkBoxEmptyProject;
    wxCheckListBox* m_checkListProjects;
    wxRadioButton* m_radioBtnFormBuilder;
    wxRadioButton* m_radioBtnGlade;
    wxRadioButton* m_radioBtnSmith;
    wxRadioButton* m_radioBtnWinRes;
    wxRadioButton* m_radioBtnXrc;
    wxStaticBoxSizer* m_import_staticbox;
    wxStaticText* m_staticFiles;
    wxStdDialogButtonSizer* m_stdBtn;
    wxButton* m_stdBtnOK;
    wxButton* m_stdBtnCancel;

    // Virtual event handlers -- override them in your derived class

    virtual void OnCheckFiles(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDirectory(wxCommandEvent& event) { event.Skip(); }
    virtual void OnEmptyProject(wxCommandEvent& event) { event.Skip(); }
    virtual void OnFormBuilder(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInitDialog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void OnOK(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSelectAll(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSelectNone(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWindowsResource(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWxGlade(wxCommandEvent& event) { event.Skip(); }
    virtual void OnWxSmith(wxCommandEvent& event) { event.Skip(); }
    virtual void OnXRC(wxCommandEvent& event) { event.Skip(); }
};
