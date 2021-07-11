#ifndef D3D12RS_RENDERER_HPP
#define D3D12RS_RENDERER_HPP

#include "D3D12Common.hpp"

#include <Cowdia/Rendering/Renderer.hpp>
#include "D3D12RenderSystem.hpp"

#include <cstdint>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <d3d12.h>

namespace Cowdia::Rendering
{
class COWDIA_D3D12_API D3D12Renderer final : public Renderer
{
 public:
    D3D12Renderer(D3D12RenderSystem* renderSystem);

    void Initialize() override;
    void Shutdown() override;

 private:
    void createCommandObjects();
    void createSwapChain();
    void createDescriptorHeaps();
    void createDepthStencilBuffer();

    void resetViewportAndScissor();

 private:
    D3D12RenderSystem* renderSystem_;

    Core::ComPtr<IDXGIFactory4> dxgiFactory_;
    Core::ComPtr<IDXGISwapChain> swapChain_;
    Core::ComPtr<ID3D12Device> device_;

    Core::ComPtr<ID3D12Fence> fence_;
    std::uint64_t currentFence_{ 0 };

    Core::ComPtr<ID3D12CommandQueue> cmdQueue_;
    Core::ComPtr<ID3D12CommandAllocator> directCmdListAlloc_;
    Core::ComPtr<ID3D12GraphicsCommandList> cmdList_;

    static constexpr int SwapChainBufferCount = 2;
    int currentBackBuffer{ 0 };
    Core::ComPtr<ID3D12Resource> swapChainBuffer_[SwapChainBufferCount];
    Core::ComPtr<ID3D12Resource> depthStencilBuffer_;

    Core::ComPtr<ID3D12DescriptorHeap> rtvHeap_;
    Core::ComPtr<ID3D12DescriptorHeap> dsvHeap_;

    std::uint32_t m4xMsaaQuality_{ 0 };
    D3D12_VIEWPORT screenViewport_;
    D3D12_RECT scissorRect_;

    std::uint32_t rtvDescriptorSize_{ 0 };
    std::uint32_t dsvDescriptorSize_{ 0 };
    std::uint32_t cbvSrcDescriptorSize_{ 0 };
};
}  // namespace Cowdia::Rendering

#endif  // D3D12RS_RENDERER_HPP
