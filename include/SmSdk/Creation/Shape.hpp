#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Util/Color.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

class Shape
{
private:
	virtual void func1() {}
	virtual void func2() {}
public:
	virtual uint32_t getCollisionShapeType() { return 0; }
private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ boost::uuids::uuid m_shapeUuid;
	/* 0x0020 */ std::int32_t m_iShapeType;
	/* 0x0024 */ Color m_shapeColor;
private:
	/* 0x0028 */ char pad_0x28[0x4];
public:
	/* 0x002C */ DirectX::XMFLOAT3 m_shapeSize;
private:
	/* 0x0038 */ char pad_0x38[0x28];
}; // Size: 0x60

static_assert(sizeof(Shape) == 0x60, "Shape: Incorrect Size");

SMSDK_END_NAMESPACE