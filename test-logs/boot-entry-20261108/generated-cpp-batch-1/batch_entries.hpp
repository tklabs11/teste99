#pragma once
#include <cstdint>

BatchLiftStatus spore_lift_00620230(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926100(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926120(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926140(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926790(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926840(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009268b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009268f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926a10(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926a30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926a60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926ab0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926c20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926db0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926fd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927140(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009274d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927700(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927860(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927a50(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009289e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00928df0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935a30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935a70(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935ad0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935b70(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00935c80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47430(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47480(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f474d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e074a(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07e6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0e95(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1219(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013000d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013000f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013002d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0138e640(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013b64c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_013b64e0(BatchLiftMemory& memory, BatchLiftState& state);

// Initializers this batch registers, in table order.
inline constexpr std::uint32_t kBatchInitializers[] = {
    0x011e0e95u, 0x013000d0u, 0x013000f0u, 0x013b64c0u, 0x013b64e0u, 0x013002d0u, 0x0138e640u,
};
inline constexpr std::uint32_t kBatchInitializerCount = 7u;

// The first table initializer this batch does not register: the walk
// must stop exactly there.
inline constexpr std::uint32_t kBatchNextInitializer = 0x01300210u;

// The first engine body the batch needs, and every lifted body entry.
inline constexpr std::uint32_t kBatchEngineBlocker = 0x011e073eu;

// Lifted bodies call these through the dispatcher because the batch does
// not lift them: the walk stops at the first one it actually reaches.
// The placeholder entry only exists because C++ forbids an empty array;
// kBatchPendingBodyCount is zero when there is nothing pending.
inline constexpr std::uint32_t kBatchPendingBodies[] = {
    0x011e073eu,
};
inline constexpr std::uint32_t kBatchPendingBodyCount = 1u;
struct BatchBodyEntry {
    std::uint32_t entry;
    BatchLiftStatus (*body)(BatchLiftMemory&, BatchLiftState&);
};
inline constexpr BatchBodyEntry kBatchBodyTable[] = {
    {0x00620230u, &spore_lift_00620230},
    {0x00926100u, &spore_lift_00926100},
    {0x00926120u, &spore_lift_00926120},
    {0x00926140u, &spore_lift_00926140},
    {0x00926340u, &spore_lift_00926340},
    {0x00926790u, &spore_lift_00926790},
    {0x009267c0u, &spore_lift_009267c0},
    {0x009267d0u, &spore_lift_009267d0},
    {0x009267e0u, &spore_lift_009267e0},
    {0x00926840u, &spore_lift_00926840},
    {0x009268b0u, &spore_lift_009268b0},
    {0x009268f0u, &spore_lift_009268f0},
    {0x00926a10u, &spore_lift_00926a10},
    {0x00926a30u, &spore_lift_00926a30},
    {0x00926a60u, &spore_lift_00926a60},
    {0x00926ab0u, &spore_lift_00926ab0},
    {0x00926c20u, &spore_lift_00926c20},
    {0x00926db0u, &spore_lift_00926db0},
    {0x00926fd0u, &spore_lift_00926fd0},
    {0x00927140u, &spore_lift_00927140},
    {0x009274d0u, &spore_lift_009274d0},
    {0x00927700u, &spore_lift_00927700},
    {0x00927860u, &spore_lift_00927860},
    {0x00927a50u, &spore_lift_00927a50},
    {0x009289e0u, &spore_lift_009289e0},
    {0x00928df0u, &spore_lift_00928df0},
    {0x00935a30u, &spore_lift_00935a30},
    {0x00935a70u, &spore_lift_00935a70},
    {0x00935ad0u, &spore_lift_00935ad0},
    {0x00935b70u, &spore_lift_00935b70},
    {0x00935c80u, &spore_lift_00935c80},
    {0x00f47430u, &spore_lift_00f47430},
    {0x00f47480u, &spore_lift_00f47480},
    {0x00f474d0u, &spore_lift_00f474d0},
    {0x011e074au, &spore_lift_011e074a},
    {0x011e07e0u, &spore_lift_011e07e0},
    {0x011e07e6u, &spore_lift_011e07e6},
    {0x011e07efu, &spore_lift_011e07ef},
    {0x011e0e95u, &spore_lift_011e0e95},
    {0x011e11d4u, &spore_lift_011e11d4},
    {0x011e1219u, &spore_lift_011e1219},
    {0x013000d0u, &spore_lift_013000d0},
    {0x013000f0u, &spore_lift_013000f0},
    {0x013002d0u, &spore_lift_013002d0},
    {0x0138e640u, &spore_lift_0138e640},
    {0x013b64c0u, &spore_lift_013b64c0},
    {0x013b64e0u, &spore_lift_013b64e0},
};
