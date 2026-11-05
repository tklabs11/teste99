#ifndef SPORE_SDL_BRIDGE_H
#define SPORE_SDL_BRIDGE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*SporeCanvasSizeHandler)(
    void* canvas_object,
    uint32_t size_type,
    int32_t width,
    int32_t height);

typedef int (*SporeCanvasActivationHandler)(
    void* canvas_object,
    uint16_t activation_state,
    uint8_t minimized);

typedef int (*SporeCanvasGeometryRefreshHandler)(
    void* canvas_object,
    int32_t width,
    int32_t height);

typedef int (*SporeCanvasSwapchainResizeHandler)(
    void* canvas_object,
    int32_t width,
    int32_t height);

typedef int (*SporeCanvasActivationNotifyHandler)(
    void* canvas_object,
    uint16_t activation_state,
    uint8_t minimized);

typedef struct SporeCanvasAdapter {
    void* canvas_object;
    int32_t width;
    int32_t height;
    uint32_t size_type;
    uint16_t activation_state;
    uint8_t minimized;
    SporeCanvasGeometryRefreshHandler refresh_cached_geometry;
    SporeCanvasSwapchainResizeHandler update_swapchain;
    SporeCanvasActivationNotifyHandler notify_activation;
} SporeCanvasAdapter;

typedef struct SporeCanvasEventHandlers {
    SporeCanvasSizeHandler on_size;
    SporeCanvasActivationHandler on_activation;
} SporeCanvasEventHandlers;

enum {
    SPORE_CANVAS_SIZE_RESTORED = 0,
    SPORE_CANVAS_SIZE_MINIMIZED = 1,
    SPORE_CANVAS_SIZE_MAXIMIZED = 2,
    SPORE_CANVAS_ACTIVATION_INACTIVE = 0,
    SPORE_CANVAS_ACTIVATION_ACTIVE = 1
};

int SporeCanvasHandleSize(
    void* canvas_adapter,
    uint32_t size_type,
    int32_t width,
    int32_t height);

int SporeCanvasHandleActivate(
    void* canvas_adapter,
    uint16_t activation_state,
    uint8_t minimized);

const SporeCanvasEventHandlers* SporeCanvasGetEventHandlers(void);

int RunAndroidEventLoop(
    void* canvas_adapter,
    const SporeCanvasEventHandlers* handlers);

#ifdef __cplusplus
}
#endif

#endif
