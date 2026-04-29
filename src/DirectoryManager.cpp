#include "SmSdk/DirectoryManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

bool DirectoryManager::getReplacement(
	const std::string_view& key,
	std::string_view& replacement)
{
	auto iter = m_mapContentKeyToPathList.find(key);
	if (iter == m_mapContentKeyToPathList.end())
		return false;

	replacement = iter->second;
	return true;
}

bool DirectoryManager::replacePathR(std::string& path)
{
	if (path.empty() || path[0] != L'$')
		return false;

	const char* v_keyBeg = path.data();
	const char* v_keyPtr = std::strchr(v_keyBeg, L'/');
	if (v_keyPtr == nullptr) return false;

	std::string_view v_keyChunk(v_keyBeg, v_keyPtr);
	const auto v_iter = m_mapContentKeyToPathList.find(v_keyChunk);
	if (v_iter == m_mapContentKeyToPathList.end())
		return false;

	const auto v_pathBegin = path.begin();
	path.replace(
		v_pathBegin,
		v_pathBegin + v_keyChunk.size(),
		std::string_view(v_iter->second)
	);

	return true;
}

bool DirectoryManager::GetReplacement(
	const std::string_view& key,
	std::string_view& replacement)
{
	DirectoryManager* v_pDirMgr = DirectoryManager::GetInstance();
	if (v_pDirMgr)
		return v_pDirMgr->getReplacement(key, replacement);
	else
		return false;
}

bool DirectoryManager::ReplacePathR(std::string& path)
{
	DirectoryManager* v_pDirMgr = DirectoryManager::GetInstance();
	if (v_pDirMgr)
		return v_pDirMgr->replacePathR(path);
	else
		return false;
}