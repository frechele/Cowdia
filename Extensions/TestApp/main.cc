#include <Cowdia/Core/Application.hpp>
#include <Cowdia/Core/Engine.hpp>

#include <iostream>

using namespace Cowdia;
using namespace Cowdia::Core;

class TestApp final : public Application
{
 public:
    void OnInitialize() override
    {
        LogManager::Get().AddStandardOutput();

        PluginManager::Get().Load("D3D12Renderer");

        renderSystem = Engine::Get().GetRenderSystemByName("D3D12RenderSystem");
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

    void OnShutdown() override
    {
        renderSystem->Shutdown();
    }

 private:
    Rendering::RenderSystem* renderSystem;
};

int main()
{
    Engine engine;
    engine.SetDebugMode(true);

    TestApp app;
    engine.Run(app);
}
