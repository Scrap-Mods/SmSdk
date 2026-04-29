#include "SmSdk/Gui/GuiSystemManager.hpp"

SMSDK_BEGIN_NAMESPACE

bool GuiSystemManager::IsMouseVisible()
{
	GuiSystemManager* v_pGuiSystemMgr = GuiSystemManager::GetInstance();
	if (v_pGuiSystemMgr)
		return v_pGuiSystemMgr->m_bMouseVisible;
	else
		return false;
}

std::int32_t GuiSystemManager::getScreenWidth() const
{
	return m_iScreenWidth;
}

std::int32_t GuiSystemManager::getScreenHeight() const
{
	return m_iScreenHeight;
}

std::int32_t GuiSystemManager::getScreenLeft() const
{
	return m_iScreenLeft;
}

std::int32_t GuiSystemManager::getScreenTop() const
{
	return m_iScreenTop;
}

SMSDK_END_NAMESPACE