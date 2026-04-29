#include "SmSdk/InputManager.hpp"

SMSDK_BEGIN_NAMESPACE

bool InputManager::isKeyPressed(const char cKey) const
{
	return m_eKeyStates[cKey] == EKeyState_Press;
}

bool InputManager::isKeyHeld(const char cKey) const
{
	return m_eKeyStates[cKey] == EKeyState_Hold;
}

bool InputManager::isMouseButtonPressed(const EMouseButton eBtn) const
{
	return m_eMouseBtnStates[eBtn] == EKeyState_Press;
}

bool InputManager::isMouseButtonHeld(const EMouseButton eBtn) const
{
	return m_eMouseBtnStates[eBtn] == EKeyState_Hold;
}

bool InputManager::IsKeyPressed(const char cKey)
{
	InputManager* v_pInputMgr = InputManager::GetInstance();
	if (v_pInputMgr)
		return v_pInputMgr->isKeyPressed(cKey);
	else
		return false;
}

bool InputManager::IsKeyHeld(const char cKey)
{
	InputManager* v_pInputMgr = InputManager::GetInstance();
	if (v_pInputMgr)
		return v_pInputMgr->isKeyHeld(cKey);
	else
		return false;
}

bool InputManager::IsMouseButtonPressed(const EMouseButton eBtn)
{
	InputManager* v_pInputMgr = InputManager::GetInstance();
	if (v_pInputMgr)
		return v_pInputMgr->isMouseButtonPressed(eBtn);
	else
		return false;
}

bool InputManager::IsMouseButtonHeld(const EMouseButton eBtn)
{
	InputManager* v_pInputMgr = InputManager::GetInstance();
	if (v_pInputMgr)
		return v_pInputMgr->isMouseButtonHeld(eBtn);
	else
		return false;
}

std::int32_t InputManager::GetMouseScrollDelta()
{
	InputManager* v_pInputMgr = InputManager::GetInstance();
	if (v_pInputMgr)
		return v_pInputMgr->m_deltaMouseData.m_scroll;
	else
		return 0;
}

SMSDK_END_NAMESPACE