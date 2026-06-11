#include "SmSdk/Network/SteamNetworkClient.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<SteamNetworkSend> SteamNetworkClient::getNetworkSend() const
{
	return std::static_pointer_cast<SteamNetworkSend, NetworkSendInterface>(m_pNetworkSend);
}

HSteamNetConnection SteamNetworkClient::getConnectionFromSteamId(const std::uint64_t uSteamId) const
{
	if (m_pNetworkSend)
		return getNetworkSend()->getConnectionFromSteamId(uSteamId);
	else
		return 0;
}

std::uint64_t SteamNetworkClient::getHostSteamId() const
{
	return m_uHostSteamId;
}

HSteamNetConnection SteamNetworkClient::getHostConnection() const
{
	return m_hostConnection;
}

SMSDK_END_NAMESPACE