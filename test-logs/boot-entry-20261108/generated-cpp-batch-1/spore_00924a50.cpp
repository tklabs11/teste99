#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923bc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924600(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924b0c(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924b69(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00924ba8(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00e25bd0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924a50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924a50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    BatchLiftStatus t39_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44 = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51a = 0;
    BatchLiftStatus t52_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0, t57b = 0, t57r = 0;
    std::uint32_t t59 = 0;
    std::uint32_t t60a = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63a = 0;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    BatchLiftStatus t66_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t68 = 0;
    std::uint32_t t69 = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    BatchLiftStatus t74_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t75 = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77 = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79a = 0, t79b = 0, t79r = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0;
    std::uint32_t t85 = 0;
    std::uint32_t t86a = 0, t86b = 0, t86r = 0;
    std::uint32_t t88 = 0;
    std::uint32_t t89 = 0;
    std::uint32_t t90a = 0;
    BatchLiftStatus t91_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t92 = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t95a = 0, t95b = 0, t95r = 0;
    std::uint32_t t97a = 0;
    BatchLiftStatus t98_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t100a = 0;
    std::uint32_t t101a = 0;
    BatchLiftStatus t102_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t103a = 0;
    std::uint32_t t104 = 0;
    std::uint32_t t105 = 0;
    std::uint32_t t106a = 0, t106b = 0, t106r = 0;
    std::uint32_t t108 = 0;
    std::uint32_t t109 = 0;
    std::uint32_t t110 = 0;
    BatchLiftStatus t111_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t112a = 0, t112b = 0, t112r = 0;
    std::uint32_t t114 = 0;
    std::uint32_t t115 = 0;
    std::uint32_t t116 = 0;
    std::uint32_t t117a = 0;
    BatchLiftStatus t118_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t119 = 0;
    std::uint32_t t120a = 0, t120b = 0, t120r = 0;
    std::uint32_t t122a = 0, t122b = 0, t122r = 0;
    std::uint32_t t124a = 0;
    BatchLiftStatus t125_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t127a = 0;
    std::uint32_t t128a = 0;
    BatchLiftStatus t129_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t130a = 0, t130b = 0, t130r = 0;
    std::uint32_t t131a = 0, t131b = 0, t131r = 0;
    std::uint32_t t133a = 0;
    std::uint32_t t134a = 0;
    std::uint32_t t135a = 0;
    std::uint32_t t136 = 0;
    BatchLiftStatus t137_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t138 = 0;
    std::uint32_t t139a = 0;
    std::uint32_t t140a = 0, t140b = 0, t140r = 0;

    // 0x00924a50: 56 PUSH
        batch_guest_pc = 0x00924a50u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a51: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00924a53: 57 PUSH
        batch_guest_pc = 0x00924a53u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a54: 8d7e38 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[7] = t3;
    // 0x00924a57: 6878dc4301 PUSH
        batch_guest_pc = 0x00924a57u;
        t4a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a5c: 8bcf MOV
        t5 = state.regs[7];
        state.regs[1] = t5;
    // 0x00924a5e: e84dd7ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00924a63u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00924a63u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a63: 8b461c MOV
        batch_guest_pc = 0x00924a63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00924a66: 8b5618 MOV
        batch_guest_pc = 0x00924a66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00924a69: 8d4e18 LEA
        t9 = static_cast<std::uint32_t>(state.regs[6] + 0x00000018u);
        state.regs[1] = t9;
    // 0x00924a6c: 50 PUSH
        batch_guest_pc = 0x00924a6cu;
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a6d: 52 PUSH
        batch_guest_pc = 0x00924a6du;
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a6e: e85d115000 CALL
        if (!batch_guest_call32(memory, state, 0x00e25bd0u, 0x00924a73u)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00e25bd0(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00924a73u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a73: 8bcf MOV
        t13 = state.regs[7];
        state.regs[1] = t13;
    // 0x00924a75: 5f POP
        batch_guest_pc = 0x00924a75u;
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t14a;
    // 0x00924a76: 5e POP
        batch_guest_pc = 0x00924a76u;
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t15a;
    // 0x00924a77: e9f4d7ffff JMP
        state.eip = 0x00922270u;
        return spore_lift_00922270(memory, state);
    // 0x00924a7c: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00924a7d: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00924a7e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00924a7f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00924a80: 83ec08 SUB
        t21a = state.regs[4];
        t21b = 0x00000008u;
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x00924a83: 56 PUSH
        batch_guest_pc = 0x00924a83u;
        t22a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a84: 8bf1 MOV
        t23 = state.regs[1];
        state.regs[6] = t23;
    // 0x00924a86: 8d4e38 LEA
        t24 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[1] = t24;
    // 0x00924a89: 6878dc4301 PUSH
        batch_guest_pc = 0x00924a89u;
        t25a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00924a8e: 894c240c MOV
        batch_guest_pc = 0x00924a8eu;
        t26 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00924a92: e819d7ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00924a97u)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_009221b0(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00924a97u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924a97: 8b442410 MOV
        batch_guest_pc = 0x00924a97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00924a9b: c644240701 MOV
        batch_guest_pc = 0x00924a9bu;
        t29 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00924aa0: 85c0 TEST
        t30a = state.regs[0];
        t30b = state.regs[0];
        t30r = (t30a & t30b) & 0xffffffffu;
        batch_set_logic_flags(state, t30r, 32u);
    // 0x00924aa2: 0f848b000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b33;
    // 0x00924aa8: 8b16 MOV
        batch_guest_pc = 0x00924aa8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t32;
    // 0x00924aaa: 8b522c MOV
        batch_guest_pc = 0x00924aaau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000002cu), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t33;
    // 0x00924aad: 8d4c2410 LEA
        t34 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t34;
    // 0x00924ab1: 51 PUSH
        batch_guest_pc = 0x00924ab1u;
        t35a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ab2: 50 PUSH
        batch_guest_pc = 0x00924ab2u;
        t36a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ab3: 8bce MOV
        t37 = state.regs[6];
        state.regs[1] = t37;
    // 0x00924ab5: c744241800000000 MOV
        batch_guest_pc = 0x00924ab5u;
        t38 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t38)) return BatchLiftStatus::invalid_memory;
    // 0x00924abd: ffd2 CALL
        t39_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924abfu);
        if (t39_call_status != BatchLiftStatus::returned) return t39_call_status;
    // 0x00924abf: 84c0 TEST
        t40a = state.regs[0] & 0x000000ffu;
        t40b = state.regs[0] & 0x000000ffu;
        t40r = (t40a & t40b) & 0x000000ffu;
        batch_set_logic_flags(state, t40r, 8u);
    // 0x00924ac1: 7444 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b07;
    // 0x00924ac3: 8b4c2410 MOV
        batch_guest_pc = 0x00924ac3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x00924ac7: 8b01 MOV
        batch_guest_pc = 0x00924ac7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x00924ac9: 8b5030 MOV
        batch_guest_pc = 0x00924ac9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t44)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t44;
    // 0x00924acc: ffd2 CALL
        t45_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924aceu);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
    // 0x00924ace: 85c0 TEST
        t46a = state.regs[0];
        t46b = state.regs[0];
        t46r = (t46a & t46b) & 0xffffffffu;
        batch_set_logic_flags(state, t46r, 32u);
    // 0x00924ad0: 743a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b0c;
    // 0x00924ad2: 8b10 MOV
        batch_guest_pc = 0x00924ad2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00924ad4: 8bc8 MOV
        t49 = state.regs[0];
        state.regs[1] = t49;
    // 0x00924ad6: 8b420c MOV
        batch_guest_pc = 0x00924ad6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t50)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t50;
    // 0x00924ad9: 68fe259e2e PUSH
        batch_guest_pc = 0x00924ad9u;
        t51a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t51a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ade: ffd0 CALL
        t52_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924ae0u);
        if (t52_call_status != BatchLiftStatus::returned) return t52_call_status;
    // 0x00924ae0: 8bc8 MOV
        t53 = state.regs[0];
        state.regs[1] = t53;
    // 0x00924ae2: 85c9 TEST
        t54a = state.regs[1];
        t54b = state.regs[1];
        t54r = (t54a & t54b) & 0xffffffffu;
        batch_set_logic_flags(state, t54r, 32u);
    // 0x00924ae4: 7426 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b0c;
    // 0x00924ae6: 8b442418 MOV
        batch_guest_pc = 0x00924ae6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t56)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t56;
    // 0x00924aea: 85c0 TEST
        t57a = state.regs[0];
        t57b = state.regs[0];
        t57r = (t57a & t57b) & 0xffffffffu;
        batch_set_logic_flags(state, t57r, 32u);
    // 0x00924aec: 750c JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924afa;
    // 0x00924aee: 8b542414 MOV
        batch_guest_pc = 0x00924aeeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t59)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t59;
    // 0x00924af2: 52 PUSH
        batch_guest_pc = 0x00924af2u;
        t60a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
    // 0x00924af3: e8c8f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924af8u)) return BatchLiftStatus::invalid_memory;
        t61_call_status = spore_lift_00923bc0(memory, state);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
        if (state.eip != 0x00924af8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924af8: eb12 JMP
        goto L_00924b0c;
    // 0x00924afa: 50 PUSH
    L_00924afa:
        batch_guest_pc = 0x00924afau;
        t63a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x00924afb: 8b442418 MOV
        batch_guest_pc = 0x00924afbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t64;
    // 0x00924aff: 50 PUSH
        batch_guest_pc = 0x00924affu;
        t65a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b00: e8fbfaffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924b05u)) return BatchLiftStatus::invalid_memory;
        t66_call_status = spore_lift_00924600(memory, state);
        if (t66_call_status != BatchLiftStatus::returned) return t66_call_status;
        if (state.eip != 0x00924b05u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b05: eb05 JMP
        goto L_00924b0c;
    // 0x00924b07: c644240700 MOV
    L_00924b07:
        batch_guest_pc = 0x00924b07u;
        t68 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00924b0c: 8b4c2410 MOV
    L_00924b0c:
        batch_guest_pc = 0x00924b0cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t69)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t69;
    // 0x00924b10: 85c9 TEST
        t70a = state.regs[1];
        t70b = state.regs[1];
        t70r = (t70a & t70b) & 0xffffffffu;
        batch_set_logic_flags(state, t70r, 32u);
    // 0x00924b12: 0f849a000000 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924bb2;
    // 0x00924b18: 8b11 MOV
        batch_guest_pc = 0x00924b18u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t72)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t72;
    // 0x00924b1a: 8b4204 MOV
        batch_guest_pc = 0x00924b1au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t73;
    // 0x00924b1d: ffd0 CALL
        t74_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b1fu);
        if (t74_call_status != BatchLiftStatus::returned) return t74_call_status;
    // 0x00924b1f: 8b4c2408 MOV
        batch_guest_pc = 0x00924b1fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t75)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t75;
    // 0x00924b23: e848d7ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924b28u)) return BatchLiftStatus::invalid_memory;
        t76_call_status = spore_lift_00922270(memory, state);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
        if (state.eip != 0x00924b28u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b28: 8a442407 MOV
        batch_guest_pc = 0x00924b28u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t77)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t77 << 0u) & 0x000000ffu);
    // 0x00924b2c: 5e POP
        batch_guest_pc = 0x00924b2cu;
        if (!memory.load32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t78a;
    // 0x00924b2d: 83c408 ADD
        t79a = state.regs[4];
        t79b = 0x00000008u;
        t79r = static_cast<std::uint32_t>(t79a + t79b) & 0xffffffffu;
        batch_set_add_flags(state, t79a, t79b, t79r, 32u);
        state.regs[4] = t79r;
    // 0x00924b30: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00924b33: 8b4e2c MOV
    L_00924b33:
        batch_guest_pc = 0x00924b33u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t81;
    // 0x00924b36: 53 PUSH
        batch_guest_pc = 0x00924b36u;
        t82a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b37: 8b5c2418 MOV
        batch_guest_pc = 0x00924b37u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t83)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t83;
    // 0x00924b3b: 55 PUSH
        batch_guest_pc = 0x00924b3bu;
        t84a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t84a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b3c: 8b6c2420 MOV
        batch_guest_pc = 0x00924b3cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t85)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t85;
    // 0x00924b40: 85c9 TEST
        t86a = state.regs[1];
        t86b = state.regs[1];
        t86r = (t86a & t86b) & 0xffffffffu;
        batch_set_logic_flags(state, t86r, 32u);
    // 0x00924b42: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b69;
    // 0x00924b44: 8b11 MOV
        batch_guest_pc = 0x00924b44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t88)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t88;
    // 0x00924b46: 8b420c MOV
        batch_guest_pc = 0x00924b46u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t89)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t89;
    // 0x00924b49: 68fe259e2e PUSH
        batch_guest_pc = 0x00924b49u;
        t90a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t90a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b4e: ffd0 CALL
        t91_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b50u);
        if (t91_call_status != BatchLiftStatus::returned) return t91_call_status;
    // 0x00924b50: 8bc8 MOV
        t92 = state.regs[0];
        state.regs[1] = t92;
    // 0x00924b52: 85c9 TEST
        t93a = state.regs[1];
        t93b = state.regs[1];
        t93r = (t93a & t93b) & 0xffffffffu;
        batch_set_logic_flags(state, t93r, 32u);
    // 0x00924b54: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924b69;
    // 0x00924b56: 85ed TEST
        t95a = state.regs[5];
        t95b = state.regs[5];
        t95r = (t95a & t95b) & 0xffffffffu;
        batch_set_logic_flags(state, t95r, 32u);
    // 0x00924b58: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924b62;
    // 0x00924b5a: 53 PUSH
        batch_guest_pc = 0x00924b5au;
        t97a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t97a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b5b: e860f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924b60u)) return BatchLiftStatus::invalid_memory;
        t98_call_status = spore_lift_00923bc0(memory, state);
        if (t98_call_status != BatchLiftStatus::returned) return t98_call_status;
        if (state.eip != 0x00924b60u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b60: eb07 JMP
        goto L_00924b69;
    // 0x00924b62: 55 PUSH
    L_00924b62:
        batch_guest_pc = 0x00924b62u;
        t100a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t100a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b63: 53 PUSH
        batch_guest_pc = 0x00924b63u;
        t101a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t101a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b64: e897faffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924b69u)) return BatchLiftStatus::invalid_memory;
        t102_call_status = spore_lift_00924600(memory, state);
        if (t102_call_status != BatchLiftStatus::returned) return t102_call_status;
        if (state.eip != 0x00924b69u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b69: 57 PUSH
    L_00924b69:
        batch_guest_pc = 0x00924b69u;
        t103a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t103a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b6a: 8b7e18 MOV
        batch_guest_pc = 0x00924b6au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t104)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t104;
    // 0x00924b6d: 8b761c MOV
        batch_guest_pc = 0x00924b6du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t105)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t105;
    // 0x00924b70: 3bfe CMP
        t106a = state.regs[7];
        t106b = state.regs[6];
        t106r = static_cast<std::uint32_t>(t106a - t106b) & 0xffffffffu;
        batch_set_sub_flags(state, t106a, t106b, t106r, 32u);
    // 0x00924b72: 743b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924baf;
    // 0x00924b74: 8b0f MOV
    L_00924b74:
        batch_guest_pc = 0x00924b74u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t108)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t108;
    // 0x00924b76: 8b11 MOV
        batch_guest_pc = 0x00924b76u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t109)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t109;
    // 0x00924b78: 8b4230 MOV
        batch_guest_pc = 0x00924b78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000030u), t110)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t110;
    // 0x00924b7b: ffd0 CALL
        t111_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b7du);
        if (t111_call_status != BatchLiftStatus::returned) return t111_call_status;
    // 0x00924b7d: 85c0 TEST
        t112a = state.regs[0];
        t112b = state.regs[0];
        t112r = (t112a & t112b) & 0xffffffffu;
        batch_set_logic_flags(state, t112r, 32u);
    // 0x00924b7f: 7427 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924ba8;
    // 0x00924b81: 8b10 MOV
        batch_guest_pc = 0x00924b81u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t114)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t114;
    // 0x00924b83: 8bc8 MOV
        t115 = state.regs[0];
        state.regs[1] = t115;
    // 0x00924b85: 8b420c MOV
        batch_guest_pc = 0x00924b85u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t116)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t116;
    // 0x00924b88: 68fe259e2e PUSH
        batch_guest_pc = 0x00924b88u;
        t117a = 0x2e9e25feu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t117a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b8d: ffd0 CALL
        t118_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924b8fu);
        if (t118_call_status != BatchLiftStatus::returned) return t118_call_status;
    // 0x00924b8f: 8bc8 MOV
        t119 = state.regs[0];
        state.regs[1] = t119;
    // 0x00924b91: 85c9 TEST
        t120a = state.regs[1];
        t120b = state.regs[1];
        t120r = (t120a & t120b) & 0xffffffffu;
        batch_set_logic_flags(state, t120r, 32u);
    // 0x00924b93: 7413 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924ba8;
    // 0x00924b95: 85ed TEST
        t122a = state.regs[5];
        t122b = state.regs[5];
        t122r = (t122a & t122b) & 0xffffffffu;
        batch_set_logic_flags(state, t122r, 32u);
    // 0x00924b97: 7508 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924ba1;
    // 0x00924b99: 53 PUSH
        batch_guest_pc = 0x00924b99u;
        t124a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t124a)) return BatchLiftStatus::invalid_memory;
    // 0x00924b9a: e821f0ffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00924b9fu)) return BatchLiftStatus::invalid_memory;
        t125_call_status = spore_lift_00923bc0(memory, state);
        if (t125_call_status != BatchLiftStatus::returned) return t125_call_status;
        if (state.eip != 0x00924b9fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924b9f: eb07 JMP
        goto L_00924ba8;
    // 0x00924ba1: 55 PUSH
    L_00924ba1:
        batch_guest_pc = 0x00924ba1u;
        t127a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t127a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ba2: 53 PUSH
        batch_guest_pc = 0x00924ba2u;
        t128a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t128a)) return BatchLiftStatus::invalid_memory;
    // 0x00924ba3: e858faffff CALL
        if (!batch_guest_call32(memory, state, 0x00924600u, 0x00924ba8u)) return BatchLiftStatus::invalid_memory;
        t129_call_status = spore_lift_00924600(memory, state);
        if (t129_call_status != BatchLiftStatus::returned) return t129_call_status;
        if (state.eip != 0x00924ba8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924ba8: 83c704 ADD
    L_00924ba8:
        t130a = state.regs[7];
        t130b = 0x00000004u;
        t130r = static_cast<std::uint32_t>(t130a + t130b) & 0xffffffffu;
        batch_set_add_flags(state, t130a, t130b, t130r, 32u);
        state.regs[7] = t130r;
    // 0x00924bab: 3bfe CMP
        t131a = state.regs[7];
        t131b = state.regs[6];
        t131r = static_cast<std::uint32_t>(t131a - t131b) & 0xffffffffu;
        batch_set_sub_flags(state, t131a, t131b, t131r, 32u);
    // 0x00924bad: 75c5 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924b74;
    // 0x00924baf: 5f POP
    L_00924baf:
        batch_guest_pc = 0x00924bafu;
        if (!memory.load32(state.regs[4], t133a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t133a;
    // 0x00924bb0: 5d POP
        batch_guest_pc = 0x00924bb0u;
        if (!memory.load32(state.regs[4], t134a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t134a;
    // 0x00924bb1: 5b POP
        batch_guest_pc = 0x00924bb1u;
        if (!memory.load32(state.regs[4], t135a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t135a;
    // 0x00924bb2: 8b4c2408 MOV
    L_00924bb2:
        batch_guest_pc = 0x00924bb2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t136)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t136;
    // 0x00924bb6: e8b5d6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924bbbu)) return BatchLiftStatus::invalid_memory;
        t137_call_status = spore_lift_00922270(memory, state);
        if (t137_call_status != BatchLiftStatus::returned) return t137_call_status;
        if (state.eip != 0x00924bbbu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924bbb: 8a442407 MOV
        batch_guest_pc = 0x00924bbbu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000007u), t138)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t138 << 0u) & 0x000000ffu);
    // 0x00924bbf: 5e POP
        batch_guest_pc = 0x00924bbfu;
        if (!memory.load32(state.regs[4], t139a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t139a;
    // 0x00924bc0: 83c408 ADD
        t140a = state.regs[4];
        t140b = 0x00000008u;
        t140r = static_cast<std::uint32_t>(t140a + t140b) & 0xffffffffu;
        batch_set_add_flags(state, t140a, t140b, t140r, 32u);
        state.regs[4] = t140r;
    // 0x00924bc3: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
