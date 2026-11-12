#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00886780(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009199c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00919a80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00919a80u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    BatchLiftStatus t35_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43 = 0;
    BatchLiftStatus t44_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t51a = 0, t51b = 0, t51r = 0;
    std::uint32_t t53a = 0;
    BatchLiftStatus t54_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t55a = 0, t55b = 0, t55r = 0;
    std::uint32_t t56a = 0;
    std::uint32_t t57a = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;

    // 0x00919a80: 83ec14 SUB
        t0a = state.regs[4];
        t0b = 0x00000014u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00919a83: 56 PUSH
        batch_guest_pc = 0x00919a83u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a84: 8b74241c MOV
        batch_guest_pc = 0x00919a84u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x00919a88: 57 PUSH
        batch_guest_pc = 0x00919a88u;
        t3a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00919a89: 8bf9 MOV
        t4 = state.regs[1];
        state.regs[7] = t4;
    // 0x00919a8b: 8d460c LEA
        t5 = static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu);
        state.regs[0] = t5;
    // 0x00919a8e: 8d4f0c LEA
        t6 = static_cast<std::uint32_t>(state.regs[7] + 0x0000000cu);
        state.regs[1] = t6;
    // 0x00919a91: 3bc8 CMP
        t7a = state.regs[1];
        t7b = state.regs[0];
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x00919a93: 7528 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00919abd;
    // 0x00919a95: 8b16 MOV
        batch_guest_pc = 0x00919a95u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00919a97: 8b07 MOV
        batch_guest_pc = 0x00919a97u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00919a99: 8917 MOV
        batch_guest_pc = 0x00919a99u;
        t11 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00919a9b: 8906 MOV
        batch_guest_pc = 0x00919a9bu;
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00919a9d: 8b4704 MOV
        batch_guest_pc = 0x00919a9du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00919aa0: 8b4e04 MOV
        batch_guest_pc = 0x00919aa0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00919aa3: 894f04 MOV
        batch_guest_pc = 0x00919aa3u;
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00919aa6: 894604 MOV
        batch_guest_pc = 0x00919aa6u;
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00919aa9: 8b5608 MOV
        batch_guest_pc = 0x00919aa9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00919aac: 8b4708 MOV
        batch_guest_pc = 0x00919aacu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x00919aaf: 895708 MOV
        batch_guest_pc = 0x00919aafu;
        t19 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[7] + 0x00000008u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00919ab2: 5f POP
        batch_guest_pc = 0x00919ab2u;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t20a;
    // 0x00919ab3: 894608 MOV
        batch_guest_pc = 0x00919ab3u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00919ab6: 5e POP
        batch_guest_pc = 0x00919ab6u;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x00919ab7: 83c414 ADD
        t23a = state.regs[4];
        t23b = 0x00000014u;
        t23r = static_cast<std::uint32_t>(t23a + t23b) & 0xffffffffu;
        batch_set_add_flags(state, t23a, t23b, t23r, 32u);
        state.regs[4] = t23r;
    // 0x00919aba: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00919abd: 57 PUSH
    L_00919abd:
        batch_guest_pc = 0x00919abdu;
        t25a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00919abe: 8d4c240c LEA
        t26 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t26;
    // 0x00919ac2: e8b9ccf6ff CALL
        if (!batch_guest_call32(memory, state, 0x00886780u, 0x00919ac7u)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_00886780(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00919ac7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00919ac7: 3bf7 CMP
        t28a = state.regs[6];
        t28b = state.regs[7];
        t28r = static_cast<std::uint32_t>(t28a - t28b) & 0xffffffffu;
        batch_set_sub_flags(state, t28a, t28b, t28r, 32u);
    // 0x00919ac9: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00919ad9;
    // 0x00919acb: 8b4604 MOV
        batch_guest_pc = 0x00919acbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x00919ace: 8b0e MOV
        batch_guest_pc = 0x00919aceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x00919ad0: 50 PUSH
        batch_guest_pc = 0x00919ad0u;
        t32a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00919ad1: 51 PUSH
        batch_guest_pc = 0x00919ad1u;
        t33a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00919ad2: 8bcf MOV
        t34 = state.regs[7];
        state.regs[1] = t34;
    // 0x00919ad4: e8e7feffff CALL
        if (!batch_guest_call32(memory, state, 0x009199c0u, 0x00919ad9u)) return BatchLiftStatus::invalid_memory;
        t35_call_status = spore_lift_009199c0(memory, state);
        if (t35_call_status != BatchLiftStatus::returned) return t35_call_status;
        if (state.eip != 0x00919ad9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00919ad9: 8b7c2408 MOV
    L_00919ad9:
        batch_guest_pc = 0x00919ad9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t36;
    // 0x00919add: 8d542408 LEA
        t37 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[2] = t37;
    // 0x00919ae1: 3bd6 CMP
        t38a = state.regs[2];
        t38b = state.regs[6];
        t38r = static_cast<std::uint32_t>(t38a - t38b) & 0xffffffffu;
        batch_set_sub_flags(state, t38a, t38b, t38r, 32u);
    // 0x00919ae3: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00919af2;
    // 0x00919ae5: 8b44240c MOV
        batch_guest_pc = 0x00919ae5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t40;
    // 0x00919ae9: 50 PUSH
        batch_guest_pc = 0x00919ae9u;
        t41a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t41a)) return BatchLiftStatus::invalid_memory;
    // 0x00919aea: 57 PUSH
        batch_guest_pc = 0x00919aeau;
        t42a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
    // 0x00919aeb: 8bce MOV
        t43 = state.regs[6];
        state.regs[1] = t43;
    // 0x00919aed: e8cefeffff CALL
        if (!batch_guest_call32(memory, state, 0x009199c0u, 0x00919af2u)) return BatchLiftStatus::invalid_memory;
        t44_call_status = spore_lift_009199c0(memory, state);
        if (t44_call_status != BatchLiftStatus::returned) return t44_call_status;
        if (state.eip != 0x00919af2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00919af2: 8b4c2410 MOV
    L_00919af2:
        batch_guest_pc = 0x00919af2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t45;
    // 0x00919af6: 2bcf SUB
        t46a = state.regs[1];
        t46b = state.regs[7];
        t46r = static_cast<std::uint32_t>(t46a - t46b) & 0xffffffffu;
        batch_set_sub_flags(state, t46a, t46b, t46r, 32u);
        state.regs[1] = t46r;
    // 0x00919af8: 83f901 CMP
        t47a = state.regs[1];
        t47b = 0x00000001u;
        t47r = static_cast<std::uint32_t>(t47a - t47b) & 0xffffffffu;
        batch_set_sub_flags(state, t47a, t47b, t47r, 32u);
    // 0x00919afb: 7e13 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00919b10;
    // 0x00919afd: 85ff TEST
        t49a = state.regs[7];
        t49b = state.regs[7];
        t49r = (t49a & t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
    // 0x00919aff: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00919b10;
    // 0x00919b01: 3b7c2418 CMP
        batch_guest_pc = 0x00919b01u;
        t51a = state.regs[7];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t51b)) return BatchLiftStatus::invalid_memory;
        t51r = static_cast<std::uint32_t>(t51a - t51b) & 0xffffffffu;
        batch_set_sub_flags(state, t51a, t51b, t51r, 32u);
    // 0x00919b05: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00919b10;
    // 0x00919b07: 57 PUSH
        batch_guest_pc = 0x00919b07u;
        t53a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t53a)) return BatchLiftStatus::invalid_memory;
    // 0x00919b08: e873d86200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00919b0du)) return BatchLiftStatus::invalid_memory;
        t54_call_status = spore_lift_00f47380(memory, state);
        if (t54_call_status != BatchLiftStatus::returned) return t54_call_status;
        if (state.eip != 0x00919b0du) return BatchLiftStatus::invalid_control_flow;
    // 0x00919b0d: 83c404 ADD
        t55a = state.regs[4];
        t55b = 0x00000004u;
        t55r = static_cast<std::uint32_t>(t55a + t55b) & 0xffffffffu;
        batch_set_add_flags(state, t55a, t55b, t55r, 32u);
        state.regs[4] = t55r;
    // 0x00919b10: 5f POP
    L_00919b10:
        batch_guest_pc = 0x00919b10u;
        if (!memory.load32(state.regs[4], t56a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t56a;
    // 0x00919b11: 5e POP
        batch_guest_pc = 0x00919b11u;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t57a;
    // 0x00919b12: 83c414 ADD
        t58a = state.regs[4];
        t58b = 0x00000014u;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x00919b15: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
