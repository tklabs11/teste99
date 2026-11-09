#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00690540(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690684(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690735(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690765(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0069077f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690f60(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00690630(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00690630u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61 = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0;
    std::uint32_t t88 = 0;
    BatchLiftStatus t89_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t118 = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t128a = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140a = 0, t140b = 0, t140r = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143a = 0;
    std::uint32_t t144a = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146a = 0, t146b = 0, t146r = 0;

    // 0x00690630: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00690632: 6858ce2001 PUSH
        t1a = 0x0120ce58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00690637: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0069063d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0069063e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00690645: 83ec08 SUB
        t5a = state.regs[4];
        t5b = 0x00000008u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00690648: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00690649: 8d442404 LEA
        t7 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t7;
    // 0x0069064d: 55 PUSH
        t8a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x0069064e: 8be9 MOV
        t9 = state.regs[1];
        state.regs[5] = t9;
    // 0x00690650: 8bc8 MOV
        t10 = state.regs[0];
        state.regs[1] = t10;
    // 0x00690652: 8944240c MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00690656: 894c2408 MOV
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0069065a: 8b442420 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x0069065e: 33db XOR
        t14a = state.regs[3];
        t14b = state.regs[3];
        t14r = (t14a ^ t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
        state.regs[3] = t14r;
    // 0x00690660: 83c040 ADD
        t15a = state.regs[0];
        t15b = 0x00000040u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00690663: 895c2418 MOV
        t16 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00690667: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x0069066a: 0f842d010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069079d;
    // 0x00690670: 56 PUSH
        t19a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00690671: 57 PUSH
        t20a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00690672: 8b542428 MOV
    L_00690672:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x00690676: 8b4244 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000044u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x00690679: 3bc3 CMP
        t23a = state.regs[0];
        t23b = state.regs[3];
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x0069067b: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690682;
    // 0x0069067d: 83c0f8 ADD
        t25a = state.regs[0];
        t25b = 0xfffffff8u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x00690680: eb02 JMP
        goto L_00690684;
    // 0x00690682: 33c0 XOR
    L_00690682:
        t27a = state.regs[0];
        t27b = state.regs[0];
        t27r = (t27a ^ t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[0] = t27r;
    // 0x00690684: 8b500c MOV
    L_00690684:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t28;
    // 0x00690687: 8b7014 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t29;
    // 0x0069068a: 8b7808 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t30;
    // 0x0069068d: 8d4808 LEA
        t31 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[1] = t31;
    // 0x00690690: 893a MOV
        t32 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00690692: 895704 MOV
        t33 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00690695: 8919 MOV
        t34 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00690697: 895904 MOV
        t35 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x0069069a: 8a5018 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t36 << 0u) & 0x000000ffu);
    // 0x0069069d: 3ad3 CMP
        t37a = state.regs[2] & 0x000000ffu;
        t37b = state.regs[3] & 0x000000ffu;
        t37r = static_cast<std::uint32_t>(t37a - t37b) & 0x000000ffu;
        batch_set_sub_flags(state, t37a, t37b, t37r, 8u);
    // 0x0069069f: 7464 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690705;
    // 0x006906a1: 33db XOR
        t39a = state.regs[3];
        t39b = state.regs[3];
        t39r = (t39a ^ t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
        state.regs[3] = t39r;
    // 0x006906a3: 385c242c CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t40a)) return BatchLiftStatus::invalid_memory;
        t40b = state.regs[3] & 0x000000ffu;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0x000000ffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 8u);
    // 0x006906a7: 7540 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006906e9;
    // 0x006906a9: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x006906ac: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t43;
    // 0x006906ae: 8911 MOV
        t44 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x006906b0: 894a04 MOV
        t45 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x006906b3: 895804 MOV
        t46 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x006906b6: 8918 MOV
        t47 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x006906b8: 8b95d4010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000001d4u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x006906be: 8d8dd0010000 LEA
        t49 = static_cast<std::uint32_t>(state.regs[5] + 0x000001d0u);
        state.regs[1] = t49;
    // 0x006906c4: 895004 MOV
        t50 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x006906c7: 8908 MOV
        t51 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x006906c9: 894104 MOV
        t52 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x006906cc: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t53;
    // 0x006906cf: 8901 MOV
        t54 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x006906d1: 8d4638 LEA
        t55 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[0] = t55;
    // 0x006906d4: 394004 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t56a)) return BatchLiftStatus::invalid_memory;
        t56b = state.regs[0];
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x006906d7: 755c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690735;
    // 0x006906d9: 837e1c02 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t58a)) return BatchLiftStatus::invalid_memory;
        t58b = 0x00000002u;
        t58r = static_cast<std::uint32_t>(t58a - t58b) & 0xffffffffu;
        batch_set_sub_flags(state, t58a, t58b, t58r, 32u);
    // 0x006906dd: 7556 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690735;
    // 0x006906df: 56 PUSH
        t60a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
    // 0x006906e0: 8bcd MOV
        t61 = state.regs[5];
        state.regs[1] = t61;
    // 0x006906e2: e859feffff CALL
        if (!batch_guest_call32(memory, state, 0x00690540u, 0x006906e7u)) return BatchLiftStatus::invalid_memory;
        t62_call_status = spore_lift_00690540(memory, state);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
        if (state.eip != 0x006906e7u) return BatchLiftStatus::invalid_control_flow;
    // 0x006906e7: eb4c JMP
        goto L_00690735;
    // 0x006906e9: 3ad3 CMP
    L_006906e9:
        t64a = state.regs[2] & 0x000000ffu;
        t64b = state.regs[3] & 0x000000ffu;
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0x000000ffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 8u);
    // 0x006906eb: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690705;
    // 0x006906ed: 8b542414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t66;
    // 0x006906f1: 895104 MOV
        t67 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t67)) return BatchLiftStatus::invalid_memory;
    // 0x006906f4: 8d442410 LEA
        t68 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t68;
    // 0x006906f8: 8901 MOV
        t69 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x006906fa: 894c2414 MOV
        t70 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x006906fe: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t71;
    // 0x00690701: 890a MOV
        t72 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x00690703: eb30 JMP
        goto L_00690735;
    // 0x00690705: 8b4804 MOV
    L_00690705:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t74;
    // 0x00690708: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t75;
    // 0x0069070a: 8911 MOV
        t76 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x0069070c: 894a04 MOV
        t77 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x0069070f: 895804 MOV
        t78 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00690712: 8918 MOV
        t79 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x00690714: 8b95d4010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000001d4u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t80;
    // 0x0069071a: 8d8dd0010000 LEA
        t81 = static_cast<std::uint32_t>(state.regs[5] + 0x000001d0u);
        state.regs[1] = t81;
    // 0x00690720: 8908 MOV
        t82 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00690722: 895004 MOV
        t83 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00690725: 894104 MOV
        t84 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x00690728: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t85)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t85;
    // 0x0069072b: 8901 MOV
        t86 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t86)) return BatchLiftStatus::invalid_memory;
    // 0x0069072d: 56 PUSH
        t87a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t87a)) return BatchLiftStatus::invalid_memory;
    // 0x0069072e: 8bcd MOV
        t88 = state.regs[5];
        state.regs[1] = t88;
    // 0x00690730: e82b080000 CALL
        if (!batch_guest_call32(memory, state, 0x00690f60u, 0x00690735u)) return BatchLiftStatus::invalid_memory;
        t89_call_status = spore_lift_00690f60(memory, state);
        if (t89_call_status != BatchLiftStatus::returned) return t89_call_status;
        if (state.eip != 0x00690735u) return BatchLiftStatus::invalid_control_flow;
    // 0x00690735: 8b7c2428 MOV
    L_00690735:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t90;
    // 0x00690739: 83c740 ADD
        t91a = state.regs[7];
        t91b = 0x00000040u;
        t91r = static_cast<std::uint32_t>(t91a + t91b) & 0xffffffffu;
        batch_set_add_flags(state, t91a, t91b, t91r, 32u);
        state.regs[7] = t91r;
    // 0x0069073c: 397f04 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t92a)) return BatchLiftStatus::invalid_memory;
        t92b = state.regs[7];
        t92r = static_cast<std::uint32_t>(t92a - t92b) & 0xffffffffu;
        batch_set_sub_flags(state, t92a, t92b, t92r, 32u);
    // 0x0069073f: 0f852dffffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690672;
    // 0x00690745: 8b442414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t94;
    // 0x00690749: 8d542410 LEA
        t95 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[2] = t95;
    // 0x0069074d: 3bc2 CMP
        t96a = state.regs[0];
        t96b = state.regs[2];
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
    // 0x0069074f: 744a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069079b;
    // 0x00690751: 3bc3 CMP
    L_00690751:
        t98a = state.regs[0];
        t98b = state.regs[3];
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
    // 0x00690753: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690761;
    // 0x00690755: 8d70f8 LEA
        t100 = static_cast<std::uint32_t>(state.regs[0] + 0xfffffff8u);
        state.regs[6] = t100;
    // 0x00690758: 3bf3 CMP
        t101a = state.regs[6];
        t101b = state.regs[3];
        t101r = static_cast<std::uint32_t>(t101a - t101b) & 0xffffffffu;
        batch_set_sub_flags(state, t101a, t101b, t101r, 32u);
    // 0x0069075a: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00690763;
    // 0x0069075c: 8d4608 LEA
        t103 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[0] = t103;
    // 0x0069075f: eb04 JMP
        goto L_00690765;
    // 0x00690761: 33f6 XOR
    L_00690761:
        t105a = state.regs[6];
        t105b = state.regs[6];
        t105r = (t105a ^ t105b) & 0xffffffffu;
        batch_set_logic_flags(state, t105r, 32u);
        state.regs[6] = t105r;
    // 0x00690763: 33c0 XOR
    L_00690763:
        t106a = state.regs[0];
        t106b = state.regs[0];
        t106r = (t106a ^ t106b) & 0xffffffffu;
        batch_set_logic_flags(state, t106r, 32u);
        state.regs[0] = t106r;
    // 0x00690765: 8b4804 MOV
    L_00690765:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t107;
    // 0x00690768: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t108;
    // 0x0069076a: 8911 MOV
        t109 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t109)) return BatchLiftStatus::invalid_memory;
    // 0x0069076c: 894a04 MOV
        t110 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t110)) return BatchLiftStatus::invalid_memory;
    // 0x0069076f: 8918 MOV
        t111 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t111)) return BatchLiftStatus::invalid_memory;
    // 0x00690771: 895804 MOV
        t112 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t112)) return BatchLiftStatus::invalid_memory;
    // 0x00690774: 3bf3 CMP
        t113a = state.regs[6];
        t113b = state.regs[3];
        t113r = static_cast<std::uint32_t>(t113a - t113b) & 0xffffffffu;
        batch_set_sub_flags(state, t113a, t113b, t113r, 32u);
    // 0x00690776: 7405 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069077d;
    // 0x00690778: 8d4608 LEA
        t115 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[0] = t115;
    // 0x0069077b: eb02 JMP
        goto L_0069077f;
    // 0x0069077d: 33c0 XOR
    L_0069077d:
        t117a = state.regs[0];
        t117b = state.regs[0];
        t117r = (t117a ^ t117b) & 0xffffffffu;
        batch_set_logic_flags(state, t117r, 32u);
        state.regs[0] = t117r;
    // 0x0069077f: 8b4f04 MOV
    L_0069077f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t118)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t118;
    // 0x00690782: 894804 MOV
        t119 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t119)) return BatchLiftStatus::invalid_memory;
    // 0x00690785: 8938 MOV
        t120 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t120)) return BatchLiftStatus::invalid_memory;
    // 0x00690787: 894704 MOV
        t121 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t121)) return BatchLiftStatus::invalid_memory;
    // 0x0069078a: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t122;
    // 0x0069078d: 8902 MOV
        t123 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t123)) return BatchLiftStatus::invalid_memory;
    // 0x0069078f: 8b442414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t124;
    // 0x00690793: 8d4c2410 LEA
        t125 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t125;
    // 0x00690797: 3bc1 CMP
        t126a = state.regs[0];
        t126b = state.regs[1];
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
    // 0x00690799: 75b6 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00690751;
    // 0x0069079b: 5f POP
    L_0069079b:
        if (!memory.load32(state.regs[4], t128a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t128a;
    // 0x0069079c: 5e POP
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t129a;
    // 0x0069079d: 8b442408 MOV
    L_0069079d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t130)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t130;
    // 0x006907a1: 8d542408 LEA
        t131 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[2] = t131;
    // 0x006907a5: 3bc2 CMP
        t132a = state.regs[0];
        t132b = state.regs[2];
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0xffffffffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 32u);
    // 0x006907a7: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006907c1;
    // 0x006907a9: 8da42400000000 LEA
        t134 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t134;
    // 0x006907b0: 8b08 MOV
    L_006907b0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t135)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t135;
    // 0x006907b2: 8d542408 LEA
        t136 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[2] = t136;
    // 0x006907b6: 895804 MOV
        t137 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x006907b9: 8918 MOV
        t138 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t138)) return BatchLiftStatus::invalid_memory;
    // 0x006907bb: 8bc1 MOV
        t139 = state.regs[1];
        state.regs[0] = t139;
    // 0x006907bd: 3bca CMP
        t140a = state.regs[1];
        t140b = state.regs[2];
        t140r = static_cast<std::uint32_t>(t140a - t140b) & 0xffffffffu;
        batch_set_sub_flags(state, t140a, t140b, t140r, 32u);
    // 0x006907bf: 75ef JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006907b0;
    // 0x006907c1: 8b4c2410 MOV
    L_006907c1:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t142)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t142;
    // 0x006907c5: 5d POP
        if (!memory.load32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t143a;
    // 0x006907c6: 5b POP
        if (!memory.load32(state.regs[4], t144a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t144a;
    // 0x006907c7: 64890d00000000 MOV
        t145 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x006907ce: 83c414 ADD
        t146a = state.regs[4];
        t146b = 0x00000014u;
        t146r = static_cast<std::uint32_t>(t146a + t146b) & 0xffffffffu;
        batch_set_add_flags(state, t146a, t146b, t146r, 32u);
        state.regs[4] = t146r;
    // 0x006907d1: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
