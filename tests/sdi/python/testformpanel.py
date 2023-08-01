###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx

class TestFormPanel(wx.Panel):

    def __init__(self, parent, id=wx.ID_ANY, pos=wx.DefaultPosition,
                size=wx.Size(500, 300), style=wx.TAB_TRAVERSAL,
                name=wx.PanelNameStr):
        wx.Panel.__init__(self)

        if not self.Create(parent, id, pos, size, style, name):
            return

        parent_sizer = wx.BoxSizer(wx.VERTICAL)

        self.splitter = wx.SplitterWindow(self, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, wx.SP_3D)
        self.splitter.SetSashGravity(0.0)
        self.splitter.SetMinimumPaneSize(150)
        parent_sizer.Add(self.splitter, wx.SizerFlags(1).Expand().Border(wx.ALL))

        panel = wx.Panel(self.splitter, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)

        parent_sizer2 = wx.BoxSizer(wx.VERTICAL)

        self.staticText = wx.StaticText(panel, wx.ID_ANY, "Left Panel")
        parent_sizer2.Add(self.staticText, wx.SizerFlags().Border(wx.ALL))
        panel.SetSizerAndFit(parent_sizer2)

        panel2 = wx.Panel(self.splitter, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize,
            wx.TAB_TRAVERSAL)

        parent_sizer3 = wx.BoxSizer(wx.VERTICAL)

        self.staticText2 = wx.StaticText(panel2, wx.ID_ANY, "Right Panel")
        parent_sizer3.Add(self.staticText2, wx.SizerFlags().Border(wx.ALL))
        panel2.SetSizerAndFit(parent_sizer3)
        self.splitter.SplitVertically(panel, panel2)

        self.SetSizerAndFit(parent_sizer)
        self.SetSize(wx.Size(500, 300))
# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************
