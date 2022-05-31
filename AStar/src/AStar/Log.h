#pragma once

#include <memory>
#include "Macros.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace AStar
{
	class ASTAR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AS_CORE_ERROR(...) ::AStar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AS_CORE_WARN(...)  ::AStar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AS_CORE_INFO(...)  ::AStar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AS_CORE_TRACE(...) ::AStar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_FATAL(...) ::AStar::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AS_ERROR(...)      ::AStar::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_WARN(...)       ::AStar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_INFO(...)       ::AStar::Log::GetClientLogger()->info(__VA_ARGS__)
#define AS_TRACE(...)      ::AStar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_FATAL(...)      ::AStar::Log::GetClientLogger()->fatal(__VA_ARGS__)