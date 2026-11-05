#include <SDL.h>
#include <SDL_vulkan.h>

#include <d3d9.h>

#include <cstdint>

#include "spore_d3d9_bridge.h"
#include "spore_translated_graphics.h"

namespace {

void ReleaseD3D9(
    IDirect3DDevice9* device,
    IDirect3D9* d3d9,
    SporeGuestMemory32* guest_memory = nullptr,
    SporeNativeDeviceRegistry* device_registry = nullptr) {
    if (guest_memory != nullptr && device_registry != nullptr) {
        std::uint32_t guest_device_token = 0;
        if (guest_memory->Read32(
                kSporeGuestD3DDeviceGlobalAddress, &guest_device_token)
                && guest_device_token != 0) {
            std::uint32_t invalidated_token = 0;
            if (!SporeTranslatedReleaseDeviceGlobal(
                    guest_memory, device_registry, &invalidated_token)) {
                SDL_LogError(
                    SDL_LOG_CATEGORY_APPLICATION,
                    "Could not invalidate guest device token 0x%08x",
                    guest_device_token);
            }
        }
        device_registry->InvalidateAll();
        guest_memory->Write32(kSporeGuestD3DDeviceGlobalAddress, 0);
    }
    if (device != nullptr) {
        device->Release();
    }
    if (d3d9 != nullptr) {
        d3d9->Release();
    }
}

}

namespace {

enum class D3D9TestMode {
    bridge_regression,
    manual_graphics_probe,
    translated_window_global,
    translated_device_global
};

int RunD3D9TestImpl(D3D9TestMode mode) {
    const bool translated_graphics = mode != D3D9TestMode::bridge_regression;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init: %s", SDL_GetError());
        return 1;
    }

    char* cachePath = SDL_GetPrefPath("SporePort", "DXVK");
    if (cachePath == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_GetPrefPath: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    if (SDL_setenv("DXVK_STATE_CACHE_PATH", cachePath, 1) != 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Could not set DXVK_STATE_CACHE_PATH: %s",
            SDL_GetError());
        SDL_free(cachePath);
        SDL_Quit();
        return 1;
    }
    SDL_Log("DXVK state cache path: %s", cachePath);
    SDL_free(cachePath);

