#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f95b(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0068f950(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068f950u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8r = 0;

    // 0x0068f950: 85c9 TEST
        t0a = state.regs[1];
        t0b = state.regs[1];
        t0r = (t0a & t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
    // 0x0068f952: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f959;
    // 0x0068f954: 8d41f8 LEA
        t2 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffff8u);
        state.regs[0] = t2;
    // 0x0068f957: eb02 JMP
        goto L_0068f95b;
    // 0x0068f959: 33c0 XOR
    L_0068f959:
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[0] = t4r;
    // 0x0068f95b: 8d484c LEA
    L_0068f95b:
        t5 = static_cast<std::uint32_t>(state.regs[0] + 0x0000004cu);
        state.regs[1] = t5;
    // 0x0068f95e: b801000000 MOV
        t6 = 0x00000001u;
        state.regs[0] = t6;
    // 0x0068f963: f00fc101 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = state.regs[0];
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t7r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7a;
    // 0x0068f967: 40 INC
        t8a = state.regs[0];
        t8r = static_cast<std::uint32_t>(t8a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t8a, t8r, 32u);
        state.regs[0] = t8r;
    // 0x0068f968: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
