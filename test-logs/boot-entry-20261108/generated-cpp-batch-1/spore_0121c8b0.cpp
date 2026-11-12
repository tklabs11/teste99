#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c8b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c8b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c8b0: 55 PUSH
        batch_guest_pc = 0x0121c8b0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8b1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c8b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8bb: f30f1105a8125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12a8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8cb: f30f1105ac125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12acu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8db: f30f1105b0125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12b0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8e3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8eb: f30f1105b4125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12b4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8f3: 5d POP
        batch_guest_pc = 0x0121c8f3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c8f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
