#pragma once

#include "SmSdk/Gui/GuiInterface.hpp"
#include "SmSdk/Util/Color.hpp"

#include "SmSdk/Tool/IToolNetworkData.hpp"
#include "SmSdk/Tool/ClientTool.hpp"

#include <DirectXMath.h>
#include <functional>

SMSDK_BEGIN_NAMESPACE

class PaintToolNetworkData : public IToolNetworkData
{
public:
	/* 0x0010 */ Color m_paintColor;
	/* 0x0014 */ bool m_bColorUpdated;
private:
	/* 0x0015 */ char pad_0x15[0x3];
public:
	/* 0x0018 */ std::function<void(void)> m_function;

}; // Size: 0x58

static_assert(sizeof(PaintToolNetworkData) == 0x58, "PaintToolNetworkData: Incorrect Size");

struct PaintToolSelectionData
{
	/* 0x0000 */ std::int32_t m_iObjectId;
	/* 0x0004 */ std::int32_t m_iObjectType;
private:
	/* 0x0008 */ DirectX::XMFLOAT3 m_someVector;
public:
	/* 0x0014 */ DirectX::XMINT3 m_selectionBoxLimiter;
	/* 0x0020 */ DirectX::XMINT3 m_selectionBoxMin;
	/* 0x002C */ DirectX::XMINT3 m_selectionBoxMax;
private:
	/* 0x0038 */ char pad_0x38[0x8];
}; // Size: 0x40

static_assert(sizeof(PaintToolSelectionData) == 0x40, "PaintToolSelectionData: Incorrect Size");

class PaintTool : public ClientTool
{
private:
	/* 0x0548 */ char pad_0x548[0x8];
public:
	/* 0x0550 */ Color m_paintColor;
	/* 0x0554 */ std::int32_t m_iLmbState;
	/* 0x0558 */ std::int32_t m_iRmbState;
private:
	/* 0x055C */ char pad_0x55C[0x4];
public:
	/* 0x0560 */ PaintToolSelectionData m_paintSelection;
	/* 0x05A0 */ PaintToolSelectionData m_eraseSelection;
	/* 0x05E0 */ DirectX::XMMATRIX m_paintSelectionObjectMatrix;
	/* 0x0620 */ DirectX::XMMATRIX m_eraseSelectionObjectMatrix;
	/* 0x0660 */ bool m_bSelectorEnabled;
private:
	/* 0x0661 */ char pad_0x661[0x3];
public:
	/* 0x0664 */ std::int32_t m_iSelectedObjectId;
	/* 0x0668 */ DirectX::XMINT3 m_selectorPosition;
private:
	/* 0x0674 */ char pad_0x674[0xC];
public:
	/* 0x0680 */ DirectX::XMMATRIX m_selectorObjectMatrix;
	/* 0x06C0 */ float m_fTimeSinceLastChange;
	/* 0x06C4 */ Color m_prevPaintColor;
	/* 0x06C8 */ Color m_visualizationColor;
private:
	/* 0x06CC */ char pad_0x6CC[0x4];
public:
	/* 0x06D0 */ PaintToolNetworkData* m_pNetworkData;
private:
	/* 0x06D8 */ char pad_0x6D8[0x8];
public:
	/* 0x06E0 */ std::shared_ptr<GuiInterface> m_pGuiInterface;

}; // Size: 0x6F0

static_assert(sizeof(PaintTool) == 0x6F0, "PaintTool: Incorrect Size");

SMSDK_END_NAMESPACE