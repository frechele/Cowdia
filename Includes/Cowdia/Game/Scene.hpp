#ifndef COWDIA_SCENE_HPP
#define COWDIA_SCENE_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Types/Color.hpp>

namespace Cowdia::Game
{
class COWDIA_API Scene
{
 public:
    Types::Color ClearColor;

    //! Default destructor.
    virtual ~Scene() noexcept = default;

    //! Triggered when this scene is loaded.
    virtual void OnLoad() = 0;

    //! Triggered when this scene is unloaded.
    virtual void OnUnload() = 0;
};
}  // namespace Cowdia::Game

#endif  // COWDIA_SCENE_HPP
