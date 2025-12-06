#pragma once

#include "SmSdk/Network/NetworkServer.hpp"

SMSDK_BEGIN_NAMESPACE

struct SteamNetworkServer : public NetworkServer
{
private:
	/* 0x0030 */ char pad_0x30[0xF8];
}; // Size: 0x128

static_assert(sizeof(SteamNetworkServer) == 0x128, "SteamNetworkServer: Incorrect Size");

SMSDK_END_NAMESPACE