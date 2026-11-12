#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_007611f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922130(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009255f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092584c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925880(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009257a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009257a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0, t49c = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    BatchLiftStatus t55_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0, t67c = 0, t67r = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t81a = 0;
    BatchLiftStatus t82_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t83a = 0, t83b = 0, t83r = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t94a = 0;
    std::uint32_t t95a = 0;
    std::uint32_t t96a = 0;
    BatchLiftStatus t97_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t98a = 0, t98c = 0, t98r = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0;
    BatchLiftStatus t112_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t113a = 0, t113c = 0, t113r = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t119a = 0, t119b = 0, t119r = 0;
    std::uint32_t t121a = 0;
    BatchLiftStatus t122_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t123a = 0, t123b = 0, t123r = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127a = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131a = 0;
    std::uint32_t t132a = 0;
    std::uint32_t t133a = 0;

    // 0x009257a0: 56 PUSH
        batch_guest_pc = 0x009257a0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009257a1: 57 PUSH
        batch_guest_pc = 0x009257a1u;
        t1a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009257a2: 8bf9 MOV
        t2 = state.regs[1];
        state.regs[7] = t2;
    // 0x009257a4: e847feffff CALL
        if (!batch_guest_call32(memory, state, 0x009255f0u, 0x009257a9u)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_009255f0(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x009257a9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009257a9: 8b4738 MOV
        batch_guest_pc = 0x009257a9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x009257ac: 8b4f34 MOV
        batch_guest_pc = 0x009257acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000034u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x009257af: 8d7730 LEA
        t6 = static_cast<std::uint32_t>(state.regs[7] + 0x00000030u);
        state.regs[6] = t6;
    // 0x009257b2: 50 PUSH
        batch_guest_pc = 0x009257b2u;
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x009257b3: 51 PUSH
        batch_guest_pc = 0x009257b3u;
        t8a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x009257b4: 8bce MOV
        t9 = state.regs[6];
        state.regs[1] = t9;
    // 0x009257b6: e835bae3ff CALL
        if (!batch_guest_call32(memory, state, 0x007611f0u, 0x009257bbu)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_007611f0(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x009257bbu) return BatchLiftStatus::invalid_control_flow;
    // 0x009257bb: 837e0801 CMP
        batch_guest_pc = 0x009257bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = 0x00000001u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x009257bf: c7460c00000000 MOV
        batch_guest_pc = 0x009257bfu;
        t12 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009257c6: 760c JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009257d4;
    // 0x009257c8: 8b5604 MOV
        batch_guest_pc = 0x009257c8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x009257cb: 52 PUSH
        batch_guest_pc = 0x009257cbu;
        t15a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x009257cc: e8af1b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009257d1u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00f47380(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x009257d1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009257d1: 83c404 ADD
        t17a = state.regs[4];
        t17b = 0x00000004u;
        t17r = static_cast<std::uint32_t>(t17a + t17b) & 0xffffffffu;
        batch_set_add_flags(state, t17a, t17b, t17r, 32u);
        state.regs[4] = t17r;
    // 0x009257d4: 8bcf MOV
    L_009257d4:
        t18 = state.regs[7];
        state.regs[1] = t18;
    // 0x009257d6: 5f POP
        batch_guest_pc = 0x009257d6u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t19a;
    // 0x009257d7: 5e POP
        batch_guest_pc = 0x009257d7u;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x009257d8: e953c9ffff JMP
        state.eip = 0x00922130u;
        return spore_lift_00922130(memory, state);
    // 0x009257dd: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009257de: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009257df: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x009257e0: 51 PUSH
        batch_guest_pc = 0x009257e0u;
        t25a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e1: 53 PUSH
        batch_guest_pc = 0x009257e1u;
        t26a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e2: 56 PUSH
        batch_guest_pc = 0x009257e2u;
        t27a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e3: 8bf1 MOV
        t28 = state.regs[1];
        state.regs[6] = t28;
    // 0x009257e5: 8b4604 MOV
        batch_guest_pc = 0x009257e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x009257e8: 57 PUSH
        batch_guest_pc = 0x009257e8u;
        t30a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e9: 3b4608 CMP
        batch_guest_pc = 0x009257e9u;
        t31a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t31b)) return BatchLiftStatus::invalid_memory;
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x009257ec: 744a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925838;
    // 0x009257ee: 8b4c2418 MOV
        batch_guest_pc = 0x009257eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x009257f2: 8b7c2414 MOV
        batch_guest_pc = 0x009257f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t34;
    // 0x009257f6: 8bd9 MOV
        t35 = state.regs[1];
        state.regs[3] = t35;
    // 0x009257f8: 3bcf CMP
        t36a = state.regs[1];
        t36b = state.regs[7];
        t36r = static_cast<std::uint32_t>(t36a - t36b) & 0xffffffffu;
        batch_set_sub_flags(state, t36a, t36b, t36r, 32u);
    // 0x009257fa: 7207 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925803;
    // 0x009257fc: 3bc8 CMP
        t38a = state.regs[1];
        t38b = state.regs[0];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x009257fe: 7303 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00925803;
    // 0x00925800: 8d5904 LEA
        t40 = static_cast<std::uint32_t>(state.regs[1] + 0x00000004u);
        state.regs[3] = t40;
    // 0x00925803: 85c0 TEST
    L_00925803:
        t41a = state.regs[0];
        t41b = state.regs[0];
        t41r = (t41a & t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
    // 0x00925805: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092580c;
    // 0x00925807: 8b48fc MOV
        batch_guest_pc = 0x00925807u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x0092580a: 8908 MOV
        batch_guest_pc = 0x0092580au;
        t44 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x0092580c: 8b4e04 MOV
    L_0092580c:
        batch_guest_pc = 0x0092580cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x0092580f: 8d41fc LEA
        t46 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu);
        state.regs[0] = t46;
    // 0x00925812: 2bc7 SUB
        t47a = state.regs[0];
        t47b = state.regs[7];
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
        state.regs[0] = t47r;
    // 0x00925814: 50 PUSH
        batch_guest_pc = 0x00925814u;
        t48a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00925815: c1f802 SAR
        t49a = state.regs[0];
        t49c = 2u;
        if (t49c != 0u) {
        t49r = (t49a >> t49c) | ((t49a & 0x80000000u) ? (0xffffffffu << (32u - t49c)) : 0u);
        batch_set_sar_flags(state, t49a, t49c, t49r, 32u);
            state.regs[0] = t49r;
        }
    // 0x00925818: 03c0 ADD
        t50a = state.regs[0];
        t50b = state.regs[0];
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[0] = t50r;
    // 0x0092581a: 03c0 ADD
        t51a = state.regs[0];
        t51b = state.regs[0];
        t51r = static_cast<std::uint32_t>(t51a + t51b) & 0xffffffffu;
        batch_set_add_flags(state, t51a, t51b, t51r, 32u);
        state.regs[0] = t51r;
    // 0x0092581c: 2bc8 SUB
        t52a = state.regs[1];
        t52b = state.regs[0];
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
        state.regs[1] = t52r;
    // 0x0092581e: 57 PUSH
        batch_guest_pc = 0x0092581eu;
        t53a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x0092581f: 51 PUSH
        batch_guest_pc = 0x0092581fu;
        t54a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00925820: ff1580c43c01 CALL
        t55_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x00925826u);
        if (t55_call_status != BatchLiftStatus::returned) return t55_call_status;
        if (state.eip != 0x00925826u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925826: 8b13 MOV
        batch_guest_pc = 0x00925826u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t56;
    // 0x00925828: 83c40c ADD
        t57a = state.regs[4];
        t57b = 0x0000000cu;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[4] = t57r;
    // 0x0092582b: 8917 MOV
        batch_guest_pc = 0x0092582bu;
        t58 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x0092582d: 83460404 ADD
        batch_guest_pc = 0x0092582du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t59a)) return BatchLiftStatus::invalid_memory;
        t59b = 0x00000004u;
        t59r = static_cast<std::uint32_t>(t59a + t59b) & 0xffffffffu;
        batch_set_add_flags(state, t59a, t59b, t59r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t59r)) return BatchLiftStatus::invalid_memory;
    // 0x00925831: 5f POP
        batch_guest_pc = 0x00925831u;
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t60a;
    // 0x00925832: 5e POP
        batch_guest_pc = 0x00925832u;
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t61a;
    // 0x00925833: 5b POP
        batch_guest_pc = 0x00925833u;
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t62a;
    // 0x00925834: 59 POP
        batch_guest_pc = 0x00925834u;
        if (!memory.load32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t63a;
    // 0x00925835: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925838: 2b06 SUB
    L_00925838:
        batch_guest_pc = 0x00925838u;
        t65a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t65b)) return BatchLiftStatus::invalid_memory;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
        state.regs[0] = t65r;
    // 0x0092583a: 55 PUSH
        batch_guest_pc = 0x0092583au;
        t66a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
    // 0x0092583b: c1f802 SAR
        t67a = state.regs[0];
        t67c = 2u;
        if (t67c != 0u) {
        t67r = (t67a >> t67c) | ((t67a & 0x80000000u) ? (0xffffffffu << (32u - t67c)) : 0u);
        batch_set_sar_flags(state, t67a, t67c, t67r, 32u);
            state.regs[0] = t67r;
        }
    // 0x0092583e: 85c0 TEST
        t68a = state.regs[0];
        t68b = state.regs[0];
        t68r = (t68a & t68b) & 0xffffffffu;
        batch_set_logic_flags(state, t68r, 32u);
    // 0x00925840: 762e JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925870;
    // 0x00925842: 03c0 ADD
        t70a = state.regs[0];
        t70b = state.regs[0];
        t70r = static_cast<std::uint32_t>(t70a + t70b) & 0xffffffffu;
        batch_set_add_flags(state, t70a, t70b, t70r, 32u);
        state.regs[0] = t70r;
    // 0x00925844: 89442410 MOV
        batch_guest_pc = 0x00925844u;
        t71 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00925848: 85c0 TEST
        t72a = state.regs[0];
        t72b = state.regs[0];
        t72r = (t72a & t72b) & 0xffffffffu;
        batch_set_logic_flags(state, t72r, 32u);
    // 0x0092584a: 7432 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092587e;
    // 0x0092584c: 68d1000000 PUSH
    L_0092584c:
        batch_guest_pc = 0x0092584cu;
        t74a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
    // 0x00925851: 6838bb3e01 PUSH
        batch_guest_pc = 0x00925851u;
        t75a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x00925856: 6a00 PUSH
        batch_guest_pc = 0x00925856u;
        t76a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x00925858: 6a00 PUSH
        batch_guest_pc = 0x00925858u;
        t77a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
    // 0x0092585a: 03c0 ADD
        t78a = state.regs[0];
        t78b = state.regs[0];
        t78r = static_cast<std::uint32_t>(t78a + t78b) & 0xffffffffu;
        batch_set_add_flags(state, t78a, t78b, t78r, 32u);
        state.regs[0] = t78r;
    // 0x0092585c: 03c0 ADD
        t79a = state.regs[0];
        t79b = state.regs[0];
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[0] = t79r;
    // 0x0092585e: 6800e04301 PUSH
        batch_guest_pc = 0x0092585eu;
        t80a = 0x0143e000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x00925863: 50 PUSH
        batch_guest_pc = 0x00925863u;
        t81a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x00925864: e8371b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00925869u)) return BatchLiftStatus::invalid_memory;
        t82_call_status = spore_lift_00f473a0(memory, state);
        if (t82_call_status != BatchLiftStatus::returned) return t82_call_status;
        if (state.eip != 0x00925869u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925869: 83c418 ADD
        t83a = state.regs[4];
        t83b = 0x00000018u;
        t83r = static_cast<std::uint32_t>(t83a + t83b) & 0xffffffffu;
        batch_set_add_flags(state, t83a, t83b, t83r, 32u);
        state.regs[4] = t83r;
    // 0x0092586c: 8be8 MOV
        t84 = state.regs[0];
        state.regs[5] = t84;
    // 0x0092586e: eb10 JMP
        goto L_00925880;
    // 0x00925870: c744241001000000 MOV
    L_00925870:
        batch_guest_pc = 0x00925870u;
        t86 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t86)) return BatchLiftStatus::invalid_memory;
    // 0x00925878: 8b442410 MOV
        batch_guest_pc = 0x00925878u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t87;
    // 0x0092587c: ebce JMP
        goto L_0092584c;
    // 0x0092587e: 33ed XOR
    L_0092587e:
        t89a = state.regs[5];
        t89b = state.regs[5];
        t89r = (t89a ^ t89b) & 0xffffffffu;
        batch_set_logic_flags(state, t89r, 32u);
        state.regs[5] = t89r;
    // 0x00925880: 8b06 MOV
    L_00925880:
        batch_guest_pc = 0x00925880u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t90;
    // 0x00925882: 8b5c2418 MOV
        batch_guest_pc = 0x00925882u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t91;
    // 0x00925886: 8bfb MOV
        t92 = state.regs[3];
        state.regs[7] = t92;
    // 0x00925888: 2bf8 SUB
        t93a = state.regs[7];
        t93b = state.regs[0];
        t93r = static_cast<std::uint32_t>(t93a - t93b) & 0xffffffffu;
        batch_set_sub_flags(state, t93a, t93b, t93r, 32u);
        state.regs[7] = t93r;
    // 0x0092588a: 57 PUSH
        batch_guest_pc = 0x0092588au;
        t94a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t94a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588b: 50 PUSH
        batch_guest_pc = 0x0092588bu;
        t95a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t95a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588c: 55 PUSH
        batch_guest_pc = 0x0092588cu;
        t96a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588d: e8b2ae8b00 CALL
        t97_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00925892u);
        if (t97_call_status != BatchLiftStatus::returned) return t97_call_status;
        if (state.eip != 0x00925892u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925892: c1ff02 SAR
        t98a = state.regs[7];
        t98c = 2u;
        if (t98c != 0u) {
        t98r = (t98a >> t98c) | ((t98a & 0x80000000u) ? (0xffffffffu << (32u - t98c)) : 0u);
        batch_set_sar_flags(state, t98a, t98c, t98r, 32u);
            state.regs[7] = t98r;
        }
    // 0x00925895: 8d04b8 LEA
        t99 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u);
        state.regs[0] = t99;
    // 0x00925898: 83c40c ADD
        t100a = state.regs[4];
        t100b = 0x0000000cu;
        t100r = static_cast<std::uint32_t>(t100a + t100b) & 0xffffffffu;
        batch_set_add_flags(state, t100a, t100b, t100r, 32u);
        state.regs[4] = t100r;
    // 0x0092589b: 85c0 TEST
        t101a = state.regs[0];
        t101b = state.regs[0];
        t101r = (t101a & t101b) & 0xffffffffu;
        batch_set_logic_flags(state, t101r, 32u);
    // 0x0092589d: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258a7;
    // 0x0092589f: 8b4c241c MOV
        batch_guest_pc = 0x0092589fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t103;
    // 0x009258a3: 8b11 MOV
        batch_guest_pc = 0x009258a3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t104;
    // 0x009258a5: 8910 MOV
        batch_guest_pc = 0x009258a5u;
        t105 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x009258a7: 8b7e04 MOV
    L_009258a7:
        batch_guest_pc = 0x009258a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t106;
    // 0x009258aa: 2bfb SUB
        t107a = state.regs[7];
        t107b = state.regs[3];
        t107r = static_cast<std::uint32_t>(t107a - t107b) & 0xffffffffu;
        batch_set_sub_flags(state, t107a, t107b, t107r, 32u);
        state.regs[7] = t107r;
    // 0x009258ac: 57 PUSH
        batch_guest_pc = 0x009258acu;
        t108a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
    // 0x009258ad: 83c004 ADD
        t109a = state.regs[0];
        t109b = 0x00000004u;
        t109r = static_cast<std::uint32_t>(t109a + t109b) & 0xffffffffu;
        batch_set_add_flags(state, t109a, t109b, t109r, 32u);
        state.regs[0] = t109r;
    // 0x009258b0: 53 PUSH
        batch_guest_pc = 0x009258b0u;
        t110a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
    // 0x009258b1: 50 PUSH
        batch_guest_pc = 0x009258b1u;
        t111a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
    // 0x009258b2: e88dae8b00 CALL
        t112_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009258b7u);
        if (t112_call_status != BatchLiftStatus::returned) return t112_call_status;
        if (state.eip != 0x009258b7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009258b7: c1ff02 SAR
        t113a = state.regs[7];
        t113c = 2u;
        if (t113c != 0u) {
        t113r = (t113a >> t113c) | ((t113a & 0x80000000u) ? (0xffffffffu << (32u - t113c)) : 0u);
        batch_set_sar_flags(state, t113a, t113c, t113r, 32u);
            state.regs[7] = t113r;
        }
    // 0x009258ba: 8d3cb8 LEA
        t114 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u);
        state.regs[7] = t114;
    // 0x009258bd: 8b06 MOV
        batch_guest_pc = 0x009258bdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t115;
    // 0x009258bf: 83c40c ADD
        t116a = state.regs[4];
        t116b = 0x0000000cu;
        t116r = static_cast<std::uint32_t>(t116a + t116b) & 0xffffffffu;
        batch_set_add_flags(state, t116a, t116b, t116r, 32u);
        state.regs[4] = t116r;
    // 0x009258c2: 85c0 TEST
        t117a = state.regs[0];
        t117b = state.regs[0];
        t117r = (t117a & t117b) & 0xffffffffu;
        batch_set_logic_flags(state, t117r, 32u);
    // 0x009258c4: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258d5;
    // 0x009258c6: 8378fc00 CMP
        batch_guest_pc = 0x009258c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t119a)) return BatchLiftStatus::invalid_memory;
        t119b = 0x00000000u;
        t119r = static_cast<std::uint32_t>(t119a - t119b) & 0xffffffffu;
        batch_set_sub_flags(state, t119a, t119b, t119r, 32u);
    // 0x009258ca: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258d5;
    // 0x009258cc: 50 PUSH
        batch_guest_pc = 0x009258ccu;
        t121a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
    // 0x009258cd: e8ae1a6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009258d2u)) return BatchLiftStatus::invalid_memory;
        t122_call_status = spore_lift_00f47380(memory, state);
        if (t122_call_status != BatchLiftStatus::returned) return t122_call_status;
        if (state.eip != 0x009258d2u) return BatchLiftStatus::invalid_control_flow;
    // 0x009258d2: 83c404 ADD
        t123a = state.regs[4];
        t123b = 0x00000004u;
        t123r = static_cast<std::uint32_t>(t123a + t123b) & 0xffffffffu;
        batch_set_add_flags(state, t123a, t123b, t123r, 32u);
        state.regs[4] = t123r;
    // 0x009258d5: 8b442410 MOV
    L_009258d5:
        batch_guest_pc = 0x009258d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t124;
    // 0x009258d9: 892e MOV
        batch_guest_pc = 0x009258d9u;
        t125 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t125)) return BatchLiftStatus::invalid_memory;
    // 0x009258db: 8d4c8500 LEA
        t126 = static_cast<std::uint32_t>(state.regs[5] + state.regs[0] * 4u + 0x00000000u);
        state.regs[1] = t126;
    // 0x009258df: 5d POP
        batch_guest_pc = 0x009258dfu;
        if (!memory.load32(state.regs[4], t127a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t127a;
    // 0x009258e0: 897e04 MOV
        batch_guest_pc = 0x009258e0u;
        t128 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t128)) return BatchLiftStatus::invalid_memory;
    // 0x009258e3: 5f POP
        batch_guest_pc = 0x009258e3u;
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t129a;
    // 0x009258e4: 894e08 MOV
        batch_guest_pc = 0x009258e4u;
        t130 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x009258e7: 5e POP
        batch_guest_pc = 0x009258e7u;
        if (!memory.load32(state.regs[4], t131a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t131a;
    // 0x009258e8: 5b POP
        batch_guest_pc = 0x009258e8u;
        if (!memory.load32(state.regs[4], t132a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t132a;
    // 0x009258e9: 59 POP
        batch_guest_pc = 0x009258e9u;
        if (!memory.load32(state.regs[4], t133a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t133a;
    // 0x009258ea: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
