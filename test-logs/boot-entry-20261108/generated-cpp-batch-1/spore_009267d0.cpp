#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009267d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009267d0u);
    std::uint32_t t0 = 0;

    // 0x009267d0: 8d4130 LEA
        t0 = static_cast<std::uint32_t>(state.regs[1] + 0x00000030u);
        state.regs[0] = t0;
    // 0x009267d3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
