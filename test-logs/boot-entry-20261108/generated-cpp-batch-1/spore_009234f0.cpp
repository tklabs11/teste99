#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923609(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00938400(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009234f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009234f0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53 = 0;
    BatchLiftStatus t54_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t55 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0, t64b = 0, t64r = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0;
    BatchLiftStatus t69_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76a = 0;
    BatchLiftStatus t77_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85a = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t90a = 0, t90b = 0, t90r = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99 = 0;
    BatchLiftStatus t100_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t101 = 0;
    std::uint32_t t103 = 0;
    std::uint32_t t104 = 0;
    BatchLiftStatus t105_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0;
    std::uint32_t t110a = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;

    // 0x009234f0: 81ec08010000 SUB
        t0a = state.regs[4];
        t0b = 0x00000108u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009234f6: 53 PUSH
        batch_guest_pc = 0x009234f6u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009234f7: 56 PUSH
        batch_guest_pc = 0x009234f7u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009234f8: 57 PUSH
        batch_guest_pc = 0x009234f8u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009234f9: 8bbc241c010000 MOV
        batch_guest_pc = 0x009234f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000011cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t4;
    // 0x00923500: 33db XOR
        t5a = state.regs[3];
        t5b = state.regs[3];
        t5r = (t5a ^ t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[3] = t5r;
    // 0x00923502: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x00923504: 3bfb CMP
        t7a = state.regs[7];
        t7b = state.regs[3];
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00923506: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923516;
    // 0x00923508: 5f POP
        batch_guest_pc = 0x00923508u;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t9a;
    // 0x00923509: 5e POP
        batch_guest_pc = 0x00923509u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x0092350a: 33c0 XOR
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a ^ t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[0] = t11r;
    // 0x0092350c: 5b POP
        batch_guest_pc = 0x0092350cu;
        if (!memory.load32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t12a;
    // 0x0092350d: 81c408010000 ADD
        t13a = state.regs[4];
        t13b = 0x00000108u;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[4] = t13r;
    // 0x00923513: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923516: 55 PUSH
    L_00923516:
        batch_guest_pc = 0x00923516u;
        t15a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00923517: 8d6e34 LEA
        t16 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[5] = t16;
    // 0x0092351a: 6878dc4301 PUSH
        batch_guest_pc = 0x0092351au;
        t17a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x0092351f: 8bcd MOV
        t18 = state.regs[5];
        state.regs[1] = t18;
    // 0x00923521: 896c2414 MOV
        batch_guest_pc = 0x00923521u;
        t19 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00923525: e886ecffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0092352au)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_009221b0(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x0092352au) return BatchLiftStatus::invalid_control_flow;
    // 0x0092352a: 385e04 CMP
        batch_guest_pc = 0x0092352au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t21a)) return BatchLiftStatus::invalid_memory;
        t21b = state.regs[3] & 0x000000ffu;
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0x000000ffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 8u);
    // 0x0092352d: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923545;
    // 0x0092352f: 8bcd MOV
        t23 = state.regs[5];
        state.regs[1] = t23;
    // 0x00923531: e83aedffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00923536u)) return BatchLiftStatus::invalid_memory;
        t24_call_status = spore_lift_00922270(memory, state);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00923536u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923536: 5d POP
        batch_guest_pc = 0x00923536u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t25a;
    // 0x00923537: 5f POP
        batch_guest_pc = 0x00923537u;
        if (!memory.load32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t26a;
    // 0x00923538: 5e POP
        batch_guest_pc = 0x00923538u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00923539: 33c0 XOR
        t28a = state.regs[0];
        t28b = state.regs[0];
        t28r = (t28a ^ t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
        state.regs[0] = t28r;
    // 0x0092353b: 5b POP
        batch_guest_pc = 0x0092353bu;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t29a;
    // 0x0092353c: 81c408010000 ADD
        t30a = state.regs[4];
        t30b = 0x00000108u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x00923542: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923545: 8bac2424010000 MOV
    L_00923545:
        batch_guest_pc = 0x00923545u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000124u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t32;
    // 0x0092354c: 55 PUSH
        batch_guest_pc = 0x0092354cu;
        t33a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x0092354d: 57 PUSH
        batch_guest_pc = 0x0092354du;
        t34a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x0092354e: 8d442420 LEA
        t35 = static_cast<std::uint32_t>(state.regs[4] + 0x00000020u);
        state.regs[0] = t35;
    // 0x00923552: 6800010000 PUSH
        batch_guest_pc = 0x00923552u;
        t36a = 0x00000100u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00923557: 50 PUSH
        batch_guest_pc = 0x00923557u;
        t37a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00923558: e8a34e0100 CALL
        if (!batch_guest_call32(memory, state, 0x00938400u, 0x0092355du)) return BatchLiftStatus::invalid_memory;
        t38_call_status = spore_lift_00938400(memory, state);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x0092355du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092355d: 83c410 ADD
        t39a = state.regs[4];
        t39b = 0x00000010u;
        t39r = static_cast<std::uint32_t>(t39a + t39b) & 0xffffffffu;
        batch_set_add_flags(state, t39a, t39b, t39r, 32u);
        state.regs[4] = t39r;
    // 0x00923560: 83f8ff CMP
        t40a = state.regs[0];
        t40b = 0xffffffffu;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x00923563: 889c2417010000 MOV
        batch_guest_pc = 0x00923563u;
        t41 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000117u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0092356a: 0f8c97000000 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00923607;
    // 0x00923570: 3bc3 CMP
        t43a = state.regs[0];
        t43b = state.regs[3];
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
    // 0x00923572: 7c59 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009235cd;
    // 0x00923574: 3d00010000 CMP
        t45a = state.regs[0];
        t45b = 0x00000100u;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
    // 0x00923579: 7d1a JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00923595;
    // 0x0092357b: 8b8c241c010000 MOV
        batch_guest_pc = 0x0092357bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000011cu), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t47;
    // 0x00923582: 8b16 MOV
        batch_guest_pc = 0x00923582u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00923584: 8b5210 MOV
        batch_guest_pc = 0x00923584u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t49;
    // 0x00923587: 8d442418 LEA
        t50 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[0] = t50;
    // 0x0092358b: 50 PUSH
        batch_guest_pc = 0x0092358bu;
        t51a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x0092358c: 51 PUSH
        batch_guest_pc = 0x0092358cu;
        t52a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x0092358d: 8bce MOV
        t53 = state.regs[6];
        state.regs[1] = t53;
    // 0x0092358f: ffd2 CALL
        t54_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00923591u);
        if (t54_call_status != BatchLiftStatus::returned) return t54_call_status;
    // 0x00923591: 8bf0 MOV
        t55 = state.regs[0];
        state.regs[6] = t55;
    // 0x00923593: eb74 JMP
        goto L_00923609;
    // 0x00923595: 8b4e0c MOV
    L_00923595:
        batch_guest_pc = 0x00923595u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t57;
    // 0x00923598: 3bc8 CMP
        t58a = state.regs[1];
        t58b = state.regs[0];
        t58r = static_cast<std::uint32_t>(t58a - t58b) & 0xffffffffu;
        batch_set_sub_flags(state, t58a, t58b, t58r, 32u);
    // 0x0092359a: 7f31 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_009235cd;
    // 0x0092359c: 7d0e JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009235ac;
    // 0x0092359e: 8bff MOV
        t61 = state.regs[7];
        state.regs[7] = t61;
    // 0x009235a0: 8b4e0c MOV
    L_009235a0:
        batch_guest_pc = 0x009235a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x009235a3: 03c9 ADD
        t63a = state.regs[1];
        t63b = state.regs[1];
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        state.regs[1] = t63r;
    // 0x009235a5: 3bc8 CMP
        t64a = state.regs[1];
        t64b = state.regs[0];
        t64r = static_cast<std::uint32_t>(t64a - t64b) & 0xffffffffu;
        batch_set_sub_flags(state, t64a, t64b, t64r, 32u);
    // 0x009235a7: 894e0c MOV
        batch_guest_pc = 0x009235a7u;
        t65 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t65)) return BatchLiftStatus::invalid_memory;
    // 0x009235aa: 7cf4 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_009235a0;
    // 0x009235ac: 8b5608 MOV
    L_009235ac:
        batch_guest_pc = 0x009235acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t67;
    // 0x009235af: 52 PUSH
        batch_guest_pc = 0x009235afu;
        t68a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x009235b0: e8cb3d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009235b5u)) return BatchLiftStatus::invalid_memory;
        t69_call_status = spore_lift_00f47380(memory, state);
        if (t69_call_status != BatchLiftStatus::returned) return t69_call_status;
        if (state.eip != 0x009235b5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009235b5: 8b460c MOV
        batch_guest_pc = 0x009235b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x009235b8: 53 PUSH
        batch_guest_pc = 0x009235b8u;
        t71a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t71a)) return BatchLiftStatus::invalid_memory;
    // 0x009235b9: 53 PUSH
        batch_guest_pc = 0x009235b9u;
        t72a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x009235ba: 53 PUSH
        batch_guest_pc = 0x009235bau;
        t73a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
    // 0x009235bb: 53 PUSH
        batch_guest_pc = 0x009235bbu;
        t74a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
    // 0x009235bc: 688cdc4301 PUSH
        batch_guest_pc = 0x009235bcu;
        t75a = 0x0143dc8cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x009235c1: 50 PUSH
        batch_guest_pc = 0x009235c1u;
        t76a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x009235c2: e8d93d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009235c7u)) return BatchLiftStatus::invalid_memory;
        t77_call_status = spore_lift_00f473a0(memory, state);
        if (t77_call_status != BatchLiftStatus::returned) return t77_call_status;
        if (state.eip != 0x009235c7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009235c7: 83c41c ADD
        t78a = state.regs[4];
        t78b = 0x0000001cu;
        t78r = static_cast<std::uint32_t>(t78a + t78b) & 0xffffffffu;
        batch_set_add_flags(state, t78a, t78b, t78r, 32u);
        state.regs[4] = t78r;
    // 0x009235ca: 894608 MOV
        batch_guest_pc = 0x009235cau;
        t79 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t79)) return BatchLiftStatus::invalid_memory;
    // 0x009235cd: 8b4e0c MOV
    L_009235cd:
        batch_guest_pc = 0x009235cdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t80;
    // 0x009235d0: 8b5608 MOV
        batch_guest_pc = 0x009235d0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t81;
    // 0x009235d3: 55 PUSH
        batch_guest_pc = 0x009235d3u;
        t82a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x009235d4: 57 PUSH
        batch_guest_pc = 0x009235d4u;
        t83a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x009235d5: 51 PUSH
        batch_guest_pc = 0x009235d5u;
        t84a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x009235d6: 52 PUSH
        batch_guest_pc = 0x009235d6u;
        t85a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t85a)) return BatchLiftStatus::invalid_memory;
    // 0x009235d7: e8244e0100 CALL
        if (!batch_guest_call32(memory, state, 0x00938400u, 0x009235dcu)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_00938400(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x009235dcu) return BatchLiftStatus::invalid_control_flow;
    // 0x009235dc: 8b4e08 MOV
        batch_guest_pc = 0x009235dcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x009235df: 8b560c MOV
        batch_guest_pc = 0x009235dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t88;
    // 0x009235e2: 83c410 ADD
        t89a = state.regs[4];
        t89b = 0x00000010u;
        t89r = static_cast<std::uint32_t>(t89a + t89b) & 0xffffffffu;
        batch_set_add_flags(state, t89a, t89b, t89r, 32u);
        state.regs[4] = t89r;
    // 0x009235e5: 83f8ff CMP
        t90a = state.regs[0];
        t90b = 0xffffffffu;
        t90r = static_cast<std::uint32_t>(t90a - t90b) & 0xffffffffu;
        batch_set_sub_flags(state, t90a, t90b, t90r, 32u);
    // 0x009235e8: 885c11ff MOV
        batch_guest_pc = 0x009235e8u;
        t91 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0xffffffffu), t91)) return BatchLiftStatus::invalid_memory;
    // 0x009235ec: 7c19 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00923607;
    // 0x009235ee: 8b4e08 MOV
        batch_guest_pc = 0x009235eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t93;
    // 0x009235f1: 8b06 MOV
        batch_guest_pc = 0x009235f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t94;
    // 0x009235f3: 8b94241c010000 MOV
        batch_guest_pc = 0x009235f3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000011cu), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t95;
    // 0x009235fa: 8b4010 MOV
        batch_guest_pc = 0x009235fau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t96;
    // 0x009235fd: 51 PUSH
        batch_guest_pc = 0x009235fdu;
        t97a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
    // 0x009235fe: 52 PUSH
        batch_guest_pc = 0x009235feu;
        t98a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
    // 0x009235ff: 8bce MOV
        t99 = state.regs[6];
        state.regs[1] = t99;
    // 0x00923601: ffd0 CALL
        t100_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923603u);
        if (t100_call_status != BatchLiftStatus::returned) return t100_call_status;
    // 0x00923603: 8bf0 MOV
        t101 = state.regs[0];
        state.regs[6] = t101;
    // 0x00923605: eb02 JMP
        goto L_00923609;
    // 0x00923607: 8bf3 MOV
    L_00923607:
        t103 = state.regs[3];
        state.regs[6] = t103;
    // 0x00923609: 8b4c2410 MOV
    L_00923609:
        batch_guest_pc = 0x00923609u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t104;
    // 0x0092360d: e85eecffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00923612u)) return BatchLiftStatus::invalid_memory;
        t105_call_status = spore_lift_00922270(memory, state);
        if (t105_call_status != BatchLiftStatus::returned) return t105_call_status;
        if (state.eip != 0x00923612u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923612: 5d POP
        batch_guest_pc = 0x00923612u;
        if (!memory.load32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t106a;
    // 0x00923613: 5f POP
        batch_guest_pc = 0x00923613u;
        if (!memory.load32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t107a;
    // 0x00923614: 8bc6 MOV
        t108 = state.regs[6];
        state.regs[0] = t108;
    // 0x00923616: 5e POP
        batch_guest_pc = 0x00923616u;
        if (!memory.load32(state.regs[4], t109a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t109a;
    // 0x00923617: 5b POP
        batch_guest_pc = 0x00923617u;
        if (!memory.load32(state.regs[4], t110a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t110a;
    // 0x00923618: 81c408010000 ADD
        t111a = state.regs[4];
        t111b = 0x00000108u;
        t111r = static_cast<std::uint32_t>(t111a + t111b) & 0xffffffffu;
        batch_set_add_flags(state, t111a, t111b, t111r, 32u);
        state.regs[4] = t111r;
    // 0x0092361e: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
