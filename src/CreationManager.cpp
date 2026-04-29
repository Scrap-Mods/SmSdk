#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

BodyState* CreationManager::getBodyState(const std::uint32_t uId)
{
	auto v_iter = m_mapBodyStates.find(uId);
	if (v_iter != m_mapBodyStates.end())
		return &v_iter->second;
	else
		return nullptr;
}

JointState* CreationManager::getJointState(const std::uint32_t uId)
{
	auto v_iter = m_mapJointStates.find(uId);
	if (v_iter == m_mapJointStates.end())
		return &v_iter->second;
	else
		return nullptr;
}

BodyState* CreationManager::GetBodyState(const std::uint32_t uId)
{
	CreationManager* v_pCreationMgr = CreationManager::GetInstance();
	if (v_pCreationMgr)
		return v_pCreationMgr->getBodyState(uId);
	else
		return nullptr;
}

JointState* CreationManager::GetJointState(const std::uint32_t uId)
{
	CreationManager* v_pCreationMgr = CreationManager::GetInstance();
	if (v_pCreationMgr)
		return v_pCreationMgr->getJointState(uId);
	else
		return nullptr;
}

SMSDK_END_NAMESPACE