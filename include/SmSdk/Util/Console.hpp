#pragma once

#include <windows.h>

#include <unordered_set>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>

namespace UTILS
{
	class Contraption;

	enum : std::uint32_t
	{
		ConsoleLogType_Default = 0x1,
		ConsoleLogType_Profile = 0x2,
		ConsoleLogType_Resource = 0x4,
		ConsoleLogType_Shader = 0x8,
		ConsoleLogType_Buffer = 0x10,
		ConsoleLogType_Render = 0x20,
		ConsoleLogType_Network = 0x40,
		ConsoleLogType_System = 0x80,
		ConsoleLogType_Terrain = 0x100,
		ConsoleLogType_World = 0x200,
		ConsoleLogType_Audio = 0x400,
		ConsoleLogType_Lua = 0x800,
		ConsoleLogType_Print = 0x1000,
		ConsoleLogType_UGC = 0x2000,
		ConsoleLogType_Steam = 0x4000,
		ConsoleLogType_Warning = 0x40000000,
		ConsoleLogType_Error = 0x80000000,
	};

	class Console
	{
	public:
		virtual ~Console();
		virtual void log(const std::string& msg, WORD color, std::uint32_t type);
		virtual bool logNoRepeat(const std::string& msg, WORD color, std::uint32_t type);

        static Console* GetInstance();
	private:
		template<typename CurArg>
		inline void variadic_internal(std::stringstream& stream, const CurArg& cur_arg)
		{
			stream << cur_arg;
		}

		template<typename CurArg, typename ...Args>
		inline void variadic_internal(std::stringstream& stream, const CurArg& cur_arg, const Args& ...arg_list)
		{
			this->variadic_internal(stream, cur_arg);
			this->variadic_internal(stream, arg_list...);
		}

	public:
		template<typename ...Args>
		inline void log_variadic(WORD color, std::uint32_t type, const Args& ...args)
		{
			std::stringstream v_stream;
			this->variadic_internal(v_stream, args...);

			this->log(v_stream.str(), color, type);
		}

		template<typename ...Args>
		inline void log_variadic_no_repeat(WORD color, std::uint32_t type, const Args& ...args)
		{
			std::stringstream v_stream;
			this->variadic_internal(v_stream, args...);

			this->logNoRepeat(v_stream.rdbuf()->str(), color, type);
		}

		//inline static std::function<void(const char*, const char*, unsigned int)> sm_assertHandler = nullptr;

	public:
		//inline static std::mutex sm_logMutex = std::mutex();
		//inline static std::mutex sm_logNoRepeatMutex = std::mutex();
		//inline static std::unordered_set<std::uint64_t> sm_messageCache = {};

		/* 0x0008 */ std::function<void(const char*, unsigned int)> unknown_function;
		/* 0x0048 */ std::uint32_t console_output_mask;
		/* 0x004C */ std::uint32_t file_output_mask;
		/* 0x0050 */ std::uint32_t callback_output_mask;
		/* 0x0054 */ char pad_0x54[0x4];
		/* 0x0058 */ HANDLE console_handle = NULL;
		/* 0x0060 */ std::ofstream out_stream;
		/* 0x0168 */ char pad_0x168[0x10];
		/* 0x0178 */ bool code_page_set = false;
		/* 0x0179 */ bool console_allocated = false;
		/* 0x017A */ char pad_0x17A[0x2];
		/* 0x017C */ std::uint32_t warning_counter = 0;
		/* 0x0180 */ std::uint32_t error_counter = 0;
		/* 0x0184 */ char pad_0x184[0x4];
	};
}

#define LOG_ERROR(...) UTILS::Console::GetInstance()->log_variadic(FOREGROUND_RED | FOREGROUND_INTENSITY, UTILS::ConsoleLogType_Error, __VA_ARGS__)
#define LOG_WARNING(...) UTILS::Console::GetInstance()->log_variadic(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, UTILS::ConsoleLogType_Warning, __VA_ARGS__)