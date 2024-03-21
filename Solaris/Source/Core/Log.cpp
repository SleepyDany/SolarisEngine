#include "slrpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Solaris
{
    std::shared_ptr<spdlog::logger> Log::s_core_logger;
    std::shared_ptr<spdlog::logger> Log::s_app_logger;

    void Log::init()
    {
        auto formatter = std::make_unique<spdlog::pattern_formatter>();
        // [{time} | {file}:{func}:{row}] {logger_name}: {message}
        formatter->add_flag<LogFormatterFlag>('s').set_pattern("%^[%T | %s] %n: %v%$");
        spdlog::set_formatter(std::move(formatter));
        
        s_core_logger = spdlog::stdout_color_mt("SOLARIS");
        s_core_logger->set_level(spdlog::level::trace);
        
        s_app_logger = spdlog::stdout_color_mt("APP");
        s_app_logger->set_level(spdlog::level::trace);
    }

    void LogFormatterFlag::format(const spdlog::details::log_msg& msg, const std::tm& time, spdlog::memory_buf_t& dest)
    {
        std::string text;
        if (msg.source.funcname && msg.source.filename)
        {
            text += msg.source.filename;
            text += " : " + std::string(msg.source.funcname);
            text += " : " + std::to_string(msg.source.line);
        }
        
        dest.append(text.data(), text.data() + text.size());
    }

    std::unique_ptr<spdlog::custom_flag_formatter> LogFormatterFlag::clone() const
    {
        return spdlog::details::make_unique<LogFormatterFlag>();
    }
}
