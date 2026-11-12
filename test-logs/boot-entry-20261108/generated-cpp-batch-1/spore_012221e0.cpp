#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012221e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012221e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x012221e0: 55 PUSH
        batch_guest_pc = 0x012221e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012221e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012221e3: f30f100580c23e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013ec280u)) return BatchLiftStatus::invalid_memory;
    // 0x012221eb: f30f11057c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d257cu)) return BatchLiftStatus::invalid_memory;
    // 0x012221f3: 5d POP
        batch_guest_pc = 0x012221f3u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x012221f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
