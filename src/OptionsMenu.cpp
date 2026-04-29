#include "SmSdk/Gui/OptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

void OptionsMenu::addSubMenu(
	const std::string_view& name,
	OptionsSubMenuBase* pSubMenu)
{
	m_mapSubMenus.emplace(name, pSubMenu);
}

SMSDK_END_NAMESPACE