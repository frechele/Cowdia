#include "D3D12Exception.hpp"

#include <iomanip>

namespace Cowdia::Core
{
D3D12Exception::D3D12Exception(long hr, std::string message, std::string source,
                               std::uint64_t line)
    : D3D12Exception(message + " " + HRESULTStr(hr), std::move(source),
                     line)
{
    // Do nothing.
}

D3D12Exception::D3D12Exception(std::string message, std::string source,
                               std::uint64_t line)
    : Exception("D3D12Exception", std::move(message), std::move(source), line)
{
    // Do nothing.
}

std::string D3D12Exception::HRESULTStr(long hr)
{
    char str[128];

    std::sprintf(str, "0x%08x", hr);

    return std::string(str);
}
}  // namespace Cowdia::Core
