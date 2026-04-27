#include "SmSdk/AudioManager.hpp"

SMSDK_BEGIN_NAMESPACE

EventData::EventData(
	const std::uint16_t worldId,
	const std::string_view& eventName
)
	: m_iWorldId(worldId)
	, m_iSomeVal(1)
	, m_eventName(eventName)
	, m_mapTemporary()
	, m_pAudioEvent()
{}

void AudioManager::_playSound(
	const std::string& soundName,
	const std::uint16_t uWorldId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_deqEventQueue.emplace_back(uWorldId, soundName);
}

void AudioManager::PlaySound(
	const std::string& soundName,
	const std::uint16_t uWorldId)
{
	AudioManager* v_pAudioMgr = AudioManager::GetInstance();
	if (v_pAudioMgr)
		v_pAudioMgr->_playSound(soundName, uWorldId);
}

SMSDK_END_NAMESPACE