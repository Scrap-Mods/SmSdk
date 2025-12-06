#pragma once

#include "SmSdk/Gui/GuiBase.hpp"

SMSDK_BEGIN_NAMESPACE

class PaintToolGui : public GuiBase
{
public:
	/* 0x0018 */ MyGUI::ItemBox* m_pItemBox;
}; // Size: 0x20

static_assert(sizeof(PaintToolGui) == 0x20, "PaintToolGui: Incorrect Size");

SMSDK_END_NAMESPACE