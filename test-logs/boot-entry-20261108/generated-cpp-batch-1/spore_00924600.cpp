#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923ac0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924060(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924600(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924600u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0, t32r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;

    // 0x00924600: 83ec10 SUB
        t0a = state.regs[4];
        t0b = 0x00000010u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00924603: 56 PUSH
        batch_guest_pc = 0x00924603u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924604: 57 PUSH
        batch_guest_pc = 0x00924604u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00924605: 8b7c241c MOV
        batch_guest_pc = 0x00924605u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t3;
    // 0x00924609: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x0092460b: 85ff TEST
        t5a = state.regs[7];
        t5b = state.regs[7];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x0092460d: 0f849e000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009246b1;
    // 0x00924613: 803f00 CMP
        batch_guest_pc = 0x00924613u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = 0x00000000u;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0x000000ffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 8u);
    // 0x00924616: 0f8495000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009246b1;
    // 0x0092461c: 53 PUSH
        batch_guest_pc = 0x0092461cu;
        t9a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0092461d: 8d442420 LEA
        t10 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[0] = t10;
    // 0x00924621: 50 PUSH
        batch_guest_pc = 0x00924621u;
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00924622: 8d4c2410 LEA
        t12 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t12;
    // 0x00924626: 8d5e1c LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu);
        state.regs[3] = t13;
    // 0x00924629: 51 PUSH
        batch_guest_pc = 0x00924629u;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0092462a: 8bcb MOV
        t15 = state.regs[3];
        state.regs[1] = t15;
    // 0x0092462c: e88ff4ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923ac0u, 0x00924631u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00923ac0(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00924631u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924631: 8b44240c MOV
        batch_guest_pc = 0x00924631u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x00924635: 83c620 ADD
        t18a = state.regs[6];
        t18b = 0x00000020u;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[6] = t18r;
    // 0x00924638: 3bc6 CMP
        t19a = state.regs[0];
        t19b = state.regs[6];
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x0092463a: 7565 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009246a1;
    // 0x0092463c: 8bc7 MOV
        t21 = state.regs[7];
        state.regs[0] = t21;
    // 0x0092463e: 8d5001 LEA
        t22 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t22;
    // 0x00924641: 8a08 MOV
    L_00924641:
        batch_guest_pc = 0x00924641u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t23 << 0u) & 0x000000ffu);
    // 0x00924643: 40 INC
        t24a = state.regs[0];
        t24r = static_cast<std::uint32_t>(t24a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t24a, t24r, 32u);
        state.regs[0] = t24r;
    // 0x00924644: 84c9 TEST
        t25a = state.regs[1] & 0x000000ffu;
        t25b = state.regs[1] & 0x000000ffu;
        t25r = (t25a & t25b) & 0x000000ffu;
        batch_set_logic_flags(state, t25r, 8u);
    // 0x00924646: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924641;
    // 0x00924648: 6a00 PUSH
        batch_guest_pc = 0x00924648u;
        t27a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x0092464a: 6a00 PUSH
        batch_guest_pc = 0x0092464au;
        t28a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0092464c: 6a00 PUSH
        batch_guest_pc = 0x0092464cu;
        t29a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x0092464e: 2bc2 SUB
        t30a = state.regs[0];
        t30b = state.regs[2];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
        state.regs[0] = t30r;
    // 0x00924650: 6a00 PUSH
        batch_guest_pc = 0x00924650u;
        t31a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00924652: 40 INC
        t32a = state.regs[0];
        t32r = static_cast<std::uint32_t>(t32a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t32a, t32r, 32u);
        state.regs[0] = t32r;
    // 0x00924653: 6894de4301 PUSH
        batch_guest_pc = 0x00924653u;
        t33a = 0x0143de94u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00924658: 50 PUSH
        batch_guest_pc = 0x00924658u;
        t34a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00924659: e8422d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x0092465eu)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_00f473a0(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x0092465eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092465e: 8bf0 MOV
        t36 = state.regs[0];
        state.regs[6] = t36;
    // 0x00924660: 83c418 ADD
        t37a = state.regs[4];
        t37b = 0x00000018u;
        t37r = static_cast<std::uint32_t>(t37a + t37b) & 0xffffffffu;
        batch_set_add_flags(state, t37a, t37b, t37r, 32u);
        state.regs[4] = t37r;
    // 0x00924663: 8bcf MOV
        t38 = state.regs[7];
        state.regs[1] = t38;
    // 0x00924665: 2bf7 SUB
        t39a = state.regs[6];
        t39b = state.regs[7];
        t39r = static_cast<std::uint32_t>(t39a - t39b) & 0xffffffffu;
        batch_set_sub_flags(state, t39a, t39b, t39r, 32u);
        state.regs[6] = t39r;
    // 0x00924667: 8a11 MOV
    L_00924667:
        batch_guest_pc = 0x00924667u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t40 << 0u) & 0x000000ffu);
    // 0x00924669: 88140e MOV
        batch_guest_pc = 0x00924669u;
        t41 = state.regs[2] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + state.regs[1] * 1u + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0092466c: 41 INC
        t42a = state.regs[1];
        t42r = static_cast<std::uint32_t>(t42a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t42a, t42r, 32u);
        state.regs[1] = t42r;
    // 0x0092466d: 84d2 TEST
        t43a = state.regs[2] & 0x000000ffu;
        t43b = state.regs[2] & 0x000000ffu;
        t43r = (t43a & t43b) & 0x000000ffu;
        batch_set_logic_flags(state, t43r, 8u);
    // 0x0092466f: 75f6 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924667;
    // 0x00924671: 8b542424 MOV
        batch_guest_pc = 0x00924671u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x00924675: 8944240c MOV
        batch_guest_pc = 0x00924675u;
        t46 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00924679: c644242400 MOV
        batch_guest_pc = 0x00924679u;
        t47 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x0092467e: 8b442424 MOV
        batch_guest_pc = 0x0092467eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00924682: 50 PUSH
        batch_guest_pc = 0x00924682u;
        t49a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00924683: 8d4c2410 LEA
        t50 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t50;
    // 0x00924687: 89542414 MOV
        batch_guest_pc = 0x00924687u;
        t51 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x0092468b: 51 PUSH
        batch_guest_pc = 0x0092468bu;
        t52a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x0092468c: 8d54241c LEA
        t53 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[2] = t53;
    // 0x00924690: 52 PUSH
        batch_guest_pc = 0x00924690u;
        t54a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00924691: 8bcb MOV
        t55 = state.regs[3];
        state.regs[1] = t55;
    // 0x00924693: e8c8f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00924060u, 0x00924698u)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00924060(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x00924698u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924698: 5b POP
        batch_guest_pc = 0x00924698u;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t57a;
    // 0x00924699: 5f POP
        batch_guest_pc = 0x00924699u;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t58a;
    // 0x0092469a: 5e POP
        batch_guest_pc = 0x0092469au;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t59a;
    // 0x0092469b: 83c410 ADD
        t60a = state.regs[4];
        t60b = 0x00000010u;
        t60r = static_cast<std::uint32_t>(t60a + t60b) & 0xffffffffu;
        batch_set_add_flags(state, t60a, t60b, t60r, 32u);
        state.regs[4] = t60r;
    // 0x0092469e: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009246a1: 8b4c2424 MOV
    L_009246a1:
        batch_guest_pc = 0x009246a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x009246a5: 5b POP
        batch_guest_pc = 0x009246a5u;
        if (!memory.load32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t63a;
    // 0x009246a6: 5f POP
        batch_guest_pc = 0x009246a6u;
        if (!memory.load32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t64a;
    // 0x009246a7: 894814 MOV
        batch_guest_pc = 0x009246a7u;
        t65 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t65)) return BatchLiftStatus::invalid_memory;
    // 0x009246aa: 5e POP
        batch_guest_pc = 0x009246aau;
        if (!memory.load32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t66a;
    // 0x009246ab: 83c410 ADD
        t67a = state.regs[4];
        t67b = 0x00000010u;
        t67r = static_cast<std::uint32_t>(t67a + t67b) & 0xffffffffu;
        batch_set_add_flags(state, t67a, t67b, t67r, 32u);
        state.regs[4] = t67r;
    // 0x009246ae: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009246b1: 8b542420 MOV
    L_009246b1:
        batch_guest_pc = 0x009246b1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t69;
    // 0x009246b5: 5f POP
        batch_guest_pc = 0x009246b5u;
        if (!memory.load32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t70a;
    // 0x009246b6: 895618 MOV
        batch_guest_pc = 0x009246b6u;
        t71 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x009246b9: 5e POP
        batch_guest_pc = 0x009246b9u;
        if (!memory.load32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t72a;
    // 0x009246ba: 83c410 ADD
        t73a = state.regs[4];
        t73b = 0x00000010u;
        t73r = static_cast<std::uint32_t>(t73a + t73b) & 0xffffffffu;
        batch_set_add_flags(state, t73a, t73b, t73r, 32u);
        state.regs[4] = t73r;
    // 0x009246bd: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
