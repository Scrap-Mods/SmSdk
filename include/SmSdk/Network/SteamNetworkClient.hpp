#pragma once

#include "SmSdk/Network/SteamNetworkSend.hpp"
#include "SmSdk/Network/NetworkClient.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

struct SteamNetworkClient : public NetworkClient
{
private:
	/* 0x0130 */ char pad_0x130[0x8];
public:
	/* 0x0138 */ std::int64_t m_iHostSteamId;
private:
	/* 0x0140 */ char pad_0x140[0x78];
public:
	/* 0x01B8 */ HSteamNetConnection m_hostConnection;
private:
	/* 0x01BC */ char pad_0x1BC[0x2C];
public:
	/* 0x01E8 */ std::string m_passphrase;
private:
	/* 0x0208 */ char pad_0x208[0x28];
}; // Size: 0x230

static_assert(sizeof(SteamNetworkClient) == 0x230, "SteamNetworkClient: Incorrect Size");

SMSDK_END_NAMESPACE