#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/config.hpp"

#include "SmSdk/Character.hpp"

#include <unordered_map>
#include <vector>
#include <memory>
#include <map>

SMSDK_BEGIN_NAMESPACE

class CharacterManager
{
	REMOVE_COPY_CONSTRUCTORS(CharacterManager);
public:
	virtual ~CharacterManager() = default;

	static CharacterManager* GetInstance();

	inline Character* _getCharacter(int iCharId)
	{
		auto iter = m_mapCharacterState.find(iCharId);
		if (iter == m_mapCharacterState.end())
			return nullptr;

		return iter->second.get();
	}

	inline static Character* GetCharacter(int iCharId)
	{
		CharacterManager* pCharacterManager = CharacterManager::GetInstance();
		if (!pCharacterManager)
			return nullptr;

		return pCharacterManager->_getCharacter(iCharId);
	}

	/* 0x0008 */ std::unordered_map<int, std::shared_ptr<Character>> m_mapCharacterState;
	/* 0x0048 */ std::unordered_map<int, std::shared_ptr<struct Lift>> m_worldLiftMap;
private:
	/* 0x0088 */ std::int32_t m_iSomeId;
public:
	/* 0x008C */ std::int32_t m_iTick;
	/* 0x0090 */ std::map<boost::uuids::uuid, struct CharacterData> m_mapCharacterData;
	/* 0x00A0 */ std::vector<std::shared_ptr<Character>> m_vecCharacters;
}; // Size: 0xB8

static_assert(sizeof(CharacterManager) == 0xB8, "CharacterManager: Incorrect Size");

SMSDK_END_NAMESPACE