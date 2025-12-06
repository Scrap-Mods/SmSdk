#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "Shape.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

class RigidBody;

class ChildShape : public NetObj
{
public:
	inline Color getColor() const
	{
		return m_pShape->m_shapeColor;
	}

	// SERVER ONLY
	inline void setColor(Color newColor)
	{
		if (m_pShape->m_shapeColor == newColor)
			return;

		m_pShape->m_shapeColor = newColor;
		this->updateObject();
	}
private:
	/* 0x0028 */ char pad_0x0028[0x30];
public:
	/* 0x0058 */ std::shared_ptr<Shape> m_pShape;
private:
	/* 0x0068 */ char pad_0x0068[0x8];
public:
	/* 0x0070 */ std::int32_t m_iCurrentIdx;
private:
	/* 0x0074 */ char pad_0x0074[0xC];
public:
	/* 0x0080 */ std::shared_ptr<RigidBody> m_pParentBody;
	/* 0x0090 */ std::shared_ptr<class ControllerBase> m_pController;
private:
	/* 0x00A0 */ char pad_0x00A0[0x30];
}; // Size: 0x00D0

static_assert(sizeof(ChildShape) == 0xD0, "ChildShape: Incorrect Size");

SMSDK_END_NAMESPACE