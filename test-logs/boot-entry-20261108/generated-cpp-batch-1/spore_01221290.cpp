#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221290(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221290u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221290: 55 PUSH
        batch_guest_pc = 0x01221290u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221291: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221293: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122129b: f30f1105ac1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1facu)) return BatchLiftStatus::invalid_memory;
    // 0x012212a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012212ab: f30f1105b01f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fb0u)) return BatchLiftStatus::invalid_memory;
    // 0x012212b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012212bb: f30f1105b41f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fb4u)) return BatchLiftStatus::invalid_memory;
    // 0x012212c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012212cb: f30f1105b81f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fb8u)) return BatchLiftStatus::invalid_memory;
    // 0x012212d3: 5d POP
        batch_guest_pc = 0x012212d3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x012212d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
