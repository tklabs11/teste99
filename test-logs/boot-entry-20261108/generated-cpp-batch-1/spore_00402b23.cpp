#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402c4f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00402c58(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00403694(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004259e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f740(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00533500(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f950(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690120(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00692400(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00402b23(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00402b23u);
    std::uint32_t t0a = 0;
    std::uint32_t t1t = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36 = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    BatchLiftStatus t63_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0;
    std::uint32_t t73 = 0;
    BatchLiftStatus t74_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0, t76b = 0, t76r = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79 = 0;
    std::uint32_t t80a = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82 = 0;
    std::uint32_t t83a = 0;
    std::uint32_t t84 = 0;
    BatchLiftStatus t85_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t86 = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89a = 0, t89b = 0, t89r = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91a = 0, t91b = 0, t91r = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95 = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98a = 0, t98b = 0, t98r = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0, t103b = 0, t103r = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t107 = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111a = 0, t111b = 0, t111r = 0;
    std::uint32_t t113 = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    BatchLiftStatus t117_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0;

    // 0x00402b23: 6800000000 PUSH
        t0a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00402b28: ff10 CALL
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t1t)) return BatchLiftStatus::invalid_memory;
        t1_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t1t, 0x00402b2au);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
    // 0x00402b2a: e9650b0000 JMP
        state.eip = 0x00403694u;
        return spore_lift_00403694(memory, state);
    // 0x00402b2f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00402b30: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00402b31: 8bec MOV
        t5 = state.regs[4];
        state.regs[5] = t5;
    // 0x00402b33: 81ec88000000 SUB
        t6a = state.regs[4];
        t6b = 0x00000088u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x00402b39: 898d78ffffff MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00402b3f: 8b8578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00402b45: 8b480c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t9;
    // 0x00402b48: 894dec MOV
        t10 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00402b4b: 837dec00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t11a)) return BatchLiftStatus::invalid_memory;
        t11b = 0x00000000u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
    // 0x00402b4f: 7454 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b51: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00402b57: 8b420c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00402b5a: 8945e8 MOV
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00402b5d: 6a01 PUSH
        t16a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00402b5f: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00402b62: e899f82800 CALL
        if (!batch_guest_call32(memory, state, 0x00692400u, 0x00402b67u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00692400(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00402b67u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402b67: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00402b6d: 83c10c ADD
        t20a = state.regs[1];
        t20b = 0x0000000cu;
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[1] = t20r;
    // 0x00402b70: 894de0 MOV
        t21 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00402b73: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00402b76: 833a00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t23a)) return BatchLiftStatus::invalid_memory;
        t23b = 0x00000000u;
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
    // 0x00402b79: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b7b: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t25;
    // 0x00402b7e: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t26;
    // 0x00402b80: 894de4 MOV
        t27 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t27)) return BatchLiftStatus::invalid_memory;
    // 0x00402b83: 33d2 XOR
        t28a = state.regs[2];
        t28b = state.regs[2];
        t28r = (t28a ^ t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
        state.regs[2] = t28r;
    // 0x00402b85: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402b8e;
    // 0x00402b87: 33c9 XOR
        t30a = state.regs[1];
        t30b = state.regs[1];
        t30r = (t30a ^ t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
        state.regs[1] = t30r;
    // 0x00402b89: e8c2cd2800 CALL
        if (!batch_guest_call32(memory, state, 0x0068f950u, 0x00402b8eu)) return BatchLiftStatus::invalid_memory;
        t31_call_status = spore_lift_0068f950(memory, state);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00402b8eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00402b8e: 8b45e0 MOV
    L_00402b8e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00402b91: c70000000000 MOV
        t33 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x00402b97: 837de400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t34a)) return BatchLiftStatus::invalid_memory;
        t34b = 0x00000000u;
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x00402b9b: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b9d: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t36;
    // 0x00402ba0: e87bd52800 CALL
        if (!batch_guest_call32(memory, state, 0x00690120u, 0x00402ba5u)) return BatchLiftStatus::invalid_memory;
        t37_call_status = spore_lift_00690120(memory, state);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x00402ba5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402ba5: 33c9 XOR
    L_00402ba5:
        t38a = state.regs[1];
        t38b = state.regs[1];
        t38r = (t38a ^ t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
        state.regs[1] = t38r;
    // 0x00402ba7: 894df0 MOV
        t39 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t39)) return BatchLiftStatus::invalid_memory;
    // 0x00402baa: c745f400000000 MOV
        t40 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00402bb1: c745f800000000 MOV
        t41 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00402bb8: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x00402bbe: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00402bc1: 8902 MOV
        t44 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00402bc3: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x00402bc6: 894a04 MOV
        t46 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00402bc9: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t47;
    // 0x00402bcc: 894208 MOV
        t48 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00402bcf: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t49;
    // 0x00402bd5: c6416400 MOV
        t50 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000064u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00402bd9: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x00402bdf: c6426500 MOV
        t52 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000065u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00402be3: 8b8578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t53;
    // 0x00402be9: 83c010 ADD
        t54a = state.regs[0];
        t54b = 0x00000010u;
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[0] = t54r;
    // 0x00402bec: 8945c4 MOV
        t55 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00402bef: 8b4dc4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t56;
    // 0x00402bf2: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t57;
    // 0x00402bf5: 52 PUSH
        t58a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
    // 0x00402bf6: 8b45c4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t59;
    // 0x00402bf9: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t60;
    // 0x00402bfb: 51 PUSH
        t61a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00402bfc: 8b4dc4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x00402bff: e83ccb1000 CALL
        if (!batch_guest_call32(memory, state, 0x0050f740u, 0x00402c04u)) return BatchLiftStatus::invalid_memory;
        t63_call_status = spore_lift_0050f740(memory, state);
        if (t63_call_status != BatchLiftStatus::returned) return t63_call_status;
        if (state.eip != 0x00402c04u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c04: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t64;
    // 0x00402c0a: 83c224 ADD
        t65a = state.regs[2];
        t65b = 0x00000024u;
        t65r = static_cast<std::uint32_t>(t65a + t65b) & 0xffffffffu;
        batch_set_add_flags(state, t65a, t65b, t65r, 32u);
        state.regs[2] = t65r;
    // 0x00402c0d: 8955a4 MOV
        t66 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x00402c10: 8b45a4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t67;
    // 0x00402c13: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t68;
    // 0x00402c16: 51 PUSH
        t69a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c17: 8b55a4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t70;
    // 0x00402c1a: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t71;
    // 0x00402c1c: 50 PUSH
        t72a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t72a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c1d: 8b4da4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t73;
    // 0x00402c20: e8db081300 CALL
        if (!batch_guest_call32(memory, state, 0x00533500u, 0x00402c25u)) return BatchLiftStatus::invalid_memory;
        t74_call_status = spore_lift_00533500(memory, state);
        if (t74_call_status != BatchLiftStatus::returned) return t74_call_status;
        if (state.eip != 0x00402c25u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c25: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t75;
    // 0x00402c2b: 83c138 ADD
        t76a = state.regs[1];
        t76b = 0x00000038u;
        t76r = static_cast<std::uint32_t>(t76a + t76b) & 0xffffffffu;
        batch_set_add_flags(state, t76a, t76b, t76r, 32u);
        state.regs[1] = t76r;
    // 0x00402c2e: 894d84 MOV
        t77 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t77)) return BatchLiftStatus::invalid_memory;
    // 0x00402c31: 8b5584 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t78;
    // 0x00402c34: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t79;
    // 0x00402c37: 50 PUSH
        t80a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c38: 8b4d84 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t81;
    // 0x00402c3b: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t82)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t82;
    // 0x00402c3d: 52 PUSH
        t83a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t83a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c3e: 8b4d84 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t84;
    // 0x00402c41: e89a2d0200 CALL
        if (!batch_guest_call32(memory, state, 0x004259e0u, 0x00402c46u)) return BatchLiftStatus::invalid_memory;
        t85_call_status = spore_lift_004259e0(memory, state);
        if (t85_call_status != BatchLiftStatus::returned) return t85_call_status;
        if (state.eip != 0x00402c46u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c46: c745fc00000000 MOV
        t86 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t86)) return BatchLiftStatus::invalid_memory;
    // 0x00402c4d: eb09 JMP
        goto L_00402c58;
    // 0x00402c4f: 8b45fc MOV
    L_00402c4f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t88;
    // 0x00402c52: 83c001 ADD
        t89a = state.regs[0];
        t89b = 0x00000001u;
        t89r = static_cast<std::uint32_t>(t89a + t89b) & 0xffffffffu;
        batch_set_add_flags(state, t89a, t89b, t89r, 32u);
        state.regs[0] = t89r;
    // 0x00402c55: 8945fc MOV
        t90 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t90)) return BatchLiftStatus::invalid_memory;
    // 0x00402c58: 837dfc06 CMP
    L_00402c58:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t91a)) return BatchLiftStatus::invalid_memory;
        t91b = 0x00000006u;
        t91r = static_cast<std::uint32_t>(t91a - t91b) & 0xffffffffu;
        batch_set_sub_flags(state, t91a, t91b, t91r, 32u);
    // 0x00402c5c: 7d5a JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00402cb8;
    // 0x00402c5e: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t93;
    // 0x00402c61: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t94;
    // 0x00402c67: 8d448a4c LEA
        t95 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 4u + 0x0000004cu);
        state.regs[0] = t95;
    // 0x00402c6b: 89857cffffff MOV
        t96 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t96)) return BatchLiftStatus::invalid_memory;
    // 0x00402c71: 8b8d7cffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t97;
    // 0x00402c77: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t98a)) return BatchLiftStatus::invalid_memory;
        t98b = 0x00000000u;
        t98r = static_cast<std::uint32_t>(t98a - t98b) & 0xffffffffu;
        batch_set_sub_flags(state, t98a, t98b, t98r, 32u);
    // 0x00402c7a: 743a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402cb6;
    // 0x00402c7c: 8b957cffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t100;
    // 0x00402c82: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t101)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t101;
    // 0x00402c84: 894580 MOV
        t102 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t102)) return BatchLiftStatus::invalid_memory;
    // 0x00402c87: 33c9 XOR
        t103a = state.regs[1];
        t103b = state.regs[1];
        t103r = (t103a ^ t103b) & 0xffffffffu;
        batch_set_logic_flags(state, t103r, 32u);
        state.regs[1] = t103r;
    // 0x00402c89: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402c97;
    // 0x00402c8b: 8b1500000000 MOV
        if (!memory.load32(0x00000000u, t105)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t105;
    // 0x00402c91: 33c9 XOR
        t106a = state.regs[1];
        t106b = state.regs[1];
        t106r = (t106a ^ t106b) & 0xffffffffu;
        batch_set_logic_flags(state, t106r, 32u);
        state.regs[1] = t106r;
    // 0x00402c93: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t107)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t107;
    // 0x00402c95: ffd0 CALL
        t108_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00402c97u);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
    // 0x00402c97: 8b8d7cffffff MOV
    L_00402c97:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t109)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t109;
    // 0x00402c9d: c70100000000 MOV
        t110 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t110)) return BatchLiftStatus::invalid_memory;
    // 0x00402ca3: 837d8000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t111a)) return BatchLiftStatus::invalid_memory;
        t111b = 0x00000000u;
        t111r = static_cast<std::uint32_t>(t111a - t111b) & 0xffffffffu;
        batch_set_sub_flags(state, t111a, t111b, t111r, 32u);
    // 0x00402ca7: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402cb6;
    // 0x00402ca9: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t113)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t113;
    // 0x00402cac: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t114;
    // 0x00402cae: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t115)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t115;
    // 0x00402cb1: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t116;
    // 0x00402cb4: ffd2 CALL
        t117_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00402cb6u);
        if (t117_call_status != BatchLiftStatus::returned) return t117_call_status;
    // 0x00402cb6: eb97 JMP
    L_00402cb6:
        goto L_00402c4f;
    // 0x00402cb8: 8be5 MOV
    L_00402cb8:
        t119 = state.regs[5];
        state.regs[4] = t119;
    // 0x00402cba: 5d POP
        if (!memory.load32(state.regs[4], t120a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t120a;
    // 0x00402cbb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
