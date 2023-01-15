###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx
import wx.adv
import wx.richtext
import wx.stc

from wx.lib.embeddedimage import PyEmbeddedImage

normal_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABrklE"
    b"QVQ4y6WTsW7aYBSFP9eGgXiwVFpFgqGoRE4kpsoDAwvPwFIpvAWPwRNk95BOYWJHLAz/AyCHAQ/YITWJ"
    b"41hCBcHfIdgktdMOPdP/X91z7tXRPQoJrq4kmganp2mJ52d4eiKDXg/iWAHQ0qKmwc0NnJ8fG+/v4e4O"
    b"pHz5K8rxndCSx/XJSVleXgaKoqBpGvv9nt1ulzO8h3eY/kagXq8DoOs6pmkSBAGu62YECoVC/gYJHMdh"
    b"OBzSaDQQQgBQLpeZTqe0Wq2MYLqKEEKxLEs2m81Zu93+ulgs0HUdgCiKqFQqjEaj2WQyOTvw5BuB1+h2"
    b"u1LX9dQDVVWJ4xjbtmvAPHeDPJFisQjAZrPBtu3PwM8/+7Q8shDik2EYhGHIYDBgPp+/Nwc1h/zFMIzF"
    b"drulVCpRq9WQUrJcLs983//xVxOBb4ZhCIBqtcpqtcL3fQA8z6Pf78/G43G+iUKIj0DwrzvodDq4rpvy"
    b"PvCfSE2crddIoAT8Wq0Iowhvvc4Qtu9l4bvjBKgqmCbc3r4UHx/h4EEKy4KHB5mk8XgHFxfZOMcxhGE2"
    b"iY4Du50C8BtZArk344GL9AAAAABJRU5ErkJggg==")

focus_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABt0lE"
    b"QVQ4y82TsYriUBSGv0RjIRkT8I6MsQgLCtYSEAux2t4pF/IavoQg1tOnHNhHEMQihWzljAZZVkUG2bUI"
    b"Q3ZTJMPdYpVxVqfe/ct7zvk53zn3wL+Xrkt0Xf71qlzIVM7qMhmpcHcnub/HenhA0zQA1uv1JQNs25YA"
    b"iZQ8OQ7M52T/eCsMBgNqtRqbzYZ+v7/0ff8jsDoWt9vt5XA4BGAZx3x6fIT5HBUA+UowmUzodDpV13W/"
    b"AdfAdaPR+Nzr9arnUMqhgxPV63XG4zG6ruO67neAZrOJZVnnTFK+Ihy13+8pFAokSUIul8OyLFqt1rs7"
    b"UDEMuLl5N6Hb7WIYBuVy+W2gXAbTJMvVFZRKZDIZbNvGcRwWiwX5fJ44jjFNkyRJKBaL5HI5AH4+P0M2"
    b"C7p+GCKgqipCCGazGZVKhSiK8DxPCcOwpGka2+0WIQRCCEzDOEE4KE1TgiCgWq0yGo2+ep6nADiO8yMM"
    b"ww8AQRAQBAGr1erEYLeDxQIpJVEUYVkWvu+/WZnjOKswDJ0oioiiiF9xDEEAux0qaQq3tyiKIgABiOl0"
    b"euknfjnGFRC8vECa/ge3+Bu3SZx0Dp9YSwAAAABJRU5ErkJggg==")

no_hour_png = PyEmbeddedImage(
    b"iVBORw0KGgoAAAANSUhEUgAAABAAAAAQCAYAAAAf8/9hAAAACXBIWXMAAAsTAAALEwEAmpwYAAABDUlE"
    b"QVQ4y52TMWrDMBSGP4U0NyhZAx08ZoghFxH0CCFracB3SC+QG3QIGT2YXCDwvHgvZE26BLqlw+tQW0iq"
    b"mpr+YGRL/j6eLT2joABms4HxmCCnE8ksFt8QYDoBgFmvwxcPhySv2627NwC+5CWWRHlerXzYGGf1JJ/X"
    b"K03T/IBneR7AAINuohZxi3ejEWVZArgxBQcRkaW1VhXcZa3VoiiCOWBJStBmmmXZhw9E8JSeqRJw/4jI"
    b"/b8FIjK58Qk3QSMijz4gIioiKYn7iQPP8TTL89fu4f18JrXFrUSJTUGJqtR13f8gxfBvSVTCMOiD/Z6H"
    b"4xGAt8slKcm9+hXUBO08n//djVUFux3aVvoF3WivIiuis94AAAAASUVORK5CYII=")

