#include "spore_translated_graphics.h"

#include <SDL_log.h>

#include <atomic>
#include <limits>

#include "spore_d3d9_bridge.h"
#include "spore_graphics_parameter_translation.h"

namespace {

constexpr std::uint32_t kGuestWindowToken = 0x00010001;
std::atomic<std::uint32_t> g_next_guest_device_token{0x00010002};

std::uint32_t allocateGuestDeviceToken() {
    std::uint32_t candidate = g_next_guest_device_token.load();
    while (candidate != 0) {
        const std::uint32_t next = candidate
                == std::numeric_limits<std::uint32_t>::max()
            ? 0
            : candidate + 1;
        if (g_next_guest_device_token.compare_exchange_weak(candidate, next)) {
            return candidate;
        }
    }
    return 0;
}

D3DPRESENT_PARAMETERS toHostPresentationParameters(
    const SporeGuestPresentParameters32& guest) {
    D3DPRESENT_PARAMETERS host{};
    host.BackBufferWidth = guest.back_buffer_width;
    host.BackBufferHeight = guest.back_buffer_height;
    host.BackBufferFormat = static_cast<D3DFORMAT>(guest.back_buffer_format);
    host.BackBufferCount = guest.back_buffer_count;
    host.MultiSampleType =
        static_cast<D3DMULTISAMPLE_TYPE>(guest.multi_sample_type);
    host.MultiSampleQuality = guest.multi_sample_quality;
    host.SwapEffect = static_cast<D3DSWAPEFFECT>(guest.swap_effect);
    host.Windowed = guest.windowed;
    host.EnableAutoDepthStencil = guest.enable_auto_depth_stencil;
    host.AutoDepthStencilFormat =
        static_cast<D3DFORMAT>(guest.auto_depth_stencil_format);
    host.Flags = guest.flags;
    host.FullScreen_RefreshRateInHz = guest.full_screen_refresh_rate;
    host.PresentationInterval = guest.presentation_interval;
    return host;
}

void prepareTranslatedGraphicsProbeState(
    SporeGuestD3D9State32* state,
    bool initialize_device_window_token) {
    *state = {};
    state->adapter_ordinal = D3DADAPTER_DEFAULT;
    state->device_type = D3DDEVTYPE_HAL;
    state->behavior_flags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    state->window_token = kGuestWindowToken;
    state->presentation.back_buffer_width = 640;
    state->presentation.back_buffer_height = 480;
    state->presentation.back_buffer_count = 1;
    state->presentation.multi_sample_type = D3DMULTISAMPLE_NONE;
    state->presentation.swap_effect = D3DSWAPEFFECT_DISCARD;
    state->presentation.presentation_interval = D3DPRESENT_INTERVAL_ONE;
    if (initialize_device_window_token) {
        state->presentation.device_window_token = kGuestWindowToken;
    }
}

}

bool SporeGuestMemory32::Read32(
    std::uint32_t address,
    std::uint32_t* value_out) const {
    if (value_out == nullptr) {
        return false;
    }

    switch (address) {
    case kSporeGuestDeviceWindowGlobalAddress:
        *value_out = device_window_token_;
        return true;
    case kSporeGuestD3DDeviceGlobalAddress:
        *value_out = d3d_device_token_;
        return true;
    default:
        return false;
    }
}

bool SporeGuestMemory32::Write32(std::uint32_t address, std::uint32_t value) {
    switch (address) {
    case kSporeGuestDeviceWindowGlobalAddress:
        device_window_token_ = value;
        return true;
    case kSporeGuestD3DDeviceGlobalAddress:
        d3d_device_token_ = value;
        return true;
    default:
        return false;
    }
}

void SporeGuestMemory32::Clear() {
    device_window_token_ = 0;
    d3d_device_token_ = 0;
}

SporeNativeDeviceRegistry::~SporeNativeDeviceRegistry() {
    InvalidateAll();
}

void SporeNativeDeviceRegistry::InvalidateAll() {
    IDirect3DDevice9* device = nullptr;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        device = device_;
        device_ = nullptr;
        guest_token_ = 0;
    }
    if (device != nullptr) {
        device->Release();
    }
}

