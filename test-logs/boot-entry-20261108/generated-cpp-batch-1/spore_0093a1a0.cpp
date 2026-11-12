#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0093a1a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093a1a0u);
    std::uint32_t t0 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t28a = 0, t28b = 0, t28r = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t36a = 0, t36b = 0, t36r = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t40a = 0, t40b = 0, t40r = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t44a = 0;
    std::uint32_t t45a = 0;
    std::uint32_t t50a = 0, t50b = 0, t50r = 0;
    std::uint32_t t54a = 0, t54b = 0, t54r = 0;
    std::uint32_t t58a = 0, t58b = 0, t58r = 0;
    std::uint32_t t62a = 0, t62b = 0, t62r = 0;
    std::uint32_t t66a = 0, t66b = 0, t66r = 0;
    std::uint32_t t70a = 0, t70b = 0, t70r = 0;

    // 0x0093a1a0: 8b442404 MOV
        batch_guest_pc = 0x0093a1a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0093a1a4: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a1ac: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0093a1af: 894110 MOV
        batch_guest_pc = 0x0093a1afu;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0093a1b2: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a1b7: 83f806 CMP
        t5a = state.regs[0];
        t5b = 0x00000006u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x0093a1ba: 772f JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_0093a1eb;
    // 0x0093a1bc: ff2485bca29300 JMP
        batch_guest_pc = 0x0093a1bcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] * 4u + 0x0093a2bcu), t7a)) return BatchLiftStatus::invalid_memory;
        switch (t7a) {
        case 0x0093a1c3u: goto L_0093a1c3;
        case 0x0093a25au: goto L_0093a25a;
        case 0x0093a262u: goto L_0093a262;
        case 0x0093a26du: goto L_0093a26d;
        case 0x0093a280u: goto L_0093a280;
        case 0x0093a293u: goto L_0093a293;
        case 0x0093a2a6u: goto L_0093a2a6;
        default:
        state.eip = t7a;
        return BatchLiftStatus::unsupported_dependency;
        }
    // 0x0093a1c3: 8b15e8ea5401 MOV
    L_0093a1c3:
        batch_guest_pc = 0x0093a1c3u;
        if (!memory.load32(0x0154eae8u, t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x0093a1c9: a1ecea5401 MOV
        batch_guest_pc = 0x0093a1c9u;
        if (!memory.load32(0x0154eaecu, t9)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t9;
    // 0x0093a1ce: 56 PUSH
        batch_guest_pc = 0x0093a1ceu;
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a1cf: 8b35f0ea5401 MOV
        batch_guest_pc = 0x0093a1cfu;
        if (!memory.load32(0x0154eaf0u, t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x0093a1d5: 57 PUSH
        batch_guest_pc = 0x0093a1d5u;
        t12a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x0093a1d6: 8b3df4ea5401 MOV
        batch_guest_pc = 0x0093a1d6u;
        if (!memory.load32(0x0154eaf4u, t13)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t13;
    // 0x0093a1dc: 3bd6 CMP
        t14a = state.regs[2];
        t14b = state.regs[6];
        t14r = static_cast<std::uint32_t>(t14a - t14b) & 0xffffffffu;
        batch_set_sub_flags(state, t14a, t14b, t14r, 32u);
    // 0x0093a1de: 7511 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a1f1;
    // 0x0093a1e0: 3bc7 CMP
        t16a = state.regs[0];
        t16b = state.regs[7];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x0093a1e2: 750d JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0093a1f1;
    // 0x0093a1e4: 5f POP
        batch_guest_pc = 0x0093a1e4u;
        if (!memory.load32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t18a;
    // 0x0093a1e5: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a1ea: 5e POP
        batch_guest_pc = 0x0093a1eau;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x0093a1eb: 83c408 ADD
    L_0093a1eb:
        t21a = state.regs[4];
        t21b = 0x00000008u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x0093a1ee: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a1f1: 89542408 MOV
    L_0093a1f1:
        batch_guest_pc = 0x0093a1f1u;
        t23 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x0093a1f5: 8bd0 MOV
        t24 = state.regs[0];
        state.regs[2] = t24;
    // 0x0093a1f7: 25ffffff7f AND
        t25a = state.regs[0];
        t25b = 0x7fffffffu;
        t25r = (t25a & t25b) & 0xffffffffu;
        batch_set_logic_flags(state, t25r, 32u);
        state.regs[0] = t25r;
    // 0x0093a1fc: 8944240c MOV
        batch_guest_pc = 0x0093a1fcu;
        t26 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t26)) return BatchLiftStatus::invalid_memory;
    // 0x0093a200: df6c2408 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a204: 81e200000080 AND
        t28a = state.regs[2];
        t28b = 0x80000000u;
        t28r = (t28a & t28b) & 0xffffffffu;
        batch_set_logic_flags(state, t28r, 32u);
        state.regs[2] = t28r;
    // 0x0093a20a: 8954240c MOV
        batch_guest_pc = 0x0093a20au;
        t29 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t29)) return BatchLiftStatus::invalid_memory;
    // 0x0093a20e: c744240800000000 MOV
        batch_guest_pc = 0x0093a20eu;
        t30 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
    // 0x0093a216: df6c2408 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a21a: 8bc7 MOV
        t32 = state.regs[7];
        state.regs[0] = t32;
    // 0x0093a21c: 8bd7 MOV
        t33 = state.regs[7];
        state.regs[2] = t33;
    // 0x0093a21e: 89742408 MOV
        batch_guest_pc = 0x0093a21eu;
        t34 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0093a222: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a224: 25ffffff7f AND
        t36a = state.regs[0];
        t36b = 0x7fffffffu;
        t36r = (t36a & t36b) & 0xffffffffu;
        batch_set_logic_flags(state, t36r, 32u);
        state.regs[0] = t36r;
    // 0x0093a229: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a22b: 8944240c MOV
        batch_guest_pc = 0x0093a22bu;
        t38 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t38)) return BatchLiftStatus::invalid_memory;
    // 0x0093a22f: df6c2408 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a233: 81e200000080 AND
        t40a = state.regs[2];
        t40b = 0x80000000u;
        t40r = (t40a & t40b) & 0xffffffffu;
        batch_set_logic_flags(state, t40r, 32u);
        state.regs[2] = t40r;
    // 0x0093a239: 8954240c MOV
        batch_guest_pc = 0x0093a239u;
        t41 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t41)) return BatchLiftStatus::invalid_memory;
    // 0x0093a23d: c744240800000000 MOV
        batch_guest_pc = 0x0093a23du;
        t42 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t42)) return BatchLiftStatus::invalid_memory;
    // 0x0093a245: df6c2408 FILD
        if (!batch_guest_fild64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a249: 5f POP
        batch_guest_pc = 0x0093a249u;
        if (!memory.load32(state.regs[4], t44a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t44a;
    // 0x0093a24a: 5e POP
        batch_guest_pc = 0x0093a24au;
        if (!memory.load32(state.regs[4], t45a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t45a;
    // 0x0093a24b: d9e0 FCHS
        if (!batch_guest_x87_chs(state)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a24d: dec1 FADDP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 0u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a24f: def9 FDIVP
        if (!batch_guest_x87_arithmetic_stack(state, 1u, 0u, 2u, true)) return BatchLiftStatus::invalid_x87_state;
    // 0x0093a251: d95914 FSTP
        if (!batch_guest_fstp32(memory, state, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a254: 83c408 ADD
        t50a = state.regs[4];
        t50b = 0x00000008u;
        t50r = static_cast<std::uint32_t>(t50a + t50b) & 0xffffffffu;
        batch_set_add_flags(state, t50a, t50b, t50r, 32u);
        state.regs[4] = t50r;
    // 0x0093a257: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a25a: f30f100558996601 MOVSS
    L_0093a25a:
        if (!batch_guest_movss_load(memory, state, 0u, 0x01669958u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a262: f30f114114 MOVSS
    L_0093a262:
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a267: 83c408 ADD
        t54a = state.regs[4];
        t54b = 0x00000008u;
        t54r = static_cast<std::uint32_t>(t54a + t54b) & 0xffffffffu;
        batch_set_add_flags(state, t54a, t54b, t54r, 32u);
        state.regs[4] = t54r;
    // 0x0093a26a: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a26d: f30f100574996601 MOVSS
    L_0093a26d:
        if (!batch_guest_movss_load(memory, state, 0u, 0x01669974u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a275: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a27a: 83c408 ADD
        t58a = state.regs[4];
        t58b = 0x00000008u;
        t58r = static_cast<std::uint32_t>(t58a + t58b) & 0xffffffffu;
        batch_set_add_flags(state, t58a, t58b, t58r, 32u);
        state.regs[4] = t58r;
    // 0x0093a27d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a280: f30f10056c996601 MOVSS
    L_0093a280:
        if (!batch_guest_movss_load(memory, state, 0u, 0x0166996cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a288: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a28d: 83c408 ADD
        t62a = state.regs[4];
        t62b = 0x00000008u;
        t62r = static_cast<std::uint32_t>(t62a + t62b) & 0xffffffffu;
        batch_set_add_flags(state, t62a, t62b, t62r, 32u);
        state.regs[4] = t62r;
    // 0x0093a290: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a293: f30f100580996601 MOVSS
    L_0093a293:
        if (!batch_guest_movss_load(memory, state, 0u, 0x01669980u)) return BatchLiftStatus::invalid_memory;
    // 0x0093a29b: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a2a0: 83c408 ADD
        t66a = state.regs[4];
        t66b = 0x00000008u;
        t66r = static_cast<std::uint32_t>(t66a + t66b) & 0xffffffffu;
        batch_set_add_flags(state, t66a, t66b, t66r, 32u);
        state.regs[4] = t66r;
    // 0x0093a2a3: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0093a2a6: f30f10055c996601 MOVSS
    L_0093a2a6:
        if (!batch_guest_movss_load(memory, state, 0u, 0x0166995cu)) return BatchLiftStatus::invalid_memory;
    // 0x0093a2ae: f30f114114 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000014u))) return BatchLiftStatus::invalid_memory;
    // 0x0093a2b3: 83c408 ADD
        t70a = state.regs[4];
        t70b = 0x00000008u;
        t70r = static_cast<std::uint32_t>(t70a + t70b) & 0xffffffffu;
        batch_set_add_flags(state, t70a, t70b, t70r, 32u);
        state.regs[4] = t70r;
    // 0x0093a2b6: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
