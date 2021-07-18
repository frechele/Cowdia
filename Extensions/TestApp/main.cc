#include <Cowdia/Core/Application.hpp>
#include <Cowdia/Core/Engine.hpp>
#include <Cowdia/Game/Scene.hpp>

#include <iostream>

using namespace Cowdia;
using namespace Cowdia::Core;
using namespace Cowdia::Game;

class TestScene final : public Scene
{
 public:
    void OnLoad() override
    {
        ClearColor = Types::Color(0, 255, 255);
    }

    void OnUnload() override
    {
        // Do nothing.
    }
};

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

        SceneManager::Get().LoadScene("InvalidScene");

        SceneManager::Get().RegisterScene<TestScene>("TestScene");
        SceneManager::Get().LoadScene("TestScene");
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
