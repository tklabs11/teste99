#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926c20(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926c20u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17r = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35r = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    BatchLiftStatus t47_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    BatchLiftStatus t59_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0, t68c = 0, t68r = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97a = 0, t97b = 0, t97r = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t104a = 0, t104b = 0, t104r = 0;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114a = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t120a = 0;
    std::uint32_t t121a = 0;
    std::uint32_t t122a = 0;
    std::uint32_t t123a = 0, t123b = 0, t123r = 0;
    std::uint32_t t124a = 0;

    // 0x00926c20: 8b442404 MOV
        batch_guest_pc = 0x00926c20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926c24: 53 PUSH
        batch_guest_pc = 0x00926c24u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c25: 55 PUSH
        batch_guest_pc = 0x00926c25u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c26: 56 PUSH
        batch_guest_pc = 0x00926c26u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c27: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x00926c29: 8b8ed4040000 MOV
        batch_guest_pc = 0x00926c29u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d4u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00926c2f: 57 PUSH
        batch_guest_pc = 0x00926c2fu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c30: 8d51ff LEA
        t7 = static_cast<std::uint32_t>(state.regs[1] + 0xffffffffu);
        state.regs[2] = t7;
    // 0x00926c33: 8d7c01ff LEA
        t8 = static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0xffffffffu);
        state.regs[7] = t8;
    // 0x00926c37: f7d2 NOT
        t9a = state.regs[2];
        state.regs[2] = (~t9a & 0xffffffffu);
    // 0x00926c39: 23fa AND
        t10a = state.regs[7];
        t10b = state.regs[2];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[7] = t10r;
    // 0x00926c3b: 8b96d8040000 MOV
        batch_guest_pc = 0x00926c3bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d8u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00926c41: bb01000000 MOV
        t12 = 0x00000001u;
        state.regs[3] = t12;
    // 0x00926c46: 8bc7 MOV
        t13 = state.regs[7];
        state.regs[0] = t13;
    // 0x00926c48: 3bfa CMP
        t14a = state.regs[7];
        t14b = state.regs[2];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x00926c4a: 7309 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926c55;
    // 0x00926c4c: 8d440aff LEA
        t16 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0xffffffffu);
        state.regs[0] = t16;
    // 0x00926c50: 49 DEC
        t17a = state.regs[1];
        t17r = static_cast<std::uint32_t>(t17a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t17a, t17r, 32u);
        state.regs[1] = t17r;
    // 0x00926c51: f7d1 NOT
        t18a = state.regs[1];
        state.regs[1] = (~t18a & 0xffffffffu);
    // 0x00926c53: 23c1 AND
        t19a = state.regs[0];
        t19b = state.regs[1];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00926c55: 6a04 PUSH
    L_00926c55:
        batch_guest_pc = 0x00926c55u;
        t20a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c57: 8da8ffff0000 LEA
        t21 = static_cast<std::uint32_t>(state.regs[0] + 0x0000ffffu);
        state.regs[5] = t21;
    // 0x00926c5d: 6800200000 PUSH
        batch_guest_pc = 0x00926c5du;
        t22a = 0x00002000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c62: 81e50000ffff AND
        t23a = state.regs[5];
        t23b = 0xffff0000u;
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[5] = t23r;
    // 0x00926c68: 55 PUSH
        batch_guest_pc = 0x00926c68u;
        t24a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c69: 6a00 PUSH
        batch_guest_pc = 0x00926c69u;
        t25a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00926c6b: 89442424 MOV
        batch_guest_pc = 0x00926c6bu;
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00926c6f: ff15c8c13c01 CALL
        t27_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualAlloc", 0x013cc1c8u, 0x00926c75u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00926c75u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926c75: 85c0 TEST
        t28a = state.regs[0];
        t28b = state.regs[0];
        t28r = (t28a & t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
    // 0x00926c77: 7439 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926cb2;
    // 0x00926c79: 8b96dc040000 MOV
        batch_guest_pc = 0x00926c79u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004dcu), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x00926c7f: 3bfa CMP
        t31a = state.regs[7];
        t31b = state.regs[2];
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x00926c81: 730f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00926c92;
    // 0x00926c83: 8b8ed4040000 MOV
        batch_guest_pc = 0x00926c83u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000004d4u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00926c89: 8d7c0aff LEA
        t34 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 1u + 0xffffffffu);
        state.regs[7] = t34;
    // 0x00926c8d: 49 DEC
        t35a = state.regs[1];
        t35r = static_cast<std::uint32_t>(t35a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t35a, t35r, 32u);
        state.regs[1] = t35r;
    // 0x00926c8e: f7d1 NOT
        t36a = state.regs[1];
        state.regs[1] = (~t36a & 0xffffffffu);
    // 0x00926c90: 23f9 AND
        t37a = state.regs[7];
        t37b = state.regs[1];
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
        state.regs[7] = t37r;
    // 0x00926c92: 3bfd CMP
    L_00926c92:
        t38a = state.regs[7];
        t38b = state.regs[5];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x00926c94: 7707 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00926c9d;
    // 0x00926c96: 807c241800 CMP
        batch_guest_pc = 0x00926c96u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t40a)) return BatchLiftStatus::invalid_memory;
        t40b = 0x00000000u;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0x000000ffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 8u);
    // 0x00926c9b: 7402 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926c9f;
    // 0x00926c9d: 8bfd MOV
    L_00926c9d:
        t42 = state.regs[5];
        state.regs[7] = t42;
    // 0x00926c9f: 6a04 PUSH
    L_00926c9f:
        batch_guest_pc = 0x00926c9fu;
        t43a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ca1: 6800100000 PUSH
        batch_guest_pc = 0x00926ca1u;
        t44a = 0x00001000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ca6: 57 PUSH
        batch_guest_pc = 0x00926ca6u;
        t45a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ca7: 50 PUSH
        batch_guest_pc = 0x00926ca7u;
        t46a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ca8: ff15c8c13c01 CALL
        t47_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualAlloc", 0x013cc1c8u, 0x00926caeu);
        if (t47_call_status != BatchLiftStatus::returned) return t47_call_status;
        if (state.eip != 0x00926caeu) return BatchLiftStatus::invalid_control_flow;
    // 0x00926cae: 85c0 TEST
        t48a = state.regs[0];
        t48b = state.regs[0];
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
    // 0x00926cb0: 7532 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926ce4;
    // 0x00926cb2: 80be9804000000 CMP
    L_00926cb2:
        batch_guest_pc = 0x00926cb2u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000498u), t50a)) return BatchLiftStatus::invalid_memory;
        t50b = 0x00000000u;
        t50r = static_cast<std::uint32_t>(t50a - t50b) & 0x000000ffu;
        batch_set_sub_flags(state, t50a, t50b, t50r, 8u);
    // 0x00926cb9: 8b7c2414 MOV
        batch_guest_pc = 0x00926cb9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t51;
    // 0x00926cbd: b800300000 MOV
        t52 = 0x00003000u;
        state.regs[0] = t52;
    // 0x00926cc2: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926cc9;
    // 0x00926cc4: b800301000 MOV
        t54 = 0x00103000u;
        state.regs[0] = t54;
    // 0x00926cc9: 6a04 PUSH
    L_00926cc9:
        batch_guest_pc = 0x00926cc9u;
        t55a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ccb: 50 PUSH
        batch_guest_pc = 0x00926ccbu;
        t56a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ccc: 57 PUSH
        batch_guest_pc = 0x00926cccu;
        t57a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ccd: 6a00 PUSH
        batch_guest_pc = 0x00926ccdu;
        t58a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x00926ccf: ff15c8c13c01 CALL
        t59_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualAlloc", 0x013cc1c8u, 0x00926cd5u);
        if (t59_call_status != BatchLiftStatus::returned) return t59_call_status;
        if (state.eip != 0x00926cd5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926cd5: 85c0 TEST
        t60a = state.regs[0];
        t60b = state.regs[0];
        t60r = (t60a & t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
    // 0x00926cd7: 0f84c6000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926da3;
    // 0x00926cdd: bb03000000 MOV
        t62 = 0x00000003u;
        state.regs[3] = t62;
    // 0x00926ce2: 8bef MOV
        t63 = state.regs[7];
        state.regs[5] = t63;
    // 0x00926ce4: 8d4827 LEA
    L_00926ce4:
        t64 = static_cast<std::uint32_t>(state.regs[0] + 0x00000027u);
        state.regs[1] = t64;
    // 0x00926ce7: 83e1f8 AND
        t65a = state.regs[1];
        t65b = 0xfffffff8u;
        t65r = (t65a & t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
        state.regs[1] = t65r;
    // 0x00926cea: 8908 MOV
        batch_guest_pc = 0x00926ceau;
        t66 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x00926cec: 8bd3 MOV
        t67 = state.regs[3];
        state.regs[2] = t67;
    // 0x00926cee: d1ea SHR
        t68a = state.regs[2];
        t68c = 1u;
        if (t68c != 0u) {
        t68r = static_cast<std::uint32_t>(t68a >> t68c);
        batch_set_shr_flags(state, t68a, t68c, t68r, 32u);
            state.regs[2] = t68r;
        }
    // 0x00926cf0: 80e201 AND
        t69a = state.regs[2] & 0x000000ffu;
        t69b = 0x00000001u;
        t69r = (t69a & t69b) & 0x000000ffu;
        batch_set_logic_flags(state, t69r, 8u);
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t69r << 0u) & 0x000000ffu);
    // 0x00926cf3: 88500c MOV
        batch_guest_pc = 0x00926cf3u;
        t70 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00926cf6: 897808 MOV
        batch_guest_pc = 0x00926cf6u;
        t71 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00926cf9: 8d8e48040000 LEA
        t72 = static_cast<std::uint32_t>(state.regs[6] + 0x00000448u);
        state.regs[1] = t72;
    // 0x00926cff: 897804 MOV
        batch_guest_pc = 0x00926cffu;
        t73 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x00926d02: 398e64040000 CMP
        batch_guest_pc = 0x00926d02u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000464u), t74a)) return BatchLiftStatus::invalid_memory;
        t74b = state.regs[1];
        t74r = static_cast<std::uint32_t>(t74a - t74b) & 0xffffffffu;
        batch_set_sub_flags(state, t74a, t74b, t74r, 32u);
    // 0x00926d08: 89481c MOV
        batch_guest_pc = 0x00926d08u;
        t75 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00926d0b: 0f95c2 SETNZ
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00926d0e: 88500d MOV
        batch_guest_pc = 0x00926d0eu;
        t77 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000du), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00926d11: 88500f MOV
        batch_guest_pc = 0x00926d11u;
        t78 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000fu), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00926d14: 33d2 XOR
        t79a = state.regs[2];
        t79b = state.regs[2];
        t79r = (t79a ^ t79b) & 0xffffffffu;
        batch_set_logic_flags(state, t79r, 32u);
        state.regs[2] = t79r;
    // 0x00926d16: c6400e01 MOV
        batch_guest_pc = 0x00926d16u;
        t80 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000eu), t80)) return BatchLiftStatus::invalid_memory;
    // 0x00926d1a: 895010 MOV
        batch_guest_pc = 0x00926d1au;
        t81 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t81)) return BatchLiftStatus::invalid_memory;
    // 0x00926d1d: 895014 MOV
        batch_guest_pc = 0x00926d1du;
        t82 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00926d20: 8b5118 MOV
        batch_guest_pc = 0x00926d20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t83;
    // 0x00926d23: 895018 MOV
        batch_guest_pc = 0x00926d23u;
        t84 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x00926d26: 894118 MOV
        batch_guest_pc = 0x00926d26u;
        t85 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00926d29: 8b4818 MOV
        batch_guest_pc = 0x00926d29u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t86;
    // 0x00926d2c: 89411c MOV
        batch_guest_pc = 0x00926d2cu;
        t87 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t87)) return BatchLiftStatus::invalid_memory;
    // 0x00926d2f: 896808 MOV
        batch_guest_pc = 0x00926d2fu;
        t88 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t88)) return BatchLiftStatus::invalid_memory;
    // 0x00926d32: 80be6c04000000 CMP
        batch_guest_pc = 0x00926d32u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x0000046cu), t89a)) return BatchLiftStatus::invalid_memory;
        t89b = 0x00000000u;
        t89r = static_cast<std::uint32_t>(t89a - t89b) & 0x000000ffu;
        batch_set_sub_flags(state, t89a, t89b, t89r, 8u);
    // 0x00926d39: 751f JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926d5a;
    // 0x00926d3b: 8b9664040000 MOV
        batch_guest_pc = 0x00926d3bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000464u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t91;
    // 0x00926d41: 3b9660040000 CMP
        batch_guest_pc = 0x00926d41u;
        t92a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000460u), t92b)) return BatchLiftStatus::invalid_memory;
        t92r = static_cast<std::uint32_t>(t92a - t92b) & 0xffffffffu;
        batch_set_sub_flags(state, t92a, t92b, t92r, 32u);
    // 0x00926d47: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926d5a;
    // 0x00926d49: c6866c04000001 MOV
        batch_guest_pc = 0x00926d49u;
        t94 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000046cu), t94)) return BatchLiftStatus::invalid_memory;
    // 0x00926d50: c7866804000000000000 MOV
        batch_guest_pc = 0x00926d50u;
        t95 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000468u), t95)) return BatchLiftStatus::invalid_memory;
    // 0x00926d5a: 8b08 MOV
    L_00926d5a:
        batch_guest_pc = 0x00926d5au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t96;
    // 0x00926d5c: 2bc1 SUB
        t97a = state.regs[0];
        t97b = state.regs[1];
        t97r = static_cast<std::uint32_t>(t97a - t97b) & 0xffffffffu;
        batch_set_sub_flags(state, t97a, t97b, t97r, 32u);
        state.regs[0] = t97r;
    // 0x00926d5e: 03c7 ADD
        t98a = state.regs[0];
        t98b = state.regs[7];
        t98r = static_cast<std::uint32_t>(t98a + t98b) & 0xffffffffu;
        batch_set_add_flags(state, t98a, t98b, t98r, 32u);
        state.regs[0] = t98r;
    // 0x00926d60: 8bd0 MOV
        t99 = state.regs[0];
        state.regs[2] = t99;
    // 0x00926d62: 0bd3 OR
        t100a = state.regs[2];
        t100b = state.regs[3];
        t100r = (t100a | t100b) & 0xffffffffu;
        batch_set_logic_flags(state, t100r, 32u);
        state.regs[2] = t100r;
    // 0x00926d64: 8bc2 MOV
        t101 = state.regs[2];
        state.regs[0] = t101;
    // 0x00926d66: 25f8ffff7f AND
        t102a = state.regs[0];
        t102b = 0x7ffffff8u;
        t102r = (t102a & t102b) & 0xffffffffu;
        batch_set_logic_flags(state, t102r, 32u);
        state.regs[0] = t102r;
    // 0x00926d6b: 83e809 SUB
        t103a = state.regs[0];
        t103b = 0x00000009u;
        t103r = static_cast<std::uint32_t>(t103a - t103b) & 0xffffffffu;
        batch_set_sub_flags(state, t103a, t103b, t103r, 32u);
        state.regs[0] = t103r;
    // 0x00926d6e: 83e0f8 AND
        t104a = state.regs[0];
        t104b = 0xfffffff8u;
        t104r = (t104a & t104b) & 0xffffffffu;
        batch_set_logic_flags(state, t104r, 32u);
        state.regs[0] = t104r;
    // 0x00926d71: 81e207000080 AND
        t105a = state.regs[2];
        t105b = 0x80000007u;
        t105r = (t105a & t105b) & 0xffffffffu;
        batch_set_logic_flags(state, t105r, 32u);
        state.regs[2] = t105r;
    // 0x00926d77: 0bd0 OR
        t106a = state.regs[2];
        t106b = state.regs[0];
        t106r = (t106a | t106b) & 0xffffffffu;
        batch_set_logic_flags(state, t106r, 32u);
        state.regs[2] = t106r;
    // 0x00926d79: 895104 MOV
        batch_guest_pc = 0x00926d79u;
        t107 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t107)) return BatchLiftStatus::invalid_memory;
    // 0x00926d7c: 5f POP
        batch_guest_pc = 0x00926d7cu;
        if (!memory.load32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t108a;
    // 0x00926d7d: c70100000000 MOV
        batch_guest_pc = 0x00926d7du;
        t109 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t109)) return BatchLiftStatus::invalid_memory;
    // 0x00926d83: ba08000000 MOV
        t110 = 0x00000008u;
        state.regs[2] = t110;
    // 0x00926d88: 5e POP
        batch_guest_pc = 0x00926d88u;
        if (!memory.load32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t111a;
    // 0x00926d89: 890408 MOV
        batch_guest_pc = 0x00926d89u;
        t112 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000000u), t112)) return BatchLiftStatus::invalid_memory;
    // 0x00926d8c: 89540804 MOV
        batch_guest_pc = 0x00926d8cu;
        t113 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000004u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00926d90: 5d POP
        batch_guest_pc = 0x00926d90u;
        if (!memory.load32(state.regs[4], t114a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t114a;
    // 0x00926d91: 89540808 MOV
        batch_guest_pc = 0x00926d91u;
        t115 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x00000008u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x00926d95: c744080c09000000 MOV
        batch_guest_pc = 0x00926d95u;
        t116 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[1] * 1u + 0x0000000cu), t116)) return BatchLiftStatus::invalid_memory;
    // 0x00926d9d: 8bc1 MOV
        t117 = state.regs[1];
        state.regs[0] = t117;
    // 0x00926d9f: 5b POP
        batch_guest_pc = 0x00926d9fu;
        if (!memory.load32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t118a;
    // 0x00926da0: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926da3: 5f POP
    L_00926da3:
        batch_guest_pc = 0x00926da3u;
        if (!memory.load32(state.regs[4], t120a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t120a;
    // 0x00926da4: 5e POP
        batch_guest_pc = 0x00926da4u;
        if (!memory.load32(state.regs[4], t121a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t121a;
    // 0x00926da5: 5d POP
        batch_guest_pc = 0x00926da5u;
        if (!memory.load32(state.regs[4], t122a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t122a;
    // 0x00926da6: 33c0 XOR
        t123a = state.regs[0];
        t123b = state.regs[0];
        t123r = (t123a ^ t123b) & 0xffffffffu;
        batch_set_logic_flags(state, t123r, 32u);
        state.regs[0] = t123r;
    // 0x00926da8: 5b POP
        batch_guest_pc = 0x00926da8u;
        if (!memory.load32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t124a;
    // 0x00926da9: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
