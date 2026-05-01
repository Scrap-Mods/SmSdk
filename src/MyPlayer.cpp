#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/MyPlayer.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<Character> MyPlayer::getCharacter() const
{
	return m_player ? CharacterManager::GetCharacter(m_player->m_uCharacterId) : nullptr;
}

std::shared_ptr<Player> MyPlayer::getPlayer() const
{
	return m_player;
}

std::shared_ptr<Character> MyPlayer::GetCharacter()
{
	MyPlayer* v_pMyPlayer = MyPlayer::GetInstance();
	if (v_pMyPlayer)
		return v_pMyPlayer->getCharacter();
	else
		return nullptr;
}

std::shared_ptr<Player> MyPlayer::GetPlayer()
{
	MyPlayer* v_pMyPlayer = MyPlayer::GetInstance();
	if (v_pMyPlayer)
		return v_pMyPlayer->getPlayer();
	else
		return nullptr;
}

bool MyPlayer::IsPlayerLocal(Player* pPlayer)
{
	const auto v_pSelfPlayer = MyPlayer::GetPlayer();
	if (v_pSelfPlayer)
		return v_pSelfPlayer->getSteamId() == pPlayer->getSteamId();
	else
		return false;
}

SMSDK_END_NAMESPACE