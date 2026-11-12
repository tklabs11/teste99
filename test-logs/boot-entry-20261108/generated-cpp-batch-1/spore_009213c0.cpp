#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921300(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009213c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009213c0u);
    std::uint32_t t0 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;

    // 0x009213c0: 8b442404 MOV
        batch_guest_pc = 0x009213c0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009213c4: db442404 FILD
        if (!batch_guest_fild32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x009213c8: 83ec10 SUB
        t2a = state.regs[4];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x009213cb: 56 PUSH
        batch_guest_pc = 0x009213cbu;
        t3a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009213cc: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x009213ce: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x009213d0: 7d06 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_009213d8;
    // 0x009213d2: d805d04f3f01 FADD
        if (!batch_guest_x87_float32_arithmetic(memory, state, 0x013f4fd0u, 0u)) return BatchLiftStatus::invalid_memory;
    // 0x009213d8: d836 FDIV
    L_009213d8:
        if (!batch_guest_x87_float32_arithmetic(memory, state, static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), 2u)) return BatchLiftStatus::invalid_memory;
    // 0x009213da: d95c2418 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x009213de: f30f2c442418 CVTTSS2SI
        if (!batch_guest_cvttss2si_memory(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x009213e4: 8d4c2418 LEA
        t11 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[1] = t11;
    // 0x009213e8: 51 PUSH
        batch_guest_pc = 0x009213e8u;
        t12a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x009213e9: 6850dc4301 PUSH
        batch_guest_pc = 0x009213e9u;
        t13a = 0x0143dc50u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009213ee: 6850d84301 PUSH
        batch_guest_pc = 0x009213eeu;
        t14a = 0x0143d850u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x009213f3: 89442424 MOV
        batch_guest_pc = 0x009213f3u;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x009213f7: e804ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00921300u, 0x009213fcu)) return BatchLiftStatus::invalid_memory;
        t16_call_status = spore_lift_00921300(memory, state);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x009213fcu) return BatchLiftStatus::invalid_control_flow;
    // 0x009213fc: 8b10 MOV
        batch_guest_pc = 0x009213fcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x009213fe: 8bc2 MOV
        t18 = state.regs[2];
        state.regs[0] = t18;
    // 0x00921400: 83c40c ADD
        t19a = state.regs[4];
        t19b = 0x0000000cu;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[4] = t19r;
    // 0x00921403: 89442418 MOV
        batch_guest_pc = 0x00921403u;
        t20 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00921407: db442418 FILD
        if (!batch_guest_fild32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000018u))) return BatchLiftStatus::invalid_memory;
    // 0x0092140b: 85c0 TEST
        t22a = state.regs[0];
        t22b = state.regs[0];
        t22r = (t22a & t22b) & 0xffffffffu;
        batch_set_logic_flags(state, t22r, 32u);
    // 0x0092140d: 7d06 JGE
        if (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u)) goto L_00921415;
    // 0x0092140f: d805d04f3f01 FADD
        if (!batch_guest_x87_float32_arithmetic(memory, state, 0x013f4fd0u, 0u)) return BatchLiftStatus::invalid_memory;
    // 0x00921415: d80e FMUL
    L_00921415:
        if (!batch_guest_x87_float32_arithmetic(memory, state, static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), 1u)) return BatchLiftStatus::invalid_memory;
    // 0x00921417: d95c2404 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0092141b: f30f10442404 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00921421: f30f2dc0 CVTSS2SI
        if (!batch_guest_cvtss2si(state, 0u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00921425: f30f2ac8 CVTSI2SS
        if (!batch_guest_cvtsi2ss(state, 1u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00921429: 8bc8 MOV
        t30 = state.regs[0];
        state.regs[1] = t30;
    // 0x0092142b: 83c101 ADD
        t31a = state.regs[1];
        t31b = 0x00000001u;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[1] = t31r;
    // 0x0092142e: 0f2ec8 UCOMISS
        if (!batch_guest_ucomiss(state, 1u, 0u)) return BatchLiftStatus::invalid_control_flow;
    // 0x00921431: 0f42c1 CMOVC
        if ((state.eflags & 0x001u) != 0u) state.regs[0] = state.regs[1];
    // 0x00921434: 894608 MOV
        batch_guest_pc = 0x00921434u;
        t34 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00921437: 8bc2 MOV
        t35 = state.regs[2];
        state.regs[0] = t35;
    // 0x00921439: 5e POP
        batch_guest_pc = 0x00921439u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x0092143a: 83c410 ADD
        t37a = state.regs[4];
        t37b = 0x00000010u;
        t37r = static_cast<std::uint32_t>(t37a + t37b) & 0xffffffffu;
        batch_set_add_flags(state, t37a, t37b, t37r, 32u);
        state.regs[4] = t37r;
    // 0x0092143d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
