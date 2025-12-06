#pragma once

#include "SmSdk/config.hpp"
#include "SmSdk/unreferenced_params.hpp"

SMSDK_BEGIN_NAMESPACE

class InputTarget
{
public:
	virtual void onKeyPress(int key) { SMSDK_UNREF(key); /* implemented by the game */ }
	virtual void onKeyRelease(int key) { SMSDK_UNREF(key); /* implemented by the game */ }
	virtual void onMouseKeyPress(int mouseKey) { SMSDK_UNREF(mouseKey); /* implemented by the game */ }
	virtual void onMouseKeyRelease(int mouseKey) { SMSDK_UNREF(mouseKey); /* implemented by the game */ }
private:
	virtual void func5() { /* implemented by the game */ }
	virtual void func6() { /* implemented by the game */ }
}; // Size: 0x8

static_assert(sizeof(InputTarget) == 0x8, "InputTarget: Incorrect Size");

SMSDK_END_NAMESPACE