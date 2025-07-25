/////////////////////////////////////////////////////////////////////////////
// Purpose:   Array of formbuilder/wxuieditor event name pairs
/////////////////////////////////////////////////////////////////////////////

constexpr auto set_ignore_flags = frozen::make_set<std::string_view>({
    "xrc_skip_sizer",  // used for XRC code generation which we don't support

    "event_handler",  // all events are now declared as virtual

    "drag_accept_files",  // wxUiEditor will turn on drag support if there is an event handler for
                          // it

    // The following are wxFormBuilder properties for wxAuiToolBar

    "label_visible",
    "toolbar_label",
    "use_explicit_ids",

    // The following are AUI properties. Unless AUI frame windows gets implemented, these will all
    // be ignored

    "BottomDockable",
    "LeftDockable",
    "RightDockable",
    "TopDockable",
    "aui_layer",
    "aui_managed",
    "aui_manager_style",
    "aui_name",
    "aui_position",
    "aui_row",
    "best_size",
    "caption",
    "caption_visible",
    "center_pane",
    "close_button",
    "context_menu",
    "default_pane",
    "dock",
    "dock_fixed",
    "docking",
    "event_generation",
    "first_id",
    "floatable",
    "gripper",
    "max_size",
    "maximize_button",
    "min_size",
    "minimize_button",
    "moveable",
    "pane_border",
    "pane_position",
    "pane_size",
    "parent",
    "pin_button",
    "resize",
    "show",
    "toolbar_pane",

    // This are miscellanious properties that we don't support

    "two_step_creation",
    "use_enum",
});