bool SporeNativeDeviceRegistry::Register(
    IDirect3DDevice9* device,
    std::uint32_t* guest_token_out) {
    if (device == nullptr || guest_token_out == nullptr) {
        return false;
    }
    *guest_token_out = 0;

    std::lock_guard<std::mutex> lock(mutex_);
    if (device_ != nullptr) {
        return false;
    }

    const std::uint32_t guest_token = allocateGuestDeviceToken();
    if (guest_token == 0) {
        return false;
    }
    device->AddRef();
    guest_token_ = guest_token;
    device_ = device;
    *guest_token_out = guest_token;
    return true;
}

bool SporeNativeDeviceRegistry::Invalidate(std::uint32_t guest_token) {
    IDirect3DDevice9* device = nullptr;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (guest_token == 0 || guest_token_ != guest_token || device_ == nullptr) {
            return false;
        }
        device = device_;
        device_ = nullptr;
        guest_token_ = 0;
    }

    device->Release();
    return true;
}

HRESULT SporeNativeDeviceRegistry::Present(
    std::uint32_t guest_token,
    const SporeGuestFrameOwner32* frame_owner) const {
    if (guest_token == 0 || frame_owner == nullptr) {
        return D3DERR_INVALIDCALL;
    }
    if (frame_owner->alternate_presenter_token != 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Translated Present does not support guest alternate presenter "
            "token 0x%08x",
            frame_owner->alternate_presenter_token);
        return E_NOTIMPL;
    }

    std::lock_guard<std::mutex> lock(mutex_);
    if (guest_token_ != guest_token || device_ == nullptr) {
        return D3DERR_INVALIDCALL;
    }
    ++present_dispatch_count_;
    return device_->Present(nullptr, nullptr, nullptr, nullptr);
}

std::uint64_t SporeNativeDeviceRegistry::PresentDispatchCount() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return present_dispatch_count_;
}

void SporePrepareTranslatedGraphicsProbe(SporeGuestD3D9State32* state) {
    if (state == nullptr) {
        return;
    }

    prepareTranslatedGraphicsProbeState(state, true);
    state->presentation.windowed = TRUE;
}

void SporePrepareTranslatedWindowGlobalProbe(
    SporeGuestD3D9State32* state,
    SporeGuestMemory32* memory) {
    if (state == nullptr || memory == nullptr) {
        return;
    }

    prepareTranslatedGraphicsProbeState(state, false);
    memory->Clear();
}

bool SporeTranslatedSetDeviceWindowGlobal(
    SporeGuestMemory32* memory,
    std::uint32_t guest_window_token) {
    if (memory == nullptr || guest_window_token == 0) {
        return false;
    }

    return memory->Write32(
        kSporeGuestDeviceWindowGlobalAddress, guest_window_token);
}

bool SporeTranslatedSetCreateDeviceBackBufferDimensions(
    SporeGuestD3D9State32* state,
    std::uint32_t guest_width,
    std::uint32_t guest_height) {
    if (state == nullptr) {
        return false;
    }

    if (!SporeTranslatedCopyBackBufferDimensions(
            &state->presentation.back_buffer_width,
            &state->presentation.back_buffer_height,
            guest_width,
            guest_height)) {
        return false;
    }
    SDL_Log(
        "TRANSLATED_STAGE FUN_0075f030 backbuffer-dimensions=PASS "
        "width=%u height=%u",
        guest_width,
        guest_height);
    return true;
}

bool SporeTranslatedSetPresentationModeFields(
    SporeGuestD3D9State32* state) {
    if (state == nullptr
            || !SporeTranslatedSetPresentationModeFields(
                &state->original_setup_field_14,
                &state->presentation.back_buffer_format,
                &state->presentation.auto_depth_stencil_format)) {
        return false;
    }

    SDL_Log(
        "TRANSLATED_STAGE FUN_0075f030 presentation-mode=PASS "
        "setup-field-14=0x%08x format=%u depth-format=%u",
        state->original_setup_field_14,
        state->presentation.back_buffer_format,
        state->presentation.auto_depth_stencil_format);
    return true;
}

