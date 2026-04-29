#include "SmSdk/Gui/GameplayOptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

GameplayOptionsMenu* GameplayOptionsMenu::New()
{
	return new GameplayOptionsMenu();
}

GameplayOptionsMenu::GameplayOptionsMenu()
{
#if _SM_VERSION_NUM >= 070771
	std::memset(this->m_someData, 0, sizeof(this->m_someData));
#endif
	Memory::OverwriteVftable(this, SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET);
}

SMSDK_END_NAMESPACE