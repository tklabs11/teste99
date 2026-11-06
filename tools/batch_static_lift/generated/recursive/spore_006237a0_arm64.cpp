#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_006237a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_006237a0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14a = 0;

    // 0x006237a0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x006237a1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x006237a3: 8b4e30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x006237a6: 85c9 TEST
        t3a = state.regs[1];
        t3b = state.regs[1];
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
    // 0x006237a8: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006237b8;
    // 0x006237aa: e8f1ffffff CALL
        if (!batch_guest_call32(memory, state, 0x006237a0u, 0x006237afu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_006237a0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x006237afu) return BatchLiftStatus::invalid_control_flow;
    // 0x006237af: 8bc8 MOV
        t6 = state.regs[0];
        state.regs[1] = t6;
    // 0x006237b1: 8b4634 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x006237b4: 03c1 ADD
        t8a = state.regs[0];
        t8b = state.regs[1];
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x006237b6: 5e POP
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x006237b7: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x006237b8: 8b4634 MOV
    L_006237b8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x006237bb: 33c9 XOR
        t12a = state.regs[1];
        t12b = state.regs[1];
        t12r = (t12a ^ t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
        state.regs[1] = t12r;
    // 0x006237bd: 03c1 ADD
        t13a = state.regs[0];
        t13b = state.regs[1];
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[0] = t13r;
    // 0x006237bf: 5e POP
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t14a;
    // 0x006237c0: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
