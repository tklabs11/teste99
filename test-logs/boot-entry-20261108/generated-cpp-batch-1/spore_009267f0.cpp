#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009267f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009267f0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2c = 0, t2r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8c = 0, t8r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14c = 0, t14r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20c = 0, t20r = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t25a = 0, t25c = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t30 = 0;

    // 0x009267f0: 8b442404 MOV
        batch_guest_pc = 0x009267f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009267f4: 8bc8 MOV
        t1 = state.regs[0];
        state.regs[1] = t1;
    // 0x009267f6: c1e906 SHR
        t2a = state.regs[1];
        t2c = 6u;
        if (t2c != 0u) {
        t2r = static_cast<std::uint32_t>(t2a >> t2c);
        batch_set_shr_flags(state, t2a, t2c, t2r, 32u);
            state.regs[1] = t2r;
        }
    // 0x009267f9: 83f920 CMP
        t3a = state.regs[1];
        t3b = 0x00000020u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x009267fc: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00926802;
    // 0x009267fe: 8d4138 LEA
        t5 = static_cast<std::uint32_t>(state.regs[1] + 0x00000038u);
        state.regs[0] = t5;
    // 0x00926801: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926802: 8bc8 MOV
    L_00926802:
        t7 = state.regs[0];
        state.regs[1] = t7;
    // 0x00926804: c1e909 SHR
        t8a = state.regs[1];
        t8c = 9u;
        if (t8c != 0u) {
        t8r = static_cast<std::uint32_t>(t8a >> t8c);
        batch_set_shr_flags(state, t8a, t8c, t8r, 32u);
            state.regs[1] = t8r;
        }
    // 0x00926807: 83f914 CMP
        t9a = state.regs[1];
        t9b = 0x00000014u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x0092680a: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00926810;
    // 0x0092680c: 8d415b LEA
        t11 = static_cast<std::uint32_t>(state.regs[1] + 0x0000005bu);
        state.regs[0] = t11;
    // 0x0092680f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926810: 8bc8 MOV
    L_00926810:
        t13 = state.regs[0];
        state.regs[1] = t13;
    // 0x00926812: c1e90c SHR
        t14a = state.regs[1];
        t14c = 12u;
        if (t14c != 0u) {
        t14r = static_cast<std::uint32_t>(t14a >> t14c);
        batch_set_shr_flags(state, t14a, t14c, t14r, 32u);
            state.regs[1] = t14r;
        }
    // 0x00926815: 83f90a CMP
        t15a = state.regs[1];
        t15b = 0x0000000au;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00926818: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0092681e;
    // 0x0092681a: 8d416e LEA
        t17 = static_cast<std::uint32_t>(state.regs[1] + 0x0000006eu);
        state.regs[0] = t17;
    // 0x0092681d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092681e: 8bc8 MOV
    L_0092681e:
        t19 = state.regs[0];
        state.regs[1] = t19;
    // 0x00926820: c1e90f SHR
        t20a = state.regs[1];
        t20c = 15u;
        if (t20c != 0u) {
        t20r = static_cast<std::uint32_t>(t20a >> t20c);
        batch_set_shr_flags(state, t20a, t20c, t20r, 32u);
            state.regs[1] = t20r;
        }
    // 0x00926823: 83f904 CMP
        t21a = state.regs[1];
        t21b = 0x00000004u;
        t21r = static_cast<std::uint32_t>(t21a - t21b) & 0xffffffffu;
        batch_set_sub_flags(state, t21a, t21b, t21r, 32u);
    // 0x00926826: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0092682c;
    // 0x00926828: 8d4177 LEA
        t23 = static_cast<std::uint32_t>(state.regs[1] + 0x00000077u);
        state.regs[0] = t23;
    // 0x0092682b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092682c: c1e812 SHR
    L_0092682c:
        t25a = state.regs[0];
        t25c = 18u;
        if (t25c != 0u) {
        t25r = static_cast<std::uint32_t>(t25a >> t25c);
        batch_set_shr_flags(state, t25a, t25c, t25r, 32u);
            state.regs[0] = t25r;
        }
    // 0x0092682f: 83f802 CMP
        t26a = state.regs[0];
        t26b = 0x00000002u;
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x00926832: 7704 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00926838;
    // 0x00926834: 83c07c ADD
        t28a = state.regs[0];
        t28b = 0x0000007cu;
        t28r = static_cast<std::uint32_t>(t28a + t28b) & 0xffffffffu;
        batch_set_add_flags(state, t28a, t28b, t28r, 32u);
        state.regs[0] = t28r;
    // 0x00926837: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926838: b87e000000 MOV
    L_00926838:
        t30 = 0x0000007eu;
        state.regs[0] = t30;
    // 0x0092683d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
