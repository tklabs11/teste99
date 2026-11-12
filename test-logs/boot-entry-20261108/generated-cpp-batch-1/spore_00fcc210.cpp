#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00fcc210(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00fcc210u);
    std::uint32_t t0 = 0;

    // 0x00fcc210: 8b4104 MOV
        batch_guest_pc = 0x00fcc210u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00fcc213: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
