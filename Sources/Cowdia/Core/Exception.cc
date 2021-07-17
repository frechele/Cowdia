#include <Cowdia/Core/Exception.hpp>

#include <sstream>

namespace Cowdia::Core
{
Exception::Exception(std::string name, std::string message)
    : Exception(std::move(name), std::move(message), "", 0)
{
    // Do nothing.
}

Exception::Exception(std::string name, std::string message, std::string source,
                     std::uint64_t line)
    : name_(std::move(name)),
      message_(std::move(message)),
      source_(std::move(source)),
      line_(line)
{
    // Do nothing.
}

const std::string& Exception::GetMessage() const
{
    return message_;
}

const std::string& Exception::GetSource() const
{
    return source_;
}

std::uint64_t Exception::GetLine() const
{
    return line_;
}

std::string Exception::What() const
{
    std::stringstream ss;

    ss << "[" << name_ << "] " << message_ << " (" << source_ << ":" << line_
       << ")";

    return ss.str();
}

UnImplementedException::UnImplementedException() : UnImplementedException("", 0)
{
    // Do nothing.
}

UnImplementedException::UnImplementedException(std::string source,
                                               std::uint64_t line)
    : Exception("UnImplementedException", "unimplemented", std::move(source),
                line)
{
    // Do nothing.
}
}  // namespace Cowdia::Core
