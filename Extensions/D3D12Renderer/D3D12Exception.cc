#include "D3D12Exception.hpp"

#include <iomanip>
#include <sstream>

namespace Cowdia::Core
{
D3D12Exception::D3D12Exception(std::uint64_t hr, const std::string& message, std::string source,
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

std::string D3D12Exception::HRESULTStr(std::uint64_t hr)
{
    std::stringstream ss;

    ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << hr;

    return ss.str();
}
}  // namespace Cowdia::Core
