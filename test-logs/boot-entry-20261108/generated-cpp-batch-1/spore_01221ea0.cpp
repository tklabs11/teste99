#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221ea0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221ea0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221ea0: 55 PUSH
        batch_guest_pc = 0x01221ea0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221ea1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221ea3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221eab: f30f110508235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2308u)) return BatchLiftStatus::invalid_memory;
    // 0x01221eb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ebb: f30f11050c235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d230cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221ec3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ecb: f30f110510235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2310u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ed3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221edb: f30f110514235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2314u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ee3: 5d POP
        batch_guest_pc = 0x01221ee3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221ee4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
