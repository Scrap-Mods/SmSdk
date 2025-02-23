#pragma once

#include "SmSdk/boost_include.hpp"

#include <cstdint>
#include <cstddef>

struct BlobDataKey
{
public:
	/* 0x0000 */ boost::uuids::uuid uuid;
	/* 0x0010 */ std::uint8_t data[14];
	/* 0x001E */ std::uint16_t size;
}; // Size: 0x20

static_assert(offsetof(BlobDataKey, BlobDataKey::uuid) == 0x0, "BlobDataKey::uuid: Incorrect offset");
static_assert(offsetof(BlobDataKey, BlobDataKey::data) == 0x10, "BlobDataKey::data: Incorrect offset");
static_assert(offsetof(BlobDataKey, BlobDataKey::size) == 0x1E, "BlobDataKey::size: Incorrect offset");

static_assert(sizeof(BlobDataKey) == 0x20, "BlobDataKey: Incorrect Size");



struct BlobData
{
public:
	/* 0x0000 */ BlobDataKey m_pKey;
	/* 0x0020 */ std::uint16_t m_u16WorldId;
	/* 0x0022 */ std::uint8_t m_u8Flags;
private:
	/* 0x0023 */ char pad_0x23[0x5];
public:
	/* 0x0028 */ std::uint64_t m_uSteamId;
	/* 0x0030 */ std::uint32_t m_uBlobSize; // might actually be 64 bit, gotta verify this later at some point
private:
	/* 0x0034 */ char pad_0x34[0x4];
public:
	/* 0x0038 */ void* m_pBlobData;
}; // Size: 0x40

static_assert(offsetof(BlobData, BlobData::m_pKey) == 0x0, "BlobData::m_pKey: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_u16WorldId) == 0x20, "BlobData::m_u16WorldId: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_u8Flags) == 0x22, "BlobData::m_u8Flags: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uSteamId) == 0x28, "BlobData::m_uSteamId: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_uBlobSize) == 0x30, "BlobData::m_uBlobSize: Incorrect offset");
static_assert(offsetof(BlobData, BlobData::m_pBlobData) == 0x38, "BlobData::m_pBlobData: Incorrect offset");

static_assert(sizeof(BlobData) == 0x40, "BlobData: Incorrect Size");