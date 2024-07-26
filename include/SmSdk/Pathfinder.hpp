#pragma once

class PathNode : public NetObj {
private:
    /* 0x0028 */ char pad_0x28[0x8];
public:
    /* 0x0030 */ __int16 world_id;
private:
    /* 0x0032 */ char pad_0x32[0x6];
public:
    /* 0x0038 */ std::vector<int> connected_ids;
    /* 0x0050 */ DirectX::XMFLOAT3 position;
private:
    /* 0x005C */ char pad_0x5C[0x4];
}; // Size: 0x60

static_assert(sizeof(PathNode) == 0x60, "PathNode: Incorrect Size");


class Pathfinder {
public:
    /* 0x0000 */ std::unordered_map<int, std::shared_ptr<PathNode>> m_map;
private:
    /* 0x0040 */ char pad_0x64[0x90];
public:

    static Pathfinder* GetInstance();
}; // Size: 0xD0

static_assert(sizeof(Pathfinder) == 0xD0, "Pathfinder: Incorrect Size");