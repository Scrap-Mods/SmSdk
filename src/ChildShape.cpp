#include "SmSdk/Creation/ChildShape.hpp"

SMSDK_BEGIN_NAMESPACE

std::uint32_t ChildShape::getCurrentIdx() const
{
	return m_uCurrentIdx;
}

Color ChildShape::getColor() const
{
	return m_pShape->m_shapeColor;
}

void ChildShape::setColor(const Color newColor)
{
	if (m_pShape->m_shapeColor == newColor)
		return;

	m_pShape->m_shapeColor = newColor;
	this->updateObject();
}

SMSDK_END_NAMESPACE