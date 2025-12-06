#pragma once

#include "SmSdk/config.hpp"
#include "SmSdk/Harvestable/Harvestable.hpp"

#include <unordered_map>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class HarvestableManager
{
	REMOVE_COPY_CONSTRUCTORS(HarvestableManager);
public:
	virtual ~HarvestableManager() = default;

	static HarvestableManager* GetInstance();

	inline Harvestable* _getHarvestable(int iHarvestableIdx)
	{
		auto iter = this->m_mapHarvestables.find(iHarvestableIdx);
		if (iter == this->m_mapHarvestables.end())
			return nullptr;

		return iter->second.get();
	}

	inline static Harvestable* GetHarvestable(int iHarvestableIdx)
	{
		HarvestableManager* pHarvestableManager = HarvestableManager::GetInstance();
		if (!pHarvestableManager)
			return nullptr;

		return pHarvestableManager->_getHarvestable(iHarvestableIdx);
	}
private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ std::unordered_map<int, std::shared_ptr<Harvestable>> m_mapHarvestables;
private:
	/* 0x0050 */ char pad_0x50[0x50];
public:
	/* 0x00A0 */ std::unordered_map<int, struct HarvestableCollision> m_mapHarvestableCollisions;
	/* 0x00E0 */ std::unordered_map<boost::uuids::uuid, std::shared_ptr<struct HarvestableData>> m_mapHarvestableData;
	/* 0x0120 */ std::shared_ptr<struct HarvestableData> m_pHarvestableData;
private:
	/* 0x0130 */ char pad_0x130[0x70];
}; // Size: 0x1A0

static_assert(sizeof(HarvestableManager) == 0x1A0, "HarvestableManager: Incorrect Size");

SMSDK_END_NAMESPACE