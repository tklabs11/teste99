#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009236c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009236c0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3r = 0;

    // 0x009236c0: 83c134 ADD
        t0a = state.regs[1];
        t0b = 0x00000034u;
        t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;
        batch_set_add_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x009236c3: b801000000 MOV
        t1 = 0x00000001u;
        state.regs[0] = t1;
    // 0x009236c8: f00fc101 XADD.LOCK
        batch_guest_pc = 0x009236c8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[0];
        t2r = static_cast<std::uint32_t>(t2a + t2b) & 0xffffffffu;
        batch_set_add_flags(state, t2a, t2b, t2r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2a;
    // 0x009236cc: 40 INC
        t3a = state.regs[0];
        t3r = static_cast<std::uint32_t>(t3a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t3a, t3r, 32u);
        state.regs[0] = t3r;
    // 0x009236cd: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
