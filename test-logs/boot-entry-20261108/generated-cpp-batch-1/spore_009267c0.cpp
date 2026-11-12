#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009267c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009267c0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;

    // 0x009267c0: 8b442404 MOV
        batch_guest_pc = 0x009267c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009267c4: 2b00 SUB
        batch_guest_pc = 0x009267c4u;
        t1a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t1b)) return BatchLiftStatus::invalid_memory;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[0] = t1r;
    // 0x009267c6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
