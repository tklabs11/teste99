#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923630(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923990(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923990u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42 = 0;
    BatchLiftStatus t43_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    BatchLiftStatus t60_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;

    // 0x00923990: 83ec1c SUB
        t0a = state.regs[4];
        t0b = 0x0000001cu;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00923993: 55 PUSH
        batch_guest_pc = 0x00923993u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923994: 56 PUSH
        batch_guest_pc = 0x00923994u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923995: 57 PUSH
        batch_guest_pc = 0x00923995u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00923996: 8b7c2430 MOV
        batch_guest_pc = 0x00923996u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x0092399a: 33ed XOR
        t5a = state.regs[5];
        t5b = state.regs[5];
        t5r = (t5a ^ t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[5] = t5r;
    // 0x0092399c: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x0092399e: 896c240c MOV
        batch_guest_pc = 0x0092399eu;
        t7 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009239a2: 85ff TEST
        t8a = state.regs[7];
        t8b = state.regs[7];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x009239a4: 0f84a0000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923a4a;
    // 0x009239aa: 53 PUSH
        batch_guest_pc = 0x009239aau;
        t10a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x009239ab: 8d5e34 LEA
        t11 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[3] = t11;
    // 0x009239ae: 6878dc4301 PUSH
        batch_guest_pc = 0x009239aeu;
        t12a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x009239b3: 8bcb MOV
        t13 = state.regs[3];
        state.regs[1] = t13;
    // 0x009239b5: 895c2438 MOV
        batch_guest_pc = 0x009239b5u;
        t14 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009239b9: e8f2e7ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x009239beu)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_009221b0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x009239beu) return BatchLiftStatus::invalid_control_flow;
    // 0x009239be: 807e0400 CMP
        batch_guest_pc = 0x009239beu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t16a)) return BatchLiftStatus::invalid_memory;
        t16b = 0x00000000u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0x000000ffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 8u);
    // 0x009239c2: 757e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923a42;
    // 0x009239c4: 8b4610 MOV
        batch_guest_pc = 0x009239c4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x009239c7: 8b4c2430 MOV
        batch_guest_pc = 0x009239c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x009239cb: 8d5001 LEA
        t20 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t20;
    // 0x009239ce: 8944241c MOV
        batch_guest_pc = 0x009239ceu;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009239d2: c6460401 MOV
        batch_guest_pc = 0x009239d2u;
        t22 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x009239d6: 895610 MOV
        batch_guest_pc = 0x009239d6u;
        t23 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x009239d9: 8b410c MOV
        batch_guest_pc = 0x009239d9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x009239dc: 894c2420 MOV
        batch_guest_pc = 0x009239dcu;
        t25 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x009239e0: 50 PUSH
        batch_guest_pc = 0x009239e0u;
        t26a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x009239e1: 8d4efc LEA
        t27 = static_cast<std::uint32_t>(state.regs[6] + 0xfffffffcu);
        state.regs[1] = t27;
    // 0x009239e4: c74424187cdc4301 MOV
        batch_guest_pc = 0x009239e4u;
        t28 = 0x0143dc7cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x009239ec: 896c241c MOV
        batch_guest_pc = 0x009239ecu;
        t29 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t29)) return BatchLiftStatus::invalid_memory;
    // 0x009239f0: 897c2428 MOV
        batch_guest_pc = 0x009239f0u;
        t30 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x009239f4: e837fcffff CALL
        if (!batch_guest_call32(memory, state, 0x00923630u, 0x009239f9u)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_00923630(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x009239f9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009239f9: 8b7e14 MOV
        batch_guest_pc = 0x009239f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t32;
    // 0x009239fc: 8b5e18 MOV
        batch_guest_pc = 0x009239fcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t33;
    // 0x009239ff: 89442428 MOV
        batch_guest_pc = 0x009239ffu;
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00923a03: 3bfb CMP
        t35a = state.regs[7];
        t35b = state.regs[3];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x00923a05: 7433 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923a3a;
    // 0x00923a07: 8b2f MOV
    L_00923a07:
        batch_guest_pc = 0x00923a07u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t37;
    // 0x00923a09: 8b5500 MOV
        batch_guest_pc = 0x00923a09u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00923a0c: 8b5210 MOV
        batch_guest_pc = 0x00923a0cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x00923a0f: 8d442414 LEA
        t40 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t40;
    // 0x00923a13: 50 PUSH
        batch_guest_pc = 0x00923a13u;
        t41a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a14: 8bcd MOV
        t42 = state.regs[5];
        state.regs[1] = t42;
    // 0x00923a16: ffd2 CALL
        t43_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923a18u);
        if (t43_call_status != BatchLiftStatus::returned) return t43_call_status;
    // 0x00923a18: 84c0 TEST
        t44a = state.regs[0] & 0x000000ffu;
        t44b = state.regs[0] & 0x000000ffu;
        t44r = (t44a & t44b) & 0x000000ffu;
        batch_set_logic_flags(state, t44r, 8u);
    // 0x00923a1a: 7513 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923a2f;
    // 0x00923a1c: 8b4500 MOV
        batch_guest_pc = 0x00923a1cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x00923a1f: 8b5018 MOV
        batch_guest_pc = 0x00923a1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x00923a22: 8d4c2414 LEA
        t48 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[1] = t48;
    // 0x00923a26: 51 PUSH
        batch_guest_pc = 0x00923a26u;
        t49a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00923a27: 8bcd MOV
        t50 = state.regs[5];
        state.regs[1] = t50;
    // 0x00923a29: ffd2 CALL
        t51_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923a2bu);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
    // 0x00923a2b: 09442410 OR
        batch_guest_pc = 0x00923a2bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t52a)) return BatchLiftStatus::invalid_memory;
        t52b = state.regs[0];
        t52r = (t52a | t52b) & 0xffffffffu;
        batch_set_logic_flags(state, t52r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t52r)) return BatchLiftStatus::invalid_memory;
    // 0x00923a2f: 83c704 ADD
    L_00923a2f:
        t53a = state.regs[7];
        t53b = 0x00000004u;
        t53r = static_cast<std::uint32_t>(t53a + t53b) & 0xffffffffu;
        batch_set_add_flags(state, t53a, t53b, t53r, 32u);
        state.regs[7] = t53r;
    // 0x00923a32: 3bfb CMP
        t54a = state.regs[7];
        t54b = state.regs[3];
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0xffffffffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 32u);
    // 0x00923a34: 75d1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923a07;
    // 0x00923a36: 8b6c2410 MOV
        batch_guest_pc = 0x00923a36u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t56;
    // 0x00923a3a: 8b5c2434 MOV
    L_00923a3a:
        batch_guest_pc = 0x00923a3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t57;
    // 0x00923a3e: c6460400 MOV
        batch_guest_pc = 0x00923a3eu;
        t58 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00923a42: 8bcb MOV
    L_00923a42:
        t59 = state.regs[3];
        state.regs[1] = t59;
    // 0x00923a44: e827e8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00923a49u)) return BatchLiftStatus::invalid_memory;
        t60_call_status = spore_lift_00922270(memory, state);
        if (t60_call_status != BatchLiftStatus::returned) return t60_call_status;
        if (state.eip != 0x00923a49u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923a49: 5b POP
        batch_guest_pc = 0x00923a49u;
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t61a;
    // 0x00923a4a: 5f POP
    L_00923a4a:
        batch_guest_pc = 0x00923a4au;
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t62a;
    // 0x00923a4b: 5e POP
        batch_guest_pc = 0x00923a4bu;
        if (!memory.load32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t63a;
    // 0x00923a4c: 8bc5 MOV
        t64 = state.regs[5];
        state.regs[0] = t64;
    // 0x00923a4e: 5d POP
        batch_guest_pc = 0x00923a4eu;
        if (!memory.load32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t65a;
    // 0x00923a4f: 83c41c ADD
        t66a = state.regs[4];
        t66b = 0x0000001cu;
        t66r = static_cast<std::uint32_t>(t66a + t66b) & 0xffffffffu;
        batch_set_add_flags(state, t66a, t66b, t66r, 32u);
        state.regs[4] = t66r;
    // 0x00923a52: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
