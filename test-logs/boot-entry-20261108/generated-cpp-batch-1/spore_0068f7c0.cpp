#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f882(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f8d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f900(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f913(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690f60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0068f7c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068f7c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t62a = 0, t62b = 0, t62r = 0;
    std::uint32_t t64 = 0;
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0;
    BatchLiftStatus t71_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    BatchLiftStatus t79_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t80a = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t83 = 0;
    BatchLiftStatus t84_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    BatchLiftStatus t91_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    BatchLiftStatus t97_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t102a = 0;
    std::uint32_t t103 = 0;
    BatchLiftStatus t104_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114a = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117 = 0;
    BatchLiftStatus t118_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;

    // 0x0068f7c0: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7c2: 68d8872101 PUSH
        t1a = 0x012187d8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7c7: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0068f7cd: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7ce: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7d5: 83ec10 SUB
        t5a = state.regs[4];
        t5b = 0x00000010u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x0068f7d8: 53 PUSH
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7d9: 55 PUSH
        t7a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7da: 56 PUSH
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7db: 33db XOR
        t9a = state.regs[3];
        t9b = state.regs[3];
        t9r = (t9a ^ t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
        state.regs[3] = t9r;
    // 0x0068f7dd: 57 PUSH
        t10a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7de: 8bf9 MOV
        t11 = state.regs[1];
        state.regs[7] = t11;
    // 0x0068f7e0: 895c2410 MOV
        t12 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7e4: 8b742434 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t13;
    // 0x0068f7e8: 56 PUSH
        t14a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7e9: 895c242c MOV
        t15 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7ed: e86e170000 CALL
        if (!batch_guest_call32(memory, state, 0x00690f60u, 0x0068f7f2u)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00690f60(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x0068f7f2u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f7f2: 8b462c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t17;
    // 0x0068f7f5: 895e2c MOV
        t18 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7f8: 8b4e28 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x0068f7fb: 895e28 MOV
        t20 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x0068f7fe: 8b6c2430 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t21;
    // 0x0068f802: 89442414 MOV
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0068f806: 8b4610 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x0068f809: 895e10 MOV
        t24 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x0068f80c: 8944241c MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t25)) return BatchLiftStatus::invalid_memory;
    // 0x0068f810: 89442410 MOV
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0068f814: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x0068f817: 894c2418 MOV
        t28 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x0068f81b: 8b0e MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t29;
    // 0x0068f81d: 8908 MOV
        t30 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0068f81f: 894104 MOV
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0068f822: 895e04 MOV
        t32 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0068f825: 891e MOV
        t33 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0068f827: 8b5750 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000050u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x0068f82a: 8d474c LEA
        t35 = static_cast<std::uint32_t>(state.regs[7] + 0x0000004cu);
        state.regs[0] = t35;
    // 0x0068f82d: 895604 MOV
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x0068f830: 8906 MOV
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0068f832: 897004 MOV
        t38 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0068f835: 8b4604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x0068f838: 8930 MOV
        t40 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x0068f83a: 895e1c MOV
        t41 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0068f83d: 8b7738 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t42;
    // 0x0068f840: 895f38 MOV
        t43 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x0068f843: 3beb CMP
        t44a = state.regs[5];
        t44b = state.regs[3];
        t44r = static_cast<std::uint32_t>(t44a - t44b) & 0xffffffffu;
        batch_set_sub_flags(state, t44a, t44b, t44r, 32u);
    // 0x0068f845: 741d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f864;
    // 0x0068f847: 3bf3 CMP
        t46a = state.regs[6];
        t46b = state.regs[3];
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
    // 0x0068f849: 7e14 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0068f85f;
    // 0x0068f84b: 89742434 MOV
        t48 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x0068f84f: 90 NOP
    // 0x0068f850: 8b4d00 MOV
    L_0068f850:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x0068f853: e8182a2900 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0068f858u)) return BatchLiftStatus::invalid_memory;
        t51_call_status = spore_lift_00922270(memory, state);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x0068f858u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f858: 836c243401 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t52a)) return BatchLiftStatus::invalid_memory;
        t52b = 0x00000001u;
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t52r)) return BatchLiftStatus::invalid_memory;
    // 0x0068f85d: 75f1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f850;
    // 0x0068f85f: 8b4d00 MOV
    L_0068f85f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t54;
    // 0x0068f862: eb1e JMP
        goto L_0068f882;
    // 0x0068f864: 3bf3 CMP
    L_0068f864:
        t56a = state.regs[6];
        t56b = state.regs[3];
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
    // 0x0068f866: 7e17 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0068f87f;
    // 0x0068f868: 89742434 MOV
        t58 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x0068f86c: 8d642400 LEA
        t59 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t59;
    // 0x0068f870: 8d4f08 LEA
    L_0068f870:
        t60 = static_cast<std::uint32_t>(state.regs[7] + 0x00000008u);
        state.regs[1] = t60;
    // 0x0068f873: e8f8292900 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0068f878u)) return BatchLiftStatus::invalid_memory;
        t61_call_status = spore_lift_00922270(memory, state);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
        if (state.eip != 0x0068f878u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f878: 836c243401 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t62a)) return BatchLiftStatus::invalid_memory;
        t62b = 0x00000001u;
        t62r = static_cast<std::uint32_t>(t62a - t62b) & 0xffffffffu;
        batch_set_sub_flags(state, t62a, t62b, t62r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t62r)) return BatchLiftStatus::invalid_memory;
    // 0x0068f87d: 75f1 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f870;
    // 0x0068f87f: 8d4f08 LEA
    L_0068f87f:
        t64 = static_cast<std::uint32_t>(state.regs[7] + 0x00000008u);
        state.regs[1] = t64;
    // 0x0068f882: e8e9292900 CALL
    L_0068f882:
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x0068f887u)) return BatchLiftStatus::invalid_memory;
        t65_call_status = spore_lift_00922270(memory, state);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x0068f887u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f887: 8b442414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t66;
    // 0x0068f88b: 3bc3 CMP
        t67a = state.regs[0];
        t67b = state.regs[3];
        t67r = static_cast<std::uint32_t>(t67a - t67b) & 0xffffffffu;
        batch_set_sub_flags(state, t67a, t67b, t67r, 32u);
    // 0x0068f88d: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f899;
    // 0x0068f88f: 8b4c2418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t69;
    // 0x0068f893: 51 PUSH
        t70a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t70a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f894: ffd0 CALL
        t71_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0068f896u);
        if (t71_call_status != BatchLiftStatus::returned) return t71_call_status;
    // 0x0068f896: 83c404 ADD
        t72a = state.regs[4];
        t72b = 0x00000004u;
        t72r = static_cast<std::uint32_t>(t72a + t72b) & 0xffffffffu;
        batch_set_add_flags(state, t72a, t72b, t72r, 32u);
        state.regs[4] = t72r;
    // 0x0068f899: 8b4c241c MOV
    L_0068f899:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t73;
    // 0x0068f89d: 3bcb CMP
        t74a = state.regs[1];
        t74b = state.regs[3];
        t74r = static_cast<std::uint32_t>(t74a - t74b) & 0xffffffffu;
        batch_set_sub_flags(state, t74a, t74b, t74r, 32u);
    // 0x0068f89f: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f8ac;
    // 0x0068f8a1: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t76;
    // 0x0068f8a3: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t77;
    // 0x0068f8a6: 895c2410 MOV
        t78 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8aa: ffd0 CALL
        t79_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0068f8acu);
        if (t79_call_status != BatchLiftStatus::returned) return t79_call_status;
    // 0x0068f8ac: 6850374001 PUSH
    L_0068f8ac:
        t80a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8b1: 3beb CMP
        t81a = state.regs[5];
        t81b = state.regs[3];
        t81r = static_cast<std::uint32_t>(t81a - t81b) & 0xffffffffu;
        batch_set_sub_flags(state, t81a, t81b, t81r, 32u);
    // 0x0068f8b3: 7431 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f8e6;
    // 0x0068f8b5: 8b4d00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x0068f8b8: e8f3282900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0068f8bdu)) return BatchLiftStatus::invalid_memory;
        t84_call_status = spore_lift_009221b0(memory, state);
        if (t84_call_status != BatchLiftStatus::returned) return t84_call_status;
        if (state.eip != 0x0068f8bdu) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f8bd: 3bf3 CMP
        t85a = state.regs[6];
        t85b = state.regs[3];
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
    // 0x0068f8bf: 7e52 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0068f913;
    // 0x0068f8c1: 89742434 MOV
        t87 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t87)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8c5: eb09 JMP
        goto L_0068f8d0;
    // 0x0068f8d0: 8b4d00 MOV
    L_0068f8d0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t89;
    // 0x0068f8d3: 6850374001 PUSH
        t90a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8d8: e8d3282900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0068f8ddu)) return BatchLiftStatus::invalid_memory;
        t91_call_status = spore_lift_009221b0(memory, state);
        if (t91_call_status != BatchLiftStatus::returned) return t91_call_status;
        if (state.eip != 0x0068f8ddu) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f8dd: 836c243401 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t92a)) return BatchLiftStatus::invalid_memory;
        t92b = 0x00000001u;
        t92r = static_cast<std::uint32_t>(t92a - t92b) & 0xffffffffu;
        batch_set_sub_flags(state, t92a, t92b, t92r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t92r)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8e2: 75ec JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f8d0;
    // 0x0068f8e4: eb2d JMP
        goto L_0068f913;
    // 0x0068f8e6: 8d6f08 LEA
    L_0068f8e6:
        t95 = static_cast<std::uint32_t>(state.regs[7] + 0x00000008u);
        state.regs[5] = t95;
    // 0x0068f8e9: 8bcd MOV
        t96 = state.regs[5];
        state.regs[1] = t96;
    // 0x0068f8eb: e8c0282900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0068f8f0u)) return BatchLiftStatus::invalid_memory;
        t97_call_status = spore_lift_009221b0(memory, state);
        if (t97_call_status != BatchLiftStatus::returned) return t97_call_status;
        if (state.eip != 0x0068f8f0u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f8f0: 3bf3 CMP
        t98a = state.regs[6];
        t98b = state.regs[3];
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
    // 0x0068f8f2: 7e1f JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0068f913;
    // 0x0068f8f4: 89742434 MOV
        t100 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t100)) return BatchLiftStatus::invalid_memory;
    // 0x0068f8f8: eb06 JMP
        goto L_0068f900;
    // 0x0068f900: 6850374001 PUSH
    L_0068f900:
        t102a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f905: 8bcd MOV
        t103 = state.regs[5];
        state.regs[1] = t103;
    // 0x0068f907: e8a4282900 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0068f90cu)) return BatchLiftStatus::invalid_memory;
        t104_call_status = spore_lift_009221b0(memory, state);
        if (t104_call_status != BatchLiftStatus::returned) return t104_call_status;
        if (state.eip != 0x0068f90cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f90c: 836c243401 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t105a)) return BatchLiftStatus::invalid_memory;
        t105b = 0x00000001u;
        t105r = static_cast<std::uint32_t>(t105a - t105b) & 0xffffffffu;
        batch_set_sub_flags(state, t105a, t105b, t105r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t105r)) return BatchLiftStatus::invalid_memory;
    // 0x0068f911: 75ed JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f900;
    // 0x0068f913: 8b4c2410 MOV
    L_0068f913:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t107;
    // 0x0068f917: 897738 MOV
        t108 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000038u), t108)) return BatchLiftStatus::invalid_memory;
    // 0x0068f91a: 5f POP
        if (!memory.load32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t109a;
    // 0x0068f91b: 5e POP
        if (!memory.load32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t110a;
    // 0x0068f91c: 5d POP
        if (!memory.load32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t111a;
    // 0x0068f91d: 3bcb CMP
        t112a = state.regs[1];
        t112b = state.regs[3];
        t112r = static_cast<std::uint32_t>(t112a - t112b) & 0xffffffffu;
        batch_set_sub_flags(state, t112a, t112b, t112r, 32u);
    // 0x0068f91f: c744241cffffffff MOV
        t113 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t113)) return BatchLiftStatus::invalid_memory;
    // 0x0068f927: 5b POP
        if (!memory.load32(state.regs[4], t114a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t114a;
    // 0x0068f928: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f931;
    // 0x0068f92a: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t116;
    // 0x0068f92c: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t117)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t117;
    // 0x0068f92f: ffd0 CALL
        t118_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0068f931u);
        if (t118_call_status != BatchLiftStatus::returned) return t118_call_status;
    // 0x0068f931: 8b4c2410 MOV
    L_0068f931:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t119;
    // 0x0068f935: 64890d00000000 MOV
        t120 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t120)) return BatchLiftStatus::invalid_memory;
    // 0x0068f93c: 83c41c ADD
        t121a = state.regs[4];
        t121b = 0x0000001cu;
        t121r = static_cast<std::uint32_t>(t121a + t121b) & 0xffffffffu;
        batch_set_add_flags(state, t121a, t121b, t121r, 32u);
        state.regs[4] = t121r;
    // 0x0068f93f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
