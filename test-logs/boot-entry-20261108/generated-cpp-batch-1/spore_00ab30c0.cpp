#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00ab30c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00ab30c0u);
    std::uint32_t t0 = 0;

    // 0x00ab30c0: 8a410c MOV
        batch_guest_pc = 0x00ab30c0u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t0 << 0u) & 0x000000ffu);
    // 0x00ab30c3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
