#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00937da0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00938400(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00938400u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8c = 0, t8r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0, t23b = 0, t23r = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30a = 0, t30b = 0, t30r = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;
    std::uint32_t t37a = 0, t37b = 0, t37r = 0;

    // 0x00938400: 83ec10 SUB
        t0a = state.regs[4];
        t0b = 0x00000010u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00938403: 8b4c2420 MOV
        batch_guest_pc = 0x00938403u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00938407: 56 PUSH
        batch_guest_pc = 0x00938407u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00938408: 8b742418 MOV
        batch_guest_pc = 0x00938408u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x0093840c: 57 PUSH
        batch_guest_pc = 0x0093840cu;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0093840d: 8b7c2420 MOV
        batch_guest_pc = 0x0093840du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t5;
    // 0x00938411: 8bc6 MOV
        t6 = state.regs[6];
        state.regs[0] = t6;
    // 0x00938413: f7d8 NEG
        t7a = state.regs[0];
        t7r = static_cast<std::uint32_t>(0u - t7a) & 0xffffffffu;
        batch_set_neg_flags(state, t7a, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00938415: 1bc0 SBB
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8c = (state.eflags & 0x001u) != 0u ? 1u : 0u;
        t8r = static_cast<std::uint32_t>(t8a - t8b - t8c) & 0xffffffffu;
        batch_set_sbb_flags(state, t8a, t8b, t8c, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00938417: 51 PUSH
        batch_guest_pc = 0x00938417u;
        t9a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00938418: 23c7 AND
        t10a = state.regs[0];
        t10b = state.regs[7];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[0] = t10r;
    // 0x0093841a: 8d54240c LEA
        t11 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[2] = t11;
    // 0x0093841e: 52 PUSH
        batch_guest_pc = 0x0093841eu;
        t12a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x0093841f: 89442418 MOV
        batch_guest_pc = 0x0093841fu;
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00938423: 8b44242c MOV
        batch_guest_pc = 0x00938423u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00938427: 6870839300 PUSH
        batch_guest_pc = 0x00938427u;
        t15a = 0x00938370u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x0093842c: 89742414 MOV
        batch_guest_pc = 0x0093842cu;
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00938430: c744241800000000 MOV
        batch_guest_pc = 0x00938430u;
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00938438: c644242000 MOV
        batch_guest_pc = 0x00938438u;
        t18 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x0093843d: e85ef9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00937da0u, 0x00938442u)) return BatchLiftStatus::invalid_memory;
        t19_call_status = spore_lift_00937da0(memory, state);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
        if (state.eip != 0x00938442u) return BatchLiftStatus::invalid_control_flow;
    // 0x00938442: 83c40c ADD
        t20a = state.regs[4];
        t20b = 0x0000000cu;
        t20r = static_cast<std::uint32_t>(t20a + t20b) & 0xffffffffu;
        batch_set_add_flags(state, t20a, t20b, t20r, 32u);
        state.regs[4] = t20r;
    // 0x00938445: 85f6 TEST
        t21a = state.regs[6];
        t21b = state.regs[6];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x00938447: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00938464;
    // 0x00938449: 85c0 TEST
        t23a = state.regs[0];
        t23b = state.regs[0];
        t23r = (t23a & t23b) & 0xffffffffu;
        batch_set_logic_flags(state, t23r, 32u);
    // 0x0093844b: 7c17 JL
        if (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u)) goto L_00938464;
    // 0x0093844d: 3bc7 CMP
        t25a = state.regs[0];
        t25b = state.regs[7];
        t25r = static_cast<std::uint32_t>(t25a - t25b) & 0xffffffffu;
        batch_set_sub_flags(state, t25a, t25b, t25r, 32u);
    // 0x0093844f: 730a JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0093845b;
    // 0x00938451: 5f POP
        batch_guest_pc = 0x00938451u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t27a;
    // 0x00938452: c6043000 MOV
        batch_guest_pc = 0x00938452u;
        t28 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + state.regs[6] * 1u + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00938456: 5e POP
        batch_guest_pc = 0x00938456u;
        if (!memory.load32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t29a;
    // 0x00938457: 83c410 ADD
        t30a = state.regs[4];
        t30b = 0x00000010u;
        t30r = static_cast<std::uint32_t>(t30a + t30b) & 0xffffffffu;
        batch_set_add_flags(state, t30a, t30b, t30r, 32u);
        state.regs[4] = t30r;
    // 0x0093845a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093845b: 85ff TEST
    L_0093845b:
        t32a = state.regs[7];
        t32b = state.regs[7];
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
    // 0x0093845d: 7605 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00938464;
    // 0x0093845f: c6443eff00 MOV
        batch_guest_pc = 0x0093845fu;
        t34 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + state.regs[7] * 1u + 0xffffffffu), t34)) return BatchLiftStatus::invalid_memory;
    // 0x00938464: 5f POP
    L_00938464:
        batch_guest_pc = 0x00938464u;
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t35a;
    // 0x00938465: 5e POP
        batch_guest_pc = 0x00938465u;
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t36a;
    // 0x00938466: 83c410 ADD
        t37a = state.regs[4];
        t37b = 0x00000010u;
        t37r = static_cast<std::uint32_t>(t37a + t37b) & 0xffffffffu;
        batch_set_add_flags(state, t37a, t37b, t37r, 32u);
        state.regs[4] = t37r;
    // 0x00938469: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
