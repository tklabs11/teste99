#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00402c4f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00402c58(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004259e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0050f740(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00533500(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0068f950(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00690120(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00692400(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00402b30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00402b30u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    BatchLiftStatus t33_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
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
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58 = 0;
    BatchLiftStatus t59_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69 = 0;
    BatchLiftStatus t70_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t71 = 0;
    std::uint32_t t72a = 0, t72b = 0, t72r = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77 = 0;
    std::uint32_t t78 = 0;
    std::uint32_t t79a = 0;
    std::uint32_t t80 = 0;
    BatchLiftStatus t81_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t82 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;
    std::uint32_t t86 = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;
    std::uint32_t t96 = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99a = 0, t99b = 0, t99r = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102a = 0, t102b = 0, t102r = 0;
    std::uint32_t t103 = 0;
    BatchLiftStatus t104_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t105 = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0, t107b = 0, t107r = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112 = 0;
    BatchLiftStatus t113_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t115 = 0;
    std::uint32_t t116a = 0;

    // 0x00402b30: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00402b31: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00402b33: 81ec88000000 SUB
        t2a = state.regs[4];
        t2b = 0x00000088u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00402b39: 898d78ffffff MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00402b3f: 8b8578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00402b45: 8b480c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00402b48: 894dec MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00402b4b: 837dec00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffecu), t7a)) return BatchLiftStatus::invalid_memory;
        t7b = 0x00000000u;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00402b4f: 7454 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b51: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00402b57: 8b420c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00402b5a: 8945e8 MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00402b5d: 6a01 PUSH
        t12a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00402b5f: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00402b62: e899f82800 CALL
        if (!batch_guest_call32(memory, state, 0x00692400u, 0x00402b67u)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00692400(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00402b67u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402b67: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00402b6d: 83c10c ADD
        t16a = state.regs[1];
        t16b = 0x0000000cu;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x00402b70: 894de0 MOV
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00402b73: 8b55e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00402b76: 833a00 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t19a)) return BatchLiftStatus::invalid_memory;
        t19b = 0x00000000u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
    // 0x00402b79: 742a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b7b: 8b45e0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00402b7e: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t22;
    // 0x00402b80: 894de4 MOV
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00402b83: 33d2 XOR
        t24a = state.regs[2];
        t24b = state.regs[2];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[2] = t24r;
    // 0x00402b85: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402b8e;
    // 0x00402b87: 33c9 XOR
        t26a = state.regs[1];
        t26b = state.regs[1];
        t26r = (t26a ^ t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[1] = t26r;
    // 0x00402b89: e8c2cd2800 CALL
        if (!batch_guest_call32(memory, state, 0x0068f950u, 0x00402b8eu)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_0068f950(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00402b8eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00402b8e: 8b45e0 MOV
    L_00402b8e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe0u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00402b91: c70000000000 MOV
        t29 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00402b97: 837de400 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t30a)) return BatchLiftStatus::invalid_memory;
        t30b = 0x00000000u;
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x00402b9b: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402ba5;
    // 0x00402b9d: 8b4de4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x00402ba0: e87bd52800 CALL
        if (!batch_guest_call32(memory, state, 0x00690120u, 0x00402ba5u)) return BatchLiftStatus::invalid_memory;
        t33_call_status = spore_lift_00690120(memory, state);
        if (t33_call_status != BatchLiftStatus::returned) return t33_call_status;
        if (state.eip != 0x00402ba5u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402ba5: 33c9 XOR
    L_00402ba5:
        t34a = state.regs[1];
        t34b = state.regs[1];
        t34r = (t34a ^ t34b) & 0xffffffffu;
        batch_set_logic_flags(state, t34r, 32u);
        state.regs[1] = t34r;
    // 0x00402ba7: 894df0 MOV
        t35 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00402baa: c745f400000000 MOV
        t36 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00402bb1: c745f800000000 MOV
        t37 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x00402bb8: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00402bbe: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x00402bc1: 8902 MOV
        t40 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00402bc3: 8b4df4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t41;
    // 0x00402bc6: 894a04 MOV
        t42 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00402bc9: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00402bcc: 894208 MOV
        t44 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00402bcf: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x00402bd5: c6416400 MOV
        t46 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000064u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00402bd9: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t47;
    // 0x00402bdf: c6426500 MOV
        t48 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000065u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00402be3: 8b8578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t49;
    // 0x00402be9: 83c010 ADD
        t50a = state.regs[0];
        t50b = 0x00000010u;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[0] = t50r;
    // 0x00402bec: 8945c4 MOV
        t51 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00402bef: 8b4dc4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t52;
    // 0x00402bf2: 8b5104 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t53;
    // 0x00402bf5: 52 PUSH
        t54a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00402bf6: 8b45c4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t55)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t55;
    // 0x00402bf9: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t56;
    // 0x00402bfb: 51 PUSH
        t57a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00402bfc: 8b4dc4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffc4u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t58;
    // 0x00402bff: e83ccb1000 CALL
        if (!batch_guest_call32(memory, state, 0x0050f740u, 0x00402c04u)) return BatchLiftStatus::invalid_memory;
        t59_call_status = spore_lift_0050f740(memory, state);
        if (t59_call_status != BatchLiftStatus::returned) return t59_call_status;
        if (state.eip != 0x00402c04u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c04: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t60;
    // 0x00402c0a: 83c224 ADD
        t61a = state.regs[2];
        t61b = 0x00000024u;
        t61r = static_cast<std::uint32_t>(t61a + t61b) & 0xffffffffu;
        batch_set_add_flags(state, t61a, t61b, t61r, 32u);
        state.regs[2] = t61r;
    // 0x00402c0d: 8955a4 MOV
        t62 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t62)) return BatchLiftStatus::invalid_memory;
    // 0x00402c10: 8b45a4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t63)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t63;
    // 0x00402c13: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t64;
    // 0x00402c16: 51 PUSH
        t65a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c17: 8b55a4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t66;
    // 0x00402c1a: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t67;
    // 0x00402c1c: 50 PUSH
        t68a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c1d: 8b4da4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffa4u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t69;
    // 0x00402c20: e8db081300 CALL
        if (!batch_guest_call32(memory, state, 0x00533500u, 0x00402c25u)) return BatchLiftStatus::invalid_memory;
        t70_call_status = spore_lift_00533500(memory, state);
        if (t70_call_status != BatchLiftStatus::returned) return t70_call_status;
        if (state.eip != 0x00402c25u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c25: 8b8d78ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t71)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t71;
    // 0x00402c2b: 83c138 ADD
        t72a = state.regs[1];
        t72b = 0x00000038u;
        t72r = static_cast<std::uint32_t>(t72a + t72b) & 0xffffffffu;
        batch_set_add_flags(state, t72a, t72b, t72r, 32u);
        state.regs[1] = t72r;
    // 0x00402c2e: 894d84 MOV
        t73 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t73)) return BatchLiftStatus::invalid_memory;
    // 0x00402c31: 8b5584 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t74;
    // 0x00402c34: 8b4204 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t75;
    // 0x00402c37: 50 PUSH
        t76a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c38: 8b4d84 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t77;
    // 0x00402c3b: 8b11 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t78;
    // 0x00402c3d: 52 PUSH
        t79a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
    // 0x00402c3e: 8b4d84 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff84u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t80;
    // 0x00402c41: e89a2d0200 CALL
        if (!batch_guest_call32(memory, state, 0x004259e0u, 0x00402c46u)) return BatchLiftStatus::invalid_memory;
        t81_call_status = spore_lift_004259e0(memory, state);
        if (t81_call_status != BatchLiftStatus::returned) return t81_call_status;
        if (state.eip != 0x00402c46u) return BatchLiftStatus::invalid_control_flow;
    // 0x00402c46: c745fc00000000 MOV
        t82 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t82)) return BatchLiftStatus::invalid_memory;
    // 0x00402c4d: eb09 JMP
        goto L_00402c58;
    // 0x00402c4f: 8b45fc MOV
    L_00402c4f:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t84)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t84;
    // 0x00402c52: 83c001 ADD
        t85a = state.regs[0];
        t85b = 0x00000001u;
        t85r = static_cast<std::uint32_t>(t85a + t85b) & 0xffffffffu;
        batch_set_add_flags(state, t85a, t85b, t85r, 32u);
        state.regs[0] = t85r;
    // 0x00402c55: 8945fc MOV
        t86 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t86)) return BatchLiftStatus::invalid_memory;
    // 0x00402c58: 837dfc06 CMP
    L_00402c58:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t87a)) return BatchLiftStatus::invalid_memory;
        t87b = 0x00000006u;
        t87r = static_cast<std::uint32_t>(t87a - t87b) & 0xffffffffu;
        batch_set_sub_flags(state, t87a, t87b, t87r, 32u);
    // 0x00402c5c: 7d5a JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00402cb8;
    // 0x00402c5e: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t89;
    // 0x00402c61: 8b9578ffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff78u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t90;
    // 0x00402c67: 8d448a4c LEA
        t91 = static_cast<std::uint32_t>(state.regs[2] + state.regs[1] * 4u + 0x0000004cu);
        state.regs[0] = t91;
    // 0x00402c6b: 89857cffffff MOV
        t92 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t92)) return BatchLiftStatus::invalid_memory;
    // 0x00402c71: 8b8d7cffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t93)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t93;
    // 0x00402c77: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t94a)) return BatchLiftStatus::invalid_memory;
        t94b = 0x00000000u;
        t94r = static_cast<std::uint32_t>(t94a - t94b) & 0xffffffffu;
        batch_set_sub_flags(state, t94a, t94b, t94r, 32u);
    // 0x00402c7a: 743a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402cb6;
    // 0x00402c7c: 8b957cffffff MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t96)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t96;
    // 0x00402c82: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t97;
    // 0x00402c84: 894580 MOV
        t98 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t98)) return BatchLiftStatus::invalid_memory;
    // 0x00402c87: 33c9 XOR
        t99a = state.regs[1];
        t99b = state.regs[1];
        t99r = (t99a ^ t99b) & 0xffffffffu;
        batch_set_logic_flags(state, t99r, 32u);
        state.regs[1] = t99r;
    // 0x00402c89: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402c97;
    // 0x00402c8b: 8b1500000000 MOV
        if (!memory.load32(0x00000000u, t101)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t101;
    // 0x00402c91: 33c9 XOR
        t102a = state.regs[1];
        t102b = state.regs[1];
        t102r = (t102a ^ t102b) & 0xffffffffu;
        batch_set_logic_flags(state, t102r, 32u);
        state.regs[1] = t102r;
    // 0x00402c93: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t103)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t103;
    // 0x00402c95: ffd0 CALL
        t104_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00402c97u);
        if (t104_call_status != BatchLiftStatus::returned) return t104_call_status;
    // 0x00402c97: 8b8d7cffffff MOV
    L_00402c97:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff7cu), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t105;
    // 0x00402c9d: c70100000000 MOV
        t106 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t106)) return BatchLiftStatus::invalid_memory;
    // 0x00402ca3: 837d8000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t107a)) return BatchLiftStatus::invalid_memory;
        t107b = 0x00000000u;
        t107r = static_cast<std::uint32_t>(t107a - t107b) & 0xffffffffu;
        batch_set_sub_flags(state, t107a, t107b, t107r, 32u);
    // 0x00402ca7: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00402cb6;
    // 0x00402ca9: 8b5580 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t109)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t109;
    // 0x00402cac: 8b02 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t110;
    // 0x00402cae: 8b4d80 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffff80u), t111)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t111;
    // 0x00402cb1: 8b5004 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t112)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t112;
    // 0x00402cb4: ffd2 CALL
        t113_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00402cb6u);
        if (t113_call_status != BatchLiftStatus::returned) return t113_call_status;
    // 0x00402cb6: eb97 JMP
    L_00402cb6:
        goto L_00402c4f;
    // 0x00402cb8: 8be5 MOV
    L_00402cb8:
        t115 = state.regs[5];
        state.regs[4] = t115;
    // 0x00402cba: 5d POP
        if (!memory.load32(state.regs[4], t116a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t116a;
    // 0x00402cbb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
