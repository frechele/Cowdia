#ifndef COWDIA_LOG_HPP
#define COWDIA_LOG_HPP

#include <Cowdia/Core/Common.hpp>

#include <ctime>
#include <string>

namespace Cowdia::Core
{
enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERR
};

std::string LogLevelStr(LogLevel level);

class COWDIA_API Log final
{
 public:
    //! Constructor.
    Log(LogLevel level, std::string msg);

    //! Returns the level of log.
    LogLevel GetLevel() const;

    //! Returns the message of log.
    const std::string& GetMessage() const;

    //! Returns formatted log message.
    std::string ToString() const;

 private:
    LogLevel level_{ LogLevel::DEBUG };
    std::string msg_;
    std::time_t time_;
};
}

#endif  // COWDIA_LOG_HPP
