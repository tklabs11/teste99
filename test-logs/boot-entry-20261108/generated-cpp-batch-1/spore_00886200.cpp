#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00886232(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00887090(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e073e(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00886200(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00886200u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0, t49r = 0;
    std::uint32_t t50a = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63a = 0;

    // 0x00886200: 51 PUSH
        batch_guest_pc = 0x00886200u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00886201: 55 PUSH
        batch_guest_pc = 0x00886201u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00886202: 8b6c240c MOV
        batch_guest_pc = 0x00886202u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t2;
    // 0x00886206: 56 PUSH
        batch_guest_pc = 0x00886206u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00886207: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x00886209: 8b06 MOV
        batch_guest_pc = 0x00886209u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x0088620b: 8b4e04 MOV
        batch_guest_pc = 0x0088620bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x0088620e: 57 PUSH
        batch_guest_pc = 0x0088620eu;
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0088620f: 8b7e08 MOV
        batch_guest_pc = 0x0088620fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t8;
    // 0x00886212: 2bc8 SUB
        t9a = state.regs[1];
        t9b = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
        state.regs[1] = t9r;
    // 0x00886214: 2bf8 SUB
        t10a = state.regs[7];
        t10b = state.regs[0];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[7] = t10r;
    // 0x00886216: 8d47ff LEA
        t11 = static_cast<std::uint32_t>(state.regs[7] + 0xffffffffu);
        state.regs[0] = t11;
    // 0x00886219: 8d1429 LEA
        t12 = static_cast<std::uint32_t>(state.regs[1] + state.regs[5] * 1u + 0x00000000u);
        state.regs[2] = t12;
    // 0x0088621c: 3bd0 CMP
        t13a = state.regs[2];
        t13b = state.regs[0];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x0088621e: 7647 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00886267;
    // 0x00886220: 8954240c MOV
        batch_guest_pc = 0x00886220u;
        t15 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00886224: 83f808 CMP
        t16a = state.regs[0];
        t16b = 0x00000008u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00886227: 7604 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0088622d;
    // 0x00886229: 03c0 ADD
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[0] = t18r;
    // 0x0088622b: eb05 JMP
        goto L_00886232;
    // 0x0088622d: b808000000 MOV
    L_0088622d:
        t20 = 0x00000008u;
        state.regs[0] = t20;
    // 0x00886232: 89442414 MOV
    L_00886232:
        batch_guest_pc = 0x00886232u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00886236: 3bc2 CMP
        t22a = state.regs[0];
        t22b = state.regs[2];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x00886238: 8d44240c LEA
        t23 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[0] = t23;
    // 0x0088623c: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00886242;
    // 0x0088623e: 8d442414 LEA
        t25 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t25;
    // 0x00886242: 8b00 MOV
    L_00886242:
        batch_guest_pc = 0x00886242u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00886244: 8944240c MOV
        batch_guest_pc = 0x00886244u;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00886248: 3bc1 CMP
        t28a = state.regs[0];
        t28b = state.regs[1];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x0088624a: 894c2414 MOV
        batch_guest_pc = 0x0088624au;
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0088624e: 8d442414 LEA
        t30 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t30;
    // 0x00886252: 7204 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00886258;
    // 0x00886254: 8d44240c LEA
        t32 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[0] = t32;
    // 0x00886258: 8b00 MOV
    L_00886258:
        batch_guest_pc = 0x00886258u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x0088625a: 40 INC
        t34a = state.regs[0];
        t34r = static_cast<std::uint32_t>(t34a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t34a, t34r, 32u);
        state.regs[0] = t34r;
    // 0x0088625b: 3bc7 CMP
        t35a = state.regs[0];
        t35b = state.regs[7];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x0088625d: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00886267;
    // 0x0088625f: 50 PUSH
        batch_guest_pc = 0x0088625fu;
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00886260: 8bce MOV
        t38 = state.regs[6];
        state.regs[1] = t38;
    // 0x00886262: e8290e0000 CALL
        if (!batch_guest_call32(memory, state, 0x00887090u, 0x00886267u)) return BatchLiftStatus::invalid_memory;
        t39_call_status = spore_lift_00887090(memory, state);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
        if (state.eip != 0x00886267u) return BatchLiftStatus::invalid_control_flow;
    // 0x00886267: 85ed TEST
    L_00886267:
        t40a = state.regs[5];
        t40b = state.regs[5];
        t40r = (t40a & t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
    // 0x00886269: 7629 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00886294;
    // 0x0088626b: 8b5604 MOV
        batch_guest_pc = 0x0088626bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x0088626e: 53 PUSH
        batch_guest_pc = 0x0088626eu;
        t43a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x0088626f: 8a5c241c MOV
        batch_guest_pc = 0x0088626fu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = (state.regs[3] & 0xffffff00u) | ((t44 << 0u) & 0x000000ffu);
    // 0x00886273: 8d45ff LEA
        t45 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffffu);
        state.regs[0] = t45;
    // 0x00886276: 0fb6cb MOVZX
        t46a = state.regs[3] & 0x000000ffu;
        state.regs[1] = t46a;
    // 0x00886279: 50 PUSH
        batch_guest_pc = 0x00886279u;
        t47a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t47a)) return BatchLiftStatus::invalid_memory;
    // 0x0088627a: 51 PUSH
        batch_guest_pc = 0x0088627au;
        t48a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x0088627b: 42 INC
        t49a = state.regs[2];
        t49r = static_cast<std::uint32_t>(t49a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t49a, t49r, 32u);
        state.regs[2] = t49r;
    // 0x0088627c: 52 PUSH
        batch_guest_pc = 0x0088627cu;
        t50a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x0088627d: e8bca49500 CALL
        t51_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x011e073eu, 0x00886282u);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x00886282u) return BatchLiftStatus::invalid_control_flow;
    // 0x00886282: 8b4604 MOV
        batch_guest_pc = 0x00886282u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x00886285: 8818 MOV
        batch_guest_pc = 0x00886285u;
        t53 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00886287: 83c40c ADD
        t54a = state.regs[4];
        t54b = 0x0000000cu;
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[4] = t54r;
    // 0x0088628a: 016e04 ADD
        batch_guest_pc = 0x0088628au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t55a)) return BatchLiftStatus::invalid_memory;
        t55b = state.regs[5];
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t55r)) return BatchLiftStatus::invalid_memory;
    // 0x0088628d: 8b4604 MOV
        batch_guest_pc = 0x0088628du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x00886290: c60000 MOV
        batch_guest_pc = 0x00886290u;
        t57 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00886293: 5b POP
        batch_guest_pc = 0x00886293u;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t58a;
    // 0x00886294: 5f POP
    L_00886294:
        batch_guest_pc = 0x00886294u;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t59a;
    // 0x00886295: 8bc6 MOV
        t60 = state.regs[6];
        state.regs[0] = t60;
    // 0x00886297: 5e POP
        batch_guest_pc = 0x00886297u;
        if (!memory.load32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t61a;
    // 0x00886298: 5d POP
        batch_guest_pc = 0x00886298u;
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t62a;
    // 0x00886299: 59 POP
        batch_guest_pc = 0x00886299u;
        if (!memory.load32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t63a;
    // 0x0088629a: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
