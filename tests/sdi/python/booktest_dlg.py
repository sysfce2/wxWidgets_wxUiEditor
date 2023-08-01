###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx
import wx.aui

import images

class BookTestDlg(wx.Dialog):
    def __init__(self, parent, id=wx.ID_ANY, title="Book tests", pos=
                wx.DefaultPosition, size=wx.DefaultSize,
                style=wx.DEFAULT_DIALOG_STYLE, name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        dlg_sizer = wx.BoxSizer(wx.VERTICAL)
        dlg_sizer.SetMinSize(400, 400)

        self.notebook = wx.aui.AuiNotebook(self, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, wx.aui.AUI_NB_TOP|wx.aui.AUI_NB_TAB_SPLIT|
            wx.aui.AUI_NB_TAB_MOVE|wx.aui.AUI_NB_SCROLL_BUTTONS|
            wx.aui.AUI_NB_CLOSE_ON_ACTIVE_TAB|wx.aui.AUI_NB_MIDDLE_CLICK_CLOSE)
        dlg_sizer.Add(self.notebook, wx.SizerFlags(1).Expand().Border(wx.ALL))

        page_2 = wx.Panel(self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook.AddPage(page_2, "ChoiceBook")

        page_sizer_1 = wx.BoxSizer(wx.VERTICAL)

        self.choicebook = wx.Choicebook(page_2, wx.ID_ANY)
        self.choicebook.SetMinSize(wx.Size(400, 400))
        page_sizer_1.Add(self.choicebook, wx.SizerFlags().Border(wx.ALL))

        btn = wx.Button(self.choicebook, wx.ID_ANY, "First")
        # wxPython 4.2.0 does not support wx.Choicebook.GetControlSizer()
        # so btn cannot be added to the Choicebook.

        btn_2 = wx.Button(self.choicebook, wx.ID_ANY, "Last")
        # wxPython 4.2.0 does not support wx.Choicebook.GetControlSizer()
        # so btn_2 cannot be added to the Choicebook.

        page_20 = wx.Panel(self.choicebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.choicebook.AddPage(page_20, "English")
        page_20.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_13 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_16 = wx.StaticText(page_20, wx.ID_ANY,
            "This is a sentence in English.")
        parent_sizer_13.Add(self.staticText_16, wx.SizerFlags().Border(wx.ALL))

        box_sizer = wx.BoxSizer(wx.VERTICAL)

        self.staticText_2 = wx.StaticText(page_20, wx.ID_ANY,
            "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.")
        self.staticText_2.Wrap(380)
        box_sizer.Add(self.staticText_2, wx.SizerFlags().Expand().Border(wx.ALL))

        parent_sizer_13.Add(box_sizer, wx.SizerFlags().Border(wx.ALL))
        page_20.SetSizerAndFit(parent_sizer_13)

        page_21 = wx.Panel(self.choicebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.choicebook.AddPage(page_21, "Français")
        page_21.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer__2 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_17 = wx.StaticText(page_21, wx.ID_ANY,
            "Ceci est une phrase en français.")
        parent_sizer__2.Add(self.staticText_17, wx.SizerFlags().Border(wx.ALL))

        box_sizer_3 = wx.BoxSizer(wx.VERTICAL)

        self.staticText__3 = wx.StaticText(page_21, wx.ID_ANY,
            "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.")
        self.staticText__3.Wrap(390)
        box_sizer_3.Add(self.staticText__3, wx.SizerFlags().Expand().Border(wx.ALL))

        parent_sizer__2.Add(box_sizer_3, wx.SizerFlags().Border(wx.ALL))
        page_21.SetSizerAndFit(parent_sizer__2)

        page_22 = wx.Panel(self.choicebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.choicebook.AddPage(page_22, "日本語")
        page_22.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_14 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_18 = wx.StaticText(page_22, wx.ID_ANY,
            "これは日本語の文章です。")
        parent_sizer_14.Add(self.staticText_18, wx.SizerFlags().Border(wx.ALL))

        box_sizer_2 = wx.BoxSizer(wx.VERTICAL)

        self.staticText__2 = wx.StaticText(page_22, wx.ID_ANY,
            "The First and Last buttons above are children of the wcChoicebook. They are added using choicebook->GetControlSizer() which allows them to share the layout space for the wxChoice control.")
        self.staticText__2.Wrap(390)
        box_sizer_2.Add(self.staticText__2, wx.SizerFlags().Expand().Border(wx.ALL))

        parent_sizer_14.Add(box_sizer_2, wx.SizerFlags().Border(wx.ALL))
        page_22.SetSizerAndFit(parent_sizer_14)
        page_2.SetSizerAndFit(page_sizer_1)

        page_3 = wx.Panel(self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook.AddPage(page_3, "ListBook")

        page_sizer_2 = wx.BoxSizer(wx.VERTICAL)

        self.listbook = wx.Listbook(page_3, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.LB_LEFT)

        bundle_1 = wx.BitmapBundle.FromBitmap(images.english_png.Bitmap)
        bundle_2 = wx.BitmapBundle.FromBitmap(images.french_png.Bitmap)
        bundle_3 = wx.BitmapBundle.FromBitmap(images.japanese_png.Bitmap)
        bundle_list = [
            bundle_1,
            bundle_2,
            bundle_3
        ]
        self.listbook.SetImages(bundle_list)
        self.listbook.SetMinSize(wx.Size(400, 400))
        page_sizer_2.Add(self.listbook, wx.SizerFlags().Border(wx.ALL))

        page_6 = wx.Panel(self.listbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.listbook.AddPage(page_6, "English", False, 0)
        page_6.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer = wx.BoxSizer(wx.VERTICAL)

        self.staticText_6 = wx.StaticText(page_6, wx.ID_ANY,
            "This is a sentence in English.")
        parent_sizer.Add(self.staticText_6, wx.SizerFlags().Border(wx.ALL))
        page_6.SetSizerAndFit(parent_sizer)

        page_7 = wx.Panel(self.listbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.listbook.AddPage(page_7, "Français", False, 1)
        page_7.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_2 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_3 = wx.StaticText(page_7, wx.ID_ANY,
            "Ceci est une phrase en français.")
        parent_sizer_2.Add(self.staticText_3, wx.SizerFlags().Border(wx.ALL))
        page_7.SetSizerAndFit(parent_sizer_2)

        page_8 = wx.Panel(self.listbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.listbook.AddPage(page_8, "日本語", False, 2)
        page_8.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_3 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_7 = wx.StaticText(page_8, wx.ID_ANY,
            "これは日本語の文章です。")
        parent_sizer_3.Add(self.staticText_7, wx.SizerFlags().Border(wx.ALL))
        page_8.SetSizerAndFit(parent_sizer_3)

        page_3.SetSizerAndFit(page_sizer_2)

        page_4 = wx.Panel(self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook.AddPage(page_4, "NoteBook")

        page_sizer_3 = wx.BoxSizer(wx.VERTICAL)

        self.notebook_2 = wx.Notebook(page_4, wx.ID_ANY)

        bundle_1 = wx.BitmapBundle.FromBitmap(images.english_png.Bitmap)
        bundle_2 = wx.BitmapBundle.FromBitmap(images.french_png.Bitmap)
        bundle_3 = wx.BitmapBundle.FromBitmap(images.japanese_png.Bitmap)
        bundle_list = [
            bundle_1,
            bundle_2,
            bundle_3
        ]
        self.notebook_2.SetImages(bundle_list)
        self.notebook_2.SetMinSize(wx.Size(400, 400))
        page_sizer_3.Add(self.notebook_2, wx.SizerFlags().Expand().Border(wx.ALL))

        page_9 = wx.Panel(self.notebook_2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook_2.AddPage(page_9, "English", False, 0)
        page_9.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_4 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_4 = wx.StaticText(page_9, wx.ID_ANY,
            "This is a sentence in English.")
        parent_sizer_4.Add(self.staticText_4, wx.SizerFlags().Border(wx.ALL))
        page_9.SetSizerAndFit(parent_sizer_4)

        page_10 = wx.Panel(self.notebook_2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook_2.AddPage(page_10, "Français", False, 1)
        page_10.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_5 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_8 = wx.StaticText(page_10, wx.ID_ANY,
            "Ceci est une phrase en français.")
        parent_sizer_5.Add(self.staticText_8, wx.SizerFlags().Border(wx.ALL))
        page_10.SetSizerAndFit(parent_sizer_5)

        page_11 = wx.Panel(self.notebook_2, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook_2.AddPage(page_11, "日本語", False, 2)
        page_11.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_6 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_9 = wx.StaticText(page_11, wx.ID_ANY,
            "これは日本語の文章です。")
        parent_sizer_6.Add(self.staticText_9, wx.SizerFlags().Border(wx.ALL))
        page_11.SetSizerAndFit(parent_sizer_6)

        page_4.SetSizerAndFit(page_sizer_3)

        page_5 = wx.Panel(self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook.AddPage(page_5, "ToolBook")

        page_sizer_4 = wx.BoxSizer(wx.VERTICAL)

        self.toolbook = wx.Toolbook(page_5, wx.ID_ANY)

        bundle_1 = wx.BitmapBundle.FromBitmap(images.english_png.Bitmap)
        bundle_2 = wx.BitmapBundle.FromBitmap(images.french_png.Bitmap)
        bundle_3 = wx.BitmapBundle.FromBitmap(images.japanese_png.Bitmap)
        bundle_list = [
            bundle_1,
            bundle_2,
            bundle_3
        ]
        self.toolbook.SetImages(bundle_list)
        self.toolbook.SetMinSize(wx.Size(400, 400))
        page_sizer_4.Add(self.toolbook, wx.SizerFlags().Border(wx.ALL))

        page_12 = wx.Panel(self.toolbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.toolbook.AddPage(page_12, "English", False, 0)
        page_12.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_7 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_5 = wx.StaticText(page_12, wx.ID_ANY,
            "This is a sentence in English.")
        parent_sizer_7.Add(self.staticText_5, wx.SizerFlags().Border(wx.ALL))
        page_12.SetSizerAndFit(parent_sizer_7)

        page_13 = wx.Panel(self.toolbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.toolbook.AddPage(page_13, "Français", False, 1)
        page_13.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_8 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_10 = wx.StaticText(page_13, wx.ID_ANY,
            "Ceci est une phrase en français.")
        parent_sizer_8.Add(self.staticText_10, wx.SizerFlags().Border(wx.ALL))
        page_13.SetSizerAndFit(parent_sizer_8)

        page_14 = wx.Panel(self.toolbook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.toolbook.AddPage(page_14, "日本語", False, 2)
        page_14.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_9 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_11 = wx.StaticText(page_14, wx.ID_ANY,
            "これは日本語の文章です。")
        parent_sizer_9.Add(self.staticText_11, wx.SizerFlags().Border(wx.ALL))
        page_14.SetSizerAndFit(parent_sizer_9)

        page_5.SetSizerAndFit(page_sizer_4)

        page = wx.Panel(self.notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.notebook.AddPage(page, "TreeBook")

        page_sizer_5 = wx.BoxSizer(wx.VERTICAL)

        self.treebook = wx.Treebook(page, wx.ID_ANY)

        bundle_1 = wx.BitmapBundle.FromBitmap(images.english_png.Bitmap)
        bundle_2 = wx.BitmapBundle.FromBitmap(images.french_png.Bitmap)
        bundle_3 = wx.BitmapBundle.FromBitmap(images.japanese_png.Bitmap)
        bundle_list = [
            bundle_1,
            bundle_2,
            bundle_3
        ]
        self.treebook.SetImages(bundle_list)
        self.treebook.SetMinSize(wx.Size(400, 400))
        page_sizer_5.Add(self.treebook, wx.SizerFlags().Border(wx.ALL))

        page_15 = wx.Panel(self.treebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.treebook.AddPage(page_15, "English", False, 0)
        page_15.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_10 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_12 = wx.StaticText(page_15, wx.ID_ANY,
            "This is a sentence in English.")
        parent_sizer_10.Add(self.staticText_12, wx.SizerFlags().Border(wx.ALL))
        page_15.SetSizerAndFit(parent_sizer_10)

        page_16 = wx.Panel(self.treebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.treebook.AddSubPage(page_16, "British", False, 1)
        page_16.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        page_sizer = wx.BoxSizer(wx.VERTICAL)

        self.staticText_13 = wx.StaticText(page_16, wx.ID_ANY, "Theatre")
        page_sizer.Add(self.staticText_13, wx.SizerFlags().Border(wx.ALL))
        page_16.SetSizerAndFit(page_sizer)

        page_17 = wx.Panel(self.treebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.treebook.AddSubPage(page_17, "United States", False, 2)
        page_17.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        page_sizer_6 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_14 = wx.StaticText(page_17, wx.ID_ANY, "Theater")
        page_sizer_6.Add(self.staticText_14, wx.SizerFlags().Border(wx.ALL))
        page_17.SetSizerAndFit(page_sizer_6)

        page_18 = wx.Panel(self.treebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.treebook.AddPage(page_18, "Français", False, 3)
        page_18.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_11 = wx.BoxSizer(wx.VERTICAL)

        self.staticText_15 = wx.StaticText(page_18, wx.ID_ANY,
            "Ceci est une phrase en français.")
        parent_sizer_11.Add(self.staticText_15, wx.SizerFlags().Border(wx.ALL))
        page_18.SetSizerAndFit(parent_sizer_11)

        page_19 = wx.Panel(self.treebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.treebook.AddPage(page_19, "日本語", False, 4)
        page_19.SetBackgroundColour(wx.SystemSettings.GetColour(wx.SYS_COLOUR_BTNFACE))

        parent_sizer_12 = wx.BoxSizer(wx.VERTICAL)

        self.staticText = wx.StaticText(page_19, wx.ID_ANY,
            "これは日本語の文章です。")
        parent_sizer_12.Add(self.staticText, wx.SizerFlags().Border(wx.ALL))
        page_19.SetSizerAndFit(parent_sizer_12)

        page.SetSizerAndFit(page_sizer_5)

        if "wxMac" not in wx.PlatformInfo:
            stdBtn_line = wx.StaticLine(self, wx.ID_ANY, wx.DefaultPosition, wx.Size(20, -1))
            dlg_sizer.Add(stdBtn_line, wx.SizerFlags().Expand().Border(wx.ALL))

        stdBtn = wx.StdDialogButtonSizer()
        stdBtn_OK = wx.Button(self, wx.ID_OK)
        stdBtn.SetAffirmativeButton(stdBtn_OK)
        stdBtn_Cancel = wx.Button(self, wx.ID_CANCEL)
        stdBtn.SetCancelButton(stdBtn_Cancel)
        stdBtn_OK.SetDefault()
        stdBtn.Realize()
        dlg_sizer.Add(stdBtn, wx.SizerFlags().Expand().Border(wx.ALL))

        self.SetSizerAndFit(dlg_sizer)
        self.Centre(wx.BOTH)

        # Bind Event handlers
        btn.Bind(wx.EVT_BUTTON, lambda event:self.m_choicebook.SetSelection(0))
        btn_2.Bind(wx.EVT_BUTTON, lambda event:self.m_choicebook.SetSelection(2))

    # Event handler functions
    # Add these below the comment block, or to your inherited class.
    """
    """

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
