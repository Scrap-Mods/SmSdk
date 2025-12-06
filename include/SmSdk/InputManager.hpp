#pragma once

#include "SmSdk/config.hpp"

#include <string>
#include <deque>

SMSDK_BEGIN_NAMESPACE

enum EKeyState : uint32_t
{
	EKeyState_None = 0,
	EKeyState_Press = 1,
	EKeyState_Hold = 2
};

enum EMouseButton : uint32_t
{
	EMouseButton_Left = 0,
	EMouseButton_Right = 1,
	EMouseButton_Middle = 2,
	EMouseButton_Button1 = 3,
	EMouseButton_Button2 = 4
};

enum EInputEventType : uint32_t
{
	InputEventType_Keyboard = 0x0,
	InputEventType_Mouse = 0x1,
	InputEventType_MouseScroll = 0x2,
	InputEventType_MouseMove = 0x3,
};


struct MouseData
{
	/* 0x0000 */ std::int32_t m_x;
	/* 0x0004 */ std::int32_t m_y;
	/* 0x0008 */ std::int32_t m_scroll;
}; // Size: 0xC

static_assert(sizeof(MouseData) == 0xC, "MouseData: Incorrect Size");

struct InputEvent
{
	/* 0x0000 */ EInputEventType m_eventType;
private:
	/* 0x0004 */ char pad_0x4[0x4];
public:
	/* 0x0008 */ std::wstring m_someName;
private:
	/* 0x0028 */ char pad_0x28[0x18];
}; // Size: 0x40

static_assert(sizeof(InputEvent) == 0x40, "InputEvent: Incorrect Size");

class InputManager
{
	REMOVE_COPY_CONSTRUCTORS(InputManager);
public:
	static InputManager* GetInstance();

	inline bool _isKeyPressed(char cKey) const
	{
		return m_eKeyStates[cKey] == EKeyState_Press;
	}

	inline bool _isKeyHeld(char cKey) const
	{
		return m_eKeyStates[cKey] == EKeyState_Hold;
	}

	inline bool _isMouseButtonPressed(EMouseButton eBtn) const
	{
		return m_eMouseBtnStates[eBtn] == EKeyState_Press;
	}

	inline bool _isMouseButtonHeld(EMouseButton eBtn) const
	{
		return m_eMouseBtnStates[eBtn] == EKeyState_Hold;
	}

	inline static bool IsKeyPressed(char cKey)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isKeyPressed(cKey);
	}

	inline static bool IsKeyHeld(char cKey)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isKeyHeld(cKey);
	}

	inline static bool IsMouseButtonPressed(EMouseButton eBtn)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isMouseButtonPressed(eBtn);
	}

	inline static bool IsMouseButtonHeld(EMouseButton eBtn)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isMouseButtonHeld(eBtn);
	}

	inline static std::int32_t GetMouseScrollDelta()
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->m_deltaMouseData.m_scroll;
	}
private:
	/* 0x0000 */ char pad_0x0[0xC];
public:
	/* 0x000C */ std::int32_t m_iCharacterCode;
private:
	/* 0x0010 */ char pad_0x10[0x18];
public:
	/* 0x0028 */ struct Contraption* m_pContraption;
	/* 0x0030 */ MouseData m_currentMouseData;
	/* 0x003C */ MouseData m_prevMouseData;
	/* 0x0048 */ MouseData m_deltaMouseData;
	/* 0x0054 */ bool m_bKeyPressStates[256];
	/* 0x0154 */ bool m_bPrevKeyPressStates[256];
	/* 0x0254 */ EKeyState m_eKeyStates[256];
	/* 0x0654 */ bool m_bMouseBtnPressStates[5];
	/* 0x0659 */ bool m_bMousePrevBtnPressStates[5];
private:
	/* 0x065E */ char pad_0x65E[0x2];
public:
	/* 0x0660 */ EMouseButton m_eMouseBtnStates[5];
private:
	/* 0x0674 */ char pad_0x674[0x4];
public:
	/* 0x0678 */ std::deque<InputEvent> m_deqInputQueue;
private:
	/* 0x06A0 */ char pad_0x6A0[0x4];
public:
	/* 0x06A4 */ float m_fCrashTimer;
private:
	/* 0x06A8 */ char pad_0x6A8[0x8];
}; // Size: 0x6B0

static_assert(sizeof(InputManager) == 0x6B0, "InputManager: Incorrect Size");

SMSDK_END_NAMESPACE