#pragma once

#include "SmSdk/boost_include.hpp"
#include <unordered_map>
#include "uuid"

class Item {
	/* 0x0000 */ boost::uuids::uuid;
	/* 0x0010 */ __int32 unknown;
	/* 0x0014 */ __int32 stackamount;
}; // Size: 0x18

static_assert(sizeof(Item) == 0x18, "Item: Incorrect Size");

class Container : public NetObj {
private:
	/* 0x0028 */ char pad_0x28[0x10];
public:
	/* 0x0038 */ std::vector<item> item_list;
private:
	/* 0x0040 */ char pad_0x40[0xB0];
}; // Size: 0xF0

static_assert(sizeof(Container) == 0xF0, "Container: Incorrect Size");

class ContainerManager {
public:
    static ContainerManager* GetInstance();
private:
	/* 0x0000 */ char pad_0x0000[0x40];
public:
	/* 0x0040 */ std::unordered_map<int, std::shared_ptr<Container>> container_list;
private:
	/* 0x0080 */ char pad_0x80[0x18];
}; // Size: 0x98

static_assert(sizeof(ContainerManager) == 0x98, "ContainerManager: Incorrect Size");
