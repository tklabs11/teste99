#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a30e10(BatchLiftMemory& memory, BatchLiftState& state) {
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

    // 0x00a30e10: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e12: 68688e2101 PUSH
        t1a = 0x01218e68u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e17: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a30e1d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e1e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e25: 83ec28 SUB
        t5a = state.regs[4];
        t5b = 0x00000028u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00a30e28: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e29: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e2a: 6a00 PUSH
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e2c: 6a04 PUSH
        t9a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e2e: 8bf1 MOV
        t10 = state.regs[1];
        state.regs[6] = t10;
    // 0x00a30e30: 6a14 PUSH
        t11a = 0x00000014u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e32: 68c0270900 PUSH
        t12a = 0x000927c0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e37: 8dbe1c2f0000 LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x00002f1cu);
        state.regs[7] = t13;
    // 0x00a30e3d: 57 PUSH
        t14a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e3e: 8d4c242c LEA
        t15 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[1] = t15;
    // 0x00a30e42: 8974241c MOV
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e46: c744242c00000000 MOV
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e4e: e80d04efff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00a30e53u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00921260(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00a30e53u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a30e53: 897c2420 MOV
        t19 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e57: 8d4634 LEA
        t20 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[0] = t20;
    // 0x00a30e5a: 81c7c0270900 ADD
        t21a = state.regs[7];
        t21b = 0x000927c0u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[7] = t21r;
    // 0x00a30e60: 68b90b0000 PUSH
        t22a = 0x00000bb9u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e65: 897c2428 MOV
        t23 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e69: c744242c14000000 MOV
        t24 = 0x00000014u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e71: 89442430 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e75: e8c604efff CALL
        if (!batch_guest_call32(memory, state, 0x00921340u, 0x00a30e7au)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00921340(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00a30e7au) return BatchLiftStatus::invalid_control_flow;
    // 0x00a30e7a: 83c404 ADD
        t27a = state.regs[4];
        t27b = 0x00000004u;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[4] = t27r;
    // 0x00a30e7d: 8d4c2418 LEA
        t28 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[1] = t28;
    // 0x00a30e81: 51 PUSH
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e82: 8b4c2448 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00a30e86: 8d542448 LEA
        t31 = static_cast<std::uint32_t>(state.regs[4] + 0x00000048u);
        state.regs[2] = t31;
    // 0x00a30e8a: 52 PUSH
        t32a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e8b: 51 PUSH
        t33a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e8c: 8d542450 LEA
        t34 = static_cast<std::uint32_t>(state.regs[4] + 0x00000050u);
        state.regs[2] = t34;
    // 0x00a30e90: 52 PUSH
        t35a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e91: 8b542450 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00a30e95: 8d4c2454 LEA
        t37 = static_cast<std::uint32_t>(state.regs[4] + 0x00000054u);
        state.regs[1] = t37;
    // 0x00a30e99: 51 PUSH
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e9a: 52 PUSH
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e9b: 50 PUSH
        t40a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30e9c: 8bce MOV
        t41 = state.regs[6];
        state.regs[1] = t41;
    state.eip = 0x00a30e9eu;
    return BatchLiftStatus::unsupported_dependency;
}
