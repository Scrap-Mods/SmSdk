#include "SmSdk/Gui/AudioOptionsMenu.hpp"

SMSDK_BEGIN_NAMESPACE

AudioOptionsMenu* AudioOptionsMenu::New()
{
	return new AudioOptionsMenu();
}

AudioOptionsMenu::AudioOptionsMenu()
{
	Memory::OverwriteVftable(this, SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET);
}

SMSDK_END_NAMESPACE