#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"

SMSDK_BEGIN_NAMESPACE

class HarvestablePhysicsProxy : public PhysicsProxy
{
public:
	/* 0x0030 */ std::int32_t m_iHarvestableId;
private:
	/* 0x0034 */ char pad_0x34[0x8C];
}; // Size: 0xC0

static_assert(sizeof(HarvestablePhysicsProxy) == 0xC0, "HarvestablePhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE