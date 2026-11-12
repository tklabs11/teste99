#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012200c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012200c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x012200c0: 55 PUSH
        batch_guest_pc = 0x012200c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012200c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012200c3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012200cb: f30f1105a8205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20a8u)) return BatchLiftStatus::invalid_memory;
    // 0x012200d3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012200db: f30f1105ac205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20acu)) return BatchLiftStatus::invalid_memory;
    // 0x012200e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012200eb: f30f1105b0205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20b0u)) return BatchLiftStatus::invalid_memory;
    // 0x012200f3: 5d POP
        batch_guest_pc = 0x012200f3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012200f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
