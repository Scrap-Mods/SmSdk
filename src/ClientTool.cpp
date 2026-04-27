#include "SmSdk/Tool/ClientTool.hpp"

SMSDK_BEGIN_NAMESPACE

ToolAnimationEntry::ToolAnimationEntry(
	const std::string_view& animName,
	const std::string_view& nextAnim,
	const float animBegin,
	const float animEnd,
	const float animTime,
	const float animWeight,
	const float animSpeed,
	const std::uint32_t animFlags
)
	: m_animName(animName)
	, m_nextAnim(nextAnim)
	, m_fAnimBegin(animBegin)
	, m_fAnimEnd(animEnd)
	, m_fAnimTime(animTime)
	, m_fWeight(animWeight)
	, m_fPlaybackSpeed(animSpeed)
	, m_uFlags(animFlags)
{}

//////////////////// TOOL ANIMATION DATA ////////////////

void ToolAnimationData::setAnimation(const std::string_view& name)
{
	auto v_iter = m_mapAnimationData.find(name);
	if (v_iter == m_mapAnimationData.end())
		return;

	m_currentAnim = name;
	m_fAnimBegin = 0.2f;

	v_iter->second.m_fAnimTime = 0.0f;
}

bool ToolAnimationData::hasAnimation(const std::string_view& name) const
{
	return m_mapAnimationData.find(name) != m_mapAnimationData.end();
}

void ToolAnimationData::resetAnimation(const std::string_view& name)
{
	auto v_iter = m_mapAnimationData.find(name);
	if (v_iter == m_mapAnimationData.end())
		return;

	v_iter->second.m_fAnimTime = 0.0f;
	v_iter->second.m_fWeight = 0.0f;
}

void ToolAnimationData::addNewAnimation(
	const std::string_view& name,
	const std::string_view& startAnim,
	const std::string_view& nextAnim,
	const float animBegin,
	const float animEnd,
	const float playbackSpeed,
	const std::uint32_t flags)
{
	m_mapAnimationData.emplace(
		std::piecewise_construct,
		std::forward_as_tuple(name),
		std::forward_as_tuple(
			startAnim,
			nextAnim,
			animBegin,
			animEnd,
			0.0f,
			0.0f,
			playbackSpeed,
			flags
		)
	);
}

void ToolAnimationData::removeAnimation(const std::string_view& name)
{
	auto v_iter = m_mapAnimationData.find(name);
	if (v_iter != m_mapAnimationData.end())
		m_mapAnimationData.erase(v_iter);
}

///////////////// CLIENT TOOL /////////////////////

void ClientTool::setTpAnimation(const std::string_view& name)
{
	m_tpAnims.setAnimation(name);
}

void ClientTool::setFpAnimation(const std::string_view& name)
{
	m_fpAnims.setAnimation(name);
}

void ClientTool::setFpAndTpAnimation(const std::string_view& name)
{
	this->setFpAnimation(name);
	this->setTpAnimation(name);
}

bool ClientTool::getBlockSprint() const
{
	return m_blockSprint;
}

void ClientTool::setBlockSprint(const bool value)
{
	m_blockSprint = value;
}

bool ClientTool::getInteractionTextSuppressed() const
{
	return m_interactionTextSuppressed;
}

void ClientTool::setInteractionTextSuppressed(const bool value)
{
	m_interactionTextSuppressed = value; 
}

float ClientTool::getDispersionFraction() const
{
	return m_fDispersionFraction;
}

void ClientTool::setDispersionFraction(const float value)
{
	m_fDispersionFraction = value;
}

float ClientTool::getCrosshairAlpha() const
{
	return m_fCrosshairAlpha;
}

void ClientTool::setCrosshairAlpha(const float value)
{
	m_fCrosshairAlpha = value;
}

SMSDK_END_NAMESPACE