SporeGuestConfigBooleanLookupStatus SporeTranslatedSetWindowedFromConfig(
    SporeGuestD3D9State32* state,
    const SporeGuestConfigBooleanFixtureView& config,
    std::uint32_t key,
    bool* query_value_out) {
    if (state == nullptr || query_value_out == nullptr) {
        return SporeGuestConfigBooleanLookupStatus::invalid_fixture;
    }

    bool query_value = false;
    const SporeGuestConfigBooleanLookupStatus status =
        SporeTranslatedLookupConfigBoolean(config, key, &query_value);
    if (status == SporeGuestConfigBooleanLookupStatus::not_initialized
            || status == SporeGuestConfigBooleanLookupStatus::invalid_fixture) {
        return status;
    }

    *query_value_out = query_value;
    state->presentation.windowed = query_value ? TRUE : FALSE;
    return status;
}

HRESULT SporeTranslatedCreateDevice(
    SporeGuestD3D9State32* state,
    SDL_Window* window,
    D3DPRESENT_PARAMETERS* host_presentation_out,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out) {
    if (d3d9_out != nullptr) {
        *d3d9_out = nullptr;
    }
    if (device_out != nullptr) {
        *device_out = nullptr;
    }
    if (state == nullptr || window == nullptr || host_presentation_out == nullptr
            || d3d9_out == nullptr || device_out == nullptr
            || state->window_token == 0
            || state->presentation.device_window_token != state->window_token) {
        return D3DERR_INVALIDCALL;
    }

    state->device_token = 0;
    D3DPRESENT_PARAMETERS host_parameters =
        toHostPresentationParameters(state->presentation);
    SDL_Log(
        "TRANSLATED_STAGE create-device-input adapter=%u device-type=%u "
        "behavior=0x%08x window-token=0x%08x backbuffer=%ux%u "
        "format=%u count=%u multisample=%u quality=%u swap=%u "
        "windowed=%u depth-stencil=%u depth-format=%u flags=0x%08x "
        "refresh=%u interval=%u",
        state->adapter_ordinal,
        state->device_type,
        state->behavior_flags,
        state->presentation.device_window_token,
        host_parameters.BackBufferWidth,
        host_parameters.BackBufferHeight,
        static_cast<unsigned int>(host_parameters.BackBufferFormat),
        host_parameters.BackBufferCount,
        static_cast<unsigned int>(host_parameters.MultiSampleType),
        host_parameters.MultiSampleQuality,
        static_cast<unsigned int>(host_parameters.SwapEffect),
        host_parameters.Windowed,
        host_parameters.EnableAutoDepthStencil,
        static_cast<unsigned int>(host_parameters.AutoDepthStencilFormat),
        host_parameters.Flags,
        host_parameters.FullScreen_RefreshRateInHz,
        host_parameters.PresentationInterval);
    const HRESULT result = CreateSporeDxvkDevice(
        window,
        state->adapter_ordinal,
        static_cast<D3DDEVTYPE>(state->device_type),
        state->behavior_flags,
        &host_parameters,
        d3d9_out,
        device_out);
    if (SUCCEEDED(result) && *device_out != nullptr) {
        *host_presentation_out = host_parameters;
        SDL_Log(
            "TRANSLATED_STAGE create-device=PASS result=0x%08x "
            "guest-window=0x%08x guest-device=unregistered backbuffer=%ux%u",
            static_cast<unsigned int>(result),
            state->window_token,
            host_parameters.BackBufferWidth,
            host_parameters.BackBufferHeight);
    } else {
        SDL_Log(
            "TRANSLATED_STAGE create-device=FAIL result=0x%08x "
            "backbuffer=%ux%u",
            static_cast<unsigned int>(result),
            host_parameters.BackBufferWidth,
            host_parameters.BackBufferHeight);
    }
    return result;
}

