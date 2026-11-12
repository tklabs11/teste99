#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922130(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009255a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009255a0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t16a = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;

    // 0x009255a0: 56 PUSH
        batch_guest_pc = 0x009255a0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009255a1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x009255a3: 8d4e20 LEA
        t2 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[1] = t2;
    // 0x009255a6: c70650e04301 MOV
        batch_guest_pc = 0x009255a6u;
        t3 = 0x0143e050u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x009255ac: e87fcbffff CALL
        if (!batch_guest_call32(memory, state, 0x00922130u, 0x009255b1u)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_00922130(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x009255b1u) return BatchLiftStatus::invalid_control_flow;
    // 0x009255b1: 8b4608 MOV
        batch_guest_pc = 0x009255b1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x009255b4: 85c0 TEST
        t6a = state.regs[0];
        t6b = state.regs[0];
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
    // 0x009255b6: 740f JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009255c7;
    // 0x009255b8: 8378fc00 CMP
        batch_guest_pc = 0x009255b8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0xfffffffcu), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = 0x00000000u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x009255bc: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009255c7;
    // 0x009255be: 50 PUSH
        batch_guest_pc = 0x009255beu;
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x009255bf: e8bc1d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009255c4u)) return BatchLiftStatus::invalid_memory;
        t11_call_status = spore_lift_00f47380(memory, state);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x009255c4u) return BatchLiftStatus::invalid_control_flow;
    // 0x009255c4: 83c404 ADD
        t12a = state.regs[4];
        t12b = 0x00000004u;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[4] = t12r;
    // 0x009255c7: f644240801 TEST
    L_009255c7:
        batch_guest_pc = 0x009255c7u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t13a)) return BatchLiftStatus::invalid_memory;
        t13b = 0x00000001u;
        t13r = (t13a & t13b) & 0x000000ffu;
        batch_set_logic_flags(state, t13r, 8u);
    // 0x009255cc: c70638b93e01 MOV
        batch_guest_pc = 0x009255ccu;
        t14 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x009255d2: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009255dd;
    // 0x009255d4: 56 PUSH
        batch_guest_pc = 0x009255d4u;
        t16a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x009255d5: e8a61d6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x009255dau)) return BatchLiftStatus::invalid_memory;
        t17_call_status = spore_lift_00f47380(memory, state);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x009255dau) return BatchLiftStatus::invalid_control_flow;
    // 0x009255da: 83c404 ADD
        t18a = state.regs[4];
        t18b = 0x00000004u;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[4] = t18r;
    // 0x009255dd: 8bc6 MOV
    L_009255dd:
        t19 = state.regs[6];
        state.regs[0] = t19;
    // 0x009255df: 5e POP
        batch_guest_pc = 0x009255dfu;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x009255e0: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
