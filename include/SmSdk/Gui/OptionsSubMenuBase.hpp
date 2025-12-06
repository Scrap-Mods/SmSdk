#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/mygui_include.hpp"
#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include "SmSdk/Gui/VerticalStackBox.hpp"
#include "SmSdk/Gui/OptionsItemBase.hpp"

#include <vector>

SMSDK_BEGIN_NAMESPACE

class OptionsSubMenuBase
{
public:
	static void GameConstructor(OptionsSubMenuBase* self)
	{
		using fSubMenuBaseConstructor = void (*)(OptionsSubMenuBase*);
		Memory::Read<fSubMenuBaseConstructor>(SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET)(self);
	}

#if defined(SMSDK_ENABLE_MYGUI)
	OptionsSubMenuBase();
#endif
	virtual ~OptionsSubMenuBase() = default;

#if defined(SMSDK_ENABLE_MYGUI)
	void onScrollChangePos(MyGUI::ScrollBar* pCaller, size_t iPos);
	void onScroll(MyGUI::Widget* pCaller, int iScrollVal);
	void updateScrollArea();
	void updateScrollAreaAndScrollBar();
	//Does not update the scroll bar
	void clearSilent();
	void clear();
#endif

	virtual void initialize(MyGUI::Widget* pParent) DEFAULT_IMPL_UNREF(pParent);

	virtual void cleanOptionItems() DEFAULT_IMPL();
	virtual void openMenu() DEFAULT_IMPL();
	virtual void closeMenu() DEFAULT_IMPL();

	virtual void onUpdate() {}
private:
	virtual bool someFunc2() { return 0; }
	virtual bool someFunc3() { return 0; }
public:
	virtual void restoreDefaults() = 0;
private:
#if _SM_VERSION_NUM >= 070771
	virtual void someFunc5() {}
#endif
	virtual void someFunc4() {}
public:
	/* 0x0008 */ MyGUI::Widget* m_pSubMenuWidget;
	/* 0x0010 */ MyGUI::Widget* m_pContainerHostPanel;
	/* 0x0018 */ MyGUI::Widget* m_pContainer;
	/* 0x0020 */ MyGUI::ScrollBar* m_pScrollBar;
	/* 0x0028 */ MyGUI::IntSize m_itemSize;
	/* 0x0030 */ VerticalStackBox m_leftStackBox;
	/* 0x00B8 */ VerticalStackBox m_rightStackBox;
	/* 0x0140 */ std::vector<std::shared_ptr<OptionsItemBase>> m_vecOptionItems;
	/* 0x0158 */ std::int32_t m_iScrollValue;
	/* 0x015C */ MyGUI::IntPoint m_containerPos;
private:
	/* 0x0164 */ char pad_0x164[0x4];

}; // Size: 0x168

static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pSubMenuWidget) == 0x8, "OptionsSubMenuBase::m_pSubMenuWidget: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pContainerHostPanel) == 0x10, "OptionsSubMenuBase::m_pContainerHostPanel: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pContainer) == 0x18, "OptionsSubMenuBase::m_pContainer: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pScrollBar) == 0x20, "OptionsSubMenuBase::m_pScrollBar: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_itemSize) == 0x28, "OptionsSubMenuBase::m_itemSize: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_leftStackBox) == 0x30, "OptionsSubMenuBase::m_leftStackBox: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_rightStackBox) == 0xB8, "OptionsSubMenuBase::m_rightStackBox: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_vecOptionItems) == 0x140, "OptionsSubMenuBase::m_vecOptionItems: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_iScrollValue) == 0x158, "OptionsSubMenuBase::m_iScrollValue: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_containerPos) == 0x15C, "OptionsSubMenuBase::m_containerPos: Incorrect offset");

static_assert(sizeof(OptionsSubMenuBase) == 0x168, "OptionsSubMenuBase: Incorrect Size");

SMSDK_END_NAMESPACE