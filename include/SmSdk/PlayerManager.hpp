#pragma once

#include "SmSdk/Player.hpp"

#include <unordered_map>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class PlayerManager
{
public:
	static PlayerManager* GetInstance();

	inline Player* _getPlayer(int player_id)
	{
		auto iter = m_mapIdToPlayers.find(player_id);
		if (iter == m_mapIdToPlayers.end())
			return nullptr;

		return iter->second.get();
	}

	inline Player* _getPlayerFromSteamId(uint64_t steam_id)
	{
		auto iter = m_mapSteamIdToPlayer.find(steam_id);
		if (iter == m_mapSteamIdToPlayer.end())
			return nullptr;

		return this->_getPlayer(iter->second);
	}

	inline static Player* GetPlayer(int player_id)
	{
		PlayerManager* pPlayerMgr = PlayerManager::GetInstance();
		if (!pPlayerMgr)
			return nullptr;

		return pPlayerMgr->_getPlayer(player_id);
	}

	inline static Player* GetPlayerFromSteamId(uint64_t steam_id)
	{
		PlayerManager* pPlayerMgr = PlayerManager::GetInstance();
		if (!pPlayerMgr)
			return nullptr;

		return pPlayerMgr->_getPlayerFromSteamId(steam_id);
	}

	/* 0x0000 */ std::int32_t m_iTick;
private:
	/* 0x0004 */ char pad_0x4[0x4];
public:
	/* 0x0008 */ std::unordered_map<int, std::shared_ptr<Player>> m_mapIdToPlayers;
	/* 0x0048 */ std::unordered_map<uint64_t, int> m_mapSteamIdToPlayer;
private:
	/* 0x0088 */ char pad_0x88[0xC0];
}; // Size: 0x148

static_assert(sizeof(PlayerManager) == 0x148, "PlayerManager: Incorrect Size");

SMSDK_END_NAMESPACE