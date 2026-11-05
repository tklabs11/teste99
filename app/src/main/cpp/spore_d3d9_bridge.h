#ifndef SPORE_D3D9_BRIDGE_H
#define SPORE_D3D9_BRIDGE_H

#include <SDL.h>
#include <d3d9.h>

HRESULT CreateSporeDxvkDevice(
    SDL_Window* sdl_window,
    UINT adapter,
    D3DDEVTYPE device_type,
    DWORD behavior_flags,
    D3DPRESENT_PARAMETERS* presentation_parameters,
    IDirect3D9** d3d9_out,
    IDirect3DDevice9** device_out);

#endif
