#pragma once

#include "SmSdk/config.hpp"
#include "SmSdk/Network/SteamNetworkSend.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

struct NetworkServer
{
private:
	/* 0x0000 */ virtual void func1() {}
public:
	/* 0x0008 */ std::shared_ptr<SteamNetworkSend> m_pNetworkSend;
	/* 0x0018 */ std::shared_ptr<struct ClientCommunication> m_pClientCommunication;
private:
	/* 0x0028 */ char pad_0x28[0x8];
}; // Size: 0x30

static_assert(sizeof(NetworkServer) == 0x30, "NetworkServer: Incorrect Size");

SMSDK_END_NAMESPACE