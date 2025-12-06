#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/Creation/ChildShape.hpp"

#include <memory>
#include <list>
#include <string>
#include <map>

SMSDK_BEGIN_NAMESPACE

enum ControllerType : uint32_t
{
	ControllerType_Null = 0x0,
	ControllerType_ElectricMotor = 0x1,
	ControllerType_MotorController = 0x2,
	ControllerType_SteeringController = 0x3,
	ControllerType_SeatController = 0x4,
	ControllerType_SequenceController = 0x5,
	ControllerType_ButtonController = 0x6,
	ControllerType_LeverController = 0x7,
	ControllerType_SensorController = 0x8,
	ControllerType_ThrusterController = 0x9,
	ControllerType_RadioController = 0xA,
	ControllerType_HornController = 0xB,
	ControllerType_ToneController = 0xC,
	ControllerType_LogicController = 0xD,
	ControllerType_TimerController = 0xE,
	ControllerType_ParticlePreviewController = 0xF,
	ControllerType_SpringController = 0x10,
	ControllerType_SpotLightController = 0x11,
	ControllerType_ChestController = 0x13,
	ControllerType_ItemStackController = 0x14,
	ControllerType_ScriptController = 0x15,
	ControllerType_COUNT = 0x1F,
};

class ControllerBase : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x10];
public:
	/* 0x0038 */ ControllerType m_controllerType;
private:
	/* 0x003C */ char pad_0x3C[0xC];
public:
	/* 0x0048 */ std::shared_ptr<ChildShape> m_pParentShape;
private:
	/* 0x0058 */ char pad_0x58[0x10];
public:
	/* 0x0068 */ std::int32_t m_iMaxParentCount;
private:
	/* 0x006C */ char pad_0x6C[0x14];
public:
	/* 0x0080 */ std::shared_ptr<class GuiInterface> m_pGuiInterface;
	/* 0x0090 */ std::list<std::shared_ptr<ControllerBase>> m_listParents;
	/* 0x00A0 */ std::list<std::shared_ptr<class Controller>> m_listChildControllers;
	/* 0x00B0 */ std::list<std::shared_ptr<class Joint>> m_listChildJoints;
	/* 0x00C0 */ std::map<std::string, class ControllerBoneData> m_mapAnimatedBones;
	/* 0x00D0 */ bool m_bUpdateFlag;
private:
	/* 0x00D1 */ char pad_0xD1[0xF];
}; // Size: 0xE0

static_assert(sizeof(ControllerBase) == 0xE0, "ControllerBase: Incorrect Size");

SMSDK_END_NAMESPACE