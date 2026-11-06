#ifndef SPORE_GRAPHICS_PARAMETER_TRANSLATION_H
#define SPORE_GRAPHICS_PARAMETER_TRANSLATION_H

#include <cstddef>
#include <cstdint>

enum class SporeGuestConfigBooleanLookupStatus {
    found,
    missing,
    unsupported_type,
    not_initialized,
    invalid_fixture
};

struct SporeGuestConfigBooleanFixtureRecord {
    std::uint32_t key;
    std::uint16_t value_type;
    std::uint8_t value_flags;
    std::uint8_t inline_value;
    std::uint8_t indirect_value;
};

struct SporeGuestConfigBooleanFixtureView {
    const SporeGuestConfigBooleanFixtureRecord* records;
    std::size_t record_count;
    const std::uint32_t* cached_values;
    std::size_t cached_count;
    bool initialized;
};

inline SporeGuestConfigBooleanLookupStatus SporeTranslatedLookupConfigBoolean(
    const SporeGuestConfigBooleanFixtureView& view,
    std::uint32_t key,
    bool* value_out) {
    if (value_out == nullptr
            || (view.record_count != 0 && view.records == nullptr)
            || (view.cached_count != 0 && view.cached_values == nullptr)) {
        return SporeGuestConfigBooleanLookupStatus::invalid_fixture;
    }
    if (!view.initialized) {
        return SporeGuestConfigBooleanLookupStatus::not_initialized;
    }
    if (key < view.cached_count) {
        *value_out = view.cached_values[key] != 0;
        return SporeGuestConfigBooleanLookupStatus::found;
    }

    const SporeGuestConfigBooleanFixtureRecord* found_record = nullptr;
    for (std::size_t i = 0; i < view.record_count; ++i) {
        if (view.records[i].key == key) {
            if (found_record != nullptr) {
                return SporeGuestConfigBooleanLookupStatus::invalid_fixture;
            }
            found_record = &view.records[i];
        }
    }

    if (found_record == nullptr) {
        *value_out = false;
        return SporeGuestConfigBooleanLookupStatus::missing;
    }
    if (found_record->value_type != 1 && found_record->value_type != 0x10) {
        *value_out = false;
        return SporeGuestConfigBooleanLookupStatus::unsupported_type;
    }

    const std::uint8_t value = (found_record->value_flags & 0x30) != 0
        ? found_record->indirect_value
        : found_record->inline_value;
    *value_out = value != 0;
    return SporeGuestConfigBooleanLookupStatus::found;
}

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
