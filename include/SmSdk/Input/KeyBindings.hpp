#pragma once

#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>
#include <map>

SMSDK_BEGIN_NAMESPACE

enum class ActionCode : std::uint32_t
{
	Attack                 = 0x1,
	Create                 = 0x2,
	Use                    = 0x3,
	Tinker                 = 0x4,
	Cancel                 = 0x5,
	Forward                = 0x6,
	Backward               = 0x7,
	StrafeLeft             = 0x8,
	StrafeRight            = 0x9,
	Jump                   = 0xA,
	Crawl                  = 0xB,
	Sprint                 = 0xC,
	NextCreateRotation     = 0xD,
	PreviousCreateRotation = 0xE,
	MenuItem0              = 0xF,
	MenuItem1              = 0x10,
	MenuItem2              = 0x11,
	MenuItem3              = 0x12,
	MenuItem4              = 0x13,
	MenuItem5              = 0x14,
	MenuItem6              = 0x15,
	MenuItem7              = 0x16,
	MenuItem8              = 0x17,
	MenuItem9              = 0x18,
	NextMenuItem           = 0x19,
	PreviousMenuItem       = 0x1A,
	Camera                 = 0x1B,
	ZoomIn                 = 0x1C,
	ZoomOut                = 0x1D,
	Chat                   = 0x1E,
	Inventory              = 0x1F,
	Logbook                = 0x20,
	Handbook               = 0x21,
	ForceBuild             = 0x22,
	LiftUp                 = 0x23,
	LiftDown               = 0x24,
	HideGui                = 0x25,
	Stuck                  = 0x26,
	SelectHotbar1          = 0x27,
	SelectHotbar2          = 0x28,
	SelectHotbar3          = 0x29,
	NextHotbar             = 0x2A,
	PreviousHotbar         = 0x2B,
	Reset                  = 0x2C,
	Reload                 = 0x2D
};

enum class LuaActionCode : std::uint32_t
{
	C_Left     = 0x1,
	C_Right    = 0x2,
	C_Forward  = 0x3,
	C_Backward = 0x4,
	C_Item0    = 0x5,
	C_Item1    = 0x6,
	C_Item2    = 0x7,
	C_Item3    = 0x8,
	C_Item4    = 0x9,
	C_Item5    = 0xA,
	C_Item6    = 0xB,
	C_Item7    = 0xC,
	C_Item8    = 0xD,
	C_Item9    = 0xE,
	C_Use      = 0xF,
	C_Jump     = 0x10,
	C_Exit     = 0x11,
	C_Attack   = 0x12,
	C_Create   = 0x13,
	C_ZoomIn   = 0x14,
	C_ZoomOut  = 0x15
};

enum class ModifierKey : std::uint32_t
{

};

// Raw Windows key code
using KeyCode = std::uint32_t;

class KeyBindings
{
	/* 0x0000 */ SDK_PUB std::unordered_map<std::string, ActionCode> m_mapKeyActions;
	/* 0x0040 */ SDK_PUB std::unordered_map<std::string, LuaActionCode> m_mapLuaKeyActions;
	/* 0x0080 */ SDK_PUB std::map<ActionCode, LuaActionCode> m_mapActionToLuaAction;
	/* 0x0090 */ SDK_PUB std::map<ModifierKey, std::unordered_map<KeyCode, ActionCode>> m_mapKeyboardBindings;
	/* 0x00A0 */ SDK_PUB std::map<ModifierKey, std::unordered_map<KeyCode, ActionCode>> m_mapMouseBindings;
	/* 0x00B0 */ SDK_PUB std::map<ModifierKey, ActionCode> m_mapPositiveScrollBindings;
	/* 0x00C0 */ SDK_PUB std::map<ModifierKey, ActionCode> m_mapNegativeScrollBindings;
	/* 0x00D0 */ SDK_PUB std::map<ModifierKey, std::unordered_map<KeyCode, LuaActionCode>> m_mapInteractableKeyboardBindings;
	/* 0x00E0 */ SDK_PUB std::map<ModifierKey, std::unordered_map<KeyCode, LuaActionCode>> m_mapInteractableMouseBindings;
	/* 0x00F0 */ SDK_PUB std::map<ModifierKey, LuaActionCode> m_mapInteractablePositiveScrollBindings;
	/* 0x0100 */ SDK_PUB std::map<ModifierKey, LuaActionCode> m_mapInteractableNegativeScrollBindings;
}; // Size: 0x110

static_assert(offsetof(KeyBindings, KeyBindings::m_mapKeyActions) == 0x0, "KeyBindings::m_mapKeyActions: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapLuaKeyActions) == 0x40, "KeyBindings::m_mapLuaKeyActions: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapActionToLuaAction) == 0x80, "KeyBindings::m_mapActionToLuaAction: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapKeyboardBindings) == 0x90, "KeyBindings::m_mapKeyboardBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapMouseBindings) == 0xA0, "KeyBindings::m_mapMouseBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapPositiveScrollBindings) == 0xB0, "KeyBindings::m_mapPositiveScrollBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapNegativeScrollBindings) == 0xC0, "KeyBindings::m_mapNegativeScrollBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapInteractableKeyboardBindings) == 0xD0, "KeyBindings::m_mapInteractableKeyboardBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapInteractableMouseBindings) == 0xE0, "KeyBindings::m_mapInteractableMouseBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapInteractablePositiveScrollBindings) == 0xF0, "KeyBindings::m_mapInteractablePositiveScrollBindings: Incorrect offset");
static_assert(offsetof(KeyBindings, KeyBindings::m_mapInteractableNegativeScrollBindings) == 0x100, "KeyBindings::m_mapInteractableNegativeScrollBindings: Incorrect offset");

static_assert(sizeof(KeyBindings) == 0x110, "KeyBindings: Incorrect Size");

SMSDK_END_NAMESPACE