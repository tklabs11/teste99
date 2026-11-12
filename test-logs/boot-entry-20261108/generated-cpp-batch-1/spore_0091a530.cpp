#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00886560(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0091a568(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0091a5a9(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00938400(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0091a530(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0091a530u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    BatchLiftStatus t37_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0, t43r = 0;
    std::uint32_t t44a = 0, t44b = 0, t44r = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    BatchLiftStatus t47_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t48a = 0, t48b = 0, t48r = 0;
    std::uint32_t t49 = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53a = 0, t53b = 0, t53r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t55 = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t58a = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0;
    std::uint32_t t61a = 0, t61b = 0, t61r = 0;
    std::uint32_t t63a = 0, t63b = 0, t63r = 0;
    std::uint32_t t65a = 0, t65b = 0, t65r = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0, t67b = 0, t67r = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;
    std::uint32_t t70 = 0;
    std::uint32_t t72 = 0;
    std::uint32_t t73 = 0;
    std::uint32_t t74a = 0, t74b = 0, t74r = 0;
    std::uint32_t t76a = 0;
    std::uint32_t t77 = 0;
    BatchLiftStatus t78_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t79 = 0;
    std::uint32_t t80 = 0;
    std::uint32_t t81 = 0;
    std::uint32_t t82a = 0;
    std::uint32_t t83 = 0;
    std::uint32_t t84a = 0, t84b = 0, t84r = 0;
    std::uint32_t t85a = 0;
    std::uint32_t t86a = 0, t86r = 0;
    std::uint32_t t87a = 0, t87b = 0, t87r = 0;
    std::uint32_t t88a = 0;
    std::uint32_t t89a = 0;
    BatchLiftStatus t90_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t91 = 0;
    std::uint32_t t92a = 0, t92b = 0, t92r = 0;
    std::uint32_t t93a = 0, t93b = 0, t93r = 0;
    std::uint32_t t94a = 0, t94b = 0, t94r = 0;

    // 0x0091a530: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x0091a533: 53 PUSH
        batch_guest_pc = 0x0091a533u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a534: 55 PUSH
        batch_guest_pc = 0x0091a534u;
        t2a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a535: 56 PUSH
        batch_guest_pc = 0x0091a535u;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a536: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x0091a538: 8b4604 MOV
        batch_guest_pc = 0x0091a538u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x0091a53b: 8b0e MOV
        batch_guest_pc = 0x0091a53bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x0091a53d: 8be8 MOV
        t7 = state.regs[0];
        state.regs[5] = t7;
    // 0x0091a53f: 2be9 SUB
        t8a = state.regs[5];
        t8b = state.regs[1];
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[5] = t8r;
    // 0x0091a541: 57 PUSH
        batch_guest_pc = 0x0091a541u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a542: 81f9ac7b6601 CMP
        t10a = state.regs[1];
        t10b = 0x01667bacu;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x0091a548: 750e JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0091a558;
    // 0x0091a54a: 8b4c2420 MOV
        batch_guest_pc = 0x0091a54au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x0091a54e: 8b54241c MOV
        batch_guest_pc = 0x0091a54eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x0091a552: 51 PUSH
        batch_guest_pc = 0x0091a552u;
        t14a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a553: 52 PUSH
        batch_guest_pc = 0x0091a553u;
        t15a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a554: 6a00 PUSH
        batch_guest_pc = 0x0091a554u;
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a556: eb10 JMP
        goto L_0091a568;
    // 0x0091a558: 8b542420 MOV
    L_0091a558:
        batch_guest_pc = 0x0091a558u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0091a55c: 8b4e08 MOV
        batch_guest_pc = 0x0091a55cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t19;
    // 0x0091a55f: 52 PUSH
        batch_guest_pc = 0x0091a55fu;
        t20a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a560: 8b542420 MOV
        batch_guest_pc = 0x0091a560u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t21;
    // 0x0091a564: 2bc8 SUB
        t22a = state.regs[1];
        t22b = state.regs[0];
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
        state.regs[1] = t22r;
    // 0x0091a566: 52 PUSH
        batch_guest_pc = 0x0091a566u;
        t23a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a567: 51 PUSH
        batch_guest_pc = 0x0091a567u;
        t24a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a568: 50 PUSH
    L_0091a568:
        batch_guest_pc = 0x0091a568u;
        t25a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a569: e892de0100 CALL
        if (!batch_guest_call32(memory, state, 0x00938400u, 0x0091a56eu)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00938400(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x0091a56eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0091a56e: 8b4e08 MOV
        batch_guest_pc = 0x0091a56eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t27;
    // 0x0091a571: 8bd8 MOV
        t28 = state.regs[0];
        state.regs[3] = t28;
    // 0x0091a573: 8b4604 MOV
        batch_guest_pc = 0x0091a573u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t29;
    // 0x0091a576: 2bc8 SUB
        t30a = state.regs[1];
        t30b = state.regs[0];
        t30r = static_cast<std::uint32_t>(t30a - t30b) & 0xffffffffu;
        batch_set_sub_flags(state, t30a, t30b, t30r, 32u);
        state.regs[1] = t30r;
    // 0x0091a578: 83c410 ADD
        t31a = state.regs[4];
        t31b = 0x00000010u;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[4] = t31r;
    // 0x0091a57b: 3bd9 CMP
        t32a = state.regs[3];
        t32b = state.regs[1];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
    // 0x0091a57d: 7c3f JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_0091a5be;
    // 0x0091a57f: 8d142b LEA
        t34 = static_cast<std::uint32_t>(state.regs[3] + state.regs[5] * 1u + 0x00000000u);
        state.regs[2] = t34;
    // 0x0091a582: 52 PUSH
        batch_guest_pc = 0x0091a582u;
        t35a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a583: 8bce MOV
        t36 = state.regs[6];
        state.regs[1] = t36;
    // 0x0091a585: e8d6bff6ff CALL
        if (!batch_guest_call32(memory, state, 0x00886560u, 0x0091a58au)) return BatchLiftStatus::invalid_memory;
        t37_call_status = spore_lift_00886560(memory, state);
        if (t37_call_status != BatchLiftStatus::returned) return t37_call_status;
        if (state.eip != 0x0091a58au) return BatchLiftStatus::invalid_control_flow;
    // 0x0091a58a: 8b4c2420 MOV
        batch_guest_pc = 0x0091a58au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t38;
    // 0x0091a58e: 8b54241c MOV
        batch_guest_pc = 0x0091a58eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t39;
    // 0x0091a592: 8b06 MOV
        batch_guest_pc = 0x0091a592u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x0091a594: 51 PUSH
        batch_guest_pc = 0x0091a594u;
        t41a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a595: 52 PUSH
        batch_guest_pc = 0x0091a595u;
        t42a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a596: 43 INC
        t43a = state.regs[3];
        t43r = static_cast<std::uint32_t>(t43a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t43a, t43r, 32u);
        state.regs[3] = t43r;
    // 0x0091a597: 03c5 ADD
        t44a = state.regs[0];
        t44b = state.regs[5];
        t44r = static_cast<std::uint32_t>(t44a + t44b) & 0xffffffffu;
        batch_set_add_flags(state, t44a, t44b, t44r, 32u);
        state.regs[0] = t44r;
    // 0x0091a599: 53 PUSH
        batch_guest_pc = 0x0091a599u;
        t45a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a59a: 50 PUSH
        batch_guest_pc = 0x0091a59au;
        t46a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a59b: e860de0100 CALL
        if (!batch_guest_call32(memory, state, 0x00938400u, 0x0091a5a0u)) return BatchLiftStatus::invalid_memory;
        t47_call_status = spore_lift_00938400(memory, state);
        if (t47_call_status != BatchLiftStatus::returned) return t47_call_status;
        if (state.eip != 0x0091a5a0u) return BatchLiftStatus::invalid_control_flow;
    // 0x0091a5a0: 83c410 ADD
        t48a = state.regs[4];
        t48b = 0x00000010u;
        t48r = static_cast<std::uint32_t>(t48a + t48b) & 0xffffffffu;
        batch_set_add_flags(state, t48a, t48b, t48r, 32u);
        state.regs[4] = t48r;
    // 0x0091a5a3: 8bd8 MOV
        t49 = state.regs[0];
        state.regs[3] = t49;
    // 0x0091a5a5: 85db TEST
    L_0091a5a5:
        t50a = state.regs[3];
        t50b = state.regs[3];
        t50r = (t50a & t50b) & 0xffffffffu;
        batch_set_logic_flags(state, t50r, 32u);
    // 0x0091a5a7: 7c09 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_0091a5b2;
    // 0x0091a5a9: 8b16 MOV
    L_0091a5a9:
        batch_guest_pc = 0x0091a5a9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t52)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t52;
    // 0x0091a5ab: 03d3 ADD
        t53a = state.regs[2];
        t53b = state.regs[3];
        t53r = static_cast<std::uint32_t>(t53a + t53b) & 0xffffffffu;
        batch_set_add_flags(state, t53a, t53b, t53r, 32u);
        state.regs[2] = t53r;
    // 0x0091a5ad: 03d5 ADD
        t54a = state.regs[2];
        t54b = state.regs[5];
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[2] = t54r;
    // 0x0091a5af: 895604 MOV
        batch_guest_pc = 0x0091a5afu;
        t55 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t55)) return BatchLiftStatus::invalid_memory;
    // 0x0091a5b2: 5f POP
    L_0091a5b2:
        batch_guest_pc = 0x0091a5b2u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t56a;
    // 0x0091a5b3: 8bc6 MOV
        t57 = state.regs[6];
        state.regs[0] = t57;
    // 0x0091a5b5: 5e POP
        batch_guest_pc = 0x0091a5b5u;
        if (!memory.load32(state.regs[4], t58a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t58a;
    // 0x0091a5b6: 5d POP
        batch_guest_pc = 0x0091a5b6u;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t59a;
    // 0x0091a5b7: 5b POP
        batch_guest_pc = 0x0091a5b7u;
        if (!memory.load32(state.regs[4], t60a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t60a;
    // 0x0091a5b8: 83c408 ADD
        t61a = state.regs[4];
        t61b = 0x00000008u;
        t61r = static_cast<std::uint32_t>(t61a + t61b) & 0xffffffffu;
        batch_set_add_flags(state, t61a, t61b, t61r, 32u);
        state.regs[4] = t61r;
    // 0x0091a5bb: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0091a5be: 85db TEST
    L_0091a5be:
        t63a = state.regs[3];
        t63b = state.regs[3];
        t63r = (t63a & t63b) & 0xffffffffu;
        batch_set_logic_flags(state, t63r, 32u);
    // 0x0091a5c0: 7de7 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_0091a5a9;
    // 0x0091a5c2: 2b06 SUB
        batch_guest_pc = 0x0091a5c2u;
        t65a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t65b)) return BatchLiftStatus::invalid_memory;
        t65r = static_cast<std::uint32_t>(t65a - t65b) & 0xffffffffu;
        batch_set_sub_flags(state, t65a, t65b, t65r, 32u);
        state.regs[0] = t65r;
    // 0x0091a5c4: c744241407000000 MOV
        batch_guest_pc = 0x0091a5c4u;
        t66 = 0x00000007u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t66)) return BatchLiftStatus::invalid_memory;
    // 0x0091a5cc: 03c0 ADD
        t67a = state.regs[0];
        t67b = state.regs[0];
        t67r = static_cast<std::uint32_t>(t67a + t67b) & 0xffffffffu;
        batch_set_add_flags(state, t67a, t67b, t67r, 32u);
        state.regs[0] = t67r;
    // 0x0091a5ce: 89442410 MOV
        batch_guest_pc = 0x0091a5ceu;
        t68 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x0091a5d2: 83f807 CMP
        t69a = state.regs[0];
        t69b = 0x00000007u;
        t69r = static_cast<std::uint32_t>(t69a - t69b) & 0xffffffffu;
        batch_set_sub_flags(state, t69a, t69b, t69r, 32u);
    // 0x0091a5d5: 8d442410 LEA
        t70 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[0] = t70;
    // 0x0091a5d9: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0091a5df;
    // 0x0091a5db: 8d442414 LEA
        t72 = static_cast<std::uint32_t>(state.regs[4] + 0x00000014u);
        state.regs[0] = t72;
    // 0x0091a5df: 8b38 MOV
    L_0091a5df:
        batch_guest_pc = 0x0091a5dfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t73)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t73;
    // 0x0091a5e1: 81ff40420f00 CMP
    L_0091a5e1:
        t74a = state.regs[7];
        t74b = 0x000f4240u;
        t74r = static_cast<std::uint32_t>(t74a - t74b) & 0xffffffffu;
        batch_set_sub_flags(state, t74a, t74b, t74r, 32u);
    // 0x0091a5e7: 73bc JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0091a5a5;
    // 0x0091a5e9: 57 PUSH
        batch_guest_pc = 0x0091a5e9u;
        t76a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t76a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a5ea: 8bce MOV
        t77 = state.regs[6];
        state.regs[1] = t77;
    // 0x0091a5ec: e86fbff6ff CALL
        if (!batch_guest_call32(memory, state, 0x00886560u, 0x0091a5f1u)) return BatchLiftStatus::invalid_memory;
        t78_call_status = spore_lift_00886560(memory, state);
        if (t78_call_status != BatchLiftStatus::returned) return t78_call_status;
        if (state.eip != 0x0091a5f1u) return BatchLiftStatus::invalid_control_flow;
    // 0x0091a5f1: 8b4c2420 MOV
        batch_guest_pc = 0x0091a5f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t79)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t79;
    // 0x0091a5f5: 8b54241c MOV
        batch_guest_pc = 0x0091a5f5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t80)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t80;
    // 0x0091a5f9: 8b06 MOV
        batch_guest_pc = 0x0091a5f9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t81)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t81;
    // 0x0091a5fb: 51 PUSH
        batch_guest_pc = 0x0091a5fbu;
        t82a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t82a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a5fc: 8bcf MOV
        t83 = state.regs[7];
        state.regs[1] = t83;
    // 0x0091a5fe: 2bcd SUB
        t84a = state.regs[1];
        t84b = state.regs[5];
        t84r = static_cast<std::uint32_t>(t84a - t84b) & 0xffffffffu;
        batch_set_sub_flags(state, t84a, t84b, t84r, 32u);
        state.regs[1] = t84r;
    // 0x0091a600: 52 PUSH
        batch_guest_pc = 0x0091a600u;
        t85a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t85a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a601: 41 INC
        t86a = state.regs[1];
        t86r = static_cast<std::uint32_t>(t86a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t86a, t86r, 32u);
        state.regs[1] = t86r;
    // 0x0091a602: 03c5 ADD
        t87a = state.regs[0];
        t87b = state.regs[5];
        t87r = static_cast<std::uint32_t>(t87a + t87b) & 0xffffffffu;
        batch_set_add_flags(state, t87a, t87b, t87r, 32u);
        state.regs[0] = t87r;
    // 0x0091a604: 51 PUSH
        batch_guest_pc = 0x0091a604u;
        t88a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t88a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a605: 50 PUSH
        batch_guest_pc = 0x0091a605u;
        t89a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t89a)) return BatchLiftStatus::invalid_memory;
    // 0x0091a606: e8f5dd0100 CALL
        if (!batch_guest_call32(memory, state, 0x00938400u, 0x0091a60bu)) return BatchLiftStatus::invalid_memory;
        t90_call_status = spore_lift_00938400(memory, state);
        if (t90_call_status != BatchLiftStatus::returned) return t90_call_status;
        if (state.eip != 0x0091a60bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0091a60b: 8bd8 MOV
        t91 = state.regs[0];
        state.regs[3] = t91;
    // 0x0091a60d: 83c410 ADD
        t92a = state.regs[4];
        t92b = 0x00000010u;
        t92r = static_cast<std::uint32_t>(t92a + t92b) & 0xffffffffu;
        batch_set_add_flags(state, t92a, t92b, t92r, 32u);
        state.regs[4] = t92r;
    // 0x0091a610: 03ff ADD
        t93a = state.regs[7];
        t93b = state.regs[7];
        t93r = static_cast<std::uint32_t>(t93a + t93b) & 0xffffffffu;
        batch_set_add_flags(state, t93a, t93b, t93r, 32u);
        state.regs[7] = t93r;
    // 0x0091a612: 85db TEST
        t94a = state.regs[3];
        t94b = state.regs[3];
        t94r = (t94a & t94b) & 0xffffffffu;
        batch_set_logic_flags(state, t94r, 32u);
    // 0x0091a614: 7ccb JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_0091a5e1;
    // 0x0091a616: eb91 JMP
        goto L_0091a5a9;
}