    SDL_Window* window = SDL_CreateWindow(
        "Spore ARM64 - DXVK-native D3D9",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        0,
        0,
        SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN
                | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int width = 0;
    int height = 0;
    SDL_Vulkan_GetDrawableSize(window, &width, &height);
    if (width <= 0 || height <= 0) {
        SDL_GetWindowSize(window, &width, &height);
    }

    D3DPRESENT_PARAMETERS parameters{};
    parameters.BackBufferWidth = static_cast<UINT>(width);
    parameters.BackBufferHeight = static_cast<UINT>(height);
    parameters.BackBufferFormat = D3DFMT_UNKNOWN;
    parameters.BackBufferCount = 1;
    parameters.MultiSampleType = D3DMULTISAMPLE_NONE;
    parameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
    parameters.hDeviceWindow = reinterpret_cast<HWND>(window);
    parameters.Windowed = TRUE;
    parameters.EnableAutoDepthStencil = FALSE;
    parameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

    IDirect3D9* d3d9 = nullptr;
    IDirect3DDevice9* device = nullptr;
    SporeGuestD3D9State32 guest_graphics_state{};
    SporeGuestMemory32 guest_memory;
    SporeNativeDeviceRegistry device_registry;
    SporeGuestFrameOwner32 guest_frame_owner{};
    HRESULT createResult;
    if (mode == D3D9TestMode::manual_graphics_probe) {
        guest_memory.Clear();
        SporePrepareTranslatedGraphicsProbe(&guest_graphics_state);
        SDL_Log(
            "TRANSLATED_STAGE mode=manual-regression prepared=PASS "
            "(manual pre-boot state; "
            "640x480 from FUN_007e7380)");
        createResult = SporeTranslatedCreateDevice(
            &guest_graphics_state, window, &parameters, &d3d9, &device);
        if (SUCCEEDED(createResult) && device != nullptr
                && !SporeTranslatedRegisterDeviceGlobal(
                    &guest_memory,
                    &device_registry,
                    guest_graphics_state.device_token,
                    device)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Could not register the manually probed guest device");
            device->Release();
            device = nullptr;
            if (d3d9 != nullptr) {
                d3d9->Release();
                d3d9 = nullptr;
            }
            createResult = D3DERR_INVALIDCALL;
        }
    } else if (mode == D3D9TestMode::translated_window_global
            || mode == D3D9TestMode::translated_device_global) {
        SporePrepareTranslatedWindowGlobalProbe(
            &guest_graphics_state, &guest_memory);
        const bool track_device_global =
            mode == D3D9TestMode::translated_device_global;
        if (track_device_global) {
            SDL_Log(
                "TRANSLATED_STAGE mode=device-global prepared=PASS "
                "device-window-param=0 guest-window-global=0 "
                "guest-device-global=0 manual-window-token=0x%08x "
                "backbuffer-before-width-copy=%ux%u",
                guest_graphics_state.window_token,
                guest_graphics_state.presentation.back_buffer_width,
                guest_graphics_state.presentation.back_buffer_height);
            if (!SporeTranslatedSetCreateDeviceBackBufferWidth(
                    &guest_graphics_state, 480)
                    || guest_graphics_state.presentation.back_buffer_width != 480
                    || guest_graphics_state.presentation.back_buffer_height != 480) {
                SDL_LogError(
                    SDL_LOG_CATEGORY_APPLICATION,
                    "Translated FUN_0075f030 backbuffer width was not applied");
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 1;
            }
        } else {
            SDL_Log(
                "TRANSLATED_STAGE mode=window-global prepared=PASS "
                "device-window-param=0 guest-global=0 manual-window-token=0x%08x",
                guest_graphics_state.window_token);
        }
        std::uint32_t initial_window_token = 0;
        std::uint32_t initial_device_token = 0;
        if (guest_graphics_state.presentation.device_window_token != 0
                || !guest_memory.Read32(
                    kSporeGuestDeviceWindowGlobalAddress, &initial_window_token)
                || !guest_memory.Read32(
                    kSporeGuestD3DDeviceGlobalAddress, &initial_device_token)
                || initial_window_token != 0 || initial_device_token != 0
                || !SporeTranslatedSetDeviceWindowGlobal(
                    &guest_memory, guest_graphics_state.window_token)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Translated FUN_011f8110 rejected the guest window token");
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
        std::uint32_t stored_window_token = 0;
        if (!guest_memory.Read32(
                kSporeGuestDeviceWindowGlobalAddress, &stored_window_token)
                || stored_window_token != guest_graphics_state.window_token) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Translated FUN_011f8110 did not store the window token");
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
        SDL_Log(
            "TRANSLATED_STAGE global-window=PASS address=0x%08x",
            kSporeGuestDeviceWindowGlobalAddress);
        createResult = SporeTranslatedCreateDeviceWithGlobals(
            &guest_graphics_state,
            &guest_memory,
            &device_registry,
            window,
            &parameters,
            &d3d9,
            &device);
    } else {
        createResult = CreateSporeDxvkDevice(
            window,
            D3DADAPTER_DEFAULT,
            D3DDEVTYPE_HAL,
            D3DCREATE_HARDWARE_VERTEXPROCESSING,
            &parameters,
            &d3d9,
            &device);
    }
    if (FAILED(createResult) || device == nullptr) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "IDirect3D9::CreateDevice failed: 0x%08x",
            static_cast<unsigned int>(static_cast<uint32_t>(createResult)));
        ReleaseD3D9(
            device,
            d3d9,
            translated_graphics ? &guest_memory : nullptr,
            translated_graphics ? &device_registry : nullptr);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    std::uint32_t registered_device_token = 0;
    if (translated_graphics
            && (!guest_memory.Read32(
                    kSporeGuestD3DDeviceGlobalAddress, &registered_device_token)
                || registered_device_token == 0
                || registered_device_token != guest_graphics_state.device_token)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Translated device global does not match the created guest device");
        ReleaseD3D9(
            device,
            d3d9,
            &guest_memory,
            &device_registry);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    if (mode == D3D9TestMode::translated_device_global) {
        const std::uint64_t dispatch_count_before_rejections =
            device_registry.PresentDispatchCount();
        if (!guest_memory.Write32(kSporeGuestD3DDeviceGlobalAddress, 0)
                || SporeTranslatedPresentFromDeviceGlobal(
                    &guest_memory, &device_registry, &guest_frame_owner)
                    != D3DERR_INVALIDCALL
                || device_registry.PresentDispatchCount()
                    != dispatch_count_before_rejections) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Zero guest device token was not rejected");
            ReleaseD3D9(device, d3d9, &guest_memory, &device_registry);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
        SDL_Log(
            "TRANSLATED_STAGE invalid-device-token=zero rejected=PASS "
            "device-dispatches=0");
        if (!guest_memory.Write32(
                kSporeGuestD3DDeviceGlobalAddress, 0xdeadbeef)
                || SporeTranslatedPresentFromDeviceGlobal(
                    &guest_memory, &device_registry, &guest_frame_owner)
                    != D3DERR_INVALIDCALL
                || device_registry.PresentDispatchCount()
                    != dispatch_count_before_rejections) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Unknown guest device token was not rejected");
            ReleaseD3D9(device, d3d9, &guest_memory, &device_registry);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
        SDL_Log(
            "TRANSLATED_STAGE invalid-device-token=unknown "
            "rejected=PASS device-dispatches=0");
        if (!guest_memory.Write32(
                kSporeGuestD3DDeviceGlobalAddress, registered_device_token)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Could not restore the registered guest device token");
            ReleaseD3D9(device, d3d9, &guest_memory, &device_registry);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
    }

    SDL_Log("DXVK-native D3D9 device created (%dx%d)", width, height);
    bool running = true;
    Uint32 frame = 0;
    bool translated_present_reported = false;
    int result = 0;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT
                    || (event.type == SDL_KEYDOWN
                        && (event.key.keysym.sym == SDLK_ESCAPE
                            || event.key.keysym.sym == SDLK_AC_BACK))) {
                running = false;
            }

            if (event.type == SDL_WINDOWEVENT
                    && (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED
                        || event.window.event == SDL_WINDOWEVENT_RESIZED)) {
                int newWidth = 0;
                int newHeight = 0;
                SDL_Vulkan_GetDrawableSize(window, &newWidth, &newHeight);
                if (newWidth <= 0 || newHeight <= 0
                        || (static_cast<UINT>(newWidth) == parameters.BackBufferWidth
                            && static_cast<UINT>(newHeight)
                                == parameters.BackBufferHeight)) {
                    continue;
                }

                parameters.BackBufferWidth = static_cast<UINT>(newWidth);
                parameters.BackBufferHeight = static_cast<UINT>(newHeight);
                const HRESULT resetResult = device->Reset(&parameters);
                if (FAILED(resetResult)) {
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "IDirect3DDevice9::Reset failed after resize: 0x%08x",
                        static_cast<unsigned int>(
                            static_cast<uint32_t>(resetResult)));
                    result = 1;
                    running = false;
                } else {
                    SDL_Log(
                        "DXVK-native D3D9 device resized (%dx%d)",
                        newWidth,
                        newHeight);
                }
            }
        }

