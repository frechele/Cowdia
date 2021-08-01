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
    [[nodiscard]] LogLevel GetLevel() const;

    //! Returns the message of log.
    [[nodiscard]] const std::string& GetMessage() const;

    //! Returns formatted log message.
    [[nodiscard]] std::string ToString() const;

 private:
    LogLevel level_{ LogLevel::DEBUG };
    std::string msg_;
    std::time_t time_;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_LOG_HPP
