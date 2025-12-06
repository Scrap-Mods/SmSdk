#pragma once

#include <memory>
#include <string>

#include "SmSdk/boost_include.hpp"
#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct PlayerGarments
{
	/* 0x0000 */ bool m_bIsFemale;
	/* 0x0001 */ boost::uuids::uuid m_headUuid;
	/* 0x0011 */ boost::uuids::uuid m_hairUuid;
	/* 0x0021 */ boost::uuids::uuid m_facialHairUuid;
	/* 0x0031 */ boost::uuids::uuid m_torsoUuid;
	/* 0x0041 */ boost::uuids::uuid m_glovesUuid;
	/* 0x0051 */ boost::uuids::uuid m_shoesUuid;
	/* 0x0061 */ boost::uuids::uuid m_legsUuid;
	/* 0x0071 */ boost::uuids::uuid m_hatUuid;
	/* 0x0081 */ boost::uuids::uuid m_backpackUuid;
	/* 0x0091 */ char pad_0x91[0x3];
	/* 0x0094 */ std::int32_t m_headColor;
	/* 0x0098 */ std::int32_t m_hairColor;
	/* 0x009C */ std::int32_t m_facialHairColor;
	/* 0x00A0 */ std::int32_t m_torsoColor;
	/* 0x00A4 */ std::int32_t m_glovesColor;
	/* 0x00A8 */ std::int32_t m_shoesColor;
	/* 0x00AC */ std::int32_t m_legsColor;
	/* 0x00B0 */ std::int32_t m_hatColor;
	/* 0x00B4 */ std::int32_t m_backpackColor;
}; // Size: 0xB8

static_assert(sizeof(PlayerGarments) == 0xB8, "PlayerGarments: Incorrect Size");

struct PlayerScriptData
{
	/* 0x0000 */ bool m_bHasServerOnRefresh;
	/* 0x0001 */ bool m_bHasServerOnProjectile;
	/* 0x0002 */ bool m_bHasServerOnExplosion;
	/* 0x0003 */ bool m_bHasServerOnMelee;
	/* 0x0004 */ bool m_bHasServerOnCollision;
	/* 0x0005 */ bool m_bHasServerOnCollisionCrush;
	/* 0x0006 */ bool m_bHasServerOnShapeRemoved;
	/* 0x0007 */ bool m_bHasServerOnInventoryChanges;
}; // Size: 0x8

static_assert(sizeof(PlayerScriptData) == 0x8, "PlayerScriptData: Incorrect Size");

class Character;

class Player
{
public:
	Character* getCharacter() const;
	bool characterExists() const;

	/* 0x0000 */ std::shared_ptr<Player> m_pSelf;
	/* 0x0010 */ std::int32_t m_iId;
	/* 0x0014 */ std::int32_t m_iCharacterId;
	/* 0x0018 */ std::int16_t m_worldId;
private:
	/* 0x001A */ char pad_0x1A[0x2];
public:
	/* 0x001C */ DirectX::XMFLOAT3 m_characterPosition;
	/* 0x0028 */ DirectX::XMFLOAT3 m_characterVelocity;
	/* 0x0034 */ float m_fCharacterYaw;
	/* 0x0038 */ float m_fCharacterPitch;
private:
	/* 0x003C */ char pad_0x3C[0x4];
public:
	/* 0x0040 */ std::int64_t m_steamId;
	/* 0x0048 */ std::string m_name;
private:
	/* 0x0068 */ char pad_0x68[0x4];
public:
	/* 0x006C */ PlayerGarments m_garments;
	/* 0x0124 */ std::int32_t m_iGarmentChangeCounter;
private:
	/* 0x0128 */ char pad_0x128[0x10];
public:
	/* 0x0138 */ std::int32_t m_scriptRef;
	/* 0x013C */ PlayerScriptData m_scriptData;
private:
	/* 0x0144 */ char pad_0x144[0xC];

}; // Size: 0x150

static_assert(sizeof(Player) == 0x150, "Player: Incorrect Size");

SMSDK_END_NAMESPACE