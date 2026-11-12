#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e08b9(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e0846(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e0846u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19c = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21c = 0, t21r = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26c = 0, t26r = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28c = 0, t28r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t35 = 0;

    // 0x011e0846: 55 PUSH
        batch_guest_pc = 0x011e0846u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0847: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x011e0849: 83ec20 SUB
        t2a = state.regs[4];
        t2b = 0x00000020u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x011e084c: 83e4f0 AND
        t3a = state.regs[4];
        t3b = 0xfffffff0u;
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[4] = t3r;
    // 0x011e084f: d9c0 FLD
        if (!batch_guest_fld_stack(state, 0u)) return BatchLiftStatus::invalid_x87_state;
    // 0x011e0851: d9542418 FST
        if (!batch_guest_fst32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x011e0855: df7c2410 FISTP
        if (!batch_guest_fistp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000010u))) return BatchLiftStatus::invalid_memory;
    // 0x011e0859: df6c2410 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000010u))) return BatchLiftStatus::invalid_memory;
    // 0x011e085d: 8b542418 MOV
        batch_guest_pc = 0x011e085du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x011e0861: 8b442410 MOV
        batch_guest_pc = 0x011e0861u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x011e0865: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x011e0867: 743c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e08a5;
    // 0x011e0869: dee9 FSUBP
    L_011e0869:
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 3u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x011e086b: 85d2 TEST
        t13a = state.regs[2];
        t13b = state.regs[2];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
    // 0x011e086d: 791e JNS
        if (!((state.eflags & 0x080u) != 0u)) goto L_011e088d;
    // 0x011e086f: d91c24 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x011e0872: 8b0c24 MOV
        batch_guest_pc = 0x011e0872u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x011e0875: 81f100000080 XOR
        t17a = state.regs[1];
        t17b = 0x80000000u;
        t17r = (t17a ^ t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
        state.regs[1] = t17r;
    // 0x011e087b: 81c1ffffff7f ADD
        t18a = state.regs[1];
        t18b = 0x7fffffffu;
        t18r = static_cast<std::uint32_t>(t18a + t18b) & 0xffffffffu;
        batch_set_add_flags(state, t18a, t18b, t18r, 32u);
        state.regs[1] = t18r;
    // 0x011e0881: 83d000 ADC
        t19a = state.regs[0];
        t19b = 0x00000000u;
        t19c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t19r = static_cast<std::uint32_t>(t19a + t19b + t19c) & 0xffffffffu;
        batch_set_adc_flags(state, t19a, t19b, t19c, t19r, 32u);
        state.regs[0] = t19r;
    // 0x011e0884: 8b542414 MOV
        batch_guest_pc = 0x011e0884u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t20;
    // 0x011e0888: 83d200 ADC
        t21a = state.regs[2];
        t21b = 0x00000000u;
        t21c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t21r = static_cast<std::uint32_t>(t21a + t21b + t21c) & 0xffffffffu;
        batch_set_adc_flags(state, t21a, t21b, t21c, t21r, 32u);
        state.regs[2] = t21r;
    // 0x011e088b: eb2c JMP
        goto L_011e08b9;
    // 0x011e088d: d91c24 FSTP
    L_011e088d:
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x011e0890: 8b0c24 MOV
        batch_guest_pc = 0x011e0890u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000000u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x011e0893: 81c1ffffff7f ADD
        t25a = state.regs[1];
        t25b = 0x7fffffffu;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[1] = t25r;
    // 0x011e0899: 83d800 SBB
        t26a = state.regs[0];
        t26b = 0x00000000u;
        t26c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t26r = static_cast<std::uint32_t>(t26a - t26b - t26c) & 0xffffffffu;
        batch_set_sbb_flags(state, t26a, t26b, t26c, t26r, 32u);
        state.regs[0] = t26r;
    // 0x011e089c: 8b542414 MOV
        batch_guest_pc = 0x011e089cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x011e08a0: 83da00 SBB
        t28a = state.regs[2];
        t28b = 0x00000000u;
        t28c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t28r = static_cast<std::uint32_t>(t28a - t28b - t28c) & 0xffffffffu;
        batch_set_sbb_flags(state, t28a, t28b, t28c, t28r, 32u);
        state.regs[2] = t28r;
    // 0x011e08a3: eb14 JMP
        goto L_011e08b9;
    // 0x011e08a5: 8b542414 MOV
    L_011e08a5:
        batch_guest_pc = 0x011e08a5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x011e08a9: f7c2ffffff7f TEST
        t31a = state.regs[2];
        t31b = 0x7fffffffu;
        t31r = (t31a & t31b) & 0xffffffffu;
        batch_set_logic_flags(state, t31r, 32u);
    // 0x011e08af: 75b8 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e0869;
    // 0x011e08b1: d95c2418 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x011e08b5: d95c2418 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x011e08b9: c9 LEAVE
    L_011e08b9:
        batch_guest_pc = 0x011e08b9u;
        state.regs[4] = state.regs[5];
        if (!memory.load32(state.regs[4], t35)) return BatchLiftStatus::invalid_memory;
        state.regs[5] = t35;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
    // 0x011e08ba: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
