#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121ae00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121ae00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121ae00: 55 PUSH
        batch_guest_pc = 0x0121ae00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121ae03: f30f100594b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb194u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae0b: f30f110504115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1104u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae13: f30f100590b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb190u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae1b: f30f110508115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1108u)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae23: f30f10058cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb18cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae2b: f30f11050c115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d110cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ae33: 5d POP
        batch_guest_pc = 0x0121ae33u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121ae34: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
