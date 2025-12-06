#pragma once

#include <unordered_map>
#include <string>

SMSDK_BEGIN_NAMESPACE

class GameSettings
{
public:
	static GameSettings* GetInstance();

	inline float _getFloatSetting(const std::string& name, float fDefaultValue = 1.0f) const
	{
		auto iter = m_mapFloatSettings.find(name);
		if (iter != m_mapFloatSettings.end())
			return iter->second;

		return fDefaultValue;
	}

	inline float _getMasterVolume() const
	{
		return this->_getFloatSetting("MasterVolume", 1.0f);
	}

	inline static float GetEffectsVolume()
	{
		GameSettings* pGameSettings = GameSettings::GetInstance();
		if (!pGameSettings)
			return 1.0f;

		const float fMasterVolume = pGameSettings->_getMasterVolume();
		const float fEffectVolume = pGameSettings->_getFloatSetting("EffectVolume");

		return fEffectVolume * fMasterVolume;
	}

	inline static float GetMasterVolume()
	{
		GameSettings* pGameSettings = GameSettings::GetInstance();
		if (!pGameSettings)
			return 1.0f;

		return pGameSettings->_getFloatSetting("MasterVolume", 1.0f);
	}
public:
	/* 0x0000 */ std::unordered_map<std::string, int> m_mapIntSettings;
	/* 0x0040 */ std::unordered_map<std::string, float> m_mapFloatSettings;
	/* 0x0080 */ std::unordered_map<std::string, std::string> m_mapStringSettings;
	/* 0x00C0 */ std::int32_t m_appliedSettings;
private:
	/* 0x00C4 */ char pad_0xC4[0x4];
}; // Size: 0xC8

static_assert(offsetof(GameSettings, GameSettings::m_mapIntSettings) == 0x0, "GameSettings::m_mapIntSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapFloatSettings) == 0x40, "GameSettings::m_mapFloatSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapStringSettings) == 0x80, "GameSettings::m_mapStringSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_appliedSettings) == 0xC0, "GameSettings::m_appliedSettings: Incorrect offset");

static_assert(sizeof(GameSettings) == 0xC8, "GameSettings: Incorrect Size");

SMSDK_END_NAMESPACE