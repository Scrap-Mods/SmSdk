#pragma once

#include "SmSdk/config.hpp"
#include "SteamNetworkServer.hpp"

SMSDK_BEGIN_NAMESPACE

struct ListenServer
{
	/* 0x0000 */ SteamNetworkServer* m_pNetworkServer;
private:
	/* 0x0008 */ char pad_0x8[0x1B8];
}; // Size: 0x1C0

static_assert(sizeof(ListenServer) == 0x1C0, "ListenServer: Incorrect Size");

SMSDK_END_NAMESPACE