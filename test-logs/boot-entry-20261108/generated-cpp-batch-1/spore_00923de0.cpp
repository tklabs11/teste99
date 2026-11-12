#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009216a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923e19(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923de0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923de0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47r = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;

    // 0x00923de0: 807c241000 CMP
        batch_guest_pc = 0x00923de0u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0x000000ffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 8u);
    // 0x00923de5: 53 PUSH
        batch_guest_pc = 0x00923de5u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923de6: 55 PUSH
        batch_guest_pc = 0x00923de6u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923de7: 8b6c2410 MOV
        batch_guest_pc = 0x00923de7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t3;
    // 0x00923deb: 56 PUSH
        batch_guest_pc = 0x00923debu;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923dec: 57 PUSH
        batch_guest_pc = 0x00923decu;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923ded: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x00923def: 7526 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923e17;
    // 0x00923df1: 8d4604 LEA
        t8 = static_cast<std::uint32_t>(state.regs[6] + 0x00000004u);
        state.regs[0] = t8;
    // 0x00923df4: 3be8 CMP
        t9a = state.regs[5];
        t9b = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x00923df6: 741f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923e17;
    // 0x00923df8: 8b4510 MOV
        batch_guest_pc = 0x00923df8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00923dfb: 8b4c241c MOV
        batch_guest_pc = 0x00923dfbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x00923dff: 8b09 MOV
        batch_guest_pc = 0x00923dffu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00923e01: 50 PUSH
        batch_guest_pc = 0x00923e01u;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e02: 51 PUSH
        batch_guest_pc = 0x00923e02u;
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e03: ff15dcc43c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_stricmp", 0x013cc4dcu, 0x00923e09u);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00923e09u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923e09: 83c408 ADD
        t17a = state.regs[4];
        t17b = 0x00000008u;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[4] = t17r;
    // 0x00923e0c: 85c0 TEST
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x00923e0e: 7c07 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00923e17;
    // 0x00923e10: bb01000000 MOV
        t20 = 0x00000001u;
        state.regs[3] = t20;
    // 0x00923e15: eb02 JMP
        goto L_00923e19;
    // 0x00923e17: 33db XOR
    L_00923e17:
        t22a = state.regs[3];
        t22b = state.regs[3];
        t22r = (t22a ^ t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
        state.regs[3] = t22r;
    // 0x00923e19: 8b461c MOV
    L_00923e19:
        batch_guest_pc = 0x00923e19u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00923e1c: 8b4e18 MOV
        batch_guest_pc = 0x00923e1cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00923e1f: 8b11 MOV
        batch_guest_pc = 0x00923e1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x00923e21: 8b5208 MOV
        batch_guest_pc = 0x00923e21u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t26;
    // 0x00923e24: 50 PUSH
        batch_guest_pc = 0x00923e24u;
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e25: 6a00 PUSH
        batch_guest_pc = 0x00923e25u;
        t28a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e27: 6a18 PUSH
        batch_guest_pc = 0x00923e27u;
        t29a = 0x00000018u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e29: ffd2 CALL
        t30_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923e2bu);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
    // 0x00923e2b: 8bf8 MOV
        t31 = state.regs[0];
        state.regs[7] = t31;
    // 0x00923e2d: 8d4710 LEA
        t32 = static_cast<std::uint32_t>(state.regs[7] + 0x00000010u);
        state.regs[0] = t32;
    // 0x00923e30: 85c0 TEST
        t33a = state.regs[0];
        t33b = state.regs[0];
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x00923e32: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923e42;
    // 0x00923e34: 8b4c241c MOV
        batch_guest_pc = 0x00923e34u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x00923e38: 8b11 MOV
        batch_guest_pc = 0x00923e38u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00923e3a: 8910 MOV
        batch_guest_pc = 0x00923e3au;
        t37 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00923e3c: 8b4904 MOV
        batch_guest_pc = 0x00923e3cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x00923e3f: 894804 MOV
        batch_guest_pc = 0x00923e3fu;
        t39 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00923e42: 53 PUSH
    L_00923e42:
        batch_guest_pc = 0x00923e42u;
        t40a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e43: 8d5604 LEA
        t41 = static_cast<std::uint32_t>(state.regs[6] + 0x00000004u);
        state.regs[2] = t41;
    // 0x00923e46: 52 PUSH
        batch_guest_pc = 0x00923e46u;
        t42a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e47: 55 PUSH
        batch_guest_pc = 0x00923e47u;
        t43a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e48: 57 PUSH
        batch_guest_pc = 0x00923e48u;
        t44a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00923e49: e852d8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009216a0u, 0x00923e4eu)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_009216a0(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x00923e4eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923e4e: 8b442424 MOV
        batch_guest_pc = 0x00923e4eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x00923e52: ff4614 INC
        batch_guest_pc = 0x00923e52u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t47a)) return BatchLiftStatus::invalid_memory;
        t47r = static_cast<std::uint32_t>(t47a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t47a, t47r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t47r)) return BatchLiftStatus::invalid_memory;
    // 0x00923e55: 83c410 ADD
        t48a = state.regs[4];
        t48b = 0x00000010u;
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[4] = t48r;
    // 0x00923e58: 8938 MOV
        batch_guest_pc = 0x00923e58u;
        t49 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x00923e5a: 5f POP
        batch_guest_pc = 0x00923e5au;
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t50a;
    // 0x00923e5b: 5e POP
        batch_guest_pc = 0x00923e5bu;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t51a;
    // 0x00923e5c: 5d POP
        batch_guest_pc = 0x00923e5cu;
        if (!memory.load32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t52a;
    // 0x00923e5d: 5b POP
        batch_guest_pc = 0x00923e5du;
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t53a;
    // 0x00923e5e: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
