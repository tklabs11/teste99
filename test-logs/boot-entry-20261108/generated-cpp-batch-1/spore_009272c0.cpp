#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926840(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926c20(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009272f0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092733c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927393(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092740a(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009272c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009272c0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0, t75b = 0, t75r = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80a = 0, t80b = 0, t80r = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t83a = 0, t83b = 0, t83r = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t88a = 0, t88b = 0, t88r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103 = 0;
    BatchLiftStatus t104_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t105 = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113 = 0;
    BatchLiftStatus t114_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0, t116b = 0, t116r = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t119a = 0;
    std::uint32_t t120 = 0;
    BatchLiftStatus t121_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124a = 0, t124b = 0, t124r = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126a = 0, t126b = 0, t126r = 0;
    std::uint32_t t128 = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t133a = 0, t133b = 0, t133r = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135 = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t139 = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142 = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t144a = 0, t144b = 0, t144r = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147 = 0;
    std::uint32_t t148a = 0, t148c = 0, t148r = 0;
    std::uint32_t t149a = 0, t149b = 0, t149r = 0;
    std::uint32_t t150a = 0;
    std::uint32_t t151a = 0, t151b = 0, t151r = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0;
    std::uint32_t t154a = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156a = 0;
    std::uint32_t t157a = 0, t157b = 0, t157r = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160a = 0, t160b = 0, t160r = 0;
    std::uint32_t t161 = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165a = 0;
    std::uint32_t t166 = 0;
    std::uint32_t t167a = 0;
    std::uint32_t t168a = 0;
    std::uint32_t t169a = 0;
    std::uint32_t t170a = 0, t170b = 0, t170r = 0;

    // 0x009272c0: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009272c3: 53 PUSH
        batch_guest_pc = 0x009272c3u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009272c4: 55 PUSH
        batch_guest_pc = 0x009272c4u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009272c5: 56 PUSH
        batch_guest_pc = 0x009272c5u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009272c6: 8be9 MOV
        t4 = state.regs[1];
        state.regs[5] = t4;
    // 0x009272c8: 57 PUSH
        batch_guest_pc = 0x009272c8u;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x009272c9: 8bbd60040000 MOV
        batch_guest_pc = 0x009272c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000460u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t6;
    // 0x009272cf: 8db548040000 LEA
        t7 = static_cast<std::uint32_t>(state.regs[5] + 0x00000448u);
        state.regs[6] = t7;
    // 0x009272d5: 33db XOR
        t8a = state.regs[3];
        t8b = state.regs[3];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[3] = t8r;
    // 0x009272d7: 896c2414 MOV
        batch_guest_pc = 0x009272d7u;
        t9 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x009272db: c644241300 MOV
        batch_guest_pc = 0x009272dbu;
        t10 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x009272e0: 3bfe CMP
        t11a = state.regs[7];
        t11b = state.regs[6];
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x009272e2: 0f842d010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927415;
    // 0x009272e8: eb06 JMP
        goto L_009272f0;
    // 0x009272f0: 8b4708 MOV
    L_009272f0:
        batch_guest_pc = 0x009272f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x009272f3: 2b4704 SUB
        batch_guest_pc = 0x009272f3u;
        t15a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t15b)) return BatchLiftStatus::invalid_memory;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[0] = t15r;
    // 0x009272f6: 8b4c241c MOV
        batch_guest_pc = 0x009272f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x009272fa: 3bc8 CMP
        t17a = state.regs[1];
        t17b = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x009272fc: 7609 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00927307;
    // 0x009272fe: 8b7f18 MOV
        batch_guest_pc = 0x009272feu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t19;
    // 0x00927301: 3bfe CMP
        t20a = state.regs[7];
        t20b = state.regs[6];
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x00927303: 75eb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009272f0;
    // 0x00927305: eb35 JMP
        goto L_0092733c;
    // 0x00927307: 8b85dc040000 MOV
    L_00927307:
        batch_guest_pc = 0x00927307u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x000004dcu), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x0092730d: 3bc8 CMP
        t24a = state.regs[1];
        t24b = state.regs[0];
        t24r = static_cast<std::uint32_t>(t24a - t24b) & 0xffffffffu;
        batch_set_sub_flags(state, t24a, t24b, t24r, 32u);
    // 0x0092730f: 8bd9 MOV
        t25 = state.regs[1];
        state.regs[3] = t25;
    // 0x00927311: 8b4f04 MOV
        batch_guest_pc = 0x00927311u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x00927314: 0f42d8 CMOVC
        if ((state.eflags & 0x001u) != 0u) state.regs[3] = state.regs[0];
    // 0x00927317: 8b4708 MOV
        batch_guest_pc = 0x00927317u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x0092731a: 2bc1 SUB
        t29a = state.regs[0];
        t29b = state.regs[1];
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
        state.regs[0] = t29r;
    // 0x0092731c: 6a04 PUSH
        batch_guest_pc = 0x0092731cu;
        t30a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x0092731e: 3bd8 CMP
        t31a = state.regs[3];
        t31b = state.regs[0];
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x00927320: 6800100000 PUSH
        batch_guest_pc = 0x00927320u;
        t32a = 0x00001000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00927325: 0f47d8 CMOVA
        t33a = state.regs[0];
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) state.regs[3] = t33a;
    // 0x00927328: 53 PUSH
        batch_guest_pc = 0x00927328u;
        t34a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00927329: 03cf ADD
        t35a = state.regs[1];
        t35b = state.regs[7];
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[1] = t35r;
    // 0x0092732b: 51 PUSH
        batch_guest_pc = 0x0092732bu;
        t36a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x0092732c: ff15c8c13c01 CALL
        t37_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualAlloc", 0x013cc1c8u, 0x00927332u);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x00927332u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927332: 85c0 TEST
        t38a = state.regs[0];
        t38b = state.regs[0];
        t38r = (t38a & t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
    // 0x00927334: 7506 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092733c;
    // 0x00927336: 8b4f04 MOV
        batch_guest_pc = 0x00927336u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x00927339: 894f08 MOV
        batch_guest_pc = 0x00927339u;
        t41 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0092733c: 3bfe CMP
    L_0092733c:
        t42a = state.regs[7];
        t42b = state.regs[6];
        t42r = static_cast<std::uint32_t>(t42a - t42b) & 0xffffffffu;
        batch_set_sub_flags(state, t42a, t42b, t42r, 32u);
    // 0x0092733e: 0f84d1000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927415;
    // 0x00927344: 8b4704 MOV
        batch_guest_pc = 0x00927344u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t44;
    // 0x00927347: 85c0 TEST
        t45a = state.regs[0];
        t45b = state.regs[0];
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
    // 0x00927349: 7462 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009273ad;
    // 0x0092734b: f64438f401 TEST
        batch_guest_pc = 0x0092734bu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0xfffffff4u), t47a)) return BatchLiftStatus::invalid_memory;
        t47b = 0x00000001u;
        t47r = (t47a & t47b) & 0x000000ffu;
        batch_set_logic_flags(state, t47r, 8u);
    // 0x00927350: 8d4438f0 LEA
        t48 = static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 1u + 0xfffffff0u);
        state.regs[0] = t48;
    // 0x00927354: 8bf0 MOV
        t49 = state.regs[0];
        state.regs[6] = t49;
    // 0x00927356: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927364;
    // 0x00927358: 8bd3 MOV
        t51 = state.regs[3];
        state.regs[2] = t51;
    // 0x0092735a: 83ca01 OR
        t52a = state.regs[2];
        t52b = 0x00000001u;
        t52r = (t52a | t52b) & 0xffffffffu;
        batch_set_logic_flags(state, t52r, 32u);
        state.regs[2] = t52r;
    // 0x0092735d: 8beb MOV
        t53 = state.regs[3];
        state.regs[5] = t53;
    // 0x0092735f: 895004 MOV
        batch_guest_pc = 0x0092735fu;
        t54 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t54)) return BatchLiftStatus::invalid_memory;
    // 0x00927362: eb2f JMP
        goto L_00927393;
    // 0x00927364: 2b30 SUB
    L_00927364:
        batch_guest_pc = 0x00927364u;
        t56a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t56b)) return BatchLiftStatus::invalid_memory;
        t56r = static_cast<std::uint32_t>(t56a - t56b) & 0xffffffffu;
        batch_set_sub_flags(state, t56a, t56b, t56r, 32u);
        state.regs[6] = t56r;
    // 0x00927366: 8b4e08 MOV
        batch_guest_pc = 0x00927366u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t57;
    // 0x00927369: 8b560c MOV
        batch_guest_pc = 0x00927369u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t58;
    // 0x0092736c: 89510c MOV
        batch_guest_pc = 0x0092736cu;
        t59 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x0092736f: 8b4e0c MOV
        batch_guest_pc = 0x0092736fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t60;
    // 0x00927372: 8b5608 MOV
        batch_guest_pc = 0x00927372u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t61;
    // 0x00927375: 895108 MOV
        batch_guest_pc = 0x00927375u;
        t62 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00927378: 8b28 MOV
        batch_guest_pc = 0x00927378u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t63;
    // 0x0092737a: 8b4c2414 MOV
        batch_guest_pc = 0x0092737au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t64;
    // 0x0092737e: 03eb ADD
        t65a = state.regs[5];
        t65b = state.regs[3];
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[5] = t65r;
    // 0x00927380: 8bc5 MOV
        t66 = state.regs[5];
        state.regs[0] = t66;
    // 0x00927382: 83c801 OR
        t67a = state.regs[0];
        t67b = 0x00000001u;
        t67r = (t67a | t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
        state.regs[0] = t67r;
    // 0x00927385: 894604 MOV
        batch_guest_pc = 0x00927385u;
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00927388: 3bb140040000 CMP
        batch_guest_pc = 0x00927388u;
        t69a = state.regs[6];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t69b)) return BatchLiftStatus::invalid_memory;
        t69r = static_cast<std::uint32_t>(t69a - t69b) & 0xffffffffu;
        batch_set_sub_flags(state, t69a, t69b, t69r, 32u);
    // 0x0092738e: 0f94442413 SETZ
        batch_guest_pc = 0x0092738eu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), (((state.eflags & 0x040u) != 0u) ? 1u : 0u))) return BatchLiftStatus::invalid_memory;
    // 0x00927393: 8d042e LEA
    L_00927393:
        t71 = static_cast<std::uint32_t>(state.regs[6] + state.regs[5] * 1u + 0x00000000u);
        state.regs[0] = t71;
    // 0x00927396: ba08000000 MOV
        t72 = 0x00000008u;
        state.regs[2] = t72;
    // 0x0092739b: 8928 MOV
        batch_guest_pc = 0x0092739bu;
        t73 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x0092739d: 895004 MOV
        batch_guest_pc = 0x0092739du;
        t74 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t74)) return BatchLiftStatus::invalid_memory;
    // 0x009273a0: 03c2 ADD
        t75a = state.regs[0];
        t75b = state.regs[2];
        t75r = static_cast<std::uint32_t>(t75a + t75b) & 0xffffffffu;
        batch_set_add_flags(state, t75a, t75b, t75r, 32u);
        state.regs[0] = t75r;
    // 0x009273a2: 8910 MOV
        batch_guest_pc = 0x009273a2u;
        t76 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x009273a4: c7400409000000 MOV
        batch_guest_pc = 0x009273a4u;
        t77 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x009273ab: eb5d JMP
        goto L_0092740a;
    // 0x009273ad: 8d4727 LEA
    L_009273ad:
        t79 = static_cast<std::uint32_t>(state.regs[7] + 0x00000027u);
        state.regs[0] = t79;
    // 0x009273b0: 83e0f8 AND
        t80a = state.regs[0];
        t80b = 0xfffffff8u;
        t80r = (t80a & t80b) & 0xffffffffu;
        batch_set_logic_flags(state, t80r, 32u);
        state.regs[0] = t80r;
    // 0x009273b3: 8bd7 MOV
        t81 = state.regs[7];
        state.regs[2] = t81;
    // 0x009273b5: 2bd0 SUB
        t82a = state.regs[2];
        t82b = state.regs[0];
        t82r = static_cast<std::uint32_t>(t82a - t82b) & 0xffffffffu;
        batch_set_sub_flags(state, t82a, t82b, t82r, 32u);
        state.regs[2] = t82r;
    // 0x009273b7: 03d3 ADD
        t83a = state.regs[2];
        t83b = state.regs[3];
        t83r = static_cast<std::uint32_t>(t83a + t83b) & 0xffffffffu;
        batch_set_add_flags(state, t83a, t83b, t83r, 32u);
        state.regs[2] = t83r;
    // 0x009273b9: 83ca01 OR
        t84a = state.regs[2];
        t84b = 0x00000001u;
        t84r = (t84a | t84b) & 0xffffffffu;
        batch_set_logic_flags(state, t84r, 32u);
        state.regs[2] = t84r;
    // 0x009273bc: 8bca MOV
        t85 = state.regs[2];
        state.regs[1] = t85;
    // 0x009273be: 81e1f8ffff7f AND
        t86a = state.regs[1];
        t86b = 0x7ffffff8u;
        t86r = (t86a & t86b) & 0xffffffffu;
        batch_set_logic_flags(state, t86r, 32u);
        state.regs[1] = t86r;
    // 0x009273c4: 83e909 SUB
        t87a = state.regs[1];
        t87b = 0x00000009u;
        t87r = static_cast<std::uint32_t>(t87a - t87b) & 0xffffffffu;
        batch_set_sub_flags(state, t87a, t87b, t87r, 32u);
        state.regs[1] = t87r;
    // 0x009273c7: 83e1f8 AND
        t88a = state.regs[1];
        t88b = 0xfffffff8u;
        t88r = (t88a & t88b) & 0xffffffffu;
        batch_set_logic_flags(state, t88r, 32u);
        state.regs[1] = t88r;
    // 0x009273ca: 8907 MOV
        batch_guest_pc = 0x009273cau;
        t89 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x009273cc: 81e207000080 AND
        t90a = state.regs[2];
        t90b = 0x80000007u;
        t90r = (t90a & t90b) & 0xffffffffu;
        batch_set_logic_flags(state, t90r, 32u);
        state.regs[2] = t90r;
    // 0x009273d2: 0bd1 OR
        t91a = state.regs[2];
        t91b = state.regs[1];
        t91r = (t91a | t91b) & 0xffffffffu;
        batch_set_logic_flags(state, t91r, 32u);
        state.regs[2] = t91r;
    // 0x009273d4: 895004 MOV
        batch_guest_pc = 0x009273d4u;
        t92 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x009273d7: c70000000000 MOV
        batch_guest_pc = 0x009273d7u;
        t93 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t93)) return BatchLiftStatus::invalid_memory;
    // 0x009273dd: ba08000000 MOV
        t94 = 0x00000008u;
        state.regs[2] = t94;
    // 0x009273e2: 890c01 MOV
        batch_guest_pc = 0x009273e2u;
        t95 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000000u), t95)) return BatchLiftStatus::invalid_memory;
    // 0x009273e5: 89540104 MOV
        batch_guest_pc = 0x009273e5u;
        t96 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000004u), t96)) return BatchLiftStatus::invalid_memory;
    // 0x009273e9: 6a01 PUSH
        batch_guest_pc = 0x009273e9u;
        t97a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
    // 0x009273eb: 89540108 MOV
        batch_guest_pc = 0x009273ebu;
        t98 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x00000008u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x009273ef: c744010c09000000 MOV
        batch_guest_pc = 0x009273efu;
        t99 = 0x00000009u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0x0000000cu), t99)) return BatchLiftStatus::invalid_memory;
    // 0x009273f7: 8b4c2418 MOV
        batch_guest_pc = 0x009273f7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t100;
    // 0x009273fb: 50 PUSH
        batch_guest_pc = 0x009273fbu;
        t101a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
    // 0x009273fc: 8bf0 MOV
        t102 = state.regs[0];
        state.regs[6] = t102;
    // 0x009273fe: 8beb MOV
        t103 = state.regs[3];
        state.regs[5] = t103;
    // 0x00927400: e83bf4ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926840u, 0x00927405u)) return BatchLiftStatus::invalid_memory;
        t104_call_status = spore_lift_00926840(memory, state);
        if (t104_call_status != BatchLiftStatus::returned) return t104_call_status;
        if (state.eip != 0x00927405u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927405: c644241301 MOV
        batch_guest_pc = 0x00927405u;
        t105 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t105)) return BatchLiftStatus::invalid_memory;
    // 0x0092740a: 015f04 ADD
    L_0092740a:
        batch_guest_pc = 0x0092740au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t106a)) return BatchLiftStatus::invalid_memory;
        t106b = state.regs[3];
        t106r = static_cast<std::uint32_t>(t106a + t106b) & 0xffffffffu;
        batch_set_add_flags(state, t106a, t106b, t106r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t106r)) return BatchLiftStatus::invalid_memory;
    // 0x0092740d: 85f6 TEST
        t107a = state.regs[6];
        t107b = state.regs[6];
        t107r = (t107a & t107b) & 0xffffffffu;
        batch_set_logic_flags(state, t107r, 32u);
    // 0x0092740f: 7534 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927445;
    // 0x00927411: 8b6c2414 MOV
        batch_guest_pc = 0x00927411u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t109)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t109;
    // 0x00927415: 8b54241c MOV
    L_00927415:
        batch_guest_pc = 0x00927415u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t110;
    // 0x00927419: 6a00 PUSH
        batch_guest_pc = 0x00927419u;
        t111a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
    // 0x0092741b: 52 PUSH
        batch_guest_pc = 0x0092741bu;
        t112a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
    // 0x0092741c: 8bcd MOV
        t113 = state.regs[5];
        state.regs[1] = t113;
    // 0x0092741e: e8fdf7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926c20u, 0x00927423u)) return BatchLiftStatus::invalid_memory;
        t114_call_status = spore_lift_00926c20(memory, state);
        if (t114_call_status != BatchLiftStatus::returned) return t114_call_status;
        if (state.eip != 0x00927423u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927423: 8bf0 MOV
        t115 = state.regs[0];
        state.regs[6] = t115;
    // 0x00927425: 85f6 TEST
        t116a = state.regs[6];
        t116b = state.regs[6];
        t116r = (t116a & t116b) & 0xffffffffu;
        batch_set_logic_flags(state, t116r, 32u);
    // 0x00927427: 0f8495000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009274c2;
    // 0x0092742d: 6a01 PUSH
        batch_guest_pc = 0x0092742du;
        t118a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x0092742f: 56 PUSH
        batch_guest_pc = 0x0092742fu;
        t119a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t119a)) return BatchLiftStatus::invalid_memory;
    // 0x00927430: 8bcd MOV
        t120 = state.regs[5];
        state.regs[1] = t120;
    // 0x00927432: e809f4ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926840u, 0x00927437u)) return BatchLiftStatus::invalid_memory;
        t121_call_status = spore_lift_00926840(memory, state);
        if (t121_call_status != BatchLiftStatus::returned) return t121_call_status;
        if (state.eip != 0x00927437u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927437: 8b6e04 MOV
        batch_guest_pc = 0x00927437u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t122;
    // 0x0092743a: c644241301 MOV
        batch_guest_pc = 0x0092743au;
        t123 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t123)) return BatchLiftStatus::invalid_memory;
    // 0x0092743f: 81e5f8ffff7f AND
        t124a = state.regs[5];
        t124b = 0x7ffffff8u;
        t124r = (t124a & t124b) & 0xffffffffu;
        batch_set_logic_flags(state, t124r, 32u);
        state.regs[5] = t124r;
    // 0x00927445: 8b4c241c MOV
    L_00927445:
        batch_guest_pc = 0x00927445u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t125;
    // 0x00927449: 3be9 CMP
        t126a = state.regs[5];
        t126b = state.regs[1];
        t126r = static_cast<std::uint32_t>(t126a - t126b) & 0xffffffffu;
        batch_set_sub_flags(state, t126a, t126b, t126r, 32u);
    // 0x0092744b: 7675 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009274c2;
    // 0x0092744d: 8bc1 MOV
        t128 = state.regs[1];
        state.regs[0] = t128;
    // 0x0092744f: 83c801 OR
        t129a = state.regs[0];
        t129b = 0x00000001u;
        t129r = (t129a | t129b) & 0xffffffffu;
        batch_set_logic_flags(state, t129r, 32u);
        state.regs[0] = t129r;
    // 0x00927452: 894604 MOV
        batch_guest_pc = 0x00927452u;
        t130 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00927455: 8d040e LEA
        t131 = static_cast<std::uint32_t>(state.regs[6] + state.regs[1] * 1u + 0x00000000u);
        state.regs[0] = t131;
    // 0x00927458: 2be9 SUB
        t132a = state.regs[5];
        t132b = state.regs[1];
        t132r = static_cast<std::uint32_t>(t132a - t132b) & 0xffffffffu;
        batch_set_sub_flags(state, t132a, t132b, t132r, 32u);
        state.regs[5] = t132r;
    // 0x0092745a: 807c241300 CMP
        batch_guest_pc = 0x0092745au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000013u), t133a)) return BatchLiftStatus::invalid_memory;
        t133b = 0x00000000u;
        t133r = static_cast<std::uint32_t>(t133a - t133b) & 0x000000ffu;
        batch_set_sub_flags(state, t133a, t133b, t133r, 8u);
    // 0x0092745f: 8908 MOV
        batch_guest_pc = 0x0092745fu;
        t134 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t134)) return BatchLiftStatus::invalid_memory;
    // 0x00927461: 8b4c2414 MOV
        batch_guest_pc = 0x00927461u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t135)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t135;
    // 0x00927465: 896804 MOV
        batch_guest_pc = 0x00927465u;
        t136 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t136)) return BatchLiftStatus::invalid_memory;
    // 0x00927468: 892c28 MOV
        batch_guest_pc = 0x00927468u;
        t137 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[5] * 1u + 0x00000000u), t137)) return BatchLiftStatus::invalid_memory;
    // 0x0092746b: 7443 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009274b0;
    // 0x0092746d: 898140040000 MOV
        batch_guest_pc = 0x0092746du;
        t139 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t139)) return BatchLiftStatus::invalid_memory;
    // 0x00927473: 89400c MOV
        batch_guest_pc = 0x00927473u;
        t140 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t140)) return BatchLiftStatus::invalid_memory;
    // 0x00927476: 8b8140040000 MOV
        batch_guest_pc = 0x00927476u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t141)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t141;
    // 0x0092747c: 8b500c MOV
        batch_guest_pc = 0x0092747cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t142)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t142;
    // 0x0092747f: 895008 MOV
        batch_guest_pc = 0x0092747fu;
        t143 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t143)) return BatchLiftStatus::invalid_memory;
    // 0x00927482: 80b96c04000000 CMP
        batch_guest_pc = 0x00927482u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000046cu), t144a)) return BatchLiftStatus::invalid_memory;
        t144b = 0x00000000u;
        t144r = static_cast<std::uint32_t>(t144a - t144b) & 0x000000ffu;
        batch_set_sub_flags(state, t144a, t144b, t144r, 8u);
    // 0x00927489: 7537 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009274c2;
    // 0x0092748b: 8b8140040000 MOV
        batch_guest_pc = 0x0092748bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t146)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t146;
    // 0x00927491: 8b5004 MOV
        batch_guest_pc = 0x00927491u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t147)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t147;
    // 0x00927494: d1ea SHR
        t148a = state.regs[2];
        t148c = 1u;
        if (t148c != 0u) {
        t148r = static_cast<std::uint32_t>(t148a >> t148c);
        batch_set_shr_flags(state, t148a, t148c, t148r, 32u);
            state.regs[2] = t148r;
        }
    // 0x00927496: 81e2fcffff3f AND
        t149a = state.regs[2];
        t149b = 0x3ffffffcu;
        t149r = (t149a & t149b) & 0xffffffffu;
        batch_set_logic_flags(state, t149r, 32u);
        state.regs[2] = t149r;
    // 0x0092749c: 5f POP
        batch_guest_pc = 0x0092749cu;
        if (!memory.load32(state.regs[4], t150a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t150a;
    // 0x0092749d: 03d0 ADD
        t151a = state.regs[2];
        t151b = state.regs[0];
        t151r = static_cast<std::uint32_t>(t151a + t151b) & 0xffffffffu;
        batch_set_add_flags(state, t151a, t151b, t151r, 32u);
        state.regs[2] = t151r;
    // 0x0092749f: 8bc6 MOV
        t152 = state.regs[6];
        state.regs[0] = t152;
    // 0x009274a1: 5e POP
        batch_guest_pc = 0x009274a1u;
        if (!memory.load32(state.regs[4], t153a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t153a;
    // 0x009274a2: 5d POP
        batch_guest_pc = 0x009274a2u;
        if (!memory.load32(state.regs[4], t154a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t154a;
    // 0x009274a3: 899168040000 MOV
        batch_guest_pc = 0x009274a3u;
        t155 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000468u), t155)) return BatchLiftStatus::invalid_memory;
    // 0x009274a9: 5b POP
        batch_guest_pc = 0x009274a9u;
        if (!memory.load32(state.regs[4], t156a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t156a;
    // 0x009274aa: 83c408 ADD
        t157a = state.regs[4];
        t157b = 0x00000008u;
        t157r = static_cast<std::uint32_t>(t157a + t157b) & 0xffffffffu;
        batch_set_add_flags(state, t157a, t157b, t157r, 32u);
        state.regs[4] = t157r;
    // 0x009274ad: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009274b0: 8b513c MOV
    L_009274b0:
        batch_guest_pc = 0x009274b0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000003cu), t159)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t159;
    // 0x009274b3: 83c130 ADD
        t160a = state.regs[1];
        t160b = 0x00000030u;
        t160r = static_cast<std::uint32_t>(t160a + t160b) & 0xffffffffu;
        batch_set_add_flags(state, t160a, t160b, t160r, 32u);
        state.regs[1] = t160r;
    // 0x009274b6: 894808 MOV
        batch_guest_pc = 0x009274b6u;
        t161 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t161)) return BatchLiftStatus::invalid_memory;
    // 0x009274b9: 89500c MOV
        batch_guest_pc = 0x009274b9u;
        t162 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t162)) return BatchLiftStatus::invalid_memory;
    // 0x009274bc: 89410c MOV
        batch_guest_pc = 0x009274bcu;
        t163 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t163)) return BatchLiftStatus::invalid_memory;
    // 0x009274bf: 894208 MOV
        batch_guest_pc = 0x009274bfu;
        t164 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t164)) return BatchLiftStatus::invalid_memory;
    // 0x009274c2: 5f POP
    L_009274c2:
        batch_guest_pc = 0x009274c2u;
        if (!memory.load32(state.regs[4], t165a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t165a;
    // 0x009274c3: 8bc6 MOV
        t166 = state.regs[6];
        state.regs[0] = t166;
    // 0x009274c5: 5e POP
        batch_guest_pc = 0x009274c5u;
        if (!memory.load32(state.regs[4], t167a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t167a;
    // 0x009274c6: 5d POP
        batch_guest_pc = 0x009274c6u;
        if (!memory.load32(state.regs[4], t168a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t168a;
    // 0x009274c7: 5b POP
        batch_guest_pc = 0x009274c7u;
        if (!memory.load32(state.regs[4], t169a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t169a;
    // 0x009274c8: 83c408 ADD
        t170a = state.regs[4];
        t170b = 0x00000008u;
        t170r = static_cast<std::uint32_t>(t170a + t170b) & 0xffffffffu;
        batch_set_add_flags(state, t170a, t170b, t170r, 32u);
        state.regs[4] = t170r;
    // 0x009274cb: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
