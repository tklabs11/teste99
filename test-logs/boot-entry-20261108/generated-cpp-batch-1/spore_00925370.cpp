#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925300(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009253ad(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925370(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925370u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t39a = 0, t39r = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t45a = 0, t45b = 0, t45r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t61a = 0;
    BatchLiftStatus t62_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t64a = 0;
    std::uint32_t t65 = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68a = 0;
    std::uint32_t t69a = 0;

    // 0x00925370: 53 PUSH
        batch_guest_pc = 0x00925370u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925371: 55 PUSH
        batch_guest_pc = 0x00925371u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925372: 8b6c240c MOV
        batch_guest_pc = 0x00925372u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t2;
    // 0x00925376: 56 PUSH
        batch_guest_pc = 0x00925376u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925377: 57 PUSH
        batch_guest_pc = 0x00925377u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925378: 55 PUSH
        batch_guest_pc = 0x00925378u;
        t5a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925379: 8bf1 MOV
        t6 = state.regs[1];
        state.regs[6] = t6;
    // 0x0092537b: e880ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00925300u, 0x00925380u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00925300(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00925380u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925380: 33ff XOR
        t8a = state.regs[7];
        t8b = state.regs[7];
        t8r = (t8a ^ t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
        state.regs[7] = t8r;
    // 0x00925382: 8bd8 MOV
        t9 = state.regs[0];
        state.regs[3] = t9;
    // 0x00925384: 397e08 CMP
        batch_guest_pc = 0x00925384u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = state.regs[7];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00925387: 7652 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_009253db;
    // 0x00925389: 8da42400000000 LEA
        t12 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t12;
    // 0x00925390: 8b4604 MOV
    L_00925390:
        batch_guest_pc = 0x00925390u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00925393: 8b0cb8 MOV
        batch_guest_pc = 0x00925393u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00925396: 85c9 TEST
        t15a = state.regs[1];
        t15b = state.regs[1];
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
    // 0x00925398: 743b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009253d5;
    // 0x0092539a: 8d9b00000000 LEA
        t17 = static_cast<std::uint32_t>(state.regs[3] + 0x00000000u);
        state.regs[3] = t17;
    // 0x009253a0: 8b4104 MOV
    L_009253a0:
        batch_guest_pc = 0x009253a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x009253a3: 85c0 TEST
        t19a = state.regs[0];
        t19b = state.regs[0];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x009253a5: 7404 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009253ab;
    // 0x009253a7: 8b10 MOV
        batch_guest_pc = 0x009253a7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x009253a9: eb02 JMP
        goto L_009253ad;
    // 0x009253ab: 33d2 XOR
    L_009253ab:
        t23a = state.regs[2];
        t23b = state.regs[2];
        t23r = (t23a ^ t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
        state.regs[2] = t23r;
    // 0x009253ad: 8b01 MOV
    L_009253ad:
        batch_guest_pc = 0x009253adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t24;
    // 0x009253af: 03c2 ADD
        t25a = state.regs[0];
        t25b = state.regs[2];
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x009253b1: 33d2 XOR
        t26a = state.regs[2];
        t26b = state.regs[2];
        t26r = (t26a ^ t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
        state.regs[2] = t26r;
    // 0x009253b3: f7f5 DIV
        t27a = state.regs[5];
        if (t27a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t27a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t27a);
        }
    // 0x009253b5: 8b6908 MOV
        batch_guest_pc = 0x009253b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t28;
    // 0x009253b8: 8b4604 MOV
        batch_guest_pc = 0x009253b8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x009253bb: 892cb8 MOV
        batch_guest_pc = 0x009253bbu;
        t30 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x009253be: 8b6c2414 MOV
        batch_guest_pc = 0x009253beu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t31;
    // 0x009253c2: 8b0493 MOV
        batch_guest_pc = 0x009253c2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + state.regs[2] * 4u + 0x00000000u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t32;
    // 0x009253c5: 894108 MOV
        batch_guest_pc = 0x009253c5u;
        t33 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t33)) return BatchLiftStatus::invalid_memory;
    // 0x009253c8: 890c93 MOV
        batch_guest_pc = 0x009253c8u;
        t34 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[3] + state.regs[2] * 4u + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x009253cb: 8b4e04 MOV
        batch_guest_pc = 0x009253cbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t35;
    // 0x009253ce: 8b0cb9 MOV
        batch_guest_pc = 0x009253ceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + state.regs[7] * 4u + 0x00000000u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t36;
    // 0x009253d1: 85c9 TEST
        t37a = state.regs[1];
        t37b = state.regs[1];
        t37r = (t37a & t37b) & 0xffffffffu;
        batch_set_logic_flags(state, t37r, 32u);
    // 0x009253d3: 75cb JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009253a0;
    // 0x009253d5: 47 INC
    L_009253d5:
        t39a = state.regs[7];
        t39r = static_cast<std::uint32_t>(t39a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t39a, t39r, 32u);
        state.regs[7] = t39r;
    // 0x009253d6: 3b7e08 CMP
        batch_guest_pc = 0x009253d6u;
        t40a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t40b)) return BatchLiftStatus::invalid_memory;
        t40r = static_cast<std::uint32_t>(t40a - t40b) & 0xffffffffu;
        batch_set_sub_flags(state, t40a, t40b, t40r, 32u);
    // 0x009253d9: 72b5 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925390;
    // 0x009253db: 837e0801 CMP
    L_009253db:
        batch_guest_pc = 0x009253dbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t42a)) return BatchLiftStatus::invalid_memory;
        t42b = 0x00000001u;
        t42r = static_cast<std::uint32_t>(t42a - t42b) & 0xffffffffu;
        batch_set_sub_flags(state, t42a, t42b, t42r, 32u);
    // 0x009253df: 8b4604 MOV
        batch_guest_pc = 0x009253dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t43)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t43;
    // 0x009253e2: 762d JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925411;
    // 0x009253e4: 3b4630 CMP
        batch_guest_pc = 0x009253e4u;
        t45a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t45b)) return BatchLiftStatus::invalid_memory;
        t45r = static_cast<std::uint32_t>(t45a - t45b) & 0xffffffffu;
        batch_set_sub_flags(state, t45a, t45b, t45r, 32u);
    // 0x009253e7: 7428 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925411;
    // 0x009253e9: 3b4624 CMP
        batch_guest_pc = 0x009253e9u;
        t47a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000024u), t47b)) return BatchLiftStatus::invalid_memory;
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
    // 0x009253ec: 721a JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925408;
    // 0x009253ee: 3b4628 CMP
        batch_guest_pc = 0x009253eeu;
        t49a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t49b)) return BatchLiftStatus::invalid_memory;
        t49r = static_cast<std::uint32_t>(t49a - t49b) & 0xffffffffu;
        batch_set_sub_flags(state, t49a, t49b, t49r, 32u);
    // 0x009253f1: 7315 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00925408;
    // 0x009253f3: 8b561c MOV
        batch_guest_pc = 0x009253f3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t51;
    // 0x009253f6: 8910 MOV
        batch_guest_pc = 0x009253f6u;
        t52 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x009253f8: 89461c MOV
        batch_guest_pc = 0x009253f8u;
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t53)) return BatchLiftStatus::invalid_memory;
    // 0x009253fb: 5f POP
        batch_guest_pc = 0x009253fbu;
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t54a;
    // 0x009253fc: 895e04 MOV
        batch_guest_pc = 0x009253fcu;
        t55 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x009253ff: 896e08 MOV
        batch_guest_pc = 0x009253ffu;
        t56 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t56)) return BatchLiftStatus::invalid_memory;
    // 0x00925402: 5e POP
        batch_guest_pc = 0x00925402u;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t57a;
    // 0x00925403: 5d POP
        batch_guest_pc = 0x00925403u;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t58a;
    // 0x00925404: 5b POP
        batch_guest_pc = 0x00925404u;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t59a;
    // 0x00925405: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925408: 50 PUSH
    L_00925408:
        batch_guest_pc = 0x00925408u;
        t61a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00925409: e8721f6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x0092540eu)) return BatchLiftStatus::invalid_memory;
        t62_call_status = spore_lift_00f47380(memory, state);
        if (t62_call_status != BatchLiftStatus::returned) return t62_call_status;
        if (state.eip != 0x0092540eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092540e: 83c404 ADD
        t63a = state.regs[4];
        t63b = 0x00000004u;
        t63r = static_cast<std::uint32_t>(t63a + t63b) & 0xffffffffu;
        batch_set_add_flags(state, t63a, t63b, t63r, 32u);
        state.regs[4] = t63r;
    // 0x00925411: 5f POP
    L_00925411:
        batch_guest_pc = 0x00925411u;
        if (!memory.load32(state.regs[4], t64a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t64a;
    // 0x00925412: 895e04 MOV
        batch_guest_pc = 0x00925412u;
        t65 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t65)) return BatchLiftStatus::invalid_memory;
    // 0x00925415: 896e08 MOV
        batch_guest_pc = 0x00925415u;
        t66 = state.regs[5];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x00925418: 5e POP
        batch_guest_pc = 0x00925418u;
        if (!memory.load32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t67a;
    // 0x00925419: 5d POP
        batch_guest_pc = 0x00925419u;
        if (!memory.load32(state.regs[4], t68a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t68a;
    // 0x0092541a: 5b POP
        batch_guest_pc = 0x0092541au;
        if (!memory.load32(state.regs[4], t69a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t69a;
    // 0x0092541b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
