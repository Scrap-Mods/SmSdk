#include "SmSdk/Gui/DisplayOptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

DisplayOptionsMenu* DisplayOptionsMenu::New()
{
	return new DisplayOptionsMenu();
}

DisplayOptionsMenu::DisplayOptionsMenu()
{
	using fSelfConstructor = void (*)(DisplayOptionsMenu*);
	Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET)(this);
}

SMSDK_END_NAMESPACE