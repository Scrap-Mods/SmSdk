#include <SmSdk/Util/Memory.hpp>
#include <SmSdk/offsets.hpp>

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"

SMSDK_BEGIN_NAMESPACE

class GameplayOptionsMenu : public OptionsSubMenuBase
{
public:
	GameplayOptionsMenu()
	{
		OptionsSubMenuBase::GameConstructor(this);
#if _SM_VERSION_NUM >= 070771
		std::memset(this->m_someData, 0, sizeof(this->m_someData));
#endif
		Memory::OverwriteVftable(this, SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET);
	}

	virtual ~GameplayOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

#if _SM_VERSION_NUM >= 070771
private:
	char m_someData[16];
#endif
}; // Size: 0x168

#if _SM_VERSION_NUM >= 070771
static_assert(sizeof(GameplayOptionsMenu) == 0x178, "GameplayOptionsMenu: Incorrect Size");
#else
static_assert(sizeof(GameplayOptionsMenu) == 0x168, "GameplayOptionsMenu: Incorrect Size");
#endif

SMSDK_END_NAMESPACE