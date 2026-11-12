#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221250(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221250u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221250: 55 PUSH
        batch_guest_pc = 0x01221250u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221251: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221253: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0122125b: f30f110530205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2030u)) return BatchLiftStatus::invalid_memory;
    // 0x01221263: f30f1005d4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0122126b: f30f110534205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2034u)) return BatchLiftStatus::invalid_memory;
    // 0x01221273: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0122127b: f30f110538205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2038u)) return BatchLiftStatus::invalid_memory;
    // 0x01221283: 5d POP
        batch_guest_pc = 0x01221283u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221284: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
