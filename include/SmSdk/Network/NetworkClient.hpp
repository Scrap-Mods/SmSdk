#pragma once

#include "SmSdk/steamapi_include.hpp"

#include <unordered_map>
#include <memory>
#include <string>

SMSDK_BEGIN_NAMESPACE

class NetworkClient
{
private:
	/* 0x0000 */ char pad_0x0[0x8];
public:
	/* 0x0008 */ std::shared_ptr<SteamNetworkSend> m_pNetworkSend;
	/* 0x0018 */ std::int32_t m_iConnectionState;
private:
	/* 0x001C */ char pad_0x1C[0x2C];
	/* 0x0048 */ std::string m_someString1;
	/* 0x0068 */ char pad_0x68[0x80];
public:
	/* 0x00E8 */ std::shared_ptr<struct TickLag> m_pTickLag;
private:
	/* 0x00F8 */ char pad_0xF8[0x38];
public:
	HSteamNetConnection getConnectionFromSteamId(uint64_t steamId) const
	{
		if (this->m_pNetworkSend == nullptr)
			return 0;

		return this->m_pNetworkSend->getConnectionFromSteamId(steamId);
	}
}; // Size: 0x130

static_assert(sizeof(NetworkClient) == 0x130, "NetworkClient: Incorrect Size");

SMSDK_END_NAMESPACE