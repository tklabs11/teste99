#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012211d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012211d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012211d0: 55 PUSH
        batch_guest_pc = 0x012211d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012211d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012211d3: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x012211db: f30f1105bc1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fbcu)) return BatchLiftStatus::invalid_memory;
    // 0x012211e3: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x012211eb: f30f1105c01f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fc0u)) return BatchLiftStatus::invalid_memory;
    // 0x012211f3: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x012211fb: f30f1105c41f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fc4u)) return BatchLiftStatus::invalid_memory;
    // 0x01221203: 5d POP
        batch_guest_pc = 0x01221203u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221204: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
