#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00454cb0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923ff0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923fe0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923fe0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;

    // 0x00923fe0: 56 PUSH
        batch_guest_pc = 0x00923fe0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923fe1: 8b742408 MOV
        batch_guest_pc = 0x00923fe1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00923fe5: 8bc6 MOV
        t2 = state.regs[6];
        state.regs[0] = t2;
    // 0x00923fe7: 57 PUSH
        batch_guest_pc = 0x00923fe7u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923fe8: 8d7801 LEA
        t4 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[7] = t4;
    // 0x00923feb: eb03 JMP
        goto L_00923ff0;
    // 0x00923ff0: 8a10 MOV
    L_00923ff0:
        batch_guest_pc = 0x00923ff0u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t6 << 0u) & 0x000000ffu);
    // 0x00923ff2: 40 INC
        t7a = state.regs[0];
        t7r = static_cast<std::uint32_t>(t7a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t7a, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00923ff3: 84d2 TEST
        t8a = state.regs[2] & 0x000000ffu;
        t8b = state.regs[2] & 0x000000ffu;
        t8r = (t8a & t8b) & 0x000000ffu;
        batch_set_logic_flags(state, t8r, 8u);
    // 0x00923ff5: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923ff0;
    // 0x00923ff7: 2bc7 SUB
        t10a = state.regs[0];
        t10b = state.regs[7];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[0] = t10r;
    // 0x00923ff9: 03c6 ADD
        t11a = state.regs[0];
        t11b = state.regs[6];
        t11r = static_cast<std::uint32_t>(t11a + t11b) & 0xffffffffu;
        batch_set_add_flags(state, t11a, t11b, t11r, 32u);
        state.regs[0] = t11r;
    // 0x00923ffb: 50 PUSH
        batch_guest_pc = 0x00923ffbu;
        t12a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ffc: 56 PUSH
        batch_guest_pc = 0x00923ffcu;
        t13a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ffd: 83c108 ADD
        t14a = state.regs[1];
        t14b = 0x00000008u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[1] = t14r;
    // 0x00924000: e8ab0cb3ff CALL
        if (!batch_guest_call32(memory, state, 0x00454cb0u, 0x00924005u)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_00454cb0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00924005u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924005: 5f POP
        batch_guest_pc = 0x00924005u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t16a;
    // 0x00924006: 5e POP
        batch_guest_pc = 0x00924006u;
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t17a;
    // 0x00924007: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
