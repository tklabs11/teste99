#ifndef SPORE_GRAPHICS_PARAMETER_TRANSLATION_H
#define SPORE_GRAPHICS_PARAMETER_TRANSLATION_H

#include <cstdint>

inline bool SporeTranslatedCopyBackBufferDimensions(
    std::uint32_t* guest_width_out,
    std::uint32_t* guest_height_out,
    std::uint32_t guest_width,
    std::uint32_t guest_height) {
    if (guest_width_out == nullptr || guest_height_out == nullptr
            || guest_width_out == guest_height_out) {
        return false;
    }

    *guest_width_out = guest_width;
    *guest_height_out = guest_height;
    return true;
}

#endif
