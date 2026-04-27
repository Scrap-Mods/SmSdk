#include "SmSdk/PlayerManager.hpp"

SMSDK_BEGIN_NAMESPACE

Player* PlayerManager::_getPlayer(const std::uint32_t playerId)
{
	auto v_iter = m_mapIdToPlayers.find(playerId);
	if (v_iter != m_mapIdToPlayers.end())
		return v_iter->second.get();
	else 
		return nullptr;
}

Player* PlayerManager::_getPlayerFromSteamId(const std::uint64_t steamId)
{
	auto v_iter = m_mapSteamIdToPlayer.find(steamId);
	if (v_iter != m_mapSteamIdToPlayer.end())
		return this->_getPlayer(v_iter->second);
	else
		return nullptr;
}

Player* PlayerManager::GetPlayer(const std::uint32_t playerId)
{
	PlayerManager* v_pPlayerMgr = PlayerManager::GetInstance();
	if (v_pPlayerMgr)
		return v_pPlayerMgr->_getPlayer(playerId);
	else
		return nullptr;
}

Player* PlayerManager::GetPlayerFromSteamId(const std::uint64_t steamId)
{
	PlayerManager* v_pPlayerMgr = PlayerManager::GetInstance();
	if (v_pPlayerMgr)
		v_pPlayerMgr->_getPlayerFromSteamId(steamId);
	else
		return nullptr;
}

SMSDK_END_NAMESPACE