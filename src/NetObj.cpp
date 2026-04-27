#include "SmSdk/Base/NetObj.hpp"

SMSDK_BEGIN_NAMESPACE

std::uint32_t NetObj::getId() const
{
    return m_uId;
}

std::uint32_t NetObj::getRevision() const
{
    return m_uRevision;
}

SMSDK_END_NAMESPACE