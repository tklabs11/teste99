#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923b40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00923bc0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923f90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923f90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;

    // 0x00923f90: 51 PUSH
        batch_guest_pc = 0x00923f90u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f91: 56 PUSH
        batch_guest_pc = 0x00923f91u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f92: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00923f94: 8d442407 LEA
        t3 = static_cast<std::uint32_t>(state.regs[4] + 0x00000007u);
        state.regs[0] = t3;
    // 0x00923f98: 50 PUSH
        batch_guest_pc = 0x00923f98u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00923f99: c7069cdd4301 MOV
        batch_guest_pc = 0x00923f99u;
        t5 = 0x0143dd9cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00923f9f: c7461801000000 MOV
        batch_guest_pc = 0x00923f9fu;
        t6 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00923fa6: c644240b00 MOV
        batch_guest_pc = 0x00923fa6u;
        t7 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x0000000bu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00923fab: e810fcffff CALL
        if (!batch_guest_call32(memory, state, 0x00923bc0u, 0x00923fb0u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00923bc0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00923fb0u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923fb0: 8b5628 MOV
        batch_guest_pc = 0x00923fb0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000028u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00923fb3: 8d4e1c LEA
        t10 = static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu);
        state.regs[1] = t10;
    // 0x00923fb6: 52 PUSH
        batch_guest_pc = 0x00923fb6u;
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00923fb7: e884fbffff CALL
        if (!batch_guest_call32(memory, state, 0x00923b40u, 0x00923fbcu)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00923b40(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00923fbcu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923fbc: 8b4608 MOV
        batch_guest_pc = 0x00923fbcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00923fbf: 8b4e10 MOV
        batch_guest_pc = 0x00923fbfu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00923fc2: 2bc8 SUB
        t15a = state.regs[1];
        t15b = state.regs[0];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[1] = t15r;
    // 0x00923fc4: 83f901 CMP
        t16a = state.regs[1];
        t16b = 0x00000001u;
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x00923fc7: 7e0d JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923fd6;
    // 0x00923fc9: 85c0 TEST
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
    // 0x00923fcb: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923fd6;
    // 0x00923fcd: 50 PUSH
        batch_guest_pc = 0x00923fcdu;
        t20a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
    // 0x00923fce: e8ad336200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923fd3u)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_00f47380(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00923fd3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923fd3: 83c404 ADD
        t22a = state.regs[4];
        t22b = 0x00000004u;
        t22r = static_cast<std::uint32_t>(t22a + t22b) & 0xffffffffu;
        batch_set_add_flags(state, t22a, t22b, t22r, 32u);
        state.regs[4] = t22r;
    // 0x00923fd6: c70638b93e01 MOV
    L_00923fd6:
        batch_guest_pc = 0x00923fd6u;
        t23 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00923fdc: 5e POP
        batch_guest_pc = 0x00923fdcu;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x00923fdd: 59 POP
        batch_guest_pc = 0x00923fddu;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t25a;
    // 0x00923fde: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
