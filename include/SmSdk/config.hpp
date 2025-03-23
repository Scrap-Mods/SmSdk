#pragma once

// Additional libraries that can be added to expand the functionality of SMSDK

//#define SMSDK_ENABLE_PHYSICS
//#define SMSDK_ENABLE_JSONCPP
//#define SMSDK_ENABLE_FMOD
//#define SMSDK_ENABLE_STEAMAPI
//#define SMSDK_ENABLE_MYGUI
//#define SMSDK_ENABLE_D3D11

// WARNING: All the map getters will be wrong without the Boost uuid library
//#define SMSDK_ENABLE_BOOST

#include <cstdint>
#include <cstddef>

#define SINGLETON_CLASS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete; \
	~class_name() = delete

#define REMOVE_COPY_CONSTRUCTORS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete;

// Means that the std::size_t is an output of an XXH function
using XXHStringHash = std::size_t;

// A simple number used as a hash
struct PassthroughHash {
	inline std::size_t operator()(const std::size_t val) const noexcept {
		return val;
	}
};