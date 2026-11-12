#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923460(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923460u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;

    // 0x00923460: 8a442404 MOV
        batch_guest_pc = 0x00923460u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t0 << 0u) & 0x000000ffu);
    // 0x00923464: 88410c MOV
        batch_guest_pc = 0x00923464u;
        t1 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
    // 0x00923467: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
