#include "SmSdk/Creation/RigidBody.hpp"

SMSDK_BEGIN_NAMESPACE

ChildShape* RigidBody::getChildShape(const std::size_t uChildId)
{
    if (uChildId >= m_vecChildShapes.size())
        return nullptr;

    return m_vecChildShapes[uChildId].get();
}

SMSDK_END_NAMESPACE