#include "SmSdk/PlayerManager.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<Player> PlayerManager::getPlayer(const std::uint32_t playerId)
{
	auto v_iter = m_mapIdToPlayers.find(playerId);
	if (v_iter != m_mapIdToPlayers.end())
		return v_iter->second;
	else 
		return nullptr;
}

std::shared_ptr<Player> PlayerManager::getPlayerFromSteamId(const std::uint64_t steamId)
{
	auto v_iter = m_mapSteamIdToPlayer.find(steamId);
	if (v_iter != m_mapSteamIdToPlayer.end())
		return this->getPlayer(v_iter->second);
	else
		return nullptr;
}

std::vector<std::shared_ptr<Player>> PlayerManager::getAllPlayers()
{
	std::vector<std::shared_ptr<Player>> v_outVecPlayers;

	for (const auto& [playerId, playerPtr] : m_mapIdToPlayers)
		v_outVecPlayers.emplace_back(playerPtr);

	return v_outVecPlayers;
}

std::shared_ptr<Player> PlayerManager::GetPlayer(const std::uint32_t playerId)
{
	PlayerManager* v_pPlayerMgr = PlayerManager::GetInstance();
	if (v_pPlayerMgr)
		return v_pPlayerMgr->getPlayer(playerId);
	else
		return nullptr;
}

std::shared_ptr<Player> PlayerManager::GetPlayerFromSteamId(const std::uint64_t steamId)
{
	PlayerManager* v_pPlayerMgr = PlayerManager::GetInstance();
	if (v_pPlayerMgr)
		return v_pPlayerMgr->getPlayerFromSteamId(steamId);
	else
		return nullptr;
}

std::vector<std::shared_ptr<Player>> PlayerManager::GetAllPlayers()
{
	PlayerManager* v_pPlayerMgr = PlayerManager::GetInstance();
	if (v_pPlayerMgr)
		return v_pPlayerMgr->getAllPlayers();
	else
		return {};
}

SMSDK_END_NAMESPACE