#include <Cowdia/Core/LogManager.hpp>

#include <fstream>
#include <iostream>

namespace Cowdia::Core
{
namespace
{
struct StdoutLogHandler final : public LogHandler
{
    void Logging(const Log& log) override
    {
        std::cout << log.ToString() << std::endl;
    }
};

struct StderrLogHandler final : public LogHandler
{
    void Logging(const Log& log) override
    {
        std::cerr << log.ToString() << std::endl;
    }
};

struct FileLogHandler final : public LogHandler
{
    explicit FileLogHandler(const std::string& path)
    {
        file_.open(path, std::ios_base::app);
    }

    void Logging(const Log& log) override
    {
        file_ << log.ToString() << std::endl;
    }

 private: std::ofstream file_;
};
}  // namespace

void LogManager::AddStandardOutput()
{
    AddHandler<StdoutLogHandler>();
}

void LogManager::AddStandardError()
{
    AddHandler<StderrLogHandler>();
}

void LogManager::AddFileOutput(const std::string& filename)
{
    AddHandler<FileLogHandler>(filename);
}

void LogManager::Logging(LogLevel level, const std::string& msg)
{
    std::scoped_lock lock(mutex_);

    Log log(level, msg);

    for (auto& handler : handlers_)
        handler->Logging(log);
}
}  // namespace Cowdia::Core
