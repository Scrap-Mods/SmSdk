#pragma once

#include <unordered_map>
#include <DirectXMath.h>
#include <memory>

class PortalData {
private:
    /* 0x0000 */ char pad0x0[0x40];
public:
    /* 0x0040 */ DirectX::XMFLOAT3 position;
}; // Size: 0x60

static_assert(sizeof(PortalData) == 0x60, "PortalData: Incorrect Size");

class PortalOpening {
private:
    /* 0x0000 */ char pad0x0[0x38];
public:
    /* 0x0038 */ PortalData* data;
}; // Size: 0x60

static_assert(sizeof(PortalOpening) == 0x60, "PortalOpening: Incorrect Size");

class Portal {
private:
    /* 0x0000 */ char pad0x0[0x10];
public:
    /* 0x0010 */ std::shared_ptr<Portal> self_ptr;
    /* 0x0020 */ __int32 Id;
    /* 0x0024 */ __int32 some_value;
private:
    /* 0x0028 */ char pad0x28[0x18];
public:
    /* 0x0040 */ PortalOpening* opening_a;
    /* 0x0048 */ PortalOpening* opening_b;
}; // Size: 0x50

static_assert(sizeof(Portal) == 0x50, "Portal: Incorrect Size");

class PortalManager {
public:
    static PortalManager* GetInstance();

    /* 0x0000 */ std::unordered_map<int, std::shared_ptr<Portal>> portal_map;
private:
    /* 0x0064 */ char pad0x64[0x34];

    // After this comes the "PortalHooks", they contain names and other stuff
}; // Size: 0x98

static_assert(sizeof(PortalManager) == 0x98, "PortalManager: Incorrect Size");