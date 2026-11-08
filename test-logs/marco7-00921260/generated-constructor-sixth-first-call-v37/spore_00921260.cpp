#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0, t23r = 0;
    std::uint32_t t24a = 0, t24b = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36a = 0;

    // 0x00921260: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00921264: 83f801 CMP
        t1a = state.regs[0];
        t1b = 0x00000001u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00921267: 7305 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_0092126e;
    // 0x00921269: b801000000 MOV
        t3 = 0x00000001u;
        state.regs[0] = t3;
    // 0x0092126e: 53 PUSH
    L_0092126e:
        t4a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092126f: 56 PUSH
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00921270: 57 PUSH
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00921271: 8b7c2418 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t7;
    // 0x00921275: 83ff04 CMP
        t8a = state.regs[7];
        t8b = 0x00000004u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x00921278: 730a JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00921284;
    // 0x0092127a: 8d78ff LEA
        t10 = static_cast<std::uint32_t>(state.regs[0] + 0xffffffffu);
        state.regs[7] = t10;
    // 0x0092127d: f7d7 NOT
        t11a = state.regs[7];
        state.regs[7] = (~t11a & 0xffffffffu);
    // 0x0092127f: 8d5003 LEA
        t12 = static_cast<std::uint32_t>(state.regs[0] + 0x00000003u);
        state.regs[2] = t12;
    // 0x00921282: 23fa AND
        t13a = state.regs[7];
        t13b = state.regs[2];
        t13r = (t13a & t13b) & 0xffffffffu;
        batch_set_logic_flags(state, t13r, 32u);
        state.regs[7] = t13r;
    // 0x00921284: 8b5c2410 MOV
    L_00921284:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t14;
    // 0x00921288: 8d7403ff LEA
        t15 = static_cast<std::uint32_t>(state.regs[3] + state.regs[0] * 1u + 0xffffffffu);
        state.regs[6] = t15;
    // 0x0092128c: 48 DEC
        t16a = state.regs[0];
        t16r = static_cast<std::uint32_t>(t16a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t16a, t16r, 32u);
        state.regs[0] = t16r;
    // 0x0092128d: f7d0 NOT
        t17a = state.regs[0];
        state.regs[0] = (~t17a & 0xffffffffu);
    // 0x0092128f: 23f0 AND
        t18a = state.regs[6];
        t18b = state.regs[0];
        t18r = (t18a & t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[6] = t18r;
    // 0x00921291: 8b442414 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t19)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t19;
    // 0x00921295: 33d2 XOR
        t20a = state.regs[2];
        t20b = state.regs[2];
        t20r = (t20a ^ t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[2] = t20r;
    // 0x00921297: f7f7 DIV
        t21a = state.regs[7];
        if (t21a == 0u) return BatchLiftStatus::divide_error;
        {
        const std::uint64_t dividend = (static_cast<std::uint64_t>(state.regs[2]) << 32u) | state.regs[0];
        const std::uint64_t quotient = dividend / t21a;
        if (quotient > 0xffffffffull) return BatchLiftStatus::divide_error;
        state.regs[0] = static_cast<std::uint32_t>(quotient);
        state.regs[2] = static_cast<std::uint32_t>(dividend % t21a);
        }
    // 0x00921299: 8931 MOV
        t22 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x0092129b: 48 DEC
        t23a = state.regs[0];
        t23r = static_cast<std::uint32_t>(t23a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t23a, t23r, 32u);
        state.regs[0] = t23r;
    // 0x0092129c: 0fafc7 IMUL
        t24a = state.regs[0];
        t24b = state.regs[7];
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t24a)) * static_cast<std::int32_t>(t24b);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x0092129f: 03c3 ADD
        t25a = state.regs[0];
        t25b = state.regs[3];
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[0] = t25r;
    // 0x009212a1: 3bf0 CMP
        t26a = state.regs[6];
        t26b = state.regs[0];
        t26r = static_cast<std::uint32_t>(t26a - t26b) & 0xffffffffu;
        batch_set_sub_flags(state, t26a, t26b, t26r, 32u);
    // 0x009212a3: 730b JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_009212b0;
    // 0x009212a5: 8d0c3e LEA
    L_009212a5:
        t28 = static_cast<std::uint32_t>(state.regs[6] + state.regs[7] * 1u + 0x00000000u);
        state.regs[1] = t28;
    // 0x009212a8: 890e MOV
        t29 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t29)) return BatchLiftStatus::invalid_memory;
    // 0x009212aa: 8bf1 MOV
        t30 = state.regs[1];
        state.regs[6] = t30;
    // 0x009212ac: 3bf0 CMP
        t31a = state.regs[6];
        t31b = state.regs[0];
        t31r = static_cast<std::uint32_t>(t31a - t31b) & 0xffffffffu;
        batch_set_sub_flags(state, t31a, t31b, t31r, 32u);
    // 0x009212ae: 72f5 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_009212a5;
    // 0x009212b0: 5f POP
    L_009212b0:
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x009212b1: c70600000000 MOV
        t34 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x009212b7: 5e POP
        if (!memory.load32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t35a;
    // 0x009212b8: 5b POP
        if (!memory.load32(state.regs[4], t36a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t36a;
    // 0x009212b9: c21400 RET
        if (!batch_guest_return32(memory, state, 20u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
