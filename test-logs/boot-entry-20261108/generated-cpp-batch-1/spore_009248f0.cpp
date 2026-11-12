#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924a19(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a0a360(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009248f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009248f0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    BatchLiftStatus t52_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66 = 0;
    BatchLiftStatus t67_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    BatchLiftStatus t72_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    BatchLiftStatus t80_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0;
    std::uint32_t t89 = 0;
    BatchLiftStatus t90_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0;
    std::uint32_t t94 = 0;
    BatchLiftStatus t95_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    BatchLiftStatus t101_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113 = 0;
    BatchLiftStatus t114_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0;
    std::uint32_t t118a = 0;
    BatchLiftStatus t119_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t120 = 0;
    std::uint32_t t121a = 0, t121b = 0, t121r = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    BatchLiftStatus t126_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t127 = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t131 = 0;
    BatchLiftStatus t132_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t133 = 0;
    BatchLiftStatus t134_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t135a = 0;
    std::uint32_t t136a = 0;
    std::uint32_t t137a = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0;
    std::uint32_t t140a = 0, t140b = 0, t140r = 0;

    // 0x009248f0: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x009248f3: 53 PUSH
        batch_guest_pc = 0x009248f3u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f4: 55 PUSH
        batch_guest_pc = 0x009248f4u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f5: 56 PUSH
        batch_guest_pc = 0x009248f5u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f6: 57 PUSH
        batch_guest_pc = 0x009248f6u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009248f7: 8bf9 MOV
        t5 = state.regs[1];
        state.regs[7] = t5;
    // 0x009248f9: 8d6f38 LEA
        t6 = static_cast<std::uint32_t>(state.regs[7] + 0x00000038u);
        state.regs[5] = t6;
    // 0x009248fc: 6878dc4301 PUSH
        batch_guest_pc = 0x009248fcu;
        t7a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00924901: 8bcd MOV
        t8 = state.regs[5];
        state.regs[1] = t8;
    // 0x00924903: 896c2418 MOV
        batch_guest_pc = 0x00924903u;
        t9 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00924907: e8a4d8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x0092490cu)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_009221b0(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x0092490cu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092490c: 8b74241c MOV
        batch_guest_pc = 0x0092490cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x00924910: 8b16 MOV
        batch_guest_pc = 0x00924910u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x00924912: 8b1f MOV
        batch_guest_pc = 0x00924912u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t13;
    // 0x00924914: 8d442410 LEA
        t14 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t14;
    // 0x00924918: 50 PUSH
        batch_guest_pc = 0x00924918u;
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00924919: 8b421c MOV
        batch_guest_pc = 0x00924919u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x0092491c: 8bce MOV
        t17 = state.regs[6];
        state.regs[1] = t17;
    // 0x0092491e: c744241400000000 MOV
        batch_guest_pc = 0x0092491eu;
        t18 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00924926: ffd0 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924928u);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x00924928: 8b532c MOV
        batch_guest_pc = 0x00924928u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x0000002cu), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x0092492b: 50 PUSH
        batch_guest_pc = 0x0092492bu;
        t21a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x0092492c: 8bcf MOV
        t22 = state.regs[7];
        state.regs[1] = t22;
    // 0x0092492e: ffd2 CALL
        t23_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924930u);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
    // 0x00924930: 84c0 TEST
        t24a = state.regs[0] & 0x000000ffu;
        t24b = state.regs[0] & 0x000000ffu;
        t24r = (t24a & t24b) & 0x000000ffu;
        batch_set_logic_flags(state, t24r, 8u);
    // 0x00924932: 742d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924961;
    // 0x00924934: 8b4c2410 MOV
        batch_guest_pc = 0x00924934u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x00924938: 3bce CMP
        t27a = state.regs[1];
        t27b = state.regs[6];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
    // 0x0092493a: 0f84ea000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a2a;
    // 0x00924940: 8b07 MOV
        batch_guest_pc = 0x00924940u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x00924942: 8b5020 MOV
        batch_guest_pc = 0x00924942u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000020u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x00924945: 51 PUSH
        batch_guest_pc = 0x00924945u;
        t31a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00924946: 8bcf MOV
        t32 = state.regs[7];
        state.regs[1] = t32;
    // 0x00924948: ffd2 CALL
        t33_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092494au);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
    // 0x0092494a: 8b4c2410 MOV
        batch_guest_pc = 0x0092494au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t34;
    // 0x0092494e: 85c9 TEST
        t35a = state.regs[1];
        t35b = state.regs[1];
        t35r = (t35a & t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
    // 0x00924950: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924961;
    // 0x00924952: c744241000000000 MOV
        batch_guest_pc = 0x00924952u;
        t37 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0092495a: 8b01 MOV
        batch_guest_pc = 0x0092495au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38;
    // 0x0092495c: 8b5004 MOV
        batch_guest_pc = 0x0092495cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x0092495f: ffd2 CALL
        t40_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924961u);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
    // 0x00924961: 8b06 MOV
    L_00924961:
        batch_guest_pc = 0x00924961u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x00924963: 8b5038 MOV
        batch_guest_pc = 0x00924963u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x00924966: 8bce MOV
        t43 = state.regs[6];
        state.regs[1] = t43;
    // 0x00924968: ffd2 CALL
        t44_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092496au);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
    // 0x0092496a: 85c0 TEST
        t45a = state.regs[0];
        t45b = state.regs[0];
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
    // 0x0092496c: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092499f;
    // 0x0092496e: 8b4f30 MOV
        batch_guest_pc = 0x0092496eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000030u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t47;
    // 0x00924971: 85c9 TEST
        t48a = state.regs[1];
        t48b = state.regs[1];
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
    // 0x00924973: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092499f;
    // 0x00924975: 8b01 MOV
        batch_guest_pc = 0x00924975u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t50;
    // 0x00924977: 8b501c MOV
        batch_guest_pc = 0x00924977u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x0092497a: ffd2 CALL
        t52_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092497cu);
        if (t52_call_status != BatchLiftStatus::returned) return t52_call_status;
    // 0x0092497c: 8bd8 MOV
        t53 = state.regs[0];
        state.regs[3] = t53;
    // 0x0092497e: 8b06 MOV
        batch_guest_pc = 0x0092497eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00924980: 8b501c MOV
        batch_guest_pc = 0x00924980u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t55)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t55;
    // 0x00924983: 8b2b MOV
        batch_guest_pc = 0x00924983u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t56;
    // 0x00924985: 8bce MOV
        t57 = state.regs[6];
        state.regs[1] = t57;
    // 0x00924987: ffd2 CALL
        t58_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924989u);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
    // 0x00924989: 50 PUSH
        batch_guest_pc = 0x00924989u;
        t59a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x0092498a: 8b4514 MOV
        batch_guest_pc = 0x0092498au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x0092498d: 8bcb MOV
        t61 = state.regs[3];
        state.regs[1] = t61;
    // 0x0092498f: ffd0 CALL
        t62_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924991u);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
    // 0x00924991: 8b16 MOV
        batch_guest_pc = 0x00924991u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t63;
    // 0x00924993: 8b4234 MOV
        batch_guest_pc = 0x00924993u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000034u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t64;
    // 0x00924996: 53 PUSH
        batch_guest_pc = 0x00924996u;
        t65a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x00924997: 8bce MOV
        t66 = state.regs[6];
        state.regs[1] = t66;
    // 0x00924999: ffd0 CALL
        t67_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x0092499bu);
        if (t67_call_status != BatchLiftStatus::returned) return t67_call_status;
    // 0x0092499b: 8b6c2414 MOV
        batch_guest_pc = 0x0092499bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t68;
    // 0x0092499f: 8b16 MOV
    L_0092499f:
        batch_guest_pc = 0x0092499fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t69;
    // 0x009249a1: 8b4230 MOV
        batch_guest_pc = 0x009249a1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000030u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x009249a4: 8bce MOV
        t71 = state.regs[6];
        state.regs[1] = t71;
    // 0x009249a6: ffd0 CALL
        t72_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249a8u);
        if (t72_call_status != BatchLiftStatus::returned) return t72_call_status;
    // 0x009249a8: 85c0 TEST
        t73a = state.regs[0];
        t73b = state.regs[0];
        t73r = (t73a & t73b) & 0xffffffffu;
        batch_set_logic_flags(state, t73r, 32u);
    // 0x009249aa: 7531 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009249dd;
    // 0x009249ac: 8b4f2c MOV
        batch_guest_pc = 0x009249acu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000002cu), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t75;
    // 0x009249af: 85c9 TEST
        t76a = state.regs[1];
        t76b = state.regs[1];
        t76r = (t76a & t76b) & 0xffffffffu;
        batch_set_logic_flags(state, t76r, 32u);
    // 0x009249b1: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009249dd;
    // 0x009249b3: 8b11 MOV
        batch_guest_pc = 0x009249b3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t78;
    // 0x009249b5: 8b4220 MOV
        batch_guest_pc = 0x009249b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000020u), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t79;
    // 0x009249b8: ffd0 CALL
        t80_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249bau);
        if (t80_call_status != BatchLiftStatus::returned) return t80_call_status;
    // 0x009249ba: 8b16 MOV
        batch_guest_pc = 0x009249bau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t81;
    // 0x009249bc: 8bd8 MOV
        t82 = state.regs[0];
        state.regs[3] = t82;
    // 0x009249be: 8b421c MOV
        batch_guest_pc = 0x009249beu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000001cu), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t83;
    // 0x009249c1: 8b2b MOV
        batch_guest_pc = 0x009249c1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t84;
    // 0x009249c3: 8bce MOV
        t85 = state.regs[6];
        state.regs[1] = t85;
    // 0x009249c5: ffd0 CALL
        t86_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009249c7u);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
    // 0x009249c7: 8b5518 MOV
        batch_guest_pc = 0x009249c7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t87;
    // 0x009249ca: 50 PUSH
        batch_guest_pc = 0x009249cau;
        t88a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
    // 0x009249cb: 8bcb MOV
        t89 = state.regs[3];
        state.regs[1] = t89;
    // 0x009249cd: ffd2 CALL
        t90_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249cfu);
        if (t90_call_status != BatchLiftStatus::returned) return t90_call_status;
    // 0x009249cf: 8b06 MOV
        batch_guest_pc = 0x009249cfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t91)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t91;
    // 0x009249d1: 8b502c MOV
        batch_guest_pc = 0x009249d1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t92;
    // 0x009249d4: 53 PUSH
        batch_guest_pc = 0x009249d4u;
        t93a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t93a)) return BatchLiftStatus::invalid_memory;
    // 0x009249d5: 8bce MOV
        t94 = state.regs[6];
        state.regs[1] = t94;
    // 0x009249d7: ffd2 CALL
        t95_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249d9u);
        if (t95_call_status != BatchLiftStatus::returned) return t95_call_status;
    // 0x009249d9: 8b6c2414 MOV
        batch_guest_pc = 0x009249d9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t96;
    // 0x009249dd: 8b06 MOV
    L_009249dd:
        batch_guest_pc = 0x009249ddu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t97;
    // 0x009249df: 8b10 MOV
        batch_guest_pc = 0x009249dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t98;
    // 0x009249e1: 8bce MOV
        t99 = state.regs[6];
        state.regs[1] = t99;
    // 0x009249e3: 8974241c MOV
        batch_guest_pc = 0x009249e3u;
        t100 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t100)) return BatchLiftStatus::invalid_memory;
    // 0x009249e7: ffd2 CALL
        t101_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009249e9u);
        if (t101_call_status != BatchLiftStatus::returned) return t101_call_status;
    // 0x009249e9: 8b471c MOV
        batch_guest_pc = 0x009249e9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x0000001cu), t102)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t102;
    // 0x009249ec: 3b4720 CMP
        batch_guest_pc = 0x009249ecu;
        t103a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000020u), t103b)) return BatchLiftStatus::invalid_memory;
        t103r = static_cast<std::uint32_t>(t103a - t103b) & 0xffffffffu;
        batch_set_sub_flags(state, t103a, t103b, t103r, 32u);
    // 0x009249ef: 8d4f18 LEA
        t104 = static_cast<std::uint32_t>(state.regs[7] + 0x00000018u);
        state.regs[1] = t104;
    // 0x009249f2: 7316 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00924a0a;
    // 0x009249f4: 8d5004 LEA
        t106 = static_cast<std::uint32_t>(state.regs[0] + 0x00000004u);
        state.regs[2] = t106;
    // 0x009249f7: 895104 MOV
        batch_guest_pc = 0x009249f7u;
        t107 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t107)) return BatchLiftStatus::invalid_memory;
    // 0x009249fa: 85c0 TEST
        t108a = state.regs[0];
        t108b = state.regs[0];
        t108r = (t108a & t108b) & 0xffffffffu;
        batch_set_logic_flags(state, t108r, 32u);
    // 0x009249fc: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a19;
    // 0x009249fe: 8930 MOV
        batch_guest_pc = 0x009249feu;
        t110 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t110)) return BatchLiftStatus::invalid_memory;
    // 0x00924a00: 8b06 MOV
        batch_guest_pc = 0x00924a00u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t111;
    // 0x00924a02: 8b10 MOV
        batch_guest_pc = 0x00924a02u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t112)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t112;
    // 0x00924a04: 8bce MOV
        t113 = state.regs[6];
        state.regs[1] = t113;
    // 0x00924a06: ffd2 CALL
        t114_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a08u);
        if (t114_call_status != BatchLiftStatus::returned) return t114_call_status;
    // 0x00924a08: eb0f JMP
        goto L_00924a19;
    // 0x00924a0a: 8d54241c LEA
    L_00924a0a:
        t116 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[2] = t116;
    // 0x00924a0e: 52 PUSH
        batch_guest_pc = 0x00924a0eu;
        t117a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a0f: 50 PUSH
        batch_guest_pc = 0x00924a0fu;
        t118a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a10: e84b590e00 CALL
        if (!batch_guest_call32(memory, state, 0x00a0a360u, 0x00924a15u)) return BatchLiftStatus::invalid_memory;
        t119_call_status = spore_lift_00a0a360(memory, state);
        if (t119_call_status != BatchLiftStatus::returned) return t119_call_status;
        if (state.eip != 0x00924a15u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a15: 8b74241c MOV
        batch_guest_pc = 0x00924a15u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t120;
    // 0x00924a19: 85f6 TEST
    L_00924a19:
        t121a = state.regs[6];
        t121b = state.regs[6];
        t121r = (t121a & t121b) & 0xffffffffu;
        batch_set_logic_flags(state, t121r, 32u);
    // 0x00924a1b: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a26;
    // 0x00924a1d: 8b06 MOV
        batch_guest_pc = 0x00924a1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t123)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t123;
    // 0x00924a1f: 8b5004 MOV
        batch_guest_pc = 0x00924a1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t124;
    // 0x00924a22: 8bce MOV
        t125 = state.regs[6];
        state.regs[1] = t125;
    // 0x00924a24: ffd2 CALL
        t126_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a26u);
        if (t126_call_status != BatchLiftStatus::returned) return t126_call_status;
    // 0x00924a26: 8b4c2410 MOV
    L_00924a26:
        batch_guest_pc = 0x00924a26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t127;
    // 0x00924a2a: 85c9 TEST
    L_00924a2a:
        t128a = state.regs[1];
        t128b = state.regs[1];
        t128r = (t128a & t128b) & 0xffffffffu;
        batch_set_logic_flags(state, t128r, 32u);
    // 0x00924a2c: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924a35;
    // 0x00924a2e: 8b01 MOV
        batch_guest_pc = 0x00924a2eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t130)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t130;
    // 0x00924a30: 8b5004 MOV
        batch_guest_pc = 0x00924a30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t131)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t131;
    // 0x00924a33: ffd2 CALL
        t132_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924a35u);
        if (t132_call_status != BatchLiftStatus::returned) return t132_call_status;
    // 0x00924a35: 8bcd MOV
    L_00924a35:
        t133 = state.regs[5];
        state.regs[1] = t133;
    // 0x00924a37: e834d8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924a3cu)) return BatchLiftStatus::invalid_memory;
        t134_call_status = spore_lift_00922270(memory, state);
        if (t134_call_status != BatchLiftStatus::returned) return t134_call_status;
        if (state.eip != 0x00924a3cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a3c: 5f POP
        batch_guest_pc = 0x00924a3cu;
        if (!memory.load32(state.regs[4], t135a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t135a;
    // 0x00924a3d: 5e POP
        batch_guest_pc = 0x00924a3du;
        if (!memory.load32(state.regs[4], t136a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t136a;
    // 0x00924a3e: 5d POP
        batch_guest_pc = 0x00924a3eu;
        if (!memory.load32(state.regs[4], t137a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t137a;
    // 0x00924a3f: b001 MOV
        t138 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t138 << 0u) & 0x000000ffu);
    // 0x00924a41: 5b POP
        batch_guest_pc = 0x00924a41u;
        if (!memory.load32(state.regs[4], t139a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t139a;
    // 0x00924a42: 83c408 ADD
        t140a = state.regs[4];
        t140b = 0x00000008u;
        t140r = static_cast<std::uint32_t>(t140a + t140b) & 0xffffffffu;
        batch_set_add_flags(state, t140a, t140b, t140r, 32u);
        state.regs[4] = t140r;
    // 0x00924a45: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
