#pragma once
#include <array>
#include <cstdint>
inline constexpr std::array<std::uint8_t, 12> kCrtPrefixBytes{0x6au, 0x58u, 0x68u, 0xa8u, 0x8cu, 0x50u, 0x01u, 0xe8u, 0xe8u, 0x02u, 0x00u, 0x00u};
inline constexpr std::array<std::uint8_t, 69> kSehPrologBytes{0x68u, 0x2du, 0x12u, 0x1eu, 0x01u, 0x64u, 0xffu, 0x35u, 0x00u, 0x00u, 0x00u, 0x00u, 0x8bu, 0x44u, 0x24u, 0x10u, 0x89u, 0x6cu, 0x24u, 0x10u, 0x8du, 0x6cu, 0x24u, 0x10u, 0x2bu, 0xe0u, 0x53u, 0x56u, 0x57u, 0xa1u, 0x70u, 0xfeu, 0x5cu, 0x01u, 0x31u, 0x45u, 0xfcu, 0x33u, 0xc5u, 0x50u, 0x89u, 0x65u, 0xe8u, 0xffu, 0x75u, 0xf8u, 0x8bu, 0x45u, 0xfcu, 0xc7u, 0x45u, 0xfcu, 0xfeu, 0xffu, 0xffu, 0xffu, 0x89u, 0x45u, 0xf8u, 0x8du, 0x45u, 0xf0u, 0x64u, 0xa3u, 0x00u, 0x00u, 0x00u, 0x00u, 0xc3u};
inline constexpr std::uint32_t kCrtEntry = 0x011e0ee0u;
inline constexpr std::uint32_t kCrtStop = 0x011e0ee7u;
inline constexpr std::uint32_t kCrtPrefixInstructions = 2u;
inline constexpr std::uint32_t kSehPrologEntry = 0x011e11d4u;
inline constexpr std::uint32_t kSehPrologInstructions = 21u;
inline constexpr bool kSehPrologExecuted = false;
inline constexpr std::uint32_t kCrtPrefixExecutedInstructions = 2u;
inline constexpr std::uint32_t kStartupInfoCall = 0x011e0ef8u;
inline constexpr std::uint32_t kInterlockedCall = 0x011e0f1eu;
inline constexpr std::uint32_t kStartupLockState = 0x0171e74cu;
inline constexpr std::uint32_t kStartupLock = 0x0171e750u;
inline constexpr std::uint32_t kStartupLockRegion = 0x0171e740u;
inline constexpr std::uint32_t kStartupLockRegionBytes = 32u;
inline constexpr bool kStartupLockExecuted = false;
inline constexpr std::uint32_t kInittermCall = 0x011e0f6fu;
inline constexpr std::uint32_t kAmsgExitCall = 0x011e0f4eu;
inline constexpr std::uint32_t kInittermTable = 0x013eb09cu;
inline constexpr std::uint32_t kInittermTableEnd = 0x013eb0acu;
inline constexpr bool kInittermCallIsBoundary = false;
inline constexpr std::uint32_t kInittermExecutedAddress = 0x011e0f85u;
inline constexpr bool kInittermExecutedIsBoundary = false;
inline constexpr std::uint32_t kInittermWalkCall = 0x011e0f98u;
inline constexpr std::uint32_t kCppInitTable = 0x013cc80cu;
inline constexpr std::uint32_t kCppInitTableEnd = 0x013eb098u;
inline constexpr bool kInittermWalkIsBoundary = false;
inline constexpr bool kCppWalkEnabled = false;
