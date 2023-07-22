///////////////////////////////////////////////////////////////////////////////
// Code generated by wxUiEditor - see https://github.com/KeyWorksRW/wxUiEditor/
//
// Do not edit any code above the "End of generated code" comment block.
// Any changes before that block will be lost if it is re-generated!
///////////////////////////////////////////////////////////////////////////////

// clang-format off

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>

#include "..\wxui\ui_images.h"

#include "doc_view.h"

#include <wx/mstream.h>  // memory stream classes
#include <wx/zstream.h>  // zlib stream classes

#include <memory>  // for std::make_unique

// Convert compressed SVG string into a wxBitmapBundle
inline wxBitmapBundle wxueBundleSVG(const unsigned char* data,
    size_t size_data, size_t size_svg, wxSize def_size)
{
    auto str = std::make_unique<char[]>(size_svg);
    wxMemoryInputStream stream_in(data, size_data);
    wxZlibInputStream zlib_strm(stream_in);
    zlib_strm.Read(str.get(), size_svg);
    return wxBitmapBundle::FromSVG(str.get(), def_size);
};

namespace wxue_img
{
    extern const unsigned char cpp_logo_svg[587];
    // python-logo-only.svg
    extern const unsigned char python_logo_only_svg[1648];
    extern const unsigned char ruby_logo_svg[1853];
}

bool DocViewPanel::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style,
    const wxString& name)
{

    if (!wxPanel::Create(parent, id, pos, size, style, name))
        return false;

    m_parent_sizer = new wxBoxSizer(wxVERTICAL);

    m_toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT);
    m_toolBar->AddTool(wxID_HOME, "Home", wxArtProvider::GetBitmapBundle(wxART_GO_HOME, wxART_TOOLBAR));

    m_toolBar->AddTool(wxID_BACKWARD, "Back", wxArtProvider::GetBitmapBundle(wxART_GO_BACK, wxART_TOOLBAR));

    m_toolBar->AddTool(wxID_FORWARD, "Forward", wxArtProvider::GetBitmapBundle(wxART_GO_FORWARD, wxART_TOOLBAR));

    m_toolBar->AddSeparator();
    m_toolBar->AddTool(ID_CPLUS, "C++", wxue_img::bundle_cpp_logo_svg(16, 16), wxEmptyString, wxITEM_RADIO);

    m_toolBar->AddTool(ID_PYTHON, "Python", wxue_img::bundle_python_logo_only_svg(16, 16), wxEmptyString, wxITEM_RADIO);

    m_toolBar->AddTool(ID_RUBY, "Ruby", wxueBundleSVG(wxue_img::ruby_logo_svg, 1853, 10034, wxSize(16, 16)),
        wxEmptyString, wxITEM_RADIO);

    m_toolBar->Realize();
    m_parent_sizer->Add(m_toolBar, wxSizerFlags().Expand().Border(wxALL));

    SetSizerAndFit(m_parent_sizer);

    // Event handlers
    Bind(wxEVT_TOOL, &DocViewPanel::OnHome, this, wxID_HOME);
    Bind(wxEVT_TOOL, &DocViewPanel::OnBack, this, wxID_BACKWARD);
    Bind(wxEVT_TOOL, &DocViewPanel::OnForward, this, wxID_FORWARD);
    Bind(wxEVT_TOOL, &DocViewPanel::OnCPlus, this, ID_CPLUS);
    Bind(wxEVT_TOOL, &DocViewPanel::OnPython, this, ID_PYTHON);
    Bind(wxEVT_TOOL, &DocViewPanel::OnRuby, this, ID_RUBY);
    Bind(wxEVT_UPDATE_UI, &DocViewPanel::OnUpdateBack, this, wxID_BACKWARD);
    Bind(wxEVT_UPDATE_UI, &DocViewPanel::OnUpdateForward, this, wxID_FORWARD);

    return true;
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
// Purpose:   Panel for displaying docs in wxWebView
// Author:    Ralph Walden
// Copyright: Copyright (c) 2023 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include <wx/webview.h>

#if !wxUSE_WEBVIEW_WEBKIT && !wxUSE_WEBVIEW_WEBKIT2 && !wxUSE_WEBVIEW_IE && !wxUSE_WEBVIEW_EDGE
    #error "A wxWebView backend is required!"
#endif

#include "doc_view.h"

#include "base_generator.h"   // BaseGenerator -- Base widget generator class
#include "cstm_event.h"       // CustomEvent -- Custom Event class
#include "mainframe.h"        // MainFrame -- Main window frame
#include "node.h"             // Node class
#include "project_handler.h"  // ProjectHandler -- Project file handler

