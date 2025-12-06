#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct CharacterPhysicsProxy : public PhysicsProxy
{
private:
	/* 0x0030 */ char pad_0x30[0x8];
public:
	/* 0x0038 */ struct CharacterController* m_pController;
private:
	/* 0x0040 */ char pad_0x40[0x38];
public:
	/* 0x0078 */ btCollisionObject* m_pCollisionObj2;
	/* 0x0080 */ btCollisionObject* m_pCollisionObj3;
private:
	/* 0x0088 */ char pad_0x88[0x8];
public:
	/* 0x0090 */ DirectX::XMFLOAT3 m_position;
private:
	/* 0x009C */ char pad_0x9C[0x34];
}; // Size: 0xD0

static_assert(sizeof(CharacterPhysicsProxy) == 0xD0, "CharacterPhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE