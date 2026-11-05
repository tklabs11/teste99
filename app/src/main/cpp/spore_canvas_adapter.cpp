#include "spore_sdl_bridge.h"

namespace {

int SporeCanvasHandleSizeImpl(
    void* canvas_adapter,
    uint32_t size_type,
    int32_t width,
    int32_t height) {
    if (canvas_adapter == nullptr) {
        return -1;
    }

    auto* adapter = static_cast<SporeCanvasAdapter*>(canvas_adapter);
    if (adapter->canvas_object == nullptr
            || (size_type != SPORE_CANVAS_SIZE_RESTORED
                && size_type != SPORE_CANVAS_SIZE_MINIMIZED
                && size_type != SPORE_CANVAS_SIZE_MAXIMIZED)) {
        return -1;
    }

    if (size_type == SPORE_CANVAS_SIZE_MINIMIZED) {
        width = 0;
        height = 0;
    } else if (width < 0 || height < 0) {
        return -1;
    }

    adapter->size_type = size_type;
    adapter->width = width;
    adapter->height = height;
    adapter->minimized = size_type == SPORE_CANVAS_SIZE_MINIMIZED ? 1 : 0;

    if (adapter->refresh_cached_geometry != nullptr
            && adapter->refresh_cached_geometry(
                adapter->canvas_object, width, height) != 0) {
        return -2;
    }

    if (width > 0 && height > 0 && adapter->update_swapchain != nullptr
            && adapter->update_swapchain(
                adapter->canvas_object, width, height) != 0) {
        return -3;
    }

    return 0;
}

int SporeCanvasHandleActivateImpl(
    void* canvas_adapter,
    uint16_t activation_state,
    uint8_t minimized) {
    if (canvas_adapter == nullptr) {
        return -1;
    }

    auto* adapter = static_cast<SporeCanvasAdapter*>(canvas_adapter);
    if (adapter->canvas_object == nullptr
            || (activation_state != SPORE_CANVAS_ACTIVATION_INACTIVE
                && activation_state != SPORE_CANVAS_ACTIVATION_ACTIVE)) {
        return -1;
    }

    adapter->activation_state = activation_state;
    adapter->minimized = minimized != 0 ? 1 : 0;

    if (adapter->notify_activation != nullptr) {
        return adapter->notify_activation(
            adapter->canvas_object,
            activation_state,
            adapter->minimized);
    }

    return 0;
}

const SporeCanvasEventHandlers kCanvasEventHandlers{
    SporeCanvasHandleSizeImpl,
    SporeCanvasHandleActivateImpl
};

}

extern "C" int SporeCanvasHandleSize(
    void* canvas_adapter,
    uint32_t size_type,
    int32_t width,
    int32_t height) {
    return SporeCanvasHandleSizeImpl(canvas_adapter, size_type, width, height);
}

extern "C" int SporeCanvasHandleActivate(
    void* canvas_adapter,
    uint16_t activation_state,
    uint8_t minimized) {
    return SporeCanvasHandleActivateImpl(
        canvas_adapter, activation_state, minimized);
}

extern "C" const SporeCanvasEventHandlers* SporeCanvasGetEventHandlers(void) {
    return &kCanvasEventHandlers;
}
