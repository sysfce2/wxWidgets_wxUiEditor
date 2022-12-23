///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#pragma once

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choicebk.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/filepicker.h>
#include <wx/gdicmn.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

class ConvertImageBase : public wxDialog
{
public:
    ConvertImageBase() {}
    ConvertImageBase(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Convert Image",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr)
    {
        Create(parent, id, title, pos, size, style, name);
    }

    bool Create(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString& title = "Convert Image",
        const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE, const wxString &name = wxDialogNameStr);

protected:

    // Virtual event handlers -- override them in your derived class

    virtual void OnCheckPngConversion(wxCommandEvent& event) { event.Skip(); }
    virtual void OnComboHdrMask(wxCommandEvent& event) { event.Skip(); }
    virtual void OnComboXpmMask(wxCommandEvent& event) { event.Skip(); }
    virtual void OnConvert(wxCommandEvent& event) { event.Skip(); }
    virtual void OnConvertAlpha(wxCommandEvent& event) { event.Skip(); }
    virtual void OnForceHdrMask(wxCommandEvent& event) { event.Skip(); }
    virtual void OnForceXpmMask(wxCommandEvent& event) { event.Skip(); }
    virtual void OnInputChange(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnOutputChange(wxFileDirPickerEvent& event) { event.Skip(); }
    virtual void OnPageChanged(wxBookCtrlEvent& event) { event.Skip(); }

    // Class member variables

    wxButton* m_btnClose;
    wxButton* m_btnConvert;
    wxCheckBox* m_ConvertAlphaChannel;
    wxCheckBox* m_ForceHdrMask;
    wxCheckBox* m_ForceXpmMask;
    wxCheckBox* m_check_make_png;
    wxChoicebook* m_choicebook;
    wxComboBox* m_comboHdrMask;
    wxComboBox* m_comboXpmMask;
    wxFilePickerCtrl* m_fileOriginal;
    wxFilePickerCtrl* m_fileOutput;
    wxStaticBitmap* m_bmpOriginal;
    wxStaticBitmap* m_bmpOutput;
    wxStaticText* m_staticDescription;
    wxStaticText* m_staticDimensions;
    wxStaticText* m_staticHdrRGB;
    wxStaticText* m_staticHeader;
    wxStaticText* m_staticOriginal;
    wxStaticText* m_staticOriginal_2;
    wxStaticText* m_staticOutput;
    wxStaticText* m_staticSave;
    wxStaticText* m_staticSize;
    wxStaticText* m_staticXpmRGB;
};

// ************* End of generated code ***********
// DO NOT EDIT THIS COMMENT BLOCK!
//
// Code below this comment block will be preserved
// if the code for this class is re-generated.
//
// clang-format on
// ***********************************************
