#pragma once

#include "SmSdk/steamapi_include.hpp"
#include "SmSdk/config.hpp"
#include <unordered_map>

SMSDK_BEGIN_NAMESPACE

struct NetworkSendInterface
{
private:
	/* 0x0000 */ virtual void func1() {}

	/* 0x0008 */ char pad_0x8[0x10];
public:
	/* 0x0018 */ std::int64_t m_iTick;
	/* 0x0020 */ std::int64_t m_iTick2;
}; // Size: 0x28

static_assert(sizeof(NetworkSendInterface) == 0x28, "NetworkSendInterface: Incorrect Size");

struct SteamNetworkSend : public NetworkSendInterface
{
	/* 0x0028 */ std::unordered_map<uint64_t, HSteamNetConnection> m_mapSteamIdToConnection;
private:
	/* 0x0068 */ char pad_0x68[0xC0];
public:
	HSteamNetConnection getConnectionFromSteamId(uint64_t uSteamId) const
	{
		auto iter = this->m_mapSteamIdToConnection.find(uSteamId);
		if (iter == this->m_mapSteamIdToConnection.end())
			return 0;

		return iter->second;
	}
}; // Size: 0x128

static_assert(sizeof(SteamNetworkSend) == 0x128, "SteamNetworkSend: Incorrect Size");

SMSDK_END_NAMESPACE