#pragma once
#include "core.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


#define HZ_CORE_TRACE(...)		::hezzle::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::hezzle::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::hezzle::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::hezzle::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::hezzle::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define HZ_CLIENT_TRACE(...)	::hezzle::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_CLIENT_WARN(...)		::hezzle::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_CLIENT_INFO(...)		::hezzle::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_CLIENT_ERROR(...)	::hezzle::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_CLIENT_FATAL(...)	::hezzle::Log::GetClientLogger()->fatal(__VA_ARGS__)


namespace hezzle
{
	class HEZZLE_API Log
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

