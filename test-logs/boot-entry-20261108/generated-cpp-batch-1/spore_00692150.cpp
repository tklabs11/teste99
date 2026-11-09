#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0068f700(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068ffb0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006908a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690930(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00691500(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006915c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00691f60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006921c4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00692213(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_006922d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921cc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921d70(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922690(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00692150(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00692150u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0;
    std::uint32_t t20 = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    BatchLiftStatus t57_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65 = 0;
    BatchLiftStatus t66_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    BatchLiftStatus t95_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t96a = 0, t96b = 0, t96r = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109a = 0;
    std::uint32_t t110 = 0;
    BatchLiftStatus t111_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t112 = 0;
    std::uint32_t t113a = 0;
    BatchLiftStatus t114_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t115a = 0, t115b = 0, t115r = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0;
    BatchLiftStatus t121_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t129a = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    BatchLiftStatus t139_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t140a = 0;
    std::uint32_t t141a = 0;
    std::uint32_t t142a = 0;
    std::uint32_t t143a = 0;

    // 0x00692150: 51 PUSH
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00692151: 53 PUSH
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00692152: 8b5c2410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t2;
    // 0x00692156: 8b431c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000001cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00692159: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0069215a: 8be9 MOV
        t5 = state.regs[1];
        state.regs[5] = t5;
    // 0x0069215c: 83f808 CMP
        t6a = state.regs[0];
        t6b = 0x00000008u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x0069215f: 0f84b7010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069231c;
    // 0x00692165: 83f807 CMP
        t8a = state.regs[0];
        t8b = 0x00000007u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00692168: 0f84ae010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069231c;
    // 0x0069216e: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x00692170: 0f84a6010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069231c;
    // 0x00692176: 83f801 CMP
        t12a = state.regs[0];
        t12b = 0x00000001u;
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00692179: 0f849d010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069231c;
    // 0x0069217f: 56 PUSH
        t14a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00692180: e83bfb2800 CALL
        if (!batch_guest_call32(memory, state, 0x00921cc0u, 0x00692185u)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_00921cc0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x00692185u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692185: 8bf0 MOV
        t16 = state.regs[0];
        state.regs[6] = t16;
    // 0x00692187: c744240c00000000 MOV
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0069218f: e8dcfb2800 CALL
        if (!batch_guest_call32(memory, state, 0x00921d70u, 0x00692194u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00921d70(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00692194u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692194: 50 PUSH
        t19a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00692195: 8bcd MOV
        t20 = state.regs[5];
        state.regs[1] = t20;
    // 0x00692197: e864f3ffff CALL
        if (!batch_guest_call32(memory, state, 0x00691500u, 0x0069219cu)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_00691500(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x0069219cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069219c: 8b8598010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000198u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x006921a2: 8d8d98010000 LEA
        t23 = static_cast<std::uint32_t>(state.regs[5] + 0x00000198u);
        state.regs[1] = t23;
    // 0x006921a8: 3bc1 CMP
        t24a = state.regs[0];
        t24b = state.regs[1];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x006921aa: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006921bb;
    // 0x006921ac: 8d642400 LEA
        t26 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t26;
    // 0x006921b0: 397024 CMP
    L_006921b0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000024u), t27a)) return BatchLiftStatus::invalid_memory;
        t27b = state.regs[6];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x006921b3: 744a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006921ff;
    // 0x006921b5: 8b00 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x006921b7: 3bc1 CMP
        t30a = state.regs[0];
        t30b = state.regs[1];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x006921b9: 75f5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006921b0;
    // 0x006921bb: 8bcd MOV
    L_006921bb:
        t32 = state.regs[5];
        state.regs[1] = t32;
    // 0x006921bd: e83ed5ffff CALL
        if (!batch_guest_call32(memory, state, 0x0068f700u, 0x006921c2u)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_0068f700(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x006921c2u) return BatchLiftStatus::invalid_control_flow;
    // 0x006921c2: 8bf0 MOV
        t34 = state.regs[0];
        state.regs[6] = t34;
    // 0x006921c4: 8b4c240c MOV
    L_006921c4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x006921c8: 57 PUSH
        t36a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x006921c9: 8b7b48 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000048u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t37;
    // 0x006921cc: 33c0 XOR
        t38a = state.regs[0];
        t38b = state.regs[0];
        t38r = (t38a ^ t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
        state.regs[0] = t38r;
    // 0x006921ce: 85ff TEST
        t39a = state.regs[7];
        t39b = state.regs[7];
        t39r = (t39a & t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
    // 0x006921d0: 0f4fc7 CMOVG
        t40a = state.regs[7];
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) state.regs[0] = t40a;
    // 0x006921d3: 85c9 TEST
        t41a = state.regs[1];
        t41b = state.regs[1];
        t41r = (t41a & t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
    // 0x006921d5: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006921e0;
    // 0x006921d7: 8b4930 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000030u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x006921da: 3bc8 CMP
        t44a = state.regs[1];
        t44b = state.regs[0];
        t44r = static_cast<std::uint32_t>(t44a - t44b) & 0xffffffffu;
        batch_set_sub_flags(state, t44a, t44b, t44r, 32u);
    // 0x006921dc: 7e02 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_006921e0;
    // 0x006921de: 8bc1 MOV
        t46 = state.regs[1];
        state.regs[0] = t46;
    // 0x006921e0: 0500000100 ADD
    L_006921e0:
        t47a = state.regs[0];
        t47b = 0x00010000u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[0] = t47r;
    // 0x006921e5: 53 PUSH
        t48a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x006921e6: 8bcd MOV
        t49 = state.regs[5];
        state.regs[1] = t49;
    // 0x006921e8: 894318 MOV
        t50 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x006921eb: e8c0ddffff CALL
        if (!batch_guest_call32(memory, state, 0x0068ffb0u, 0x006921f0u)) return BatchLiftStatus::invalid_memory;
        t51_call_status = spore_lift_0068ffb0(memory, state);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x006921f0u) return BatchLiftStatus::invalid_control_flow;
    // 0x006921f0: 3bf8 CMP
        t52a = state.regs[7];
        t52b = state.regs[0];
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
    // 0x006921f2: 7d14 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00692208;
    // 0x006921f4: 50 PUSH
        t54a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x006921f5: 53 PUSH
        t55a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x006921f6: 8bcd MOV
        t56 = state.regs[5];
        state.regs[1] = t56;
    // 0x006921f8: e8a3e6ffff CALL
        if (!batch_guest_call32(memory, state, 0x006908a0u, 0x006921fdu)) return BatchLiftStatus::invalid_memory;
        t57_call_status = spore_lift_006908a0(memory, state);
        if (t57_call_status != BatchLiftStatus::returned) return t57_call_status;
        if (state.eip != 0x006921fdu) return BatchLiftStatus::invalid_control_flow;
    // 0x006921fd: eb14 JMP
        goto L_00692213;
    // 0x006921ff: 8944240c MOV
    L_006921ff:
        t59 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00692203: 8d7008 LEA
        t60 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[6] = t60;
    // 0x00692206: ebbc JMP
        goto L_006921c4;
    // 0x00692208: 7e09 JLE
    L_00692208:
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00692213;
    // 0x0069220a: 50 PUSH
        t63a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x0069220b: 53 PUSH
        t64a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
    // 0x0069220c: 8bcd MOV
        t65 = state.regs[5];
        state.regs[1] = t65;
    // 0x0069220e: e81de7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00690930u, 0x00692213u)) return BatchLiftStatus::invalid_memory;
        t66_call_status = spore_lift_00690930(memory, state);
        if (t66_call_status != BatchLiftStatus::returned) return t66_call_status;
        if (state.eip != 0x00692213u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692213: 837b1c08 CMP
    L_00692213:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000001cu), t67a)) return BatchLiftStatus::invalid_memory;
        t67b = 0x00000008u;
        t67r = static_cast<std::uint32_t>(t67a - t67b) & 0xffffffffu;
        batch_set_sub_flags(state, t67a, t67b, t67r, 32u);
    // 0x00692217: 0f84d7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006922f4;
    // 0x0069221d: 8b7c2418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t69;
    // 0x00692221: 8b431c MOV
    L_00692221:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000001cu), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x00692224: 83f807 CMP
        t71a = state.regs[0];
        t71b = 0x00000007u;
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
    // 0x00692227: 0f84c7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006922f4;
    // 0x0069222d: 85c0 TEST
        t73a = state.regs[0];
        t73b = state.regs[0];
        t73r = (t73a & t73b) & 0xffffffffu;
        batch_set_logic_flags(state, t73r, 32u);
    // 0x0069222f: 0f84bf000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006922f4;
    // 0x00692235: 83f801 CMP
        t75a = state.regs[0];
        t75b = 0x00000001u;
        t75r = static_cast<std::uint32_t>(t75a - t75b) & 0xffffffffu;
        batch_set_sub_flags(state, t75a, t75b, t75r, 32u);
    // 0x00692238: 0f84b6000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_006922f4;
    // 0x0069223e: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t77;
    // 0x00692242: c6433401 MOV
        t78 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[3] + 0x00000034u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00692246: 85c0 TEST
        t79a = state.regs[0];
        t79b = state.regs[0];
        t79r = (t79a & t79b) & 0xffffffffu;
        batch_set_logic_flags(state, t79r, 32u);
    // 0x00692248: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0069225f;
    // 0x0069224a: 6a01 PUSH
        t81a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x0069224c: 6a00 PUSH
        t82a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x0069224e: 50 PUSH
        t83a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x0069224f: 57 PUSH
        t84a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x00692250: 8bcd MOV
        t85 = state.regs[5];
        state.regs[1] = t85;
    // 0x00692252: e809fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00691f60u, 0x00692257u)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_00691f60(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x00692257u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692257: 84c0 TEST
        t87a = state.regs[0] & 0x000000ffu;
        t87b = state.regs[0] & 0x000000ffu;
        t87r = (t87a & t87b) & 0x000000ffu;
        batch_set_logic_flags(state, t87r, 8u);
    // 0x00692259: 0f858b000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006922ea;
    // 0x0069225f: 8b5d38 MOV
    L_0069225f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000038u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t89;
    // 0x00692262: c7453800000000 MOV
        t90 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000038u), t90)) return BatchLiftStatus::invalid_memory;
    // 0x00692269: 85db TEST
        t91a = state.regs[3];
        t91b = state.regs[3];
        t91r = (t91a & t91b) & 0xffffffffu;
        batch_set_logic_flags(state, t91r, 32u);
    // 0x0069226b: 7e12 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_0069227f;
    // 0x0069226d: 895c2418 MOV
        t93 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x00692271: 8b0f MOV
    L_00692271:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t94;
    // 0x00692273: e8f8ff2800 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00692278u)) return BatchLiftStatus::invalid_memory;
        t95_call_status = spore_lift_00922270(memory, state);
        if (t95_call_status != BatchLiftStatus::returned) return t95_call_status;
        if (state.eip != 0x00692278u) return BatchLiftStatus::invalid_control_flow;
    // 0x00692278: 836c241801 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t96a)) return BatchLiftStatus::invalid_memory;
        t96b = 0x00000001u;
        t96r = static_cast<std::uint32_t>(t96a - t96b) & 0xffffffffu;
        batch_set_sub_flags(state, t96a, t96b, t96r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t96r)) return BatchLiftStatus::invalid_memory;
    // 0x0069227d: 75f2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00692271;
    // 0x0069227f: c7460400000000 MOV
    L_0069227f:
        t98 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00692286: c70600000000 MOV
        t99 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t99)) return BatchLiftStatus::invalid_memory;
    // 0x0069228c: 8b4d48 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000048u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t100;
    // 0x0069228f: 8d4544 LEA
        t101 = static_cast<std::uint32_t>(state.regs[5] + 0x00000044u);
        state.regs[0] = t101;
    // 0x00692292: 894e04 MOV
        t102 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t102)) return BatchLiftStatus::invalid_memory;
    // 0x00692295: 8906 MOV
        t103 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t103)) return BatchLiftStatus::invalid_memory;
    // 0x00692297: 897004 MOV
        t104 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t104)) return BatchLiftStatus::invalid_memory;
    // 0x0069229a: 8b5604 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t105;
    // 0x0069229d: 8932 MOV
        t106 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t106)) return BatchLiftStatus::invalid_memory;
    // 0x0069229f: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t107;
    // 0x006922a1: e8caff2800 CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x006922a6u)) return BatchLiftStatus::invalid_memory;
        t108_call_status = spore_lift_00922270(memory, state);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
        if (state.eip != 0x006922a6u) return BatchLiftStatus::invalid_control_flow;
    // 0x006922a6: 6850374001 PUSH
        t109a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
    // 0x006922ab: 8d4e08 LEA
        t110 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t110;
    // 0x006922ae: e8dd032900 CALL
        if (!batch_guest_call32(memory, state, 0x00922690u, 0x006922b3u)) return BatchLiftStatus::invalid_memory;
        t111_call_status = spore_lift_00922690(memory, state);
        if (t111_call_status != BatchLiftStatus::returned) return t111_call_status;
        if (state.eip != 0x006922b3u) return BatchLiftStatus::invalid_control_flow;
    // 0x006922b3: 8b0f MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t112)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t112;
    // 0x006922b5: 6850374001 PUSH
        t113a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t113a)) return BatchLiftStatus::invalid_memory;
    // 0x006922ba: e8f1fe2800 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x006922bfu)) return BatchLiftStatus::invalid_memory;
        t114_call_status = spore_lift_009221b0(memory, state);
        if (t114_call_status != BatchLiftStatus::returned) return t114_call_status;
        if (state.eip != 0x006922bfu) return BatchLiftStatus::invalid_control_flow;
    // 0x006922bf: 85db TEST
        t115a = state.regs[3];
        t115b = state.regs[3];
        t115r = (t115a & t115b) & 0xffffffffu;
        batch_set_logic_flags(state, t115r, 32u);
    // 0x006922c1: 7e20 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_006922e3;
    // 0x006922c3: 895c2418 MOV
        t117 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t117)) return BatchLiftStatus::invalid_memory;
    // 0x006922c7: eb07 JMP
        goto L_006922d0;
    // 0x006922d0: 8b0f MOV
    L_006922d0:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t119;
    // 0x006922d2: 6850374001 PUSH
        t120a = 0x01403750u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t120a)) return BatchLiftStatus::invalid_memory;
    // 0x006922d7: e8d4fe2800 CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x006922dcu)) return BatchLiftStatus::invalid_memory;
        t121_call_status = spore_lift_009221b0(memory, state);
        if (t121_call_status != BatchLiftStatus::returned) return t121_call_status;
        if (state.eip != 0x006922dcu) return BatchLiftStatus::invalid_control_flow;
    // 0x006922dc: 836c241801 SUB
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t122a)) return BatchLiftStatus::invalid_memory;
        t122b = 0x00000001u;
        t122r = static_cast<std::uint32_t>(t122a - t122b) & 0xffffffffu;
        batch_set_sub_flags(state, t122a, t122b, t122r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t122r)) return BatchLiftStatus::invalid_memory;
    // 0x006922e1: 75ed JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_006922d0;
    // 0x006922e3: 895d38 MOV
    L_006922e3:
        t124 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000038u), t124)) return BatchLiftStatus::invalid_memory;
    // 0x006922e6: 8b5c241c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t125;
    // 0x006922ea: 837b1c08 CMP
    L_006922ea:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000001cu), t126a)) return BatchLiftStatus::invalid_memory;
        t126b = 0x00000008u;
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
    // 0x006922ee: 0f852dffffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00692221;
    // 0x006922f4: 837c241000 CMP
    L_006922f4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t128a)) return BatchLiftStatus::invalid_memory;
        t128b = 0x00000000u;
        t128r = static_cast<std::uint32_t>(t128a - t128b) & 0xffffffffu;
        batch_set_sub_flags(state, t128a, t128b, t128r, 32u);
    // 0x006922f9: 5f POP
        if (!memory.load32(state.regs[4], t129a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t129a;
    // 0x006922fa: 7518 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00692314;
    // 0x006922fc: 8b8dd8010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000001d8u), t131)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t131;
    // 0x00692302: 8d85d8010000 LEA
        t132 = static_cast<std::uint32_t>(state.regs[5] + 0x000001d8u);
        state.regs[0] = t132;
    // 0x00692308: 890e MOV
        t133 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x0069230a: 894604 MOV
        t134 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x0069230d: 8930 MOV
        t135 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t135)) return BatchLiftStatus::invalid_memory;
    // 0x0069230f: 8b16 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t136;
    // 0x00692311: 897204 MOV
        t137 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x00692314: 8bcd MOV
    L_00692314:
        t138 = state.regs[5];
        state.regs[1] = t138;
    // 0x00692316: e8a5f2ffff CALL
        if (!batch_guest_call32(memory, state, 0x006915c0u, 0x0069231bu)) return BatchLiftStatus::invalid_memory;
        t139_call_status = spore_lift_006915c0(memory, state);
        if (t139_call_status != BatchLiftStatus::returned) return t139_call_status;
        if (state.eip != 0x0069231bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069231b: 5e POP
        if (!memory.load32(state.regs[4], t140a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t140a;
    // 0x0069231c: 5d POP
    L_0069231c:
        if (!memory.load32(state.regs[4], t141a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t141a;
    // 0x0069231d: 5b POP
        if (!memory.load32(state.regs[4], t142a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t142a;
    // 0x0069231e: 59 POP
        if (!memory.load32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t143a;
    // 0x0069231f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
