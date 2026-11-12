#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e5830(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e5830u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;

    // 0x011e5830: 8b442404 MOV
        batch_guest_pc = 0x011e5830u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x011e5834: a3e44a6f01 MOV
        batch_guest_pc = 0x011e5834u;
        t1 = state.regs[0];
        if (!memory.store32(0x016f4ae4u, t1)) return BatchLiftStatus::invalid_memory;
    // 0x011e5839: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
