#ifndef D3D12RS_RENDERER_HPP
#define D3D12RS_RENDERER_HPP

#include "D3D12Common.hpp"

#include <Cowdia/Rendering/Renderer.hpp>
#include <Cowdia/Utils/ComPtr.hpp>
#include "D3D12RenderSystem.hpp"

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <cstdint>

namespace Cowdia::Rendering
{
class COWDIA_D3D12_API D3D12Renderer final : public Renderer
{
 public:
    explicit D3D12Renderer(D3D12RenderSystem* renderSystem);

    void Initialize() override;
    void Shutdown() override;

    bool IsInitialized() const override;

    void BeginFrame(Types::Color color) override;
    void EndFrame() override;

 private:
    void createCommandObjects();
    void createSwapChain();
    void createDescriptorHeaps();
    void createDepthStencilBuffer();

    void resetViewportAndScissor();

    void flushCommandQueue();

    D3D12_CPU_DESCRIPTOR_HANDLE getCurrentBackBufferView() const;

 private:
    bool initialized_{ false };
    D3D12RenderSystem* renderSystem_;

    Utils::ComPtr<IDXGIFactory4> dxgiFactory_;
    Utils::ComPtr<IDXGISwapChain> swapChain_;
    Utils::ComPtr<ID3D12Device> device_;

    Utils::ComPtr<ID3D12Fence> fence_;
    std::uint64_t currentFence_{ 0 };

    Utils::ComPtr<ID3D12CommandQueue> cmdQueue_;
    Utils::ComPtr<ID3D12CommandAllocator> directCmdListAlloc_;
    Utils::ComPtr<ID3D12GraphicsCommandList> cmdList_;

    static constexpr int SwapChainBufferCount = 2;
    int currentBackBuffer{ 0 };
    Utils::ComPtr<ID3D12Resource> swapChainBuffer_[SwapChainBufferCount];
    Utils::ComPtr<ID3D12Resource> depthStencilBuffer_;

    Utils::ComPtr<ID3D12DescriptorHeap> rtvHeap_;
    Utils::ComPtr<ID3D12DescriptorHeap> dsvHeap_;

    std::uint32_t m4xMsaaQuality_{ 0 };
    D3D12_VIEWPORT screenViewport_;
    D3D12_RECT scissorRect_;

    std::uint32_t rtvDescriptorSize_{ 0 };
    std::uint32_t dsvDescriptorSize_{ 0 };
    std::uint32_t cbvSrcDescriptorSize_{ 0 };
};
}  // namespace Cowdia::Rendering

#endif  // D3D12RS_RENDERER_HPP
