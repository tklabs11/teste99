#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0092584c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925880(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009257e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009257e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0, t24c = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0, t42c = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56a = 0;
    BatchLiftStatus t57_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t71a = 0;
    BatchLiftStatus t72_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t73a = 0, t73c = 0, t73r = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85a = 0;
    std::uint32_t t86a = 0;
    BatchLiftStatus t87_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t88a = 0, t88c = 0, t88r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96a = 0;
    BatchLiftStatus t97_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108a = 0;

    // 0x009257e0: 51 PUSH
        batch_guest_pc = 0x009257e0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e1: 53 PUSH
        batch_guest_pc = 0x009257e1u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e2: 56 PUSH
        batch_guest_pc = 0x009257e2u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e3: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x009257e5: 8b4604 MOV
        batch_guest_pc = 0x009257e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x009257e8: 57 PUSH
        batch_guest_pc = 0x009257e8u;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x009257e9: 3b4608 CMP
        batch_guest_pc = 0x009257e9u;
        t6a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t6b)) return BatchLiftStatus::invalid_memory;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x009257ec: 744a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925838;
    // 0x009257ee: 8b4c2418 MOV
        batch_guest_pc = 0x009257eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x009257f2: 8b7c2414 MOV
        batch_guest_pc = 0x009257f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t9;
    // 0x009257f6: 8bd9 MOV
        t10 = state.regs[1];
        state.regs[3] = t10;
    // 0x009257f8: 3bcf CMP
        t11a = state.regs[1];
        t11b = state.regs[7];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x009257fa: 7207 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925803;
    // 0x009257fc: 3bc8 CMP
        t13a = state.regs[1];
        t13b = state.regs[0];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x009257fe: 7303 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00925803;
    // 0x00925800: 8d5904 LEA
        t15 = static_cast<std::uint32_t>(state.regs[1] + 0x00000004u);
        state.regs[3] = t15;
    // 0x00925803: 85c0 TEST
    L_00925803:
        t16a = state.regs[0];
        t16b = state.regs[0];
        t16r = (t16a & t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
    // 0x00925805: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092580c;
    // 0x00925807: 8b48fc MOV
        batch_guest_pc = 0x00925807u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t18;
    // 0x0092580a: 8908 MOV
        batch_guest_pc = 0x0092580au;
        t19 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x0092580c: 8b4e04 MOV
    L_0092580c:
        batch_guest_pc = 0x0092580cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x0092580f: 8d41fc LEA
        t21 = static_cast<std::uint32_t>(state.regs[1] + 0xfffffffcu);
        state.regs[0] = t21;
    // 0x00925812: 2bc7 SUB
        t22a = state.regs[0];
        t22b = state.regs[7];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
        state.regs[0] = t22r;
    // 0x00925814: 50 PUSH
        batch_guest_pc = 0x00925814u;
        t23a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00925815: c1f802 SAR
        t24a = state.regs[0];
        t24c = 2u;
        if (t24c != 0u) {
        t24r = (t24a >> t24c) | ((t24a & 0x80000000u) ? (0xffffffffu << (32u - t24c)) : 0u);
        batch_set_sar_flags(state, t24a, t24c, t24r, 32u);
            state.regs[0] = t24r;
        }
    // 0x00925818: 03c0 ADD
        t25a = state.regs[0];
        t25b = state.regs[0];
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x0092581a: 03c0 ADD
        t26a = state.regs[0];
        t26b = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[0] = t26r;
    // 0x0092581c: 2bc8 SUB
        t27a = state.regs[1];
        t27b = state.regs[0];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[1] = t27r;
    // 0x0092581e: 57 PUSH
        batch_guest_pc = 0x0092581eu;
        t28a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0092581f: 51 PUSH
        batch_guest_pc = 0x0092581fu;
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00925820: ff1580c43c01 CALL
        t30_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memmove", 0x013cc480u, 0x00925826u);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00925826u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925826: 8b13 MOV
        batch_guest_pc = 0x00925826u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t31;
    // 0x00925828: 83c40c ADD
        t32a = state.regs[4];
        t32b = 0x0000000cu;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[4] = t32r;
    // 0x0092582b: 8917 MOV
        batch_guest_pc = 0x0092582bu;
        t33 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0092582d: 83460404 ADD
        batch_guest_pc = 0x0092582du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t34a)) return BatchLiftStatus::invalid_memory;
        t34b = 0x00000004u;
        t34r = static_cast<std::uint32_t>(t34a + t34b) & 0xffffffffu;
        batch_set_add_flags(state, t34a, t34b, t34r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t34r)) return BatchLiftStatus::invalid_memory;
    // 0x00925831: 5f POP
        batch_guest_pc = 0x00925831u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t35a;
    // 0x00925832: 5e POP
        batch_guest_pc = 0x00925832u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x00925833: 5b POP
        batch_guest_pc = 0x00925833u;
        if (!memory.load32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t37a;
    // 0x00925834: 59 POP
        batch_guest_pc = 0x00925834u;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t38a;
    // 0x00925835: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925838: 2b06 SUB
    L_00925838:
        batch_guest_pc = 0x00925838u;
        t40a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t40b)) return BatchLiftStatus::invalid_memory;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
        state.regs[0] = t40r;
    // 0x0092583a: 55 PUSH
        batch_guest_pc = 0x0092583au;
        t41a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x0092583b: c1f802 SAR
        t42a = state.regs[0];
        t42c = 2u;
        if (t42c != 0u) {
        t42r = (t42a >> t42c) | ((t42a & 0x80000000u) ? (0xffffffffu << (32u - t42c)) : 0u);
        batch_set_sar_flags(state, t42a, t42c, t42r, 32u);
            state.regs[0] = t42r;
        }
    // 0x0092583e: 85c0 TEST
        t43a = state.regs[0];
        t43b = state.regs[0];
        t43r = (t43a & t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
    // 0x00925840: 762e JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925870;
    // 0x00925842: 03c0 ADD
        t45a = state.regs[0];
        t45b = state.regs[0];
        t45r = static_cast<std::uint32_t>(t45a + t45b) & 0xffffffffu;
        batch_set_add_flags(state, t45a, t45b, t45r, 32u);
        state.regs[0] = t45r;
    // 0x00925844: 89442410 MOV
        batch_guest_pc = 0x00925844u;
        t46 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00925848: 85c0 TEST
        t47a = state.regs[0];
        t47b = state.regs[0];
        t47r = (t47a & t47b) & 0xffffffffu;
        batch_set_logic_flags(state, t47r, 32u);
    // 0x0092584a: 7432 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092587e;
    // 0x0092584c: 68d1000000 PUSH
    L_0092584c:
        batch_guest_pc = 0x0092584cu;
        t49a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00925851: 6838bb3e01 PUSH
        batch_guest_pc = 0x00925851u;
        t50a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x00925856: 6a00 PUSH
        batch_guest_pc = 0x00925856u;
        t51a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00925858: 6a00 PUSH
        batch_guest_pc = 0x00925858u;
        t52a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x0092585a: 03c0 ADD
        t53a = state.regs[0];
        t53b = state.regs[0];
        t53r = static_cast<std::uint32_t>(t53a + t53b) & 0xffffffffu;
        batch_set_add_flags(state, t53a, t53b, t53r, 32u);
        state.regs[0] = t53r;
    // 0x0092585c: 03c0 ADD
        t54a = state.regs[0];
        t54b = state.regs[0];
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[0] = t54r;
    // 0x0092585e: 6800e04301 PUSH
        batch_guest_pc = 0x0092585eu;
        t55a = 0x0143e000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00925863: 50 PUSH
        batch_guest_pc = 0x00925863u;
        t56a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00925864: e8371b6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00925869u)) return BatchLiftStatus::invalid_memory;
        t57_call_status = spore_lift_00f473a0(memory, state);
        if (t57_call_status != BatchLiftStatus::returned) return t57_call_status;
        if (state.eip != 0x00925869u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925869: 83c418 ADD
        t58a = state.regs[4];
        t58b = 0x00000018u;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x0092586c: 8be8 MOV
        t59 = state.regs[0];
        state.regs[5] = t59;
    // 0x0092586e: eb10 JMP
        goto L_00925880;
    // 0x00925870: c744241001000000 MOV
    L_00925870:
        batch_guest_pc = 0x00925870u;
        t61 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00925878: 8b442410 MOV
        batch_guest_pc = 0x00925878u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t62;
    // 0x0092587c: ebce JMP
        goto L_0092584c;
    // 0x0092587e: 33ed XOR
    L_0092587e:
        t64a = state.regs[5];
        t64b = state.regs[5];
        t64r = (t64a ^ t64b) & 0xffffffffu;
        batch_set_logic_flags(state, t64r, 32u);
        state.regs[5] = t64r;
    // 0x00925880: 8b06 MOV
    L_00925880:
        batch_guest_pc = 0x00925880u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t65;
    // 0x00925882: 8b5c2418 MOV
        batch_guest_pc = 0x00925882u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t66;
    // 0x00925886: 8bfb MOV
        t67 = state.regs[3];
        state.regs[7] = t67;
    // 0x00925888: 2bf8 SUB
        t68a = state.regs[7];
        t68b = state.regs[0];
        t68r = static_cast<std::uint32_t>(t68a - t68b) & 0xffffffffu;
        batch_set_sub_flags(state, t68a, t68b, t68r, 32u);
        state.regs[7] = t68r;
    // 0x0092588a: 57 PUSH
        batch_guest_pc = 0x0092588au;
        t69a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588b: 50 PUSH
        batch_guest_pc = 0x0092588bu;
        t70a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588c: 55 PUSH
        batch_guest_pc = 0x0092588cu;
        t71a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
    // 0x0092588d: e8b2ae8b00 CALL
        t72_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00925892u);
        if (t72_call_status != BatchLiftStatus::returned) return t72_call_status;
        if (state.eip != 0x00925892u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925892: c1ff02 SAR
        t73a = state.regs[7];
        t73c = 2u;
        if (t73c != 0u) {
        t73r = (t73a >> t73c) | ((t73a & 0x80000000u) ? (0xffffffffu << (32u - t73c)) : 0u);
        batch_set_sar_flags(state, t73a, t73c, t73r, 32u);
            state.regs[7] = t73r;
        }
    // 0x00925895: 8d04b8 LEA
        t74 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u);
        state.regs[0] = t74;
    // 0x00925898: 83c40c ADD
        t75a = state.regs[4];
        t75b = 0x0000000cu;
        t75r = static_cast<std::uint32_t>(t75a + t75b) & 0xffffffffu;
        batch_set_add_flags(state, t75a, t75b, t75r, 32u);
        state.regs[4] = t75r;
    // 0x0092589b: 85c0 TEST
        t76a = state.regs[0];
        t76b = state.regs[0];
        t76r = (t76a & t76b) & 0xffffffffu;
        batch_set_logic_flags(state, t76r, 32u);
    // 0x0092589d: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258a7;
    // 0x0092589f: 8b4c241c MOV
        batch_guest_pc = 0x0092589fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t78;
    // 0x009258a3: 8b11 MOV
        batch_guest_pc = 0x009258a3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t79;
    // 0x009258a5: 8910 MOV
        batch_guest_pc = 0x009258a5u;
        t80 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x009258a7: 8b7e04 MOV
    L_009258a7:
        batch_guest_pc = 0x009258a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t81;
    // 0x009258aa: 2bfb SUB
        t82a = state.regs[7];
        t82b = state.regs[3];
        t82r = static_cast<std::uint32_t>(t82a - t82b) & 0xffffffffu;
        batch_set_sub_flags(state, t82a, t82b, t82r, 32u);
        state.regs[7] = t82r;
    // 0x009258ac: 57 PUSH
        batch_guest_pc = 0x009258acu;
        t83a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x009258ad: 83c004 ADD
        t84a = state.regs[0];
        t84b = 0x00000004u;
        t84r = static_cast<std::uint32_t>(t84a + t84b) & 0xffffffffu;
        batch_set_add_flags(state, t84a, t84b, t84r, 32u);
        state.regs[0] = t84r;
    // 0x009258b0: 53 PUSH
        batch_guest_pc = 0x009258b0u;
        t85a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t85a)) return BatchLiftStatus::invalid_memory;
    // 0x009258b1: 50 PUSH
        batch_guest_pc = 0x009258b1u;
        t86a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x009258b2: e88dae8b00 CALL
        t87_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x009258b7u);
        if (t87_call_status != BatchLiftStatus::returned) return t87_call_status;
        if (state.eip != 0x009258b7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009258b7: c1ff02 SAR
        t88a = state.regs[7];
        t88c = 2u;
        if (t88c != 0u) {
        t88r = (t88a >> t88c) | ((t88a & 0x80000000u) ? (0xffffffffu << (32u - t88c)) : 0u);
        batch_set_sar_flags(state, t88a, t88c, t88r, 32u);
            state.regs[7] = t88r;
        }
    // 0x009258ba: 8d3cb8 LEA
        t89 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u);
        state.regs[7] = t89;
    // 0x009258bd: 8b06 MOV
        batch_guest_pc = 0x009258bdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t90;
    // 0x009258bf: 83c40c ADD
        t91a = state.regs[4];
        t91b = 0x0000000cu;
        t91r = static_cast<std::uint32_t>(t91a + t91b) & 0xffffffffu;
        batch_set_add_flags(state, t91a, t91b, t91r, 32u);
        state.regs[4] = t91r;
    // 0x009258c2: 85c0 TEST
        t92a = state.regs[0];
        t92b = state.regs[0];
        t92r = (t92a & t92b) & 0xffffffffu;
        batch_set_logic_flags(state, t92r, 32u);
    // 0x009258c4: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258d5;
    // 0x009258c6: 8378fc00 CMP
        batch_guest_pc = 0x009258c6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t94a)) return BatchLiftStatus::invalid_memory;
        t94b = 0x00000000u;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
    // 0x009258ca: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009258d5;
    // 0x009258cc: 50 PUSH
        batch_guest_pc = 0x009258ccu;
        t96a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x009258cd: e8ae1a6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009258d2u)) return BatchLiftStatus::invalid_memory;
        t97_call_status = spore_lift_00f47380(memory, state);
        if (t97_call_status != BatchLiftStatus::returned) return t97_call_status;
        if (state.eip != 0x009258d2u) return BatchLiftStatus::invalid_control_flow;
    // 0x009258d2: 83c404 ADD
        t98a = state.regs[4];
        t98b = 0x00000004u;
        t98r = static_cast<std::uint32_t>(t98a + t98b) & 0xffffffffu;
        batch_set_add_flags(state, t98a, t98b, t98r, 32u);
        state.regs[4] = t98r;
    // 0x009258d5: 8b442410 MOV
    L_009258d5:
        batch_guest_pc = 0x009258d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t99)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t99;
    // 0x009258d9: 892e MOV
        batch_guest_pc = 0x009258d9u;
        t100 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t100)) return BatchLiftStatus::invalid_memory;
    // 0x009258db: 8d4c8500 LEA
        t101 = static_cast<std::uint32_t>(state.regs[5] + state.regs[0] * 4u + 0x00000000u);
        state.regs[1] = t101;
    // 0x009258df: 5d POP
        batch_guest_pc = 0x009258dfu;
        if (!memory.load32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t102a;
    // 0x009258e0: 897e04 MOV
        batch_guest_pc = 0x009258e0u;
        t103 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t103)) return BatchLiftStatus::invalid_memory;
    // 0x009258e3: 5f POP
        batch_guest_pc = 0x009258e3u;
        if (!memory.load32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t104a;
    // 0x009258e4: 894e08 MOV
        batch_guest_pc = 0x009258e4u;
        t105 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x009258e7: 5e POP
        batch_guest_pc = 0x009258e7u;
        if (!memory.load32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t106a;
    // 0x009258e8: 5b POP
        batch_guest_pc = 0x009258e8u;
        if (!memory.load32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t107a;
    // 0x009258e9: 59 POP
        batch_guest_pc = 0x009258e9u;
        if (!memory.load32(state.regs[4], t108a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t108a;
    // 0x009258ea: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
