#include <Cowdia/Core/Engine.hpp>
#include <Cowdia/Core/PluginManager.hpp>

#include <iostream>

using namespace Cowdia;
using namespace Cowdia::Core;

void Setup();
void Shutdown();

int main()
{
    Engine engine;

    Setup();

    engine.Run();

    Shutdown();
}

void Setup()
{
    PluginManager::Get().Load("D3D12Renderer");
    
    const auto renderSystem =
        Engine::Get().GetRenderSystemByName("D3D12RenderSystem");
    Engine::Get().SetRenderSystem(renderSystem);

    renderSystem->Initialize();

    const auto window = renderSystem->GetRenderWindow();
    if (!window->Create(680, 480, false))
    {
        std::cerr << "Cannot create render window." << std::endl;
        std::exit(1);
    }

    window->SetTitle("TestApplication");
}

void Shutdown()
{
    const auto renderSystem = Engine::Get().GetRenderSystem();
    renderSystem->Shutdown();

    PluginManager::Get().Unload("D3D12Renderer");
}