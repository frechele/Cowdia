#include <Cowdia/Core/Log.hpp>

#include <chrono>
#include <sstream>
#include <time.h>

namespace Cowdia::Core
{
std::string LogLevelStr(LogLevel level)
{
    using namespace std::string_literals;

    switch (level)
    {
        case LogLevel::DEBUG:
            return "DEBUG"s;
        case LogLevel::INFO:
            return "INFO"s;
        case LogLevel::WARNING:
            return "WARNING"s;
        case LogLevel::ERR:
            return "ERROR"s;
        default:
            return "UNKNOWN"s;
    }
}

Log::Log(LogLevel level, std::string msg)
    : level_(level),
      msg_(std::move(msg)),
      time_(std::chrono::system_clock::to_time_t(
          std::chrono::system_clock::now()))
{
    // Do nothing.
}

LogLevel Log::GetLevel() const
{
    return level_;
}

const std::string& Log::GetMessage() const
{
    return msg_;
}

std::string Log::ToString() const
{
    std::stringstream ss;

    std::tm* now;
#ifdef COWDIA_PLATFORM_WIN32
    now = std::localtime(&time_);
#else
    now = localtime_r(&time_);
#endif

    ss << "[" << (now->tm_year + 1900) << "-" << (now->tm_mon + 1) << "-"
       << (now->tm_mday) << " " << (now->tm_hour) << ":" << (now->tm_min) << ":"
       << (now->tm_sec)
       << "] (" << LogLevelStr(level_) << ") "
       << msg_;

    return ss.str();
}
}  // namespace Cowdia::Core
