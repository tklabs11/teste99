#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f560(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f560u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121f560: 55 PUSH
        batch_guest_pc = 0x0121f560u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f561: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f563: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f56b: f30f1105f41a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1af4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f573: f30f1005d0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f57b: f30f1105f81a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1af8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f583: f30f1005ccb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f58b: f30f1105fc1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1afcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f593: 5d POP
        batch_guest_pc = 0x0121f593u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121f594: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
