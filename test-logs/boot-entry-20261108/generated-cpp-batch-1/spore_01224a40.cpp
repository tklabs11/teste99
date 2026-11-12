#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224a40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224a40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01224a40: 55 PUSH
        batch_guest_pc = 0x01224a40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224a41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224a43: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01224a4b: f30f1105e4265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26e4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224a53: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01224a5b: f30f1105e8265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26e8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224a63: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01224a6b: f30f1105ec265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d26ecu)) return BatchLiftStatus::invalid_memory;
    // 0x01224a73: 5d POP
        batch_guest_pc = 0x01224a73u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01224a74: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
