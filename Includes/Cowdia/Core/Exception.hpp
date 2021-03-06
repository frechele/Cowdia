#ifndef COWDIA_EXCEPTION_HPP
#define COWDIA_EXCEPTION_HPP

#include <Cowdia/Core/Common.hpp>

#include <cstdint>
#include <string>

namespace Cowdia::Core
{
class COWDIA_API Exception
{
 public:
    //! Constructor with only a message.
    //! \param name The name of the exception.
    //! \param message The exception message.
    Exception(std::string name, std::string message);

    //! Constructor with a message and more informations.
    //! \param name The name of the exception.
    //! \param message The exception message.
    //! \param source The source where the exception is thrown.
    //! \param line The line number where the exception is thrown.
    Exception(std::string name, std::string message, std::string source,
              std::uint64_t line);

    //! Default destructor.
    virtual ~Exception() noexcept = default;

    //! Returns exception name.
    [[nodiscard]] const std::string& GetName() const;

    //! Returns exception message.
    [[nodiscard]] const std::string& GetMessage() const;

    //! Returns source where the exception is thrown.
    [[nodiscard]] const std::string& GetSource() const;

    //! Returns line number where the exception is thrown.
    [[nodiscard]] std::uint64_t GetLine() const;

    [[nodiscard]] std::string What() const;

 private:
    std::string name_;
    std::string message_;
    std::string source_;
    std::uint64_t line_;
};

struct COWDIA_API UnImplementedException final : public Exception
{
    UnImplementedException();
    UnImplementedException(std::string source, std::uint64_t line);
};

struct COWDIA_API RuntimeException final : public Exception
{
    RuntimeException(std::string message);
    RuntimeException(std::string message, std::string source,
                     std::uint64_t line);
};
}  // namespace Cowdia::Core

#endif  // COWDIA_EXCEPTION_HPP
