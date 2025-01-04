#pragma once

#define _SM_VERSION_NUM 073776

///////STATIC VALUE OFFSETS

#if _SM_VERSION_NUM == 073776
#	define SM_CURRENT_GAME_STATE_OFFSET 0x1267598
#	define SM_IN_GAME_GUI_MANAGER_OFFSET 0x1267570
#	define SM_GUI_SYSTEM_MANAGER_OFFSET 0x12676E8
#	define SM_CHARACTER_MANAGER_OFFSET 0x1267738
#	define SM_PLAYER_MANAGER_OFFSET 0x12677D8
#	define SM_AUDIO_MANAGER_OFFSET 0x1267648
#	define SM_INPUT_MANAGER_OFFSET 0x1267800
#	define SM_MY_PLAYER_OFFSET 0x12675A8
#	define SM_GAME_SETTINGS_OFFSET 0x1267760
#   define SM_CONTAINER_MANAGER_OFFSET 0x1267798
#   define SM_PORTAL_MANAGER_OFFSET 0x1267690
#   define SM_PATHFINDER_MANAGER_OFFSET 0x12676B0
#   define SM_AREA_TRIGGER_MANAGER_OFFSET 0x1267668
#   define SM_HARVESTABLE_MANAGER_OFFSET 0x1267718
#   define SM_DIRECTORY_MANAGER_OFFSET 0x1267810
#   define SM_CREATION_MANAGER_OFFSET 0x1267740
#   define SM_NET_OBJ_MANAGER_OFFSET 0x12677D0
#   define SM_PHYSICS_OFFSET 0x1267590
#elif _SM_VERSION_NUM == 071772 || _SM_VERSION_NUM == 072775
#	define SM_CURRENT_GAME_STATE_OFFSET 0x1267518
#	define SM_IN_GAME_GUI_MANAGER_OFFSET 0x12674F0
#	define SM_GUI_SYSTEM_MANAGER_OFFSET 0x1267668
#	define SM_CHARACTER_MANAGER_OFFSET 0x12676B8
#	define SM_PLAYER_MANAGER_OFFSET 0x1267758
#	define SM_AUDIO_MANAGER_OFFSET 0x12675C8
#	define SM_INPUT_MANAGER_OFFSET 0x1267780
#	define SM_MY_PLAYER_OFFSET 0x1267528
#	define SM_GAME_SETTINGS_OFFSET 0x12676E0
#   define SM_CONTAINER_MANAGER_OFFSET 0x1267718
#   define SM_PORTAL_MANAGER_OFFSET 0x1267610
#   define SM_PATHFINDER_MANAGER_OFFSET 0x1267630
#   define SM_AREA_TRIGGER_MANAGER_OFFSET 0x12675E8
#   define SM_HARVESTABLE_MANAGER_OFFSET 0x1267698
#   define SM_DIRECTORY_MANAGER_OFFSET 0x1267790
#   define SM_CREATION_MANAGER_OFFSET 0x12676C0
#   define SM_NET_OBJ_MANAGER_OFFSET 0x1267750
#   define SM_PHYSICS_OFFSET 0x1267510
#elif _SM_VERSION_NUM == 070771
#	define SM_CURRENT_GAME_STATE_OFFSET 0x12674F8
#	define SM_IN_GAME_GUI_MANAGER_OFFSET 0x12674D0
#	define SM_GUI_SYSTEM_MANAGER_OFFSET 0x12675C0
#	define SM_CHARACTER_MANAGER_OFFSET 0x1267658
#	define SM_PLAYER_MANAGER_OFFSET 0x1267650
#	define SM_AUDIO_MANAGER_OFFSET 0x12675A8
#	define SM_INPUT_MANAGER_OFFSET 0x1267768
#	define SM_MY_PLAYER_OFFSET 0x1267508
#	define SM_GAME_SETTINGS_OFFSET 0x1267758
#   define SM_CONTAINER_MANAGER_OFFSET 0x1267700
#   define SM_PORTAL_MANAGER_OFFSET 0x1267618
#   define SM_PATHFINDER_MANAGER_OFFSET 0x12676C8
#   define SM_AREA_TRIGGER_MANAGER_OFFSET 0x1267628
#   define SM_HARVESTABLE_MANAGER_OFFSET 0x12676B0
#   define SM_DIRECTORY_MANAGER_OFFSET 0x1267770
#   define SM_CREATION_MANAGER_OFFSET 0x1267660
#   define SM_NET_OBJ_MANAGER_OFFSET 0x1267648
#   define SM_PHYSICS_OFFSET 0x12674F0
#else
#	define SM_CURRENT_GAME_STATE_OFFSET 0x128D638
#	define SM_IN_GAME_GUI_MANAGER_OFFSET 0x128D670
#	define SM_GUI_SYSTEM_MANAGER_OFFSET 0x128D7B0
#	define SM_CHARACTER_MANAGER_OFFSET 0x128D8C0
#	define SM_PLAYER_MANAGER_OFFSET 0x128D8B8
#	define SM_AUDIO_MANAGER_OFFSET 0x128D720
#	define SM_INPUT_MANAGER_OFFSET 0x128D8E0
#	define SM_MY_PLAYER_OFFSET 0x128D658
#	define SM_GAME_SETTINGS_OFFSET 0x128D830
#   define SM_CONTAINER_MANAGER_OFFSET 0x128D770
#   define SM_PORTAL_MANAGER_OFFSET 0x128D7D8
#   define SM_PATHFINDER_MANAGER_OFFSET 0x128D778
#   define SM_AREA_TRIGGER_MANAGER_OFFSET 0x128D7E8
#   define SM_HARVESTABLE_MANAGER_OFFSET 0x128D8A0
#   define SM_DIRECTORY_MANAGER_OFFSET 0x128D8F0
#   define SM_CREATION_MANAGER_OFFSET 0x128D8C8
#   define SM_NET_OBJ_MANAGER_OFFSET 0x128D8B0
#   define SM_PHYSICS_OFFSET 0x128D628
#endif