        if (!running) {
            break;
        }

        const Uint32 phase = (frame++ / 4) % 96;
        const D3DCOLOR color = D3DCOLOR_XRGB(24 + phase, 112, 184);
        const HRESULT clearResult = device->Clear(
            0, nullptr, D3DCLEAR_TARGET, color, 1.0f, 0);
        if (FAILED(clearResult)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "IDirect3DDevice9::Clear failed: 0x%08x",
                static_cast<unsigned int>(static_cast<uint32_t>(clearResult)));
            result = 1;
            break;
        }

        const HRESULT presentResult = translated_graphics
            ? SporeTranslatedPresentFromDeviceGlobal(
                &guest_memory, &device_registry, &guest_frame_owner)
            : device->Present(nullptr, nullptr, nullptr, nullptr);
        if (FAILED(presentResult)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "IDirect3DDevice9::Present failed: 0x%08x",
                static_cast<unsigned int>(static_cast<uint32_t>(presentResult)));
            result = 1;
            break;
        }
        if (mode == D3D9TestMode::translated_device_global
                && !translated_present_reported) {
            SDL_Log(
                "TRANSLATED_STAGE FUN_011f8120 device-global=PASS "
                "address=0x%08x guest-device=0x%08x",
                kSporeGuestD3DDeviceGlobalAddress,
                registered_device_token);
        }
        if (translated_graphics && !translated_present_reported) {
            SDL_Log("TRANSLATED_STAGE present=PASS");
            translated_present_reported = true;
        }
    }

    if (mode == D3D9TestMode::translated_device_global) {
        std::uint32_t invalidated_token = 0;
        const std::uint64_t dispatch_count_before_invalidation =
            device_registry.PresentDispatchCount();
        if (dispatch_count_before_invalidation == 0
                || !SporeTranslatedReleaseDeviceGlobal(
                    &guest_memory, &device_registry, &invalidated_token)
                || invalidated_token != registered_device_token
                || SporeTranslatedPresentFromDeviceGlobal(
                    &guest_memory, &device_registry, &guest_frame_owner)
                    != D3DERR_INVALIDCALL
                || device_registry.Present(
                    invalidated_token, &guest_frame_owner)
                    != D3DERR_INVALIDCALL
                || device_registry.PresentDispatchCount()
                    != dispatch_count_before_invalidation) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Invalidated guest device token remained usable");
            result = 1;
        } else {
            SDL_Log(
                "TRANSLATED_STAGE invalid-device-token=invalidated "
                "rejected=PASS guest-device=0x%08x device-dispatches=%llu",
                invalidated_token,
                static_cast<unsigned long long>(
                    dispatch_count_before_invalidation));
        }
        guest_graphics_state.device_token = 0;
    }
    ReleaseD3D9(
        device,
        d3d9,
        translated_graphics ? &guest_memory : nullptr,
        translated_graphics ? &device_registry : nullptr);
    SDL_DestroyWindow(window);
    SDL_Quit();
    SDL_Log("DXVK-native D3D9 test stopped");
    return result;
}

}

int RunD3D9Test() {
    return RunD3D9TestImpl(D3D9TestMode::bridge_regression);
}

int RunTranslatedGraphicsTest() {
    return RunD3D9TestImpl(D3D9TestMode::manual_graphics_probe);
}

int RunTranslatedWindowGlobalGraphicsTest() {
    return RunD3D9TestImpl(D3D9TestMode::translated_window_global);
}

int RunTranslatedDeviceGlobalGraphicsTest() {
    return RunD3D9TestImpl(D3D9TestMode::translated_device_global);
}
