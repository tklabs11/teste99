#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_0093a3a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0093a640(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_0093a650(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e0846(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0093a5e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093a5e0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27 = 0;
    BatchLiftStatus t28_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t29a = 0, t29b = 0, t29r = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34a = 0, t34b = 0, t34r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0, t38b = 0, t38r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0, t42b = 0, t42r = 0;
    std::uint32_t t43a = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t46a = 0;
    std::uint32_t t47a = 0, t47b = 0, t47r = 0;

    // 0x0093a5e0: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x0093a5e3: 56 PUSH
        batch_guest_pc = 0x0093a5e3u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5e4: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x0093a5e6: e8b5fdffff CALL
        if (!batch_guest_call32(memory, state, 0x0093a3a0u, 0x0093a5ebu)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_0093a3a0(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0093a5ebu) return BatchLiftStatus::invalid_control_flow;
    // 0x0093a5eb: 89442404 MOV
        batch_guest_pc = 0x0093a5ebu;
        t4 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5ef: 89542408 MOV
        batch_guest_pc = 0x0093a5efu;
        t5 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5f3: df6c2404 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a5f7: d84e14 FMUL
        if (!batch_guest_x87_float32_arithmetic(memory, state, static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), 1u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a5fa: 5e POP
        batch_guest_pc = 0x0093a5fau;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t8a;
    // 0x0093a5fb: d80598ea4301 FADD
        if (!batch_guest_x87_float32_arithmetic(memory, state, 0x0143ea98u, 0u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a601: 83c408 ADD
        t10a = state.regs[4];
        t10b = 0x00000008u;
        t10r = static_cast<std::uint32_t>(t10a + t10b) & 0xffffffffu;
        batch_set_add_flags(state, t10a, t10b, t10r, 32u);
        state.regs[4] = t10r;
    // 0x0093a604: e93d628a00 JMP
        state.eip = 0x011e0846u;
        return spore_lift_011e0846(memory, state);
    // 0x0093a609: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60a: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60b: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60c: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60d: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a60f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0093a610: 81ec00080000 SUB
        t19a = state.regs[4];
        t19b = 0x00000800u;
        t19r = static_cast<std::uint32_t>(t19a - t19b) & 0xffffffffu;
        batch_set_sub_flags(state, t19a, t19b, t19r, 32u);
        state.regs[4] = t19r;
    // 0x0093a616: 53 PUSH
        batch_guest_pc = 0x0093a616u;
        t20a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a617: 8b9c2408080000 MOV
        batch_guest_pc = 0x0093a617u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000808u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t21;
    // 0x0093a61e: 8b03 MOV
        batch_guest_pc = 0x0093a61eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t22;
    // 0x0093a620: 8b501c MOV
        batch_guest_pc = 0x0093a620u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t23;
    // 0x0093a623: 55 PUSH
        batch_guest_pc = 0x0093a623u;
        t24a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a624: 56 PUSH
        batch_guest_pc = 0x0093a624u;
        t25a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a625: 57 PUSH
        batch_guest_pc = 0x0093a625u;
        t26a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a626: 8bcb MOV
        t27 = state.regs[3];
        state.regs[1] = t27;
    // 0x0093a628: ffd2 CALL
        t28_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x0093a62au);
        if (t28_call_status != BatchLiftStatus::returned) return t28_call_status;
    // 0x0093a62a: 83f8ff CMP
        t29a = state.regs[0];
        t29b = 0xffffffffu;
        t29r = static_cast<std::uint32_t>(t29a - t29b) & 0xffffffffu;
        batch_set_sub_flags(state, t29a, t29b, t29r, 32u);
    // 0x0093a62d: 7504 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a633;
    // 0x0093a62f: 0be8 OR
        t31a = state.regs[5];
        t31b = state.regs[0];
        t31r = (t31a | t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
        state.regs[5] = t31r;
    // 0x0093a631: eb0d JMP
        goto L_0093a640;
    // 0x0093a633: 8bac241c080000 MOV
    L_0093a633:
        batch_guest_pc = 0x0093a633u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000081cu), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t33;
    // 0x0093a63a: 3be8 CMP
        t34a = state.regs[5];
        t34b = state.regs[0];
        t34r = static_cast<std::uint32_t>(t34a - t34b) & 0xffffffffu;
        batch_set_sub_flags(state, t34a, t34b, t34r, 32u);
    // 0x0093a63c: 7602 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_0093a640;
    // 0x0093a63e: 8be8 MOV
        t36 = state.regs[0];
        state.regs[5] = t36;
    // 0x0093a640: 8bfd MOV
    L_0093a640:
        t37 = state.regs[5];
        state.regs[7] = t37;
    // 0x0093a642: 85ed TEST
        t38a = state.regs[5];
        t38b = state.regs[5];
        t38r = (t38a & t38b) & 0xffffffffu;
        batch_set_logic_flags(state, t38r, 32u);
    // 0x0093a644: 744f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0093a695;
    // 0x0093a646: eb08 JMP
        state.eip = 0x0093a650u;
        return spore_lift_0093a650(memory, state);
    // 0x0093a695: 8bc5 MOV
    L_0093a695:
        t41 = state.regs[5];
        state.regs[0] = t41;
    // 0x0093a697: 2bc7 SUB
        t42a = state.regs[0];
        t42b = state.regs[7];
        t42r = static_cast<std::uint32_t>(t42a - t42b) & 0xffffffffu;
        batch_set_sub_flags(state, t42a, t42b, t42r, 32u);
        state.regs[0] = t42r;
    // 0x0093a699: 5f POP
        batch_guest_pc = 0x0093a699u;
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t43a;
    // 0x0093a69a: 5e POP
        batch_guest_pc = 0x0093a69au;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t44a;
    // 0x0093a69b: 5d POP
        batch_guest_pc = 0x0093a69bu;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t45a;
    // 0x0093a69c: 5b POP
        batch_guest_pc = 0x0093a69cu;
        if (!memory.load32(state.regs[4], t46a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t46a;
    // 0x0093a69d: 81c400080000 ADD
        t47a = state.regs[4];
        t47b = 0x00000800u;
        t47r = static_cast<std::uint32_t>(t47a + t47b) & 0xffffffffu;
        batch_set_add_flags(state, t47a, t47b, t47r, 32u);
        state.regs[4] = t47r;
    // 0x0093a6a3: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
