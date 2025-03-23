#pragma once

#include "SmSdk/d3d11_include.hpp"
#include "rend_resources.hpp"

#include <string>
#include <vector>

struct LayoutParameter
{
public:
	/* 0x0000 */ std::string m_defineString;
	/* 0x0020 */ __int8 m_semanticIndex;
private:
	/* 0x0021 */ char pad_0x21[0x3];
public:
	/* 0x0024 */ DXGI_FORMAT m_format;
	/* 0x0028 */ __int8 m_inputSlot;
	/* 0x0029 */ bool m_someBool2;
private:
	/* 0x002A */ char pad_0x2A[0x6];
}; // Size: 0x30

static_assert(offsetof(LayoutParameter, LayoutParameter::m_defineString) == 0x0, "LayoutParameter::m_defineString: Incorrect offset");
static_assert(offsetof(LayoutParameter, LayoutParameter::m_semanticIndex) == 0x20, "LayoutParameter::m_semanticIndex: Incorrect offset");
static_assert(offsetof(LayoutParameter, LayoutParameter::m_format) == 0x24, "LayoutParameter::m_format: Incorrect offset");
static_assert(offsetof(LayoutParameter, LayoutParameter::m_inputSlot) == 0x28, "LayoutParameter::m_inputSlot: Incorrect offset");
static_assert(offsetof(LayoutParameter, LayoutParameter::m_someBool2) == 0x29, "LayoutParameter::m_someBool2: Incorrect offset");

static_assert(sizeof(LayoutParameter) == 0x30, "LayoutParameter: Incorrect Size");

class MaterialData
{
public:
	/* 0x0000 */ std::string m_vsEntry;
	/* 0x0020 */ std::string m_psEntry;
	/* 0x0040 */ std::string m_shaderPath;
	/* 0x0060 */ std::vector<std::string> m_vecDefines;
	/* 0x0078 */ std::vector<LayoutParameter> m_vecLayoutParams;

}; // Size: 0x90

static_assert(offsetof(MaterialData, MaterialData::m_vsEntry) == 0x0, "MaterialData::m_vsEntry: Incorrect offset");
static_assert(offsetof(MaterialData, MaterialData::m_psEntry) == 0x20, "MaterialData::m_psEntry: Incorrect offset");
static_assert(offsetof(MaterialData, MaterialData::m_shaderPath) == 0x40, "MaterialData::m_shaderPath: Incorrect offset");
static_assert(offsetof(MaterialData, MaterialData::m_vecDefines) == 0x60, "MaterialData::m_vecDefines: Incorrect offset");
static_assert(offsetof(MaterialData, MaterialData::m_vecLayoutParams) == 0x78, "MaterialData::m_vecLayoutParams: Incorrect offset");

static_assert(sizeof(MaterialData) == 0x90, "MaterialData: Incorrect Size");

struct Material
{
public:
	/* 0x0000 */ MaterialData m_data;
	/* 0x0090 */ rend::D3D11Layout* m_pLayout;
	/* 0x0098 */ rend::D3D11ShaderProgram* m_pShaderProgram;

}; // Size: 0xA0

static_assert(offsetof(Material, Material::m_data) == 0x0, "Material::m_data: Incorrect offset");
static_assert(offsetof(Material, Material::m_pLayout) == 0x90, "Material::m_pLayout: Incorrect offset");
static_assert(offsetof(Material, Material::m_pShaderProgram) == 0x98, "Material::m_pShaderProgram: Incorrect offset");

static_assert(sizeof(Material) == 0xA0, "Material: Incorrect Size");