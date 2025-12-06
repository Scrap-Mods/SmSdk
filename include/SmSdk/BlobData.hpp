#pragma once

#include "SmSdk/boost_include.hpp"

#include <cstdint>
#include <cstddef>

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

struct BlobDataKey
{
public:
	/* 0x0000 */ boost::uuids::uuid m_uuid;
	/* 0x0010 */ uint8_t m_data[14];
	/* 0x001E */ uint16_t m_uSize;
}; // Size: 0x20

static_assert(offsetof(BlobDataKey, BlobDataKey::m_uuid) == 0x0, "BlobDataKey::m_uuid: Incorrect offset");
static_assert(offsetof(BlobDataKey, BlobDataKey::m_data) == 0x10, "BlobDataKey::m_data: Incorrect offset");
static_assert(offsetof(BlobDataKey, BlobDataKey::m_uSize) == 0x1E, "BlobDataKey::m_uSize: Incorrect offset");

static_assert(sizeof(BlobDataKey) == 0x20, "BlobDataKey: Incorrect Size");


struct BlobData
{
public:
	/* 0x0000 */ BlobDataKey m_key;
	/* 0x0020 */ uint16_t m_uWorldId;
	/* 0x0022 */ uint8_t m_uFlags;
private:
	/* 0x0023 */ char pad_0x23[0x5];
public:
	/* 0x0028 */ uint64_t m_uSteamId;
	/* 0x0030 */ uint32_t m_uBlobSize; // might actually be 64 bit, gotta verify this later at some point
private:
	/* 0x0034 */ char pad_0x34[0x4];
public:
	/* 0x0038 */ void* m_pBlobData;
}; // Size: 0x40

static_assert(offsetof(BlobData, BlobData::m_key) == 0x0, "BlobData::m_key: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uWorldId) == 0x20, "BlobData::m_uWorldId: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uFlags) == 0x22, "BlobData::m_uFlags: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uSteamId) == 0x28, "BlobData::m_uSteamId: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uBlobSize) == 0x30, "BlobData::m_uBlobSize: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_pBlobData) == 0x38, "BlobData::m_pBlobData: Incorrect offset");

static_assert(sizeof(BlobData) == 0x40, "BlobData: Incorrect Size");

SMSDK_END_NAMESPACE