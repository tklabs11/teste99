#ifndef SPORE_TRANSLATED_GRAPHICS_H
#define SPORE_TRANSLATED_GRAPHICS_H

#include <SDL.h>
#include <d3d9.h>

#include <cstddef>
#include <cstdint>
#include <mutex>

struct SporeGuestPresentParameters32 {
    std::uint32_t back_buffer_width;
    std::uint32_t back_buffer_height;
    std::uint32_t back_buffer_format;
    std::uint32_t back_buffer_count;
    std::uint32_t multi_sample_type;
    std::uint32_t multi_sample_quality;
    std::uint32_t swap_effect;
    std::uint32_t device_window_token;
    std::int32_t windowed;
    std::int32_t enable_auto_depth_stencil;
    std::uint32_t auto_depth_stencil_format;
    std::uint32_t flags;
    std::uint32_t full_screen_refresh_rate;
    std::uint32_t presentation_interval;
};

struct SporeGuestD3D9State32 {
    std::uint32_t adapter_ordinal;
    std::uint32_t device_type;
    std::uint32_t behavior_flags;
    std::uint32_t window_token;
    std::uint32_t device_token;
    SporeGuestPresentParameters32 presentation;
    std::uint32_t original_setup_field_14;
};

struct SporeGuestFrameOwner32 {
    std::uint8_t reserved[0x18];
    std::uint32_t alternate_presenter_token;
};

constexpr std::uint32_t kSporeGuestDeviceWindowGlobalAddress = 0x016f658c;
constexpr std::uint32_t kSporeGuestD3DDeviceGlobalAddress = 0x016f89d0;

class SporeGuestMemory32 final {
public:
    bool Read32(std::uint32_t address, std::uint32_t* value_out) const;
    bool Write32(std::uint32_t address, std::uint32_t value);
    void Clear();

private:
    std::uint32_t device_window_token_ = 0;
    std::uint32_t d3d_device_token_ = 0;
};

class SporeNativeDeviceRegistry final {
public:
    SporeNativeDeviceRegistry() = default;
    ~SporeNativeDeviceRegistry();

    SporeNativeDeviceRegistry(const SporeNativeDeviceRegistry&) = delete;
    SporeNativeDeviceRegistry& operator=(const SporeNativeDeviceRegistry&) = delete;

    bool Register(
        IDirect3DDevice9* device,
        std::uint32_t* guest_token_out);
    bool Invalidate(std::uint32_t guest_token);
    void InvalidateAll();
    HRESULT Present(
        std::uint32_t guest_token,
        const SporeGuestFrameOwner32* frame_owner) const;
    std::uint64_t PresentDispatchCount() const;

private:
    mutable std::mutex mutex_;
    std::uint32_t guest_token_ = 0;
    IDirect3DDevice9* device_ = nullptr;
    mutable std::uint64_t present_dispatch_count_ = 0;
};

static_assert(sizeof(SporeGuestPresentParameters32) == 0x38);
static_assert(offsetof(SporeGuestPresentParameters32, device_window_token) == 0x1c);
static_assert(offsetof(SporeGuestPresentParameters32, presentation_interval) == 0x34);
static_assert(offsetof(SporeGuestD3D9State32, presentation) == 0x14);
static_assert(offsetof(SporeGuestD3D9State32, original_setup_field_14) == 0x4c);
static_assert(sizeof(SporeGuestD3D9State32) == 0x50);
static_assert(offsetof(SporeGuestFrameOwner32, alternate_presenter_token) == 0x18);
static_assert(sizeof(SporeGuestFrameOwner32) == 0x1c);

void SporePrepareTranslatedGraphicsProbe(SporeGuestD3D9State32* state);
void SporePrepareTranslatedWindowGlobalProbe(
    SporeGuestD3D9State32* state,
    SporeGuestMemory32* memory);
bool SporeTranslatedSetDeviceWindowGlobal(
    SporeGuestMemory32* memory,
    std::uint32_t guest_window_token);
bool SporeTranslatedSetCreateDeviceBackBufferDimensions(
    SporeGuestD3D9State32* state,
    std::uint32_t guest_width,
    std::uint32_t guest_height);
bool SporeTranslatedSetPresentationModeFields(
    SporeGuestD3D9State32* state);

HRESULT SporeTranslatedCreateDevice(
    SporeGuestD3D9State32* state,
    SDL_Window* window,
    D3DPRESENT_PARAMETERS* host_presentation_out,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out);

HRESULT SporeTranslatedCreateDeviceWithGlobals(
    SporeGuestD3D9State32* state,
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    SDL_Window* window,
    D3DPRESENT_PARAMETERS* host_presentation_out,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out);

bool SporeTranslatedRegisterDeviceGlobal(
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    std::uint32_t* guest_device_token_out,
    IDirect3DDevice9* host_device);

HRESULT SporeTranslatedPresentFromDeviceGlobal(
    const SporeGuestMemory32* memory,
    const SporeNativeDeviceRegistry* device_registry,
    const SporeGuestFrameOwner32* frame_owner);

bool SporeTranslatedReleaseDeviceGlobal(
    SporeGuestMemory32* memory,
    SporeNativeDeviceRegistry* device_registry,
    std::uint32_t* invalidated_token_out);

#endif
