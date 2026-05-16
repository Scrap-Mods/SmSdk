#include "SmSdk/Gui/OptionsMenu.hpp"

#include "SmSdk/Gui/GameplayOptionsMenu.hpp"
#include "SmSdk/Gui/ControlOptionsMenu.hpp"
#include "SmSdk/Gui/AudioOptionsMenu.hpp"
#include "SmSdk/Gui/DisplayOptionsMenu.hpp"
#include "SmSdk/Gui/GraphicsOptionsMenu.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"

SMSDK_BEGIN_NAMESPACE

struct OptionsMenuTabCallback
{
	std::string m_tabGuiName;
	std::string m_tabCaption;
	// A callback that checks whether the sub menu should be created in the first place
	bool (*canCreate)(OptionsMenu* self);
	OptionsSubMenuBase* (*create)();
};

static std::vector<OptionsMenuTabCallback> ms_vecOptionCallbacks =
{
	{
		.m_tabGuiName = "Gameplay",
		.m_tabCaption = "GAMEPLAY_CHANGE_LATER",
		.canCreate = [](OptionsMenu* self) { return self->m_bIsServer; },
		.create = []() -> OptionsSubMenuBase* {
			return SM::GameplayOptionsMenu::New();	
		}
	},
	{
		.m_tabGuiName = "Controls",
		.m_tabCaption = "CONTROLS_CHANGE_LATER",
		.canCreate = [](OptionsMenu* self) { return true; },
		.create = []() -> OptionsSubMenuBase* {
			return SM::ControlOptionsMenu::New();
		}
	},
	{
		.m_tabGuiName = "Audio",
		.m_tabCaption = "AUDIO_CHANGE_LATER",
		.canCreate = [](OptionsMenu* self) { return true; },
		.create = []() -> OptionsSubMenuBase* {
			return SM::AudioOptionsMenu::New();
		}
	},
	{
		.m_tabGuiName = "Display",
		.m_tabCaption = "DISPLAY_CHANGE_LATER",
		.canCreate = [](OptionsMenu* self) { return true; },
		.create = []() -> OptionsSubMenuBase* {
			return SM::DisplayOptionsMenu::New();
		}
	},
	{
		.m_tabGuiName = "Graphics",
		.m_tabCaption = "GRAPHICS_CHANGE_LATER",
		.canCreate = [](OptionsMenu* self) { return true; },
		.create = []() -> OptionsSubMenuBase* {
			return SM::GraphicsOptionsMenu::New();
		}
	}
};

OptionsMenu::OptionsMenu(
	GuiBase* rootGui,
	const bool isServer
)
	: m_pMenuRootGui(rootGui)
	, m_bIsOpen(false)
	, m_bIsServer(isServer)
	, m_pCompoundButton(nullptr)
	, m_pRadioButtonSet(nullptr)
	, m_pCurrentTab(nullptr)
	, m_mapSubMenus()
{
	for (const auto& v_curTab : ms_vecOptionCallbacks)
	{
		if (v_curTab.canCreate(this))
			m_mapSubMenus.emplace(v_curTab.m_tabGuiName, v_curTab.create());
	}

	m_pCurrentTab = m_mapSubMenus[m_bIsServer ? "Gameplay" : "Controls"];
}

OptionsMenu* OptionsMenu::Constructor(
	OptionsMenu* self,
	GuiBase* rootGui,
	const bool isServer)
{
	// In place constructor for a completely custom options menu
	new (self) OptionsMenu(rootGui, isServer);
	// Overwrite the vftable with the original one since I can't be bothered to recreate this humongous vftable for now.
	SM::Memory::OverwriteVftable(self, SM_VTBL_OPTIONS_MENU_OFFSET);

	return self;
}

static void InitializeButtonList(
	OptionsMenu* self,
	std::vector<MyGUI::Button*>& outVecButtons)
{
	MyGUI::Widget* v_pGfxWidget = self->m_pMainPanel->findWidget("Graphics");
	MyGUI::Widget* v_pDisplayWidget = self->m_pMainPanel->findWidget("Display");
	
	const float v_parentWidth = static_cast<float>(v_pDisplayWidget->getParentSize().width);
	const int v_tabDistance = static_cast<int>(v_parentWidth / 500.0f);
	int v_tabOffset = static_cast<int>(v_parentWidth / 40.0f);
	
	const MyGUI::IntCoord v_tabData = v_pDisplayWidget->getCoord();
	for (const auto& v_curTab : ms_vecOptionCallbacks)
	{
		if (!v_curTab.canCreate(self)) continue;

		MyGUI::Button* v_pCurTabWidgetBtn;

		MyGUI::Widget* v_pCurTabWidget = self->m_pMainPanel->findWidget(v_curTab.m_tabGuiName);
		if (!v_pCurTabWidget)
		{
			const MyGUI::IntCoord v_newTabPos(
				v_tabOffset,
				v_tabData.top,
				v_tabData.width,
				v_tabData.height);

			v_pCurTabWidgetBtn = v_pGfxWidget->getParent()->createWidget<MyGUI::Button>(
				"InventoryTab", v_newTabPos, MyGUI::Align::Default, v_curTab.m_tabGuiName);

			v_pCurTabWidgetBtn->setFontName("SM_Tab");
			v_pCurTabWidgetBtn->setCaption(v_curTab.m_tabCaption);
			v_pCurTabWidgetBtn->setTextAlign(MyGUI::Align::Center);
		}
		else
		{
			v_pCurTabWidgetBtn = v_pCurTabWidget->castType<MyGUI::Button>();
		}

		const int v_textSize = v_pCurTabWidgetBtn->getTextSize().width;

		auto v_adjustedTabPos = v_pCurTabWidgetBtn->getCoord();
		v_adjustedTabPos.left = v_tabOffset;
		v_adjustedTabPos.width = v_textSize + static_cast<int>(v_parentWidth / (15.0f * 2.0f));
		v_pCurTabWidgetBtn->setCoord(v_adjustedTabPos);

		outVecButtons.push_back(v_pCurTabWidgetBtn);
		v_tabOffset += (v_tabDistance + v_adjustedTabPos.width);
	}
}

