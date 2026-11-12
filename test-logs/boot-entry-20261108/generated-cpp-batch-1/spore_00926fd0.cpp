#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009268b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926ab0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926db0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927096(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009270c7(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00926fd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926fd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23c = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t57 = 0;
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
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91 = 0;
    BatchLiftStatus t92_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99 = 0;
    BatchLiftStatus t100_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t101a = 0;
    std::uint32_t t102a = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0, t120b = 0, t120r = 0;
    std::uint32_t t121a = 0, t121r = 0;
    std::uint32_t t122a = 0;
    BatchLiftStatus t123_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t124a = 0;
    std::uint32_t t125a = 0;
    std::uint32_t t126a = 0;
    std::uint32_t t127a = 0;

    // 0x00926fd0: 53 PUSH
        batch_guest_pc = 0x00926fd0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926fd1: 56 PUSH
        batch_guest_pc = 0x00926fd1u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926fd2: 8b74240c MOV
        batch_guest_pc = 0x00926fd2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x00926fd6: 8bd9 MOV
        t3 = state.regs[1];
        state.regs[3] = t3;
    // 0x00926fd8: 85f6 TEST
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00926fda: 0f8457010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927137;
    // 0x00926fe0: 8b4efc MOV
        batch_guest_pc = 0x00926fe0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0xfffffffcu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00926fe3: 8b4304 MOV
        batch_guest_pc = 0x00926fe3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00926fe6: 83c6f8 ADD
        t8a = state.regs[6];
        t8b = 0xfffffff8u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[6] = t8r;
    // 0x00926fe9: 57 PUSH
        batch_guest_pc = 0x00926fe9u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00926fea: 8bf9 MOV
        t10 = state.regs[1];
        state.regs[7] = t10;
    // 0x00926fec: 81e7f8ffff7f AND
        t11a = state.regs[7];
        t11b = 0x7ffffff8u;
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
        state.regs[7] = t11r;
    // 0x00926ff2: 3bf8 CMP
        t12a = state.regs[7];
        t12b = state.regs[0];
        t12r = static_cast<std::uint32_t>(t12a - t12b) & 0xffffffffu;
        batch_set_sub_flags(state, t12a, t12b, t12r, 32u);
    // 0x00926ff4: 7734 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0092702a;
    // 0x00926ff6: 8b9368040000 MOV
        batch_guest_pc = 0x00926ff6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000468u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00926ffc: 85d2 TEST
        t15a = state.regs[2];
        t15b = state.regs[2];
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
    // 0x00926ffe: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927009;
    // 0x00927000: 3bf2 CMP
        t17a = state.regs[6];
        t17b = state.regs[2];
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00927002: 0f92c2 SETC
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((((state.eflags & 0x001u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00927005: 84d2 TEST
        t19a = state.regs[2] & 0x000000ffu;
        t19b = state.regs[2] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x00927007: 7421 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092702a;
    // 0x00927009: 83c801 OR
    L_00927009:
        t21a = state.regs[0];
        t21b = 0x00000001u;
        t21r = (t21a | t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
        state.regs[0] = t21r;
    // 0x0092700c: 894304 MOV
        batch_guest_pc = 0x0092700cu;
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0092700f: c1ef03 SHR
        t23a = state.regs[7];
        t23c = 3u;
        if (t23c != 0u) {
        t23r = static_cast<std::uint32_t>(t23a >> t23c);
        batch_set_shr_flags(state, t23a, t23c, t23r, 32u);
            state.regs[7] = t23r;
        }
    // 0x00927012: 8b0cbb MOV
        batch_guest_pc = 0x00927012u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00927015: 814e0404000080 OR
        batch_guest_pc = 0x00927015u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t25a)) return BatchLiftStatus::invalid_memory;
        t25b = 0x80000004u;
        t25r = (t25a | t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t25r)) return BatchLiftStatus::invalid_memory;
    // 0x0092701c: 8d04bb LEA
        t26 = static_cast<std::uint32_t>(state.regs[3] + state.regs[7] * 4u + 0x00000000u);
        state.regs[0] = t26;
    // 0x0092701f: 894e0c MOV
        batch_guest_pc = 0x0092701fu;
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00927022: 5f POP
        batch_guest_pc = 0x00927022u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t28a;
    // 0x00927023: 8930 MOV
        batch_guest_pc = 0x00927023u;
        t29 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00927025: 5e POP
        batch_guest_pc = 0x00927025u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t30a;
    // 0x00927026: 5b POP
        batch_guest_pc = 0x00927026u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t31a;
    // 0x00927027: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092702a: 55 PUSH
    L_0092702a:
        batch_guest_pc = 0x0092702au;
        t33a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x0092702b: f6c102 TEST
        t34a = state.regs[1] & 0x000000ffu;
        t34b = 0x00000002u;
        t34r = (t34a & t34b) & 0x000000ffu;
        batch_set_logic_flags(state, t34r, 8u);
    // 0x0092702e: 0f85c7000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009270fb;
    // 0x00927034: 8b6c3704 MOV
        batch_guest_pc = 0x00927034u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t36;
    // 0x00927038: 8d0437 LEA
        t37 = static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000000u);
        state.regs[0] = t37;
    // 0x0092703b: 81e5f8ffff7f AND
        t38a = state.regs[5];
        t38b = 0x7ffffff8u;
        t38r = (t38a & t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
        state.regs[5] = t38r;
    // 0x00927041: f6c101 TEST
        t39a = state.regs[1] & 0x000000ffu;
        t39b = 0x00000001u;
        t39r = (t39a & t39b) & 0x000000ffu;
        batch_set_logic_flags(state, t39r, 8u);
    // 0x00927044: 7522 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927068;
    // 0x00927046: 8b0e MOV
        batch_guest_pc = 0x00927046u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t41;
    // 0x00927048: 03f9 ADD
        t42a = state.regs[7];
        t42b = state.regs[1];
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        state.regs[7] = t42r;
    // 0x0092704a: 2bf1 SUB
        t43a = state.regs[6];
        t43b = state.regs[1];
        t43r = static_cast<std::uint32_t>(t43a - t43b) & 0xffffffffu;
        batch_set_sub_flags(state, t43a, t43b, t43r, 32u);
        state.regs[6] = t43r;
    // 0x0092704c: 8bd7 MOV
        t44 = state.regs[7];
        state.regs[2] = t44;
    // 0x0092704e: 83ca01 OR
        t45a = state.regs[2];
        t45b = 0x00000001u;
        t45r = (t45a | t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
        state.regs[2] = t45r;
    // 0x00927051: 895604 MOV
        batch_guest_pc = 0x00927051u;
        t46 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00927054: 8938 MOV
        batch_guest_pc = 0x00927054u;
        t47 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00927056: 8b4e08 MOV
        batch_guest_pc = 0x00927056u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t48;
    // 0x00927059: 8b560c MOV
        batch_guest_pc = 0x00927059u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t49;
    // 0x0092705c: 89510c MOV
        batch_guest_pc = 0x0092705cu;
        t50 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x0092705f: 8b4e0c MOV
        batch_guest_pc = 0x0092705fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00927062: 8b5608 MOV
        batch_guest_pc = 0x00927062u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x00927065: 895108 MOV
        batch_guest_pc = 0x00927065u;
        t53 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00927068: f644280401 TEST
    L_00927068:
        batch_guest_pc = 0x00927068u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + state.regs[5] * 1u + 0x00000004u), t54a)) return BatchLiftStatus::invalid_memory;
        t54b = 0x00000001u;
        t54r = (t54a & t54b) & 0x000000ffu;
        batch_set_logic_flags(state, t54r, 8u);
    // 0x0092706d: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927077;
    // 0x0092706f: 836004fe AND
        batch_guest_pc = 0x0092706fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t56a)) return BatchLiftStatus::invalid_memory;
        t56b = 0xfffffffeu;
        t56r = (t56a & t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t56r)) return BatchLiftStatus::invalid_memory;
    // 0x00927073: 8938 MOV
        batch_guest_pc = 0x00927073u;
        t57 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00927075: eb1f JMP
        goto L_00927096;
    // 0x00927077: 8b4808 MOV
    L_00927077:
        batch_guest_pc = 0x00927077u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t59;
    // 0x0092707a: 8b500c MOV
        batch_guest_pc = 0x0092707au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t60;
    // 0x0092707d: 89510c MOV
        batch_guest_pc = 0x0092707du;
        t61 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t61)) return BatchLiftStatus::invalid_memory;
    // 0x00927080: 8b480c MOV
        batch_guest_pc = 0x00927080u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x00927083: 8b5008 MOV
        batch_guest_pc = 0x00927083u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t63;
    // 0x00927086: 895108 MOV
        batch_guest_pc = 0x00927086u;
        t64 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x00927089: 03fd ADD
        t65a = state.regs[7];
        t65b = state.regs[5];
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[7] = t65r;
    // 0x0092708b: 8bcf MOV
        t66 = state.regs[7];
        state.regs[1] = t66;
    // 0x0092708d: 83c901 OR
        t67a = state.regs[1];
        t67b = 0x00000001u;
        t67r = (t67a | t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
        state.regs[1] = t67r;
    // 0x00927090: 894e04 MOV
        batch_guest_pc = 0x00927090u;
        t68 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00927093: 893c37 MOV
        batch_guest_pc = 0x00927093u;
        t69 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00927096: 8b8b40040000 MOV
    L_00927096:
        batch_guest_pc = 0x00927096u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000440u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t70;
    // 0x0092709c: 3bf1 CMP
        t71a = state.regs[6];
        t71b = state.regs[1];
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
    // 0x0092709e: 7418 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009270b8;
    // 0x009270a0: 3bc1 CMP
        t73a = state.regs[0];
        t73b = state.regs[1];
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
    // 0x009270a2: 7414 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009270b8;
    // 0x009270a4: 8b4b3c MOV
        batch_guest_pc = 0x009270a4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000003cu), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t75;
    // 0x009270a7: 8d4330 LEA
        t76 = static_cast<std::uint32_t>(state.regs[3] + 0x00000030u);
        state.regs[0] = t76;
    // 0x009270aa: 894608 MOV
        batch_guest_pc = 0x009270aau;
        t77 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x009270ad: 894e0c MOV
        batch_guest_pc = 0x009270adu;
        t78 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t78)) return BatchLiftStatus::invalid_memory;
    // 0x009270b0: 89700c MOV
        batch_guest_pc = 0x009270b0u;
        t79 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t79)) return BatchLiftStatus::invalid_memory;
    // 0x009270b3: 897108 MOV
        batch_guest_pc = 0x009270b3u;
        t80 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t80)) return BatchLiftStatus::invalid_memory;
    // 0x009270b6: eb0f JMP
        goto L_009270c7;
    // 0x009270b8: 57 PUSH
    L_009270b8:
        batch_guest_pc = 0x009270b8u;
        t82a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x009270b9: 56 PUSH
        batch_guest_pc = 0x009270b9u;
        t83a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x009270ba: 8bcb MOV
        t84 = state.regs[3];
        state.regs[1] = t84;
    // 0x009270bc: 89b340040000 MOV
        batch_guest_pc = 0x009270bcu;
        t85 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000440u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x009270c2: e8e9f7ffff CALL
        if (!batch_guest_call32(memory, state, 0x009268b0u, 0x009270c7u)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_009268b0(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x009270c7u) return BatchLiftStatus::invalid_control_flow;
    // 0x009270c7: 81ff00000100 CMP
    L_009270c7:
        t87a = state.regs[7];
        t87b = 0x00010000u;
        t87r = static_cast<std::uint32_t>(t87a - t87b) & 0xffffffffu;
        batch_set_sub_flags(state, t87a, t87b, t87r, 32u);
    // 0x009270cd: 7266 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00927135;
    // 0x009270cf: 8d1437 LEA
        t89 = static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000000u);
        state.regs[2] = t89;
    // 0x009270d2: 52 PUSH
        batch_guest_pc = 0x009270d2u;
        t90a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x009270d3: 8bcb MOV
        t91 = state.regs[3];
        state.regs[1] = t91;
    // 0x009270d5: e8d6f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926ab0u, 0x009270dau)) return BatchLiftStatus::invalid_memory;
        t92_call_status = spore_lift_00926ab0(memory, state);
        if (t92_call_status != BatchLiftStatus::returned) return t92_call_status;
        if (state.eip != 0x009270dau) return BatchLiftStatus::invalid_control_flow;
    // 0x009270da: 84c0 TEST
        t93a = state.regs[0] & 0x000000ffu;
        t93b = state.regs[0] & 0x000000ffu;
        t93r = (t93a & t93b) & 0x000000ffu;
        batch_set_logic_flags(state, t93r, 8u);
    // 0x009270dc: 7457 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927135;
    // 0x009270de: 3bbbc8040000 CMP
        batch_guest_pc = 0x009270deu;
        t95a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000004c8u), t95b)) return BatchLiftStatus::invalid_memory;
        t95r = static_cast<std::uint32_t>(t95a - t95b) & 0xffffffffu;
        batch_set_sub_flags(state, t95a, t95b, t95r, 32u);
    // 0x009270e4: 724f JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00927135;
    // 0x009270e6: 8b83cc040000 MOV
        batch_guest_pc = 0x009270e6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x000004ccu), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t97;
    // 0x009270ec: 50 PUSH
        batch_guest_pc = 0x009270ecu;
        t98a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
    // 0x009270ed: 8bcb MOV
        t99 = state.regs[3];
        state.regs[1] = t99;
    // 0x009270ef: e8bcfcffff CALL
        if (!batch_guest_call32(memory, state, 0x00926db0u, 0x009270f4u)) return BatchLiftStatus::invalid_memory;
        t100_call_status = spore_lift_00926db0(memory, state);
        if (t100_call_status != BatchLiftStatus::returned) return t100_call_status;
        if (state.eip != 0x009270f4u) return BatchLiftStatus::invalid_control_flow;
    // 0x009270f4: 5d POP
        batch_guest_pc = 0x009270f4u;
        if (!memory.load32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t101a;
    // 0x009270f5: 5f POP
        batch_guest_pc = 0x009270f5u;
        if (!memory.load32(state.regs[4], t102a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t102a;
    // 0x009270f6: 5e POP
        batch_guest_pc = 0x009270f6u;
        if (!memory.load32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t103a;
    // 0x009270f7: 5b POP
        batch_guest_pc = 0x009270f7u;
        if (!memory.load32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t104a;
    // 0x009270f8: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009270fb: 8b0e MOV
    L_009270fb:
        batch_guest_pc = 0x009270fbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t106;
    // 0x009270fd: 8d6c3910 LEA
        t107 = static_cast<std::uint32_t>(state.regs[1] + state.regs[7] * 1u + 0x00000010u);
        state.regs[5] = t107;
    // 0x00927101: 8bc6 MOV
        t108 = state.regs[6];
        state.regs[0] = t108;
    // 0x00927103: 2bc1 SUB
        t109a = state.regs[0];
        t109b = state.regs[1];
        t109r = static_cast<std::uint32_t>(t109a - t109b) & 0xffffffffu;
        batch_set_sub_flags(state, t109a, t109b, t109r, 32u);
        state.regs[0] = t109r;
    // 0x00927105: 8d4c370c LEA
        t110 = static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x0000000cu);
        state.regs[1] = t110;
    // 0x00927109: 8d543708 LEA
        t111 = static_cast<std::uint32_t>(state.regs[7] + state.regs[6] * 1u + 0x00000008u);
        state.regs[2] = t111;
    // 0x0092710d: 8b32 MOV
        batch_guest_pc = 0x0092710du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t112)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t112;
    // 0x0092710f: 8b39 MOV
        batch_guest_pc = 0x0092710fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t113)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t113;
    // 0x00927111: 897e0c MOV
        batch_guest_pc = 0x00927111u;
        t114 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t114)) return BatchLiftStatus::invalid_memory;
    // 0x00927114: 8b09 MOV
        batch_guest_pc = 0x00927114u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t115;
    // 0x00927116: 8b12 MOV
        batch_guest_pc = 0x00927116u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t116;
    // 0x00927118: 6800800000 PUSH
        batch_guest_pc = 0x00927118u;
        t117a = 0x00008000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x0092711d: 6a00 PUSH
        batch_guest_pc = 0x0092711du;
        t118a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x0092711f: 895108 MOV
        batch_guest_pc = 0x0092711fu;
        t119 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t119)) return BatchLiftStatus::invalid_memory;
    // 0x00927122: 29ab8c040000 SUB
        batch_guest_pc = 0x00927122u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000048cu), t120a)) return BatchLiftStatus::invalid_memory;
        t120b = state.regs[5];
        t120r = static_cast<std::uint32_t>(t120a - t120b) & 0xffffffffu;
        batch_set_sub_flags(state, t120a, t120b, t120r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x0000048cu), t120r)) return BatchLiftStatus::invalid_memory;
    // 0x00927128: ff8b88040000 DEC
        batch_guest_pc = 0x00927128u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000488u), t121a)) return BatchLiftStatus::invalid_memory;
        t121r = static_cast<std::uint32_t>(t121a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t121a, t121r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + 0x00000488u), t121r)) return BatchLiftStatus::invalid_memory;
    // 0x0092712e: 50 PUSH
        batch_guest_pc = 0x0092712eu;
        t122a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t122a)) return BatchLiftStatus::invalid_memory;
    // 0x0092712f: ff15c4c13c01 CALL
        t123_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualFree", 0x013cc1c4u, 0x00927135u);
        if (t123_call_status != BatchLiftStatus::returned) return t123_call_status;
        if (state.eip != 0x00927135u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927135: 5d POP
    L_00927135:
        batch_guest_pc = 0x00927135u;
        if (!memory.load32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t124a;
    // 0x00927136: 5f POP
        batch_guest_pc = 0x00927136u;
        if (!memory.load32(state.regs[4], t125a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t125a;
    // 0x00927137: 5e POP
    L_00927137:
        batch_guest_pc = 0x00927137u;
        if (!memory.load32(state.regs[4], t126a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t126a;
    // 0x00927138: 5b POP
        batch_guest_pc = 0x00927138u;
        if (!memory.load32(state.regs[4], t127a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t127a;
    // 0x00927139: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
