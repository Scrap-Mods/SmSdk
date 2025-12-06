#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

BodyStructure* CreationManager::_getBodyData(int iId)
{
	auto iter = m_mapBodies.find(iId);
	if (iter == m_mapBodies.end())
		return nullptr;

	return &iter->second;
}

JointStructure* CreationManager::_getJointData(int iId)
{
	auto iter = m_mapJoints.find(iId);
	if (iter == m_mapJoints.end())
		return nullptr;

	return &iter->second;
}

BodyStructure* CreationManager::GetBodyData(int iId)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getBodyData(iId);
}

JointStructure* CreationManager::GetJointData(int iId)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getJointData(iId);
}