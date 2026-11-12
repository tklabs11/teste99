#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009216dd(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009216df(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092175e(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921804(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921847(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092184a(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921850(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009216a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009216a0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t100a = 0, t100b = 0, t100r = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0, t117b = 0, t117r = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127a = 0, t127b = 0, t127r = 0;
    std::uint32_t t129 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143a = 0, t143b = 0, t143r = 0;
    std::uint32_t t145 = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148a = 0, t148b = 0, t148r = 0;
    std::uint32_t t150 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0, t161b = 0, t161r = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164a = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166a = 0;
    std::uint32_t t167 = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t170 = 0;
    std::uint32_t t171a = 0;
    std::uint32_t t172 = 0;
    std::uint32_t t173a = 0;
    std::uint32_t t175 = 0;
    std::uint32_t t176a = 0;
    std::uint32_t t177a = 0;
    std::uint32_t t178a = 0;
    std::uint32_t t179 = 0;
    std::uint32_t t180a = 0;

    // 0x009216a0: 8b442404 MOV
        batch_guest_pc = 0x009216a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009216a4: 8b4c2408 MOV
        batch_guest_pc = 0x009216a4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x009216a8: 53 PUSH
        batch_guest_pc = 0x009216a8u;
        t2a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009216a9: 33db XOR
        t3a = state.regs[3];
        t3b = state.regs[3];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[3] = t3r;
    // 0x009216ab: 56 PUSH
        batch_guest_pc = 0x009216abu;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009216ac: 8b742414 MOV
        batch_guest_pc = 0x009216acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t5;
    // 0x009216b0: 894808 MOV
        batch_guest_pc = 0x009216b0u;
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x009216b3: 8918 MOV
        batch_guest_pc = 0x009216b3u;
        t7 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x009216b5: 895804 MOV
        batch_guest_pc = 0x009216b5u;
        t8 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x009216b8: 88580c MOV
        batch_guest_pc = 0x009216b8u;
        t9 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x009216bb: 395c2418 CMP
        batch_guest_pc = 0x009216bbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = state.regs[3];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x009216bf: 7516 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009216d7;
    // 0x009216c1: 894104 MOV
        batch_guest_pc = 0x009216c1u;
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x009216c4: 3bce CMP
        t13a = state.regs[1];
        t13b = state.regs[6];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x009216c6: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009216cd;
    // 0x009216c8: 894608 MOV
        batch_guest_pc = 0x009216c8u;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x009216cb: eb10 JMP
        goto L_009216dd;
    // 0x009216cd: 3b4e04 CMP
    L_009216cd:
        batch_guest_pc = 0x009216cdu;
        t17a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t17b)) return BatchLiftStatus::invalid_memory;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x009216d0: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009216df;
    // 0x009216d2: 894604 MOV
        batch_guest_pc = 0x009216d2u;
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x009216d5: eb08 JMP
        goto L_009216df;
    // 0x009216d7: 8901 MOV
    L_009216d7:
        batch_guest_pc = 0x009216d7u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009216d9: 3b0e CMP
        batch_guest_pc = 0x009216d9u;
        t22a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
    // 0x009216db: 7502 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009216df;
    // 0x009216dd: 8906 MOV
    L_009216dd:
        batch_guest_pc = 0x009216ddu;
        t24 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x009216df: 3b4608 CMP
    L_009216df:
        batch_guest_pc = 0x009216dfu;
        t25a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t25b)) return BatchLiftStatus::invalid_memory;
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x009216e2: 0f847d010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921865;
    // 0x009216e8: 55 PUSH
        batch_guest_pc = 0x009216e8u;
        t27a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x009216e9: 57 PUSH
        batch_guest_pc = 0x009216e9u;
        t28a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x009216ea: 8d9b00000000 LEA
        t29 = static_cast<std::uint32_t>(state.regs[3] + 0x00000000u);
        state.regs[3] = t29;
    // 0x009216f0: 8b5008 MOV
    L_009216f0:
        batch_guest_pc = 0x009216f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x009216f3: 385a0c CMP
        batch_guest_pc = 0x009216f3u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t31a)) return BatchLiftStatus::invalid_memory;
        t31b = state.regs[3] & 0x000000ffu;
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0x000000ffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 8u);
    // 0x009216f6: 0f8573010000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092186f;
    // 0x009216fc: 8b4a08 MOV
        batch_guest_pc = 0x009216fcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x009216ff: 8b7904 MOV
        batch_guest_pc = 0x009216ffu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t34;
    // 0x00921702: 3bd7 CMP
        t35a = state.regs[2];
        t35b = state.regs[7];
        t35r = static_cast<std::uint32_t>(t35a - t35b) & 0xffffffffu;
        batch_set_sub_flags(state, t35a, t35b, t35r, 32u);
    // 0x00921704: 0f85a8000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009217b2;
    // 0x0092170a: 8b39 MOV
        batch_guest_pc = 0x0092170au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t37;
    // 0x0092170c: 3bfb CMP
        t38a = state.regs[7];
        t38b = state.regs[3];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x0092170e: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921727;
    // 0x00921710: 385f0c CMP
        batch_guest_pc = 0x00921710u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t40a)) return BatchLiftStatus::invalid_memory;
        t40b = state.regs[3] & 0x000000ffu;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0x000000ffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 8u);
    // 0x00921713: 7512 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921727;
    // 0x00921715: c6420c01 MOV
        batch_guest_pc = 0x00921715u;
        t42 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00921719: c6470c01 MOV
        batch_guest_pc = 0x00921719u;
        t43 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t43)) return BatchLiftStatus::invalid_memory;
    // 0x0092171d: 88590c MOV
        batch_guest_pc = 0x0092171du;
        t44 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00921720: 8bc1 MOV
        t45 = state.regs[1];
        state.regs[0] = t45;
    // 0x00921722: e929010000 JMP
        goto L_00921850;
    // 0x00921727: 3b02 CMP
    L_00921727:
        batch_guest_pc = 0x00921727u;
        t47a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t47b)) return BatchLiftStatus::invalid_memory;
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
    // 0x00921729: 753c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921767;
    // 0x0092172b: 8b6e08 MOV
        batch_guest_pc = 0x0092172bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t49;
    // 0x0092172e: 8bc2 MOV
        t50 = state.regs[2];
        state.regs[0] = t50;
    // 0x00921730: 8b10 MOV
        batch_guest_pc = 0x00921730u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00921732: 8b7a04 MOV
        batch_guest_pc = 0x00921732u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t52;
    // 0x00921735: 8938 MOV
        batch_guest_pc = 0x00921735u;
        t53 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00921737: 8b7a04 MOV
        batch_guest_pc = 0x00921737u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t54;
    // 0x0092173a: 3bfb CMP
        t55a = state.regs[7];
        t55b = state.regs[3];
        t55r = static_cast<std::uint32_t>(t55a - t55b) & 0xffffffffu;
        batch_set_sub_flags(state, t55a, t55b, t55r, 32u);
    // 0x0092173c: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921741;
    // 0x0092173e: 894708 MOV
        batch_guest_pc = 0x0092173eu;
        t57 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00921741: 8b7808 MOV
    L_00921741:
        batch_guest_pc = 0x00921741u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t58;
    // 0x00921744: 897a08 MOV
        batch_guest_pc = 0x00921744u;
        t59 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00921747: 3bc5 CMP
        t60a = state.regs[0];
        t60b = state.regs[5];
        t60r = static_cast<std::uint32_t>(t60a - t60b) & 0xffffffffu;
        batch_set_sub_flags(state, t60a, t60b, t60r, 32u);
    // 0x00921749: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092174f;
    // 0x0092174b: 8bea MOV
        t62 = state.regs[2];
        state.regs[5] = t62;
    // 0x0092174d: eb0f JMP
        goto L_0092175e;
    // 0x0092174f: 8b7808 MOV
    L_0092174f:
        batch_guest_pc = 0x0092174fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t64;
    // 0x00921752: 3b4704 CMP
        batch_guest_pc = 0x00921752u;
        t65a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t65b)) return BatchLiftStatus::invalid_memory;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
    // 0x00921755: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092175c;
    // 0x00921757: 895704 MOV
        batch_guest_pc = 0x00921757u;
        t67 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t67)) return BatchLiftStatus::invalid_memory;
    // 0x0092175a: eb02 JMP
        goto L_0092175e;
    // 0x0092175c: 8917 MOV
    L_0092175c:
        batch_guest_pc = 0x0092175cu;
        t69 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x0092175e: 894204 MOV
    L_0092175e:
        batch_guest_pc = 0x0092175eu;
        t70 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00921761: 895008 MOV
        batch_guest_pc = 0x00921761u;
        t71 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t71)) return BatchLiftStatus::invalid_memory;
    // 0x00921764: 896e08 MOV
        batch_guest_pc = 0x00921764u;
        t72 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t72)) return BatchLiftStatus::invalid_memory;
    // 0x00921767: 8b5008 MOV
    L_00921767:
        batch_guest_pc = 0x00921767u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t73;
    // 0x0092176a: c6420c01 MOV
        batch_guest_pc = 0x0092176au;
        t74 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t74)) return BatchLiftStatus::invalid_memory;
    // 0x0092176e: 8b5104 MOV
        batch_guest_pc = 0x0092176eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t75;
    // 0x00921771: 88590c MOV
        batch_guest_pc = 0x00921771u;
        t76 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t76)) return BatchLiftStatus::invalid_memory;
    // 0x00921774: 8b3a MOV
        batch_guest_pc = 0x00921774u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t77;
    // 0x00921776: 8b6e08 MOV
        batch_guest_pc = 0x00921776u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t78;
    // 0x00921779: 897904 MOV
        batch_guest_pc = 0x00921779u;
        t79 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x0092177c: 8b3a MOV
        batch_guest_pc = 0x0092177cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t80;
    // 0x0092177e: 3bfb CMP
        t81a = state.regs[7];
        t81b = state.regs[3];
        t81r = static_cast<std::uint32_t>(t81a - t81b) & 0xffffffffu;
        batch_set_sub_flags(state, t81a, t81b, t81r, 32u);
    // 0x00921780: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921785;
    // 0x00921782: 894f08 MOV
        batch_guest_pc = 0x00921782u;
        t83 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00921785: 8b7908 MOV
    L_00921785:
        batch_guest_pc = 0x00921785u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t84;
    // 0x00921788: 897a08 MOV
        batch_guest_pc = 0x00921788u;
        t85 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x0092178b: 3bcd CMP
        t86a = state.regs[1];
        t86b = state.regs[5];
        t86r = static_cast<std::uint32_t>(t86a - t86b) & 0xffffffffu;
        batch_set_sub_flags(state, t86a, t86b, t86r, 32u);
    // 0x0092178d: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921798;
    // 0x0092178f: 8bea MOV
        t88 = state.regs[2];
        state.regs[5] = t88;
    // 0x00921791: 890a MOV
        batch_guest_pc = 0x00921791u;
        t89 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x00921793: e9b2000000 JMP
        goto L_0092184a;
    // 0x00921798: 8b7908 MOV
    L_00921798:
        batch_guest_pc = 0x00921798u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t91;
    // 0x0092179b: 3b0f CMP
        batch_guest_pc = 0x0092179bu;
        t92a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t92b)) return BatchLiftStatus::invalid_memory;
        t92r = static_cast<std::uint32_t>(t92a - t92b) & 0xffffffffu;
        batch_set_sub_flags(state, t92a, t92b, t92r, 32u);
    // 0x0092179d: 7509 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009217a8;
    // 0x0092179f: 8917 MOV
        batch_guest_pc = 0x0092179fu;
        t94 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t94)) return BatchLiftStatus::invalid_memory;
    // 0x009217a1: 890a MOV
        batch_guest_pc = 0x009217a1u;
        t95 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t95)) return BatchLiftStatus::invalid_memory;
    // 0x009217a3: e9a2000000 JMP
        goto L_0092184a;
    // 0x009217a8: 895704 MOV
    L_009217a8:
        batch_guest_pc = 0x009217a8u;
        t97 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x009217ab: 890a MOV
        batch_guest_pc = 0x009217abu;
        t98 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x009217ad: e998000000 JMP
        goto L_0092184a;
    // 0x009217b2: 3bfb CMP
    L_009217b2:
        t100a = state.regs[7];
        t100b = state.regs[3];
        t100r = static_cast<std::uint32_t>(t100a - t100b) & 0xffffffffu;
        batch_set_sub_flags(state, t100a, t100b, t100r, 32u);
    // 0x009217b4: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009217cd;
    // 0x009217b6: 385f0c CMP
        batch_guest_pc = 0x009217b6u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t102a)) return BatchLiftStatus::invalid_memory;
        t102b = state.regs[3] & 0x000000ffu;
        t102r = static_cast<std::uint32_t>(t102a - t102b) & 0x000000ffu;
        batch_set_sub_flags(state, t102a, t102b, t102r, 8u);
    // 0x009217b9: 7512 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009217cd;
    // 0x009217bb: c6420c01 MOV
        batch_guest_pc = 0x009217bbu;
        t104 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t104)) return BatchLiftStatus::invalid_memory;
    // 0x009217bf: c6470c01 MOV
        batch_guest_pc = 0x009217bfu;
        t105 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t105)) return BatchLiftStatus::invalid_memory;
    // 0x009217c3: 88590c MOV
        batch_guest_pc = 0x009217c3u;
        t106 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t106)) return BatchLiftStatus::invalid_memory;
    // 0x009217c6: 8bc1 MOV
        t107 = state.regs[1];
        state.regs[0] = t107;
    // 0x009217c8: e983000000 JMP
        goto L_00921850;
    // 0x009217cd: 3b4204 CMP
    L_009217cd:
        batch_guest_pc = 0x009217cdu;
        t109a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t109b)) return BatchLiftStatus::invalid_memory;
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0xffffffffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 32u);
    // 0x009217d0: 753a JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092180c;
    // 0x009217d2: 8b6e08 MOV
        batch_guest_pc = 0x009217d2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t111;
    // 0x009217d5: 8bc2 MOV
        t112 = state.regs[2];
        state.regs[0] = t112;
    // 0x009217d7: 8b5004 MOV
        batch_guest_pc = 0x009217d7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t113)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t113;
    // 0x009217da: 8b3a MOV
        batch_guest_pc = 0x009217dau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t114;
    // 0x009217dc: 897804 MOV
        batch_guest_pc = 0x009217dcu;
        t115 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t115)) return BatchLiftStatus::invalid_memory;
    // 0x009217df: 8b3a MOV
        batch_guest_pc = 0x009217dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t116;
    // 0x009217e1: 3bfb CMP
        t117a = state.regs[7];
        t117b = state.regs[3];
        t117r = static_cast<std::uint32_t>(t117a - t117b) & 0xffffffffu;
        batch_set_sub_flags(state, t117a, t117b, t117r, 32u);
    // 0x009217e3: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009217e8;
    // 0x009217e5: 894708 MOV
        batch_guest_pc = 0x009217e5u;
        t119 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t119)) return BatchLiftStatus::invalid_memory;
    // 0x009217e8: 8b7808 MOV
    L_009217e8:
        batch_guest_pc = 0x009217e8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t120;
    // 0x009217eb: 897a08 MOV
        batch_guest_pc = 0x009217ebu;
        t121 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t121)) return BatchLiftStatus::invalid_memory;
    // 0x009217ee: 3bc5 CMP
        t122a = state.regs[0];
        t122b = state.regs[5];
        t122r = static_cast<std::uint32_t>(t122a - t122b) & 0xffffffffu;
        batch_set_sub_flags(state, t122a, t122b, t122r, 32u);
    // 0x009217f0: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009217f6;
    // 0x009217f2: 8bea MOV
        t124 = state.regs[2];
        state.regs[5] = t124;
    // 0x009217f4: eb0e JMP
        goto L_00921804;
    // 0x009217f6: 8b7808 MOV
    L_009217f6:
        batch_guest_pc = 0x009217f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t126)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t126;
    // 0x009217f9: 3b07 CMP
        batch_guest_pc = 0x009217f9u;
        t127a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t127b)) return BatchLiftStatus::invalid_memory;
        t127r = static_cast<std::uint32_t>(t127a - t127b) & 0xffffffffu;
        batch_set_sub_flags(state, t127a, t127b, t127r, 32u);
    // 0x009217fb: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921801;
    // 0x009217fd: 8917 MOV
        batch_guest_pc = 0x009217fdu;
        t129 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t129)) return BatchLiftStatus::invalid_memory;
    // 0x009217ff: eb03 JMP
        goto L_00921804;
    // 0x00921801: 895704 MOV
    L_00921801:
        batch_guest_pc = 0x00921801u;
        t131 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t131)) return BatchLiftStatus::invalid_memory;
    // 0x00921804: 8902 MOV
    L_00921804:
        batch_guest_pc = 0x00921804u;
        t132 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t132)) return BatchLiftStatus::invalid_memory;
    // 0x00921806: 895008 MOV
        batch_guest_pc = 0x00921806u;
        t133 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x00921809: 896e08 MOV
        batch_guest_pc = 0x00921809u;
        t134 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x0092180c: 8b5008 MOV
    L_0092180c:
        batch_guest_pc = 0x0092180cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t135)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t135;
    // 0x0092180f: c6420c01 MOV
        batch_guest_pc = 0x0092180fu;
        t136 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t136)) return BatchLiftStatus::invalid_memory;
    // 0x00921813: 8b11 MOV
        batch_guest_pc = 0x00921813u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t137)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t137;
    // 0x00921815: 88590c MOV
        batch_guest_pc = 0x00921815u;
        t138 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t138)) return BatchLiftStatus::invalid_memory;
    // 0x00921818: 8b7a04 MOV
        batch_guest_pc = 0x00921818u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t139)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t139;
    // 0x0092181b: 8b6e08 MOV
        batch_guest_pc = 0x0092181bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t140)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t140;
    // 0x0092181e: 8939 MOV
        batch_guest_pc = 0x0092181eu;
        t141 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t141)) return BatchLiftStatus::invalid_memory;
    // 0x00921820: 8b7a04 MOV
        batch_guest_pc = 0x00921820u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t142)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t142;
    // 0x00921823: 3bfb CMP
        t143a = state.regs[7];
        t143b = state.regs[3];
        t143r = static_cast<std::uint32_t>(t143a - t143b) & 0xffffffffu;
        batch_set_sub_flags(state, t143a, t143b, t143r, 32u);
    // 0x00921825: 7403 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092182a;
    // 0x00921827: 894f08 MOV
        batch_guest_pc = 0x00921827u;
        t145 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t145)) return BatchLiftStatus::invalid_memory;
    // 0x0092182a: 8b7908 MOV
    L_0092182a:
        batch_guest_pc = 0x0092182au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t146)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t146;
    // 0x0092182d: 897a08 MOV
        batch_guest_pc = 0x0092182du;
        t147 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t147)) return BatchLiftStatus::invalid_memory;
    // 0x00921830: 3bcd CMP
        t148a = state.regs[1];
        t148b = state.regs[5];
        t148r = static_cast<std::uint32_t>(t148a - t148b) & 0xffffffffu;
        batch_set_sub_flags(state, t148a, t148b, t148r, 32u);
    // 0x00921832: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921838;
    // 0x00921834: 8bea MOV
        t150 = state.regs[2];
        state.regs[5] = t150;
    // 0x00921836: eb0f JMP
        goto L_00921847;
    // 0x00921838: 8b7908 MOV
    L_00921838:
        batch_guest_pc = 0x00921838u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t152;
    // 0x0092183b: 3b4f04 CMP
        batch_guest_pc = 0x0092183bu;
        t153a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t153b)) return BatchLiftStatus::invalid_memory;
        t153r = static_cast<std::uint32_t>(t153a - t153b) & 0xffffffffu;
        batch_set_sub_flags(state, t153a, t153b, t153r, 32u);
    // 0x0092183e: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00921845;
    // 0x00921840: 895704 MOV
        batch_guest_pc = 0x00921840u;
        t155 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t155)) return BatchLiftStatus::invalid_memory;
    // 0x00921843: eb02 JMP
        goto L_00921847;
    // 0x00921845: 8917 MOV
    L_00921845:
        batch_guest_pc = 0x00921845u;
        t157 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t157)) return BatchLiftStatus::invalid_memory;
    // 0x00921847: 894a04 MOV
    L_00921847:
        batch_guest_pc = 0x00921847u;
        t158 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t158)) return BatchLiftStatus::invalid_memory;
    // 0x0092184a: 895108 MOV
    L_0092184a:
        batch_guest_pc = 0x0092184au;
        t159 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t159)) return BatchLiftStatus::invalid_memory;
    // 0x0092184d: 896e08 MOV
        batch_guest_pc = 0x0092184du;
        t160 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t160)) return BatchLiftStatus::invalid_memory;
    // 0x00921850: 3b4608 CMP
    L_00921850:
        batch_guest_pc = 0x00921850u;
        t161a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t161b)) return BatchLiftStatus::invalid_memory;
        t161r = static_cast<std::uint32_t>(t161a - t161b) & 0xffffffffu;
        batch_set_sub_flags(state, t161a, t161b, t161r, 32u);
    // 0x00921853: 0f8597feffff JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009216f0;
    // 0x00921859: 8b4608 MOV
        batch_guest_pc = 0x00921859u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t163)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t163;
    // 0x0092185c: 5f POP
        batch_guest_pc = 0x0092185cu;
        if (!memory.load32(state.regs[4], t164a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t164a;
    // 0x0092185d: 5d POP
        batch_guest_pc = 0x0092185du;
        if (!memory.load32(state.regs[4], t165a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t165a;
    // 0x0092185e: 5e POP
        batch_guest_pc = 0x0092185eu;
        if (!memory.load32(state.regs[4], t166a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t166a;
    // 0x0092185f: c6400c01 MOV
        batch_guest_pc = 0x0092185fu;
        t167 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t167)) return BatchLiftStatus::invalid_memory;
    // 0x00921863: 5b POP
        batch_guest_pc = 0x00921863u;
        if (!memory.load32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t168a;
    // 0x00921864: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00921865: 8b4e08 MOV
    L_00921865:
        batch_guest_pc = 0x00921865u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t170)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t170;
    // 0x00921868: 5e POP
        batch_guest_pc = 0x00921868u;
        if (!memory.load32(state.regs[4], t171a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t171a;
    // 0x00921869: c6410c01 MOV
        batch_guest_pc = 0x00921869u;
        t172 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t172)) return BatchLiftStatus::invalid_memory;
    // 0x0092186d: 5b POP
        batch_guest_pc = 0x0092186du;
        if (!memory.load32(state.regs[4], t173a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t173a;
    // 0x0092186e: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092186f: 8b5608 MOV
    L_0092186f:
        batch_guest_pc = 0x0092186fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t175)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t175;
    // 0x00921872: 5f POP
        batch_guest_pc = 0x00921872u;
        if (!memory.load32(state.regs[4], t176a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t176a;
    // 0x00921873: 5d POP
        batch_guest_pc = 0x00921873u;
        if (!memory.load32(state.regs[4], t177a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t177a;
    // 0x00921874: 5e POP
        batch_guest_pc = 0x00921874u;
        if (!memory.load32(state.regs[4], t178a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t178a;
    // 0x00921875: c6420c01 MOV
        batch_guest_pc = 0x00921875u;
        t179 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t179)) return BatchLiftStatus::invalid_memory;
    // 0x00921879: 5b POP
        batch_guest_pc = 0x00921879u;
        if (!memory.load32(state.regs[4], t180a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t180a;
    // 0x0092187a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