bool SporeTranslatedRegisterDeviceGlobal(
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    std::uint32_t* guest_device_token_out,
    IDirect3DDevice9* host_device) {
    if (memory == nullptr || device_registry == nullptr
            || guest_device_token_out == nullptr || host_device == nullptr) {
        return false;
    }
    *guest_device_token_out = 0;
    std::uint32_t guest_device_token = 0;
    if (!device_registry->Register(host_device, &guest_device_token)) {
        return false;
    }
    if (!memory->Write32(kSporeGuestD3DDeviceGlobalAddress, guest_device_token)) {
        device_registry->Invalidate(guest_device_token);
        return false;
    }

    *guest_device_token_out = guest_device_token;
    SDL_Log(
        "TRANSLATED_STAGE FUN_011f8680 device-global=PASS "
        "address=0x%08x guest-device=0x%08x",
        kSporeGuestD3DDeviceGlobalAddress,
        guest_device_token);
    return true;
}

HRESULT SporeTranslatedCreateDeviceWithGlobals(
    SporeGuestD3D9State32* state,
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    SDL_Window* window,
    D3DPRESENT_PARAMETERS* host_presentation_out,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out) {
    if (state == nullptr || memory == nullptr || device_registry == nullptr
            || host_presentation_out == nullptr || d3d9_out == nullptr
            || device_out == nullptr) {
        return D3DERR_INVALIDCALL;
    }

    std::uint32_t existing_device_token = 0;
    if (!memory->Read32(
            kSporeGuestD3DDeviceGlobalAddress, &existing_device_token)
            || existing_device_token != 0) {
        return D3DERR_INVALIDCALL;
    }

    std::uint32_t guest_window_token = 0;
    if (!memory->Read32(
            kSporeGuestDeviceWindowGlobalAddress, &guest_window_token)
            || guest_window_token == 0) {
        return D3DERR_INVALIDCALL;
    }

    SDL_Log(
        "TRANSLATED_STAGE FUN_011f8110 global=0x%08x window-token=0x%08x",
        kSporeGuestDeviceWindowGlobalAddress,
        guest_window_token);
    state->presentation.device_window_token = guest_window_token;
    state->device_token = 0;
    const HRESULT result = SporeTranslatedCreateDevice(
        state,
        window,
        host_presentation_out,
        d3d9_out,
        device_out);
    if (FAILED(result) || *device_out == nullptr) {
        return FAILED(result) ? result : D3DERR_NOTAVAILABLE;
    }

    if (!SporeTranslatedRegisterDeviceGlobal(
            memory, device_registry, &state->device_token, *device_out)) {
        (*device_out)->Release();
        *device_out = nullptr;
        if (*d3d9_out != nullptr) {
            (*d3d9_out)->Release();
            *d3d9_out = nullptr;
        }
        state->device_token = 0;
        return D3DERR_INVALIDCALL;
    }
    return result;
}

HRESULT SporeTranslatedPresentFromDeviceGlobal(
    const SporeGuestMemory32* memory,
    const SporeNativeDeviceRegistry* device_registry,
    const SporeGuestFrameOwner32* frame_owner) {
    if (memory == nullptr || device_registry == nullptr || frame_owner == nullptr) {
        return D3DERR_INVALIDCALL;
    }

    std::uint32_t guest_device_token = 0;
    if (!memory->Read32(
            kSporeGuestD3DDeviceGlobalAddress, &guest_device_token)) {
        return D3DERR_INVALIDCALL;
    }
    return device_registry->Present(guest_device_token, frame_owner);
}

bool SporeTranslatedReleaseDeviceGlobal(
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    std::uint32_t* invalidated_token_out) {
    if (memory == nullptr || device_registry == nullptr
            || invalidated_token_out == nullptr) {
        return false;
    }

    std::uint32_t guest_device_token = 0;
    if (!memory->Read32(
            kSporeGuestD3DDeviceGlobalAddress, &guest_device_token)
            || guest_device_token == 0) {
        return false;
    }
    if (!device_registry->Invalidate(guest_device_token)) {
        memory->Write32(kSporeGuestD3DDeviceGlobalAddress, 0);
        return false;
    }
    if (!memory->Write32(kSporeGuestD3DDeviceGlobalAddress, 0)) {
        return false;
    }

    *invalidated_token_out = guest_device_token;
    SDL_Log(
        "TRANSLATED_STAGE device-global invalidated address=0x%08x "
        "guest-device=0x%08x",
        kSporeGuestD3DDeviceGlobalAddress,
        guest_device_token);
    return true;
}
