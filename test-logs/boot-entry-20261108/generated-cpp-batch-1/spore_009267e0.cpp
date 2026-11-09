#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009267e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009267e0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;

    // 0x009267e0: 8b4104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009267e3: 83e001 AND
        t1a = state.regs[0];
        t1b = 0x00000001u;
        t1r = (t1a & t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[0] = t1r;
    // 0x009267e6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
