#include "SmSdk/SmSdk.hpp"

#include "SmSdk/win_include.hpp"

bool SmSdk::CheckTimestamp(const std::uint32_t timeStamp)
{
	const std::uintptr_t pBase = (std::uintptr_t)GetModuleHandle(NULL);

	const IMAGE_DOS_HEADER* pDosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(pBase);
	const IMAGE_NT_HEADERS64* pNtHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(pBase + pDosHeader->e_lfanew);

	return pNtHeader->FileHeader.TimeDateStamp == timeStamp;
}