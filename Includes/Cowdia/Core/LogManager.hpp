#ifndef COWDIA_LOG_MANAGER_HPP
#define COWDIA_LOG_MANAGER_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Utils/Singleton.hpp>

namespace Cowdia::Core
{
class COWDIA_API LogManager final : public Utils::Singleton<LogManager>
{

};

inline LogManager& LOG()
{
    return LogManager::Get();
}
}

#endif  // COWDIA_LOG_MANAGER_HPP
