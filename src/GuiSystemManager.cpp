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

int GuiSystemManager::ProcessScroll(
	const int unknownVal,
	const int scrollDistance,
	const int topPos,
	const int scrollVal,
	const float itemSize)
{
	if (unknownVal <= 0)
		return 0;

	const int vScrollClamped = (scrollVal <= 0)
		? -scrollDistance
		: scrollDistance;

	const int vVal = topPos - int(vScrollClamped * -itemSize);

	return std::min(std::max(-unknownVal, vVal), 0);
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