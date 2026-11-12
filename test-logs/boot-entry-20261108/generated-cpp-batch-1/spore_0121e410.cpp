#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e410(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e410u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e410: 55 PUSH
        batch_guest_pc = 0x0121e410u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e411: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e413: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e41b: f30f11055c1b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b5cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e423: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e42b: f30f1105601b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b60u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e433: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e43b: f30f1105641b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1b64u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e443: 5d POP
        batch_guest_pc = 0x0121e443u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e444: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
