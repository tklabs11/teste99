#include "spore_d3d9_bridge.h"

#include <SDL_log.h>

HRESULT CreateSporeDxvkDevice(
    SDL_Window* sdl_window,
    UINT adapter,
    D3DDEVTYPE device_type,
    DWORD behavior_flags,
    D3DPRESENT_PARAMETERS* presentation_parameters,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out) {
    if (d3d9_out == nullptr || device_out == nullptr) {
        return D3DERR_INVALIDCALL;
    }

    *d3d9_out = nullptr;
    *device_out = nullptr;

    if (sdl_window == nullptr || presentation_parameters == nullptr) {
        return D3DERR_INVALIDCALL;
    }

    if (presentation_parameters->BackBufferWidth == 0) {
        presentation_parameters->BackBufferWidth = 1;
    }
    if (presentation_parameters->BackBufferHeight == 0) {
        presentation_parameters->BackBufferHeight = 1;
    }

    const HWND sdl_window_handle = reinterpret_cast<HWND>(sdl_window);
    presentation_parameters->hDeviceWindow = sdl_window_handle;

    SDL_Log(
        "D3D9_CALL CreateDevice input adapter=%u device-type=%u "
        "behavior=0x%08x window-handle-present=%u backbuffer=%ux%u "
        "format=%u count=%u multisample=%u quality=%u swap=%u "
        "windowed=%u depth-stencil=%u depth-format=%u flags=0x%08x "
        "refresh=%u interval=%u",
        adapter,
        static_cast<unsigned int>(device_type),
        behavior_flags,
        sdl_window_handle != nullptr,
        presentation_parameters->BackBufferWidth,
        presentation_parameters->BackBufferHeight,
        static_cast<unsigned int>(presentation_parameters->BackBufferFormat),
        presentation_parameters->BackBufferCount,
        static_cast<unsigned int>(presentation_parameters->MultiSampleType),
        presentation_parameters->MultiSampleQuality,
        static_cast<unsigned int>(presentation_parameters->SwapEffect),
        presentation_parameters->Windowed,
        presentation_parameters->EnableAutoDepthStencil,
        static_cast<unsigned int>(
            presentation_parameters->AutoDepthStencilFormat),
        presentation_parameters->Flags,
        presentation_parameters->FullScreen_RefreshRateInHz,
        presentation_parameters->PresentationInterval);

    IDirect3D9* d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
    if (d3d9 == nullptr) {
        SDL_LogError(
            SDL_LOG_CATEGORY_VIDEO,
            "Direct3DCreate9 returned null while creating the Spore device");
        return D3DERR_NOTAVAILABLE;
    }

    const HRESULT result = d3d9->CreateDevice(
        adapter,
        device_type,
        sdl_window_handle,
        behavior_flags,
        presentation_parameters,
        device_out);
    if (FAILED(result) || *device_out == nullptr) {
        if (*device_out != nullptr) {
            (*device_out)->Release();
            *device_out = nullptr;
        }
        d3d9->Release();
        SDL_LogError(
            SDL_LOG_CATEGORY_VIDEO,
            "DXVK-native CreateDevice failed: HRESULT 0x%08x",
            static_cast<unsigned int>(result));
        return FAILED(result) ? result : D3DERR_NOTAVAILABLE;
    }

    *d3d9_out = d3d9;
    return result;
}