// The left name is what wxFormBuilder calls the event, the right name is what wxUiEditor calls the
// event
constexpr auto map_evt_pair = frozen::make_map<std::string_view, std::string_view>({
    { "OnActivate", "wxEVT_ACTIVATE" },

    { "OnAuiFindManager", "wxEVT_AUI_FIND_MANAGER" },
    { "OnAuiPaneActivated", "wxEVT_AUI_PANE_ACTIVATED" },
    { "OnAuiPaneButton", "wxEVT_AUI_PANE_BUTTON" },
    { "OnAuiPaneClose", "wxEVT_AUI_PANE_CLOSE" },
    { "OnAuiPaneMaximize", "wxEVT_AUI_PANE_MAXIMIZE" },
    { "OnAuiPaneRestore", "wxEVT_AUI_PANE_RESTORE" },
    { "OnAuiRender", "wxEVT_AUI_RENDER" },
    { "OnAuiToolBarBeginDrag", "wxEVT_AUITOOLBAR_BEGIN_DRAG" },
    { "OnAuiToolBarMiddleClick", "wxEVT_AUITOOLBAR_MIDDLE_CLICK" },
    { "OnAuiToolBarOverflowClick", "wxEVT_AUITOOLBAR_OVERFLOW_CLICK" },
    { "OnAuiToolBarRightClick", "wxEVT_AUITOOLBAR_RIGHT_CLICK" },
    { "OnAuiToolBarToolDropDown", "wxEVT_AUITOOLBAR_TOOL_DROPDOWN" },
    { "OnAux1DClick", "wxEVT_AUX1_DCLICK" },
    { "OnAux1Down", "wxEVT_AUX1_DOWN" },
    { "OnAux1Up", "wxEVT_AUX1_UP" },
    { "OnAux2DClick", "wxEVT_AUX2_DCLICK" },
    { "OnAux2Down", "wxEVT_AUX2_DOWN" },
    { "OnAux2Up", "wxEVT_AUX2_UP" },

    { "OnNotebookPageChanged", "wxEVT_NOTEBOOK_PAGE_CHANGED" },
    { "OnNotebookPageChanging", "wxEVT_NOTEBOOK_PAGE_CHANGING" },
    { "OnChoicebookPageChanged", "wxEVT_CHOICEBOOK_PAGE_CHANGED" },
    { "OnChoicebookPageChanging", "wxEVT_CHOICEBOOK_PAGE_CHANGING" },
    { "OnSimplebookPageChanged", "wxEVT_BOOKCTRL_PAGE_CHANGED" },
    { "OnSimplebookPageChanging", "wxEVT_BOOKCTRL_PAGE_CHANGING" },
    { "OnListbookPageChanged", "wxEVT_LISTBOOK_PAGE_CHANGED" },
    { "OnListbookPageChanging", "wxEVT_LISTBOOK_PAGE_CHANGING" },

    { "OnCollapsiblePaneChanged", "wxEVT_COLLAPSIBLEPANE_CHANGED" },
    { "OnSplitterSashPosChanged ", "wxEVT_SPLITTER_SASH_POS_CHANGED" },
    { "OnSplitterSashPosChanging", "wxEVT_SPLITTER_SASH_POS_CHANGING" },
    { "OnSplitterUnsplit", "wxEVT_SPLITTER_UNSPLIT" },
    { "OnSplitterDClick", "wxEVT_SPLITTER_DOUBLECLICKED" },

    { "OnAuiNotebookPageClose", "wxEVT_AUINOTEBOOK_PAGE_CLOSE" },
    { "OnAuiNotebookPageClosed", "wxEVT_AUINOTEBOOK_PAGE_CLOSED" },
    { "OnAuiNotebookPageChanged", "wxEVT_AUINOTEBOOK_PAGE_CHANGED" },
    { "OnAuiNotebookPageChanging", "wxEVT_AUINOTEBOOK_PAGE_CHANGING" },
    { "OnAuiNotebookButton", "wxEVT_AUINOTEBOOK_BUTTON" },
    { "OnAuiNotebookBeginDrag", "wxEVT_AUINOTEBOOK_BEGIN_DRAG" },
    { "OnAuiNotebookEndDrag", "wxEVT_AUINOTEBOOK_END_DRAG" },
    { "OnAuiNotebookDragMotion", "wxEVT_AUINOTEBOOK_DRAG_MOTION" },
    { "OnAuiNotebookAllowDND", "wxEVT_AUINOTEBOOK_ALLOW_DND" },
    { "OnAuiNotebookDragDone", "wxEVT_AUINOTEBOOK_DRAG_DONE" },
    { "OnAuiNotebookTabMiddleDown", "wxEVT_AUINOTEBOOK_TAB_MIDDLE_DOWN" },
    { "OnAuiNotebookTabMiddleUp", "wxEVT_AUINOTEBOOK_TAB_MIDDLE_IP" },
    { "OnAuiNotebookTabRightDown", "wxEVT_AUINOTEBOOK_TAB_RIGHT_DOWN" },
    { "OnAuiNotebookTabRightUp", "wxEVT_AUINOTEBOOK_TAB_RIGHT_UP" },
    { "OnAuiNotebookBGDClick", "wxEVT_AUINOTEBOOK_BG_DCLICK" },

    { "OnButtonClick", "wxEVT_BUTTON" },
    { "OnCalendar", "wxEVT_CALENDAR_DOUBLECLICKED" },
    { "OnCalendarDay", "wxEVT_CALENDAR_DAY_CHANGED" },
    { "OnCalendarMonth", "wxEVT_CALENDAR_MONTH_CHANGED" },
    { "OnCalendarPageChanged", "wxEVT_CALENDAR_PAGE_CHANGED" },
    { "OnCalendarSelChanged", "wxEVT_CALENDAR_SEL_CHANGED" },
    { "OnCalendarWeekClicked", "wxEVT_CALENDAR_WEEK_CLICKED" },
    { "OnCalendarWeekDayClicked", "wxEVT_CALENDAR_WEEKDAY_CLICKED" },
    { "OnCalendarYear", "wxEVT_CALENDAR_YEAR_CHANGED" },
    { "OnCancelButton", "wxEVT_SEARCHCTRL_CANCEL_BTN" },
    { "OnChar", "wxEVT_CHAR" },
    { "OnCharHook", "wxEVT_CHAR_HOOK" },
    { "OnCheckBox", "wxEVT_CHECKBOX" },
    { "OnCheckListBox", "wxEVT_LISTBOX" },
    { "OnCheckListBoxDClick", "wxEVT_LISTBOX_DCLICK" },
    { "OnCheckListBoxToggled", "wxEVT_CHECKLISTBOX" },
    { "OnChoice", "wxEVT_CHOICE" },
    { "OnClose", "wxEVT_CLOSE_WINDOW" },
    { "OnColourChanged", "wxEVT_COLOURPICKER_CHANGED" },
    { "OnCombobox", "wxEVT_COMBOBOX" },
    { "OnComboboxCloseup", "wxEVT_COMBOBOX_CLOSEUP" },
    { "OnComboboxDropdown", "wxEVT_COMBOBOX_DROPDOWN" },
    { "OnCommandScroll", "AllScrollEvents" },
    { "OnCommandScrollBottom", "wxEVT_SCROLL_BOTTOM" },
    { "OnCommandScrollChanged", "wxEVT_SCROLL_CHANGED" },
    { "OnCommandScrollLineDown", "wxEVT_SCROLL_LINEDOWN" },
    { "OnCommandScrollLineUp", "wxEVT_SCROLL_LINEUP" },
    { "OnCommandScrollPageDown", "wxEVT_SCROLL_PAGEDOWN" },
    { "OnCommandScrollPageUp", "wxEVT_SCROLL_PAGEUP" },
    { "OnCommandScrollThumbRelease", "wxEVT_SCROLL_THUMBRELEASE" },
    { "OnCommandScrollThumbTrack", "wxEVT_SCROLL_THUMBTRACK" },
    { "OnCommandScrollTop", "wxEVT_SCROLL_TOP" },
    { "OnDataViewCtrlColumnHeaderClick", "wxEVT_DATAVIEW_COLUMN_HEADER_CLICK" },
    { "OnDataViewCtrlColumnHeaderRightClick", "wxEVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK" },
    { "OnDataViewCtrlColumnReordered", "wxEVT_DATAVIEW_COLUMN_REORDERED" },
    { "OnDataViewCtrlColumnSorted", "wxEVT_DATAVIEW_COLUMN_SORTED" },
    { "OnDataViewCtrlItemActivated", "wxEVT_DATAVIEW_ITEM_ACTIVATED" },
    { "OnDataViewCtrlItemBeginDrag", "wxEVT_DATAVIEW_ITEM_BEGIN_DRAG" },
    { "OnDataViewCtrlItemCollapsed", "wxEVT_DATAVIEW_ITEM_COLLAPSED" },
    { "OnDataViewCtrlItemCollapsing", "wxEVT_DATAVIEW_ITEM_COLLAPSING" },
    { "OnDataViewCtrlItemContextMenu", "wxEVT_DATAVIEW_ITEM_CONTEXT_MENU" },
    { "OnDataViewCtrlItemDrop", "wxEVT_DATAVIEW_ITEM_DROP" },
    { "OnDataViewCtrlItemDropPossible", "wxEVT_DATAVIEW_ITEM_DROP_POSSIBLE" },
    { "OnDataViewCtrlItemEditingDone", "wxEVT_DATAVIEW_ITEM_EDITING_DONE" },
    { "OnDataViewCtrlItemEditingStarted", "wxEVT_DATAVIEW_ITEM_EDITING_STARTED" },
    { "OnDataViewCtrlItemExpanded", "wxEVT_DATAVIEW_ITEM_EXPANDED" },
    { "OnDataViewCtrlItemExpanding", "wxEVT_DATAVIEW_ITEM_EXPANDING" },
    { "OnDataViewCtrlItemStartEditing", "wxEVT_DATAVIEW_ITEM_START_EDITING" },
    { "OnDataViewCtrlItemValueChanged", "wxEVT_DATAVIEW_ITEM_VALUE_CHANGED" },
    { "OnDataViewCtrlSelectionChanged", "wxEVT_DATAVIEW_SELECTION_CHANGED" },
    { "OnDataViewListCtrlColumnHeaderClick", "wxEVT_DATAVIEW_COLUMN_HEADER_CLICK" },
    { "OnDataViewListCtrlColumnHeaderRightClick", "wxEVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK" },
    { "OnDataViewListCtrlColumnReordered", "wxEVT_DATAVIEW_COLUMN_REORDERED" },
    { "OnDataViewListCtrlColumnSorted", "wxEVT_DATAVIEW_COLUMN_SORTED" },
    { "OnDataViewListCtrlItemActivated", "wxEVT_DATAVIEW_ITEM_ACTIVATED" },
    { "OnDataViewListCtrlItemBeginDrag", "wxEVT_DATAVIEW_ITEM_BEGIN_DRAG" },
    { "OnDataViewListCtrlItemCollapsed", "wxEVT_DATAVIEW_ITEM_COLLAPSED" },
    { "OnDataViewListCtrlItemCollapsing", "wxEVT_DATAVIEW_ITEM_COLLAPSING" },
    { "OnDataViewListCtrlItemContextMenu", "wxEVT_DATAVIEW_ITEM_CONTEXT_MENU" },
    { "OnDataViewListCtrlItemDrop", "wxEVT_DATAVIEW_ITEM_DROP" },
    { "OnDataViewListCtrlItemDropPossible", "wxEVT_DATAVIEW_ITEM_DROP_POSSIBLE" },
    { "OnDataViewListCtrlItemEditingDone", "wxEVT_DATAVIEW_ITEM_EDITING_DONE" },
    { "OnDataViewListCtrlItemEditingStarted", "wxEVT_DATAVIEW_ITEM_EDITING_STARTED" },
    { "OnDataViewListCtrlItemExpanded", "wxEVT_DATAVIEW_ITEM_EXPANDED" },
    { "OnDataViewListCtrlItemExpanding", "wxEVT_DATAVIEW_ITEM_EXPANDING" },
    { "OnDataViewListCtrlItemStartEditing", "wxEVT_DATAVIEW_ITEM_START_EDITING" },
    { "OnDataViewListCtrlItemValueChanged", "wxEVT_DATAVIEW_ITEM_VALUE_CHANGED" },
    { "OnDataViewListCtrlSelectionChanged", "wxEVT_DATAVIEW_SELECTION_CHANGED" },
    { "OnDataViewTreeCtrlColumnHeaderClick", "wxEVT_DATAVIEW_COLUMN_HEADER_CLICK" },
    { "OnDataViewTreeCtrlColumnHeaderRightClick", "wxEVT_DATAVIEW_COLUMN_HEADER_RIGHT_CLICK" },
    { "OnDataViewTreeCtrlColumnReordered", "wxEVT_DATAVIEW_COLUMN_REORDERED" },
    { "OnDataViewTreeCtrlColumnSorted", "wxEVT_DATAVIEW_COLUMN_SORTED" },
    { "OnDataViewTreeCtrlItemActivated", "wxEVT_DATAVIEW_ITEM_ACTIVATED" },
    { "OnDataViewTreeCtrlItemBeginDrag", "wxEVT_DATAVIEW_ITEM_BEGIN_DRAG" },
    { "OnDataViewTreeCtrlItemCollapsed", "wxEVT_DATAVIEW_ITEM_COLLAPSED" },
    { "OnDataViewTreeCtrlItemCollapsing", "wxEVT_DATAVIEW_ITEM_COLLAPSING" },
    { "OnDataViewTreeCtrlItemContextMenu", "wxEVT_DATAVIEW_ITEM_CONTEXT_MENU" },
    { "OnDataViewTreeCtrlItemDrop", "wxEVT_DATAVIEW_ITEM_DROP" },
    { "OnDataViewTreeCtrlItemDropPossible", "wxEVT_DATAVIEW_ITEM_DROP_POSSIBLE" },
    { "OnDataViewTreeCtrlItemEditingDone", "wxEVT_DATAVIEW_ITEM_EDITING_DONE" },
    { "OnDataViewTreeCtrlItemEditingStarted", "wxEVT_DATAVIEW_ITEM_EDITING_STARTED" },
    { "OnDataViewTreeCtrlItemExpanded", "wxEVT_DATAVIEW_ITEM_EXPANDED" },
    { "OnDataViewTreeCtrlItemExpanding", "wxEVT_DATAVIEW_ITEM_EXPANDING" },
    { "OnDataViewTreeCtrlItemStartEditing", "wxEVT_DATAVIEW_ITEM_START_EDITING" },
    { "OnDataViewTreeCtrlItemValueChanged", "wxEVT_DATAVIEW_ITEM_VALUE_CHANGED" },
    { "OnDataViewTreeCtrlSelectionChanged", "wxEVT_DATAVIEW_SELECTION_CHANGED" },
    { "OnDateChanged", "wxEVT_DATE_CHANGED" },
    { "OnDirChanged", "wxEVT_DIRPICKER_CHANGED" },
    { "OnDirctrlFileActivated", "wxEVT_DIRCTRL_FILEACTIVATED" },
    { "OnDirctrlSelectionChanged", "wxEVT_DIRCTRL_SELECTIONCHANGED" },
    { "OnEnterWindow", "wxEVT_ENTER_WINDOW" },
    { "OnEraseBackground", "wxEVT_ERASE_BACKGROUND" },
    { "OnFileChanged", "wxEVT_FILEPICKER_CHANGED" },
    { "OnFontChanged", "wxEVT_FONTPICKER_CHANGED" },
    { "OnGridCellChange", "wxEVT_GRID_CELL_CHANGED" },
    { "OnGridCellLeftClick", "wxEVT_GRID_CELL_LEFT_CLICK" },
    { "OnGridCellLeftDClick", "wxEVT_GRID_CELL_LEFT_DCLICK" },
    { "OnGridCellRightClick", "wxEVT_GRID_CELL_RIGHT_CLICK" },
    { "OnGridCellRightDClick", "wxEVT_GRID_CELL_RIGHT_DCLICK" },
    { "OnGridCmdCellChange", "wxEVT_GRID_CELL_CHANGED" },
    { "OnGridCmdCellLeftClick", "wxEVT_GRID_CELL_LEFT_CLICK" },
    { "OnGridCmdCellLeftDClick", "wxEVT_GRID_CELL_LEFT_DCLICK" },
    { "OnGridCmdCellRightClick", "wxEVT_GRID_CELL_RIGHT_CLICK" },
    { "OnGridCmdCellRightDClick", "wxEVT_GRID_CELL_RIGHT_DCLICK" },
    { "OnGridCmdColSize", "wxEVT_GRID_COL_SIZE" },
    { "OnGridCmdEditorCreated", "wxEVT_GRID_EDITOR_CREATED" },
    { "OnGridCmdEditorHidden", "wxEVT_GRID_EDITOR_HIDDEN" },
    { "OnGridCmdEditorShown", "wxEVT_GRID_EDITOR_SHOWN" },
    { "OnGridCmdLabelLeftClick", "wxEVT_GRID_LABEL_LEFT_CLICK" },
    { "OnGridCmdLabelLeftDClick", "wxEVT_GRID_LABEL_LEFT_DCLICK" },
    { "OnGridCmdLabelRightClick", "wxEVT_GRID_LABEL_RIGHT_CLICK" },
    { "OnGridCmdLabelRightDClick", "wxEVT_GRID_LABEL_RIGHT_DCLICK" },
    { "OnGridCmdRangeSelect", "wxEVT_GRID_RANGE_SELECT" },
    { "OnGridCmdRowSize", "wxEVT_GRID_ROW_SIZE" },
    { "OnGridCmdSelectCell", "wxEVT_GRID_SELECT_CELL" },
    { "OnGridColSize", "wxEVT_GRID_COL_SIZE" },
    { "OnGridEditorCreated", "wxEVT_GRID_EDITOR_CREATED" },
    { "OnGridEditorHidden", "wxEVT_GRID_EDITOR_HIDDEN" },
    { "OnGridEditorShown", "wxEVT_GRID_EDITOR_SHOWN" },
    { "OnGridLabelLeftClick", "wxEVT_GRID_LABEL_LEFT_CLICK" },
    { "OnGridLabelLeftDClick", "wxEVT_GRID_LABEL_LEFT_DCLICK" },
    { "OnGridLabelRightClick", "wxEVT_GRID_LABEL_RIGHT_CLICK" },
    { "OnGridLabelRightDClick", "wxEVT_GRID_LABEL_RIGHT_DCLICK" },
    { "OnGridRangeSelect", "wxEVT_GRID_RANGE_SELECT" },
    { "OnGridRowSize", "wxEVT_GRID_ROW_SIZE" },
    { "OnGridSelectCell", "wxEVT_GRID_SELECT_CELL" },
    { "OnHtmlCellClicked", "wxEVT_HTML_CELL_CLICKED" },
    { "OnHtmlCellHover", "wxEVT_HTML_CELL_HOVER" },
    { "OnHtmlLinkClicked", "wxEVT_HTML_LINK_CLICKED" },
    { "OnHyperlink", "wxEVT_HYPERLINK" },
    { "OnIconize", "wxEVT_ICONIZE" },
    { "OnIdle", "wxEVT_IDLE" },
    { "OnInitDialog", "wxEVT_INIT_DIALOG" },
    { "OnKeyDown", "wxEVT_KEY_DOWN" },
    { "OnKeyUp", "wxEVT_KEY_UP" },
    { "OnKillFocus", "wxEVT_KILL_FOCUS" },
    { "OnLeaveWindow", "wxEVT_LEAVE_WINDOW" },
    { "OnLeftDClick", "wxEVT_LEFT_DCLICK" },
    { "OnLeftDown", "wxEVT_LEFT_DOWN" },
    { "OnLeftUp", "wxEVT_LEFT_UP" },
    { "OnListBeginDrag", "wxEVT_LIST_BEGIN_DRAG" },
    { "OnListBeginLabelEdit", "wxEVT_LIST_BEGIN_LABEL_EDIT" },
    { "OnListBeginRDrag", "wxEVT_LIST_BEGIN_RDRAG" },
    { "OnListBox", "wxEVT_LISTBOX" },
    { "OnListBoxDClick", "wxEVT_LISTBOX_DCLICK" },
    { "OnListCacheHint", "wxEVT_LIST_CACHE_HINT" },
    { "OnListColBeginDrag", "wxEVT_LIST_COL_BEGIN_DRAG" },
    { "OnListColClick", "wxEVT_LIST_COL_CLICK" },
    { "OnListColDragging", "wxEVT_LIST_COL_DRAGGING" },
    { "OnListColEndDrag", "wxEVT_LIST_COL_END_DRAG" },
    { "OnListColRightClick", "wxEVT_LIST_COL_RIGHT_CLICK" },
    { "OnListDeleteAllItems", "wxEVT_LIST_DELETE_ALL_ITEMS" },
    { "OnListDeleteItem", "wxEVT_LIST_DELETE_ITEM" },
    { "OnListEndLabelEdit", "wxEVT_LIST_END_LABEL_EDIT" },
    { "OnListInsertItem", "wxEVT_LIST_INSERT_ITEM" },
    { "OnListItemActivated", "wxEVT_LIST_ITEM_ACTIVATED" },
    { "OnListItemDeselected", "wxEVT_LIST_ITEM_DESELECTED" },
    { "OnListItemFocused", "wxEVT_LIST_ITEM_FOCUSED" },
    { "OnListItemMiddleClick", "wxEVT_LIST_ITEM_MIDDLE_CLICK" },
    { "OnListItemRightClick", "wxEVT_LIST_ITEM_RIGHT_CLICK" },
    { "OnListItemSelected", "wxEVT_LIST_ITEM_SELECTED" },
    { "OnListKeyDown", "wxEVT_LIST_KEY_DOWN" },
    { "OnMaximize", "wxEVT_MAXIMIZE" },
    { "OnMenuSelection", "wxEVT_MENU" },
    { "OnMiddleDClick", "wxEVT_MIDDLE_DCLICK" },
    { "OnMiddleDown", "wxEVT_MIDDLE_DOWN" },
    { "OnMiddleUp", "wxEVT_MIDDLE_UP" },
    { "OnMotion", "wxEVT_MOTION" },
    { "OnMouseWheel", "wxEVT_MOUSEWHEEL" },
    { "OnMove", "wxEVT_MOVE" },
    { "OnMove", "wxEVT_MOVE" },
    { "OnMoveEnd", "wxEVT_MOVE_END" },
    { "OnMoveStart", "wxEVT_MOVE_START" },
    { "OnMoving", "wxEVT_MOVING" },
    { "OnPaint", "wxEVT_PAINT" },
    { "OnPropertyGridChanged", "wxEVT_PG_CHANGED" },
    { "OnPropertyGridChanging", "wxEVT_PG_CHANGING" },
    { "OnRadioBox", "wxEVT_RADIOBOX" },
    { "OnRadioButton", "wxEVT_RADIOBUTTON" },
    { "OnRibbonBarHelpClick", "wxEVT_RIBBONBAR_HELP_CLICKED" },
    { "OnRibbonBarPageChanged", "wxEVT_RIBBONBAR_PAGE_CHANGED" },
    { "OnRibbonBarPageChanging", "wxEVT_RIBBONBAR_PAGE_CHANGING" },
    { "OnRibbonBarTabLeftDClick", "wxEVT_RIBBONBAR_TAB_LEFT_DCLICK" },
    { "OnRibbonBarTabMiddleDown", "wxEVT_RIBBONBAR_TAB_MIDDLE_DOWN" },
    { "OnRibbonBarTabMiddleUp", "wxEVT_RIBBONBAR_TAB_MIDDLE_UP" },
    { "OnRibbonBarTabRightDown", "wxEVT_RIBBONBAR_TAB_RIGHT_DOWN" },
    { "OnRibbonBarTabRightUp", "wxEVT_RIBBONBAR_TAB_RIGHT_UP" },
    { "OnRibbonBarToggled", "wxEVT_RIBBONBAR_TOGGLED" },
    { "OnRibbonButtonClicked", "wxEVT_RIBBONBUTTON_CLICKED" },
    { "OnRibbonButtonClicked", "wxEVT_RIBBONBUTTON_CLICKED" },
    { "OnRibbonButtonDropdownClicked", "wxEVT_RIBBONBUTTON_DROPDOWN_CLICKED" },
    { "OnRibbonGalleryClicked", "wxEVT_RIBBONGALLERY_CLICKED" },
    { "OnRibbonGalleryExtensionButtonPressed", "wxEVT_BUTTON" },
    { "OnRibbonGalleryHoverChanged", "wxEVT_RIBBONGALLERY_HOVER_CHANGED" },
    { "OnRibbonGallerySelected", "wxEVT_RIBBONGALLERY_SELECTED" },
    { "OnRibbonPanelExtbuttonActivated", "wxEVT_RIBBONPANEL_EXTBUTTON_ACTIVATED" },
    { "OnRibbonToolClicked", "wxEVT_RIBBONTOOL_DROPDOWN_CLICKED" },
    { "OnRibbonToolDropdownClicked", "wxEVT_RIBBONTOOL_DROPDOWN_CLICKED" },
    { "OnRichTextCharacter", "wxEVT_RICHTEXT_CHARACTER" },
    { "OnRichTextContentDeleted", "wxEVT_RICHTEXT_CONTENT_DELETED" },
    { "OnRichTextContentInserted", "wxEVT_RICHTEXT_CONTENT_INSERTED" },
    { "OnRichTextDelete", "wxEVT_RICHTEXT_DELETE" },
    { "OnRichTextReturn", "wxEVT_RICHTEXT_RETURN" },
    { "OnRichTextStyleChanged", "wxEVT_RICHTEXT_STYLE_CHANGED" },
    { "OnRichTextStyleSheetChanged", "wxEVT_RICHTEXT_STYLESHEET_CHANGED" },
    { "OnRichTextStyleSheetReplaced", "wxEVT_RICHTEXT_STYLESHEET_REPLACED" },
    { "OnRichTextStyleSheetReplacing", "wxEVT_RICHTEXT_STYLESHEET_REPLACING" },
    { "OnRightDClick", "wxEVT_RIGHT_DCLICK" },
    { "OnRightDown", "wxEVT_RIGHT_DOWN" },
    { "OnRightUp", "wxEVT_RIGHT_UP" },
    { "OnScroll", "AllScrollEvents" },
    { "OnScrollBottom", "wxEVT_SCROLL_BOTTOM" },
    { "OnScrollChanged", "wxEVT_SCROLL_CHANGED" },
    { "OnScrollLineDown", "wxEVT_SCROLL_LINEDOWN" },
    { "OnScrollLineUp", "wxEVT_SCROLL_LINEUP" },
    { "OnScrollPageDown", "wxEVT_SCROLL_PAGEDOWN" },
    { "OnScrollPageUp", "wxEVT_SCROLL_PAGEUP" },
    { "OnScrollThumbRelease", "wxEVT_SCROLL_THUMBRELEASE" },
    { "OnScrollThumbTrack", "wxEVT_SCROLL_THUMBTRACK" },
    { "OnScrollTop", "wxEVT_SCROLL_TOP" },
    { "OnSearchButton", "wxEVT_SEARCHCTRL_SEARCH_BTN" },
    { "OnSetFocus", "wxEVT_SET_FOCUS" },
    { "OnShow", "wxEVT_SHOW" },
    { "OnSize", "wxEVT_SIZE" },
    { "OnSlider", "wxEVT_SLIDER" },
    { "OnSpin", "wxEVT_SPIN" },
    { "OnSpinCtrl", "wxEVT_SPINCTRL" },
    { "OnSpinCtrlDouble", "wxEVT_SPINCTRLDOUBLE" },
    { "OnSpinCtrlText", "wxEVT_TEXT" },
    { "OnSpinDown", "wxEVT_SPIN_DOWN" },
    { "OnSpinUp", "wxEVT_SPIN_UP" },
    { "OnText", "wxEVT_TEXT" },
    { "OnTextEnter", "wxEVT_TEXT_ENTER" },
    { "OnTextMaxLen", "wxEVT_TEXT_MAXLEN" },
    { "OnTextURL", "wxEVT_TEXT_URL" },
    { "OnTimeChanged", "wxEVT_TIME_CHANGED" },
    { "OnTimer", "wxEVT_TIMER" },
    { "OnToggleButton", "wxEVT_TOGGLEBUTTON" },
    { "OnToolClicked", "wxEVT_TOOL" },
    { "OnToolDropdown", "wxEVT_TOOL_DROPDOWN" },
    { "OnToolEnter", "wxEVT_TOOL_ENTER" },
    { "OnToolRClicked", "wxEVT_TOOL_RCLICKED" },
    { "OnTreeBeginDrag", "wxEVT_TREE_BEGIN_DRAG" },
    { "OnTreeBeginLabelEdit", "wxEVT_TREE_BEGIN_LABEL_EDIT" },
    { "OnTreeBeginRDrag", "wxEVT_TREE_BEGIN_RDRAG" },
    { "OnTreeDeleteItem", "wxEVT_TREE_DELETE_ITEM" },
    { "OnTreeEndDrag", "wxEVT_TREE_END_DRAG" },
    { "OnTreeEndLabelEdit", "wxEVT_TREE_END_LABEL_EDIT" },
    { "OnTreeGetInfo", "wxEVT_TREE_GET_INFO" },
    { "OnTreeItemActivated", "wxEVT_TREE_ITEM_ACTIVATED" },
    { "OnTreeItemCollapsed", "wxEVT_TREE_ITEM_COLLAPSED" },
    { "OnTreeItemCollapsing", "wxEVT_TREE_ITEM_COLLAPSING" },
    { "OnTreeItemExpanded", "wxEVT_TREE_ITEM_EXPANDED" },
    { "OnTreeItemExpanding", "wxEVT_TREE_ITEM_EXPANDING" },
    { "OnTreeItemGetTooltip", "wxEVT_TREE_ITEM_GETTOOLTIP" },
    { "OnTreeItemMenu", "wxEVT_TREE_ITEM_MENU" },
    { "OnTreeItemMiddleClick", "wxEVT_TREE_ITEM_MIDDLE_CLICK" },
    { "OnTreeItemRightClick", "wxEVT_TREE_ITEM_RIGHT_CLICK" },
    { "OnTreeKeyDown", "wxEVT_TREE_KEY_DOWN" },
    { "OnTreeSelChanged", "wxEVT_TREE_SEL_CHANGED" },
    { "OnTreeSelChanging", "wxEVT_TREE_SEL_CHANGING" },
    { "OnTreeSetInfo", "wxEVT_TREE_SET_INFO" },
    { "OnTreeStateImageClick", "wxEVT_TREE_STATE_IMAGE_CLICK" },
    { "OnTreelistColumnSorted", "wxEVT_TREELIST_COLUMN_SORTED" },
    { "OnTreelistItemActivated", "wxEVT_TREELIST_ITEM_ACTIVATED" },
    { "OnTreelistItemChecked", "wxEVT_TREELIST_ITEM_CHECKED" },
    { "OnTreelistItemContextMenu", "wxEVT_TREELIST_ITEM_CONTEXT_MENU" },
    { "OnTreelistItemExpanded", "wxEVT_TREELIST_ITEM_EXPANDED" },
    { "OnTreelistItemExpanding", "wxEVT_TREELIST_ITEM_EXPANDING" },
    { "OnTreelistSelectionChanged", "wxEVT_TREELIST_SELECTION_CHANGED" },
    { "OnUpdateUI", "wxEVT_UPDATE_UI" },
    { "OnUpdateUI", "wxEVT_UPDATE_UI" },
    { "OnWizardBeforePageChanged", "wxEVT_WIZARD_BEFORE_PAGE_CHANGED" },
    { "OnWizardCancel", "wxEVT_WIZARD_CANCEL" },
    { "OnWizardFinished", "wxEVT_WIZARD_FINISHED" },
    { "OnWizardHelp", "wxEVT_WIZARD_HELP" },
    { "OnWizardPageChanged", "wxEVT_WIZARD_PAGE_CHANGED" },
    { "OnWizardPageChanging", "wxEVT_WIZARD_PAGE_CHANGING" },
    { "OnWizardPageShown", "wxEVT_WIZARD_PAGE_SHOWN" },

    { "OnApplyButtonClick", "ApplyButtonClicked" },
    { "OnCancelButtonClick", "CancelButtonClicked" },
    { "OnContextHelpButtonClick", "ContextHelpButtonClicked" },
    { "OnHelpButtonClick", "HelpButtonClicked" },
    { "OnNoButtonClick", "NoButtonClicked" },
    { "OnOKButtonClick", "OKButtonClicked" },
    { "OnSaveButtonClick", "SaveButtonClicked" },
    { "OnYesButtonClick", "YesButtonClicked" },
});
