#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009213c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00a23570(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00a2f210(BatchLiftMemory& memory, BatchLiftState& state) {
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
    BatchLiftStatus t58_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t59a = 0, t59b = 0, t59r = 0;
    std::uint32_t t61a = 0;
    std::uint32_t t62 = 0;
    BatchLiftStatus t63_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t64 = 0;
    std::uint32_t t65a = 0;
    std::uint32_t t66 = 0;
    std::uint32_t t67a = 0;
    std::uint32_t t68 = 0;
    std::uint32_t t69a = 0, t69b = 0, t69r = 0;

    // 0x00a2f210: 6aff PUSH
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f212: 68f88b2101 PUSH
        t1a = 0x01218bf8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f217: 64a100000000 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00a2f21d: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f21e: 64892500000000 MOV
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f225: 83ec28 SUB
        t5a = state.regs[4];
        t5b = 0x00000028u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00a2f228: 56 PUSH
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f229: 57 PUSH
        t7a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f22a: 6a00 PUSH
        t8a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f22c: 6a04 PUSH
        t9a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f22e: 8bf1 MOV
        t10 = state.regs[1];
        state.regs[6] = t10;
    // 0x00a2f230: 6a0c PUSH
        t11a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f232: 6860090000 PUSH
        t12a = 0x00000960u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f237: 8dbe5c030000 LEA
        t13 = static_cast<std::uint32_t>(state.regs[6] + 0x0000035cu);
        state.regs[7] = t13;
    // 0x00a2f23d: 57 PUSH
        t14a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f23e: 8d4c242c LEA
        t15 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[1] = t15;
    // 0x00a2f242: 8974241c MOV
        t16 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f246: c744242c00000000 MOV
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f24e: e80d20efff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00a2f253u)) return BatchLiftStatus::invalid_memory;
        t18_call_status = spore_lift_00921260(memory, state);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
        if (state.eip != 0x00a2f253u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2f253: 897c2420 MOV
        t19 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f257: 8d4634 LEA
        t20 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[0] = t20;
    // 0x00a2f25a: 81c760090000 ADD
        t21a = state.regs[7];
        t21b = 0x00000960u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[7] = t21r;
    // 0x00a2f260: 68c9000000 PUSH
        t22a = 0x000000c9u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f265: 897c2428 MOV
        t23 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000028u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f269: c744242c0c000000 MOV
        t24 = 0x0000000cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t24)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f271: 89442430 MOV
        t25 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f275: e8c620efff CALL
        if (!batch_guest_call32(memory, state, 0x00921340u, 0x00a2f27au)) return BatchLiftStatus::invalid_memory;
        t26_call_status = spore_lift_00921340(memory, state);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00a2f27au) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2f27a: 83c404 ADD
        t27a = state.regs[4];
        t27b = 0x00000004u;
        t27r = static_cast<std::uint32_t>(t27a + t27b) & 0xffffffffu;
        batch_set_add_flags(state, t27a, t27b, t27r, 32u);
        state.regs[4] = t27r;
    // 0x00a2f27d: 8d4c2418 LEA
        t28 = static_cast<std::uint32_t>(state.regs[4] + 0x00000018u);
        state.regs[1] = t28;
    // 0x00a2f281: 51 PUSH
        t29a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f282: 8b4c2448 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000048u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t30;
    // 0x00a2f286: 8d542448 LEA
        t31 = static_cast<std::uint32_t>(state.regs[4] + 0x00000048u);
        state.regs[2] = t31;
    // 0x00a2f28a: 52 PUSH
        t32a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f28b: 51 PUSH
        t33a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f28c: 8d542450 LEA
        t34 = static_cast<std::uint32_t>(state.regs[4] + 0x00000050u);
        state.regs[2] = t34;
    // 0x00a2f290: 52 PUSH
        t35a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t35a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f291: 8b542450 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000050u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00a2f295: 8d4c2454 LEA
        t37 = static_cast<std::uint32_t>(state.regs[4] + 0x00000054u);
        state.regs[1] = t37;
    // 0x00a2f299: 51 PUSH
        t38a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f29a: 52 PUSH
        t39a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f29b: 50 PUSH
        t40a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t40a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f29c: 8bce MOV
        t41 = state.regs[6];
        state.regs[1] = t41;
    // 0x00a2f29e: e8cd42ffff CALL
        if (!batch_guest_call32(memory, state, 0x00a23570u, 0x00a2f2a3u)) return BatchLiftStatus::invalid_memory;
        t42_call_status = spore_lift_00a23570(memory, state);
        if (t42_call_status != BatchLiftStatus::returned) return t42_call_status;
        if (state.eip != 0x00a2f2a3u) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2f2a3: f30f100520063f01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013f0620u)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2ab: f30f1144240c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2b1: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2b9: 8b4c240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t46)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t46;
    // 0x00a2f2bd: f30f11442410 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000010u))) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2c3: 8b542410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t48;
    // 0x00a2f2c7: 33c0 XOR
        t49a = state.regs[0];
        t49b = state.regs[0];
        t49r = (t49a ^ t49b) & 0xffffffffu;
        batch_set_logic_flags(state, t49r, 32u);
        state.regs[0] = t49r;
    // 0x00a2f2c9: 894e10 MOV
        t50 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t50)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2cc: 895614 MOV
        t51 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t51)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2cf: 89442414 MOV
        t52 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t52)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2d3: 894618 MOV
        t53 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t53)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2d6: 8b460c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t54;
    // 0x00a2f2d9: 50 PUSH
        t55a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t55a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2da: 8d4c2410 LEA
        t56 = static_cast<std::uint32_t>(state.regs[4] + 0x00000010u);
        state.regs[1] = t56;
    // 0x00a2f2de: c744243c00000000 MOV
        t57 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000003cu), t57)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2e6: e8d520efff CALL
        if (!batch_guest_call32(memory, state, 0x009213c0u, 0x00a2f2ebu)) return BatchLiftStatus::invalid_memory;
        t58_call_status = spore_lift_009213c0(memory, state);
        if (t58_call_status != BatchLiftStatus::returned) return t58_call_status;
        if (state.eip != 0x00a2f2ebu) return BatchLiftStatus::invalid_control_flow;
    // 0x00a2f2eb: 3b4608 CMP
        t59a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t59b)) return BatchLiftStatus::invalid_memory;
        t59r = static_cast<std::uint32_t>(t59a - t59b) & 0xffffffffu;
        batch_set_sub_flags(state, t59a, t59b, t59r, 32u);
    // 0x00a2f2ee: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00a2f2f8;
    // 0x00a2f2f0: 50 PUSH
        t61a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t61a)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f2f1: 8bce MOV
        t62 = state.regs[6];
        state.regs[1] = t62;
    // 0x00a2f2f3: e8282fffff CALL
        state.eip = 0x00a2f2f3u;
        return BatchLiftStatus::unsupported_dependency;
    // 0x00a2f2f8: 8b4c2430 MOV
    L_00a2f2f8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t64)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t64;
    // 0x00a2f2fc: 5f POP
        if (!memory.load32(state.regs[4], t65a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t65a;
    // 0x00a2f2fd: 8bc6 MOV
        t66 = state.regs[6];
        state.regs[0] = t66;
    // 0x00a2f2ff: 5e POP
        if (!memory.load32(state.regs[4], t67a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t67a;
    // 0x00a2f300: 64890d00000000 MOV
        t68 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t68)) return BatchLiftStatus::invalid_memory;
    // 0x00a2f307: 83c434 ADD
        t69a = state.regs[4];
        t69b = 0x00000034u;
        t69r = static_cast<std::uint32_t>(t69a + t69b) & 0xffffffffu;
        batch_set_add_flags(state, t69a, t69b, t69r, 32u);
        state.regs[4] = t69r;
    // 0x00a2f30a: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
