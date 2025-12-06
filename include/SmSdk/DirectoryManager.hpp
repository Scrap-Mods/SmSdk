#pragma once

#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>

SMSDK_BEGIN_NAMESPACE

class DirectoryManager
{
	SINGLETON_CLASS(DirectoryManager);
public:
	static DirectoryManager* GetInstance();

	bool getReplacement(const std::string& key, std::string& replacement);
	bool replacePathR(std::string& path);

	static bool ReplacePathR(std::string& path);
	static bool GetReplacement(const std::string& key, std::string& replacement);
private:
	char unk_data1[8];
public:
	std::unordered_map<std::string, std::string> m_mapContentKeyToPathList;
};

SMSDK_END_NAMESPACE