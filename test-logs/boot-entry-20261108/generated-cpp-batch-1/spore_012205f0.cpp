#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012205f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012205f0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x012205f0: 55 PUSH
        batch_guest_pc = 0x012205f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012205f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012205f3: f30f10050cbd3e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013ebd0cu)) return BatchLiftStatus::invalid_memory;
    // 0x012205fb: f30f1105bc1e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ebcu)) return BatchLiftStatus::invalid_memory;
    // 0x01220603: 5d POP
        batch_guest_pc = 0x01220603u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x01220604: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
