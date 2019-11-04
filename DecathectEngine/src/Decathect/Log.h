#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Decathect {
	class DCTHCT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define DCTHCT_CORE_FATAL(...) ::Decathect::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define DCTHCT_CORE_ERROR(...) ::Decathect::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DCTHCT_CORE_WARN(...)  ::Decathect::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DCTHCT_CORE_INFO(...)  ::Decathect::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DCTHCT_CORE_TRACE(...) ::Decathect::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define DCTHCT_FATAL(...) ::Decathect::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define DCTHCT_ERROR(...) ::Decathect::Log::GetClientLogger()->error(__VA_ARGS__)
#define DCTHCT_WARN(...)  ::Decathect::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DCTHCT_INFO(...)  ::Decathect::Log::GetClientLogger()->info(__VA_ARGS__)
#define DCTHCT_TRACE(...) ::Decathect::Log::GetClientLogger()->trace(__VA_ARGS__)