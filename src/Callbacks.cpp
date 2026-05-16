#include "SmSdk/Gui/OptionsMenu.hpp"
#include "SmSdk/Callbacks.hpp"
#include "SmSdk/offsets.hpp"

#if defined(SMSDK_BUILD_DLL)
# include <MinHook.h>
# include <mutex>
#endif

SMSDK_BEGIN_NAMESPACE

#if defined(SMSDK_BUILD_DLL)

void Callbacks::RegisterOnRenderCallback(OnRenderCallback callback)
{
	std::lock_guard<std::mutex> v_lock(ms_mutex);
	ms_onRenderCallbacks.push_back(callback);
}

void Callbacks::RegisterOnServerPacketCallback(ServerPacketCallback callback)
{
	std::lock_guard<std::mutex> v_lock(ms_mutex);
	ms_onServerPacketCallbacks.push_back(callback);
}

void Callbacks::RegisterOnClientPacketCallback(ClientPacketCallback callback)
{
	std::lock_guard<std::mutex> v_lock(ms_mutex);
	ms_onClientPacketCallbacks.push_back(callback);
}

static void (*o_OnRenderCallback)(void*, float, void*, void*, void*) = nullptr;
void Callbacks::OnRenderCallbackHandler(
	void* self,
	float deltaTime,
	void* a3,
	void* a4,
	void* pFrameSettings)
{
	for (const auto v_curCallback : ms_onRenderCallbacks)
		v_curCallback(deltaTime);

	o_OnRenderCallback(self, deltaTime, a3, a4, pFrameSettings);
}

static void (*o_OnServerPacketCallbackHandler)(SteamNetworkServer*, STEAM_ID_TYPE, const void*, const std::uint32_t);
void Callbacks::OnServerPacketCallbackHandler(
	SteamNetworkServer* self,
	STEAM_ID_TYPE steamId,
	const void* packetData,
	const std::uint32_t packetDataSz)
{
	for (const auto v_curCallback : ms_onServerPacketCallbacks)
		if (v_curCallback(self, DEREF_STEAM_ID(steamId), packetData, packetDataSz))
			return;

	o_OnServerPacketCallbackHandler(self, steamId, packetData, packetDataSz);
}

static void (*o_OnClientPacketCallbackHandler)(SteamNetworkClient*, STEAM_ID_TYPE, const void*, const std::uint32_t, const bool);
void Callbacks::OnClientPacketCallbackHandler(
	SteamNetworkClient* self,
	STEAM_ID_TYPE steamId,
	const void* packetData,
	const std::uint32_t packetDataSz,
	const bool someFlag)
{
	for (const auto v_curCallback : ms_onClientPacketCallbacks)
		if (v_curCallback(self, DEREF_STEAM_ID(steamId), packetData, packetDataSz))
			return;

	o_OnClientPacketCallbackHandler(self, steamId, packetData, packetDataSz, someFlag);
}

static void (*o_OptionsMenuConstructor)(OptionsMenu*, class GuiBase*, const bool);
static void (*o_OptionsMenuInitialize)(OptionsMenu*);

bool Callbacks::InstallHandlers()
{
	const std::uintptr_t v_moduleBase = std::uintptr_t(GetModuleHandleA(nullptr));

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_PERFRAME_UPDATE),
		reinterpret_cast<LPVOID>(Callbacks::OnRenderCallbackHandler),
		reinterpret_cast<LPVOID*>(&o_OnRenderCallback)
	) != MH_OK) return false;

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_SERVER_PACKET_HANDLER),
		reinterpret_cast<LPVOID>(Callbacks::OnServerPacketCallbackHandler),
		reinterpret_cast<LPVOID*>(&o_OnServerPacketCallbackHandler)
	) != MH_OK) return false;

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_CLIENT_PACKET_HANDLER),
		reinterpret_cast<LPVOID>(Callbacks::OnClientPacketCallbackHandler),
		reinterpret_cast<LPVOID*>(&o_OnClientPacketCallbackHandler)
	) != MH_OK) return false;

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_OPTIONS_MENU_CONSTRUCTOR),
		reinterpret_cast<LPVOID>(OptionsMenu::Constructor),
		reinterpret_cast<LPVOID*>(&o_OptionsMenuConstructor)
	) != MH_OK) return false;

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_OPTIONS_MENU_INITIALIZE),
		reinterpret_cast<LPVOID>(OptionsMenu::Initialize),
		reinterpret_cast<LPVOID*>(&o_OptionsMenuInitialize)
	) != MH_OK) return false;

	return true;
}

std::mutex Callbacks::ms_mutex;
std::vector<Callbacks::OnRenderCallback> Callbacks::ms_onRenderCallbacks;
std::vector<Callbacks::ServerPacketCallback> Callbacks::ms_onServerPacketCallbacks;
std::vector<Callbacks::ClientPacketCallback> Callbacks::ms_onClientPacketCallbacks;

#endif

SMSDK_END_NAMESPACE