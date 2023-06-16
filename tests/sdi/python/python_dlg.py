###############################################################################
# Code generated by wxUiEditor -- see https://github.com/KeyWorksRW/wxUiEditor/
#
# Do not edit any code above the "End of generated code" comment block.
# Any changes before that block will be lost if it is re-generated!
###############################################################################

import wx
import wx.adv
import wx.aui

import images
import zlib
import base64
from wx.lib.embeddedimage import PyEmbeddedImage

clr_hourglass_gif = PyEmbeddedImage(
    b"R0lGODlhIAAgAPIAAP///8zMzAD//wCZmQAAAAAAAAAAAAAAACH/C05FVFNDQVBFMi4wAwEAAAAh+QQJ"
    b"CgAFACwAAAAAIAAgAAADZli63P4wykmrvTjnwbvnhFZwQil8QygSbOuqYiDPNKzJAEDLdobrux6GByAE"
    b"jEjRAnlsCjXMpLIRnT6k1gYvq509YwHgkfurWcvBKdqsXHvVYfFbifJ8KSQT6i55+VlcgYKDhIUSCQAh"
    b"+QQJCgAFACwAAAAAIAAgAAADZ1i63P4wykmrvTjnwbvnhFZwQil8QygSbOuqYiDPNKzJAEDLdobrux6G"
    b"ByDMjEIMMrBMZppM0aMphSCrEB7WUdsucMbo9tetkoPmQG4njqmBZfcaLUV5nBSSCYWXvP4sXoKDhIWG"
    b"EgkAIfkECQoABQAsAAAAACAAIAAAA2pYutz+MMpJq70458G754RWcEIpfEMoEmzrqmIgzzSsyQBAy3aG"
    b"67sehgfkBYQYwnGpRGaaTNED6pQ2pREe9lHbMnDKo7fw62LLYa20HDwHcjvx+l2cVSkoz11CMqH2EC+C"
    b"LGOFhoeIiRIJACH5BAkKAAUALAAAAAAgACAAAANpWLrc/jDKSau9OOfBu+eEVnBCKXxDKBJs66piIM80"
    b"rMkAQMt2huu7HoYHrIkWhEByqTwymEtnAyp1RKsNHpZh3OKSzeqvexyDteVAbheOqXXn9u3NFl5QHnuF"
    b"ZELpJy+BLFuEhYaHiAwJACH5BAkKAAUALAAAAAAgACAAAANpWLrc/jDKSau9OOfBu+eEVnBCKXxDKBJs"
    b"66piIM80rMkAQMt2huu7Hua3CwgxBKMyecwwl6LHsxllRiO866OmZeCSxm6BOKNWiOBslMxdB3LK8vWX"
    b"VotQHrOEZELpIS+BLGKEhYaHiBIJACH5BAkKAAUALAAAAAAgACAAAANoWLrc/jDKSau9OOfBu+eEVnBC"
    b"KXxDKBJs66piIM80rMkAQMt2huu7Hua3CwgxBOMsecwwlU3NM7oyiiS8K6SmbeCS1m6BuOwSwdkrmasO"
    b"5JTldu6ZFqE8VAnJhMpDXoAsYoOEhYaHGAkAIfkECQoABQAsAAAAACAAIAAAA2lYutz+MMpJq70458G7"
    b"54RWcEIpfEMoEmzrqmIgzzSsyQBAy3aG67se5rcLCDEEY1DUSDqNTMfzGHVGIbyro6Zd4JJQLXFGtRDB"
    b"WeaYqw7klOQoD/BMi1Ce8oRkQukjL4EsXYSFhoeIEgkAIfkECQoABQAsAAAAACAAIAAAA2lYutz+MMpJ"
    b"q70458G754RWcEIpfEMoEmzrqmIgzzSsyQBAy3aG67se5rcLCDGEolHUSDqXzKYRGpUeq7yqo6Zd4JLU"
    b"KHF2tRDBWeaYqw7kpmSxEfB0RlGe8oRkQukjL4EsXYSFhoeIEgkAIfkECQoABQAsAAAAACAAIAAAA2xY"
    b"utz+MMpJq70458G754RWcEIpfEMoEmzrqmIgzzSsyQBAy3aG67se5rcLCDGEolHUSCZ5TIdzGZVSqw0o"
    b"llHbKnDPoy+Q60aJT22MDDSvAdOZuMKDG+9zCsqTl5BMKH0QL4QsXoeIiYqLDAkAIfkECQoABQAsAAAA"
    b"ACAAIAAAA2pYutz+MMpJq70458G754RWcEIpfEMoEmzrqmIgzzSsyQBAy3aG67se5rcLCDGEolHUSNaY"
    b"jqQU+phSHbxr46kt4JxHXyDHZRKdWfMYWL6NpcZ0zAiAW0UoT5hCMqH2Ei+CLF2FhoeIiQwJACH5BAkK"
    b"AAUALAAAAAAgACAAAANsWLrc/jDKSau9OOfBu+eEVnBCKXxDKBJs66piIM80rMkAQMt2huu7Hua3Cwgx"
    b"hKJR1EjWmA7nEhqdUhu8K3Z2jAUAzu7wC8xCiVLrjZxW+77JuNlLABvvYgrKk5eQTCh9EC+ELFqHiImK"
    b"ixIJACH5BAkKAAUALAAAAAAgACAAAANrWLrc/jDKSau9OOfBu+eEVnBCKXxDKBJs66piIM80rMkAQMt2"
    b"huu7Hua3CwgxhKJR1EjWmA7nEhqdUhu8K3Z2jAWAViiRSyVKw74vICntVnBsY5bJW8vZUJTHPSGZUHwR"
    b"L4MsWoaHiImKEgkAIfkECQoABQAsAAAAACAAIAAAA2dYutz+MMpJq7046zfInkP3RYMgjk0QlCdaqADA"
    b"eigMqGG7BbGKh7TdzffTYXhEH2H5QSaDl+SQCLXYeoGlVmOjfoBZAMG7mYmzytEMPWaqTW22KxevfsF2"
    b"NdDl2PMbbn+Cg4SFhhMJACH5BAkKAAUALAAAAAAgACAAAANzWLrc/jDKSau9OOvNu//ZMGgDIYlEoAbQ"
    b"GqCnkK5m475ynAJ8UCsqHm+QixB3PR8wIBwWIUdm0hcEuI6n0m17gxm1qbBv1i1lCeKwgrzyQsHUX4H9"
    b"Mn/RcQfb/UCh0RB/aHaBchaAIImKi4yNjo+QkZINCQAh+QQJCgAFACwAAAAAIAAgAAADbVi63P4wykmr"
    b"vTjrQsiWxOB9TyiSjjkEI8oNcCC3Xyis8kzaeM7Wg5uP9dvAVgAAgdhxzZRMV+FJgPpomI4WMCyiAtwh"
    b"VgPuspqbshg2toDDsyNJlozDnG+VdMoKDvYKPIAKfoOEf4aJiouMJAkAIf4yUmVkdWNlZCA1NiUgQCB3"
    b"d3cucmFzcGJlcnJ5aGlsbC5jb20vZ2lmd2l6YXJkLmh0bWwAOw==")

