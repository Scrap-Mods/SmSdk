#include "SmSdk/Player.hpp"

#include "SmSdk/Character/CharacterManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

std::uint64_t Player::getSteamId() const
{
	return m_uSteamId;
}

std::uint32_t Player::getId() const
{
	return m_uId;
}

std::uint32_t Player::getCharacterId() const
{
	return m_uCharacterId;
}

std::uint16_t Player::getWorldId() const
{
	return m_uWorldId;
}

std::shared_ptr<Character> Player::getCharacter() const
{
	return CharacterManager::GetCharacter(m_uCharacterId);
}

bool Player::characterExists() const
{
	return this->getCharacter() != nullptr;
}