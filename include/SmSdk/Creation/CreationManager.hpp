#pragma once

#include "SmSdk/Creation/JointPhysicsProxy.hpp"
#include "SmSdk/Creation/RigidBody.hpp"
#include "SmSdk/Creation/Joint.hpp"
#include "SmSdk/config.hpp"

#include <unordered_map>
#include <memory>
#include <string>

SMSDK_BEGIN_NAMESPACE

struct BodyStructure
{
	std::shared_ptr<RigidBody> m_pBody;
	std::shared_ptr<struct BodyPhysicsProxy> m_pPhysicsProxy;
};

struct JointStructure
{
	std::shared_ptr<Joint> m_pJoint;
	std::shared_ptr<JointPhysicsProxy> m_pPhysicsProxy;
};

class CreationManager
{
	REMOVE_COPY_CONSTRUCTORS(CreationManager);
public:
	virtual ~CreationManager() = default;

	static CreationManager* GetInstance();

	BodyStructure* _getBodyData(int iId);
	JointStructure* _getJointData(int iId);

	static BodyStructure* GetBodyData(int iId);
	static JointStructure* GetJointData(int iId);

	std::unordered_map<int, BodyStructure> m_mapBodies;
	std::unordered_map<int, std::shared_ptr<ChildShape>> m_mapChildShapes;
	std::unordered_map<int, JointStructure> m_mapJoints;
	std::unordered_map<int, std::shared_ptr<struct ControllerEntry>> m_mapInteractiveParts;
	std::unordered_map<int, struct CreationEntry> m_mapCreations;
};

SMSDK_END_NAMESPACE