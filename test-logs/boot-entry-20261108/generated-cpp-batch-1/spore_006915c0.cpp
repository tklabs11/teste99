#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00691600(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922ab0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_006915c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x006915c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12a = 0, t12c = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20 = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t33a = 0, t33c = 0, t33r = 0;
    std::uint32_t t34a = 0, t34r = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0, t41b = 0, t41r = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    BatchLiftStatus t45_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47c = 0, t47r = 0;
    std::uint32_t t48a = 0, t48r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t53a = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55a = 0;

    // 0x006915c0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x006915c1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x006915c3: 8b86a0010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a0u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x006915c9: 85c0 TEST
        t3a = state.regs[0];
        t3b = state.regs[0];
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
    // 0x006915cb: 0f8ea3000000 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00691674;
    // 0x006915d1: 83c0ff ADD
        t5a = state.regs[0];
        t5b = 0xffffffffu;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[0] = t5r;
    // 0x006915d4: 8986a0010000 MOV
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a0u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x006915da: 0f8594000000 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00691674;
    // 0x006915e0: 53 PUSH
        t8a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x006915e1: 57 PUSH
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x006915e2: 8bbea8010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a8u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t10;
    // 0x006915e8: 2bbea4010000 SUB
        t11a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a4u), t11b)) return BatchLiftStatus::invalid_memory;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
        state.regs[7] = t11r;
    // 0x006915ee: c1ff02 SAR
        t12a = state.regs[7];
        t12c = 2u;
        if (t12c != 0u) {
        t12r = (t12a >> t12c) | ((t12a & 0x80000000u) ? (0xffffffffu << (32u - t12c)) : 0u);
        batch_set_sar_flags(state, t12a, t12c, t12r, 32u);
            state.regs[7] = t12r;
        }
    // 0x006915f1: 83ef01 SUB
        t13a = state.regs[7];
        t13b = 0x00000001u;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
        state.regs[7] = t13r;
    // 0x006915f4: 7827 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_0069161d;
    // 0x006915f6: eb08 JMP
        goto L_00691600;
    // 0x00691600: 8b86a4010000 MOV
    L_00691600:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a4u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t16;
    // 0x00691606: 8b0cb8 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + state.regs[7] * 4u + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00691609: 8b96b8010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001b8u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x0069160f: 51 PUSH
        t19a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00691610: 8b0cba MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 4u + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t20;
    // 0x00691613: e898142900 CALL
        t21_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922ab0u, 0x00691618u);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00691618u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691618: 83ef01 SUB
        t22a = state.regs[7];
        t22b = 0x00000001u;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
        state.regs[7] = t22r;
    // 0x0069161b: 79e3 JNS
        if (!((state.eflags & 0x080u) != 0u)) goto L_00691600;
    // 0x0069161d: 8bbea8010000 MOV
    L_0069161d:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a8u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t24;
    // 0x00691623: 8b9ea4010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a4u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t25;
    // 0x00691629: 8bc7 MOV
        t26 = state.regs[7];
        state.regs[0] = t26;
    // 0x0069162b: 2bc7 SUB
        t27a = state.regs[0];
        t27b = state.regs[7];
        t27r = static_cast<std::uint32_t>(t27a - t27b) & 0xffffffffu;
        batch_set_sub_flags(state, t27a, t27b, t27r, 32u);
        state.regs[0] = t27r;
    // 0x0069162d: 50 PUSH
        t28a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x0069162e: 57 PUSH
        t29a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x0069162f: 53 PUSH
        t30a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
    // 0x00691630: e80ff1b400 CALL
        t31_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x00691635u);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
        if (state.eip != 0x00691635u) return BatchLiftStatus::invalid_control_flow;
    // 0x00691635: 2bfb SUB
        t32a = state.regs[7];
        t32b = state.regs[3];
        t32r = static_cast<std::uint32_t>(t32a - t32b) & 0xffffffffu;
        batch_set_sub_flags(state, t32a, t32b, t32r, 32u);
        state.regs[7] = t32r;
    // 0x00691637: c1ff02 SAR
        t33a = state.regs[7];
        t33c = 2u;
        if (t33c != 0u) {
        t33r = (t33a >> t33c) | ((t33a & 0x80000000u) ? (0xffffffffu << (32u - t33c)) : 0u);
        batch_set_sar_flags(state, t33a, t33c, t33r, 32u);
            state.regs[7] = t33r;
        }
    // 0x0069163a: f7df NEG
        t34a = state.regs[7];
        t34r = static_cast<std::uint32_t>(0u - t34a) & 0xffffffffu;
        batch_set_neg_flags(state, t34a, t34r, 32u);
        state.regs[7] = t34r;
    // 0x0069163c: 03ff ADD
        t35a = state.regs[7];
        t35b = state.regs[7];
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[7] = t35r;
    // 0x0069163e: 03ff ADD
        t36a = state.regs[7];
        t36b = state.regs[7];
        t36r = static_cast<std::uint32_t>(t36a + t36b) & 0xffffffffu;
        batch_set_add_flags(state, t36a, t36b, t36r, 32u);
        state.regs[7] = t36r;
    // 0x00691640: 01bea8010000 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a8u), t37a)) return BatchLiftStatus::invalid_memory;
        t37b = state.regs[7];
        t37r = static_cast<std::uint32_t>(t37a + t37b) & 0xffffffffu;
        batch_set_add_flags(state, t37a, t37b, t37r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000001a8u), t37r)) return BatchLiftStatus::invalid_memory;
    // 0x00691646: 8bbebc010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001bcu), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t38;
    // 0x0069164c: 8b9eb8010000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001b8u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t39;
    // 0x00691652: 8bcf MOV
        t40 = state.regs[7];
        state.regs[1] = t40;
    // 0x00691654: 2bcf SUB
        t41a = state.regs[1];
        t41b = state.regs[7];
        t41r = static_cast<std::uint32_t>(t41a - t41b) & 0xffffffffu;
        batch_set_sub_flags(state, t41a, t41b, t41r, 32u);
        state.regs[1] = t41r;
    // 0x00691656: 51 PUSH
        t42a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00691657: 57 PUSH
        t43a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
    // 0x00691658: 53 PUSH
        t44a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
    // 0x00691659: e8e6f0b400 CALL
        t45_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!memcpy", 0x013cc47cu, 0x0069165eu);
        if (t45_call_status != BatchLiftStatus::returned) return t45_call_status;
        if (state.eip != 0x0069165eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0069165e: 2bfb SUB
        t46a = state.regs[7];
        t46b = state.regs[3];
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
        state.regs[7] = t46r;
    // 0x00691660: c1ff02 SAR
        t47a = state.regs[7];
        t47c = 2u;
        if (t47c != 0u) {
        t47r = (t47a >> t47c) | ((t47a & 0x80000000u) ? (0xffffffffu << (32u - t47c)) : 0u);
        batch_set_sar_flags(state, t47a, t47c, t47r, 32u);
            state.regs[7] = t47r;
        }
    // 0x00691663: f7df NEG
        t48a = state.regs[7];
        t48r = static_cast<std::uint32_t>(0u - t48a) & 0xffffffffu;
        batch_set_neg_flags(state, t48a, t48r, 32u);
        state.regs[7] = t48r;
    // 0x00691665: 03ff ADD
        t49a = state.regs[7];
        t49b = state.regs[7];
        t49r = static_cast<std::uint32_t>(t49a + t49b) & 0xffffffffu;
        batch_set_add_flags(state, t49a, t49b, t49r, 32u);
        state.regs[7] = t49r;
    // 0x00691667: 83c418 ADD
        t50a = state.regs[4];
        t50b = 0x00000018u;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[4] = t50r;
    // 0x0069166a: 03ff ADD
        t51a = state.regs[7];
        t51b = state.regs[7];
        t51r = static_cast<std::uint32_t>(t51a + t51b) & 0xffffffffu;
        batch_set_add_flags(state, t51a, t51b, t51r, 32u);
        state.regs[7] = t51r;
    // 0x0069166c: 01bebc010000 ADD
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x000001bcu), t52a)) return BatchLiftStatus::invalid_memory;
        t52b = state.regs[7];
        t52r = static_cast<std::uint32_t>(t52a + t52b) & 0xffffffffu;
        batch_set_add_flags(state, t52a, t52b, t52r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x000001bcu), t52r)) return BatchLiftStatus::invalid_memory;
    // 0x00691672: 5f POP
        if (!memory.load32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t53a;
    // 0x00691673: 5b POP
        if (!memory.load32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t54a;
    // 0x00691674: 5e POP
    L_00691674:
        if (!memory.load32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t55a;
    // 0x00691675: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
