#include "SmSdk/Network/NetworkSendInterface.hpp"

SMSDK_BEGIN_NAMESPACE

std::vector<std::pair<std::uint64_t, HSteamNetConnection>> SteamNetworkSend::getAllConnections() const
{
	std::vector<std::pair<std::uint64_t, HSteamNetConnection>> v_vecConnections;

	v_vecConnections.reserve(m_mapSteamIdToConnection.size());
	for (const auto& [steamId, netConnection] : m_mapSteamIdToConnection)
		v_vecConnections.emplace_back(steamId, netConnection);
	
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