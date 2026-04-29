#include "SmSdk/Gui/GraphicsOptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

GraphicsOptionsMenu* GraphicsOptionsMenu::New()
{
	return new GraphicsOptionsMenu();
}

GraphicsOptionsMenu::GraphicsOptionsMenu()
{
	using fSelfConstructor = void (*)(GraphicsOptionsMenu*);
	Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET)(this);
}

SMSDK_END_NAMESPACE