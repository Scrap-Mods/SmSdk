#pragma once

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

struct IToolImpl
{
private:
	virtual void func1() { /* implemented by the game */ }
	virtual void func2() { /* implemented by the game */ }
	virtual void func3() { /* implemented by the game */ }
	virtual void func4() { /* implemented by the game */ }
	virtual void func5() { /* implemented by the game */ }
	virtual void func6() { /* implemented by the game */ }
public:
	virtual bool isEquipped() { return false; /* implemented by the game */ }
}; // Size: 0x8

static_assert(sizeof(IToolImpl) == 0x8, "IToolImpl: Incorrect Size");

SMSDK_END_NAMESPACE