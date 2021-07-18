#ifndef COWDIA_APPLICATION_HPP
#define COWDIA_APPLICATION_HPP

#include <Cowdia/Core/Common.hpp>

namespace Cowdia::Core
{
class COWDIA_API Application
{
 public:
    virtual void OnInitialize() = 0;
    virtual void OnShutdown() = 0;
};
}

#endif  // COWDIA_APPLICATION_HPP
