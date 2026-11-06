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

#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a23570(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a2a210(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27a = 0, t27b = 0, t27r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;
    std::uint32_t t39a = 0;
    std::uint32_t t40a = 0;
    std::uint32_t t41 = 0;
    BatchLiftStatus t42_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t46 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0, t49b = 0, t49r = 0;
    std::uint32_t t50 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t52 = 0;
    std::uint32_t t53 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t55a = 0;
    std::uint32_t t56 = 0;
    std::uint32_t t57 = 0;

    // 0x00a2a210: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a212: 6858822101 PUSH
        t1a = 0x01218258u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a217: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a2a21d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a21e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a225: 83ec28 SUB
        t5a = state.regs[4];
        t5b = 0x00000028u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00a2a228: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a229: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22a: 6a00 PUSH
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22c: 6a04 PUSH
        t9a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a22e: 8bf1 MOV
        t10 = state.regs[1];
        state.regs[6] = t10;
    // 0x00a2a230: 6a0c PUSH
        t11a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a232: 6860090000 PUSH
        t12a = 0x00000960u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a237: 8dbe5c030000 LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x0000035cu);
        state.regs[7] = t13;
    // 0x00a2a23d: 57 PUSH
        t14a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a23e: 8d4c242c LEA
        t15 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[1] = t15;
    // 0x00a2a242: 8974241c MOV
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a246: c744242c00000000 MOV
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a24e: e80d70efff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00a2a253u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00921260(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00a2a253u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2a253: 897c2420 MOV
        t19 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a257: 8d4634 LEA
        t20 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[0] = t20;
    // 0x00a2a25a: 81c760090000 ADD
        t21a = state.regs[7];
        t21b = 0x00000960u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[7] = t21r;
    // 0x00a2a260: 68c9000000 PUSH
        t22a = 0x000000c9u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a265: 897c2428 MOV
        t23 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a269: c744242c0c000000 MOV
        t24 = 0x0000000cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a271: 89442430 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a275: e8c670efff CALL
        if (!batch_guest_call32(memory, state, 0x00921340u, 0x00a2a27au)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00921340(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00a2a27au) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2a27a: 83c404 ADD
        t27a = state.regs[4];
        t27b = 0x00000004u;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[4] = t27r;
    // 0x00a2a27d: 8d4c2418 LEA
        t28 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[1] = t28;
    // 0x00a2a281: 51 PUSH
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a282: 8b4c2448 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00a2a286: 8d542448 LEA
        t31 = static_cast<std::uint32_t>(state.regs[4] + 0x00000048u);
        state.regs[2] = t31;
    // 0x00a2a28a: 52 PUSH
        t32a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a28b: 51 PUSH
        t33a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a28c: 8d542450 LEA
        t34 = static_cast<std::uint32_t>(state.regs[4] + 0x00000050u);
        state.regs[2] = t34;
    // 0x00a2a290: 52 PUSH
        t35a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a291: 8b542450 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00a2a295: 8d4c2454 LEA
        t37 = static_cast<std::uint32_t>(state.regs[4] + 0x00000054u);
        state.regs[1] = t37;
    // 0x00a2a299: 51 PUSH
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a29a: 52 PUSH
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a29b: 50 PUSH
        t40a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a29c: 8bce MOV
        t41 = state.regs[6];
        state.regs[1] = t41;
    // 0x00a2a29e: e8cd92ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a23570u, 0x00a2a2a3u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00a23570(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00a2a2a3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2a2a3: f30f100520063f01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013f0620u)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2ab: f30f1144240c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2b1: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2b9: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00a2a2bd: f30f11442410 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000010u))) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2c3: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00a2a2c7: 33c0 XOR
        t49a = state.regs[0];
        t49b = state.regs[0];
        t49r = (t49a ^ t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
        state.regs[0] = t49r;
    // 0x00a2a2c9: 894e10 MOV
        t50 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2cc: 895614 MOV
        t51 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2cf: 89442414 MOV
        t52 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2d3: 894618 MOV
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2d6: 8b460c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00a2a2d9: 50 PUSH
        t55a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2a2da: 8d4c2410 LEA
        t56 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t56;
    // 0x00a2a2de: c744243c00000000 MOV
        t57 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t57)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x00a2a2e6u;
    return BatchLiftStatus::unsupported_dependency;
}
