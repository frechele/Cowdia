#ifndef D3D12RS_COMMON_HPP
#define D3D12RS_COMMON_HPP

#ifdef COWDIA_PLATFORM_WIN32
#define COWDIA_D3D12_API __declspec(dllexport)
#else
#define COWDIA_D3D12_API
#endif

#endif  // D3D12RS_COMMON_HPP