import popupwin

class MainTestDialog(wx.Dialog):
    def __init__(self, parent, id=wx.ID_ANY, title="", pos=
                wx.DefaultPosition, size=wx.DefaultSize,
                style=wx.DEFAULT_DIALOG_STYLE, name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        dlg_sizer = wx.BoxSizer(wx.VERTICAL)

        self.m_notebook = wx.Notebook(self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.BK_TOP|wx.NB_MULTILINE)
        dlg_sizer.Add(self.m_notebook, wx.SizerFlags().Expand().Border(wx.ALL))

        page_2 = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page_2, "Text")

        page_sizer_1 = wx.BoxSizer(wx.VERTICAL)

        self.m_text_ctrl = wx.TextCtrl(page_2, wx.ID_ANY, "", wx.DefaultPosition,
            wx.DefaultSize, wx.TE_RICH2)
        self.m_text_ctrl.SetHint("wxTextCtrl")
        page_sizer_1.Add(self.m_text_ctrl, wx.SizerFlags().Expand().Border(wx.ALL))

        self.m_richText = wx.richtext.RichTextCtrl(page_2, wx.ID_ANY, "",
            wx.DefaultPosition, wx.DefaultSize, wx.richtext.RE_MULTILINE|
        wx.VSCROLL|wx.HSCROLL|wx.NO_BORDER|wx.WANTS_CHARS)
        self.m_richText.SetHint("wxRichTextCtrl")
        self.m_richText.SetMinSize(self.ConvertDialogToPixels(wx.Size(150, 30)))
        page_sizer_1.Add(self.m_richText, wx.SizerFlags().Expand().Border(wx.ALL))

        self.m_scintilla = wx.stc.StyledTextCtrl(page_2, wx.ID_ANY)
        self.m_scintilla.SetLexer(wx.stc.STC_LEX_CPP)
        self.m_scintilla.SetEOLMode(wx.stc.STC_EOL_LF)
        self.m_scintilla.SetViewWhiteSpace(wx.stc.STC_WS_VISIBLEALWAYS)
        # Sets text margin scaled appropriately for the current DPI on Windows,
        # 5 on wxGTK or wxOSX
        self.m_scintilla.SetMarginLeft(wx.SizerFlags.GetDefaultBorder())
        self.m_scintilla.SetMarginRight(wx.SizerFlags.GetDefaultBorder())
        self.m_scintilla.SetMarginWidth(1, 0) # Remove default margin
        self.m_scintilla.SetBackSpaceUnIndents(True)
        self.m_scintilla.SetMinSize(self.ConvertDialogToPixels(wx.Size(150, 60)))
        page_sizer_1.Add(self.m_scintilla, wx.SizerFlags().Expand().Border(wx.ALL))
        page_2.SetSizerAndFit(page_sizer_1)

        page_4 = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page_4, "Buttons")

        box_sizer_3 = wx.BoxSizer(wx.VERTICAL)

        grid_bag_sizer = wx.GridBagSizer()

        self.m_btn = wx.Button(page_4, wx.ID_ANY, "Normal")
        self.m_btn.SetToolTip("A normal button")
        grid_bag_sizer.Add(self.m_btn, wx.GBPosition(0, 0), wx.GBSpan(1, 1), wx.ALL, 5)

        self.m_btn_2 = wx.Button(page_4, wx.ID_ANY, wx.EmptyString)
        self.m_btn_2.SetLabelMarkup("<b><span foreground=\'red\'>Markup</span></b>")
        self.m_btn_2.SetToolTip("Text should be Bold and Red.")
        grid_bag_sizer.Add(self.m_btn_2, wx.GBPosition(0, 1), wx.GBSpan(1, 1), wx.ALL, 5)

        self.m_btn_bitmaps = wx.Button(page_4, wx.ID_ANY, "Bitmaps")
        self.m_btn_bitmaps.SetBitmap(wx.BitmapBundle.FromBitmap(normal_png.Bitmap))
        self.m_btn_bitmaps.SetBitmapDisabled(wx.BitmapBundle.FromBitmap(
            no_hour_png.Bitmap))
        self.m_btn_bitmaps.SetBitmapCurrent(wx.BitmapBundle.FromBitmap(focus_png.Bitmap))
        self.m_btn_bitmaps.SetToolTip(
        "Bitmap should change when mouse is over button, or button is disabled.")
        grid_bag_sizer.Add(self.m_btn_bitmaps, wx.GBPosition(0, 2), wx.GBSpan(1, 1), wx.ALL,
            5)

        self.m_btn_4 = wx.Button(page_4, wx.ID_ANY, "Right")
        self.m_btn_4.SetBitmapPosition(wx.RIGHT)
        self.m_btn_4.SetBitmap(wx.BitmapBundle.FromBitmap(normal_png.Bitmap))
        self.m_btn_4.SetToolTip(
        "Bitmap should be on the right side (fails in wxPython 4.2).")
        grid_bag_sizer.Add(self.m_btn_4, wx.GBPosition(0, 3), wx.GBSpan(1, 1), wx.ALL, 5)

        self.m_toggleBtn = wx.ToggleButton(page_4, wx.ID_ANY, "Toggle", wx.DefaultPosition,
            wx.DefaultSize, wx.BU_EXACTFIT)
        self.m_toggleBtn.SetToolTip(
        "Style set to exact fit, so it should be a bit smaller than usual.")
        grid_bag_sizer.Add(self.m_toggleBtn, wx.GBPosition(0, 4), wx.GBSpan(1, 1), wx.ALL,
            5)

        disable_bitmaps = wx.CheckBox(page_4, wx.ID_ANY, "Disable")
        disable_bitmaps.SetToolTip(
        "This will change the enable state and bitmap of the Bitmaps button.")
        grid_bag_sizer.Add(disable_bitmaps, wx.GBPosition(2, 2), wx.GBSpan(1, 1), wx.ALL,
            5)

        box_sizer_3.Add(grid_bag_sizer, wx.SizerFlags().Border(wx.ALL))

        box_sizer_7 = wx.BoxSizer(wx.HORIZONTAL)

        self.m_btn_5 = wx.adv.CommandLinkButton(page_4, wx.ID_ANY, "Command",
            "wxCommandLinkButton")
        self.m_btn_5.SetBitmap(wx.ArtProvider.GetBitmapBundle(wx.ART_GO_FORWARD,
            wx.ART_OTHER))
        self.m_btn_5.SetToolTip("The bitmap for this is from Art Provider.")
        box_sizer_7.Add(self.m_btn_5, wx.SizerFlags().Border(wx.ALL))

        # Trailing spaces added to avoid clipping
        radioBox = wx.RadioBox(page_4, wx.ID_ANY, "Radio Box", wx.DefaultPosition,
            wx.DefaultSize, ["Button zero ","Button one ","Button two "], 0,
            wx.RA_SPECIFY_ROWS)
        radioBox.SetSelection(1)
        box_sizer_7.Add(radioBox, wx.SizerFlags().Border(wx.ALL))

        box_sizer_3.Add(box_sizer_7, wx.SizerFlags().Border(wx.ALL))

        box_sizer2 = wx.BoxSizer(wx.HORIZONTAL)

        self.m_btn_3 = wx.Button(page_4, wx.ID_ANY, "First btn")
        box_sizer2.Add(self.m_btn_3, wx.SizerFlags().Border(wx.ALL))

        btn2 = wx.Button(page_4, wx.ID_ANY, "Popup")
        box_sizer2.Add(btn2, wx.SizerFlags().Border(wx.ALL))

        self.m_radioBtn = wx.RadioButton(page_4, wx.ID_ANY, "First radio",
            wx.DefaultPosition, wx.DefaultSize, wx.RB_GROUP)
        box_sizer2.Add(self.m_radioBtn, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_radioBtn2 = wx.RadioButton(page_4, wx.ID_ANY, "Second radio")
        box_sizer2.Add(self.m_radioBtn2, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_checkBox2 = wx.CheckBox(page_4, wx.ID_ANY, "Checkbox")
        box_sizer2.Add(self.m_checkBox2, wx.SizerFlags().Center().Border(wx.ALL))

        box_sizer_3.Add(box_sizer2, wx.SizerFlags().Expand().Border(wx.ALL))
        page_4.SetSizerAndFit(box_sizer_3)

        page_5 = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page_5, "Lists")

        box_sizer_5 = wx.BoxSizer(wx.VERTICAL)

        flex_grid_sizer = wx.FlexGridSizer(2, 0, 0)

        box_sizer_10 = wx.BoxSizer(wx.VERTICAL)

        self.m_staticText_2 = wx.StaticText(page_5, wx.ID_ANY, "wxRearrangeCtrl")
        box_sizer_10.Add(self.m_staticText_2, wx.SizerFlags().Expand().Border(wx.ALL))

        self.m_rearrange = wx.RearrangeCtrl(page_5, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, [], [])
        box_sizer_10.Add(self.m_rearrange, wx.SizerFlags().Border(wx.ALL))

        flex_grid_sizer.Add(box_sizer_10, wx.SizerFlags().Border(wx.ALL))

        box_sizer_11 = wx.BoxSizer(wx.VERTICAL)

        staticText_3 = wx.StaticText(page_5, wx.ID_ANY, "wxCheckListBox")
        box_sizer_11.Add(staticText_3, wx.SizerFlags().Expand().Border(wx.ALL))

        self.m_checkList = wx.CheckListBox(page_5, wx.ID_ANY)
        box_sizer_11.Add(self.m_checkList, wx.SizerFlags().Border(wx.ALL))

        flex_grid_sizer.Add(box_sizer_11, wx.SizerFlags().Border(wx.ALL))

        box_sizer_12 = wx.BoxSizer(wx.VERTICAL)

        self.m_staticText_4 = wx.StaticText(page_5, wx.ID_ANY, "wxListView")
        box_sizer_12.Add(self.m_staticText_4, wx.SizerFlags().Border(wx.ALL))

        self.m_listview = wx.ListView(page_5, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, wx.LC_SINGLE_SEL|wx.LC_REPORT)
        self.m_listview.AppendColumn("name")
        self.m_listview.AppendColumn("value")
        info = wx.ListItem()
        info.Clear()
        info.SetId(0)
        idx = self.m_listview.InsertItem(info)
        self.m_listview.SetItem(idx, 0, "meaning")
        self.m_listview.SetItem(idx, 1, "42")
        self.m_listview.SetToolTip("Separate content columns with a semi-colon (;)")
        box_sizer_12.Add(self.m_listview, wx.SizerFlags().Border(wx.ALL))

        flex_grid_sizer.Add(box_sizer_12, wx.SizerFlags().Border(wx.ALL))

        box_sizer_13 = wx.BoxSizer(wx.HORIZONTAL)

        self.m_edit_listbox = wx.adv.EditableListBox(page_5, wx.ID_ANY,
            "My Editable ListBox", wx.DefaultPosition, wx.DefaultSize,
            wx.adv.EL_ALLOW_NEW|wx.adv.EL_ALLOW_EDIT|wx.adv.EL_ALLOW_DELETE)
        box_sizer_13.Add(self.m_edit_listbox, wx.SizerFlags().Border(wx.ALL))

        flex_grid_sizer.Add(box_sizer_13, wx.SizerFlags().Border(wx.ALL))

        box_sizer_5.Add(flex_grid_sizer, wx.SizerFlags().Border(wx.ALL))
        page_5.SetSizerAndFit(box_sizer_5)

        page_3 = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page_3, "Combos")

        page_sizer_2 = wx.BoxSizer(wx.VERTICAL)

        static_box = wx.StaticBoxSizer(wx.VERTICAL, page_3, "Combos and Choices")

        box_sizer3 = wx.BoxSizer(wx.HORIZONTAL)

        static_box_sizer2 = wx.StaticBoxSizer(wx.VERTICAL, static_box.GetStaticBox(),
            "Combo")

        self.m_staticText3 = wx.StaticText(static_box_sizer2.GetStaticBox(), wx.ID_ANY,
            "Unsorted")
        static_box_sizer2.Add(self.m_staticText3, wx.SizerFlags().Border(wx.ALL))

        self.m_comboBox = wx.ComboBox(static_box_sizer2.GetStaticBox(), wx.ID_ANY)
        self.m_comboBox.Append("item #1")
        self.m_comboBox.Append("item #2")
        self.m_comboBox.Append("item #0")
        self.m_comboBox.SetStringSelection("item #2")
        self.m_comboBox.SetToolTip("Item #0 should be selected by default")
        static_box_sizer2.Add(self.m_comboBox, wx.SizerFlags().Expand().Border(wx.ALL))

        self.m_staticText4 = wx.StaticText(static_box_sizer2.GetStaticBox(), wx.ID_ANY,
            "Sorted")
        static_box_sizer2.Add(self.m_staticText4, wx.SizerFlags().Border(wx.ALL))

        self.m_comboBox2 = wx.ComboBox(static_box_sizer2.GetStaticBox(), wx.ID_ANY,
            wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, [], wx.CB_SORT)
        self.m_comboBox2.Append("item #1")
        self.m_comboBox2.Append("item #2")
        self.m_comboBox2.Append("item #0")
        self.m_comboBox2.SetStringSelection("item #2")
        self.m_comboBox2.SetToolTip("Item #2 should be selected by default")
        static_box_sizer2.Add(self.m_comboBox2, wx.SizerFlags().Border(wx.ALL))

        box_sizer3.Add(static_box_sizer2, wx.SizerFlags().Expand().Border(wx.ALL))

        static_box_sizer3 = wx.StaticBoxSizer(wx.VERTICAL, static_box.GetStaticBox(),
            "Choice")

        self.m_staticText5 = wx.StaticText(static_box_sizer3.GetStaticBox(), wx.ID_ANY,
            "Unsorted")
        static_box_sizer3.Add(self.m_staticText5, wx.SizerFlags().Border(wx.ALL))

        self.m_choice = wx.Choice(static_box_sizer3.GetStaticBox(), wx.ID_ANY)
        self.m_choice.Append("item #1")
        self.m_choice.Append("item #2")
        self.m_choice.Append("item #0")
        self.m_choice.SetSelection(2)
        self.m_choice.SetToolTip("Item #0 should be selected by default")
        static_box_sizer3.Add(self.m_choice, wx.SizerFlags().Border(wx.ALL))

        self.m_staticText6 = wx.StaticText(static_box_sizer3.GetStaticBox(), wx.ID_ANY,
            "Sorted")
        static_box_sizer3.Add(self.m_staticText6, wx.SizerFlags().Border(wx.ALL))

        self.m_choice2 = wx.Choice(static_box_sizer3.GetStaticBox(), wx.ID_ANY,
            wx.DefaultPosition, wx.DefaultSize, [], wx.CB_SORT)
        self.m_choice2.Append("item #1")
        self.m_choice2.Append("item #2")
        self.m_choice2.Append("item #0")
        self.m_choice2.SetSelection(2)
        self.m_choice2.SetToolTip("Item #2 should be selected by default")
        static_box_sizer3.Add(self.m_choice2, wx.SizerFlags().Border(wx.ALL))

        box_sizer3.Add(static_box_sizer3, wx.SizerFlags().Expand().Border(wx.ALL))

        static_box_sizer4 = wx.StaticBoxSizer(wx.VERTICAL, static_box.GetStaticBox(),
            "List")

        self.m_staticText7 = wx.StaticText(static_box_sizer4.GetStaticBox(), wx.ID_ANY,
            "Unsorted")
        static_box_sizer4.Add(self.m_staticText7, wx.SizerFlags().Border(wx.ALL))

        self.m_listbox = wx.ListBox(static_box_sizer4.GetStaticBox(), wx.ID_ANY)
        self.m_listbox.Append("item #1")
        self.m_listbox.Append("item #2")
        self.m_listbox.Append("item #0")
        static_box_sizer4.Add(self.m_listbox, wx.SizerFlags().Border(wx.ALL))

        self.m_staticText8 = wx.StaticText(static_box_sizer4.GetStaticBox(), wx.ID_ANY,
            "Sorted")
        static_box_sizer4.Add(self.m_staticText8, wx.SizerFlags().Border(wx.ALL))

        self.m_listBox2 = wx.ListBox(static_box_sizer4.GetStaticBox(), wx.ID_ANY,
            wx.DefaultPosition, wx.DefaultSize, [], wx.LB_SINGLE|wx.LB_SORT)
        self.m_listBox2.Append("item #1")
        self.m_listBox2.Append("item #2")
        self.m_listBox2.Append("item #0")
        static_box_sizer4.Add(self.m_listBox2, wx.SizerFlags().Border(wx.ALL))

        box_sizer3.Add(static_box_sizer4, wx.SizerFlags().Expand().Border(wx.ALL))

        static_box_sizer5 = wx.StaticBoxSizer(wx.VERTICAL, static_box.GetStaticBox(),
            "Checked")

        self.m_staticText9 = wx.StaticText(static_box_sizer5.GetStaticBox(), wx.ID_ANY,
            "Unsorted")
        static_box_sizer5.Add(self.m_staticText9, wx.SizerFlags().Border(wx.ALL))

        self.m_checkList_2 = wx.CheckListBox(static_box_sizer5.GetStaticBox(), wx.ID_ANY)
        self.m_checkList_2.Append("item #1")
        self.m_checkList_2.Append("item #2")
        self.m_checkList_2.Append("item #0")
        static_box_sizer5.Add(self.m_checkList_2, wx.SizerFlags().Border(wx.ALL))

        self.m_staticText10 = wx.StaticText(static_box_sizer5.GetStaticBox(), wx.ID_ANY,
            "Sorted")
        static_box_sizer5.Add(self.m_staticText10, wx.SizerFlags().Border(wx.ALL))

        self.m_checkList2 = wx.CheckListBox(static_box_sizer5.GetStaticBox(), wx.ID_ANY,
            wx.DefaultPosition, wx.DefaultSize, [], wx.LB_SINGLE|wx.LB_SORT)
        self.m_checkList2.Append("item #1")
        self.m_checkList2.Append("item #2")
        self.m_checkList2.Append("item #0")
        static_box_sizer5.Add(self.m_checkList2, wx.SizerFlags().Border(wx.ALL))

        box_sizer3.Add(static_box_sizer5, wx.SizerFlags().Expand().Border(wx.ALL))

        static_box.Add(box_sizer3, wx.SizerFlags().Expand().Border(wx.ALL))

        page_sizer_2.Add(static_box, wx.SizerFlags().Expand().Border(wx.ALL))
        page_3.SetSizerAndFit(page_sizer_2)

        page_6 = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.BORDER_THEME|wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page_6, "Pickers")

        parent_sizer2 = wx.BoxSizer(wx.VERTICAL)

        static_box_2 = wx.StaticBoxSizer(wx.VERTICAL, page_6, "Pickers")

        box_sizer = wx.BoxSizer(wx.HORIZONTAL)

        staticText__2 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "File:")
        box_sizer.Add(staticText__2, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_filePicker = wx.FilePickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.EmptyString, wx.FileSelectorPromptStr, "BMP files|*.bmp", wx.DefaultPosition,
            wx.DefaultSize, wx.FLP_USE_TEXTCTRL|wx.FLP_OPEN|wx.FLP_FILE_MUST_EXIST)
        box_sizer.Add(self.m_filePicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer, wx.SizerFlags().Border(wx.ALL))

        box_sizer_2 = wx.BoxSizer(wx.HORIZONTAL)

        staticText__3 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "Directory:")
        box_sizer_2.Add(staticText__3, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_dirPicker = wx.DirPickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY, ".",
            wx.DirSelectorPromptStr, wx.DefaultPosition, wx.DefaultSize,
            wx.DIRP_DEFAULT_STYLE|wx.DIRP_SMALL)
        box_sizer_2.Add(self.m_dirPicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer_2, wx.SizerFlags().Border(wx.ALL))

        box_sizer_4 = wx.BoxSizer(wx.HORIZONTAL)

        staticText__4 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "Colour:")
        box_sizer_4.Add(staticText__4, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_colourPicker = wx.ColourPickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.BLACK)
        box_sizer_4.Add(self.m_colourPicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer_4, wx.SizerFlags().Border(wx.ALL))

        box_sizer_6 = wx.BoxSizer(wx.HORIZONTAL)

        staticText__5 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "Date:")
        box_sizer_6.Add(staticText__5, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_datePicker = wx.adv.DatePickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.DefaultDateTime)
        box_sizer_6.Add(self.m_datePicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer_6, wx.SizerFlags().Border(wx.ALL))

        box_sizer_8 = wx.BoxSizer(wx.HORIZONTAL)

        staticText__6 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "Time:")
        box_sizer_8.Add(staticText__6, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_timePicker = wx.adv.TimePickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.DefaultDateTime)
        box_sizer_8.Add(self.m_timePicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer_8, wx.SizerFlags().Border(wx.ALL))

        box_sizer_9 = wx.BoxSizer(wx.HORIZONTAL)

        staticText__7 = wx.StaticText(static_box_2.GetStaticBox(), wx.ID_ANY, "Font:")
        box_sizer_9.Add(staticText__7, wx.SizerFlags().Center().Border(wx.ALL))

        self.m_fontPicker = wx.FontPickerCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.Font(wx.NORMAL_FONT.GetPointSize(), wx.FONTFAMILY_DEFAULT, wx.FONTSTYLE_NORMAL,
            wx.FONTWEIGHT_NORMAL, False, "Comic Sans MS"), wx.DefaultPosition, wx.DefaultSize,
            wx.FNTP_DEFAULT_STYLE|wx.FNTP_USE_TEXTCTRL)
        box_sizer_9.Add(self.m_fontPicker, wx.SizerFlags().Border(wx.ALL))

        static_box_2.Add(box_sizer_9, wx.SizerFlags().Border(wx.ALL))

        parent_sizer2.Add(static_box_2, wx.SizerFlags().Expand().Border(wx.ALL))
        page_6.SetSizerAndFit(parent_sizer2)

        page = wx.Panel(self.m_notebook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)
        self.m_notebook.AddPage(page, "Tab 3")

        page_sizer_3 = wx.BoxSizer(wx.VERTICAL)

        self.m_staticText = wx.StaticText(page, wx.ID_ANY,
            "TODO: replace this control with something more useful...")
        self.m_staticText.Wrap(200)
        page_sizer_3.Add(self.m_staticText, wx.SizerFlags().Border(wx.ALL))
        page.SetSizerAndFit(page_sizer_3)

        box_sizer_14 = wx.BoxSizer(wx.HORIZONTAL)

        staticText_4 = wx.StaticText(self, wx.ID_ANY, "Events:")
        box_sizer_14.Add(staticText_4, wx.SizerFlags().Center().Border(wx.ALL))

        btn = wx.Button(self, wx.ID_ANY, "Clear Events")
        box_sizer_14.Add(btn, wx.SizerFlags().Border(wx.ALL))

        dlg_sizer.Add(box_sizer_14, wx.SizerFlags().Border(wx.ALL))

        self.m_events_list = wx.ListBox(self, wx.ID_ANY)
        self.m_events_list.SetMinSize(self.ConvertDialogToPixels(wx.Size(-1, 60)))
        dlg_sizer.Add(self.m_events_list, wx.SizerFlags().Expand().Border(wx.ALL))

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
        self.m_btn.Bind(wx.EVT_BUTTON, self.OnButton)
        self.m_btn_bitmaps.Bind(wx.EVT_BUTTON, self.OnButton)
        self.m_btn_5.Bind(wx.EVT_BUTTON, self.OnButton)
        self.m_btn_3.Bind(wx.EVT_BUTTON, self.OnButton)
        btn2.Bind(wx.EVT_BUTTON, self.OnPopupBtn)
        btn.Bind(wx.EVT_BUTTON, self.OnClearList)
        disable_bitmaps.Bind(wx.EVT_CHECKBOX, self.OnDisableBitmapsBtn)
        self.m_checkBox2.Bind(wx.EVT_CHECKBOX, self.OnCheckBox)
        self.m_checkList_2.Bind(wx.EVT_CHECKLISTBOX, self.OnListChecked)
        self.m_checkList2.Bind(wx.EVT_CHECKLISTBOX, self.OnListChecked)
        self.m_choice.Bind(wx.EVT_CHOICE, self.OnChoice)
        self.m_choice2.Bind(wx.EVT_CHOICE, self.OnChoice)
        self.m_colourPicker.Bind(wx.EVT_COLOURPICKER_CHANGED, self.OnColourChanged)
        self.m_comboBox.Bind(wx.EVT_COMBOBOX, self.OnCombobox)
        self.m_comboBox2.Bind(wx.EVT_COMBOBOX, self.OnCombobox)
        self.m_datePicker.Bind(wx.adv.EVT_DATE_CHANGED, self.OnDateChanged)
        self.m_dirPicker.Bind(wx.EVT_DIRPICKER_CHANGED, self.OnDirChanged)
        self.m_filePicker.Bind(wx.EVT_FILEPICKER_CHANGED, self.OnFileChanged)
        self.m_fontPicker.Bind(wx.EVT_FONTPICKER_CHANGED, self.OnFontChanged)
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInit)
        self.m_listbox.Bind(wx.EVT_LISTBOX, self.OnListBox)
        self.m_listBox2.Bind(wx.EVT_LISTBOX, self.OnListBox)
        self.m_notebook.Bind(wx.EVT_NOTEBOOK_PAGE_CHANGED, self.OnPageChanged)
        radioBox.Bind(wx.EVT_RADIOBOX, self.OnRadioBox)
        self.m_radioBtn.Bind(wx.EVT_RADIOBUTTON, self.OnRadioButton)
        self.m_radioBtn2.Bind(wx.EVT_RADIOBUTTON, self.OnRadioButton)
        self.m_scintilla.Bind(wx.stc.EVT_STC_CHANGE, self.OnStcChange)
        self.m_text_ctrl.Bind(wx.EVT_TEXT, self.OnText)
        self.m_richText.Bind(wx.EVT_TEXT, self.OnRichText)
        self.m_timePicker.Bind(wx.adv.EVT_TIME_CHANGED, self.OnTimeChanged)
        self.m_toggleBtn.Bind(wx.EVT_TOGGLEBUTTON, self.OnToggle)

    # Unimplemented Event handler functions
    # Copy any listed and paste them below the comment block, or to your inherited class.
    """
    """

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

    def OnInit(self, event):
        event.Skip()

    def OnClearList(self, event):
        self.m_events_list.Clear()

    def OnDisableBitmapsBtn(self, event):
        self.m_btn_bitmaps.Enable(not event.IsChecked())

    def OnPageChanged(self, event):
        self.m_events_list.Clear()
        event.Skip()

    def OnText(self, event):
        pos = self.m_events_list.Append("wx.TextCtrl: wx.EVT_TEXT")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnRichText(self, event):
        pos = self.m_events_list.Append("wx.RichTextCtrl: wx.EVT_TEXT")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnStcChange(self, event):
        pos = self.m_events_list.Append("wx.StyledTextCtrl: wx.EVT_STC_CHANGE")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnButton(self, event):
        pos = self.m_events_list.Append("Button: wx.EVT_BUTTON")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnToggle(self, event):
        pos = self.m_events_list.Append("OnToggle: wx.EVT_BUTTON")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnChoice(self, event):
        pos = self.m_events_list.Append("OnChoice: wx.EVT_CHOICE")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnCombobox(self, event):
        pos = self.m_events_list.Append("OnCombobox: wx.EVT_COMBOBOX")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnRadioBox(self, event):
        pos = self.m_events_list.Append("OnRadioBox: wx.EVT_RADIOBOX")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnCheckBox(self, event):
        pos = self.m_events_list.Append("OnCheckBox:wx.EVT_CHECKBOX")
        self.m_events_list.Select(pos)

    def OnRadioButton(self, event):
        pos = self.m_events_list.Append("OnRadioButton: wx.EVT_RADIOBUTTON")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnFileChanged(self, event):
        pos = self.m_events_list.Append("OnFileChanged: wx.EVT_FILEPICKER_CHANGED")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnDirChanged(self, event):
        pos = self.m_events_list.Append("OnDirChanged: wx.EVT_DIRPICKER_CHANGED")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnColourChanged(self, event):
        pos = self.m_events_list.Append("OnColourChanged: wx.EVT_COLOURPICKER_CHANGED")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnDateChanged(self, event):
        pos = self.m_events_list.Append("OnDateChanged: wx.EVT_DATE_CHANGED")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnTimeChanged(self, event):
        pos = self.m_events_list.Append("OnTimeChanged: wx.EVT_TIME_CHANGED")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnFontChanged(self, event):
        pos = self.m_events_list.Append("OnFontChanged: wx.OnFontChanged")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnPopupBtn(self, event):
        self.popupwin = popupwin.PopupWin(self)
        btn = event.GetEventObject()
        pos = btn.ClientToScreen(wx.Point(0, 0))
        self.popupwin.Position(pos, btn.GetSize());
        self.popupwin.Show()

    def OnListBox(self, event):
        pos = self.m_events_list.Append("wx.ListBox: wx.EVT_LISTBOX")
        self.m_events_list.Select(pos)
        event.Skip()

    def OnListChecked(self, event):
        pos = self.m_events_list.Append("wx.CheckListBox: wx.EVT_CHECKLISTBOX")
        self.m_events_list.Select(pos)
        event.Skip()
