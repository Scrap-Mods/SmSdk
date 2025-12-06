#pragma once

#include "SmSdk/Tool/IToolImpl.hpp"
#include "SmSdk/Tool/Tool.hpp"

#include <unordered_map>
#include <string>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class ClientTool;

enum AnimationFlag : uint32_t
{
	AnimationFlag_None = 0,
	AnimationFlag_Repeat = 1
};

struct ToolAnimationEntry
{
	/* 0x0000 */ std::string m_animName;
	/* 0x0020 */ std::string m_nextAnim;
	/* 0x0040 */ float m_fAnimBegin;
	/* 0x0044 */ float m_fAnimEnd;
	/* 0x0048 */ float m_fAnimTime;
	/* 0x004C */ float m_fWeight;
	/* 0x0050 */ float m_fPlaybackSpeed;
	/* 0x0054 */ uint32_t m_uFlags;

}; // Size: 0x58

static_assert(sizeof(ToolAnimationEntry) == 0x58, "ToolAnimationEntry: Incorrect Size");

struct ToolAnimationList
{
	/* 0x0000 */ std::string m_toolIdle;
	/* 0x0020 */ std::string m_toolIdleRelaxed;
	/* 0x0040 */ std::string m_toolRunFwd;
	/* 0x0060 */ std::string m_toolRunBwd;
	/* 0x0080 */ std::string m_toolSprint;
	/* 0x00A0 */ std::string m_toolJump;
	/* 0x00C0 */ std::string m_toolJumpUp;
	/* 0x00E0 */ std::string m_toolJumpDown;
	/* 0x0100 */ std::string m_toolJumpLand;
	/* 0x0120 */ std::string m_toolJumpLandFwd;
	/* 0x0140 */ std::string m_toolJumpLandBwd;
	/* 0x0160 */ std::string m_toolCrouchIdle;
	/* 0x0180 */ std::string m_toolCrouchFwd;
	/* 0x01A0 */ std::string m_toolCrouchBwd;
private:
	/* 0x01C0 */ std::string m_someString1;
	/* 0x01E0 */ std::string m_someString2;
	/* 0x0200 */ std::string m_someString3;
}; // Size: 0x220

static_assert(sizeof(ToolAnimationList) == 0x220, "ToolAnimationList: Incorrect Size");

struct ToolAnimationData
{
	void setAnimation(const std::string& name)
	{
		auto iter = this->m_mapAnimationData.find(name);
		if (iter == this->m_mapAnimationData.end())
			return;

		this->m_currentAnim = name;
		iter->second.m_fAnimTime = 0.0f;
		this->m_fAnimBegin = 0.2f;
	}

	bool hasAnimation(const std::string& name) const
	{
		return this->m_mapAnimationData.find(name) != this->m_mapAnimationData.end();
	}

	void resetAnimation(const std::string& name)
	{
		auto iter = this->m_mapAnimationData.find(name);
		if (iter == this->m_mapAnimationData.end())
			return;

		iter->second.m_fAnimTime = 0.0f;
		iter->second.m_fWeight = 0.0f;
	}

	void addNewAnimation(
	    const std::string& name,
	    const std::string& startAnim,
	    const std::string& nextAnim,
	    float animBegin = 0.0f,
	    float animEnd = 1.0f,
	    float playbackSpeed = 1.0f,
	    uint32_t flags = 256)
	{
		ToolAnimationEntry newEntry;
		newEntry.m_animName = startAnim;
		newEntry.m_nextAnim = nextAnim;
		newEntry.m_fAnimTime = 0.0f;
		newEntry.m_fAnimBegin = animBegin;
		newEntry.m_fAnimEnd = animEnd;
		newEntry.m_fWeight = 0.0f;
		newEntry.m_fPlaybackSpeed = playbackSpeed;
		newEntry.m_uFlags = flags;

		this->m_mapAnimationData.emplace(name, newEntry);
	}

	void removeAnimation(const std::string& name)
	{
		auto iter = this->m_mapAnimationData.find(name);
		if (iter != this->m_mapAnimationData.end())
			this->m_mapAnimationData.erase(iter);
	}

	/* 0x0000 */ ClientTool* m_pToolPtr;
	/* 0x0008 */ std::unordered_map<std::string, ToolAnimationEntry> m_mapAnimationData;
	/* 0x0048 */ std::string m_currentAnim;
	/* 0x0068 */ ToolAnimationList m_toolAnimList;
	/* 0x0288 */ float m_fAnimBegin;
private:
	/* 0x028C */ char pad_0x28C[0x4];

}; // Size: 0x290

static_assert(sizeof(ToolAnimationData) == 0x290, "ToolAnimationData: Incorrect Size");

class ClientTool : public IToolImpl
{
public:
	inline void setTpAnimation(const std::string& name)
	{
		m_tpAnims.setAnimation(name);
	}

	inline void setFpAnimation(const std::string& name)
	{
		m_fpAnims.setAnimation(name);
	}

	inline void setFpAndTpAnimation(const std::string& name)
	{
		this->setFpAnimation(name);
		this->setTpAnimation(name);
	}

	/* 0x0008 */ ToolAnimationData m_tpAnims;
	/* 0x0298 */ ToolAnimationData m_fpAnims;
	/* 0x0528 */ std::shared_ptr<Tool> m_pTool;
	/* 0x0538 */ bool m_blockSprint;
private:
	/* 0x0539 */ char pad_0x539[0x3];
public:
	/* 0x053C */ float m_fDispersionFraction;
	/* 0x0540 */ float m_fCrosshairAlpha;
	/* 0x0544 */ bool m_fInteractionTextSuppressed;
private:
	/* 0x0545 */ char pad_0x545[0x3];
}; // Size: 0x548

static_assert(sizeof(ClientTool) == 0x548, "ClientTool: Incorrect Size");

SMSDK_END_NAMESPACE