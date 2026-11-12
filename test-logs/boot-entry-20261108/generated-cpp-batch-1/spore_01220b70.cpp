#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220b70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220b70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220b70: 55 PUSH
        batch_guest_pc = 0x01220b70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220b71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220b73: f30f1005101d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d10u)) return BatchLiftStatus::invalid_memory;
    // 0x01220b7b: f30f1105181f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f18u)) return BatchLiftStatus::invalid_memory;
    // 0x01220b83: f30f1005141d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d14u)) return BatchLiftStatus::invalid_memory;
    // 0x01220b8b: f30f11051c1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f1cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220b93: f30f1005181d5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1d18u)) return BatchLiftStatus::invalid_memory;
    // 0x01220b9b: f30f1105201f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f20u)) return BatchLiftStatus::invalid_memory;
    // 0x01220ba3: 5d POP
        batch_guest_pc = 0x01220ba3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220ba4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