void OptionsMenu::Initialize(OptionsMenu* self)
{
	SM::GuiSystemManager* v_pGuiSysMgr = SM::GuiSystemManager::GetInstance();

	const MyGUI::IntCoord v_panelCoord(
		v_pGuiSysMgr->getScreenLeft(), v_pGuiSysMgr->getScreenTop(),
		v_pGuiSysMgr->getScreenWidth(), v_pGuiSysMgr->getScreenHeight());

	self->m_pMainPanel = MyGUI::Gui::getInstancePtr()->createWidget<MyGUI::Widget>(
		"PanelEmpty", v_panelCoord, MyGUI::Align::Default, "MainMenu", "OptionsMenu");

	MyGUI::LayoutManager::getInstancePtr()->loadLayout(
		"$GAME_DATA/Gui/Layouts/Common/MenuBackButton.layout", "", self->m_pMainPanel);

	if (self->m_bIsServer)
	{
		MyGUI::LayoutManager::getInstancePtr()->loadLayout(
			"$GAME_DATA/Gui/Layouts/Options/Options_InGameMenu.layout", "", self->m_pMainPanel);
	}
	else
	{
		MyGUI::LayoutManager::getInstancePtr()->loadLayout(
			"$GAME_DATA/Gui/Layouts/Options/Options_MainMenu.layout", "", self->m_pMainPanel);
	}

	MyGUI::Widget* v_pBackWidget = self->m_pMainPanel->findWidget("Back");
	v_pBackWidget->eventMouseButtonClick += MyGUI::newDelegate(self, &OptionsMenu::onBackPanelMouseClickCallback);
	self->m_pCompoundButton = CompoundButton::New(v_pBackWidget);

	std::vector<MyGUI::Button*> v_tabButtons;
	InitializeButtonList(self, v_tabButtons);

	for (auto& v_curTab : self->m_mapSubMenus)
	{
		if (v_curTab.second != self->m_pCurrentTab)
			continue;

		MyGUI::Button* v_pSelectedTab = self->m_pMainPanel->findWidget(v_curTab.first)->castType<MyGUI::Button>();
		v_pSelectedTab->setStateSelected(true);
	}

	self->m_pRadioButtonSet = SM::RadioButtonSet::New(v_tabButtons);

	// Initialize all the tabs
	MyGUI::Widget* v_pHostPanel = self->m_pMainPanel->findWidget("OptionsHostPanel");
	for (auto& v_pCurSubMenu : self->m_mapSubMenus)
		v_pCurSubMenu.second->initialize(v_pHostPanel);

	// Attach the tab switch callback to all the tabs
	for (MyGUI::Widget* v_pCurTabWidget : v_tabButtons)
		v_pCurTabWidget->eventMouseButtonClick += MyGUI::newDelegate(
			self, &OptionsMenu::onTabSwitchCallback);

	self->m_pMainPanel->findWidget("Default")->eventMouseButtonClick += MyGUI::newDelegate(
		self, &OptionsMenu::onRestoreDefaultsButtonClick);

	self->m_pMainPanel->setVisible(self->m_bIsOpen);
	if (self->m_bIsOpen)
		self->m_pCurrentTab->openMenu();
}

void OptionsMenu::AddSubMenu(
	const std::string_view& tabGuiName,
	const std::string_view& tabCaption,
	bool (*onCanCreate)(OptionsMenu*),
	OptionsSubMenuBase* (*onCreate)())
{
	auto& v_newItem = ms_vecOptionCallbacks.emplace_back();
	v_newItem.m_tabGuiName = tabGuiName;
	v_newItem.m_tabCaption = tabCaption;
	v_newItem.canCreate = onCanCreate;
	v_newItem.create = onCreate;
}

void OptionsMenu::onBackPanelMouseClickCallback(MyGUI::Widget* _sender)
{
	this->close();
	m_pMenuRootGui->open();
}

void OptionsMenu::onTabSwitchCallback(MyGUI::Widget* _sender)
{
	auto v_iter = m_mapSubMenus.find(_sender->getName());
	if (v_iter == m_mapSubMenus.end())
		return;

	if (v_iter->second != m_pCurrentTab)
	{
		if (m_pCurrentTab)
			m_pCurrentTab->closeMenu();

		v_iter->second->openMenu();
		m_pCurrentTab = v_iter->second;
	}
}

void OptionsMenu::onRestoreDefaultsButtonClick(MyGUI::Widget* _sender)
{
	m_pCurrentTab->restoreDefaults();
}

SMSDK_END_NAMESPACE