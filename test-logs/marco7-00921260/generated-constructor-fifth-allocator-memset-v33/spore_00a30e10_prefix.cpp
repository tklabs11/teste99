#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a236d0(BatchLiftMemory& memory, BatchLiftState& state);


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
    // 0x00a30e9e: e82d28ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a236d0u, 0x00a30ea3u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00a236d0(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00a30ea3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a30ea3: f30f100520063f01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013f0620u)) return BatchLiftStatus::invalid_memory;
    // 0x00a30eab: f30f1144240c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a30eb1: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00a30eb9: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00a30ebd: f30f11442410 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000010u))) return BatchLiftStatus::invalid_memory;
    // 0x00a30ec3: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00a30ec7: 33c0 XOR
        t49a = state.regs[0];
        t49b = state.regs[0];
        t49r = (t49a ^ t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
        state.regs[0] = t49r;
    // 0x00a30ec9: 894e10 MOV
        t50 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00a30ecc: 895614 MOV
        t51 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00a30ecf: 89442414 MOV
        t52 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00a30ed3: 894618 MOV
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00a30ed6: 8b460c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00a30ed9: 50 PUSH
        t55a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00a30eda: 8d4c2410 LEA
        t56 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t56;
    // 0x00a30ede: c744243c00000000 MOV
        t57 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t57)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x00a30ee6u;
    return BatchLiftStatus::unsupported_dependency;
}
