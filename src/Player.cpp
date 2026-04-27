#include "SmSdk/Player.hpp"

#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

Character* Player::getCharacter() const
{
	return CharacterManager::GetCharacter(m_uCharacterId);
}

bool Player::characterExists() const
{
	return this->getCharacter() != nullptr;
}