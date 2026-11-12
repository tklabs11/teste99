#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921580(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924600(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0092472f(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925cb0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009246c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009246c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t39a = 0, t39b = 0, t39r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    BatchLiftStatus t49_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55 = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57 = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65 = 0;
    BatchLiftStatus t66_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t67a = 0;
    BatchLiftStatus t68_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73a = 0;
    std::uint32_t t74 = 0;
    std::uint32_t t75a = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77a = 0;
    std::uint32_t t78a = 0;

    // 0x009246c0: 51 PUSH
        batch_guest_pc = 0x009246c0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c1: 53 PUSH
        batch_guest_pc = 0x009246c1u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c2: 55 PUSH
        batch_guest_pc = 0x009246c2u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c3: 56 PUSH
        batch_guest_pc = 0x009246c3u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c4: 57 PUSH
        batch_guest_pc = 0x009246c4u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c5: 33db XOR
        t5a = state.regs[3];
        t5b = state.regs[3];
        t5r = (t5a ^ t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
        state.regs[3] = t5r;
    // 0x009246c7: 53 PUSH
        batch_guest_pc = 0x009246c7u;
        t6a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c8: 53 PUSH
        batch_guest_pc = 0x009246c8u;
        t7a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x009246c9: 53 PUSH
        batch_guest_pc = 0x009246c9u;
        t8a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x009246ca: 53 PUSH
        batch_guest_pc = 0x009246cau;
        t9a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x009246cb: 68c8de4301 PUSH
        batch_guest_pc = 0x009246cbu;
        t10a = 0x0143dec8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x009246d0: 6a3c PUSH
        batch_guest_pc = 0x009246d0u;
        t11a = 0x0000003cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x009246d2: 8be9 MOV
        t12 = state.regs[1];
        state.regs[5] = t12;
    // 0x009246d4: e8c72c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009246d9u)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_00f473a0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x009246d9u) return BatchLiftStatus::invalid_control_flow;
    // 0x009246d9: 8bf0 MOV
        t14 = state.regs[0];
        state.regs[6] = t14;
    // 0x009246db: 83c418 ADD
        t15a = state.regs[4];
        t15b = 0x00000018u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[4] = t15r;
    // 0x009246de: 3bf3 CMP
        t16a = state.regs[6];
        t16b = state.regs[3];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x009246e0: 744b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092472d;
    // 0x009246e2: c7069cdd4301 MOV
        batch_guest_pc = 0x009246e2u;
        t18 = 0x0143dd9cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x009246e8: 895e04 MOV
        batch_guest_pc = 0x009246e8u;
        t19 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x009246eb: b8ac7b6601 MOV
        t20 = 0x01667bacu;
        state.regs[0] = t20;
    // 0x009246f0: 894608 MOV
        batch_guest_pc = 0x009246f0u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x009246f3: 89460c MOV
        batch_guest_pc = 0x009246f3u;
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t22)) return BatchLiftStatus::invalid_memory;
    // 0x009246f6: c74610ad7b6601 MOV
        batch_guest_pc = 0x009246f6u;
        t23 = 0x01667badu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x009246fd: c7461801000000 MOV
        batch_guest_pc = 0x009246fdu;
        t24 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00924704: e8a7150000 CALL
        if (!batch_guest_call32(memory, state, 0x00925cb0u, 0x00924709u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_00925cb0(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00924709u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924709: 8d4e20 LEA
        t26 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[1] = t26;
    // 0x0092470c: 33d2 XOR
        t27a = state.regs[2];
        t27b = state.regs[2];
        t27r = (t27a ^ t27b) & 0xffffffffu;
        batch_set_logic_flags(state, t27r, 32u);
        state.regs[2] = t27r;
    // 0x0092470e: 895104 MOV
        batch_guest_pc = 0x0092470eu;
        t28 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00924711: 895108 MOV
        batch_guest_pc = 0x00924711u;
        t29 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00924714: 89510c MOV
        batch_guest_pc = 0x00924714u;
        t30 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t30)) return BatchLiftStatus::invalid_memory;
    // 0x00924717: 894634 MOV
        batch_guest_pc = 0x00924717u;
        t31 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x0092471a: 895e38 MOV
        batch_guest_pc = 0x0092471au;
        t32 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000038u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x0092471d: 8909 MOV
        batch_guest_pc = 0x0092471du;
        t33 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x0092471f: 894e24 MOV
        batch_guest_pc = 0x0092471fu;
        t34 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00924722: 895e28 MOV
        batch_guest_pc = 0x00924722u;
        t35 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t35)) return BatchLiftStatus::invalid_memory;
    // 0x00924725: 885e2c MOV
        batch_guest_pc = 0x00924725u;
        t36 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t36)) return BatchLiftStatus::invalid_memory;
    // 0x00924728: 895e30 MOV
        batch_guest_pc = 0x00924728u;
        t37 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t37)) return BatchLiftStatus::invalid_memory;
    // 0x0092472b: eb02 JMP
        goto L_0092472f;
    // 0x0092472d: 33f6 XOR
    L_0092472d:
        t39a = state.regs[6];
        t39b = state.regs[6];
        t39r = (t39a ^ t39b) & 0xffffffffu;
        batch_set_logic_flags(state, t39r, 32u);
        state.regs[6] = t39r;
    // 0x0092472f: 8b4500 MOV
    L_0092472f:
        batch_guest_pc = 0x0092472fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x00924732: 8b3e MOV
        batch_guest_pc = 0x00924732u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t41;
    // 0x00924734: 8b501c MOV
        batch_guest_pc = 0x00924734u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x00924737: 8bcd MOV
        t43 = state.regs[5];
        state.regs[1] = t43;
    // 0x00924739: 83c718 ADD
        t44a = state.regs[7];
        t44b = 0x00000018u;
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[7] = t44r;
    // 0x0092473c: ffd2 CALL
        t45_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0092473eu);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
    // 0x0092473e: 50 PUSH
        batch_guest_pc = 0x0092473eu;
        t46a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x0092473f: 8b07 MOV
        batch_guest_pc = 0x0092473fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t47)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t47;
    // 0x00924741: 8bce MOV
        t48 = state.regs[6];
        state.regs[1] = t48;
    // 0x00924743: ffd0 CALL
        t49_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924745u);
        if (t49_call_status != BatchLiftStatus::returned) return t49_call_status;
    // 0x00924745: 8b4d18 MOV
        batch_guest_pc = 0x00924745u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000018u), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t50;
    // 0x00924748: 51 PUSH
        batch_guest_pc = 0x00924748u;
        t51a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00924749: 8d542417 LEA
        t52 = static_cast<std::uint32_t>(state.regs[4] + 0x00000017u);
        state.regs[2] = t52;
    // 0x0092474d: 52 PUSH
        batch_guest_pc = 0x0092474du;
        t53a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x0092474e: 8bce MOV
        t54 = state.regs[6];
        state.regs[1] = t54;
    // 0x00924750: 885c241b MOV
        batch_guest_pc = 0x00924750u;
        t55 = state.regs[3] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000001bu), t55)) return BatchLiftStatus::invalid_memory;
    // 0x00924754: e8a7feffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924759u)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00924600(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x00924759u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924759: 8b7d24 MOV
        batch_guest_pc = 0x00924759u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000024u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t57;
    // 0x0092475c: 8d5d20 LEA
        t58 = static_cast<std::uint32_t>(state.regs[5] + 0x00000020u);
        state.regs[3] = t58;
    // 0x0092475f: 3bfb CMP
        t59a = state.regs[7];
        t59b = state.regs[3];
        t59r = static_cast<std::uint32_t>(t59a - t59b) & 0xffffffffu;
        batch_set_sub_flags(state, t59a, t59b, t59r, 32u);
    // 0x00924761: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924781;
    // 0x00924763: 8b4714 MOV
    L_00924763:
        batch_guest_pc = 0x00924763u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000014u), t61)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t61;
    // 0x00924766: 8b4f10 MOV
        batch_guest_pc = 0x00924766u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000010u), t62)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t62;
    // 0x00924769: 50 PUSH
        batch_guest_pc = 0x00924769u;
        t63a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x0092476a: 51 PUSH
        batch_guest_pc = 0x0092476au;
        t64a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
    // 0x0092476b: 8bce MOV
        t65 = state.regs[6];
        state.regs[1] = t65;
    // 0x0092476d: e88efeffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924772u)) return BatchLiftStatus::invalid_memory;
        t66_call_status = spore_lift_00924600(memory, state);
        if (t66_call_status != BatchLiftStatus::returned) return t66_call_status;
        if (state.eip != 0x00924772u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924772: 57 PUSH
        batch_guest_pc = 0x00924772u;
        t67a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
    // 0x00924773: e808ceffff CALL
        if (!batch_guest_call32(memory, state, 0x00921580u, 0x00924778u)) return BatchLiftStatus::invalid_memory;
        t68_call_status = spore_lift_00921580(memory, state);
        if (t68_call_status != BatchLiftStatus::returned) return t68_call_status;
        if (state.eip != 0x00924778u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924778: 8bf8 MOV
        t69 = state.regs[0];
        state.regs[7] = t69;
    // 0x0092477a: 83c404 ADD
        t70a = state.regs[4];
        t70b = 0x00000004u;
        t70r = static_cast<std::uint32_t>(t70a + t70b) & 0xffffffffu;
        batch_set_add_flags(state, t70a, t70b, t70r, 32u);
        state.regs[4] = t70r;
    // 0x0092477d: 3bfb CMP
        t71a = state.regs[7];
        t71b = state.regs[3];
        t71r = static_cast<std::uint32_t>(t71a - t71b) & 0xffffffffu;
        batch_set_sub_flags(state, t71a, t71b, t71r, 32u);
    // 0x0092477f: 75e2 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924763;
    // 0x00924781: 5f POP
    L_00924781:
        batch_guest_pc = 0x00924781u;
        if (!memory.load32(state.regs[4], t73a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t73a;
    // 0x00924782: 8bc6 MOV
        t74 = state.regs[6];
        state.regs[0] = t74;
    // 0x00924784: 5e POP
        batch_guest_pc = 0x00924784u;
        if (!memory.load32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t75a;
    // 0x00924785: 5d POP
        batch_guest_pc = 0x00924785u;
        if (!memory.load32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t76a;
    // 0x00924786: 5b POP
        batch_guest_pc = 0x00924786u;
        if (!memory.load32(state.regs[4], t77a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t77a;
    // 0x00924787: 59 POP
        batch_guest_pc = 0x00924787u;
        if (!memory.load32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t78a;
    // 0x00924788: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
