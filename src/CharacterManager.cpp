#include "SmSdk/Character/CharacterManager.hpp"

SMSDK_BEGIN_NAMESPACE

std::shared_ptr<Character> CharacterManager::getCharacter(const std::uint32_t uCharId)
{
	const auto v_iter = m_mapCharacterState.find(uCharId);
	if (v_iter != m_mapCharacterState.end())
		return v_iter->second;
	else
		return nullptr;
}

std::span<std::shared_ptr<Character>> CharacterManager::getAllCharacters()
{
	return std::span<std::shared_ptr<Character>>(m_vecCharacters.begin(), m_vecCharacters.end());
}

std::shared_ptr<Character> CharacterManager::GetCharacter(const std::uint32_t uCharId)
{
	CharacterManager* v_pCharMgr = CharacterManager::GetInstance();
	if (v_pCharMgr)
		return v_pCharMgr->getCharacter(uCharId);
	else
		return nullptr;
}

std::span<std::shared_ptr<Character>> CharacterManager::GetAllCharacters()
{
	CharacterManager* v_pCharMgr = CharacterManager::GetInstance();
	if (v_pCharMgr)
		return v_pCharMgr->getAllCharacters();
	else
		return {};
}

//
// CHARACTER MANAGER CLIENT
//

std::shared_ptr<CharacterGraphics> CharacterManagerClient::getCharacterGraphics(const std::uint32_t uCharId)
{
	const auto v_iter = m_mapCharacterGraphics.find(uCharId);
	if (v_iter != m_mapCharacterGraphics.end())
		return v_iter->second.m_pCharacterGfx;
	else
		return nullptr;
}

std::shared_ptr<CharacterGraphics> CharacterManagerClient::GetCharacterGraphics(const std::uint32_t uCharId)
{
	CharacterManagerClient* v_pCharMgr = CharacterManagerClient::GetInstance();
	if (v_pCharMgr)
		return v_pCharMgr->getCharacterGraphics(uCharId);
	else
		return nullptr;
}

SMSDK_END_NAMESPACE