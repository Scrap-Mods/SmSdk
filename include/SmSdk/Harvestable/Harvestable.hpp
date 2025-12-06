#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Base/NetObj.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct Harvestable : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ bool m_bPoseWeightUpdateFlag;
	/* 0x0031 */ bool m_bColorUpdateFlag;
	/* 0x0032 */ bool m_bUVUpdateFlag;
	/* 0x0033 */ bool m_bTransformUpdateFlag;
private:
	/* 0x0034 */ char pad_0x34[0x4];
public:
	/* 0x0038 */ std::shared_ptr<struct HarvestableData> m_pHarvestableData;
	/* 0x0048 */ std::int16_t m_iWorldId;
	/* 0x004A */ boost::uuids::uuid m_uuid;
private:
	/* 0x005A */ char pad_0x5A[0x1E];
public:
	/* 0x0078 */ DirectX::XMFLOAT3 m_position;
	/* 0x0084 */ DirectX::XMFLOAT4 m_rotation;
	/* 0x0094 */ DirectX::XMFLOAT3 m_scale;
private:
	/* 0x00A0 */ char pad_0xA0[0x4];
public:
	/* 0x00A4 */ bool m_bKinematic;
private:
	/* 0x00A5 */ char pad_0xA5[0x12B];
public:
	/* 0x01D0 */ float m_fPoseWeights[3];
private:
	/* 0x01DC */ char pad_0x1DC[0xC];
public:
	/* 0x01E8 */ DirectX::XMFLOAT4 m_color;
	/* 0x01F8 */ std::int8_t m_iUVFrameIndex;
private:
	/* 0x01F9 */ char pad_0x1F9[0x37];
}; // Size: 0x230

static_assert(sizeof(Harvestable) == 0x230, "Harvestable: Incorrect Size");

SMSDK_END_NAMESPACE