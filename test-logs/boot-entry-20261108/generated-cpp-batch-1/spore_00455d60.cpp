#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00455dcc(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00455de8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00455f3c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00455d60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00455d60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31c = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52a = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77a = 0;
    BatchLiftStatus t78_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81a = 0, t81b = 0, t81r = 0;
    std::uint32_t t82a = 0, t82b = 0, t82r = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t86a = 0;
    std::uint32_t t87 = 0;
    std::uint32_t t88a = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    BatchLiftStatus t91_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107 = 0;
    std::uint32_t t108a = 0, t108b = 0, t108r = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    std::uint32_t t113a = 0, t113b = 0, t113r = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117 = 0;
    std::uint32_t t118a = 0;
    BatchLiftStatus t119_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t120a = 0, t120b = 0, t120r = 0;
    std::uint32_t t121 = 0;
    std::uint32_t t122 = 0;
    std::uint32_t t123 = 0;
    std::uint32_t t124 = 0;
    std::uint32_t t125 = 0;
    std::uint32_t t126 = 0;
    std::uint32_t t127 = 0;
    std::uint32_t t128a = 0, t128b = 0, t128r = 0;
    std::uint32_t t129 = 0;
    std::uint32_t t130 = 0;
    std::uint32_t t132 = 0;
    std::uint32_t t133 = 0;
    std::uint32_t t134 = 0;
    std::uint32_t t135a = 0, t135b = 0, t135r = 0;
    std::uint32_t t136 = 0;
    std::uint32_t t137 = 0;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0, t139b = 0, t139r = 0;
    std::uint32_t t140 = 0;
    std::uint32_t t141 = 0;
    std::uint32_t t142a = 0, t142b = 0, t142r = 0;
    std::uint32_t t143a = 0;
    std::uint32_t t144 = 0;
    std::uint32_t t145a = 0;
    std::uint32_t t146 = 0;
    std::uint32_t t147a = 0;
    BatchLiftStatus t148_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t149a = 0, t149b = 0, t149r = 0;
    std::uint32_t t150 = 0;
    std::uint32_t t151 = 0;
    std::uint32_t t152 = 0;
    std::uint32_t t153 = 0;
    std::uint32_t t154 = 0;
    std::uint32_t t155 = 0;
    std::uint32_t t156 = 0;
    std::uint32_t t157 = 0;
    std::uint32_t t158 = 0;
    std::uint32_t t159 = 0;
    std::uint32_t t160 = 0;
    std::uint32_t t161a = 0, t161b = 0, t161r = 0;
    std::uint32_t t162 = 0;
    std::uint32_t t163 = 0;
    std::uint32_t t164 = 0;
    std::uint32_t t165 = 0;
    std::uint32_t t166a = 0;

    // 0x00455d60: 55 PUSH
        batch_guest_pc = 0x00455d60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00455d61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00455d63: 83ec50 SUB
        t2a = state.regs[4];
        t2b = 0x00000050u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00455d66: 894db8 MOV
        batch_guest_pc = 0x00455d66u;
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00455d69: 8b4508 MOV
        batch_guest_pc = 0x00455d69u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00455d6c: 3b450c CMP
        batch_guest_pc = 0x00455d6cu;
        t5a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t5b)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x00455d6f: 0f84c7010000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00455f3c;
    // 0x00455d75: 8b4db8 MOV
        batch_guest_pc = 0x00455d75u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x00455d78: 8b55b8 MOV
        batch_guest_pc = 0x00455d78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00455d7b: 8b4104 MOV
        batch_guest_pc = 0x00455d7bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x00455d7e: 2b02 SUB
        batch_guest_pc = 0x00455d7eu;
        t10a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t10b)) return BatchLiftStatus::invalid_memory;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[0] = t10r;
    // 0x00455d80: 8945fc MOV
        batch_guest_pc = 0x00455d80u;
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00455d83: 8b4d0c MOV
        batch_guest_pc = 0x00455d83u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x00455d86: 2b4d08 SUB
        batch_guest_pc = 0x00455d86u;
        t13a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t13b)) return BatchLiftStatus::invalid_memory;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
        state.regs[1] = t13r;
    // 0x00455d89: 894df8 MOV
        batch_guest_pc = 0x00455d89u;
        t14 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00455d8c: 8b55b8 MOV
        batch_guest_pc = 0x00455d8cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00455d8f: 8b45b8 MOV
        batch_guest_pc = 0x00455d8fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x00455d92: 8b4a08 MOV
        batch_guest_pc = 0x00455d92u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00455d95: 2b08 SUB
        batch_guest_pc = 0x00455d95u;
        t18a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t18b)) return BatchLiftStatus::invalid_memory;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
        state.regs[1] = t18r;
    // 0x00455d97: 83e901 SUB
        t19a = state.regs[1];
        t19b = 0x00000001u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[1] = t19r;
    // 0x00455d9a: 894df4 MOV
        batch_guest_pc = 0x00455d9au;
        t20 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00455d9d: 8b55fc MOV
        batch_guest_pc = 0x00455d9du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x00455da0: 0355f8 ADD
        batch_guest_pc = 0x00455da0u;
        t22a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t22b)) return BatchLiftStatus::invalid_memory;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[2] = t22r;
    // 0x00455da3: 3b55f4 CMP
        batch_guest_pc = 0x00455da3u;
        t23a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t23b)) return BatchLiftStatus::invalid_memory;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x00455da6: 0f8635010000 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00455ee1;
    // 0x00455dac: 8b45fc MOV
        batch_guest_pc = 0x00455dacu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00455daf: 0345f8 ADD
        batch_guest_pc = 0x00455dafu;
        t26a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t26b)) return BatchLiftStatus::invalid_memory;
        t26r = static_cast<std::uint32_t>(t26a + t26b) & 0xffffffffu;
        batch_set_add_flags(state, t26a, t26b, t26r, 32u);
        state.regs[0] = t26r;
    // 0x00455db2: 8945e0 MOV
        batch_guest_pc = 0x00455db2u;
        t27 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00455db5: 837df408 CMP
        batch_guest_pc = 0x00455db5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t28a)) return BatchLiftStatus::invalid_memory;
        t28b = 0x00000008u;
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00455db9: 760a JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00455dc5;
    // 0x00455dbb: 8b4df4 MOV
        batch_guest_pc = 0x00455dbbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00455dbe: d1e1 SHL
        t31a = state.regs[1];
        t31c = 1u;
        if (t31c != 0u) {
        t31r = static_cast<std::uint32_t>(t31a << t31c) & 0xffffffffu;
        batch_set_shl_flags(state, t31a, t31c, t31r, 32u);
            state.regs[1] = t31r;
        }
    // 0x00455dc0: 894db4 MOV
        batch_guest_pc = 0x00455dc0u;
        t32 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb4u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00455dc3: eb07 JMP
        goto L_00455dcc;
    // 0x00455dc5: c745b408000000 MOV
    L_00455dc5:
        batch_guest_pc = 0x00455dc5u;
        t34 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb4u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00455dcc: 8b55b4 MOV
    L_00455dcc:
        batch_guest_pc = 0x00455dccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb4u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x00455dcf: 8955dc MOV
        batch_guest_pc = 0x00455dcfu;
        t36 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00455dd2: 8b45dc MOV
        batch_guest_pc = 0x00455dd2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t37;
    // 0x00455dd5: 3b45e0 CMP
        batch_guest_pc = 0x00455dd5u;
        t38a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t38b)) return BatchLiftStatus::invalid_memory;
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x00455dd8: 7308 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00455de2;
    // 0x00455dda: 8d4de0 LEA
        t40 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u);
        state.regs[1] = t40;
    // 0x00455ddd: 894db0 MOV
        batch_guest_pc = 0x00455dddu;
        t41 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb0u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00455de0: eb06 JMP
        goto L_00455de8;
    // 0x00455de2: 8d55dc LEA
    L_00455de2:
        t43 = static_cast<std::uint32_t>(state.regs[5] + 0xffffffdcu);
        state.regs[2] = t43;
    // 0x00455de5: 8955b0 MOV
        batch_guest_pc = 0x00455de5u;
        t44 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb0u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00455de8: 8b45b0 MOV
    L_00455de8:
        batch_guest_pc = 0x00455de8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb0u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t45;
    // 0x00455deb: 8945d8 MOV
        batch_guest_pc = 0x00455debu;
        t46 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00455dee: 8b4dd8 MOV
        batch_guest_pc = 0x00455deeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd8u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t47;
    // 0x00455df1: 8b11 MOV
        batch_guest_pc = 0x00455df1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00455df3: 83c201 ADD
        t49a = state.regs[2];
        t49b = 0x00000001u;
        t49r = static_cast<std::uint32_t>(t49a + t49b) & 0xffffffffu;
        batch_set_add_flags(state, t49a, t49b, t49r, 32u);
        state.regs[2] = t49r;
    // 0x00455df6: 8955ec MOV
        batch_guest_pc = 0x00455df6u;
        t50 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00455df9: 68d1000000 PUSH
        batch_guest_pc = 0x00455df9u;
        t51a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00455dfe: 6838bb3e01 PUSH
        batch_guest_pc = 0x00455dfeu;
        t52a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t52a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e03: 6a00 PUSH
        batch_guest_pc = 0x00455e03u;
        t53a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e05: 6a00 PUSH
        batch_guest_pc = 0x00455e05u;
        t54a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e07: 6830b43e01 PUSH
        batch_guest_pc = 0x00455e07u;
        t55a = 0x013eb430u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e0c: 8b45ec MOV
        batch_guest_pc = 0x00455e0cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x00455e0f: 50 PUSH
        batch_guest_pc = 0x00455e0fu;
        t57a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e10: e88b15af00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00455e15u)) return BatchLiftStatus::invalid_memory;
        t58_call_status = spore_lift_00f473a0(memory, state);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x00455e15u) return BatchLiftStatus::invalid_control_flow;
    // 0x00455e15: 83c418 ADD
        t59a = state.regs[4];
        t59b = 0x00000018u;
        t59r = static_cast<std::uint32_t>(t59a + t59b) & 0xffffffffu;
        batch_set_add_flags(state, t59a, t59b, t59r, 32u);
        state.regs[4] = t59r;
    // 0x00455e18: 8945d4 MOV
        batch_guest_pc = 0x00455e18u;
        t60 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd4u), t60)) return BatchLiftStatus::invalid_memory;
    // 0x00455e1b: 8b4dd4 MOV
        batch_guest_pc = 0x00455e1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd4u), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t61;
    // 0x00455e1e: 894de8 MOV
        batch_guest_pc = 0x00455e1eu;
        t62 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00455e21: 8b55e8 MOV
        batch_guest_pc = 0x00455e21u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t63;
    // 0x00455e24: 8955f0 MOV
        batch_guest_pc = 0x00455e24u;
        t64 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x00455e27: 8b45b8 MOV
        batch_guest_pc = 0x00455e27u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t65;
    // 0x00455e2a: 8b4804 MOV
        batch_guest_pc = 0x00455e2au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t66;
    // 0x00455e2d: 894dcc MOV
        batch_guest_pc = 0x00455e2du;
        t67 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffccu), t67)) return BatchLiftStatus::invalid_memory;
    // 0x00455e30: 8b55b8 MOV
        batch_guest_pc = 0x00455e30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t68;
    // 0x00455e33: 8b02 MOV
        batch_guest_pc = 0x00455e33u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t69;
    // 0x00455e35: 8945d0 MOV
        batch_guest_pc = 0x00455e35u;
        t70 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t70)) return BatchLiftStatus::invalid_memory;
    // 0x00455e38: 8b4dcc MOV
        batch_guest_pc = 0x00455e38u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffccu), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t71;
    // 0x00455e3b: 2b4dd0 SUB
        batch_guest_pc = 0x00455e3bu;
        t72a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t72b)) return BatchLiftStatus::invalid_memory;
        t72r = static_cast<std::uint32_t>(t72a - t72b) & 0xffffffffu;
        batch_set_sub_flags(state, t72a, t72b, t72r, 32u);
        state.regs[1] = t72r;
    // 0x00455e3e: 51 PUSH
        batch_guest_pc = 0x00455e3eu;
        t73a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e3f: 8b55d0 MOV
        batch_guest_pc = 0x00455e3fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t74;
    // 0x00455e42: 52 PUSH
        batch_guest_pc = 0x00455e42u;
        t75a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e43: 8b45e8 MOV
        batch_guest_pc = 0x00455e43u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t76;
    // 0x00455e46: 50 PUSH
        batch_guest_pc = 0x00455e46u;
        t77a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e47: e8f8a8d800 CALL
        t78_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00455e4cu);
        if (t78_call_status != BatchLiftStatus::returned) return t78_call_status;
        if (state.eip != 0x00455e4cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00455e4c: 83c40c ADD
        t79a = state.regs[4];
        t79b = 0x0000000cu;
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[4] = t79r;
    // 0x00455e4f: 8b4dcc MOV
        batch_guest_pc = 0x00455e4fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffccu), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t80;
    // 0x00455e52: 2b4dd0 SUB
        batch_guest_pc = 0x00455e52u;
        t81a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffd0u), t81b)) return BatchLiftStatus::invalid_memory;
        t81r = static_cast<std::uint32_t>(t81a - t81b) & 0xffffffffu;
        batch_set_sub_flags(state, t81a, t81b, t81r, 32u);
        state.regs[1] = t81r;
    // 0x00455e55: 034de8 ADD
        batch_guest_pc = 0x00455e55u;
        t82a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t82b)) return BatchLiftStatus::invalid_memory;
        t82r = static_cast<std::uint32_t>(t82a + t82b) & 0xffffffffu;
        batch_set_add_flags(state, t82a, t82b, t82r, 32u);
        state.regs[1] = t82r;
    // 0x00455e58: 894df0 MOV
        batch_guest_pc = 0x00455e58u;
        t83 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t83)) return BatchLiftStatus::invalid_memory;
    // 0x00455e5b: 8b550c MOV
        batch_guest_pc = 0x00455e5bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t84;
    // 0x00455e5e: 2b5508 SUB
        batch_guest_pc = 0x00455e5eu;
        t85a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t85b)) return BatchLiftStatus::invalid_memory;
        t85r = static_cast<std::uint32_t>(t85a - t85b) & 0xffffffffu;
        batch_set_sub_flags(state, t85a, t85b, t85r, 32u);
        state.regs[2] = t85r;
    // 0x00455e61: 52 PUSH
        batch_guest_pc = 0x00455e61u;
        t86a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t86a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e62: 8b4508 MOV
        batch_guest_pc = 0x00455e62u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t87)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t87;
    // 0x00455e65: 50 PUSH
        batch_guest_pc = 0x00455e65u;
        t88a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e66: 8b4df0 MOV
        batch_guest_pc = 0x00455e66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t89;
    // 0x00455e69: 51 PUSH
        batch_guest_pc = 0x00455e69u;
        t90a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x00455e6a: e8d5a8d800 CALL
        t91_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00455e6fu);
        if (t91_call_status != BatchLiftStatus::returned) return t91_call_status;
        if (state.eip != 0x00455e6fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00455e6f: 83c40c ADD
        t92a = state.regs[4];
        t92b = 0x0000000cu;
        t92r = static_cast<std::uint32_t>(t92a + t92b) & 0xffffffffu;
        batch_set_add_flags(state, t92a, t92b, t92r, 32u);
        state.regs[4] = t92r;
    // 0x00455e72: 8b550c MOV
        batch_guest_pc = 0x00455e72u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t93;
    // 0x00455e75: 2b5508 SUB
        batch_guest_pc = 0x00455e75u;
        t94a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t94b)) return BatchLiftStatus::invalid_memory;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
        state.regs[2] = t94r;
    // 0x00455e78: 0355f0 ADD
        batch_guest_pc = 0x00455e78u;
        t95a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t95b)) return BatchLiftStatus::invalid_memory;
        t95r = static_cast<std::uint32_t>(t95a + t95b) & 0xffffffffu;
        batch_set_add_flags(state, t95a, t95b, t95r, 32u);
        state.regs[2] = t95r;
    // 0x00455e7b: 8955f0 MOV
        batch_guest_pc = 0x00455e7bu;
        t96 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t96)) return BatchLiftStatus::invalid_memory;
    // 0x00455e7e: 8b45f0 MOV
        batch_guest_pc = 0x00455e7eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t97;
    // 0x00455e81: c60000 MOV
        batch_guest_pc = 0x00455e81u;
        t98 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00455e84: 8b4db8 MOV
        batch_guest_pc = 0x00455e84u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t99)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t99;
    // 0x00455e87: 8b55b8 MOV
        batch_guest_pc = 0x00455e87u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t100;
    // 0x00455e8a: 8b4108 MOV
        batch_guest_pc = 0x00455e8au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x00455e8d: 2b02 SUB
        batch_guest_pc = 0x00455e8du;
        t102a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t102b)) return BatchLiftStatus::invalid_memory;
        t102r = static_cast<std::uint32_t>(t102a - t102b) & 0xffffffffu;
        batch_set_sub_flags(state, t102a, t102b, t102r, 32u);
        state.regs[0] = t102r;
    // 0x00455e8f: 83f801 CMP
        t103a = state.regs[0];
        t103b = 0x00000001u;
        t103r = static_cast<std::uint32_t>(t103a - t103b) & 0xffffffffu;
        batch_set_sub_flags(state, t103a, t103b, t103r, 32u);
    // 0x00455e92: 7e2e JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00455ec2;
    // 0x00455e94: 8b4db8 MOV
        batch_guest_pc = 0x00455e94u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t105;
    // 0x00455e97: 8b55b8 MOV
        batch_guest_pc = 0x00455e97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t106;
    // 0x00455e9a: 8b4108 MOV
        batch_guest_pc = 0x00455e9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t107;
    // 0x00455e9d: 2b02 SUB
        batch_guest_pc = 0x00455e9du;
        t108a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t108b)) return BatchLiftStatus::invalid_memory;
        t108r = static_cast<std::uint32_t>(t108a - t108b) & 0xffffffffu;
        batch_set_sub_flags(state, t108a, t108b, t108r, 32u);
        state.regs[0] = t108r;
    // 0x00455e9f: 8945c0 MOV
        batch_guest_pc = 0x00455e9fu;
        t109 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc0u), t109)) return BatchLiftStatus::invalid_memory;
    // 0x00455ea2: 8b4db8 MOV
        batch_guest_pc = 0x00455ea2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t110;
    // 0x00455ea5: 8b11 MOV
        batch_guest_pc = 0x00455ea5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t111;
    // 0x00455ea7: 8955c4 MOV
        batch_guest_pc = 0x00455ea7u;
        t112 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t112)) return BatchLiftStatus::invalid_memory;
    // 0x00455eaa: 837dc400 CMP
        batch_guest_pc = 0x00455eaau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t113a)) return BatchLiftStatus::invalid_memory;
        t113b = 0x00000000u;
        t113r = static_cast<std::uint32_t>(t113a - t113b) & 0xffffffffu;
        batch_set_sub_flags(state, t113a, t113b, t113r, 32u);
    // 0x00455eae: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00455ec2;
    // 0x00455eb0: 8b45c4 MOV
        batch_guest_pc = 0x00455eb0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t115;
    // 0x00455eb3: 8945c8 MOV
        batch_guest_pc = 0x00455eb3u;
        t116 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc8u), t116)) return BatchLiftStatus::invalid_memory;
    // 0x00455eb6: 8b4dc8 MOV
        batch_guest_pc = 0x00455eb6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc8u), t117)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t117;
    // 0x00455eb9: 51 PUSH
        batch_guest_pc = 0x00455eb9u;
        t118a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t118a)) return BatchLiftStatus::invalid_memory;
    // 0x00455eba: e8c114af00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00455ebfu)) return BatchLiftStatus::invalid_memory;
        t119_call_status = spore_lift_00f47380(memory, state);
        if (t119_call_status != BatchLiftStatus::returned) return t119_call_status;
        if (state.eip != 0x00455ebfu) return BatchLiftStatus::invalid_control_flow;
    // 0x00455ebf: 83c404 ADD
        t120a = state.regs[4];
        t120b = 0x00000004u;
        t120r = static_cast<std::uint32_t>(t120a + t120b) & 0xffffffffu;
        batch_set_add_flags(state, t120a, t120b, t120r, 32u);
        state.regs[4] = t120r;
    // 0x00455ec2: 8b55b8 MOV
    L_00455ec2:
        batch_guest_pc = 0x00455ec2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t121)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t121;
    // 0x00455ec5: 8b45e8 MOV
        batch_guest_pc = 0x00455ec5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t122)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t122;
    // 0x00455ec8: 8902 MOV
        batch_guest_pc = 0x00455ec8u;
        t123 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t123)) return BatchLiftStatus::invalid_memory;
    // 0x00455eca: 8b4db8 MOV
        batch_guest_pc = 0x00455ecau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t124)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t124;
    // 0x00455ecd: 8b55f0 MOV
        batch_guest_pc = 0x00455ecdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t125)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t125;
    // 0x00455ed0: 895104 MOV
        batch_guest_pc = 0x00455ed0u;
        t126 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t126)) return BatchLiftStatus::invalid_memory;
    // 0x00455ed3: 8b45e8 MOV
        batch_guest_pc = 0x00455ed3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t127)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t127;
    // 0x00455ed6: 0345ec ADD
        batch_guest_pc = 0x00455ed6u;
        t128a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t128b)) return BatchLiftStatus::invalid_memory;
        t128r = static_cast<std::uint32_t>(t128a + t128b) & 0xffffffffu;
        batch_set_add_flags(state, t128a, t128b, t128r, 32u);
        state.regs[0] = t128r;
    // 0x00455ed9: 8b4db8 MOV
        batch_guest_pc = 0x00455ed9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t129)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t129;
    // 0x00455edc: 894108 MOV
        batch_guest_pc = 0x00455edcu;
        t130 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t130)) return BatchLiftStatus::invalid_memory;
    // 0x00455edf: eb5b JMP
        goto L_00455f3c;
    // 0x00455ee1: 8b5508 MOV
    L_00455ee1:
        batch_guest_pc = 0x00455ee1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t132)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t132;
    // 0x00455ee4: 8955e4 MOV
        batch_guest_pc = 0x00455ee4u;
        t133 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t133)) return BatchLiftStatus::invalid_memory;
    // 0x00455ee7: 8b45e4 MOV
        batch_guest_pc = 0x00455ee7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t134)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t134;
    // 0x00455eea: 83c001 ADD
        t135a = state.regs[0];
        t135b = 0x00000001u;
        t135r = static_cast<std::uint32_t>(t135a + t135b) & 0xffffffffu;
        batch_set_add_flags(state, t135a, t135b, t135r, 32u);
        state.regs[0] = t135r;
    // 0x00455eed: 8945e4 MOV
        batch_guest_pc = 0x00455eedu;
        t136 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t136)) return BatchLiftStatus::invalid_memory;
    // 0x00455ef0: 8b4db8 MOV
        batch_guest_pc = 0x00455ef0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t137)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t137;
    // 0x00455ef3: 8b5104 MOV
        batch_guest_pc = 0x00455ef3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t138)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t138;
    // 0x00455ef6: 83c201 ADD
        t139a = state.regs[2];
        t139b = 0x00000001u;
        t139r = static_cast<std::uint32_t>(t139a + t139b) & 0xffffffffu;
        batch_set_add_flags(state, t139a, t139b, t139r, 32u);
        state.regs[2] = t139r;
    // 0x00455ef9: 8955bc MOV
        batch_guest_pc = 0x00455ef9u;
        t140 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffbcu), t140)) return BatchLiftStatus::invalid_memory;
    // 0x00455efc: 8b450c MOV
        batch_guest_pc = 0x00455efcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t141)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t141;
    // 0x00455eff: 2b45e4 SUB
        batch_guest_pc = 0x00455effu;
        t142a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t142b)) return BatchLiftStatus::invalid_memory;
        t142r = static_cast<std::uint32_t>(t142a - t142b) & 0xffffffffu;
        batch_set_sub_flags(state, t142a, t142b, t142r, 32u);
        state.regs[0] = t142r;
    // 0x00455f02: 50 PUSH
        batch_guest_pc = 0x00455f02u;
        t143a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t143a)) return BatchLiftStatus::invalid_memory;
    // 0x00455f03: 8b4de4 MOV
        batch_guest_pc = 0x00455f03u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t144)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t144;
    // 0x00455f06: 51 PUSH
        batch_guest_pc = 0x00455f06u;
        t145a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t145a)) return BatchLiftStatus::invalid_memory;
    // 0x00455f07: 8b55bc MOV
        batch_guest_pc = 0x00455f07u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffbcu), t146)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t146;
    // 0x00455f0a: 52 PUSH
        batch_guest_pc = 0x00455f0au;
        t147a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t147a)) return BatchLiftStatus::invalid_memory;
    // 0x00455f0b: e834a8d800 CALL
        t148_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00455f10u);
        if (t148_call_status != BatchLiftStatus::returned) return t148_call_status;
        if (state.eip != 0x00455f10u) return BatchLiftStatus::invalid_control_flow;
    // 0x00455f10: 83c40c ADD
        t149a = state.regs[4];
        t149b = 0x0000000cu;
        t149r = static_cast<std::uint32_t>(t149a + t149b) & 0xffffffffu;
        batch_set_add_flags(state, t149a, t149b, t149r, 32u);
        state.regs[4] = t149r;
    // 0x00455f13: 8b45b8 MOV
        batch_guest_pc = 0x00455f13u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t150)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t150;
    // 0x00455f16: 8b4804 MOV
        batch_guest_pc = 0x00455f16u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t151)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t151;
    // 0x00455f19: 8b55f8 MOV
        batch_guest_pc = 0x00455f19u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t152)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t152;
    // 0x00455f1c: c6041100 MOV
        batch_guest_pc = 0x00455f1cu;
        t153 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + state.regs[2] * 1u + 0x00000000u), t153)) return BatchLiftStatus::invalid_memory;
    // 0x00455f20: 8b45b8 MOV
        batch_guest_pc = 0x00455f20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t154)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t154;
    // 0x00455f23: 8b4804 MOV
        batch_guest_pc = 0x00455f23u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t155)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t155;
    // 0x00455f26: 8b5508 MOV
        batch_guest_pc = 0x00455f26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t156)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t156;
    // 0x00455f29: 8a02 MOV
        batch_guest_pc = 0x00455f29u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t157)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t157 << 0u) & 0x000000ffu);
    // 0x00455f2b: 8801 MOV
        batch_guest_pc = 0x00455f2bu;
        t158 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t158)) return BatchLiftStatus::invalid_memory;
    // 0x00455f2d: 8b4db8 MOV
        batch_guest_pc = 0x00455f2du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t159)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t159;
    // 0x00455f30: 8b5104 MOV
        batch_guest_pc = 0x00455f30u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t160)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t160;
    // 0x00455f33: 0355f8 ADD
        batch_guest_pc = 0x00455f33u;
        t161a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t161b)) return BatchLiftStatus::invalid_memory;
        t161r = static_cast<std::uint32_t>(t161a + t161b) & 0xffffffffu;
        batch_set_add_flags(state, t161a, t161b, t161r, 32u);
        state.regs[2] = t161r;
    // 0x00455f36: 8b45b8 MOV
        batch_guest_pc = 0x00455f36u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t162)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t162;
    // 0x00455f39: 895004 MOV
        batch_guest_pc = 0x00455f39u;
        t163 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t163)) return BatchLiftStatus::invalid_memory;
    // 0x00455f3c: 8b45b8 MOV
    L_00455f3c:
        batch_guest_pc = 0x00455f3cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffb8u), t164)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t164;
    // 0x00455f3f: 8be5 MOV
        t165 = state.regs[5];
        state.regs[4] = t165;
    // 0x00455f41: 5d POP
        batch_guest_pc = 0x00455f41u;
        if (!memory.load32(state.regs[4], t166a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t166a;
    // 0x00455f42: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
