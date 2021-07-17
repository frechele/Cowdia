#ifndef D3D12RS_EXCEPTION_HPP
#define D3D12RS_EXCEPTION_HPP

#include "D3D12Common.hpp"

#include <Cowdia/Core/Exception.hpp>

namespace Cowdia::Core
{
struct COWDIA_D3D12_API D3D12Exception final : public Exception
{
    D3D12Exception(std::string message, std::string source,
                   std::uint64_t line);

    D3D12Exception(long hr, std::string message, std::string source,
                   std::uint64_t line);
};
}  // namespace Cowdia::Core

#ifndef THROW_IF_FAILED
#define THROW_IF_FAILED(x)                                                    \
    do                                                                        \
    {                                                                         \
        const long hr__ = (x);                                                \
        if (FAILED(hr__))                                                     \
            throw Cowdia::Core::D3D12Exception(hr__, #x, __FILE__, __LINE__); \
    } while (false)
#endif

#endif  // D3D12RS_EXCEPTION_HPP
