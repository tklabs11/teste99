#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935a70(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00935ad0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00935ad0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41a = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;

    // 0x00935ad0: 51 PUSH
        batch_guest_pc = 0x00935ad0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ad1: a130996601 MOV
        batch_guest_pc = 0x00935ad1u;
        if (!memory.load32(0x01669930u, t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00935ad6: 53 PUSH
        batch_guest_pc = 0x00935ad6u;
        t2a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ad7: 56 PUSH
        batch_guest_pc = 0x00935ad7u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00935ad8: 83c00c ADD
        t4a = state.regs[0];
        t4b = 0x0000000cu;
        t4r = static_cast<std::uint32_t>(t4a + t4b) & 0xffffffffu;
        batch_set_add_flags(state, t4a, t4b, t4r, 32u);
        state.regs[0] = t4r;
    // 0x00935adb: 50 PUSH
        batch_guest_pc = 0x00935adbu;
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00935adc: ff15d8c23c01 CALL
        t6_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x00935ae2u);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00935ae2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935ae2: b934996601 MOV
        t7 = 0x01669934u;
        state.regs[1] = t7;
    // 0x00935ae7: 83caff OR
        t8a = state.regs[2];
        t8b = 0xffffffffu;
        t8r = (t8a | t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[2] = t8r;
    // 0x00935aea: f00fc111 XADD.LOCK
        batch_guest_pc = 0x00935aeau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9r)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9a;
    // 0x00935aee: 8b542410 MOV
        batch_guest_pc = 0x00935aeeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x00935af2: 8d420c LEA
        t11 = static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu);
        state.regs[0] = t11;
    // 0x00935af5: 0f9444240b SETZ
        batch_guest_pc = 0x00935af5u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000bu), (((state.eflags & 0x040u) != 0u) ? 1u : 0u))) return BatchLiftStatus::invalid_memory;
    // 0x00935afa: 8bc8 MOV
        t13 = state.regs[0];
        state.regs[1] = t13;
    // 0x00935afc: 83ceff OR
        t14a = state.regs[6];
        t14b = 0xffffffffu;
        t14r = (t14a | t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
        state.regs[6] = t14r;
    // 0x00935aff: f00fc131 XADD.LOCK
        batch_guest_pc = 0x00935affu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t15a)) return BatchLiftStatus::invalid_memory;
        t15b = state.regs[6];
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t15r)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t15a;
    // 0x00935b03: 33c9 XOR
        t16a = state.regs[1];
        t16b = state.regs[1];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[1] = t16r;
    // 0x00935b05: f00fc108 XADD.LOCK
        batch_guest_pc = 0x00935b05u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17r)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17a;
    // 0x00935b09: 85c9 TEST
        t18a = state.regs[1];
        t18b = state.regs[1];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x00935b0b: 0f94c3 SETZ
        state.regs[3] = (state.regs[3] & 0xffffff00u) | (((((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00935b0e: 84db TEST
        t20a = state.regs[3] & 0x000000ffu;
        t20b = state.regs[3] & 0x000000ffu;
        t20r = (t20a & t20b) & 0x000000ffu;
        batch_set_logic_flags(state, t20r, 8u);
    // 0x00935b10: 7431 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935b43;
    // 0x00935b12: 8b0d30996601 MOV
        batch_guest_pc = 0x00935b12u;
        if (!memory.load32(0x01669930u, t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00935b18: 8b01 MOV
        batch_guest_pc = 0x00935b18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00935b1a: 3bc1 CMP
        t24a = state.regs[0];
        t24b = state.regs[1];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x00935b1c: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935b2a;
    // 0x00935b1e: 8bff MOV
        t26 = state.regs[7];
        state.regs[7] = t26;
    // 0x00935b20: 3bc2 CMP
    L_00935b20:
        t27a = state.regs[0];
        t27b = state.regs[2];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x00935b22: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935b2c;
    // 0x00935b24: 8b00 MOV
        batch_guest_pc = 0x00935b24u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x00935b26: 3bc1 CMP
        t30a = state.regs[0];
        t30b = state.regs[1];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x00935b28: 75f6 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00935b20;
    // 0x00935b2a: 8bc1 MOV
    L_00935b2a:
        t32 = state.regs[1];
        state.regs[0] = t32;
    // 0x00935b2c: 8b4804 MOV
    L_00935b2c:
        batch_guest_pc = 0x00935b2cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00935b2f: 8b10 MOV
        batch_guest_pc = 0x00935b2fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00935b31: 8911 MOV
        batch_guest_pc = 0x00935b31u;
        t35 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00935b33: 894a04 MOV
        batch_guest_pc = 0x00935b33u;
        t36 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00935b36: c70000000000 MOV
        batch_guest_pc = 0x00935b36u;
        t37 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00935b3c: c7400400000000 MOV
        batch_guest_pc = 0x00935b3cu;
        t38 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00935b43: 8b1530996601 MOV
    L_00935b43:
        batch_guest_pc = 0x00935b43u;
        if (!memory.load32(0x01669930u, t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x00935b49: 83c20c ADD
        t40a = state.regs[2];
        t40b = 0x0000000cu;
        t40r = static_cast<std::uint32_t>(t40a + t40b) & 0xffffffffu;
        batch_set_add_flags(state, t40a, t40b, t40r, 32u);
        state.regs[2] = t40r;
    // 0x00935b4c: 52 PUSH
        batch_guest_pc = 0x00935b4cu;
        t41a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00935b4d: ff15dcc23c01 CALL
        t42_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00935b53u);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00935b53u) return BatchLiftStatus::invalid_control_flow;
    // 0x00935b53: 807c240b00 CMP
        batch_guest_pc = 0x00935b53u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000bu), t43a)) return BatchLiftStatus::invalid_memory;
        t43b = 0x00000000u;
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0x000000ffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 8u);
    // 0x00935b58: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00935b5f;
    // 0x00935b5a: e811ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00935a70u, 0x00935b5fu)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_00935a70(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x00935b5fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00935b5f: 5e POP
    L_00935b5f:
        batch_guest_pc = 0x00935b5fu;
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t46a;
    // 0x00935b60: 8ac3 MOV
        t47 = state.regs[3] & 0x000000ffu;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t47 << 0u) & 0x000000ffu);
    // 0x00935b62: 5b POP
        batch_guest_pc = 0x00935b62u;
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t48a;
    // 0x00935b63: 59 POP
        batch_guest_pc = 0x00935b63u;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t49a;
    // 0x00935b64: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
