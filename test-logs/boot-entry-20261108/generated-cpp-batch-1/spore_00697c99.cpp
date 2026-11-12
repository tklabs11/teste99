#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00697d06(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009233e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009244d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924790(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697c99(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697c99u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    BatchLiftStatus t46_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    BatchLiftStatus t55_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61 = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66a = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68 = 0;
    BatchLiftStatus t69_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75 = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    BatchLiftStatus t90_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    BatchLiftStatus t98_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t99a = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    BatchLiftStatus t102_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t103 = 0;
    std::uint32_t t104a = 0, t104b = 0, t104r = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108 = 0;
    BatchLiftStatus t109_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114a = 0;
    std::uint32_t t115a = 0, t115b = 0, t115r = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118 = 0;
    BatchLiftStatus t119_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t120 = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;

    // 0x00697c99: 8b5e2c MOV
        batch_guest_pc = 0x00697c99u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t0;
    // 0x00697c9c: c744241cffffffff MOV
        batch_guest_pc = 0x00697c9cu;
        t1 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t1)) return BatchLiftStatus::invalid_memory;
    // 0x00697ca4: 3bfb CMP
        t2a = state.regs[7];
        t2b = state.regs[3];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x00697ca6: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cc4;
    // 0x00697ca8: 85ff TEST
        t4a = state.regs[7];
        t4b = state.regs[7];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00697caa: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cb4;
    // 0x00697cac: 8b07 MOV
        batch_guest_pc = 0x00697cacu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00697cae: 8b10 MOV
        batch_guest_pc = 0x00697caeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00697cb0: 8bcf MOV
        t8 = state.regs[7];
        state.regs[1] = t8;
    // 0x00697cb2: ffd2 CALL
        t9_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697cb4u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
    // 0x00697cb4: 897e2c MOV
    L_00697cb4:
        batch_guest_pc = 0x00697cb4u;
        t10 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00697cb7: 85db TEST
        t11a = state.regs[3];
        t11b = state.regs[3];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x00697cb9: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cc4;
    // 0x00697cbb: 8b03 MOV
        batch_guest_pc = 0x00697cbbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00697cbd: 8b5004 MOV
        batch_guest_pc = 0x00697cbdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00697cc0: 8bcb MOV
        t15 = state.regs[3];
        state.regs[1] = t15;
    // 0x00697cc2: ffd2 CALL
        t16_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697cc4u);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
    // 0x00697cc4: 837e3000 CMP
    L_00697cc4:
        batch_guest_pc = 0x00697cc4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t17a)) return BatchLiftStatus::invalid_memory;
        t17b = 0x00000000u;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x00697cc8: 7567 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697cca: 6a00 PUSH
        batch_guest_pc = 0x00697ccau;
        t19a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ccc: 6a00 PUSH
        batch_guest_pc = 0x00697cccu;
        t20a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cce: 6a00 PUSH
        batch_guest_pc = 0x00697cceu;
        t21a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd0: 6a00 PUSH
        batch_guest_pc = 0x00697cd0u;
        t22a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd2: 6870824001 PUSH
        batch_guest_pc = 0x00697cd2u;
        t23a = 0x01408270u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd7: 68580a0000 PUSH
        batch_guest_pc = 0x00697cd7u;
        t24a = 0x00000a58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cdc: e8bff68a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00697ce1u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00f473a0(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00697ce1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697ce1: 83c418 ADD
        t26a = state.regs[4];
        t26b = 0x00000018u;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[4] = t26r;
    // 0x00697ce4: 89442410 MOV
        batch_guest_pc = 0x00697ce4u;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00697ce8: c744241c01000000 MOV
        batch_guest_pc = 0x00697ce8u;
        t28 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00697cf0: 85c0 TEST
        t29a = state.regs[0];
        t29b = state.regs[0];
        t29r = (t29a & t29b) & 0xffffffffu;
        batch_set_logic_flags(state, t29r, 32u);
    // 0x00697cf2: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d04;
    // 0x00697cf4: 685c824001 PUSH
        batch_guest_pc = 0x00697cf4u;
        t31a = 0x0140825cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cf9: 8bc8 MOV
        t32 = state.regs[0];
        state.regs[1] = t32;
    // 0x00697cfb: e8d0c72800 CALL
        if (!batch_guest_call32(memory, state, 0x009244d0u, 0x00697d00u)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_009244d0(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x00697d00u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697d00: 8bf8 MOV
        t34 = state.regs[0];
        state.regs[7] = t34;
    // 0x00697d02: eb02 JMP
        goto L_00697d06;
    // 0x00697d04: 33ff XOR
    L_00697d04:
        t36a = state.regs[7];
        t36b = state.regs[7];
        t36r = (t36a ^ t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
        state.regs[7] = t36r;
    // 0x00697d06: 8b5e30 MOV
    L_00697d06:
        batch_guest_pc = 0x00697d06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t37;
    // 0x00697d09: c744241cffffffff MOV
        batch_guest_pc = 0x00697d09u;
        t38 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00697d11: 3bfb CMP
        t39a = state.regs[7];
        t39b = state.regs[3];
        t39r = static_cast<std::uint32_t>(t39a - t39b) & 0xffffffffu;
        batch_set_sub_flags(state, t39a, t39b, t39r, 32u);
    // 0x00697d13: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d15: 85ff TEST
        t41a = state.regs[7];
        t41b = state.regs[7];
        t41r = (t41a & t41b) & 0xffffffffu;
        batch_set_logic_flags(state, t41r, 32u);
    // 0x00697d17: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d21;
    // 0x00697d19: 8b07 MOV
        batch_guest_pc = 0x00697d19u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00697d1b: 8b10 MOV
        batch_guest_pc = 0x00697d1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t44;
    // 0x00697d1d: 8bcf MOV
        t45 = state.regs[7];
        state.regs[1] = t45;
    // 0x00697d1f: ffd2 CALL
        t46_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d21u);
        if (t46_call_status != BatchLiftStatus::returned) return t46_call_status;
    // 0x00697d21: 897e30 MOV
    L_00697d21:
        batch_guest_pc = 0x00697d21u;
        t47 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00697d24: 85db TEST
        t48a = state.regs[3];
        t48b = state.regs[3];
        t48r = (t48a & t48b) & 0xffffffffu;
        batch_set_logic_flags(state, t48r, 32u);
    // 0x00697d26: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d28: 8b03 MOV
        batch_guest_pc = 0x00697d28u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t50;
    // 0x00697d2a: 8b5004 MOV
        batch_guest_pc = 0x00697d2au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00697d2d: 8bcb MOV
        t52 = state.regs[3];
        state.regs[1] = t52;
    // 0x00697d2f: ffd2 CALL
        t53_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d31u);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
    // 0x00697d31: 8bce MOV
    L_00697d31:
        t54 = state.regs[6];
        state.regs[1] = t54;
    // 0x00697d33: e858ca2800 CALL
        if (!batch_guest_call32(memory, state, 0x00924790u, 0x00697d38u)) return BatchLiftStatus::invalid_memory;
        t55_call_status = spore_lift_00924790(memory, state);
        if (t55_call_status != BatchLiftStatus::returned) return t55_call_status;
        if (state.eip != 0x00697d38u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697d38: 8b06 MOV
        batch_guest_pc = 0x00697d38u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x00697d3a: 8b5030 MOV
        batch_guest_pc = 0x00697d3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t57;
    // 0x00697d3d: 68fb000000 PUSH
        batch_guest_pc = 0x00697d3du;
        t58a = 0x000000fbu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d42: 6a00 PUSH
        batch_guest_pc = 0x00697d42u;
        t59a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d44: 6a00 PUSH
        batch_guest_pc = 0x00697d44u;
        t60a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d46: 8bce MOV
        t61 = state.regs[6];
        state.regs[1] = t61;
    // 0x00697d48: ffd2 CALL
        t62_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d4au);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
    // 0x00697d4a: 8b06 MOV
        batch_guest_pc = 0x00697d4au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t63;
    // 0x00697d4c: 8b5030 MOV
        batch_guest_pc = 0x00697d4cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t64;
    // 0x00697d4f: 6a19 PUSH
        batch_guest_pc = 0x00697d4fu;
        t65a = 0x00000019u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d51: 6a00 PUSH
        batch_guest_pc = 0x00697d51u;
        t66a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t66a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d53: 6850824001 PUSH
        batch_guest_pc = 0x00697d53u;
        t67a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d58: 8bce MOV
        t68 = state.regs[6];
        state.regs[1] = t68;
    // 0x00697d5a: ffd2 CALL
        t69_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d5cu);
        if (t69_call_status != BatchLiftStatus::returned) return t69_call_status;
    // 0x00697d5c: 8b06 MOV
        batch_guest_pc = 0x00697d5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t70;
    // 0x00697d5e: 8b5030 MOV
        batch_guest_pc = 0x00697d5eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t71;
    // 0x00697d61: 6a32 PUSH
        batch_guest_pc = 0x00697d61u;
        t72a = 0x00000032u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d63: 6a00 PUSH
        batch_guest_pc = 0x00697d63u;
        t73a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d65: 6840824001 PUSH
        batch_guest_pc = 0x00697d65u;
        t74a = 0x01408240u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d6a: 8bce MOV
        t75 = state.regs[6];
        state.regs[1] = t75;
    // 0x00697d6c: ffd2 CALL
        t76_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d6eu);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
    // 0x00697d6e: c744240c00000000 MOV
        batch_guest_pc = 0x00697d6eu;
        t77 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00697d76: 8b06 MOV
        batch_guest_pc = 0x00697d76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t78;
    // 0x00697d78: 8b502c MOV
        batch_guest_pc = 0x00697d78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t79;
    // 0x00697d7b: 8d4c240c LEA
        t80 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t80;
    // 0x00697d7f: 51 PUSH
        batch_guest_pc = 0x00697d7fu;
        t81a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t81a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d80: bb02000000 MOV
        t82 = 0x00000002u;
        state.regs[3] = t82;
    // 0x00697d85: 6850824001 PUSH
        batch_guest_pc = 0x00697d85u;
        t83a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d8a: 8bce MOV
        t84 = state.regs[6];
        state.regs[1] = t84;
    // 0x00697d8c: 895c2424 MOV
        batch_guest_pc = 0x00697d8cu;
        t85 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t85)) return BatchLiftStatus::invalid_memory;
    // 0x00697d90: ffd2 CALL
        t86_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d92u);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
    // 0x00697d92: 8b4c240c MOV
        batch_guest_pc = 0x00697d92u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t87;
    // 0x00697d96: 8b01 MOV
        batch_guest_pc = 0x00697d96u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t88;
    // 0x00697d98: 8b5038 MOV
        batch_guest_pc = 0x00697d98u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t89;
    // 0x00697d9b: ffd2 CALL
        t90_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d9du);
        if (t90_call_status != BatchLiftStatus::returned) return t90_call_status;
    // 0x00697d9d: 8bf0 MOV
        t91 = state.regs[0];
        state.regs[6] = t91;
    // 0x00697d9f: 89742410 MOV
        batch_guest_pc = 0x00697d9fu;
        t92 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t92)) return BatchLiftStatus::invalid_memory;
    // 0x00697da3: 85f6 TEST
        t93a = state.regs[6];
        t93b = state.regs[6];
        t93r = (t93a & t93b) & 0xffffffffu;
        batch_set_logic_flags(state, t93r, 32u);
    // 0x00697da5: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697daf;
    // 0x00697da7: 8b06 MOV
        batch_guest_pc = 0x00697da7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t95;
    // 0x00697da9: 8b10 MOV
        batch_guest_pc = 0x00697da9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t96;
    // 0x00697dab: 8bce MOV
        t97 = state.regs[6];
        state.regs[1] = t97;
    // 0x00697dad: ffd2 CALL
        t98_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dafu);
        if (t98_call_status != BatchLiftStatus::returned) return t98_call_status;
    // 0x00697daf: 6a15 PUSH
    L_00697daf:
        batch_guest_pc = 0x00697dafu;
        t99a = 0x00000015u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t99a)) return BatchLiftStatus::invalid_memory;
    // 0x00697db1: 8bce MOV
        t100 = state.regs[6];
        state.regs[1] = t100;
    // 0x00697db3: c644242003 MOV
        batch_guest_pc = 0x00697db3u;
        t101 = 0x00000003u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00697db8: e823b62800 CALL
        if (!batch_guest_call32(memory, state, 0x009233e0u, 0x00697dbdu)) return BatchLiftStatus::invalid_memory;
        t102_call_status = spore_lift_009233e0(memory, state);
        if (t102_call_status != BatchLiftStatus::returned) return t102_call_status;
        if (state.eip != 0x00697dbdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697dbd: 885c241c MOV
        batch_guest_pc = 0x00697dbdu;
        t103 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t103)) return BatchLiftStatus::invalid_memory;
    // 0x00697dc1: 85f6 TEST
        t104a = state.regs[6];
        t104b = state.regs[6];
        t104r = (t104a & t104b) & 0xffffffffu;
        batch_set_logic_flags(state, t104r, 32u);
    // 0x00697dc3: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697dce;
    // 0x00697dc5: 8b06 MOV
        batch_guest_pc = 0x00697dc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t106;
    // 0x00697dc7: 8b5004 MOV
        batch_guest_pc = 0x00697dc7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t107;
    // 0x00697dca: 8bce MOV
        t108 = state.regs[6];
        state.regs[1] = t108;
    // 0x00697dcc: ffd2 CALL
        t109_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dceu);
        if (t109_call_status != BatchLiftStatus::returned) return t109_call_status;
    // 0x00697dce: 8b4c240c MOV
    L_00697dce:
        batch_guest_pc = 0x00697dceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t110;
    // 0x00697dd2: 5f POP
        batch_guest_pc = 0x00697dd2u;
        if (!memory.load32(state.regs[4], t111a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t111a;
    // 0x00697dd3: 5e POP
        batch_guest_pc = 0x00697dd3u;
        if (!memory.load32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t112a;
    // 0x00697dd4: c7442414ffffffff MOV
        batch_guest_pc = 0x00697dd4u;
        t113 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t113)) return BatchLiftStatus::invalid_memory;
    // 0x00697ddc: 5b POP
        batch_guest_pc = 0x00697ddcu;
        if (!memory.load32(state.regs[4], t114a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t114a;
    // 0x00697ddd: 85c9 TEST
        t115a = state.regs[1];
        t115b = state.regs[1];
        t115r = (t115a & t115b) & 0xffffffffu;
        batch_set_logic_flags(state, t115r, 32u);
    // 0x00697ddf: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697de8;
    // 0x00697de1: 8b01 MOV
        batch_guest_pc = 0x00697de1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t117)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t117;
    // 0x00697de3: 8b5004 MOV
        batch_guest_pc = 0x00697de3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t118)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t118;
    // 0x00697de6: ffd2 CALL
        t119_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697de8u);
        if (t119_call_status != BatchLiftStatus::returned) return t119_call_status;
    // 0x00697de8: 8b4c2408 MOV
    L_00697de8:
        batch_guest_pc = 0x00697de8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t120;
    // 0x00697dec: 64890d00000000 MOV
        batch_guest_pc = 0x00697decu;
        t121 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t121)) return BatchLiftStatus::invalid_memory;
    // 0x00697df3: 83c414 ADD
        t122a = state.regs[4];
        t122b = 0x00000014u;
        t122r = static_cast<std::uint32_t>(t122a + t122b) & 0xffffffffu;
        batch_set_add_flags(state, t122a, t122b, t122r, 32u);
        state.regs[4] = t122r;
    // 0x00697df6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
