#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/Task.hpp"

SMSDK_BEGIN_NAMESPACE

struct PhysicsBase : public Task
{
private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ struct World* m_pWorld;
private:
	/* 0x0018 */ char pad_0x18[0x48];
public:
	/* 0x0060 */ btNullPairCache* m_pNullPairCache;
private:
	/* 0x0068 */ char pad_0x68[0x8];
public:
	/* 0x0070 */ struct ParallelDispatcher* m_pParallelDispatcher;
private:
	/* 0x0078 */ char pad_0x78[0x8];
public:
	/* 0x0080 */ struct SolverPool* m_pSolverPool;
	/* 0x0088 */ struct TickDynamicsWorld* m_pTickDynamicsWorld;
	/* 0x0090 */ btGhostPairCallback* m_pGhostPairCallback;
private:
	/* 0x0098 */ char pad_0x98[0xD8];
public:
	/* 0x0170 */ btCollisionWorld* m_pCollisionWorld2;
private:
	/* 0x0178 */ char pad_0x178[0x18];
public:
	/* 0x0190 */ btCollisionWorld* m_pCollisionWorld;
private:
	/* 0x0198 */ char pad_0x198[0x1A8];

}; // Size: 0x340

static_assert(sizeof(PhysicsBase) == 0x340, "PhysicsBase: Incorrect Size");

enum PhysicsFilterMask
{
	PhysicsFilterMask_DynamicBody = 1,
	PhysicsFilterMask_StaticBody = 2,
	PhysicsFilterMask_Character = 4,
	PhysicsFilterMask_AreaTrigger = 8,
	PhysicsFilterMask_TerrainSurface = 128,
	PhysicsFilterMask_TerrainAsset = 256,
	PhysicsFilterMask_Harvestable = 512,
	PhysicsFilterMask_Lifts = 1024,
	PhysicsFilterMask_Joints = 4096,
	PhysicsFilterMask_VoxelTerrain = 32768
};

class Physics
{
public:
	static Physics* GetInstance();

	/* 0x0000 */ PhysicsBase* m_pPhysicsBase;
	/* 0x0008 */ btNullPairCache* m_pNullPairCache;
	/* 0x0010 */ char pad_0x10[0x10];
	/* 0x0020 */ btCollisionDispatcher* m_pDispatcher;
	/* 0x0028 */ btCollisionWorld* m_pCollisionWorld;
}; // Size: 0x30

static_assert(sizeof(Physics) == 0x30, "Physics: Incorrect Size");

SMSDK_END_NAMESPACE