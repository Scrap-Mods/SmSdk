#include "SmSdk/Tool/Tool.hpp"

SMSDK_BEGIN_NAMESPACE

boost::uuids::uuid Tool::getUuid() const
{
	return m_uuid;
}

std::uint32_t Tool::getOwnerId() const
{
	return m_uOwnerId;
}

bool Tool::getMovementSlowdown() const
{
	return m_bMovementSlowDown;
}

void Tool::setMovementSlowdown(const bool value)
{
	m_bMovementSlowDown = value;
}

SMSDK_END_NAMESPACE