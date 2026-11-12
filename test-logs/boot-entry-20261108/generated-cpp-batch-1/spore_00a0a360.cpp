#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00a0a3f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a0a42c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00ac97a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a0a360(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00a0a360u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58a = 0, t58c = 0, t58r = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71a = 0;
    std::uint32_t t72a = 0;
    BatchLiftStatus t73_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87a = 0;
    std::uint32_t t88a = 0;
    BatchLiftStatus t89_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t90a = 0, t90c = 0, t90r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    BatchLiftStatus t102_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0, t104b = 0, t104r = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108a = 0;
    BatchLiftStatus t109_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t110a = 0, t110c = 0, t110r = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t118a = 0;
    BatchLiftStatus t119_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t120a = 0, t120b = 0, t120r = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127a = 0;
    std::uint32_t t128a = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130a = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;

    // 0x00a0a360: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00a0a363: 53 PUSH
        batch_guest_pc = 0x00a0a363u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a364: 55 PUSH
        batch_guest_pc = 0x00a0a364u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a365: 56 PUSH
        batch_guest_pc = 0x00a0a365u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a366: 57 PUSH
        batch_guest_pc = 0x00a0a366u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a367: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x00a0a369: 8b4704 MOV
        batch_guest_pc = 0x00a0a369u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00a0a36c: 3b4708 CMP
        batch_guest_pc = 0x00a0a36cu;
        t7a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t7b)) return BatchLiftStatus::invalid_memory;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00a0a36f: 746c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a3dd;
    // 0x00a0a371: 8b4c2420 MOV
        batch_guest_pc = 0x00a0a371u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00a0a375: 8b6c241c MOV
        batch_guest_pc = 0x00a0a375u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t10;
    // 0x00a0a379: 8bf1 MOV
        t11 = state.regs[1];
        state.regs[6] = t11;
    // 0x00a0a37b: 3bcd CMP
        t12a = state.regs[1];
        t12b = state.regs[5];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00a0a37d: 7207 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00a0a386;
    // 0x00a0a37f: 3bc8 CMP
        t14a = state.regs[1];
        t14b = state.regs[0];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x00a0a381: 7303 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00a0a386;
    // 0x00a0a383: 8d7104 LEA
        t16 = static_cast<std::uint32_t>(state.regs[1] + 0x00000004u);
        state.regs[6] = t16;
    // 0x00a0a386: 85c0 TEST
    L_00a0a386:
        t17a = state.regs[0];
        t17b = state.regs[0];
        t17r = (t17a & t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
    // 0x00a0a388: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a399;
    // 0x00a0a38a: 8b48fc MOV
        batch_guest_pc = 0x00a0a38au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00a0a38d: 8908 MOV
        batch_guest_pc = 0x00a0a38du;
        t20 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a38f: 85c9 TEST
        t21a = state.regs[1];
        t21b = state.regs[1];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x00a0a391: 7406 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a399;
    // 0x00a0a393: 8b01 MOV
        batch_guest_pc = 0x00a0a393u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00a0a395: 8b10 MOV
        batch_guest_pc = 0x00a0a395u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x00a0a397: ffd2 CALL
        t25_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00a0a399u);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
    // 0x00a0a399: 8b4704 MOV
    L_00a0a399:
        batch_guest_pc = 0x00a0a399u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00a0a39c: 50 PUSH
        batch_guest_pc = 0x00a0a39cu;
        t27a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a39d: 83c0fc ADD
        t28a = state.regs[0];
        t28b = 0xfffffffcu;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[0] = t28r;
    // 0x00a0a3a0: 50 PUSH
        batch_guest_pc = 0x00a0a3a0u;
        t29a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3a1: 55 PUSH
        batch_guest_pc = 0x00a0a3a1u;
        t30a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3a2: e8f9f30b00 CALL
        if (!batch_guest_call32(memory, state, 0x00ac97a0u, 0x00a0a3a7u)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_00ac97a0(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00a0a3a7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a0a3a7: 8b36 MOV
        batch_guest_pc = 0x00a0a3a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t32;
    // 0x00a0a3a9: 8b5d00 MOV
        batch_guest_pc = 0x00a0a3a9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t33;
    // 0x00a0a3ac: 83c40c ADD
        t34a = state.regs[4];
        t34b = 0x0000000cu;
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        state.regs[4] = t34r;
    // 0x00a0a3af: 3bf3 CMP
        t35a = state.regs[6];
        t35b = state.regs[3];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x00a0a3b1: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a3cf;
    // 0x00a0a3b3: 85f6 TEST
        t37a = state.regs[6];
        t37b = state.regs[6];
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
    // 0x00a0a3b5: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a3bf;
    // 0x00a0a3b7: 8b06 MOV
        batch_guest_pc = 0x00a0a3b7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x00a0a3b9: 8b10 MOV
        batch_guest_pc = 0x00a0a3b9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t40;
    // 0x00a0a3bb: 8bce MOV
        t41 = state.regs[6];
        state.regs[1] = t41;
    // 0x00a0a3bd: ffd2 CALL
        t42_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00a0a3bfu);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
    // 0x00a0a3bf: 897500 MOV
    L_00a0a3bf:
        batch_guest_pc = 0x00a0a3bfu;
        t43 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3c2: 85db TEST
        t44a = state.regs[3];
        t44b = state.regs[3];
        t44r = (t44a & t44b) & 0xffffffffu;
        batch_set_logic_flags(state, t44r, 32u);
    // 0x00a0a3c4: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a3cf;
    // 0x00a0a3c6: 8b03 MOV
        batch_guest_pc = 0x00a0a3c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t46;
    // 0x00a0a3c8: 8b5004 MOV
        batch_guest_pc = 0x00a0a3c8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x00a0a3cb: 8bcb MOV
        t48 = state.regs[3];
        state.regs[1] = t48;
    // 0x00a0a3cd: ffd2 CALL
        t49_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00a0a3cfu);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
    // 0x00a0a3cf: 83470404 ADD
    L_00a0a3cf:
        batch_guest_pc = 0x00a0a3cfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t50a)) return BatchLiftStatus::invalid_memory;
        t50b = 0x00000004u;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t50r)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3d3: 5f POP
        batch_guest_pc = 0x00a0a3d3u;
        if (!memory.load32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t51a;
    // 0x00a0a3d4: 5e POP
        batch_guest_pc = 0x00a0a3d4u;
        if (!memory.load32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t52a;
    // 0x00a0a3d5: 5d POP
        batch_guest_pc = 0x00a0a3d5u;
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t53a;
    // 0x00a0a3d6: 5b POP
        batch_guest_pc = 0x00a0a3d6u;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t54a;
    // 0x00a0a3d7: 83c408 ADD
        t55a = state.regs[4];
        t55b = 0x00000008u;
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[4] = t55r;
    // 0x00a0a3da: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00a0a3dd: 2b07 SUB
    L_00a0a3dd:
        batch_guest_pc = 0x00a0a3ddu;
        t57a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t57b)) return BatchLiftStatus::invalid_memory;
        t57r = static_cast<std::uint32_t>(t57a - t57b) & 0xffffffffu;
        batch_set_sub_flags(state, t57a, t57b, t57r, 32u);
        state.regs[0] = t57r;
    // 0x00a0a3df: c1f802 SAR
        t58a = state.regs[0];
        t58c = 2u;
        if (t58c != 0u) {
        t58r = (t58a >> t58c) | ((t58a & 0x80000000u) ? (0xffffffffu << (32u - t58c)) : 0u);
        batch_set_sar_flags(state, t58a, t58c, t58r, 32u);
            state.regs[0] = t58r;
        }
    // 0x00a0a3e2: 85c0 TEST
        t59a = state.regs[0];
        t59b = state.regs[0];
        t59r = (t59a & t59b) & 0xffffffffu;
        batch_set_logic_flags(state, t59r, 32u);
    // 0x00a0a3e4: 7630 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00a0a416;
    // 0x00a0a3e6: 03c0 ADD
        t61a = state.regs[0];
        t61b = state.regs[0];
        t61r = static_cast<std::uint32_t>(t61a + t61b) & 0xffffffffu;
        batch_set_add_flags(state, t61a, t61b, t61r, 32u);
        state.regs[0] = t61r;
    // 0x00a0a3e8: 89442414 MOV
        batch_guest_pc = 0x00a0a3e8u;
        t62 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3ec: 85c0 TEST
        t63a = state.regs[0];
        t63b = state.regs[0];
        t63r = (t63a & t63b) & 0xffffffffu;
        batch_set_logic_flags(state, t63r, 32u);
    // 0x00a0a3ee: 7434 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a424;
    // 0x00a0a3f0: 68d1000000 PUSH
    L_00a0a3f0:
        batch_guest_pc = 0x00a0a3f0u;
        t65a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3f5: 6838bb3e01 PUSH
        batch_guest_pc = 0x00a0a3f5u;
        t66a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3fa: 6a00 PUSH
        batch_guest_pc = 0x00a0a3fau;
        t67a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3fc: 6a00 PUSH
        batch_guest_pc = 0x00a0a3fcu;
        t68a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a3fe: 03c0 ADD
        t69a = state.regs[0];
        t69b = state.regs[0];
        t69r = static_cast<std::uint32_t>(t69a + t69b) & 0xffffffffu;
        batch_set_add_flags(state, t69a, t69b, t69r, 32u);
        state.regs[0] = t69r;
    // 0x00a0a400: 03c0 ADD
        t70a = state.regs[0];
        t70b = state.regs[0];
        t70r = static_cast<std::uint32_t>(t70a + t70b) & 0xffffffffu;
        batch_set_add_flags(state, t70a, t70b, t70r, 32u);
        state.regs[0] = t70r;
    // 0x00a0a402: 6850213f01 PUSH
        batch_guest_pc = 0x00a0a402u;
        t71a = 0x013f2150u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a407: 50 PUSH
        batch_guest_pc = 0x00a0a407u;
        t72a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a408: e893cf5300 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00a0a40du)) return BatchLiftStatus::invalid_memory;
        t73_call_status = spore_lift_00f473a0(memory, state);
        if (t73_call_status != BatchLiftStatus::returned) return t73_call_status;
        if (state.eip != 0x00a0a40du) return BatchLiftStatus::invalid_control_flow;
    // 0x00a0a40d: 83c418 ADD
        t74a = state.regs[4];
        t74b = 0x00000018u;
        t74r = static_cast<std::uint32_t>(t74a + t74b) & 0xffffffffu;
        batch_set_add_flags(state, t74a, t74b, t74r, 32u);
        state.regs[4] = t74r;
    // 0x00a0a410: 89442410 MOV
        batch_guest_pc = 0x00a0a410u;
        t75 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a414: eb16 JMP
        goto L_00a0a42c;
    // 0x00a0a416: c744241401000000 MOV
    L_00a0a416:
        batch_guest_pc = 0x00a0a416u;
        t77 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a41e: 8b442414 MOV
        batch_guest_pc = 0x00a0a41eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t78;
    // 0x00a0a422: ebcc JMP
        goto L_00a0a3f0;
    // 0x00a0a424: c744241000000000 MOV
    L_00a0a424:
        batch_guest_pc = 0x00a0a424u;
        t80 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a42c: 8b07 MOV
    L_00a0a42c:
        batch_guest_pc = 0x00a0a42cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t81;
    // 0x00a0a42e: 8b6c241c MOV
        batch_guest_pc = 0x00a0a42eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t82;
    // 0x00a0a432: 8b4c2410 MOV
        batch_guest_pc = 0x00a0a432u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x00a0a436: 8bf5 MOV
        t84 = state.regs[5];
        state.regs[6] = t84;
    // 0x00a0a438: 2bf0 SUB
        t85a = state.regs[6];
        t85b = state.regs[0];
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
        state.regs[6] = t85r;
    // 0x00a0a43a: 56 PUSH
        batch_guest_pc = 0x00a0a43au;
        t86a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a43b: 50 PUSH
        batch_guest_pc = 0x00a0a43bu;
        t87a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t87a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a43c: 51 PUSH
        batch_guest_pc = 0x00a0a43cu;
        t88a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a43d: e802637d00 CALL
        t89_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00a0a442u);
        if (t89_call_status != BatchLiftStatus::returned) return t89_call_status;
        if (state.eip != 0x00a0a442u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a0a442: c1fe02 SAR
        t90a = state.regs[6];
        t90c = 2u;
        if (t90c != 0u) {
        t90r = (t90a >> t90c) | ((t90a & 0x80000000u) ? (0xffffffffu << (32u - t90c)) : 0u);
        batch_set_sar_flags(state, t90a, t90c, t90r, 32u);
            state.regs[6] = t90r;
        }
    // 0x00a0a445: 8d1cb0 LEA
        t91 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 4u + 0x00000000u);
        state.regs[3] = t91;
    // 0x00a0a448: 83c40c ADD
        t92a = state.regs[4];
        t92b = 0x0000000cu;
        t92r = static_cast<std::uint32_t>(t92a + t92b) & 0xffffffffu;
        batch_set_add_flags(state, t92a, t92b, t92r, 32u);
        state.regs[4] = t92r;
    // 0x00a0a44b: 85db TEST
        t93a = state.regs[3];
        t93b = state.regs[3];
        t93r = (t93a & t93b) & 0xffffffffu;
        batch_set_logic_flags(state, t93r, 32u);
    // 0x00a0a44d: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a461;
    // 0x00a0a44f: 8b542420 MOV
        batch_guest_pc = 0x00a0a44fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t95;
    // 0x00a0a453: 8b0a MOV
        batch_guest_pc = 0x00a0a453u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t96;
    // 0x00a0a455: 890b MOV
        batch_guest_pc = 0x00a0a455u;
        t97 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a457: 85c9 TEST
        t98a = state.regs[1];
        t98b = state.regs[1];
        t98r = (t98a & t98b) & 0xffffffffu;
        batch_set_logic_flags(state, t98r, 32u);
    // 0x00a0a459: 7406 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a461;
    // 0x00a0a45b: 8b01 MOV
        batch_guest_pc = 0x00a0a45bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t100;
    // 0x00a0a45d: 8b10 MOV
        batch_guest_pc = 0x00a0a45du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t101;
    // 0x00a0a45f: ffd2 CALL
        t102_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00a0a461u);
        if (t102_call_status != BatchLiftStatus::returned) return t102_call_status;
    // 0x00a0a461: 8b7704 MOV
    L_00a0a461:
        batch_guest_pc = 0x00a0a461u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t103;
    // 0x00a0a464: 2bf5 SUB
        t104a = state.regs[6];
        t104b = state.regs[5];
        t104r = static_cast<std::uint32_t>(t104a - t104b) & 0xffffffffu;
        batch_set_sub_flags(state, t104a, t104b, t104r, 32u);
        state.regs[6] = t104r;
    // 0x00a0a466: 56 PUSH
        batch_guest_pc = 0x00a0a466u;
        t105a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a467: 83c304 ADD
        t106a = state.regs[3];
        t106b = 0x00000004u;
        t106r = static_cast<std::uint32_t>(t106a + t106b) & 0xffffffffu;
        batch_set_add_flags(state, t106a, t106b, t106r, 32u);
        state.regs[3] = t106r;
    // 0x00a0a46a: 55 PUSH
        batch_guest_pc = 0x00a0a46au;
        t107a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a46b: 53 PUSH
        batch_guest_pc = 0x00a0a46bu;
        t108a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a46c: e8d3627d00 CALL
        t109_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00a0a471u);
        if (t109_call_status != BatchLiftStatus::returned) return t109_call_status;
        if (state.eip != 0x00a0a471u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a0a471: c1fe02 SAR
        t110a = state.regs[6];
        t110c = 2u;
        if (t110c != 0u) {
        t110r = (t110a >> t110c) | ((t110a & 0x80000000u) ? (0xffffffffu << (32u - t110c)) : 0u);
        batch_set_sar_flags(state, t110a, t110c, t110r, 32u);
            state.regs[6] = t110r;
        }
    // 0x00a0a474: 8d34b0 LEA
        t111 = static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 4u + 0x00000000u);
        state.regs[6] = t111;
    // 0x00a0a477: 8b07 MOV
        batch_guest_pc = 0x00a0a477u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t112)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t112;
    // 0x00a0a479: 83c40c ADD
        t113a = state.regs[4];
        t113b = 0x0000000cu;
        t113r = static_cast<std::uint32_t>(t113a + t113b) & 0xffffffffu;
        batch_set_add_flags(state, t113a, t113b, t113r, 32u);
        state.regs[4] = t113r;
    // 0x00a0a47c: 85c0 TEST
        t114a = state.regs[0];
        t114b = state.regs[0];
        t114r = (t114a & t114b) & 0xffffffffu;
        batch_set_logic_flags(state, t114r, 32u);
    // 0x00a0a47e: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a48f;
    // 0x00a0a480: 8378fc00 CMP
        batch_guest_pc = 0x00a0a480u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t116a)) return BatchLiftStatus::invalid_memory;
        t116b = 0x00000000u;
        t116r = static_cast<std::uint32_t>(t116a - t116b) & 0xffffffffu;
        batch_set_sub_flags(state, t116a, t116b, t116r, 32u);
    // 0x00a0a484: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00a0a48f;
    // 0x00a0a486: 50 PUSH
        batch_guest_pc = 0x00a0a486u;
        t118a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a487: e8f4ce5300 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00a0a48cu)) return BatchLiftStatus::invalid_memory;
        t119_call_status = spore_lift_00f47380(memory, state);
        if (t119_call_status != BatchLiftStatus::returned) return t119_call_status;
        if (state.eip != 0x00a0a48cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a0a48c: 83c404 ADD
        t120a = state.regs[4];
        t120b = 0x00000004u;
        t120r = static_cast<std::uint32_t>(t120a + t120b) & 0xffffffffu;
        batch_set_add_flags(state, t120a, t120b, t120r, 32u);
        state.regs[4] = t120r;
    // 0x00a0a48f: 8b442410 MOV
    L_00a0a48f:
        batch_guest_pc = 0x00a0a48fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t121)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t121;
    // 0x00a0a493: 8b4c2414 MOV
        batch_guest_pc = 0x00a0a493u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t122;
    // 0x00a0a497: 8d1488 LEA
        t123 = static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 4u + 0x00000000u);
        state.regs[2] = t123;
    // 0x00a0a49a: 897704 MOV
        batch_guest_pc = 0x00a0a49au;
        t124 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t124)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a49d: 8907 MOV
        batch_guest_pc = 0x00a0a49du;
        t125 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t125)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a49f: 895708 MOV
        batch_guest_pc = 0x00a0a49fu;
        t126 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t126)) return BatchLiftStatus::invalid_memory;
    // 0x00a0a4a2: 5f POP
        batch_guest_pc = 0x00a0a4a2u;
        if (!memory.load32(state.regs[4], t127a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t127a;
    // 0x00a0a4a3: 5e POP
        batch_guest_pc = 0x00a0a4a3u;
        if (!memory.load32(state.regs[4], t128a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t128a;
    // 0x00a0a4a4: 5d POP
        batch_guest_pc = 0x00a0a4a4u;
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t129a;
    // 0x00a0a4a5: 5b POP
        batch_guest_pc = 0x00a0a4a5u;
        if (!memory.load32(state.regs[4], t130a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t130a;
    // 0x00a0a4a6: 83c408 ADD
        t131a = state.regs[4];
        t131b = 0x00000008u;
        t131r = static_cast<std::uint32_t>(t131a + t131b) & 0xffffffffu;
        batch_set_add_flags(state, t131a, t131b, t131r, 32u);
        state.regs[4] = t131r;
    // 0x00a0a4a9: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
