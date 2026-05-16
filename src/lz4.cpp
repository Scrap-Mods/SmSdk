#include "SmSdk/lz4.hpp"

#include <lz4.h>

SMSDK_BEGIN_NAMESPACE

int Lz4::Compress(
	const void* src,
	void* dst,
	const int srcSize,
	const int dstCapacity)
{
	return LZ4_compress_default(
		reinterpret_cast<const char*>(src),
		reinterpret_cast<char*>(dst),
		srcSize,
		dstCapacity);
}

int Lz4::Decompress(
	const void* src,
	void* dst,
	const int compressedSize,
	const int dstCapacity)
{
	return LZ4_decompress_safe(
		reinterpret_cast<const char*>(src),
		reinterpret_cast<char*>(dst),
		compressedSize,
		dstCapacity);
}

SMSDK_END_NAMESPACE