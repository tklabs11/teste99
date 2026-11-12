#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c680(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c680u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c680: 55 PUSH
        batch_guest_pc = 0x0121c680u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c681: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c683: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c68b: f30f1105bc125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c693: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c69b: f30f1105c0125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6ab: f30f1105c4125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12c4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6bb: f30f1105c8125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12c8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c6c3: 5d POP
        batch_guest_pc = 0x0121c6c3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c6c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
