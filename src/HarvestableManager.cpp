#include "SmSdk/Harvestable/HarvestableManager.hpp"

SMSDK_BEGIN_NAMESPACE

Harvestable* HarvestableManager::getHarvestable(const std::uint32_t uHvsIdx)
{
	auto v_iter = m_mapHarvestables.find(uHvsIdx);
	if (v_iter != m_mapHarvestables.end())
		return v_iter->second.get();
	else
		return nullptr;
}

Harvestable* HarvestableManager::GetHarvestable(const std::uint32_t uHvsIdx)
{
	HarvestableManager* v_pHvsMgr = HarvestableManager::GetInstance();
	if (v_pHvsMgr)
		return v_pHvsMgr->getHarvestable(uHvsIdx);
	else
		return nullptr;
}

SMSDK_END_NAMESPACE