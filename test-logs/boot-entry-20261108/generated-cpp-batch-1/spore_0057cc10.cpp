#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00475ab0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0057cc10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0057cc10u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10r = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;

    // 0x0057cc10: 53 PUSH
        batch_guest_pc = 0x0057cc10u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc11: 55 PUSH
        batch_guest_pc = 0x0057cc11u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc12: 56 PUSH
        batch_guest_pc = 0x0057cc12u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc13: 57 PUSH
        batch_guest_pc = 0x0057cc13u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc14: 8b7c2414 MOV
        batch_guest_pc = 0x0057cc14u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x0057cc18: 8bc7 MOV
        t5 = state.regs[7];
        state.regs[0] = t5;
    // 0x0057cc1a: 8be9 MOV
        t6 = state.regs[1];
        state.regs[5] = t6;
    // 0x0057cc1c: 8d5001 LEA
        t7 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t7;
    // 0x0057cc1f: 90 NOP
    // 0x0057cc20: 8a08 MOV
    L_0057cc20:
        batch_guest_pc = 0x0057cc20u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t9 << 0u) & 0x000000ffu);
    // 0x0057cc22: 40 INC
        t10a = state.regs[0];
        t10r = static_cast<std::uint32_t>(t10a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t10a, t10r, 32u);
        state.regs[0] = t10r;
    // 0x0057cc23: 84c9 TEST
        t11a = state.regs[1] & 0x000000ffu;
        t11b = state.regs[1] & 0x000000ffu;
        t11r = (t11a & t11b) & 0x000000ffu;
        batch_set_logic_flags(state, t11r, 8u);
    // 0x0057cc25: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0057cc20;
    // 0x0057cc27: 2bc2 SUB
        t13a = state.regs[0];
        t13b = state.regs[2];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
        state.regs[0] = t13r;
    // 0x0057cc29: 8d1c38 LEA
        t14 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0x00000000u);
        state.regs[3] = t14;
    // 0x0057cc2c: 895c2414 MOV
        batch_guest_pc = 0x0057cc2cu;
        t15 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc30: 2bdf SUB
        t16a = state.regs[3];
        t16b = state.regs[7];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
        state.regs[3] = t16r;
    // 0x0057cc32: 8d4301 LEA
        t17 = static_cast<std::uint32_t>(state.regs[3] + 0x00000001u);
        state.regs[0] = t17;
    // 0x0057cc35: 50 PUSH
        batch_guest_pc = 0x0057cc35u;
        t18a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc36: 8bcd MOV
        t19 = state.regs[5];
        state.regs[1] = t19;
    // 0x0057cc38: e8738eefff CALL
        if (!batch_guest_call32(memory, state, 0x00475ab0u, 0x0057cc3du)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_00475ab0(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x0057cc3du) return BatchLiftStatus::invalid_control_flow;
    // 0x0057cc3d: 8b7500 MOV
        batch_guest_pc = 0x0057cc3du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t21;
    // 0x0057cc40: 53 PUSH
        batch_guest_pc = 0x0057cc40u;
        t22a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc41: 57 PUSH
        batch_guest_pc = 0x0057cc41u;
        t23a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc42: 56 PUSH
        batch_guest_pc = 0x0057cc42u;
        t24a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc43: e8fc3ac600 CALL
        t25_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0057cc48u);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x0057cc48u) return BatchLiftStatus::invalid_control_flow;
    // 0x0057cc48: 8b4c2420 MOV
        batch_guest_pc = 0x0057cc48u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x0057cc4c: 2bf7 SUB
        t27a = state.regs[6];
        t27b = state.regs[7];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[6] = t27r;
    // 0x0057cc4e: 83c40c ADD
        t28a = state.regs[4];
        t28b = 0x0000000cu;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[4] = t28r;
    // 0x0057cc51: 03f1 ADD
        t29a = state.regs[6];
        t29b = state.regs[1];
        t29r = static_cast<std::uint32_t>(t29a + t29b) & 0xffffffffu;
        batch_set_add_flags(state, t29a, t29b, t29r, 32u);
        state.regs[6] = t29r;
    // 0x0057cc53: 897504 MOV
        batch_guest_pc = 0x0057cc53u;
        t30 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000004u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc56: 5f POP
        batch_guest_pc = 0x0057cc56u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t31a;
    // 0x0057cc57: c60600 MOV
        batch_guest_pc = 0x0057cc57u;
        t32 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0057cc5a: 5e POP
        batch_guest_pc = 0x0057cc5au;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t33a;
    // 0x0057cc5b: 5d POP
        batch_guest_pc = 0x0057cc5bu;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t34a;
    // 0x0057cc5c: 5b POP
        batch_guest_pc = 0x0057cc5cu;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t35a;
    // 0x0057cc5d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
