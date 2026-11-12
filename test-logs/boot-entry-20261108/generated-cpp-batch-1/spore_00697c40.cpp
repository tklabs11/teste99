#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00697c99(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00697d06(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009233e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923f30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009244d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924790(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697c40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697c40u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    BatchLiftStatus t40_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    BatchLiftStatus t47_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;
    std::uint32_t t62a = 0;
    std::uint32_t t63 = 0;
    BatchLiftStatus t64_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t65 = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    BatchLiftStatus t77_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83 = 0;
    BatchLiftStatus t84_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t85 = 0;
    BatchLiftStatus t86_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t87 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0;
    std::uint32_t t90a = 0;
    std::uint32_t t91a = 0;
    std::uint32_t t92 = 0;
    BatchLiftStatus t93_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96a = 0;
    std::uint32_t t97a = 0;
    std::uint32_t t98a = 0;
    std::uint32_t t99 = 0;
    BatchLiftStatus t100_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0;
    std::uint32_t t104a = 0;
    std::uint32_t t105a = 0;
    std::uint32_t t106 = 0;
    BatchLiftStatus t107_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t108 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112a = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114a = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    BatchLiftStatus t117_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t118 = 0;
    std::uint32_t t119 = 0;
    std::uint32_t t120 = 0;
    BatchLiftStatus t121_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124a = 0, t124b = 0, t124r = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128 = 0;
    BatchLiftStatus t129_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t130a = 0;
    std::uint32_t t131 = 0;
    std::uint32_t t132 = 0;
    BatchLiftStatus t133_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t134 = 0;
    std::uint32_t t135a = 0, t135b = 0, t135r = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139 = 0;
    BatchLiftStatus t140_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t141 = 0;
    std::uint32_t t142a = 0;
    std::uint32_t t143a = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145a = 0;
    std::uint32_t t146a = 0, t146b = 0, t146r = 0;
    std::uint32_t t148 = 0;
    std::uint32_t t149 = 0;
    BatchLiftStatus t150_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153a = 0, t153b = 0, t153r = 0;

    // 0x00697c40: 64a100000000 MOV
        batch_guest_pc = 0x00697c40u;
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00697c46: 6aff PUSH
        batch_guest_pc = 0x00697c46u;
        t1a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c48: 6834d32001 PUSH
        batch_guest_pc = 0x00697c48u;
        t2a = 0x0120d334u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c4d: 50 PUSH
        batch_guest_pc = 0x00697c4du;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c4e: 64892500000000 MOV
        batch_guest_pc = 0x00697c4eu;
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00697c55: 83ec08 SUB
        t5a = state.regs[4];
        t5b = 0x00000008u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00697c58: 53 PUSH
        batch_guest_pc = 0x00697c58u;
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c59: 56 PUSH
        batch_guest_pc = 0x00697c59u;
        t7a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c5a: 8bf1 MOV
        t8 = state.regs[1];
        state.regs[6] = t8;
    // 0x00697c5c: 8b462c MOV
        batch_guest_pc = 0x00697c5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00697c5f: 57 PUSH
        batch_guest_pc = 0x00697c5fu;
        t10a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c60: 85c0 TEST
        t11a = state.regs[0];
        t11b = state.regs[0];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x00697c62: 7560 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00697cc4;
    // 0x00697c64: 50 PUSH
        batch_guest_pc = 0x00697c64u;
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c65: 50 PUSH
        batch_guest_pc = 0x00697c65u;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c66: 50 PUSH
        batch_guest_pc = 0x00697c66u;
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c67: 50 PUSH
        batch_guest_pc = 0x00697c67u;
        t16a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c68: 68bc824001 PUSH
        batch_guest_pc = 0x00697c68u;
        t17a = 0x014082bcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c6d: 6a3c PUSH
        batch_guest_pc = 0x00697c6du;
        t18a = 0x0000003cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c6f: e82cf78a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00697c74u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_00f473a0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x00697c74u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697c74: 83c418 ADD
        t20a = state.regs[4];
        t20b = 0x00000018u;
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[4] = t20r;
    // 0x00697c77: 89442410 MOV
        batch_guest_pc = 0x00697c77u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00697c7b: c744241c00000000 MOV
        batch_guest_pc = 0x00697c7bu;
        t22 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00697c83: 85c0 TEST
        t23a = state.regs[0];
        t23b = state.regs[0];
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
    // 0x00697c85: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697c97;
    // 0x00697c87: 68ac824001 PUSH
        batch_guest_pc = 0x00697c87u;
        t25a = 0x014082acu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00697c8c: 8bc8 MOV
        t26 = state.regs[0];
        state.regs[1] = t26;
    // 0x00697c8e: e89dc22800 CALL
        if (!batch_guest_call32(memory, state, 0x00923f30u, 0x00697c93u)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00923f30(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00697c93u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697c93: 8bf8 MOV
        t28 = state.regs[0];
        state.regs[7] = t28;
    // 0x00697c95: eb02 JMP
        goto L_00697c99;
    // 0x00697c97: 33ff XOR
    L_00697c97:
        t30a = state.regs[7];
        t30b = state.regs[7];
        t30r = (t30a ^ t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
        state.regs[7] = t30r;
    // 0x00697c99: 8b5e2c MOV
    L_00697c99:
        batch_guest_pc = 0x00697c99u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t31;
    // 0x00697c9c: c744241cffffffff MOV
        batch_guest_pc = 0x00697c9cu;
        t32 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00697ca4: 3bfb CMP
        t33a = state.regs[7];
        t33b = state.regs[3];
        t33r = static_cast<std::uint32_t>(t33a - t33b) & 0xffffffffu;
        batch_set_sub_flags(state, t33a, t33b, t33r, 32u);
    // 0x00697ca6: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cc4;
    // 0x00697ca8: 85ff TEST
        t35a = state.regs[7];
        t35b = state.regs[7];
        t35r = (t35a & t35b) & 0xffffffffu;
        batch_set_logic_flags(state, t35r, 32u);
    // 0x00697caa: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cb4;
    // 0x00697cac: 8b07 MOV
        batch_guest_pc = 0x00697cacu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x00697cae: 8b10 MOV
        batch_guest_pc = 0x00697caeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00697cb0: 8bcf MOV
        t39 = state.regs[7];
        state.regs[1] = t39;
    // 0x00697cb2: ffd2 CALL
        t40_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697cb4u);
        if (t40_call_status != BatchLiftStatus::returned) return t40_call_status;
    // 0x00697cb4: 897e2c MOV
    L_00697cb4:
        batch_guest_pc = 0x00697cb4u;
        t41 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00697cb7: 85db TEST
        t42a = state.regs[3];
        t42b = state.regs[3];
        t42r = (t42a & t42b) & 0xffffffffu;
        batch_set_logic_flags(state, t42r, 32u);
    // 0x00697cb9: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697cc4;
    // 0x00697cbb: 8b03 MOV
        batch_guest_pc = 0x00697cbbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t44;
    // 0x00697cbd: 8b5004 MOV
        batch_guest_pc = 0x00697cbdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x00697cc0: 8bcb MOV
        t46 = state.regs[3];
        state.regs[1] = t46;
    // 0x00697cc2: ffd2 CALL
        t47_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697cc4u);
        if (t47_call_status != BatchLiftStatus::returned) return t47_call_status;
    // 0x00697cc4: 837e3000 CMP
    L_00697cc4:
        batch_guest_pc = 0x00697cc4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t48a)) return BatchLiftStatus::invalid_memory;
        t48b = 0x00000000u;
        t48r = static_cast<std::uint32_t>(t48a - t48b) & 0xffffffffu;
        batch_set_sub_flags(state, t48a, t48b, t48r, 32u);
    // 0x00697cc8: 7567 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697cca: 6a00 PUSH
        batch_guest_pc = 0x00697ccau;
        t50a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
    // 0x00697ccc: 6a00 PUSH
        batch_guest_pc = 0x00697cccu;
        t51a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cce: 6a00 PUSH
        batch_guest_pc = 0x00697cceu;
        t52a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd0: 6a00 PUSH
        batch_guest_pc = 0x00697cd0u;
        t53a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd2: 6870824001 PUSH
        batch_guest_pc = 0x00697cd2u;
        t54a = 0x01408270u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cd7: 68580a0000 PUSH
        batch_guest_pc = 0x00697cd7u;
        t55a = 0x00000a58u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cdc: e8bff68a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00697ce1u)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00f473a0(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x00697ce1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697ce1: 83c418 ADD
        t57a = state.regs[4];
        t57b = 0x00000018u;
        t57r = static_cast<std::uint32_t>(t57a + t57b) & 0xffffffffu;
        batch_set_add_flags(state, t57a, t57b, t57r, 32u);
        state.regs[4] = t57r;
    // 0x00697ce4: 89442410 MOV
        batch_guest_pc = 0x00697ce4u;
        t58 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t58)) return BatchLiftStatus::invalid_memory;
    // 0x00697ce8: c744241c01000000 MOV
        batch_guest_pc = 0x00697ce8u;
        t59 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00697cf0: 85c0 TEST
        t60a = state.regs[0];
        t60b = state.regs[0];
        t60r = (t60a & t60b) & 0xffffffffu;
        batch_set_logic_flags(state, t60r, 32u);
    // 0x00697cf2: 7410 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d04;
    // 0x00697cf4: 685c824001 PUSH
        batch_guest_pc = 0x00697cf4u;
        t62a = 0x0140825cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x00697cf9: 8bc8 MOV
        t63 = state.regs[0];
        state.regs[1] = t63;
    // 0x00697cfb: e8d0c72800 CALL
        if (!batch_guest_call32(memory, state, 0x009244d0u, 0x00697d00u)) return BatchLiftStatus::invalid_memory;
        t64_call_status = spore_lift_009244d0(memory, state);
        if (t64_call_status != BatchLiftStatus::returned) return t64_call_status;
        if (state.eip != 0x00697d00u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697d00: 8bf8 MOV
        t65 = state.regs[0];
        state.regs[7] = t65;
    // 0x00697d02: eb02 JMP
        goto L_00697d06;
    // 0x00697d04: 33ff XOR
    L_00697d04:
        t67a = state.regs[7];
        t67b = state.regs[7];
        t67r = (t67a ^ t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
        state.regs[7] = t67r;
    // 0x00697d06: 8b5e30 MOV
    L_00697d06:
        batch_guest_pc = 0x00697d06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t68;
    // 0x00697d09: c744241cffffffff MOV
        batch_guest_pc = 0x00697d09u;
        t69 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t69)) return BatchLiftStatus::invalid_memory;
    // 0x00697d11: 3bfb CMP
        t70a = state.regs[7];
        t70b = state.regs[3];
        t70r = static_cast<std::uint32_t>(t70a - t70b) & 0xffffffffu;
        batch_set_sub_flags(state, t70a, t70b, t70r, 32u);
    // 0x00697d13: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d15: 85ff TEST
        t72a = state.regs[7];
        t72b = state.regs[7];
        t72r = (t72a & t72b) & 0xffffffffu;
        batch_set_logic_flags(state, t72r, 32u);
    // 0x00697d17: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d21;
    // 0x00697d19: 8b07 MOV
        batch_guest_pc = 0x00697d19u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t74;
    // 0x00697d1b: 8b10 MOV
        batch_guest_pc = 0x00697d1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t75;
    // 0x00697d1d: 8bcf MOV
        t76 = state.regs[7];
        state.regs[1] = t76;
    // 0x00697d1f: ffd2 CALL
        t77_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d21u);
        if (t77_call_status != BatchLiftStatus::returned) return t77_call_status;
    // 0x00697d21: 897e30 MOV
    L_00697d21:
        batch_guest_pc = 0x00697d21u;
        t78 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t78)) return BatchLiftStatus::invalid_memory;
    // 0x00697d24: 85db TEST
        t79a = state.regs[3];
        t79b = state.regs[3];
        t79r = (t79a & t79b) & 0xffffffffu;
        batch_set_logic_flags(state, t79r, 32u);
    // 0x00697d26: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d28: 8b03 MOV
        batch_guest_pc = 0x00697d28u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t81;
    // 0x00697d2a: 8b5004 MOV
        batch_guest_pc = 0x00697d2au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t82;
    // 0x00697d2d: 8bcb MOV
        t83 = state.regs[3];
        state.regs[1] = t83;
    // 0x00697d2f: ffd2 CALL
        t84_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d31u);
        if (t84_call_status != BatchLiftStatus::returned) return t84_call_status;
    // 0x00697d31: 8bce MOV
    L_00697d31:
        t85 = state.regs[6];
        state.regs[1] = t85;
    // 0x00697d33: e858ca2800 CALL
        if (!batch_guest_call32(memory, state, 0x00924790u, 0x00697d38u)) return BatchLiftStatus::invalid_memory;
        t86_call_status = spore_lift_00924790(memory, state);
        if (t86_call_status != BatchLiftStatus::returned) return t86_call_status;
        if (state.eip != 0x00697d38u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697d38: 8b06 MOV
        batch_guest_pc = 0x00697d38u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t87;
    // 0x00697d3a: 8b5030 MOV
        batch_guest_pc = 0x00697d3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t88;
    // 0x00697d3d: 68fb000000 PUSH
        batch_guest_pc = 0x00697d3du;
        t89a = 0x000000fbu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t89a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d42: 6a00 PUSH
        batch_guest_pc = 0x00697d42u;
        t90a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d44: 6a00 PUSH
        batch_guest_pc = 0x00697d44u;
        t91a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t91a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d46: 8bce MOV
        t92 = state.regs[6];
        state.regs[1] = t92;
    // 0x00697d48: ffd2 CALL
        t93_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d4au);
        if (t93_call_status != BatchLiftStatus::returned) return t93_call_status;
    // 0x00697d4a: 8b06 MOV
        batch_guest_pc = 0x00697d4au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t94;
    // 0x00697d4c: 8b5030 MOV
        batch_guest_pc = 0x00697d4cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t95)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t95;
    // 0x00697d4f: 6a19 PUSH
        batch_guest_pc = 0x00697d4fu;
        t96a = 0x00000019u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t96a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d51: 6a00 PUSH
        batch_guest_pc = 0x00697d51u;
        t97a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d53: 6850824001 PUSH
        batch_guest_pc = 0x00697d53u;
        t98a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t98a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d58: 8bce MOV
        t99 = state.regs[6];
        state.regs[1] = t99;
    // 0x00697d5a: ffd2 CALL
        t100_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d5cu);
        if (t100_call_status != BatchLiftStatus::returned) return t100_call_status;
    // 0x00697d5c: 8b06 MOV
        batch_guest_pc = 0x00697d5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x00697d5e: 8b5030 MOV
        batch_guest_pc = 0x00697d5eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t102)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t102;
    // 0x00697d61: 6a32 PUSH
        batch_guest_pc = 0x00697d61u;
        t103a = 0x00000032u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d63: 6a00 PUSH
        batch_guest_pc = 0x00697d63u;
        t104a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t104a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d65: 6840824001 PUSH
        batch_guest_pc = 0x00697d65u;
        t105a = 0x01408240u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t105a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d6a: 8bce MOV
        t106 = state.regs[6];
        state.regs[1] = t106;
    // 0x00697d6c: ffd2 CALL
        t107_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d6eu);
        if (t107_call_status != BatchLiftStatus::returned) return t107_call_status;
    // 0x00697d6e: c744240c00000000 MOV
        batch_guest_pc = 0x00697d6eu;
        t108 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t108)) return BatchLiftStatus::invalid_memory;
    // 0x00697d76: 8b06 MOV
        batch_guest_pc = 0x00697d76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t109)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t109;
    // 0x00697d78: 8b502c MOV
        batch_guest_pc = 0x00697d78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t110;
    // 0x00697d7b: 8d4c240c LEA
        t111 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t111;
    // 0x00697d7f: 51 PUSH
        batch_guest_pc = 0x00697d7fu;
        t112a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d80: bb02000000 MOV
        t113 = 0x00000002u;
        state.regs[3] = t113;
    // 0x00697d85: 6850824001 PUSH
        batch_guest_pc = 0x00697d85u;
        t114a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t114a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d8a: 8bce MOV
        t115 = state.regs[6];
        state.regs[1] = t115;
    // 0x00697d8c: 895c2424 MOV
        batch_guest_pc = 0x00697d8cu;
        t116 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t116)) return BatchLiftStatus::invalid_memory;
    // 0x00697d90: ffd2 CALL
        t117_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d92u);
        if (t117_call_status != BatchLiftStatus::returned) return t117_call_status;
    // 0x00697d92: 8b4c240c MOV
        batch_guest_pc = 0x00697d92u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t118)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t118;
    // 0x00697d96: 8b01 MOV
        batch_guest_pc = 0x00697d96u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t119)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t119;
    // 0x00697d98: 8b5038 MOV
        batch_guest_pc = 0x00697d98u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t120)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t120;
    // 0x00697d9b: ffd2 CALL
        t121_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d9du);
        if (t121_call_status != BatchLiftStatus::returned) return t121_call_status;
    // 0x00697d9d: 8bf0 MOV
        t122 = state.regs[0];
        state.regs[6] = t122;
    // 0x00697d9f: 89742410 MOV
        batch_guest_pc = 0x00697d9fu;
        t123 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t123)) return BatchLiftStatus::invalid_memory;
    // 0x00697da3: 85f6 TEST
        t124a = state.regs[6];
        t124b = state.regs[6];
        t124r = (t124a & t124b) & 0xffffffffu;
        batch_set_logic_flags(state, t124r, 32u);
    // 0x00697da5: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697daf;
    // 0x00697da7: 8b06 MOV
        batch_guest_pc = 0x00697da7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t126)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t126;
    // 0x00697da9: 8b10 MOV
        batch_guest_pc = 0x00697da9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t127;
    // 0x00697dab: 8bce MOV
        t128 = state.regs[6];
        state.regs[1] = t128;
    // 0x00697dad: ffd2 CALL
        t129_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dafu);
        if (t129_call_status != BatchLiftStatus::returned) return t129_call_status;
    // 0x00697daf: 6a15 PUSH
    L_00697daf:
        batch_guest_pc = 0x00697dafu;
        t130a = 0x00000015u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t130a)) return BatchLiftStatus::invalid_memory;
    // 0x00697db1: 8bce MOV
        t131 = state.regs[6];
        state.regs[1] = t131;
    // 0x00697db3: c644242003 MOV
        batch_guest_pc = 0x00697db3u;
        t132 = 0x00000003u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t132)) return BatchLiftStatus::invalid_memory;
    // 0x00697db8: e823b62800 CALL
        if (!batch_guest_call32(memory, state, 0x009233e0u, 0x00697dbdu)) return BatchLiftStatus::invalid_memory;
        t133_call_status = spore_lift_009233e0(memory, state);
        if (t133_call_status != BatchLiftStatus::returned) return t133_call_status;
        if (state.eip != 0x00697dbdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697dbd: 885c241c MOV
        batch_guest_pc = 0x00697dbdu;
        t134 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t134)) return BatchLiftStatus::invalid_memory;
    // 0x00697dc1: 85f6 TEST
        t135a = state.regs[6];
        t135b = state.regs[6];
        t135r = (t135a & t135b) & 0xffffffffu;
        batch_set_logic_flags(state, t135r, 32u);
    // 0x00697dc3: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697dce;
    // 0x00697dc5: 8b06 MOV
        batch_guest_pc = 0x00697dc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t137)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t137;
    // 0x00697dc7: 8b5004 MOV
        batch_guest_pc = 0x00697dc7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t138)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t138;
    // 0x00697dca: 8bce MOV
        t139 = state.regs[6];
        state.regs[1] = t139;
    // 0x00697dcc: ffd2 CALL
        t140_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dceu);
        if (t140_call_status != BatchLiftStatus::returned) return t140_call_status;
    // 0x00697dce: 8b4c240c MOV
    L_00697dce:
        batch_guest_pc = 0x00697dceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t141)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t141;
    // 0x00697dd2: 5f POP
        batch_guest_pc = 0x00697dd2u;
        if (!memory.load32(state.regs[4], t142a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t142a;
    // 0x00697dd3: 5e POP
        batch_guest_pc = 0x00697dd3u;
        if (!memory.load32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t143a;
    // 0x00697dd4: c7442414ffffffff MOV
        batch_guest_pc = 0x00697dd4u;
        t144 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t144)) return BatchLiftStatus::invalid_memory;
    // 0x00697ddc: 5b POP
        batch_guest_pc = 0x00697ddcu;
        if (!memory.load32(state.regs[4], t145a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t145a;
    // 0x00697ddd: 85c9 TEST
        t146a = state.regs[1];
        t146b = state.regs[1];
        t146r = (t146a & t146b) & 0xffffffffu;
        batch_set_logic_flags(state, t146r, 32u);
    // 0x00697ddf: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697de8;
    // 0x00697de1: 8b01 MOV
        batch_guest_pc = 0x00697de1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t148)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t148;
    // 0x00697de3: 8b5004 MOV
        batch_guest_pc = 0x00697de3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t149)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t149;
    // 0x00697de6: ffd2 CALL
        t150_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697de8u);
        if (t150_call_status != BatchLiftStatus::returned) return t150_call_status;
    // 0x00697de8: 8b4c2408 MOV
    L_00697de8:
        batch_guest_pc = 0x00697de8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t151;
    // 0x00697dec: 64890d00000000 MOV
        batch_guest_pc = 0x00697decu;
        t152 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t152)) return BatchLiftStatus::invalid_memory;
    // 0x00697df3: 83c414 ADD
        t153a = state.regs[4];
        t153b = 0x00000014u;
        t153r = static_cast<std::uint32_t>(t153a + t153b) & 0xffffffffu;
        batch_set_add_flags(state, t153a, t153b, t153r, 32u);
        state.regs[4] = t153r;
    // 0x00697df6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
