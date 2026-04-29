#include "SmSdk/Gui/InGameGuiManager.hpp"

SMSDK_BEGIN_NAMESPACE

void InGameGuiManager::displayAlertText(
	const std::string_view& text,
	const float duration)
{
	if (!m_pHudGui)
		return;

	m_pHudGui->m_alertText = text;
	m_pHudGui->m_fAlertTextTimer = duration;
}

void InGameGuiManager::setInteractionText(const std::vector<std::string>& vec)
{
	if (m_pHudGui)
	{
		const size_t lastEntry = m_pHudGui->m_vecInteractionTexts.size();

		m_pHudGui->m_vecInteractionTexts.push_back(vec);
		m_pHudGui->m_vecInteractionTexts[lastEntry].push_back("\n");
	}
}

void InGameGuiManager::DisplayAlertText(const std::string_view& text, const float duration)
{
	InGameGuiManager* v_pInGameGuiMgr = InGameGuiManager::GetInstance();
	if (v_pInGameGuiMgr)
		v_pInGameGuiMgr->displayAlertText(text, duration);
}

void InGameGuiManager::SetInteractionText(const std::vector<std::string>& vec)
{
	InGameGuiManager* v_pInGameGuiMgr = InGameGuiManager::GetInstance();
	if (v_pInGameGuiMgr)
		return v_pInGameGuiMgr->setInteractionText(vec);
}

SMSDK_END_NAMESPACE