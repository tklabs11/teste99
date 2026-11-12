#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221bb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221bb0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221bb0: 55 PUSH
        batch_guest_pc = 0x01221bb0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221bb1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221bb3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bbb: f30f110584215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2184u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bc3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bcb: f30f110588215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2188u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bd3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221bdb: f30f11058c215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d218cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221be3: 5d POP
        batch_guest_pc = 0x01221be3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221be4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
