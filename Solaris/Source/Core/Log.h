#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/pattern_formatter.h"

namespace std
{
    struct source_location;
}

enum ELogLevel : int
{
    Trace,
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

namespace Solaris
{
    class SOLARIS_API Log
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_core_logger()
        {
            return s_core_logger;
        }
        
        inline static std::shared_ptr<spdlog::logger>& get_app_logger()
        {
            return s_app_logger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_app_logger;

        static std::source_location s_source_location;
    };

    class LogFormatterFlag : public spdlog::custom_flag_formatter
    {
    public:
        void format(const spdlog::details::log_msg& msg, const std::tm& time, spdlog::memory_buf_t& dest) override;
        std::unique_ptr<custom_flag_formatter> clone() const override;
    };
}

#define SLR_CORE_LOG(log_level, ...) \
    Solaris::Log::get_core_logger()->log( \
        spdlog::source_loc( \
            std::filesystem::path(std::source_location::current().file_name()).filename().string().c_str(), \
            std::source_location::current().line(), \
            std::source_location::current().function_name()), \
        static_cast<spdlog::level::level_enum>(log_level), \
        __VA_ARGS__ \
    ) \

#define SLR_APP_LOG(log_level, ...) \
    Solaris::Log::get_app_logger()->log( \
        spdlog::source_loc( \
            std::filesystem::path(std::source_location::current().file_name()).filename().string().c_str(), \
            std::source_location::current().line(), \
            std::source_location::current().function_name()), \
        static_cast<spdlog::level::level_enum>(log_level), \
        __VA_ARGS__ \
    ) \
