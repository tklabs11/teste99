#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923bc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924600(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924b0c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924b69(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924ba8(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924a80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924a80u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    BatchLiftStatus t55_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0;
    BatchLiftStatus t70_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t76a = 0;
    BatchLiftStatus t77_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t79a = 0;
    std::uint32_t t80a = 0;
    BatchLiftStatus t81_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t82a = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    BatchLiftStatus t90_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0;
    BatchLiftStatus t97_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101a = 0, t101b = 0, t101r = 0;
    std::uint32_t t103a = 0;
    BatchLiftStatus t104_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t106a = 0;
    std::uint32_t t107a = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110a = 0, t110b = 0, t110r = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113a = 0;
    std::uint32_t t114a = 0;
    std::uint32_t t115 = 0;
    BatchLiftStatus t116_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0;
    std::uint32_t t119a = 0, t119b = 0, t119r = 0;

    // 0x00924a80: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00924a83: 56 PUSH
        batch_guest_pc = 0x00924a83u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a84: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00924a86: 8d4e38 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[1] = t3;
    // 0x00924a89: 6878dc4301 PUSH
        batch_guest_pc = 0x00924a89u;
        t4a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a8e: 894c240c MOV
        batch_guest_pc = 0x00924a8eu;
        t5 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00924a92: e819d7ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00924a97u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00924a97u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a97: 8b442410 MOV
        batch_guest_pc = 0x00924a97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00924a9b: c644240701 MOV
        batch_guest_pc = 0x00924a9bu;
        t8 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00924aa0: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00924aa2: 0f848b000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b33;
    // 0x00924aa8: 8b16 MOV
        batch_guest_pc = 0x00924aa8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t11;
    // 0x00924aaa: 8b522c MOV
        batch_guest_pc = 0x00924aaau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000002cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x00924aad: 8d4c2410 LEA
        t13 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t13;
    // 0x00924ab1: 51 PUSH
        batch_guest_pc = 0x00924ab1u;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ab2: 50 PUSH
        batch_guest_pc = 0x00924ab2u;
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ab3: 8bce MOV
        t16 = state.regs[6];
        state.regs[1] = t16;
    // 0x00924ab5: c744241800000000 MOV
        batch_guest_pc = 0x00924ab5u;
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00924abd: ffd2 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924abfu);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x00924abf: 84c0 TEST
        t19a = state.regs[0] & 0x000000ffu;
        t19b = state.regs[0] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x00924ac1: 7444 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b07;
    // 0x00924ac3: 8b4c2410 MOV
        batch_guest_pc = 0x00924ac3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t21;
    // 0x00924ac7: 8b01 MOV
        batch_guest_pc = 0x00924ac7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x00924ac9: 8b5030 MOV
        batch_guest_pc = 0x00924ac9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x00924acc: ffd2 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924aceu);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x00924ace: 85c0 TEST
        t25a = state.regs[0];
        t25b = state.regs[0];
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
    // 0x00924ad0: 743a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b0c;
    // 0x00924ad2: 8b10 MOV
        batch_guest_pc = 0x00924ad2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x00924ad4: 8bc8 MOV
        t28 = state.regs[0];
        state.regs[1] = t28;
    // 0x00924ad6: 8b420c MOV
        batch_guest_pc = 0x00924ad6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x00924ad9: 68fe259e2e PUSH
        batch_guest_pc = 0x00924ad9u;
        t30a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ade: ffd0 CALL
        t31_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924ae0u);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
    // 0x00924ae0: 8bc8 MOV
        t32 = state.regs[0];
        state.regs[1] = t32;
    // 0x00924ae2: 85c9 TEST
        t33a = state.regs[1];
        t33b = state.regs[1];
        t33r = (t33a & t33b) & 0xffffffffu;
        batch_set_logic_flags(state, t33r, 32u);
    // 0x00924ae4: 7426 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b0c;
    // 0x00924ae6: 8b442418 MOV
        batch_guest_pc = 0x00924ae6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t35;
    // 0x00924aea: 85c0 TEST
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
    // 0x00924aec: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924afa;
    // 0x00924aee: 8b542414 MOV
        batch_guest_pc = 0x00924aeeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00924af2: 52 PUSH
        batch_guest_pc = 0x00924af2u;
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00924af3: e8c8f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924af8u)) return BatchLiftStatus::invalid_memory;
        t40_call_status = spore_lift_00923bc0(memory, state);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
        if (state.eip != 0x00924af8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924af8: eb12 JMP
        goto L_00924b0c;
    // 0x00924afa: 50 PUSH
    L_00924afa:
        batch_guest_pc = 0x00924afau;
        t42a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00924afb: 8b442418 MOV
        batch_guest_pc = 0x00924afbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00924aff: 50 PUSH
        batch_guest_pc = 0x00924affu;
        t44a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b00: e8fbfaffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924b05u)) return BatchLiftStatus::invalid_memory;
        t45_call_status = spore_lift_00924600(memory, state);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x00924b05u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b05: eb05 JMP
        goto L_00924b0c;
    // 0x00924b07: c644240700 MOV
    L_00924b07:
        batch_guest_pc = 0x00924b07u;
        t47 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00924b0c: 8b4c2410 MOV
    L_00924b0c:
        batch_guest_pc = 0x00924b0cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t48;
    // 0x00924b10: 85c9 TEST
        t49a = state.regs[1];
        t49b = state.regs[1];
        t49r = (t49a & t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
    // 0x00924b12: 0f849a000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924bb2;
    // 0x00924b18: 8b11 MOV
        batch_guest_pc = 0x00924b18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00924b1a: 8b4204 MOV
        batch_guest_pc = 0x00924b1au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t52;
    // 0x00924b1d: ffd0 CALL
        t53_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b1fu);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
    // 0x00924b1f: 8b4c2408 MOV
        batch_guest_pc = 0x00924b1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t54;
    // 0x00924b23: e848d7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924b28u)) return BatchLiftStatus::invalid_memory;
        t55_call_status = spore_lift_00922270(memory, state);
        if (t55_call_status != BatchLiftStatus::returned) return t55_call_status;
        if (state.eip != 0x00924b28u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b28: 8a442407 MOV
        batch_guest_pc = 0x00924b28u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t56 << 0u) & 0x000000ffu);
    // 0x00924b2c: 5e POP
        batch_guest_pc = 0x00924b2cu;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t57a;
    // 0x00924b2d: 83c408 ADD
        t58a = state.regs[4];
        t58b = 0x00000008u;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x00924b30: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00924b33: 8b4e2c MOV
    L_00924b33:
        batch_guest_pc = 0x00924b33u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t60;
    // 0x00924b36: 53 PUSH
        batch_guest_pc = 0x00924b36u;
        t61a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b37: 8b5c2418 MOV
        batch_guest_pc = 0x00924b37u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t62;
    // 0x00924b3b: 55 PUSH
        batch_guest_pc = 0x00924b3bu;
        t63a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b3c: 8b6c2420 MOV
        batch_guest_pc = 0x00924b3cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t64;
    // 0x00924b40: 85c9 TEST
        t65a = state.regs[1];
        t65b = state.regs[1];
        t65r = (t65a & t65b) & 0xffffffffu;
        batch_set_logic_flags(state, t65r, 32u);
    // 0x00924b42: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b69;
    // 0x00924b44: 8b11 MOV
        batch_guest_pc = 0x00924b44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t67;
    // 0x00924b46: 8b420c MOV
        batch_guest_pc = 0x00924b46u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t68;
    // 0x00924b49: 68fe259e2e PUSH
        batch_guest_pc = 0x00924b49u;
        t69a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b4e: ffd0 CALL
        t70_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b50u);
        if (t70_call_status != BatchLiftStatus::returned) return t70_call_status;
    // 0x00924b50: 8bc8 MOV
        t71 = state.regs[0];
        state.regs[1] = t71;
    // 0x00924b52: 85c9 TEST
        t72a = state.regs[1];
        t72b = state.regs[1];
        t72r = (t72a & t72b) & 0xffffffffu;
        batch_set_logic_flags(state, t72r, 32u);
    // 0x00924b54: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b69;
    // 0x00924b56: 85ed TEST
        t74a = state.regs[5];
        t74b = state.regs[5];
        t74r = (t74a & t74b) & 0xffffffffu;
        batch_set_logic_flags(state, t74r, 32u);
    // 0x00924b58: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924b62;
    // 0x00924b5a: 53 PUSH
        batch_guest_pc = 0x00924b5au;
        t76a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b5b: e860f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924b60u)) return BatchLiftStatus::invalid_memory;
        t77_call_status = spore_lift_00923bc0(memory, state);
        if (t77_call_status != BatchLiftStatus::returned) return t77_call_status;
        if (state.eip != 0x00924b60u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b60: eb07 JMP
        goto L_00924b69;
    // 0x00924b62: 55 PUSH
    L_00924b62:
        batch_guest_pc = 0x00924b62u;
        t79a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b63: 53 PUSH
        batch_guest_pc = 0x00924b63u;
        t80a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b64: e897faffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924b69u)) return BatchLiftStatus::invalid_memory;
        t81_call_status = spore_lift_00924600(memory, state);
        if (t81_call_status != BatchLiftStatus::returned) return t81_call_status;
        if (state.eip != 0x00924b69u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b69: 57 PUSH
    L_00924b69:
        batch_guest_pc = 0x00924b69u;
        t82a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b6a: 8b7e18 MOV
        batch_guest_pc = 0x00924b6au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t83;
    // 0x00924b6d: 8b761c MOV
        batch_guest_pc = 0x00924b6du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t84;
    // 0x00924b70: 3bfe CMP
        t85a = state.regs[7];
        t85b = state.regs[6];
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
    // 0x00924b72: 743b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924baf;
    // 0x00924b74: 8b0f MOV
    L_00924b74:
        batch_guest_pc = 0x00924b74u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x00924b76: 8b11 MOV
        batch_guest_pc = 0x00924b76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t88;
    // 0x00924b78: 8b4230 MOV
        batch_guest_pc = 0x00924b78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000030u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t89;
    // 0x00924b7b: ffd0 CALL
        t90_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b7du);
        if (t90_call_status != BatchLiftStatus::returned) return t90_call_status;
    // 0x00924b7d: 85c0 TEST
        t91a = state.regs[0];
        t91b = state.regs[0];
        t91r = (t91a & t91b) & 0xffffffffu;
        batch_set_logic_flags(state, t91r, 32u);
    // 0x00924b7f: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924ba8;
    // 0x00924b81: 8b10 MOV
        batch_guest_pc = 0x00924b81u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t93;
    // 0x00924b83: 8bc8 MOV
        t94 = state.regs[0];
        state.regs[1] = t94;
    // 0x00924b85: 8b420c MOV
        batch_guest_pc = 0x00924b85u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t95;
    // 0x00924b88: 68fe259e2e PUSH
        batch_guest_pc = 0x00924b88u;
        t96a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b8d: ffd0 CALL
        t97_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b8fu);
        if (t97_call_status != BatchLiftStatus::returned) return t97_call_status;
    // 0x00924b8f: 8bc8 MOV
        t98 = state.regs[0];
        state.regs[1] = t98;
    // 0x00924b91: 85c9 TEST
        t99a = state.regs[1];
        t99b = state.regs[1];
        t99r = (t99a & t99b) & 0xffffffffu;
        batch_set_logic_flags(state, t99r, 32u);
    // 0x00924b93: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924ba8;
    // 0x00924b95: 85ed TEST
        t101a = state.regs[5];
        t101b = state.regs[5];
        t101r = (t101a & t101b) & 0xffffffffu;
        batch_set_logic_flags(state, t101r, 32u);
    // 0x00924b97: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924ba1;
    // 0x00924b99: 53 PUSH
        batch_guest_pc = 0x00924b99u;
        t103a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b9a: e821f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924b9fu)) return BatchLiftStatus::invalid_memory;
        t104_call_status = spore_lift_00923bc0(memory, state);
        if (t104_call_status != BatchLiftStatus::returned) return t104_call_status;
        if (state.eip != 0x00924b9fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b9f: eb07 JMP
        goto L_00924ba8;
    // 0x00924ba1: 55 PUSH
    L_00924ba1:
        batch_guest_pc = 0x00924ba1u;
        t106a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t106a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ba2: 53 PUSH
        batch_guest_pc = 0x00924ba2u;
        t107a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ba3: e858faffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924ba8u)) return BatchLiftStatus::invalid_memory;
        t108_call_status = spore_lift_00924600(memory, state);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
        if (state.eip != 0x00924ba8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924ba8: 83c704 ADD
    L_00924ba8:
        t109a = state.regs[7];
        t109b = 0x00000004u;
        t109r = static_cast<std::uint32_t>(t109a + t109b) & 0xffffffffu;
        batch_set_add_flags(state, t109a, t109b, t109r, 32u);
        state.regs[7] = t109r;
    // 0x00924bab: 3bfe CMP
        t110a = state.regs[7];
        t110b = state.regs[6];
        t110r = static_cast<std::uint32_t>(t110a - t110b) & 0xffffffffu;
        batch_set_sub_flags(state, t110a, t110b, t110r, 32u);
    // 0x00924bad: 75c5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924b74;
    // 0x00924baf: 5f POP
    L_00924baf:
        batch_guest_pc = 0x00924bafu;
        if (!memory.load32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t112a;
    // 0x00924bb0: 5d POP
        batch_guest_pc = 0x00924bb0u;
        if (!memory.load32(state.regs[4], t113a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t113a;
    // 0x00924bb1: 5b POP
        batch_guest_pc = 0x00924bb1u;
        if (!memory.load32(state.regs[4], t114a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t114a;
    // 0x00924bb2: 8b4c2408 MOV
    L_00924bb2:
        batch_guest_pc = 0x00924bb2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t115;
    // 0x00924bb6: e8b5d6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924bbbu)) return BatchLiftStatus::invalid_memory;
        t116_call_status = spore_lift_00922270(memory, state);
        if (t116_call_status != BatchLiftStatus::returned) return t116_call_status;
        if (state.eip != 0x00924bbbu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924bbb: 8a442407 MOV
        batch_guest_pc = 0x00924bbbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t117)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t117 << 0u) & 0x000000ffu);
    // 0x00924bbf: 5e POP
        batch_guest_pc = 0x00924bbfu;
        if (!memory.load32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t118a;
    // 0x00924bc0: 83c408 ADD
        t119a = state.regs[4];
        t119b = 0x00000008u;
        t119r = static_cast<std::uint32_t>(t119a + t119b) & 0xffffffffu;
        batch_set_add_flags(state, t119a, t119b, t119r, 32u);
        state.regs[4] = t119r;
    // 0x00924bc3: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
