#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925050(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925050u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3r = 0;

    // 0x00925050: 83c150 ADD
        t0a = state.regs[1];
        t0b = 0x00000050u;
        t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;
        batch_set_add_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00925053: b801000000 MOV
        t1 = 0x00000001u;
        state.regs[0] = t1;
    // 0x00925058: f00fc101 XADD.LOCK
        batch_guest_pc = 0x00925058u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[0];
        t2r = static_cast<std::uint32_t>(t2a + t2b) & 0xffffffffu;
        batch_set_add_flags(state, t2a, t2b, t2r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2a;
    // 0x0092505c: 40 INC
        t3a = state.regs[0];
        t3r = static_cast<std::uint32_t>(t3a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t3a, t3r, 32u);
        state.regs[0] = t3r;
    // 0x0092505d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
