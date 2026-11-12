#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925eb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925eb0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0, t30r = 0;
    std::uint32_t t31a = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t35a = 0, t35r = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38 = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41a = 0;

    // 0x00925eb0: 8b442408 MOV
        batch_guest_pc = 0x00925eb0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925eb4: 53 PUSH
        batch_guest_pc = 0x00925eb4u;
        t1a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925eb5: 8b5914 MOV
        batch_guest_pc = 0x00925eb5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000014u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t2;
    // 0x00925eb8: 3bc3 CMP
        t3a = state.regs[0];
        t3b = state.regs[3];
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x00925eba: 773f JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00925efb;
    // 0x00925ebc: 8b410c MOV
        batch_guest_pc = 0x00925ebcu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00925ebf: 57 PUSH
        batch_guest_pc = 0x00925ebfu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ec0: 8b7918 MOV
        batch_guest_pc = 0x00925ec0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t7;
    // 0x00925ec3: 0faffb IMUL
        t8a = state.regs[7];
        t8b = state.regs[3];
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t8a)) * static_cast<std::int32_t>(t8b);
        state.regs[7] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00925ec6: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00925ec8: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925ee5;
    // 0x00925eca: 56 PUSH
        batch_guest_pc = 0x00925ecau;
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ecb: 8b742410 MOV
        batch_guest_pc = 0x00925ecbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00925ecf: 90 NOP
    // 0x00925ed0: 8d1498 LEA
    L_00925ed0:
        t14 = static_cast<std::uint32_t>(state.regs[0] + state.regs[3] * 4u + 0x00000000u);
        state.regs[2] = t14;
    // 0x00925ed3: 3bf2 CMP
        t15a = state.regs[6];
        t15b = state.regs[2];
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00925ed5: 7207 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925ede;
    // 0x00925ed7: 8d14ba LEA
        t17 = static_cast<std::uint32_t>(state.regs[2] + state.regs[7] * 4u + 0x00000000u);
        state.regs[2] = t17;
    // 0x00925eda: 3bf2 CMP
        t18a = state.regs[6];
        t18b = state.regs[2];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00925edc: 720c JC
        if (((state.eflags & 0x001u) != 0u)) goto L_00925eea;
    // 0x00925ede: 8b00 MOV
    L_00925ede:
        batch_guest_pc = 0x00925edeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x00925ee0: 85c0 TEST
        t21a = state.regs[0];
        t21b = state.regs[0];
        t21r = (t21a & t21b) & 0xffffffffu;
        batch_set_logic_flags(state, t21r, 32u);
    // 0x00925ee2: 75ec JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925ed0;
    // 0x00925ee4: 5e POP
        batch_guest_pc = 0x00925ee4u;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t23a;
    // 0x00925ee5: 5f POP
    L_00925ee5:
        batch_guest_pc = 0x00925ee5u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t24a;
    // 0x00925ee6: 5b POP
        batch_guest_pc = 0x00925ee6u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t25a;
    // 0x00925ee7: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925eea: 8b4108 MOV
    L_00925eea:
        batch_guest_pc = 0x00925eeau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t27;
    // 0x00925eed: 897108 MOV
        batch_guest_pc = 0x00925eedu;
        t28 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
    // 0x00925ef0: 8906 MOV
        batch_guest_pc = 0x00925ef0u;
        t29 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x00925ef2: ff4910 DEC
        batch_guest_pc = 0x00925ef2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t30a)) return BatchLiftStatus::invalid_memory;
        t30r = static_cast<std::uint32_t>(t30a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t30a, t30r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t30r)) return BatchLiftStatus::invalid_memory;
    // 0x00925ef5: 5e POP
        batch_guest_pc = 0x00925ef5u;
        if (!memory.load32(state.regs[4], t31a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t31a;
    // 0x00925ef6: 5f POP
        batch_guest_pc = 0x00925ef6u;
        if (!memory.load32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t32a;
    // 0x00925ef7: 5b POP
        batch_guest_pc = 0x00925ef7u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t33a;
    // 0x00925ef8: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925efb: ff491c DEC
    L_00925efb:
        batch_guest_pc = 0x00925efbu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t35a)) return BatchLiftStatus::invalid_memory;
        t35r = static_cast<std::uint32_t>(t35a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t35a, t35r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t35r)) return BatchLiftStatus::invalid_memory;
    // 0x00925efe: 8b4904 MOV
        batch_guest_pc = 0x00925efeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t36;
    // 0x00925f01: 8b11 MOV
        batch_guest_pc = 0x00925f01u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t37)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t37;
    // 0x00925f03: 8b520c MOV
        batch_guest_pc = 0x00925f03u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t38)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t38;
    // 0x00925f06: 5b POP
        batch_guest_pc = 0x00925f06u;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t39a;
    // 0x00925f07: 89442408 MOV
        batch_guest_pc = 0x00925f07u;
        t40 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00925f0b: ffe2 JMP
        t41a = state.regs[2];
        state.eip = t41a;
        return state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_tail_call(memory, state, t41a);
}
