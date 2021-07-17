#include "D3D12Exception.hpp"

namespace Cowdia::Core
{
D3D12Exception::D3D12Exception(long hr, std::string message, std::string source,
                               std::uint64_t line)
    : D3D12Exception(message + " " + std::to_string(hr), std::move(source),
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
}  // namespace Cowdia::Core
