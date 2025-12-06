#pragma once

#include <memory>

SMSDK_BEGIN_NAMESPACE

class NetObj
{
public:
	virtual ~NetObj() = default;
private:
	virtual void func2() {}
public:
	virtual char getObjectType() { return 0; }
	virtual void updateObject() {}
private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ std::shared_ptr<NetObj> m_pSelf;
	/* 0x0020 */ std::int32_t m_iId;
	/* 0x0024 */ std::int32_t m_iRevision;
}; // Size: 0x28

static_assert(sizeof(NetObj) == 0x28, "NetObj: Incorrect Size");

SMSDK_END_NAMESPACE