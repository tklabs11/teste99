#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00942e9c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00942e50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00942e50u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0, t39r = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49 = 0;
    BatchLiftStatus t50_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t72a = 0;
    BatchLiftStatus t73_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0, t88r = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t92a = 0, t92r = 0;
    std::uint32_t t93a = 0;
    BatchLiftStatus t94_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;

    // 0x00942e50: 8b442404 MOV
        batch_guest_pc = 0x00942e50u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00942e54: 83ec08 SUB
        t1a = state.regs[4];
        t1b = 0x00000008u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
        state.regs[4] = t1r;
    // 0x00942e57: 56 PUSH
        batch_guest_pc = 0x00942e57u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00942e58: 57 PUSH
        batch_guest_pc = 0x00942e58u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00942e59: 8b7c2418 MOV
        batch_guest_pc = 0x00942e59u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x00942e5d: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x00942e5f: 3bc7 CMP
        t6a = state.regs[0];
        t6b = state.regs[7];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00942e61: 0f84fa000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00942f61;
    // 0x00942e67: 8b16 MOV
        batch_guest_pc = 0x00942e67u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00942e69: 53 PUSH
        batch_guest_pc = 0x00942e69u;
        t9a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00942e6a: 55 PUSH
        batch_guest_pc = 0x00942e6au;
        t10a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00942e6b: 8b6e04 MOV
        batch_guest_pc = 0x00942e6bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t11;
    // 0x00942e6e: 8bdf MOV
        t12 = state.regs[7];
        state.regs[3] = t12;
    // 0x00942e70: 2bd8 SUB
        t13a = state.regs[3];
        t13b = state.regs[0];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
        state.regs[3] = t13r;
    // 0x00942e72: 8b4608 MOV
        batch_guest_pc = 0x00942e72u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00942e75: 8bcd MOV
        t15 = state.regs[5];
        state.regs[1] = t15;
    // 0x00942e77: 2bca SUB
        t16a = state.regs[1];
        t16b = state.regs[2];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x00942e79: 2bc2 SUB
        t17a = state.regs[0];
        t17b = state.regs[2];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
        state.regs[0] = t17r;
    // 0x00942e7b: 48 DEC
        t18a = state.regs[0];
        t18r = static_cast<std::uint32_t>(t18a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t18a, t18r, 32u);
        state.regs[0] = t18r;
    // 0x00942e7c: 03cb ADD
        t19a = state.regs[1];
        t19b = state.regs[3];
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[1] = t19r;
    // 0x00942e7e: 895c2414 MOV
        batch_guest_pc = 0x00942e7eu;
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00942e82: 3bc8 CMP
        t21a = state.regs[1];
        t21b = state.regs[0];
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
    // 0x00942e84: 0f86ad000000 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00942f37;
    // 0x00942e8a: 894c2410 MOV
        batch_guest_pc = 0x00942e8au;
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00942e8e: 83f808 CMP
        t24a = state.regs[0];
        t24b = 0x00000008u;
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x00942e91: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00942e97;
    // 0x00942e93: 03c0 ADD
        t26a = state.regs[0];
        t26b = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[0] = t26r;
    // 0x00942e95: eb05 JMP
        goto L_00942e9c;
    // 0x00942e97: b808000000 MOV
    L_00942e97:
        t28 = 0x00000008u;
        state.regs[0] = t28;
    // 0x00942e9c: 89442420 MOV
    L_00942e9c:
        batch_guest_pc = 0x00942e9cu;
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00942ea0: 3bc1 CMP
        t30a = state.regs[0];
        t30b = state.regs[1];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x00942ea2: 8d442410 LEA
        t31 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t31;
    // 0x00942ea6: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00942eac;
    // 0x00942ea8: 8d442420 LEA
        t33 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[0] = t33;
    // 0x00942eac: 8b18 MOV
    L_00942eac:
        batch_guest_pc = 0x00942eacu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t34;
    // 0x00942eae: 68d1000000 PUSH
        batch_guest_pc = 0x00942eaeu;
        t35a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00942eb3: 6838bb3e01 PUSH
        batch_guest_pc = 0x00942eb3u;
        t36a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00942eb8: 6a00 PUSH
        batch_guest_pc = 0x00942eb8u;
        t37a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00942eba: 6a00 PUSH
        batch_guest_pc = 0x00942ebau;
        t38a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ebc: 43 INC
        t39a = state.regs[3];
        t39r = static_cast<std::uint32_t>(t39a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t39a, t39r, 32u);
        state.regs[3] = t39r;
    // 0x00942ebd: 6850213f01 PUSH
        batch_guest_pc = 0x00942ebdu;
        t40a = 0x013f2150u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ec2: 53 PUSH
        batch_guest_pc = 0x00942ec2u;
        t41a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ec3: e8d8446000 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00942ec8u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00f473a0(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00942ec8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00942ec8: 8b0e MOV
        batch_guest_pc = 0x00942ec8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00942eca: 8b6e04 MOV
        batch_guest_pc = 0x00942ecau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t44;
    // 0x00942ecd: 2be9 SUB
        t45a = state.regs[5];
        t45b = state.regs[1];
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
        state.regs[5] = t45r;
    // 0x00942ecf: 55 PUSH
        batch_guest_pc = 0x00942ecfu;
        t46a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ed0: 51 PUSH
        batch_guest_pc = 0x00942ed0u;
        t47a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ed1: 50 PUSH
        batch_guest_pc = 0x00942ed1u;
        t48a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ed2: 89442444 MOV
        batch_guest_pc = 0x00942ed2u;
        t49 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t49)) return BatchLiftStatus::invalid_memory;
    // 0x00942ed6: e869d88900 CALL
        t50_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00942edbu);
        if (t50_call_status != BatchLiftStatus::returned) return t50_call_status;
        if (state.eip != 0x00942edbu) return BatchLiftStatus::invalid_control_flow;
    // 0x00942edb: 8b4c2438 MOV
        batch_guest_pc = 0x00942edbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000038u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00942edf: 8b442444 MOV
        batch_guest_pc = 0x00942edfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000044u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x00942ee3: 8b542440 MOV
        batch_guest_pc = 0x00942ee3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000040u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t53;
    // 0x00942ee7: 51 PUSH
        batch_guest_pc = 0x00942ee7u;
        t54a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00942ee8: 03e8 ADD
        t55a = state.regs[5];
        t55b = state.regs[0];
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[5] = t55r;
    // 0x00942eea: 52 PUSH
        batch_guest_pc = 0x00942eeau;
        t56a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00942eeb: 55 PUSH
        batch_guest_pc = 0x00942eebu;
        t57a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00942eec: e853d88900 CALL
        t58_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00942ef1u);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x00942ef1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00942ef1: 2b7c244c SUB
        batch_guest_pc = 0x00942ef1u;
        t59a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000004cu), t59b)) return BatchLiftStatus::invalid_memory;
        t59r = static_cast<std::uint32_t>(t59a - t59b) & 0xffffffffu;
        batch_set_sub_flags(state, t59a, t59b, t59r, 32u);
        state.regs[7] = t59r;
    // 0x00942ef5: c6443d0000 MOV
        batch_guest_pc = 0x00942ef5u;
        t60 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[5] + state.regs[7] * 1u + 0x00000000u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00942efa: 8b06 MOV
        batch_guest_pc = 0x00942efau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t61;
    // 0x00942efc: 8b4e08 MOV
        batch_guest_pc = 0x00942efcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x00942eff: 03ef ADD
        t63a = state.regs[5];
        t63b = state.regs[7];
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        state.regs[5] = t63r;
    // 0x00942f01: 2bc8 SUB
        t64a = state.regs[1];
        t64b = state.regs[0];
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
        state.regs[1] = t64r;
    // 0x00942f03: 83c430 ADD
        t65a = state.regs[4];
        t65b = 0x00000030u;
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[4] = t65r;
    // 0x00942f06: 83f901 CMP
        t66a = state.regs[1];
        t66b = 0x00000001u;
        t66r = static_cast<std::uint32_t>(t66a - t66b) & 0xffffffffu;
        batch_set_sub_flags(state, t66a, t66b, t66r, 32u);
    // 0x00942f09: 7e12 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00942f1d;
    // 0x00942f0b: 85c0 TEST
        t68a = state.regs[0];
        t68b = state.regs[0];
        t68r = (t68a & t68b) & 0xffffffffu;
        batch_set_logic_flags(state, t68r, 32u);
    // 0x00942f0d: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00942f1d;
    // 0x00942f0f: 3b4610 CMP
        batch_guest_pc = 0x00942f0fu;
        t70a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t70b)) return BatchLiftStatus::invalid_memory;
        t70r = static_cast<std::uint32_t>(t70a - t70b) & 0xffffffffu;
        batch_set_sub_flags(state, t70a, t70b, t70r, 32u);
    // 0x00942f12: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00942f1d;
    // 0x00942f14: 50 PUSH
        batch_guest_pc = 0x00942f14u;
        t72a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x00942f15: e866446000 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00942f1au)) return BatchLiftStatus::invalid_memory;
        t73_call_status = spore_lift_00f47380(memory, state);
        if (t73_call_status != BatchLiftStatus::returned) return t73_call_status;
        if (state.eip != 0x00942f1au) return BatchLiftStatus::invalid_control_flow;
    // 0x00942f1a: 83c404 ADD
        t74a = state.regs[4];
        t74b = 0x00000004u;
        t74r = static_cast<std::uint32_t>(t74a + t74b) & 0xffffffffu;
        batch_set_add_flags(state, t74a, t74b, t74r, 32u);
        state.regs[4] = t74r;
    // 0x00942f1d: 8b442420 MOV
    L_00942f1d:
        batch_guest_pc = 0x00942f1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t75;
    // 0x00942f21: 8906 MOV
        batch_guest_pc = 0x00942f21u;
        t76 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x00942f23: 896e04 MOV
        batch_guest_pc = 0x00942f23u;
        t77 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00942f26: 5d POP
        batch_guest_pc = 0x00942f26u;
        if (!memory.load32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t78a;
    // 0x00942f27: 03c3 ADD
        t79a = state.regs[0];
        t79b = state.regs[3];
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[0] = t79r;
    // 0x00942f29: 5b POP
        batch_guest_pc = 0x00942f29u;
        if (!memory.load32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t80a;
    // 0x00942f2a: 894608 MOV
        batch_guest_pc = 0x00942f2au;
        t81 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t81)) return BatchLiftStatus::invalid_memory;
    // 0x00942f2d: 5f POP
        batch_guest_pc = 0x00942f2du;
        if (!memory.load32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t82a;
    // 0x00942f2e: 8bc6 MOV
        t83 = state.regs[6];
        state.regs[0] = t83;
    // 0x00942f30: 5e POP
        batch_guest_pc = 0x00942f30u;
        if (!memory.load32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t84a;
    // 0x00942f31: 83c408 ADD
        t85a = state.regs[4];
        t85b = 0x00000008u;
        t85r = static_cast<std::uint32_t>(t85a + t85b) & 0xffffffffu;
        batch_set_add_flags(state, t85a, t85b, t85r, 32u);
        state.regs[4] = t85r;
    // 0x00942f34: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00942f37: 8b44241c MOV
    L_00942f37:
        batch_guest_pc = 0x00942f37u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t87;
    // 0x00942f3b: 40 INC
        t88a = state.regs[0];
        t88r = static_cast<std::uint32_t>(t88a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t88a, t88r, 32u);
        state.regs[0] = t88r;
    // 0x00942f3c: 2bf8 SUB
        t89a = state.regs[7];
        t89b = state.regs[0];
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0xffffffffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 32u);
        state.regs[7] = t89r;
    // 0x00942f3e: 57 PUSH
        batch_guest_pc = 0x00942f3eu;
        t90a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x00942f3f: 50 PUSH
        batch_guest_pc = 0x00942f3fu;
        t91a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t91a)) return BatchLiftStatus::invalid_memory;
    // 0x00942f40: 45 INC
        t92a = state.regs[5];
        t92r = static_cast<std::uint32_t>(t92a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t92a, t92r, 32u);
        state.regs[5] = t92r;
    // 0x00942f41: 55 PUSH
        batch_guest_pc = 0x00942f41u;
        t93a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
    // 0x00942f42: e8fdd78900 CALL
        t94_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00942f47u);
        if (t94_call_status != BatchLiftStatus::returned) return t94_call_status;
        if (state.eip != 0x00942f47u) return BatchLiftStatus::invalid_control_flow;
    // 0x00942f47: 8b5604 MOV
        batch_guest_pc = 0x00942f47u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t95;
    // 0x00942f4a: 8b4c2428 MOV
        batch_guest_pc = 0x00942f4au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t96;
    // 0x00942f4e: c6041300 MOV
        batch_guest_pc = 0x00942f4eu;
        t97 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[3] + state.regs[2] * 1u + 0x00000000u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00942f52: 8b4604 MOV
        batch_guest_pc = 0x00942f52u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t98;
    // 0x00942f55: 8a11 MOV
        batch_guest_pc = 0x00942f55u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t99)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t99 << 0u) & 0x000000ffu);
    // 0x00942f57: 83c40c ADD
        t100a = state.regs[4];
        t100b = 0x0000000cu;
        t100r = static_cast<std::uint32_t>(t100a + t100b) & 0xffffffffu;
        batch_set_add_flags(state, t100a, t100b, t100r, 32u);
        state.regs[4] = t100r;
    // 0x00942f5a: 8810 MOV
        batch_guest_pc = 0x00942f5au;
        t101 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00942f5c: 015e04 ADD
        batch_guest_pc = 0x00942f5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t102a)) return BatchLiftStatus::invalid_memory;
        t102b = state.regs[3];
        t102r = static_cast<std::uint32_t>(t102a + t102b) & 0xffffffffu;
        batch_set_add_flags(state, t102a, t102b, t102r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t102r)) return BatchLiftStatus::invalid_memory;
    // 0x00942f5f: 5d POP
        batch_guest_pc = 0x00942f5fu;
        if (!memory.load32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t103a;
    // 0x00942f60: 5b POP
        batch_guest_pc = 0x00942f60u;
        if (!memory.load32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t104a;
    // 0x00942f61: 5f POP
    L_00942f61:
        batch_guest_pc = 0x00942f61u;
        if (!memory.load32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t105a;
    // 0x00942f62: 8bc6 MOV
        t106 = state.regs[6];
        state.regs[0] = t106;
    // 0x00942f64: 5e POP
        batch_guest_pc = 0x00942f64u;
        if (!memory.load32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t107a;
    // 0x00942f65: 83c408 ADD
        t108a = state.regs[4];
        t108b = 0x00000008u;
        t108r = static_cast<std::uint32_t>(t108a + t108b) & 0xffffffffu;
        batch_set_add_flags(state, t108a, t108b, t108r, 32u);
        state.regs[4] = t108r;
    // 0x00942f68: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
