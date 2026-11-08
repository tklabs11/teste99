#pragma once
#include <array>
#include <cstdint>
inline constexpr std::array<std::uint8_t, 12> kCrtPrefixBytes{0x6au, 0x58u, 0x68u, 0xa8u, 0x8cu, 0x50u, 0x01u, 0xe8u, 0xe8u, 0x02u, 0x00u, 0x00u};
inline constexpr std::uint32_t kCrtEntry = 0x011e0ee0u;
inline constexpr std::uint32_t kCrtStop = 0x011e0ee7u;
