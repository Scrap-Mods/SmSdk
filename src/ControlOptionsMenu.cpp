#include "SmSdk/Gui/ControlOptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

ControlOptionsMenu* ControlOptionsMenu::New()
{
	return new ControlOptionsMenu();
}

ControlOptionsMenu::ControlOptionsMenu()
{
	using fSelfConstructor = void (*)(ControlOptionsMenu*);
	Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET)(this);
}

SMSDK_END_NAMESPACE