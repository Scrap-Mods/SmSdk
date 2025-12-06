#pragma once

#include "SmSdk/fmod_include.hpp"
#include "SmSdk/Base/Task.hpp"

#include <memory>
#include <string>
#include <mutex>
#include <deque>
#include <map>

SMSDK_BEGIN_NAMESPACE

struct EventData
{
	/* 0x0000 */ std::int16_t m_iWorldId;
private:
	/* 0x0002 */ char pad_0x2[0x2];
public:
	/* 0x0004 */ std::int32_t m_iSomeVal;
private:
	/* 0x0008 */ char pad_0x8[0x18];
public:
	/* 0x0020 */ std::string m_eventName;
	/* 0x0040 */ std::map<std::string, float> m_mapTemporary;
	/* 0x0050 */ std::shared_ptr<struct AudioEvent> m_pAudioEvent;
}; // Size: 0x60

static_assert(sizeof(EventData) == 0x60, "EventData: Incorrect Size");

class AudioManager : public Task
{
public:
	static AudioManager* GetInstance();

	inline void _playSound(const std::string& soundName, uint16_t uWorldId = 0xFFFF)
	{
		std::lock_guard<std::mutex> lock(m_mutex);

		EventData newEvent;
		newEvent.m_iWorldId = uWorldId;
		newEvent.m_iSomeVal = 1;
		newEvent.m_eventName = soundName;

		m_deqEventQueue.push_back(newEvent);
	}

	inline static void PlaySound(const std::string& soundName, uint16_t uWorldId = 0xFFFF)
	{
		AudioManager* pAudioMgr = AudioManager::GetInstance();
		if (!pAudioMgr)
			return;

		pAudioMgr->_playSound(soundName, uWorldId);
	}

	/* 0x0008 */ std::shared_ptr<struct AudioEventManager> pAudioEventManager;
	/* 0x0018 */ std::mutex m_mutex;
	/* 0x0068 */ FMOD::Studio::System* m_pFmodStudioSystem;
	/* 0x0070 */ FMOD::System* m_pFmodSystem;
	/* 0x0078 */ FMOD_ADVANCEDSETTINGS m_fmodAdvancedSettings;
	/* 0x00E0 */ float m_fMasterVolume;
	/* 0x00E4 */ float m_fOldMasterVolume;
private:
	/* 0x00E8 */ char pad_0xE8[0x10];
public:
	/* 0x00F8 */ std::deque<EventData> m_deqEventQueue;
private:
	/* 0x0120 */ char pad_0x120[0x78];
public:
	/* 0x0198 */ std::map<std::string, std::string> m_mapNameToFmodPath;
	/* 0x01A8 */ std::map<size_t, std::string> m_someHashToFmodPath;
	/* 0x01B8 */ std::map<std::string, std::shared_ptr<struct AudioEvent>> m_nameToEventPtr;
private:
	/* 0x01C8 */ char pad_0x1C8[0x100];
public:
	/* 0x02C8 */ std::int32_t m_iFmodInitFlags;
private:
	/* 0x02CC */ char pad_0x2CC[0xC];
}; // Size: 0x2D8

static_assert(sizeof(AudioManager) == 0x2D8, "AudioManager: Incorrect Size");

SMSDK_END_NAMESPACE