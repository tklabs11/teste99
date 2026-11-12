#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00886560(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00886780(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00919a80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00887090(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00887090u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33b = 0, t33r = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40a = 0;
    BatchLiftStatus t41_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43 = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48a = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50a = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t57a = 0;
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0;
    std::uint32_t t60 = 0;
    BatchLiftStatus t61_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t62 = 0;
    std::uint32_t t63a = 0;
    std::uint32_t t64 = 0;
    BatchLiftStatus t65_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t66 = 0;
    std::uint32_t t67 = 0;
    std::uint32_t t68a = 0, t68b = 0, t68r = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t71a = 0, t71b = 0, t71r = 0;
    std::uint32_t t73a = 0, t73b = 0, t73r = 0;
    std::uint32_t t75a = 0;
    BatchLiftStatus t76_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t77a = 0, t77b = 0, t77r = 0;
    std::uint32_t t78a = 0;
    std::uint32_t t79a = 0;
    std::uint32_t t80a = 0, t80b = 0, t80r = 0;

    // 0x00887090: 83ec14 SUB
        t0a = state.regs[4];
        t0b = 0x00000014u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00887093: 55 PUSH
        batch_guest_pc = 0x00887093u;
        t1a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00887094: 8b6c241c MOV
        batch_guest_pc = 0x00887094u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t2;
    // 0x00887098: 56 PUSH
        batch_guest_pc = 0x00887098u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00887099: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x0088709b: 83fdff CMP
        t5a = state.regs[5];
        t5b = 0xffffffffu;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0088709e: 746f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0088710f;
    // 0x008870a0: 8b4604 MOV
        batch_guest_pc = 0x008870a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x008870a3: 2b06 SUB
        batch_guest_pc = 0x008870a3u;
        t8a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8b)) return BatchLiftStatus::invalid_memory;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x008870a5: 3be8 CMP
        t9a = state.regs[5];
        t9b = state.regs[0];
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x008870a7: 7666 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0088710f;
    // 0x008870a9: 53 PUSH
        batch_guest_pc = 0x008870a9u;
        t11a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x008870aa: 57 PUSH
        batch_guest_pc = 0x008870aau;
        t12a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x008870ab: 68d1000000 PUSH
        batch_guest_pc = 0x008870abu;
        t13a = 0x000000d1u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x008870b0: 6838bb3e01 PUSH
        batch_guest_pc = 0x008870b0u;
        t14a = 0x013ebb38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x008870b5: 6a00 PUSH
        batch_guest_pc = 0x008870b5u;
        t15a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x008870b7: 6a00 PUSH
        batch_guest_pc = 0x008870b7u;
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x008870b9: 6850213f01 PUSH
        batch_guest_pc = 0x008870b9u;
        t17a = 0x013f2150u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x008870be: 55 PUSH
        batch_guest_pc = 0x008870beu;
        t18a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x008870bf: e8dc026c00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x008870c4u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_00f473a0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x008870c4u) return BatchLiftStatus::invalid_control_flow;
    // 0x008870c4: 8b7e04 MOV
        batch_guest_pc = 0x008870c4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t20;
    // 0x008870c7: 8bd8 MOV
        t21 = state.regs[0];
        state.regs[3] = t21;
    // 0x008870c9: 8b06 MOV
        batch_guest_pc = 0x008870c9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x008870cb: 2bf8 SUB
        t23a = state.regs[7];
        t23b = state.regs[0];
        t23r = static_cast<std::uint32_t>(t23a - t23b) & 0xffffffffu;
        batch_set_sub_flags(state, t23a, t23b, t23r, 32u);
        state.regs[7] = t23r;
    // 0x008870cd: 57 PUSH
        batch_guest_pc = 0x008870cdu;
        t24a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x008870ce: 50 PUSH
        batch_guest_pc = 0x008870ceu;
        t25a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x008870cf: 53 PUSH
        batch_guest_pc = 0x008870cfu;
        t26a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x008870d0: e86f969500 CALL
        t27_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x008870d5u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x008870d5u) return BatchLiftStatus::invalid_control_flow;
    // 0x008870d5: 03fb ADD
        t28a = state.regs[7];
        t28b = state.regs[3];
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[7] = t28r;
    // 0x008870d7: c60700 MOV
        batch_guest_pc = 0x008870d7u;
        t29 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x008870da: 8b06 MOV
        batch_guest_pc = 0x008870dau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x008870dc: 8b4e08 MOV
        batch_guest_pc = 0x008870dcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x008870df: 2bc8 SUB
        t32a = state.regs[1];
        t32b = state.regs[0];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
        state.regs[1] = t32r;
    // 0x008870e1: 83c424 ADD
        t33a = state.regs[4];
        t33b = 0x00000024u;
        t33r = static_cast<std::uint32_t>(t33a + t33b) & 0xffffffffu;
        batch_set_add_flags(state, t33a, t33b, t33r, 32u);
        state.regs[4] = t33r;
    // 0x008870e4: 83f901 CMP
        t34a = state.regs[1];
        t34b = 0x00000001u;
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x008870e7: 7e12 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_008870fb;
    // 0x008870e9: 85c0 TEST
        t36a = state.regs[0];
        t36b = state.regs[0];
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
    // 0x008870eb: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_008870fb;
    // 0x008870ed: 3b4610 CMP
        batch_guest_pc = 0x008870edu;
        t38a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t38b)) return BatchLiftStatus::invalid_memory;
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x008870f0: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_008870fb;
    // 0x008870f2: 50 PUSH
        batch_guest_pc = 0x008870f2u;
        t40a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x008870f3: e888026c00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x008870f8u)) return BatchLiftStatus::invalid_memory;
        t41_call_status = spore_lift_00f47380(memory, state);
        if (t41_call_status != BatchLiftStatus::returned) return t41_call_status;
        if (state.eip != 0x008870f8u) return BatchLiftStatus::invalid_control_flow;
    // 0x008870f8: 83c404 ADD
        t42a = state.regs[4];
        t42b = 0x00000004u;
        t42r = static_cast<std::uint32_t>(t42a + t42b) & 0xffffffffu;
        batch_set_add_flags(state, t42a, t42b, t42r, 32u);
        state.regs[4] = t42r;
    // 0x008870fb: 891e MOV
    L_008870fb:
        batch_guest_pc = 0x008870fbu;
        t43 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t43)) return BatchLiftStatus::invalid_memory;
    // 0x008870fd: 03dd ADD
        t44a = state.regs[3];
        t44b = state.regs[5];
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[3] = t44r;
    // 0x008870ff: 897e04 MOV
        batch_guest_pc = 0x008870ffu;
        t45 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00887102: 5f POP
        batch_guest_pc = 0x00887102u;
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t46a;
    // 0x00887103: 895e08 MOV
        batch_guest_pc = 0x00887103u;
        t47 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00887106: 5b POP
        batch_guest_pc = 0x00887106u;
        if (!memory.load32(state.regs[4], t48a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t48a;
    // 0x00887107: 5e POP
        batch_guest_pc = 0x00887107u;
        if (!memory.load32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t49a;
    // 0x00887108: 5d POP
        batch_guest_pc = 0x00887108u;
        if (!memory.load32(state.regs[4], t50a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t50a;
    // 0x00887109: 83c414 ADD
        t51a = state.regs[4];
        t51b = 0x00000014u;
        t51r = static_cast<std::uint32_t>(t51a + t51b) & 0xffffffffu;
        batch_set_add_flags(state, t51a, t51b, t51r, 32u);
        state.regs[4] = t51r;
    // 0x0088710c: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0088710f: 8b5604 MOV
    L_0088710f:
        batch_guest_pc = 0x0088710fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t53)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t53;
    // 0x00887112: 2b16 SUB
        batch_guest_pc = 0x00887112u;
        t54a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t54b)) return BatchLiftStatus::invalid_memory;
        t54r = static_cast<std::uint32_t>(t54a - t54b) & 0xffffffffu;
        batch_set_sub_flags(state, t54a, t54b, t54r, 32u);
        state.regs[2] = t54r;
    // 0x00887114: 3bea CMP
        t55a = state.regs[5];
        t55b = state.regs[2];
        t55r = static_cast<std::uint32_t>(t55a - t55b) & 0xffffffffu;
        batch_set_sub_flags(state, t55a, t55b, t55r, 32u);
    // 0x00887116: 7306 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0088711e;
    // 0x00887118: 55 PUSH
        batch_guest_pc = 0x00887118u;
        t57a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
    // 0x00887119: e842f4ffff CALL
        if (!batch_guest_call32(memory, state, 0x00886560u, 0x0088711eu)) return BatchLiftStatus::invalid_memory;
        t58_call_status = spore_lift_00886560(memory, state);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x0088711eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0088711e: 56 PUSH
    L_0088711e:
        batch_guest_pc = 0x0088711eu;
        t59a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
    // 0x0088711f: 8d4c240c LEA
        t60 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t60;
    // 0x00887123: e858f6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00886780u, 0x00887128u)) return BatchLiftStatus::invalid_memory;
        t61_call_status = spore_lift_00886780(memory, state);
        if (t61_call_status != BatchLiftStatus::returned) return t61_call_status;
        if (state.eip != 0x00887128u) return BatchLiftStatus::invalid_control_flow;
    // 0x00887128: 8d442408 LEA
        t62 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[0] = t62;
    // 0x0088712c: 50 PUSH
        batch_guest_pc = 0x0088712cu;
        t63a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t63a)) return BatchLiftStatus::invalid_memory;
    // 0x0088712d: 8bce MOV
        t64 = state.regs[6];
        state.regs[1] = t64;
    // 0x0088712f: e84c290900 CALL
        if (!batch_guest_call32(memory, state, 0x00919a80u, 0x00887134u)) return BatchLiftStatus::invalid_memory;
        t65_call_status = spore_lift_00919a80(memory, state);
        if (t65_call_status != BatchLiftStatus::returned) return t65_call_status;
        if (state.eip != 0x00887134u) return BatchLiftStatus::invalid_control_flow;
    // 0x00887134: 8b4c2410 MOV
        batch_guest_pc = 0x00887134u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t66)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t66;
    // 0x00887138: 8b442408 MOV
        batch_guest_pc = 0x00887138u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t67)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t67;
    // 0x0088713c: 2bc8 SUB
        t68a = state.regs[1];
        t68b = state.regs[0];
        t68r = static_cast<std::uint32_t>(t68a - t68b) & 0xffffffffu;
        batch_set_sub_flags(state, t68a, t68b, t68r, 32u);
        state.regs[1] = t68r;
    // 0x0088713e: 83f901 CMP
        t69a = state.regs[1];
        t69b = 0x00000001u;
        t69r = static_cast<std::uint32_t>(t69a - t69b) & 0xffffffffu;
        batch_set_sub_flags(state, t69a, t69b, t69r, 32u);
    // 0x00887141: 7e13 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00887156;
    // 0x00887143: 85c0 TEST
        t71a = state.regs[0];
        t71b = state.regs[0];
        t71r = (t71a & t71b) & 0xffffffffu;
        batch_set_logic_flags(state, t71r, 32u);
    // 0x00887145: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00887156;
    // 0x00887147: 3b442418 CMP
        batch_guest_pc = 0x00887147u;
        t73a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t73b)) return BatchLiftStatus::invalid_memory;
        t73r = static_cast<std::uint32_t>(t73a - t73b) & 0xffffffffu;
        batch_set_sub_flags(state, t73a, t73b, t73r, 32u);
    // 0x0088714b: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00887156;
    // 0x0088714d: 50 PUSH
        batch_guest_pc = 0x0088714du;
        t75a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t75a)) return BatchLiftStatus::invalid_memory;
    // 0x0088714e: e82d026c00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00887153u)) return BatchLiftStatus::invalid_memory;
        t76_call_status = spore_lift_00f47380(memory, state);
        if (t76_call_status != BatchLiftStatus::returned) return t76_call_status;
        if (state.eip != 0x00887153u) return BatchLiftStatus::invalid_control_flow;
    // 0x00887153: 83c404 ADD
        t77a = state.regs[4];
        t77b = 0x00000004u;
        t77r = static_cast<std::uint32_t>(t77a + t77b) & 0xffffffffu;
        batch_set_add_flags(state, t77a, t77b, t77r, 32u);
        state.regs[4] = t77r;
    // 0x00887156: 5e POP
    L_00887156:
        batch_guest_pc = 0x00887156u;
        if (!memory.load32(state.regs[4], t78a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t78a;
    // 0x00887157: 5d POP
        batch_guest_pc = 0x00887157u;
        if (!memory.load32(state.regs[4], t79a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t79a;
    // 0x00887158: 83c414 ADD
        t80a = state.regs[4];
        t80b = 0x00000014u;
        t80r = static_cast<std::uint32_t>(t80a + t80b) & 0xffffffffu;
        batch_set_add_flags(state, t80a, t80b, t80r, 32u);
        state.regs[4] = t80r;
    // 0x0088715b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
