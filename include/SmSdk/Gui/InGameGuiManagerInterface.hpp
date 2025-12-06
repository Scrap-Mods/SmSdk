#pragma once

SMSDK_BEGIN_NAMESPACE

class InGameGuiManagerInterface
{
public:
	virtual ~InGameGuiManagerInterface() = default;
}; // Size: 0x8

static_assert(sizeof(InGameGuiManagerInterface) == 0x8, "InGameGuiManagerInterface: Incorrect Size");

SMSDK_END_NAMESPACE