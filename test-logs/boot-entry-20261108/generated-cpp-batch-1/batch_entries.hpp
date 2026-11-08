#pragma once
#include <cstdint>

BatchLiftStatus spore_lift_011e074a(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07e6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0e95(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1219(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013000d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013000f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013b64c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013b64e0(BatchLiftMemory& memory, BatchLiftState& state);

// Initializers this batch registers, in table order.
inline constexpr std::uint32_t kBatchInitializers[] = {
    0x011e0e95u, 0x013000d0u, 0x013000f0u, 0x013b64c0u, 0x013b64e0u,
};
inline constexpr std::uint32_t kBatchInitializerCount = 5u;

// The first table initializer this batch does not register: the walk
// must stop exactly there.
inline constexpr std::uint32_t kBatchNextInitializer = 0x013002d0u;

// The first engine body the batch needs, and every lifted body entry.
inline constexpr std::uint32_t kBatchEngineBlocker = 0u;
struct BatchBodyEntry {
    std::uint32_t entry;
    BatchLiftStatus (*body)(BatchLiftMemory&, BatchLiftState&);
};
inline constexpr BatchBodyEntry kBatchBodyTable[] = {
    {0x011e074au, &spore_lift_011e074a},
    {0x011e07e0u, &spore_lift_011e07e0},
    {0x011e07e6u, &spore_lift_011e07e6},
    {0x011e07efu, &spore_lift_011e07ef},
    {0x011e0e95u, &spore_lift_011e0e95},
    {0x011e11d4u, &spore_lift_011e11d4},
    {0x011e1219u, &spore_lift_011e1219},
    {0x013000d0u, &spore_lift_013000d0},
    {0x013000f0u, &spore_lift_013000f0},
    {0x013b64c0u, &spore_lift_013b64c0},
    {0x013b64e0u, &spore_lift_013b64e0},
};
