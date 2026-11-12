#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222da0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222da0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222da0: 55 PUSH
        batch_guest_pc = 0x01222da0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222da1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222da3: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dab: f30f11051c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d251cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222db3: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dbb: f30f110520255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2520u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dc3: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dcb: f30f110524255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2524u)) return BatchLiftStatus::invalid_memory;
    // 0x01222dd3: 5d POP
        batch_guest_pc = 0x01222dd3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222dd4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
