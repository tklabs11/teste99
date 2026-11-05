#include "spore_sdl_bridge.h"

#include <SDL.h>

namespace {

int DispatchSize(
    void* canvas_adapter,
    const SporeCanvasEventHandlers& handlers,
    std::uint32_t size_type,
    int width,
    int height) {
    return handlers.on_size(canvas_adapter, size_type, width, height);
}

int DispatchActivation(
    void* canvas_adapter,
    const SporeCanvasEventHandlers& handlers,
    std::uint16_t activation_state,
    bool minimized) {
    return handlers.on_activation(
        canvas_adapter,
        activation_state,
        minimized ? 1 : 0);
}

}

extern "C" int RunAndroidEventLoop(
    void* canvas_adapter,
    const SporeCanvasEventHandlers* handlers) {
    if (canvas_adapter == nullptr
            || handlers == nullptr
            || handlers->on_size == nullptr
            || handlers->on_activation == nullptr) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "RunAndroidEventLoop requires a Canvas and both event handlers");
        return -1;
    }

    bool running = true;
    bool minimized = false;
    int last_width = 0;
    int last_height = 0;
    bool have_size = false;

    while (running) {
        bool received_event = false;
        SDL_Event event{};

        while (SDL_PollEvent(&event) != 0) {
            received_event = true;
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            if (event.type != SDL_WINDOWEVENT) {
                continue;
            }

            switch (event.window.event) {
                case SDL_WINDOWEVENT_MINIMIZED:
                    if (!minimized) {
                        minimized = true;
                        if (DispatchSize(
                                canvas_adapter,
                                *handlers,
                                SPORE_CANVAS_SIZE_MINIMIZED,
                                0,
                                0) != 0) {
                            SDL_LogError(
                                SDL_LOG_CATEGORY_APPLICATION,
                                "Canvas size/minimize handler failed");
                            return -2;
                        }
                    }
                    break;

                case SDL_WINDOWEVENT_RESTORED:
                case SDL_WINDOWEVENT_SHOWN:
                case SDL_WINDOWEVENT_MAXIMIZED: {
                    minimized = false;
                    const std::uint32_t size_type =
                        event.window.event == SDL_WINDOWEVENT_MAXIMIZED
                            ? SPORE_CANVAS_SIZE_MAXIMIZED
                            : SPORE_CANVAS_SIZE_RESTORED;
                    if (SDL_Window* window =
                            SDL_GetWindowFromID(event.window.windowID)) {
                        int width = 0;
                        int height = 0;
                        SDL_GetWindowSize(window, &width, &height);
                        if (DispatchSize(
                                canvas_adapter,
                                *handlers,
                                size_type,
                                width,
                                height) != 0) {
                            SDL_LogError(
                                SDL_LOG_CATEGORY_APPLICATION,
                                "Canvas size/restore handler failed");
                            return -2;
                        }
                        last_width = width;
                        last_height = height;
                        have_size = true;
                    }
                    break;
                }

                case SDL_WINDOWEVENT_SIZE_CHANGED:
                case SDL_WINDOWEVENT_RESIZED:
                    minimized = false;
                    if (!have_size
                            || event.window.data1 != last_width
                            || event.window.data2 != last_height) {
                        if (DispatchSize(
                                canvas_adapter,
                                *handlers,
                                SPORE_CANVAS_SIZE_RESTORED,
                                event.window.data1,
                                event.window.data2) != 0) {
                            SDL_LogError(
                                SDL_LOG_CATEGORY_APPLICATION,
                                "Canvas size handler failed");
                            return -2;
                        }
                        last_width = event.window.data1;
                        last_height = event.window.data2;
                        have_size = true;
                    }
                    break;

                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    if (DispatchActivation(
                            canvas_adapter,
                            *handlers,
                            SPORE_CANVAS_ACTIVATION_ACTIVE,
                            minimized) != 0) {
                        SDL_LogError(
                            SDL_LOG_CATEGORY_APPLICATION,
                            "Canvas focus-gained handler failed");
                        return -2;
                    }
                    break;

                case SDL_WINDOWEVENT_FOCUS_LOST:
                    if (DispatchActivation(
                            canvas_adapter,
                            *handlers,
                            SPORE_CANVAS_ACTIVATION_INACTIVE,
                            minimized) != 0) {
                        SDL_LogError(
                            SDL_LOG_CATEGORY_APPLICATION,
                            "Canvas focus-lost handler failed");
                        return -2;
                    }
                    break;

                default:
                    break;
            }
        }

        if (running && !received_event) {
            SDL_Delay(1);
        }
    }

    return 0;
}
