#include "D3D12Renderer.hpp"

#include "D3D12RenderWindow.hpp"

#include <stdexcept>

namespace Cowdia::Rendering
{
D3D12Renderer::D3D12Renderer(D3D12RenderSystem* renderSystem)
    : renderSystem_(renderSystem)
{
    memset(&screenViewport_, 0, sizeof(screenViewport_));
    memset(&scissorRect_, 0, sizeof(scissorRect_));
}

void D3D12Renderer::Initialize()
{
    // 0. Create DXGI factory.
    if (FAILED(CreateDXGIFactory1(
            __uuidof(IDXGIFactory4),
            reinterpret_cast<void**>(dxgiFactory_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateDXGIFactory1");
    }

    // 1. Create D3D12 device;
    if (FAILED(D3D12CreateDevice(
            nullptr, D3D_FEATURE_LEVEL_12_0, __uuidof(ID3D12Device),
            reinterpret_cast<void**>(device_.GetAddressOf()))))
    {
        Utils::ComPtr<IDXGIAdapter> warpAdapter;
        if (FAILED(dxgiFactory_->EnumWarpAdapter(
                __uuidof(IDXGIAdapter),
                reinterpret_cast<void**>(warpAdapter.GetAddressOf()))))
        {
            throw std::runtime_error("EnumWarpAdapter");
        }

        if (FAILED(D3D12CreateDevice(
                warpAdapter.Get(), D3D_FEATURE_LEVEL_12_0,
                __uuidof(ID3D12Device),
                reinterpret_cast<void**>(device_.GetAddressOf()))))
        {
            throw std::runtime_error("D3D12CreateDevice");
        }
    }

    // 2. Create fence.
    if (FAILED(device_->CreateFence(
            0, D3D12_FENCE_FLAG_NONE, __uuidof(ID3D12Fence),
            reinterpret_cast<void**>(fence_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateFence");
    }

    rtvDescriptorSize_ = device_->GetDescriptorHandleIncrementSize(
        D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    dsvDescriptorSize_ = device_->GetDescriptorHandleIncrementSize(
        D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
    cbvSrcDescriptorSize_ = device_->GetDescriptorHandleIncrementSize(
        D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

    // 3. Check 4x MSAA supporting.
    D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS msQualityLevels;
    msQualityLevels.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    msQualityLevels.SampleCount = 4;
    msQualityLevels.Flags = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;
    msQualityLevels.NumQualityLevels = 0;
    if (FAILED(device_->CheckFeatureSupport(
            D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &msQualityLevels,
            sizeof(msQualityLevels))))
    {
        throw std::runtime_error("CheckFeatureSupport");
    }

    m4xMsaaQuality_ = msQualityLevels.NumQualityLevels;
    if (m4xMsaaQuality_ <= 0)
    {
        throw std::runtime_error("Unexpected MSAA quality level");
    }

    // 4. Create command queue
    createCommandObjects();

    // 5. Create swap chain.
    createSwapChain();

    // 6. Create descriptor heaps.
    createDescriptorHeaps();

    // 7. Create depth stencil buffer.
    createDepthStencilBuffer();

    // 8. Create viewport and scissor.
    resetViewportAndScissor();
}

void D3D12Renderer::Shutdown()
{
    flushCommandQueue();

    depthStencilBuffer_.Reset();

    for (auto& buffer : swapChainBuffer_)
        buffer.Reset();

    dsvHeap_.Reset();
    rtvHeap_.Reset();

    cmdList_.Reset();
    directCmdListAlloc_.Reset();
    cmdQueue_.Reset();

    fence_.Reset();

    device_.Reset();
    swapChain_.Reset();
    dxgiFactory_.Reset();
}

void D3D12Renderer::createCommandObjects()
{
    D3D12_COMMAND_QUEUE_DESC cmdQueueDesc;
    memset(&cmdQueueDesc, 0, sizeof(cmdQueueDesc));
    cmdQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    cmdQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

    if (FAILED(device_->CreateCommandQueue(
            &cmdQueueDesc, __uuidof(ID3D12CommandQueue),
            reinterpret_cast<void**>(cmdQueue_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateCommandQeueue");
    }

    if (FAILED(device_->CreateCommandAllocator(
            D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator),
            reinterpret_cast<void**>(directCmdListAlloc_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateCommandAllocator");
    }

    if (FAILED(device_->CreateCommandList(
            0, D3D12_COMMAND_LIST_TYPE_DIRECT, directCmdListAlloc_.Get(),
            nullptr, __uuidof(ID3D12GraphicsCommandList),
            reinterpret_cast<void**>(cmdList_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateCommandList");
    }

    cmdList_->Close();
}

void D3D12Renderer::createSwapChain()
{
    const D3D12RenderWindow* window =
        static_cast<D3D12RenderWindow*>(renderSystem_->GetRenderWindow());

    swapChain_.Reset();

    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    swapChainDesc.BufferDesc.Width = window->GetWidth();
    swapChainDesc.BufferDesc.Height = window->GetHeight();
    swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.ScanlineOrdering =
        DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    swapChainDesc.SampleDesc.Count = 4;
    swapChainDesc.SampleDesc.Quality = m4xMsaaQuality_ - 1;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount = SwapChainBufferCount;
    swapChainDesc.OutputWindow = window->GetHWND();
    swapChainDesc.Windowed = !window->IsFullscreen();
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    if (FAILED(dxgiFactory_->CreateSwapChain(cmdQueue_.Get(), &swapChainDesc,
                                             swapChain_.GetAddressOf())))
    {
        throw std::runtime_error("CreateSwapChain");
    }
}

void D3D12Renderer::createDescriptorHeaps()
{
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc;
    rtvHeapDesc.NumDescriptors = SwapChainBufferCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    rtvHeapDesc.NodeMask = 0;

    if (FAILED(device_->CreateDescriptorHeap(
            &rtvHeapDesc, __uuidof(ID3D12DescriptorHeap),
            reinterpret_cast<void**>(rtvHeap_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateDescriptorHeap of RTV");
    }

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHeapHandle =
        rtvHeap_->GetCPUDescriptorHandleForHeapStart();
    for (std::uint32_t i = 0; i < SwapChainBufferCount; ++i)
    {
        if (FAILED(swapChain_->GetBuffer(
                i, __uuidof(ID3D12Resource),
                reinterpret_cast<void**>(swapChainBuffer_[i].GetAddressOf()))))
        {
            throw std::runtime_error("GetBuffer");
        }

        device_->CreateRenderTargetView(swapChainBuffer_[i].Get(), nullptr,
                                        rtvHeapHandle);

        rtvHeapHandle.ptr += rtvDescriptorSize_;
    }

    D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc;
    dsvHeapDesc.NumDescriptors = 1;
    dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    dsvHeapDesc.NodeMask = 0;
    if (FAILED(device_->CreateDescriptorHeap(
            &dsvHeapDesc, __uuidof(ID3D12DescriptorHeap),
            reinterpret_cast<void**>(dsvHeap_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateDescriptorHeap of DSV");
    }
}

void D3D12Renderer::createDepthStencilBuffer()
{
    const D3D12RenderWindow* window =
        static_cast<D3D12RenderWindow*>(renderSystem_->GetRenderWindow());

    D3D12_RESOURCE_DESC depthStencilDesc;
    depthStencilDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    depthStencilDesc.Alignment = 0;
    depthStencilDesc.Width = window->GetWidth();
    depthStencilDesc.Height = window->GetHeight();
    depthStencilDesc.DepthOrArraySize = 1;
    depthStencilDesc.MipLevels = 1;
    depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthStencilDesc.SampleDesc.Count = 4;
    depthStencilDesc.SampleDesc.Quality = m4xMsaaQuality_ - 1;
    depthStencilDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    depthStencilDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

    D3D12_CLEAR_VALUE optClear;
    optClear.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    optClear.DepthStencil.Depth = 1.0f;
    optClear.DepthStencil.Stencil = 0;

    D3D12_HEAP_PROPERTIES heapProperty;
    heapProperty.Type = D3D12_HEAP_TYPE_DEFAULT;
    heapProperty.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heapProperty.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    heapProperty.CreationNodeMask = 1;
    heapProperty.VisibleNodeMask = 1;

    if (FAILED(device_->CreateCommittedResource(
            &heapProperty, D3D12_HEAP_FLAG_NONE, &depthStencilDesc,
            D3D12_RESOURCE_STATE_COMMON, &optClear, __uuidof(ID3D12Resource),
            reinterpret_cast<void**>(depthStencilBuffer_.GetAddressOf()))))
    {
        throw std::runtime_error("CreateCommittedResource");
    }

    device_->CreateDepthStencilView(depthStencilBuffer_.Get(), nullptr,
                                    dsvHeap_->GetCPUDescriptorHandleForHeapStart());

    D3D12_RESOURCE_BARRIER rscBarrier;
    memset(&rscBarrier, 0, sizeof(rscBarrier));
    rscBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    rscBarrier.Transition.pResource = depthStencilBuffer_.Get();
    rscBarrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COMMON;
    rscBarrier.Transition.StateAfter = D3D12_RESOURCE_STATE_DEPTH_WRITE;
    rscBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

    cmdList_->ResourceBarrier(1, &rscBarrier);
}

void D3D12Renderer::resetViewportAndScissor()
{
    const D3D12RenderWindow* window =
        static_cast<D3D12RenderWindow*>(renderSystem_->GetRenderWindow());

    const int clientWidth = window->GetWidth();
    const int clientHeight = window->GetHeight();

    screenViewport_.TopLeftX = 0;
    screenViewport_.TopLeftY = 0;
    screenViewport_.Width = static_cast<float>(clientWidth);
    screenViewport_.Height = static_cast<float>(clientHeight);
    screenViewport_.MinDepth = 0;
    screenViewport_.MaxDepth = 1;

    cmdList_->RSSetViewports(1, &screenViewport_);

    scissorRect_ = { 0, 0, clientWidth / 2, clientHeight / 2 };
    cmdList_->RSSetScissorRects(1, &scissorRect_);
}

void D3D12Renderer::flushCommandQueue()
{
    ++currentFence_;

    if (FAILED(cmdQueue_->Signal(fence_.Get(), currentFence_)))
    {
        throw std::runtime_error("Signal");
    }

    if (fence_->GetCompletedValue() < currentFence_)
    {
        HANDLE eventHandle =
            CreateEventEx(nullptr, false, false, EVENT_ALL_ACCESS);

        if (FAILED(fence_->SetEventOnCompletion(currentFence_, eventHandle)))
        {
            throw std::runtime_error("SetEventOnCompletion");
        }

        WaitForSingleObject(eventHandle, INFINITE);
        CloseHandle(eventHandle);
    }
}
}  // namespace Cowdia::Rendering
