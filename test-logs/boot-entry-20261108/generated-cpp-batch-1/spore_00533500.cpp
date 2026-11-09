#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0042f530(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00533546(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0053354f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00533500(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00533500u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0;
    BatchLiftStatus t46_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0, t51c = 0, t51r = 0;
    std::uint32_t t52a = 0, t52c = 0, t52r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;

    // 0x00533500: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00533501: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00533503: 83ec20 SUB
        t2a = state.regs[4];
        t2b = 0x00000020u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00533506: 894de0 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00533509: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0053350c: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0053350f: 894dec MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00533512: c645fa00 MOV
        t7 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffau), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00533516: c645fb00 MOV
        t8 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffbu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x0053351a: c645f900 MOV
        t9 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff9u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0053351e: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t10;
    // 0x00533521: 52 PUSH
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00533522: 8b45ec MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00533525: 50 PUSH
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00533526: 8b4d0c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00533529: 51 PUSH
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0053352a: e801c0efff CALL
        if (!batch_guest_call32(memory, state, 0x0042f530u, 0x0053352fu)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_0042f530(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0053352fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0053352f: 83c40c ADD
        t17a = state.regs[4];
        t17b = 0x0000000cu;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[4] = t17r;
    // 0x00533532: 8945fc MOV
        t18 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00533535: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t19;
    // 0x00533538: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x0053353b: 8945e4 MOV
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x0053353e: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00533541: 894de8 MOV
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00533544: eb09 JMP
        goto L_0053354f;
    // 0x00533546: 8b55e8 MOV
    L_00533546:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x00533549: 83c204 ADD
        t26a = state.regs[2];
        t26b = 0x00000004u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[2] = t26r;
    // 0x0053354c: 8955e8 MOV
        t27 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x0053354f: 8b45e8 MOV
    L_0053354f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00533552: 3b45e4 CMP
        t29a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t29b)) return BatchLiftStatus::invalid_memory;
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x00533555: 732e JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00533585;
    // 0x00533557: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x0053355a: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t32a)) return BatchLiftStatus::invalid_memory;
        t32b = 0x00000000u;
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
    // 0x0053355d: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00533570;
    // 0x0053355f: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00533562: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x00533564: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t36;
    // 0x00533567: 8b09 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t37;
    // 0x00533569: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x0053356b: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x0053356e: ffd0 CALL
        t40_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00533570u);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
    // 0x00533570: 33c9 XOR
    L_00533570:
        t41a = state.regs[1];
        t41b = state.regs[1];
        t41r = (t41a ^ t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
        state.regs[1] = t41r;
    // 0x00533572: 83e101 AND
        t42a = state.regs[1];
        t42b = 0x00000001u;
        t42r = (t42a & t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
        state.regs[1] = t42r;
    // 0x00533575: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00533583;
    // 0x00533577: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t44;
    // 0x0053357a: 52 PUSH
        t45a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x0053357b: e8003ea100 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00533580u)) return BatchLiftStatus::invalid_memory;
        t46_call_status = spore_lift_00f47380(memory, state);
        if (t46_call_status != BatchLiftStatus::returned) return t46_call_status;
        if (state.eip != 0x00533580u) return BatchLiftStatus::invalid_control_flow;
    // 0x00533580: 83c404 ADD
        t47a = state.regs[4];
        t47b = 0x00000004u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[4] = t47r;
    // 0x00533583: ebc1 JMP
    L_00533583:
        goto L_00533546;
    // 0x00533585: 8b450c MOV
    L_00533585:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t49;
    // 0x00533588: 2b4508 SUB
        t50a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t50b)) return BatchLiftStatus::invalid_memory;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0xffffffffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 32u);
        state.regs[0] = t50r;
    // 0x0053358b: c1f802 SAR
        t51a = state.regs[0];
        t51c = 2u;
        if (t51c != 0u) {
        t51r = (t51a >> t51c) | ((t51a & 0x80000000u) ? (0xffffffffu << (32u - t51c)) : 0u);
        batch_set_sar_flags(state, t51a, t51c, t51r, 32u);
            state.regs[0] = t51r;
        }
    // 0x0053358e: c1e002 SHL
        t52a = state.regs[0];
        t52c = 2u;
        if (t52c != 0u) {
        t52r = static_cast<std::uint32_t>(t52a << t52c) & 0xffffffffu;
        batch_set_shl_flags(state, t52a, t52c, t52r, 32u);
            state.regs[0] = t52r;
        }
    // 0x00533591: 8b4de0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53;
    // 0x00533594: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t54;
    // 0x00533597: 2bd0 SUB
        t55a = state.regs[2];
        t55b = state.regs[0];
        t55r = static_cast<std::uint32_t>(t55a - t55b) & 0xffffffffu;
        batch_set_sub_flags(state, t55a, t55b, t55r, 32u);
        state.regs[2] = t55r;
    // 0x00533599: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x0053359c: 895004 MOV
        t57 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x0053359f: 8b4508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t58;
    // 0x005335a2: 8be5 MOV
        t59 = state.regs[5];
        state.regs[4] = t59;
    // 0x005335a4: 5d POP
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t60a;
    // 0x005335a5: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
