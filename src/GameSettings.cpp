#include "SmSdk/GameSettings.hpp"

SMSDK_BEGIN_NAMESPACE

float GameSettings::getFloatSetting(
	const std::string_view& name,
	const float fDefaultValue) const
{
	const auto v_iter = m_mapFloatSettings.find(name);
	if (v_iter != m_mapFloatSettings.end())
		return v_iter->second;
	else
		return fDefaultValue;
}

std::int32_t GameSettings::getIntSetting(
	const std::string_view& name,
	const std::int32_t iDefaultValue) const
{
	const auto v_iter = m_mapIntSettings.find(name);
	if (v_iter != m_mapIntSettings.end())
		return v_iter->second;
	else
		return iDefaultValue;
}

std::string_view GameSettings::getStringSetting(
	const std::string_view& name,
	const std::string_view& defaultValue) const
{
	const auto v_iter = m_mapStringSettings.find(name);
	if (v_iter != m_mapStringSettings.end())
		return v_iter->second;
	else
		return defaultValue;
}

float GameSettings::GetEffectsVolume()
{
	GameSettings* v_pGameSettings = GameSettings::GetInstance();
	if (v_pGameSettings)
	{
		const float v_fMasterVolume = v_pGameSettings->getMasterVolume();
		const float v_fEffectVolume = v_pGameSettings->getEffectsVolumeRaw();

		return v_fEffectVolume * v_fMasterVolume;
	}
	else
	{
		return 1.0f;
	}
}

float GameSettings::GetMasterVolume()
{
	GameSettings* v_pGameSettings = GameSettings::GetInstance();
	if (v_pGameSettings)
		return v_pGameSettings->getMasterVolume();
	else
		return 1.0f;
}

SMSDK_END_NAMESPACE