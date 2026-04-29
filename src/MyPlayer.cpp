#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/MyPlayer.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

Character* MyPlayer::getCharacter() const
{
	return m_player ? CharacterManager::GetCharacter(m_player->m_uCharacterId) : nullptr;
}

Player* MyPlayer::getPlayer() const
{
	return m_player.get();
}

SMSDK_END_NAMESPACE