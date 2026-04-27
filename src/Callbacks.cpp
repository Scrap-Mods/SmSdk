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

bool Callbacks::InstallHandlers()
{
	const std::uintptr_t v_moduleBase = std::uintptr_t(GetModuleHandleA(nullptr));

	if (MH_CreateHook(
		reinterpret_cast<LPVOID>(v_moduleBase + SM_FUNC_PERFRAME_UPDATE),
		reinterpret_cast<LPVOID>(Callbacks::OnRenderCallbackHandler),
		reinterpret_cast<LPVOID*>(&o_OnRenderCallback)
	) != MH_OK) return false;

	return true;
}

std::mutex Callbacks::ms_mutex;
std::vector<Callbacks::OnRenderCallback> Callbacks::ms_onRenderCallbacks;

#endif

SMSDK_END_NAMESPACE