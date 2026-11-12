#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00571e80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923dc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924c60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924e76(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924eb6(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924f30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0093a5e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00942e50(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0cc0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924d90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924d90u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t30 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35a = 0;
    BatchLiftStatus t36_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    BatchLiftStatus t52_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71r = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79 = 0;
    BatchLiftStatus t80_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t84 = 0;
    BatchLiftStatus t85_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t86 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t93a = 0;
    BatchLiftStatus t94_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    BatchLiftStatus t99_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t100a = 0;
    std::uint32_t t101a = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    BatchLiftStatus t105_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111r = 0;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t114a = 0, t114b = 0, t114r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t119 = 0;
    BatchLiftStatus t120_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128a = 0, t128r = 0;
    std::uint32_t t129a = 0, t129b = 0, t129r = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t132a = 0, t132b = 0, t132r = 0;
    std::uint32_t t133a = 0;
    std::uint32_t t134a = 0;
    std::uint32_t t135 = 0;
    BatchLiftStatus t136_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t137a = 0;
    std::uint32_t t138 = 0;
    BatchLiftStatus t139_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t140 = 0;
    std::uint32_t t141a = 0, t141b = 0, t141r = 0;
    std::uint32_t t143 = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145 = 0;
    BatchLiftStatus t146_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t147 = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    std::uint32_t t150a = 0, t150r = 0;
    std::uint32_t t151a = 0, t151b = 0, t151r = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;
    std::uint32_t t154a = 0, t154b = 0, t154r = 0;
    std::uint32_t t155a = 0;
    std::uint32_t t156a = 0;
    std::uint32_t t157 = 0;
    BatchLiftStatus t158_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t159a = 0;
    std::uint32_t t160 = 0;
    BatchLiftStatus t161_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t166a = 0, t166r = 0;
    std::uint32_t t167a = 0, t167b = 0, t167r = 0;
    std::uint32_t t169 = 0;
    std::uint32_t t170a = 0, t170b = 0, t170r = 0;
    std::uint32_t t171a = 0, t171b = 0, t171r = 0;
    std::uint32_t t172a = 0;
    std::uint32_t t173a = 0;
    std::uint32_t t174 = 0;
    BatchLiftStatus t175_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t176 = 0;
    std::uint32_t t177a = 0, t177b = 0, t177r = 0;
    std::uint32_t t179 = 0;
    std::uint32_t t180a = 0, t180b = 0, t180r = 0;
    std::uint32_t t182a = 0;
    std::uint32_t t183 = 0;
    BatchLiftStatus t184_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t185 = 0;
    std::uint32_t t186a = 0, t186b = 0, t186r = 0;
    std::uint32_t t188 = 0;
    std::uint32_t t189 = 0;
    std::uint32_t t190 = 0;
    std::uint32_t t191a = 0;
    std::uint32_t t192a = 0;
    std::uint32_t t193a = 0;
    std::uint32_t t194a = 0;
    std::uint32_t t195a = 0;
    BatchLiftStatus t196_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t197a = 0, t197b = 0, t197r = 0;
    std::uint32_t t198 = 0;
    std::uint32_t t199a = 0;
    std::uint32_t t200a = 0;
    std::uint32_t t201a = 0;
    std::uint32_t t202a = 0;
    std::uint32_t t203a = 0, t203b = 0, t203r = 0;

    // 0x00924d90: 83ec34 SUB
        t0a = state.regs[4];
        t0b = 0x00000034u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00924d93: 53 PUSH
        batch_guest_pc = 0x00924d93u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d94: 8b5c243c MOV
        batch_guest_pc = 0x00924d94u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t2;
    // 0x00924d98: 8b03 MOV
        batch_guest_pc = 0x00924d98u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00924d9a: 8b500c MOV
        batch_guest_pc = 0x00924d9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t4;
    // 0x00924d9d: 55 PUSH
        batch_guest_pc = 0x00924d9du;
        t5a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d9e: 57 PUSH
        batch_guest_pc = 0x00924d9eu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d9f: 8b7b0c MOV
        batch_guest_pc = 0x00924d9fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000000cu), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t7;
    // 0x00924da2: 8be9 MOV
        t8 = state.regs[1];
        state.regs[5] = t8;
    // 0x00924da4: 8bcb MOV
        t9 = state.regs[3];
        state.regs[1] = t9;
    // 0x00924da6: 896c240c MOV
        batch_guest_pc = 0x00924da6u;
        t10 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00924daa: 897c2410 MOV
        batch_guest_pc = 0x00924daau;
        t11 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00924dae: ffd2 CALL
        t12_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924db0u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
    // 0x00924db0: 6683bd1c02000000 CMP
        batch_guest_pc = 0x00924db0u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[5] + 0x0000021cu), t13a)) return BatchLiftStatus::invalid_memory;
        t13b = 0x00000000u;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0x0000ffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 16u);
    // 0x00924db8: 89442414 MOV
        batch_guest_pc = 0x00924db8u;
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00924dbc: 750f JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924dcd;
    // 0x00924dbe: 8b4f0c MOV
        batch_guest_pc = 0x00924dbeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x00924dc1: 3b8d20020000 CMP
        batch_guest_pc = 0x00924dc1u;
        t17a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000220u), t17b)) return BatchLiftStatus::invalid_memory;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00924dc7: 0f8c1c020000 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00924fe9;
    // 0x00924dcd: 8b8540020000 MOV
    L_00924dcd:
        batch_guest_pc = 0x00924dcdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000240u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00924dd3: 3b8544020000 CMP
        batch_guest_pc = 0x00924dd3u;
        t20a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000244u), t20b)) return BatchLiftStatus::invalid_memory;
        t20r = static_cast<std::uint32_t>(t20a - t20b) & 0xffffffffu;
        batch_set_sub_flags(state, t20a, t20b, t20r, 32u);
    // 0x00924dd9: 56 PUSH
        batch_guest_pc = 0x00924dd9u;
        t21a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00924dda: 8db540020000 LEA
        t22 = static_cast<std::uint32_t>(state.regs[5] + 0x00000240u);
        state.regs[6] = t22;
    // 0x00924de0: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924dea;
    // 0x00924de2: c60000 MOV
        batch_guest_pc = 0x00924de2u;
        t24 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00924de5: 8b16 MOV
        batch_guest_pc = 0x00924de5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t25;
    // 0x00924de7: 895604 MOV
        batch_guest_pc = 0x00924de7u;
        t26 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00924dea: f6851c02000003 TEST
    L_00924dea:
        batch_guest_pc = 0x00924deau;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000021cu), t27a)) return BatchLiftStatus::invalid_memory;
        t27b = 0x00000003u;
        t27r = (t27a & t27b) & 0x000000ffu;
        batch_set_logic_flags(state, t27r, 8u);
    // 0x00924df1: 0f84c7000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924ebe;
    // 0x00924df7: 81c528020000 ADD
        t29a = state.regs[5];
        t29b = 0x00000228u;
        t29r = static_cast<std::uint32_t>(t29a + t29b) & 0xffffffffu;
        batch_set_add_flags(state, t29a, t29b, t29r, 32u);
        state.regs[5] = t29r;
    // 0x00924dfd: 8bcd MOV
        t30 = state.regs[5];
        state.regs[1] = t30;
    // 0x00924dff: e8dc570100 CALL
        if (!batch_guest_call32(memory, state, 0x0093a5e0u, 0x00924e04u)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_0093a5e0(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00924e04u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e04: 6a00 PUSH
        batch_guest_pc = 0x00924e04u;
        t32a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e06: 68e8030000 PUSH
        batch_guest_pc = 0x00924e06u;
        t33a = 0x000003e8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e0b: 52 PUSH
        batch_guest_pc = 0x00924e0bu;
        t34a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e0c: 50 PUSH
        batch_guest_pc = 0x00924e0cu;
        t35a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e0d: e8aebe8b00 CALL
        if (!batch_guest_call32(memory, state, 0x011e0cc0u, 0x00924e12u)) return BatchLiftStatus::invalid_memory;
        t36_call_status = spore_lift_011e0cc0(memory, state);
        if (t36_call_status != BatchLiftStatus::returned) return t36_call_status;
        if (state.eip != 0x00924e12u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e12: 8944241c MOV
        batch_guest_pc = 0x00924e12u;
        t37 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00924e16: 8d44241c LEA
        t38 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[0] = t38;
    // 0x00924e1a: 50 PUSH
        batch_guest_pc = 0x00924e1au;
        t39a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e1b: 8bf9 MOV
        t40 = state.regs[1];
        state.regs[7] = t40;
    // 0x00924e1d: 89542424 MOV
        batch_guest_pc = 0x00924e1du;
        t41 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00924e21: ff1510c43c01 CALL
        t42_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_gmtime64", 0x013cc410u, 0x00924e27u);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00924e27u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e27: 8b4c2414 MOV
        batch_guest_pc = 0x00924e27u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00924e2b: 83c404 ADD
        t44a = state.regs[4];
        t44b = 0x00000004u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[4] = t44r;
    // 0x00924e2e: f6811c02000004 TEST
        batch_guest_pc = 0x00924e2eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000021cu), t45a)) return BatchLiftStatus::invalid_memory;
        t45b = 0x00000004u;
        t45r = (t45a & t45b) & 0x000000ffu;
        batch_set_logic_flags(state, t45r, 8u);
    // 0x00924e35: 50 PUSH
        batch_guest_pc = 0x00924e35u;
        t46a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e36: 7429 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924e61;
    // 0x00924e38: 68dcdf4301 PUSH
        batch_guest_pc = 0x00924e38u;
        t48a = 0x0143dfdcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e3d: 8d54242c LEA
        t49 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[2] = t49;
    // 0x00924e41: 6a20 PUSH
        batch_guest_pc = 0x00924e41u;
        t50a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e43: 52 PUSH
        batch_guest_pc = 0x00924e43u;
        t51a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e44: ff15dcc33c01 CALL
        t52_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strftime", 0x013cc3dcu, 0x00924e4au);
        if (t52_call_status != BatchLiftStatus::returned) return t52_call_status;
        if (state.eip != 0x00924e4au) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e4a: 53 PUSH
        batch_guest_pc = 0x00924e4au;
        t53a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e4b: 57 PUSH
        batch_guest_pc = 0x00924e4bu;
        t54a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e4c: 8d44043c LEA
        t55 = static_cast<std::uint32_t>(state.regs[4] + state.regs[0] * 1u + 0x0000003cu);
        state.regs[0] = t55;
    // 0x00924e50: 68d4df4301 PUSH
        batch_guest_pc = 0x00924e50u;
        t56a = 0x0143dfd4u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e55: 50 PUSH
        batch_guest_pc = 0x00924e55u;
        t57a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e56: ff15a0c43c01 CALL
        t58_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!sprintf", 0x013cc4a0u, 0x00924e5cu);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x00924e5cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e5c: 83c420 ADD
        t59a = state.regs[4];
        t59b = 0x00000020u;
        t59r = static_cast<std::uint32_t>(t59a + t59b) & 0xffffffffu;
        batch_set_add_flags(state, t59a, t59b, t59r, 32u);
        state.regs[4] = t59r;
    // 0x00924e5f: eb15 JMP
        goto L_00924e76;
    // 0x00924e61: 68c8df4301 PUSH
    L_00924e61:
        batch_guest_pc = 0x00924e61u;
        t61a = 0x0143dfc8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e66: 8d44242c LEA
        t62 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[0] = t62;
    // 0x00924e6a: 6a20 PUSH
        batch_guest_pc = 0x00924e6au;
        t63a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e6c: 50 PUSH
        batch_guest_pc = 0x00924e6cu;
        t64a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e6d: ff15dcc33c01 CALL
        t65_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strftime", 0x013cc3dcu, 0x00924e73u);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x00924e73u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e73: 83c410 ADD
        t66a = state.regs[4];
        t66b = 0x00000010u;
        t66r = static_cast<std::uint32_t>(t66a + t66b) & 0xffffffffu;
        batch_set_add_flags(state, t66a, t66b, t66r, 32u);
        state.regs[4] = t66r;
    // 0x00924e76: 8d442424 LEA
    L_00924e76:
        t67 = static_cast<std::uint32_t>(state.regs[4] + 0x00000024u);
        state.regs[0] = t67;
    // 0x00924e7a: 8d5001 LEA
        t68 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t68;
    // 0x00924e7d: 8d4900 LEA
        t69 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t69;
    // 0x00924e80: 8a08 MOV
    L_00924e80:
        batch_guest_pc = 0x00924e80u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t70 << 0u) & 0x000000ffu);
    // 0x00924e82: 40 INC
        t71a = state.regs[0];
        t71r = static_cast<std::uint32_t>(t71a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t71a, t71r, 32u);
        state.regs[0] = t71r;
    // 0x00924e83: 84c9 TEST
        t72a = state.regs[1] & 0x000000ffu;
        t72b = state.regs[1] & 0x000000ffu;
        t72r = (t72a & t72b) & 0x000000ffu;
        batch_set_logic_flags(state, t72r, 8u);
    // 0x00924e85: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924e80;
    // 0x00924e87: 2bc2 SUB
        t74a = state.regs[0];
        t74b = state.regs[2];
        t74r = static_cast<std::uint32_t>(t74a - t74b) & 0xffffffffu;
        batch_set_sub_flags(state, t74a, t74b, t74r, 32u);
        state.regs[0] = t74r;
    // 0x00924e89: 8d4c0424 LEA
        t75 = static_cast<std::uint32_t>(state.regs[4] + state.regs[0] * 1u + 0x00000024u);
        state.regs[1] = t75;
    // 0x00924e8d: 51 PUSH
        batch_guest_pc = 0x00924e8du;
        t76a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e8e: 8d542428 LEA
        t77 = static_cast<std::uint32_t>(state.regs[4] + 0x00000028u);
        state.regs[2] = t77;
    // 0x00924e92: 52 PUSH
        batch_guest_pc = 0x00924e92u;
        t78a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
    // 0x00924e93: 8bce MOV
        t79 = state.regs[6];
        state.regs[1] = t79;
    // 0x00924e95: e8b6df0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924e9au)) return BatchLiftStatus::invalid_memory;
        t80_call_status = spore_lift_00942e50(memory, state);
        if (t80_call_status != BatchLiftStatus::returned) return t80_call_status;
        if (state.eip != 0x00924e9au) return BatchLiftStatus::invalid_control_flow;
    // 0x00924e9a: 8b442410 MOV
        batch_guest_pc = 0x00924e9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t81;
    // 0x00924e9e: f6801c02000002 TEST
        batch_guest_pc = 0x00924e9eu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000021cu), t82a)) return BatchLiftStatus::invalid_memory;
        t82b = 0x00000002u;
        t82r = (t82a & t82b) & 0x000000ffu;
        batch_set_logic_flags(state, t82r, 8u);
    // 0x00924ea5: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924eb4;
    // 0x00924ea7: 8bcd MOV
        t84 = state.regs[5];
        state.regs[1] = t84;
    // 0x00924ea9: e8d2cfc4ff CALL
        if (!batch_guest_call32(memory, state, 0x00571e80u, 0x00924eaeu)) return BatchLiftStatus::invalid_memory;
        t85_call_status = spore_lift_00571e80(memory, state);
        if (t85_call_status != BatchLiftStatus::returned) return t85_call_status;
        if (state.eip != 0x00924eaeu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924eae: 8b6c2410 MOV
        batch_guest_pc = 0x00924eaeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t86;
    // 0x00924eb2: eb02 JMP
        goto L_00924eb6;
    // 0x00924eb4: 8be8 MOV
    L_00924eb4:
        t88 = state.regs[0];
        state.regs[5] = t88;
    // 0x00924eb6: 8b7c2414 MOV
    L_00924eb6:
        batch_guest_pc = 0x00924eb6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t89;
    // 0x00924eba: 8b5c2448 MOV
        batch_guest_pc = 0x00924ebau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t90;
    // 0x00924ebe: f6851c02000008 TEST
    L_00924ebe:
        batch_guest_pc = 0x00924ebeu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000021cu), t91a)) return BatchLiftStatus::invalid_memory;
        t91b = 0x00000008u;
        t91r = (t91a & t91b) & 0x000000ffu;
        batch_set_logic_flags(state, t91r, 8u);
    // 0x00924ec5: 7453 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924f1a;
    // 0x00924ec7: 6a00 PUSH
        batch_guest_pc = 0x00924ec7u;
        t93a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ec9: ff155cc53c01 CALL
        t94_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_time64", 0x013cc55cu, 0x00924ecfu);
        if (t94_call_status != BatchLiftStatus::returned) return t94_call_status;
        if (state.eip != 0x00924ecfu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924ecf: 8d4c2420 LEA
        t95 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[1] = t95;
    // 0x00924ed3: 51 PUSH
        batch_guest_pc = 0x00924ed3u;
        t96a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ed4: 89442424 MOV
        batch_guest_pc = 0x00924ed4u;
        t97 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t97)) return BatchLiftStatus::invalid_memory;
    // 0x00924ed8: 89542428 MOV
        batch_guest_pc = 0x00924ed8u;
        t98 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00924edc: ff15e0c33c01 CALL
        t99_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_localtime64", 0x013cc3e0u, 0x00924ee2u);
        if (t99_call_status != BatchLiftStatus::returned) return t99_call_status;
        if (state.eip != 0x00924ee2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924ee2: 50 PUSH
        batch_guest_pc = 0x00924ee2u;
        t100a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t100a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ee3: 68b8df4301 PUSH
        batch_guest_pc = 0x00924ee3u;
        t101a = 0x0143dfb8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ee8: 8d542434 LEA
        t102 = static_cast<std::uint32_t>(state.regs[4] + 0x00000034u);
        state.regs[2] = t102;
    // 0x00924eec: 6a20 PUSH
        batch_guest_pc = 0x00924eecu;
        t103a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00924eee: 52 PUSH
        batch_guest_pc = 0x00924eeeu;
        t104a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
    // 0x00924eef: ff15dcc33c01 CALL
        t105_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strftime", 0x013cc3dcu, 0x00924ef5u);
        if (t105_call_status != BatchLiftStatus::returned) return t105_call_status;
        if (state.eip != 0x00924ef5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924ef5: 8d44243c LEA
        t106 = static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu);
        state.regs[0] = t106;
    // 0x00924ef9: 83c418 ADD
        t107a = state.regs[4];
        t107b = 0x00000018u;
        t107r = static_cast<std::uint32_t>(t107a + t107b) & 0xffffffffu;
        batch_set_add_flags(state, t107a, t107b, t107r, 32u);
        state.regs[4] = t107r;
    // 0x00924efc: 8d5001 LEA
        t108 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t108;
    // 0x00924eff: 90 NOP
    // 0x00924f00: 8a08 MOV
    L_00924f00:
        batch_guest_pc = 0x00924f00u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t110 << 0u) & 0x000000ffu);
    // 0x00924f02: 40 INC
        t111a = state.regs[0];
        t111r = static_cast<std::uint32_t>(t111a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t111a, t111r, 32u);
        state.regs[0] = t111r;
    // 0x00924f03: 84c9 TEST
        t112a = state.regs[1] & 0x000000ffu;
        t112b = state.regs[1] & 0x000000ffu;
        t112r = (t112a & t112b) & 0x000000ffu;
        batch_set_logic_flags(state, t112r, 8u);
    // 0x00924f05: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924f00;
    // 0x00924f07: 2bc2 SUB
        t114a = state.regs[0];
        t114b = state.regs[2];
        t114r = static_cast<std::uint32_t>(t114a - t114b) & 0xffffffffu;
        batch_set_sub_flags(state, t114a, t114b, t114r, 32u);
        state.regs[0] = t114r;
    // 0x00924f09: 8d440424 LEA
        t115 = static_cast<std::uint32_t>(state.regs[4] + state.regs[0] * 1u + 0x00000024u);
        state.regs[0] = t115;
    // 0x00924f0d: 50 PUSH
        batch_guest_pc = 0x00924f0du;
        t116a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f0e: 8d4c2428 LEA
        t117 = static_cast<std::uint32_t>(state.regs[4] + 0x00000028u);
        state.regs[1] = t117;
    // 0x00924f12: 51 PUSH
        batch_guest_pc = 0x00924f12u;
        t118a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f13: 8bce MOV
        t119 = state.regs[6];
        state.regs[1] = t119;
    // 0x00924f15: e836df0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924f1au)) return BatchLiftStatus::invalid_memory;
        t120_call_status = spore_lift_00942e50(memory, state);
        if (t120_call_status != BatchLiftStatus::returned) return t120_call_status;
        if (state.eip != 0x00924f1au) return BatchLiftStatus::invalid_control_flow;
    // 0x00924f1a: f6851c02000010 TEST
    L_00924f1a:
        batch_guest_pc = 0x00924f1au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000021cu), t121a)) return BatchLiftStatus::invalid_memory;
        t121b = 0x00000010u;
        t121r = (t121a & t121b) & 0x000000ffu;
        batch_set_logic_flags(state, t121r, 8u);
    // 0x00924f21: 742e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924f51;
    // 0x00924f23: 8b4f10 MOV
        batch_guest_pc = 0x00924f23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t123)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t123;
    // 0x00924f26: 8bc1 MOV
        t124 = state.regs[1];
        state.regs[0] = t124;
    // 0x00924f28: 8d7801 LEA
        t125 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[7] = t125;
    // 0x00924f2b: eb03 JMP
        goto L_00924f30;
    // 0x00924f30: 8a10 MOV
    L_00924f30:
        batch_guest_pc = 0x00924f30u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t127 << 0u) & 0x000000ffu);
    // 0x00924f32: 40 INC
        t128a = state.regs[0];
        t128r = static_cast<std::uint32_t>(t128a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t128a, t128r, 32u);
        state.regs[0] = t128r;
    // 0x00924f33: 84d2 TEST
        t129a = state.regs[2] & 0x000000ffu;
        t129b = state.regs[2] & 0x000000ffu;
        t129r = (t129a & t129b) & 0x000000ffu;
        batch_set_logic_flags(state, t129r, 8u);
    // 0x00924f35: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924f30;
    // 0x00924f37: 2bc7 SUB
        t131a = state.regs[0];
        t131b = state.regs[7];
        t131r = static_cast<std::uint32_t>(t131a - t131b) & 0xffffffffu;
        batch_set_sub_flags(state, t131a, t131b, t131r, 32u);
        state.regs[0] = t131r;
    // 0x00924f39: 03c1 ADD
        t132a = state.regs[0];
        t132b = state.regs[1];
        t132r = static_cast<std::uint32_t>(t132a + t132b) & 0xffffffffu;
        batch_set_add_flags(state, t132a, t132b, t132r, 32u);
        state.regs[0] = t132r;
    // 0x00924f3b: 50 PUSH
        batch_guest_pc = 0x00924f3bu;
        t133a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t133a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f3c: 51 PUSH
        batch_guest_pc = 0x00924f3cu;
        t134a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t134a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f3d: 8bce MOV
        t135 = state.regs[6];
        state.regs[1] = t135;
    // 0x00924f3f: e80cdf0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924f44u)) return BatchLiftStatus::invalid_memory;
        t136_call_status = spore_lift_00942e50(memory, state);
        if (t136_call_status != BatchLiftStatus::returned) return t136_call_status;
        if (state.eip != 0x00924f44u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924f44: 6a20 PUSH
        batch_guest_pc = 0x00924f44u;
        t137a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t137a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f46: 8bce MOV
        t138 = state.regs[6];
        state.regs[1] = t138;
    // 0x00924f48: e813fdffff CALL
        if (!batch_guest_call32(memory, state, 0x00924c60u, 0x00924f4du)) return BatchLiftStatus::invalid_memory;
        t139_call_status = spore_lift_00924c60(memory, state);
        if (t139_call_status != BatchLiftStatus::returned) return t139_call_status;
        if (state.eip != 0x00924f4du) return BatchLiftStatus::invalid_control_flow;
    // 0x00924f4d: 8b7c2414 MOV
        batch_guest_pc = 0x00924f4du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t140)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t140;
    // 0x00924f51: f6851c02000020 TEST
    L_00924f51:
        batch_guest_pc = 0x00924f51u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[5] + 0x0000021cu), t141a)) return BatchLiftStatus::invalid_memory;
        t141b = 0x00000020u;
        t141r = (t141a & t141b) & 0x000000ffu;
        batch_set_logic_flags(state, t141r, 8u);
    // 0x00924f58: 742f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924f89;
    // 0x00924f5a: 8b13 MOV
        batch_guest_pc = 0x00924f5au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t143)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t143;
    // 0x00924f5c: 8b4208 MOV
        batch_guest_pc = 0x00924f5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t144)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t144;
    // 0x00924f5f: 8bcb MOV
        t145 = state.regs[3];
        state.regs[1] = t145;
    // 0x00924f61: ffd0 CALL
        t146_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924f63u);
        if (t146_call_status != BatchLiftStatus::returned) return t146_call_status;
    // 0x00924f63: 8bc8 MOV
        t147 = state.regs[0];
        state.regs[1] = t147;
    // 0x00924f65: 8d7901 LEA
        t148 = static_cast<std::uint32_t>(state.regs[1] + 0x00000001u);
        state.regs[7] = t148;
    // 0x00924f68: 8a11 MOV
    L_00924f68:
        batch_guest_pc = 0x00924f68u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t149)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = (state.regs[2] & 0xffffff00u) | ((t149 << 0u) & 0x000000ffu);
    // 0x00924f6a: 41 INC
        t150a = state.regs[1];
        t150r = static_cast<std::uint32_t>(t150a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t150a, t150r, 32u);
        state.regs[1] = t150r;
    // 0x00924f6b: 84d2 TEST
        t151a = state.regs[2] & 0x000000ffu;
        t151b = state.regs[2] & 0x000000ffu;
        t151r = (t151a & t151b) & 0x000000ffu;
        batch_set_logic_flags(state, t151r, 8u);
    // 0x00924f6d: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924f68;
    // 0x00924f6f: 2bcf SUB
        t153a = state.regs[1];
        t153b = state.regs[7];
        t153r = static_cast<std::uint32_t>(t153a - t153b) & 0xffffffffu;
        batch_set_sub_flags(state, t153a, t153b, t153r, 32u);
        state.regs[1] = t153r;
    // 0x00924f71: 03c8 ADD
        t154a = state.regs[1];
        t154b = state.regs[0];
        t154r = static_cast<std::uint32_t>(t154a + t154b) & 0xffffffffu;
        batch_set_add_flags(state, t154a, t154b, t154r, 32u);
        state.regs[1] = t154r;
    // 0x00924f73: 51 PUSH
        batch_guest_pc = 0x00924f73u;
        t155a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t155a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f74: 50 PUSH
        batch_guest_pc = 0x00924f74u;
        t156a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t156a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f75: 8bce MOV
        t157 = state.regs[6];
        state.regs[1] = t157;
    // 0x00924f77: e8d4de0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924f7cu)) return BatchLiftStatus::invalid_memory;
        t158_call_status = spore_lift_00942e50(memory, state);
        if (t158_call_status != BatchLiftStatus::returned) return t158_call_status;
        if (state.eip != 0x00924f7cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924f7c: 6a20 PUSH
        batch_guest_pc = 0x00924f7cu;
        t159a = 0x00000020u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t159a)) return BatchLiftStatus::invalid_memory;
    // 0x00924f7e: 8bce MOV
        t160 = state.regs[6];
        state.regs[1] = t160;
    // 0x00924f80: e8dbfcffff CALL
        if (!batch_guest_call32(memory, state, 0x00924c60u, 0x00924f85u)) return BatchLiftStatus::invalid_memory;
        t161_call_status = spore_lift_00924c60(memory, state);
        if (t161_call_status != BatchLiftStatus::returned) return t161_call_status;
        if (state.eip != 0x00924f85u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924f85: 8b7c2414 MOV
        batch_guest_pc = 0x00924f85u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t162;
    // 0x00924f89: 8b442418 MOV
    L_00924f89:
        batch_guest_pc = 0x00924f89u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t163)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t163;
    // 0x00924f8d: 8d5001 LEA
        t164 = static_cast<std::uint32_t>(state.regs[0] + 0x00000001u);
        state.regs[2] = t164;
    // 0x00924f90: 8a08 MOV
    L_00924f90:
        batch_guest_pc = 0x00924f90u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t165)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t165 << 0u) & 0x000000ffu);
    // 0x00924f92: 40 INC
        t166a = state.regs[0];
        t166r = static_cast<std::uint32_t>(t166a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t166a, t166r, 32u);
        state.regs[0] = t166r;
    // 0x00924f93: 84c9 TEST
        t167a = state.regs[1] & 0x000000ffu;
        t167b = state.regs[1] & 0x000000ffu;
        t167r = (t167a & t167b) & 0x000000ffu;
        batch_set_logic_flags(state, t167r, 8u);
    // 0x00924f95: 75f9 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924f90;
    // 0x00924f97: 8b4c2418 MOV
        batch_guest_pc = 0x00924f97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t169)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t169;
    // 0x00924f9b: 2bc2 SUB
        t170a = state.regs[0];
        t170b = state.regs[2];
        t170r = static_cast<std::uint32_t>(t170a - t170b) & 0xffffffffu;
        batch_set_sub_flags(state, t170a, t170b, t170r, 32u);
        state.regs[0] = t170r;
    // 0x00924f9d: 03c1 ADD
        t171a = state.regs[0];
        t171b = state.regs[1];
        t171r = static_cast<std::uint32_t>(t171a + t171b) & 0xffffffffu;
        batch_set_add_flags(state, t171a, t171b, t171r, 32u);
        state.regs[0] = t171r;
    // 0x00924f9f: 50 PUSH
        batch_guest_pc = 0x00924f9fu;
        t172a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t172a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fa0: 51 PUSH
        batch_guest_pc = 0x00924fa0u;
        t173a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t173a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fa1: 8bce MOV
        t174 = state.regs[6];
        state.regs[1] = t174;
    // 0x00924fa3: e8a8de0100 CALL
        if (!batch_guest_call32(memory, state, 0x00942e50u, 0x00924fa8u)) return BatchLiftStatus::invalid_memory;
        t175_call_status = spore_lift_00942e50(memory, state);
        if (t175_call_status != BatchLiftStatus::returned) return t175_call_status;
        if (state.eip != 0x00924fa8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924fa8: 8b4604 MOV
        batch_guest_pc = 0x00924fa8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t176)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t176;
    // 0x00924fab: 2b06 SUB
        batch_guest_pc = 0x00924fabu;
        t177a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t177b)) return BatchLiftStatus::invalid_memory;
        t177r = static_cast<std::uint32_t>(t177a - t177b) & 0xffffffffu;
        batch_set_sub_flags(state, t177a, t177b, t177r, 32u);
        state.regs[0] = t177r;
    // 0x00924fad: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924fb8;
    // 0x00924faf: 8b0e MOV
        batch_guest_pc = 0x00924fafu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t179)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t179;
    // 0x00924fb1: 807c01ff0a CMP
        batch_guest_pc = 0x00924fb1u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + state.regs[0] * 1u + 0xffffffffu), t180a)) return BatchLiftStatus::invalid_memory;
        t180b = 0x0000000au;
        t180r = static_cast<std::uint32_t>(t180a - t180b) & 0x000000ffu;
        batch_set_sub_flags(state, t180a, t180b, t180r, 8u);
    // 0x00924fb6: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924fc1;
    // 0x00924fb8: 6a0a PUSH
    L_00924fb8:
        batch_guest_pc = 0x00924fb8u;
        t182a = 0x0000000au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t182a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fba: 8bce MOV
        t183 = state.regs[6];
        state.regs[1] = t183;
    // 0x00924fbc: e89ffcffff CALL
        if (!batch_guest_call32(memory, state, 0x00924c60u, 0x00924fc1u)) return BatchLiftStatus::invalid_memory;
        t184_call_status = spore_lift_00924c60(memory, state);
        if (t184_call_status != BatchLiftStatus::returned) return t184_call_status;
        if (state.eip != 0x00924fc1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924fc1: 8b570c MOV
    L_00924fc1:
        batch_guest_pc = 0x00924fc1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu), t185)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t185;
    // 0x00924fc4: 3b9520020000 CMP
        batch_guest_pc = 0x00924fc4u;
        t186a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000220u), t186b)) return BatchLiftStatus::invalid_memory;
        t186r = static_cast<std::uint32_t>(t186a - t186b) & 0xffffffffu;
        batch_set_sub_flags(state, t186a, t186b, t186r, 32u);
    // 0x00924fca: 7c1a JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00924fe6;
    // 0x00924fcc: 8b471c MOV
        batch_guest_pc = 0x00924fccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t188)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t188;
    // 0x00924fcf: 8b4f18 MOV
        batch_guest_pc = 0x00924fcfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000018u), t189)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t189;
    // 0x00924fd2: 8b5714 MOV
        batch_guest_pc = 0x00924fd2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t190)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t190;
    // 0x00924fd5: 50 PUSH
        batch_guest_pc = 0x00924fd5u;
        t191a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t191a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fd6: 51 PUSH
        batch_guest_pc = 0x00924fd6u;
        t192a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t192a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fd7: 52 PUSH
        batch_guest_pc = 0x00924fd7u;
        t193a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t193a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fd8: 68acdf4301 PUSH
        batch_guest_pc = 0x00924fd8u;
        t194a = 0x0143dfacu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t194a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fdd: 56 PUSH
        batch_guest_pc = 0x00924fddu;
        t195a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t195a)) return BatchLiftStatus::invalid_memory;
    // 0x00924fde: e8ddedffff CALL
        if (!batch_guest_call32(memory, state, 0x00923dc0u, 0x00924fe3u)) return BatchLiftStatus::invalid_memory;
        t196_call_status = spore_lift_00923dc0(memory, state);
        if (t196_call_status != BatchLiftStatus::returned) return t196_call_status;
        if (state.eip != 0x00924fe3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924fe3: 83c414 ADD
        t197a = state.regs[4];
        t197b = 0x00000014u;
        t197r = static_cast<std::uint32_t>(t197a + t197b) & 0xffffffffu;
        batch_set_add_flags(state, t197a, t197b, t197r, 32u);
        state.regs[4] = t197r;
    // 0x00924fe6: 8b06 MOV
    L_00924fe6:
        batch_guest_pc = 0x00924fe6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t198)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t198;
    // 0x00924fe8: 5e POP
        batch_guest_pc = 0x00924fe8u;
        if (!memory.load32(state.regs[4], t199a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t199a;
    // 0x00924fe9: 5f POP
    L_00924fe9:
        batch_guest_pc = 0x00924fe9u;
        if (!memory.load32(state.regs[4], t200a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t200a;
    // 0x00924fea: 5d POP
        batch_guest_pc = 0x00924feau;
        if (!memory.load32(state.regs[4], t201a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t201a;
    // 0x00924feb: 5b POP
        batch_guest_pc = 0x00924febu;
        if (!memory.load32(state.regs[4], t202a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t202a;
    // 0x00924fec: 83c434 ADD
        t203a = state.regs[4];
        t203b = 0x00000034u;
        t203r = static_cast<std::uint32_t>(t203a + t203b) & 0xffffffffu;
        batch_set_add_flags(state, t203a, t203b, t203r, 32u);
        state.regs[4] = t203r;
    // 0x00924fef: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
