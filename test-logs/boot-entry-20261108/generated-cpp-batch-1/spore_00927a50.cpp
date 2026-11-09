#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00926120(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926140(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926790(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009267e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926a10(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926a60(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00926fd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927700(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927a7c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927a85(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927aea(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00927b2a(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00927a50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00927a50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47 = 0;
    BatchLiftStatus t48_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;
    BatchLiftStatus t57_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61a = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65 = 0;
    BatchLiftStatus t66_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75 = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78 = 0;
    BatchLiftStatus t79_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t80a = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83 = 0;
    BatchLiftStatus t84_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t86 = 0;
    BatchLiftStatus t87_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90 = 0;
    std::uint32_t t91 = 0;
    std::uint32_t t92 = 0;
    std::uint32_t t93 = 0;
    std::uint32_t t94 = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t97 = 0;
    std::uint32_t t98 = 0;
    std::uint32_t t99 = 0;
    std::uint32_t t100 = 0;
    std::uint32_t t101 = 0;
    std::uint32_t t102 = 0;
    std::uint32_t t103a = 0;
    BatchLiftStatus t104_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t105a = 0, t105b = 0, t105r = 0;
    std::uint32_t t106 = 0;
    std::uint32_t t107a = 0;
    BatchLiftStatus t108_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t109a = 0, t109b = 0, t109r = 0;
    std::uint32_t t110 = 0;
    std::uint32_t t111 = 0;
    std::uint32_t t112a = 0;

    // 0x00927a50: 55 PUSH
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00927a53: 83ec18 SUB
        t2a = state.regs[4];
        t2b = 0x00000018u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00927a56: 894de8 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00927a59: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00927a5c: 0fbe880c050000 MOVSX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000050cu), t5a)) return BatchLiftStatus::invalid_memory;
        t5a = static_cast<std::uint32_t>((t5a ^ 0x00000080u) - 0x00000080u);
        state.regs[1] = t5a;
    // 0x00927a63: 83f901 CMP
        t6a = state.regs[1];
        t6b = 0x00000001u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00927a66: 753c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00927aa4;
    // 0x00927a68: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00927a6b: c6820c05000000 MOV
        t9 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x0000050cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00927a72: a1c08e6601 MOV
        if (!memory.load32(0x01668ec0u, t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00927a77: 8945fc MOV
        t11 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00927a7a: eb09 JMP
        goto L_00927a85;
    // 0x00927a7c: 8b4dfc MOV
    L_00927a7c:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00927a7f: 8b5108 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00927a82: 8955fc MOV
        t15 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00927a85: 837dfc00 CMP
    L_00927a85:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16a)) return BatchLiftStatus::invalid_memory;
        t16b = 0x00000000u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00927a89: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927aa4;
    // 0x00927a8b: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x00927a8e: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x00927a91: 51 PUSH
        t20a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a92: 6a00 PUSH
        t21a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a94: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00927a97: 52 PUSH
        t23a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00927a98: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x00927a9b: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x00927a9d: ffd1 CALL
        t26_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[1], 0x00927a9fu);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
    // 0x00927a9f: 83c40c ADD
        t27a = state.regs[4];
        t27b = 0x0000000cu;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[4] = t27r;
    // 0x00927aa2: ebd8 JMP
        goto L_00927a7c;
    // 0x00927aa4: 8b55e8 MOV
    L_00927aa4:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x00927aa7: 83bae404000000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x000004e4u), t30a)) return BatchLiftStatus::invalid_memory;
        t30b = 0x00000000u;
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
    // 0x00927aae: 7412 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927ac2;
    // 0x00927ab0: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x00927ab3: 8b88e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x000004e4u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00927ab9: 51 PUSH
        t34a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00927aba: e861e6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926120u, 0x00927abfu)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_00926120(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x00927abfu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927abf: 83c404 ADD
        t36a = state.regs[4];
        t36b = 0x00000004u;
        t36r = static_cast<std::uint32_t>(t36a + t36b) & 0xffffffffu;
        batch_set_add_flags(state, t36a, t36b, t36r, 32u);
        state.regs[4] = t36r;
    // 0x00927ac2: 8b55e8 MOV
    L_00927ac2:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t37;
    // 0x00927ac5: 0fb602 MOVZX
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t38a;
    // 0x00927ac8: 85c0 TEST
        t39a = state.regs[0];
        t39b = state.regs[0];
        t39r = (t39a & t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
    // 0x00927aca: 0f84be000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927b8e;
    // 0x00927ad0: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t41;
    // 0x00927ad3: c60100 MOV
        t42 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x00927ad6: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t43;
    // 0x00927ad9: e802edffff CALL
        if (!batch_guest_call32(memory, state, 0x009267e0u, 0x00927adeu)) return BatchLiftStatus::invalid_memory;
        t44_call_status = spore_lift_009267e0(memory, state);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x00927adeu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927ade: 85c0 TEST
        t45a = state.regs[0];
        t45b = state.regs[0];
        t45r = (t45a & t45b) & 0xffffffffu;
        batch_set_logic_flags(state, t45r, 32u);
    // 0x00927ae0: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927aea;
    // 0x00927ae2: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t47;
    // 0x00927ae5: e816fcffff CALL
        if (!batch_guest_call32(memory, state, 0x00927700u, 0x00927aeau)) return BatchLiftStatus::invalid_memory;
        t48_call_status = spore_lift_00927700(memory, state);
        if (t48_call_status != BatchLiftStatus::returned) return t48_call_status;
        if (state.eip != 0x00927aeau) return BatchLiftStatus::invalid_control_flow;
    // 0x00927aea: 8b55e8 MOV
    L_00927aea:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t49)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t49;
    // 0x00927aed: 81c29c040000 ADD
        t50a = state.regs[2];
        t50b = 0x0000049cu;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[2] = t50r;
    // 0x00927af3: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t51;
    // 0x00927af6: 3990a8040000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x000004a8u), t52a)) return BatchLiftStatus::invalid_memory;
        t52b = state.regs[2];
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
    // 0x00927afc: 742c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927b2a;
    // 0x00927afe: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t54;
    // 0x00927b01: 8b91a8040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x000004a8u), t55)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t55;
    // 0x00927b07: 52 PUSH
        t56a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b08: e8b3ecffff CALL
        if (!batch_guest_call32(memory, state, 0x009267c0u, 0x00927b0du)) return BatchLiftStatus::invalid_memory;
        t57_call_status = spore_lift_009267c0(memory, state);
        if (t57_call_status != BatchLiftStatus::returned) return t57_call_status;
        if (state.eip != 0x00927b0du) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b0d: 83c404 ADD
        t58a = state.regs[4];
        t58b = 0x00000004u;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x00927b10: 8945f8 MOV
        t59 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t59)) return BatchLiftStatus::invalid_memory;
    // 0x00927b13: 8b45f8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x00927b16: 50 PUSH
        t61a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b17: e874ecffff CALL
        if (!batch_guest_call32(memory, state, 0x00926790u, 0x00927b1cu)) return BatchLiftStatus::invalid_memory;
        t62_call_status = spore_lift_00926790(memory, state);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
        if (state.eip != 0x00927b1cu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b1c: 83c404 ADD
        t63a = state.regs[4];
        t63b = 0x00000004u;
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        state.regs[4] = t63r;
    // 0x00927b1f: 50 PUSH
        t64a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b20: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t65)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t65;
    // 0x00927b23: e8a8f4ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926fd0u, 0x00927b28u)) return BatchLiftStatus::invalid_memory;
        t66_call_status = spore_lift_00926fd0(memory, state);
        if (t66_call_status != BatchLiftStatus::returned) return t66_call_status;
        if (state.eip != 0x00927b28u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b28: ebc0 JMP
        goto L_00927aea;
    // 0x00927b2a: 8b4de8 MOV
    L_00927b2a:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t68)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t68;
    // 0x00927b2d: 81c148040000 ADD
        t69a = state.regs[1];
        t69b = 0x00000448u;
        t69r = static_cast<std::uint32_t>(t69a + t69b) & 0xffffffffu;
        batch_set_add_flags(state, t69a, t69b, t69r, 32u);
        state.regs[1] = t69r;
    // 0x00927b33: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t70;
    // 0x00927b36: 398a64040000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000464u), t71a)) return BatchLiftStatus::invalid_memory;
        t71b = state.regs[1];
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
    // 0x00927b3c: 7428 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927b66;
    // 0x00927b3e: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t73;
    // 0x00927b41: 8b8864040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000464u), t74)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t74;
    // 0x00927b47: 894df4 MOV
        t75 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t75)) return BatchLiftStatus::invalid_memory;
    // 0x00927b4a: 8b55f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t76)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t76;
    // 0x00927b4d: 52 PUSH
        t77a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b4e: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t78)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t78;
    // 0x00927b51: e8baeeffff CALL
        if (!batch_guest_call32(memory, state, 0x00926a10u, 0x00927b56u)) return BatchLiftStatus::invalid_memory;
        t79_call_status = spore_lift_00926a10(memory, state);
        if (t79_call_status != BatchLiftStatus::returned) return t79_call_status;
        if (state.eip != 0x00927b56u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b56: 6a01 PUSH
        t80a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t80a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b58: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t81;
    // 0x00927b5b: 50 PUSH
        t82a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x00927b5c: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x00927b5f: e8fceeffff CALL
        if (!batch_guest_call32(memory, state, 0x00926a60u, 0x00927b64u)) return BatchLiftStatus::invalid_memory;
        t84_call_status = spore_lift_00926a60(memory, state);
        if (t84_call_status != BatchLiftStatus::returned) return t84_call_status;
        if (state.eip != 0x00927b64u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b64: ebc4 JMP
        goto L_00927b2a;
    // 0x00927b66: 8b4de8 MOV
    L_00927b66:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t86)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t86;
    // 0x00927b69: e862ecffff CALL
        if (!batch_guest_call32(memory, state, 0x009267d0u, 0x00927b6eu)) return BatchLiftStatus::invalid_memory;
        t87_call_status = spore_lift_009267d0(memory, state);
        if (t87_call_status != BatchLiftStatus::returned) return t87_call_status;
        if (state.eip != 0x00927b6eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927b6e: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t88;
    // 0x00927b71: 898140040000 MOV
        t89 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000440u), t89)) return BatchLiftStatus::invalid_memory;
    // 0x00927b77: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t90)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t90;
    // 0x00927b7a: c7826804000000000000 MOV
        t91 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000468u), t91)) return BatchLiftStatus::invalid_memory;
    // 0x00927b84: 8b45e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t92)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t92;
    // 0x00927b87: c6806c04000000 MOV
        t93 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x0000046cu), t93)) return BatchLiftStatus::invalid_memory;
    // 0x00927b8e: 8b4de8 MOV
    L_00927b8e:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t94)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t94;
    // 0x00927b91: 83b9e404000000 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x000004e4u), t95a)) return BatchLiftStatus::invalid_memory;
        t95b = 0x00000000u;
        t95r = static_cast<std::uint32_t>(t95a - t95b) & 0xffffffffu;
        batch_set_sub_flags(state, t95a, t95b, t95r, 32u);
    // 0x00927b98: 7431 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00927bcb;
    // 0x00927b9a: 8b55e8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t97)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t97;
    // 0x00927b9d: 8b82e4040000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x000004e4u), t98)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t98;
    // 0x00927ba3: 8945f0 MOV
        t99 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t99)) return BatchLiftStatus::invalid_memory;
    // 0x00927ba6: 8b4de8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe8u), t100)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t100;
    // 0x00927ba9: c781e404000000000000 MOV
        t101 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x000004e4u), t101)) return BatchLiftStatus::invalid_memory;
    // 0x00927bb3: 8b55f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t102)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t102;
    // 0x00927bb6: 52 PUSH
        t103a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00927bb7: e884e5ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926140u, 0x00927bbcu)) return BatchLiftStatus::invalid_memory;
        t104_call_status = spore_lift_00926140(memory, state);
        if (t104_call_status != BatchLiftStatus::returned) return t104_call_status;
        if (state.eip != 0x00927bbcu) return BatchLiftStatus::invalid_control_flow;
    // 0x00927bbc: 83c404 ADD
        t105a = state.regs[4];
        t105b = 0x00000004u;
        t105r = static_cast<std::uint32_t>(t105a + t105b) & 0xffffffffu;
        batch_set_add_flags(state, t105a, t105b, t105r, 32u);
        state.regs[4] = t105r;
    // 0x00927bbf: 8b45f0 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u), t106)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t106;
    // 0x00927bc2: 50 PUSH
        t107a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t107a)) return BatchLiftStatus::invalid_memory;
    // 0x00927bc3: e878e7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00926340u, 0x00927bc8u)) return BatchLiftStatus::invalid_memory;
        t108_call_status = spore_lift_00926340(memory, state);
        if (t108_call_status != BatchLiftStatus::returned) return t108_call_status;
        if (state.eip != 0x00927bc8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00927bc8: 83c404 ADD
        t109a = state.regs[4];
        t109b = 0x00000004u;
        t109r = static_cast<std::uint32_t>(t109a + t109b) & 0xffffffffu;
        batch_set_add_flags(state, t109a, t109b, t109r, 32u);
        state.regs[4] = t109r;
    // 0x00927bcb: b001 MOV
    L_00927bcb:
        t110 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t110 << 0u) & 0x000000ffu);
    // 0x00927bcd: 8be5 MOV
        t111 = state.regs[5];
        state.regs[4] = t111;
    // 0x00927bcf: 5d POP
        if (!memory.load32(state.regs[4], t112a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t112a;
    // 0x00927bd0: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
