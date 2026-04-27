#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/MyPlayer.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

Character* MyPlayer::getCharacter() const
{
	return m_player ? CharacterManager::GetCharacter(m_player->m_uCharacterId) : nullptr;
}