class PythonDlg(wx.Dialog):
    def __init__(self, parent, id=wx.ID_ANY, title="Hello Python Dialog!",
                pos=wx.DefaultPosition, size=wx.DefaultSize,
                style=wx.DEFAULT_DIALOG_STYLE, name=wx.DialogNameStr):
        wx.Dialog.__init__(self)

        if not self.Create(parent, id, title, pos, size, style, name):
            return

        bSizer1 = wx.BoxSizer(wx.VERTICAL)

        box_sizer = wx.BoxSizer(wx.VERTICAL)

        self.auiToolBar = wx.aui.AuiToolBar(self, wx.ID_ANY, wx.DefaultPosition,
            wx.DefaultSize, wx.aui.AUI_TB_PLAIN_BACKGROUND|wx.aui.AUI_TB_DEFAULT_STYLE)
        self.auiToolBar.AddLabel(wx.ID_ANY, "Label")
        tool_2 = self.auiToolBar.AddTool(wx.ID_ANY, "Search", wx.BitmapBundle.FromBitmap(
            images.fontPicker_png.Bitmap), wx.NullBitmap, wx.ITEM_NORMAL,
            "This tool should be initially disabled.",
            "This tool should be initially disabled.", None)
        tool_2.SetState(wx.aui.AUI_BUTTON_STATE_NORMAL|wx.aui.AUI_BUTTON_STATE_DISABLED)
        self.auiToolBar.AddSpacer(self.auiToolBar.FromDIP(10))

        self.spinCtrl = wx.SpinCtrl(self.auiToolBar)
        self.auiToolBar.AddControl(self.spinCtrl)
        self.auiToolBar.Realize()
        box_sizer.Add(self.auiToolBar, wx.SizerFlags().Border(wx.ALL))

        self.m_staticText = wx.StaticText(self, wx.ID_ANY,
            "wxPython est génial n\'est-ce pas?",
            self.ConvertDialogToPixels(wx.Point(50, 100)),
            self.ConvertDialogToPixels(wx.Size(150, 32)), wx.ALIGN_CENTER_HORIZONTAL,
            "my_text")
        self.m_staticText.SetWindowVariant(wx.WINDOW_VARIANT_LARGE)
        self.m_staticText.SetForegroundColour(wx.Colour(0, 128, 0))
        box_sizer.Add(self.m_staticText, wx.SizerFlags().Center().Border(wx.ALL))

        _svg_string_ = zlib.decompress(base64.b64decode(images.face_smile_svg))
        bmp = wx.StaticBitmap(self, wx.ID_ANY, wx.BitmapBundle.FromSVG(_svg_string_,
            wx.Size(32, 32)))
        box_sizer.Add(bmp, wx.SizerFlags().Border(wx.ALL))

        # wxPython currently does not support a checkbox as a static box label
        static_box_2 = wx.StaticBoxSizer(wx.VERTICAL, self, "Play Animation")

        self.m_toggleBtn = wx.ToggleButton(static_box_2.GetStaticBox(), wx.ID_ANY,
            "Play Animation", wx.DefaultPosition, wx.DefaultSize, wx.BU_EXACTFIT)
        static_box_2.Add(self.m_toggleBtn, wx.SizerFlags().Border(wx.ALL))

        self.m_animation_ctrl = wx.adv.AnimationCtrl(static_box_2.GetStaticBox(), wx.ID_ANY,
            wx.adv.Animation("../../art/clr_hourglass.gif"), wx.DefaultPosition,
            wx.DefaultSize, wx.adv.AC_DEFAULT_STYLE)
        self.m_animation_ctrl.SetInactiveBitmap(wx.BitmapBundle.FromBitmap(
            images.disabled_png.Bitmap))
        static_box_2.Add(self.m_animation_ctrl, wx.SizerFlags().Border(wx.ALL))

        box_sizer.Add(static_box_2, wx.SizerFlags().Border(wx.ALL))

        bSizer1.Add(box_sizer, wx.SizerFlags().Expand().Border(wx.ALL))

        if "wxMac" not in wx.PlatformInfo:
            stdBtn_line = wx.StaticLine(self, wx.ID_ANY, wx.DefaultPosition, wx.Size(20, -1))
            bSizer1.Add(stdBtn_line, wx.SizerFlags().Expand().Border(wx.ALL))

        stdBtn = wx.StdDialogButtonSizer()
        stdBtn_OK = wx.Button(self, wx.ID_OK)
        stdBtn.SetAffirmativeButton(stdBtn_OK)
        stdBtn_Cancel = wx.Button(self, wx.ID_CANCEL)
        stdBtn.SetCancelButton(stdBtn_Cancel)
        stdBtn_OK.SetDefault()
        stdBtn.Realize()
        bSizer1.Add(stdBtn, wx.SizerFlags().Expand().Border(wx.ALL))

        self.SetSizerAndFit(bSizer1)
        self.Centre(wx.BOTH)

        # Bind Event handlers
        self.Bind(wx.EVT_INIT_DIALOG, self.OnInit)
        self.m_toggleBtn.Bind(wx.EVT_TOGGLEBUTTON, lambda event:self.m_animation_ctrl.Play())

    # Unimplemented Event handler functions
    # Copy any listed and paste them below the comment block, or to your inherited class.
    """
    def (self, event):
        event.Skip()

    """

# ************* End of generated code ***********
# DO NOT EDIT THIS COMMENT BLOCK!
#
# Code below this comment block will be preserved
# if the code for this class is re-generated.
# ***********************************************

    # Event handler functions
    def OnInit(self, event):
        # self.m_staticText.SetLabel("Hello Python!")
        event.Skip()
