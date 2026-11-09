#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935b70(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00935c80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00935c80u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t49a = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;

    // 0x00935c80: e8ebfeffff CALL
        if (!batch_guest_call32(memory, state, 0x00935b70u, 0x00935c85u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_00935b70(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x00935c85u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c85: 84c0 TEST
        t1a = state.regs[0] & 0x000000ffu;
        t1b = state.regs[0] & 0x000000ffu;
        t1r = (t1a & t1b) & 0x000000ffu;
        batch_set_logic_flags(state, t1r, 8u);
    // 0x00935c87: 7503 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935c8c;
    // 0x00935c89: 33c0 XOR
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x00935c8b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00935c8c: a130996601 MOV
    L_00935c8c:
        if (!memory.load32(0x01669930u, t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00935c91: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c92: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c93: 83c00c ADD
        t8a = state.regs[0];
        t8b = 0x0000000cu;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00935c96: 50 PUSH
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00935c97: ff15d8c23c01 CALL
        t10_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00935c9du);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x00935c9du) return BatchLiftStatus::invalid_control_flow;
    // 0x00935c9d: a130996601 MOV
        if (!memory.load32(0x01669930u, t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00935ca2: 8b30 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00935ca4: 8b7c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t13;
    // 0x00935ca8: 3bf0 CMP
        t14a = state.regs[6];
        t14b = state.regs[0];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x00935caa: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935cbb;
    // 0x00935cac: 8d642400 LEA
        t16 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t16;
    // 0x00935cb0: 397e08 CMP
    L_00935cb0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[7];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00935cb3: 743e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935cf3;
    // 0x00935cb5: 8b36 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t19;
    // 0x00935cb7: 3bf0 CMP
        t20a = state.regs[6];
        t20b = state.regs[0];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x00935cb9: 75f5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935cb0;
    // 0x00935cbb: 8b4c2410 MOV
    L_00935cbb:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00935cbf: 33f6 XOR
        t23a = state.regs[6];
        t23b = state.regs[6];
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[6] = t23r;
    // 0x00935cc1: 85c9 TEST
        t24a = state.regs[1];
        t24b = state.regs[1];
        t24r = (t24a & t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
    // 0x00935cc3: 744d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935d12;
    // 0x00935cc5: ffd1 CALL
        t26_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[1], 0x00935cc7u);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
    // 0x00935cc7: 8bf0 MOV
        t27 = state.regs[0];
        state.regs[6] = t27;
    // 0x00935cc9: 897e08 MOV
        t28 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00935ccc: 33c9 XOR
        t29a = state.regs[1];
        t29b = state.regs[1];
        t29r = (t29a ^ t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
        state.regs[1] = t29r;
    // 0x00935cce: 8d560c LEA
        t30 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu);
        state.regs[2] = t30;
    // 0x00935cd1: 870a XCHG
        if (!batch_guest_xchg32(memory, state, 1u, static_cast<std::uint32_t>(state.regs[2] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00935cd3: c70600000000 MOV
        t32 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00935cd9: c7460400000000 MOV
        t33 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00935ce0: a130996601 MOV
        if (!memory.load32(0x01669930u, t34)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t34;
    // 0x00935ce5: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x00935ce7: 890e MOV
        t36 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00935ce9: 894604 MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00935cec: 8930 MOV
        t38 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00935cee: 8b16 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x00935cf0: 897204 MOV
        t40 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00935cf3: 8d460c LEA
    L_00935cf3:
        t41 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu);
        state.regs[0] = t41;
    // 0x00935cf6: b901000000 MOV
        t42 = 0x00000001u;
        state.regs[1] = t42;
    // 0x00935cfb: f00fc108 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t43a)) return BatchLiftStatus::invalid_memory;
        t43b = state.regs[1];
        t43r = static_cast<std::uint32_t>(t43a + t43b) & 0xffffffffu;
        batch_set_add_flags(state, t43a, t43b, t43r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t43r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43a;
    // 0x00935cff: ba34996601 MOV
        t44 = 0x01669934u;
        state.regs[2] = t44;
    // 0x00935d04: b801000000 MOV
        t45 = 0x00000001u;
        state.regs[0] = t45;
    // 0x00935d09: f00fc102 XADD.LOCK
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t46a)) return BatchLiftStatus::invalid_memory;
        t46b = state.regs[0];
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t46r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46a;
    // 0x00935d0d: a130996601 MOV
        if (!memory.load32(0x01669930u, t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t47;
    // 0x00935d12: 83c00c ADD
    L_00935d12:
        t48a = state.regs[0];
        t48b = 0x0000000cu;
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[0] = t48r;
    // 0x00935d15: 50 PUSH
        t49a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00935d16: ff15dcc23c01 CALL
        t50_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00935d1cu);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x00935d1cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935d1c: 5f POP
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t51a;
    // 0x00935d1d: 8bc6 MOV
        t52 = state.regs[6];
        state.regs[0] = t52;
    // 0x00935d1f: 5e POP
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t53a;
    // 0x00935d20: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
