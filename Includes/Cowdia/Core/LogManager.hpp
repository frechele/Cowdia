#ifndef COWDIA_LOG_MANAGER_HPP
#define COWDIA_LOG_MANAGER_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Core/Exception.hpp>
#include <Cowdia/Core/Log.hpp>
#include <Cowdia/Utils/Singleton.hpp>

#include <vector>
#include <string>
#include <mutex>
#include <memory>

namespace Cowdia::Core
{
class COWDIA_API LogHandler
{
 public:
    virtual ~LogHandler() noexcept = default;

    virtual void Logging(const Log& log) = 0;
};

class COWDIA_API LogManager final : public Utils::Singleton<LogManager>
{
 public:
    //! Add stdout to stream list.
    //! NOTE: not thread-safe
    void AddStandardOutput();

    //! Add stderr to stream list.
    //! NOTE: not thread-safe
    void AddStandardError();

    //! Add file stream to stream list.
    //! \param filename the file name of the file stream.
    //! NOTE: not thread-safe
    void AddFileOutput(const std::string& filename);

    //! Add log handler.
    template <class HandlerT, typename... Args>
    void AddHandler(Args&&... args);

    //! Add log
    void Logging(LogLevel level, const std::string& msg);

    //! Add exception log
    void Logging(const Exception& e);

 private:
    std::mutex mutex_;
    std::vector<std::unique_ptr<LogHandler>> handlers_;
};

inline LogManager& LOG()
{
    return LogManager::Get();
}

template <class HandlerT, typename... Args>
void LogManager::AddHandler(Args&&... args)
{
    handlers_.emplace_back(
        std::make_unique<HandlerT>(std::forward<Args>(args)...));
}
}  // namespace Cowdia::Core

#endif  // COWDIA_LOG_MANAGER_HPP
