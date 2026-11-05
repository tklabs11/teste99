#include <SDL.h>

int RunVulkanTest();
int RunD3D9Test();
int RunTranslatedGraphicsTest();
int RunTranslatedWindowGlobalGraphicsTest();
int RunTranslatedDeviceGlobalGraphicsTest();

extern "C" int SDL_main(int argc, char** argv) {
    if (argc > 1 && SDL_strcmp(argv[1], "--spore-vulkan-test") == 0) {
        return RunVulkanTest();
    }
    if (argc > 1 && SDL_strcmp(argv[1], "--spore-d3d9-test") == 0) {
        return RunD3D9Test();
    }
    if (argc > 1
            && SDL_strcmp(argv[1], "--spore-translated-graphics-test") == 0) {
        return RunTranslatedGraphicsTest();
    }
    if (argc > 1
            && SDL_strcmp(argv[1], "--spore-translated-window-global-test") == 0) {
        return RunTranslatedWindowGlobalGraphicsTest();
    }
    if (argc > 1
            && SDL_strcmp(argv[1], "--spore-translated-device-global-test") == 0) {
        return RunTranslatedDeviceGlobalGraphicsTest();
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init: %s", SDL_GetError());
        return 1;
    }

    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengles2");

    SDL_Window* window = SDL_CreateWindow(
        "Spore ARM64 - SDL2",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        0,
        0,
        SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateRenderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Log("SDL2 %d.%d.%d renderer test started",
            SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);

    bool running = true;
    Uint32 frame = 0;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT
                    || (event.type == SDL_KEYDOWN
                        && (event.key.keysym.sym == SDLK_ESCAPE
                            || event.key.keysym.sym == SDLK_AC_BACK))) {
                running = false;
            }
        }

        const Uint8 pulse = static_cast<Uint8>((frame++ / 4) % 96);
        SDL_SetRenderDrawColor(renderer, 16, 26, 42, 255);
        SDL_RenderClear(renderer);

        int width = 0;
        int height = 0;
        SDL_GetRendererOutputSize(renderer, &width, &height);
        SDL_Rect panel{
            width / 4,
            height / 3,
            width / 2,
            height / 3
        };
        SDL_SetRenderDrawColor(
            renderer, static_cast<Uint8>(32 + pulse), 190, 180, 255);
        SDL_RenderFillRect(renderer, &panel);

        SDL_Rect marker{
            width / 2 - 12,
            height / 2 - 12,
            24,
            24
        };
        SDL_SetRenderDrawColor(renderer, 234, 242, 248, 255);
        SDL_RenderFillRect(renderer, &marker);
        SDL_RenderPresent(renderer);
    }

    SDL_Log("SDL2 renderer test stopped");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
