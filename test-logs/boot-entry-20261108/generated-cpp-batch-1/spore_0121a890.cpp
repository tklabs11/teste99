#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121a890(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121a890u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121a890: 55 PUSH
        batch_guest_pc = 0x0121a890u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121a891: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121a893: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a89b: f30f1105440f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f44u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a8a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a8ab: f30f1105480f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f48u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a8b3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121a8bb: f30f11054c0f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0f4cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121a8c3: 5d POP
        batch_guest_pc = 0x0121a8c3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121a8c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
