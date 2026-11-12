#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009233e0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924790(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697d06(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697d06u);
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
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    BatchLiftStatus t53_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0, t56b = 0, t56r = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60 = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t62a = 0;
    std::uint32_t t63 = 0;
    std::uint32_t t64 = 0;
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t71 = 0;
    BatchLiftStatus t72_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76 = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78a = 0, t78b = 0, t78r = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    BatchLiftStatus t82_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t83 = 0;
    std::uint32_t t84 = 0;
    std::uint32_t t85a = 0, t85b = 0, t85r = 0;

    // 0x00697d06: 8b5e30 MOV
        batch_guest_pc = 0x00697d06u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t0;
    // 0x00697d09: c744241cffffffff MOV
        batch_guest_pc = 0x00697d09u;
        t1 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t1)) return BatchLiftStatus::invalid_memory;
    // 0x00697d11: 3bfb CMP
        t2a = state.regs[7];
        t2b = state.regs[3];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x00697d13: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d15: 85ff TEST
        t4a = state.regs[7];
        t4b = state.regs[7];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00697d17: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d21;
    // 0x00697d19: 8b07 MOV
        batch_guest_pc = 0x00697d19u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00697d1b: 8b10 MOV
        batch_guest_pc = 0x00697d1bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00697d1d: 8bcf MOV
        t8 = state.regs[7];
        state.regs[1] = t8;
    // 0x00697d1f: ffd2 CALL
        t9_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d21u);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
    // 0x00697d21: 897e30 MOV
    L_00697d21:
        batch_guest_pc = 0x00697d21u;
        t10 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00697d24: 85db TEST
        t11a = state.regs[3];
        t11b = state.regs[3];
        t11r = (t11a & t11b) & 0xffffffffu;
        batch_set_logic_flags(state, t11r, 32u);
    // 0x00697d26: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697d31;
    // 0x00697d28: 8b03 MOV
        batch_guest_pc = 0x00697d28u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00697d2a: 8b5004 MOV
        batch_guest_pc = 0x00697d2au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00697d2d: 8bcb MOV
        t15 = state.regs[3];
        state.regs[1] = t15;
    // 0x00697d2f: ffd2 CALL
        t16_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d31u);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
    // 0x00697d31: 8bce MOV
    L_00697d31:
        t17 = state.regs[6];
        state.regs[1] = t17;
    // 0x00697d33: e858ca2800 CALL
        if (!batch_guest_call32(memory, state, 0x00924790u, 0x00697d38u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00924790(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00697d38u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697d38: 8b06 MOV
        batch_guest_pc = 0x00697d38u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00697d3a: 8b5030 MOV
        batch_guest_pc = 0x00697d3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x00697d3d: 68fb000000 PUSH
        batch_guest_pc = 0x00697d3du;
        t21a = 0x000000fbu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d42: 6a00 PUSH
        batch_guest_pc = 0x00697d42u;
        t22a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d44: 6a00 PUSH
        batch_guest_pc = 0x00697d44u;
        t23a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d46: 8bce MOV
        t24 = state.regs[6];
        state.regs[1] = t24;
    // 0x00697d48: ffd2 CALL
        t25_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d4au);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
    // 0x00697d4a: 8b06 MOV
        batch_guest_pc = 0x00697d4au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t26)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t26;
    // 0x00697d4c: 8b5030 MOV
        batch_guest_pc = 0x00697d4cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x00697d4f: 6a19 PUSH
        batch_guest_pc = 0x00697d4fu;
        t28a = 0x00000019u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d51: 6a00 PUSH
        batch_guest_pc = 0x00697d51u;
        t29a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d53: 6850824001 PUSH
        batch_guest_pc = 0x00697d53u;
        t30a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d58: 8bce MOV
        t31 = state.regs[6];
        state.regs[1] = t31;
    // 0x00697d5a: ffd2 CALL
        t32_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d5cu);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
    // 0x00697d5c: 8b06 MOV
        batch_guest_pc = 0x00697d5cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t33;
    // 0x00697d5e: 8b5030 MOV
        batch_guest_pc = 0x00697d5eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t34;
    // 0x00697d61: 6a32 PUSH
        batch_guest_pc = 0x00697d61u;
        t35a = 0x00000032u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d63: 6a00 PUSH
        batch_guest_pc = 0x00697d63u;
        t36a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d65: 6840824001 PUSH
        batch_guest_pc = 0x00697d65u;
        t37a = 0x01408240u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t37a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d6a: 8bce MOV
        t38 = state.regs[6];
        state.regs[1] = t38;
    // 0x00697d6c: ffd2 CALL
        t39_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d6eu);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
    // 0x00697d6e: c744240c00000000 MOV
        batch_guest_pc = 0x00697d6eu;
        t40 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00697d76: 8b06 MOV
        batch_guest_pc = 0x00697d76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t41;
    // 0x00697d78: 8b502c MOV
        batch_guest_pc = 0x00697d78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x00697d7b: 8d4c240c LEA
        t43 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t43;
    // 0x00697d7f: 51 PUSH
        batch_guest_pc = 0x00697d7fu;
        t44a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d80: bb02000000 MOV
        t45 = 0x00000002u;
        state.regs[3] = t45;
    // 0x00697d85: 6850824001 PUSH
        batch_guest_pc = 0x00697d85u;
        t46a = 0x01408250u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x00697d8a: 8bce MOV
        t47 = state.regs[6];
        state.regs[1] = t47;
    // 0x00697d8c: 895c2424 MOV
        batch_guest_pc = 0x00697d8cu;
        t48 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t48)) return BatchLiftStatus::invalid_memory;
    // 0x00697d90: ffd2 CALL
        t49_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d92u);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
    // 0x00697d92: 8b4c240c MOV
        batch_guest_pc = 0x00697d92u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x00697d96: 8b01 MOV
        batch_guest_pc = 0x00697d96u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t51;
    // 0x00697d98: 8b5038 MOV
        batch_guest_pc = 0x00697d98u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x00697d9b: ffd2 CALL
        t53_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697d9du);
        if (t53_call_status != BatchLiftStatus::returned) return t53_call_status;
    // 0x00697d9d: 8bf0 MOV
        t54 = state.regs[0];
        state.regs[6] = t54;
    // 0x00697d9f: 89742410 MOV
        batch_guest_pc = 0x00697d9fu;
        t55 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00697da3: 85f6 TEST
        t56a = state.regs[6];
        t56b = state.regs[6];
        t56r = (t56a & t56b) & 0xffffffffu;
        batch_set_logic_flags(state, t56r, 32u);
    // 0x00697da5: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697daf;
    // 0x00697da7: 8b06 MOV
        batch_guest_pc = 0x00697da7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t58)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t58;
    // 0x00697da9: 8b10 MOV
        batch_guest_pc = 0x00697da9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t59;
    // 0x00697dab: 8bce MOV
        t60 = state.regs[6];
        state.regs[1] = t60;
    // 0x00697dad: ffd2 CALL
        t61_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dafu);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
    // 0x00697daf: 6a15 PUSH
    L_00697daf:
        batch_guest_pc = 0x00697dafu;
        t62a = 0x00000015u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
    // 0x00697db1: 8bce MOV
        t63 = state.regs[6];
        state.regs[1] = t63;
    // 0x00697db3: c644242003 MOV
        batch_guest_pc = 0x00697db3u;
        t64 = 0x00000003u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t64)) return BatchLiftStatus::invalid_memory;
    // 0x00697db8: e823b62800 CALL
        if (!batch_guest_call32(memory, state, 0x009233e0u, 0x00697dbdu)) return BatchLiftStatus::invalid_memory;
        t65_call_status = spore_lift_009233e0(memory, state);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x00697dbdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697dbd: 885c241c MOV
        batch_guest_pc = 0x00697dbdu;
        t66 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t66)) return BatchLiftStatus::invalid_memory;
    // 0x00697dc1: 85f6 TEST
        t67a = state.regs[6];
        t67b = state.regs[6];
        t67r = (t67a & t67b) & 0xffffffffu;
        batch_set_logic_flags(state, t67r, 32u);
    // 0x00697dc3: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697dce;
    // 0x00697dc5: 8b06 MOV
        batch_guest_pc = 0x00697dc5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t69;
    // 0x00697dc7: 8b5004 MOV
        batch_guest_pc = 0x00697dc7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t70)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t70;
    // 0x00697dca: 8bce MOV
        t71 = state.regs[6];
        state.regs[1] = t71;
    // 0x00697dcc: ffd2 CALL
        t72_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697dceu);
        if (t72_call_status != BatchLiftStatus::returned) return t72_call_status;
    // 0x00697dce: 8b4c240c MOV
    L_00697dce:
        batch_guest_pc = 0x00697dceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t73;
    // 0x00697dd2: 5f POP
        batch_guest_pc = 0x00697dd2u;
        if (!memory.load32(state.regs[4], t74a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t74a;
    // 0x00697dd3: 5e POP
        batch_guest_pc = 0x00697dd3u;
        if (!memory.load32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t75a;
    // 0x00697dd4: c7442414ffffffff MOV
        batch_guest_pc = 0x00697dd4u;
        t76 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t76)) return BatchLiftStatus::invalid_memory;
    // 0x00697ddc: 5b POP
        batch_guest_pc = 0x00697ddcu;
        if (!memory.load32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t77a;
    // 0x00697ddd: 85c9 TEST
        t78a = state.regs[1];
        t78b = state.regs[1];
        t78r = (t78a & t78b) & 0xffffffffu;
        batch_set_logic_flags(state, t78r, 32u);
    // 0x00697ddf: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697de8;
    // 0x00697de1: 8b01 MOV
        batch_guest_pc = 0x00697de1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t80;
    // 0x00697de3: 8b5004 MOV
        batch_guest_pc = 0x00697de3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t81;
    // 0x00697de6: ffd2 CALL
        t82_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697de8u);
        if (t82_call_status != BatchLiftStatus::returned) return t82_call_status;
    // 0x00697de8: 8b4c2408 MOV
    L_00697de8:
        batch_guest_pc = 0x00697de8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t83;
    // 0x00697dec: 64890d00000000 MOV
        batch_guest_pc = 0x00697decu;
        t84 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t84)) return BatchLiftStatus::invalid_memory;
    // 0x00697df3: 83c414 ADD
        t85a = state.regs[4];
        t85b = 0x00000014u;
        t85r = static_cast<std::uint32_t>(t85a + t85b) & 0xffffffffu;
        batch_set_add_flags(state, t85a, t85b, t85r, 32u);
        state.regs[4] = t85r;
    // 0x00697df6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
