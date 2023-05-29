///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/bitmap.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/grid.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/menu.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/propgrid.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>

class MainFrame : public wxFrame
{
public:
    MainFrame() {}
    MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "pytest", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL,
        const wxString &name = wxFrameNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "pytest", const wxPoint& pos =
        wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL,
        const wxString &name = wxFrameNameStr);

protected:

    // Event handlers

    void OnBookTestDlg(wxCommandEvent& event);
    void OnCommonDialog(wxCommandEvent& event);
    void OnDlgIssue_956(wxCommandEvent& event);
    void OnMainTestDlg(wxCommandEvent& event);
    void OnPythonDlg(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnWizard(wxCommandEvent& event);

    // Class member variables

    wxGrid* grid;
    wxMenu* menu;
    wxPGProperty* propertyGridItem;
    wxPGProperty* propertyGridItem_2;
    wxPGProperty* propertyGridItem_3;
    wxPGProperty* propertyGridItem_4;
    wxPGProperty* propertyGridItem_5;
    wxPGProperty* propertyGridItem_6;
    wxPGProperty* propertyGridItem_7;
    wxPGProperty* propertyGridItem_8;
    wxPropertyGridManager* propertyGridManager;
    wxPropertyGridPage* propertyGridPage;
    wxPropertyGridPage* propertyGridPage_2;
    wxSplitterWindow* splitter;
    wxStatusBar* m_statusBar;
    wxToolBar* m_toolBar;
};

namespace wxue_img
{
    // Images declared in this class module:

    extern const unsigned char debug_32_png[1701];
    extern const unsigned char wxDialog_png[636];
    extern const unsigned char wxNotebook_png[177];
    extern const unsigned char wxPython_1_5x_png[765];
    extern const unsigned char wxPython_2x_png[251];
    extern const unsigned char wxPython_png[399];
}

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
