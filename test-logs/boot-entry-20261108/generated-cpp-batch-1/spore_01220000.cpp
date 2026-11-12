#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220000(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220000u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220000: 55 PUSH
        batch_guest_pc = 0x01220000u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220001: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220003: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122000b: f30f1105281c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c28u)) return BatchLiftStatus::invalid_memory;
    // 0x01220013: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122001b: f30f11052c1c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c2cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220023: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122002b: f30f1105301c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c30u)) return BatchLiftStatus::invalid_memory;
    // 0x01220033: 5d POP
        batch_guest_pc = 0x01220033u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220034: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