//////VFTABLE OFFSETS

#if _SM_VERSION_NUM == 073776
#	define SM_VTBL_GAME_STATE_OFFSET 0xF88A70
#	define SM_VTBL_OPTIONS_MENU_OFFSET 0xF82558
#	define SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET 0xF824F8
#	define SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET 0xF31370
#	define SM_VTBL_OPTIONS_SUB_MENU_BASE_OFFSET 0xF6A698
#elif _SM_VERSION_NUM == 071772 || _SM_VERSION_NUM == 072775
#	define SM_VTBL_GAME_STATE_OFFSET 0xF889B0
#	define SM_VTBL_OPTIONS_MENU_OFFSET 0xF82498
#	define SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET 0xF82438
#	define SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET 0xF31370
#	define SM_VTBL_OPTIONS_SUB_MENU_BASE_OFFSET 0xF6A5D8
#elif _SM_VERSION_NUM == 070771
#	define SM_VTBL_GAME_STATE_OFFSET 0xF88940
#	define SM_VTBL_OPTIONS_MENU_OFFSET 0xF82418
#	define SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET 0xF823B8
#	define SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET 0xF31370
#	define SM_VTBL_OPTIONS_SUB_MENU_BASE_OFFSET 0xF54E30
#else
#	define SM_VTBL_GAME_STATE_OFFSET 0xF73358
#	define SM_VTBL_OPTIONS_MENU_OFFSET 0xF6CD90
#	define SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET 0xF6CD08
#	define SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET 0xF1EBA0
#	define SM_VTBL_OPTIONS_SUB_MENU_BASE_OFFSET 0xF6A558
#endif

//////CONSTRUCTOR OFFSETS

#if _SM_VERSION_NUM == 073776
#	define SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET 0x3BF890
#	define SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET 0x328620
#	define SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET 0x337FC0
#	define SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET 0x351D20
#	define SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET 0x644A70
#	define SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET 0x28C6B0
#	define SM_CONSTRUCTOR_OPTIONS_ITEM_SLIDER_OFFSET 0x3BBE20
#elif _SM_VERSION_NUM == 072775
#	define SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET 0x3BF910
#	define SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET 0x3286A0
#	define SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET 0x338040
#	define SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET 0x351DA0
#	define SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET 0x644AF0
#	define SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET 0x28C730
#	define SM_CONSTRUCTOR_OPTIONS_ITEM_SLIDER_OFFSET 0x3BBEA0
#elif _SM_VERSION_NUM == 071772
#	define SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET 0x3BF8F0
#	define SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET 0x3286A0
#	define SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET 0x338040
#	define SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET 0x351DA0
#	define SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET 0x644AD0
#	define SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET 0x28C730
#	define SM_CONSTRUCTOR_OPTIONS_ITEM_SLIDER_OFFSET 0x3BBE80
#elif _SM_VERSION_NUM == 070771
#	define SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET 0x3BF8F0
#	define SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET 0x3286A0
#	define SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET 0x338040
#	define SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET 0x351DA0
#	define SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET 0x644AD0
#	define SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET 0x28C730
#	define SM_CONSTRUCTOR_OPTIONS_ITEM_SLIDER_OFFSET 0x3BBE80
#else
#	define SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET 0x3CD530
#	define SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET 0x333F90
#	define SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET 0x343AF0
#	define SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET 0x35D2D0
#	define SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET 0x650220
#	define SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET 0x297680
#	define SM_CONSTRUCTOR_OPTIONS_ITEM_SLIDER_OFFSET 0x3C9A30
#endif

/////FUNCTIONS

#if _SM_VERSION_NUM == 073776
#   define SM_FUNC_VERTICAL_STACK_BOX_ADD_NEW_ITEM_OFFSET 0x5270E0
#elif _SM_VERSION_NUM == 072775
#   define SM_FUNC_VERTICAL_STACK_BOX_ADD_NEW_ITEM_OFFSET 0x527160
#elif _SM_VERSION_NUM == 071772
#   define SM_FUNC_VERTICAL_STACK_BOX_ADD_NEW_ITEM_OFFSET 0x527140
#elif _SM_VERSION_NUM == 070771
#   define SM_FUNC_VERTICAL_STACK_BOX_ADD_NEW_ITEM_OFFSET 0x527140
#else
#   define SM_FUNC_VERTICAL_STACK_BOX_ADD_NEW_ITEM_OFFSET 0x536A90
#endif

/////VARIABLES

#if _SM_VERSION_NUM == 073776
#   define SM_VAR_PAINT_DRAG_LIMITER 0x3E0DBB
#   define SM_VAR_PAINT_ERASE_LIMITER 0x2AD4BD
#   define SM_VAR_BLOCK_BUILD_LIMITER 0x2C5D8E
#elif _SM_VERSION_NUM == 072775
#   define SM_VAR_PAINT_DRAG_LIMITER 0x3E0E3B
#   define SM_VAR_PAINT_ERASE_LIMITER 0x2AD53D
#elif _SM_VERSION_NUM == 071772
#   define SM_VAR_PAINT_DRAG_LIMITER 0x3E0E1B
#   define SM_VAR_PAINT_ERASE_LIMITER 0x2AD53D
#else
#   define SM_VAR_PAINT_DRAG_LIMITER 0x3F060D
#   define SM_VAR_PAINT_ERASE_LIMITER 0x3F0D9B
#endif