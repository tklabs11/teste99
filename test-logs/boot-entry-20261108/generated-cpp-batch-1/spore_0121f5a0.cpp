#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f5a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f5a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121f5a0: 55 PUSH
        batch_guest_pc = 0x0121f5a0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5a1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f5a3: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5ab: f30f1105e81a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ae8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5b3: f30f1005d4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5bb: f30f1105ec1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1aecu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5c3: f30f1005d8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5cb: f30f1105f01a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1af0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f5d3: 5d POP
        batch_guest_pc = 0x0121f5d3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121f5d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
