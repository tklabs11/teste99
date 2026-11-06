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

inline bool SporeTranslatedSetPresentationModeFields(
    std::uint32_t* setup_field_14_out,
    std::uint32_t* back_buffer_format_out,
    std::uint32_t* depth_stencil_format_out) {
    if (setup_field_14_out == nullptr
            || back_buffer_format_out == nullptr
            || depth_stencil_format_out == nullptr
            || setup_field_14_out == back_buffer_format_out
            || setup_field_14_out == depth_stencil_format_out
            || back_buffer_format_out == depth_stencil_format_out) {
        return false;
    }

    *setup_field_14_out = 0x16;
    *back_buffer_format_out = 0x15;
    *depth_stencil_format_out = 0x4b;
    return true;
}

#endif
