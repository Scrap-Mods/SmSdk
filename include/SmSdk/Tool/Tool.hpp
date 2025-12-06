#pragma once

#include "SmSdk/Tool/IToolNetworkData.hpp"
#include "SmSdk/Tool/IToolImpl.hpp"

#include "SmSdk/Base/NetObj.hpp"

SMSDK_BEGIN_NAMESPACE

class Tool : public NetObj
{
public:
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ char uuid[16];
	/* 0x0040 */ std::int32_t m_iOwnerId;
private:
	/* 0x0044 */ char pad_0x44[0x4];
public:
	/* 0x0048 */ std::shared_ptr<IToolImpl> m_pImplementation;
	/* 0x0058 */ IToolNetworkData* m_pNetworkData;
	/* 0x0060 */ bool m_bMovementSlowDown;
private:
	/* 0x0061 */ char pad_0x61[0xF];

}; // Size: 0x70

static_assert(sizeof(Tool) == 0x70, "Tool: Incorrect Size");

SMSDK_END_NAMESPACE