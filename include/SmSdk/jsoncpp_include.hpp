#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_JSONCPP)
#include <json/json.h>
#else
namespace Json
{
	class Value {
	private:
		char data[0x18];
	};
}
#endif