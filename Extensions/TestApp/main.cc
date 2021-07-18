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

    try
    {
        Setup();

        engine.Run();

        Shutdown();
    }
    catch (Exception& e)
    {
        LOG(e);
        throw;
    }
}

void Setup()
{
    LogManager::Get().AddStandardOutput();

    PluginManager::Get().Load("D3D12Renderer");
    
    const auto renderSystem =
        Engine::Get().GetRenderSystemByName("D3D12RenderSystem");
    Engine::Get().SetRenderSystem(renderSystem);

    renderSystem->Initialize();

    const auto window = renderSystem->GetRenderWindow();
    if (!window->Create(680, 480))
    {
        std::cerr << "Cannot create render window." << std::endl;
        std::exit(1);
    }

    window->SetTitle("TestApplication");

    const auto renderer = renderSystem->GetRenderer();
    renderer->Initialize();
}

void Shutdown()
{
    const auto renderSystem = Engine::Get().GetRenderSystem();
    renderSystem->Shutdown();

    PluginManager::Get().Unload("D3D12Renderer");
}