DocViewPanel::DocViewPanel(wxWindow* parent, MainFrame* frame)
{
    m_mainframe = frame;
    // Don't allow events to propagate any higher than this window.
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);

    Create(parent);

    frame->AddCustomEventHandler(GetEventHandler());

    Bind(EVT_NodeSelected, &DocViewPanel::OnNodeSelected, this);
}

void DocViewPanel::ActivatePage()
{
    if (!m_webview)
    {
        wxBusyCursor wait;

        m_language = Project.get_PreferredLanguage();
        m_toolBar->ToggleTool(ID_CPLUS, m_language == GEN_LANG_CPLUSPLUS);
        m_toolBar->ToggleTool(ID_PYTHON, m_language == GEN_LANG_PYTHON);
        m_toolBar->ToggleTool(ID_RUBY, m_language == GEN_LANG_RUBY);

        m_webview = wxWebView::New(this, wxID_ANY, "about:blank");
        m_parent_sizer->Add(m_webview, wxSizerFlags(1).Expand().Border(wxALL));
        m_parent_sizer->Layout();
    }

    wxCommandEvent dummy;
    switch (m_language)
    {
        case GEN_LANG_CPLUSPLUS:
            OnCPlus(dummy);
            break;
        case GEN_LANG_PYTHON:
            OnPython(dummy);
            break;
        case GEN_LANG_RUBY:
            OnRuby(dummy);
            break;
    }
}

void DocViewPanel::OnNodeSelected(CustomEvent& WXUNUSED(event))
{
    if (!IsShown())
        return;

    ActivatePage();
}

void DocViewPanel::OnCPlus(wxCommandEvent& /* event */)
{
    wxBusyCursor wait;
    m_language = GEN_LANG_CPLUSPLUS;
    if (auto* cur_sel = m_mainframe->GetSelectedNode(); cur_sel)
    {
        if (auto* gen = cur_sel->GetGenerator(); gen)
        {
            if (auto file = gen->GetHelpURL(cur_sel); file.size())
            {
                wxString url("https://docs.wxwidgets.org/3.2.0/class");
                url << file.make_wxString();

                m_webview->LoadURL(url);
                return;
            }
        }
    }
    m_webview->SetPage("<html><title>Select Node</title>"
                       "<body>The selected node does not have any specific documentation for this language.</body></html>",
                       wxEmptyString);
}

void DocViewPanel::OnPython(wxCommandEvent& /* event */)
{
    wxBusyCursor wait;
    m_language = GEN_LANG_PYTHON;
    if (auto* cur_sel = m_mainframe->GetSelectedNode(); cur_sel)
    {
        if (auto* gen = cur_sel->GetGenerator(); gen)
        {
            if (auto file = gen->GetPythonURL(cur_sel); file.size())
            {
                wxString url("https://docs.wxpython.org/");
                url << file.make_wxString();

                m_webview->LoadURL(url);
                return;
            }
        }
    }
    m_webview->SetPage("<html><title>Select Node</title>"
                       "<body>The selected node does not have any specific documentation for this language.</body></html>",
                       wxEmptyString);
}

void DocViewPanel::OnRuby(wxCommandEvent& /* event */)
{
    wxBusyCursor wait;
    m_language = GEN_LANG_RUBY;
    if (auto* cur_sel = m_mainframe->GetSelectedNode(); cur_sel)
    {
        if (auto* gen = cur_sel->GetGenerator(); gen)
        {
            if (auto file = gen->GetRubyURL(cur_sel); file.size())
            {
                wxString url("https://mcorino.github.io/wxRuby3/");
                url << file.make_wxString();

                m_webview->LoadURL(url);
                return;
            }
        }
    }
    m_webview->SetPage("<html><title>Select Node</title>"
                       "<body>The selected node does not have any specific documentation for this language.</body></html>",
                       wxEmptyString);
}

void DocViewPanel::OnHome(wxCommandEvent& WXUNUSED(event))
{
    ActivatePage();
}

void DocViewPanel::OnBack(wxCommandEvent& WXUNUSED(event))
{
    wxBusyCursor wait;

    m_webview->GoBack();
}

void DocViewPanel::OnForward(wxCommandEvent& WXUNUSED(event))
{
    wxBusyCursor wait;
    m_webview->GoForward();
}

void DocViewPanel::OnUpdateBack(wxUpdateUIEvent& event)
{
    if (!m_webview)
    {
        event.Enable(false);
        return;
    }

    if (auto history = m_webview->GetBackwardHistory(); history.size() == 1)
    {
        event.Enable(history[0].get()->GetUrl() != "about:blank");
        return;
    }

    event.Enable(m_webview->CanGoBack());
}

void DocViewPanel::OnUpdateForward(wxUpdateUIEvent& event)
{
    if (!m_webview)
    {
        event.Enable(false);

        return;
    }

    event.Enable(m_webview->CanGoForward());
}
