#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/NetObj.hpp"

#include "SmSdk/Creation/ChildShape.hpp"
#include "SmSdk/Creation/Joint.hpp"

#include <unordered_set>
#include <vector>

SMSDK_BEGIN_NAMESPACE

class RigidBody : public NetObj
{
public:
	inline ChildShape* getChildShape(int iChildId)
	{
		if (iChildId < 0 || iChildId >= m_vecChildShapes.size())
			return nullptr;

		return m_vecChildShapes[iChildId].get();
	}
private:
	/* 0x0028 */ char pad_0x28[0xC];
public:
	/* 0x0034 */ std::int16_t m_iWorldId;
private:
	/* 0x0036 */ char pad_0x36[0xA];
public:
	/* 0x0040 */ DirectX::XMMATRIX m_transform;
private:
	/* 0x0080 */ char pad_0x80[0x8];
public:
	/* 0x0088 */ std::shared_ptr<struct ShapeGridData> m_pShapeGridData;
	/* 0x0098 */ DirectX::XMFLOAT3 m_localAabbMin;
	/* 0x00A4 */ DirectX::XMFLOAT3 m_localAabbMax;
private:
	/* 0x00B0 */ char pad_0xB0[0x20];
public:
	/* 0x00D0 */ btCompoundShape m_compoundShape;
	/* 0x0150 */ std::vector<std::shared_ptr<ChildShape>> m_vecChildShapes;
private:
	/* 0x0168 */ char pad_0x168[0x18];
public:
	/* 0x0180 */ std::unordered_set<std::shared_ptr<Joint>> m_setJointStorage;
private:
	/* 0x01C0 */ char pad_0x1C0[0x10];
}; // Size: 0x1D0

static_assert(sizeof(RigidBody) == 0x1D0, "RigidBody: Incorrect Size");

SMSDK_END_NAMESPACE