#include "SmSdk/Network/NetworkSendInterface.hpp"

SMSDK_BEGIN_NAMESPACE

std::vector<HSteamNetConnection> SteamNetworkSend::getAllConnections() const
{
	std::vector<HSteamNetConnection> v_vecConnections;

	v_vecConnections.reserve(m_mapSteamIdToConnection.size());
	for (const auto& [steamId, netConnection] : m_mapSteamIdToConnection)
		v_vecConnections.push_back(netConnection);
	
	return v_vecConnections;
}

HSteamNetConnection SteamNetworkSend::getConnectionFromSteamId(const std::uint64_t uSteamId) const
{
	auto v_iter = m_mapSteamIdToConnection.find(uSteamId);
	if (v_iter != m_mapSteamIdToConnection.end())
		return v_iter->second;
	else
		return 0;
}

SMSDK_END_NAMESPACE