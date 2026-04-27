#if defined(SMSDK_BUILD_DLL)

#include "SmSdk/win_include.hpp"
#include "SmSdk/SmSdk.hpp"

#include "SmSdk/Callbacks.hpp"
#include <MinHook.h>

static bool SmSdk_MinHookInitialized = false;
static bool SmSdk_MinHookAttached = false;

static bool SmSdkInitialize()
{
	if (!SmSdk::CheckTimestamp(_SM_TIMESTAMP_074_778))
	{
		MessageBoxA(nullptr, "The specific SmSdk build requires Scrap Mechanic version 0.7.4.778\n\nPress OK if you want to continue loading without SmSdk", "SmSdk Fail", MB_OK);
		return false;
	}

	if (MH_Initialize() != MH_OK)
		return false;

	SM::Callbacks::InstallHandlers();
		
	SmSdk_MinHookInitialized = true;
	SmSdk_MinHookAttached = MH_EnableHook(MH_ALL_HOOKS) == MH_OK;

	return true;
}

static void SmSdkUninitialize()
{
	if (SmSdk_MinHookAttached)
	{
		if (SmSdk_MinHookAttached)
		{
			MH_DisableHook(MH_ALL_HOOKS);
			SmSdk_MinHookAttached = false;
		}

		MH_Uninitialize();
		SmSdk_MinHookAttached = false;
	}
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		if (!SmSdkInitialize())
			return FALSE;

		break;
	}
	case DLL_PROCESS_DETACH:
		SmSdkUninitialize();
		break;
	default:
		break;
	}

	return TRUE;
}

#endif