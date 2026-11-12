#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921260(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921340(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009213c0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925370(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00925490(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925a30(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925a30u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21a = 0, t21b = 0, t21r = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29a = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;
    std::uint32_t t35 = 0;
    BatchLiftStatus t36_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t40 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t43a = 0, t43b = 0, t43r = 0;
    std::uint32_t t44 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46 = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t49a = 0;
    std::uint32_t t50 = 0;
    BatchLiftStatus t51_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t52a = 0, t52b = 0, t52r = 0;
    std::uint32_t t54a = 0;
    std::uint32_t t55 = 0;
    BatchLiftStatus t56_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t57a = 0;
    std::uint32_t t58 = 0;
    std::uint32_t t59a = 0;
    std::uint32_t t60a = 0, t60b = 0, t60r = 0;

    // 0x00925a30: 83ec18 SUB
        t0a = state.regs[4];
        t0b = 0x00000018u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00925a33: 56 PUSH
        batch_guest_pc = 0x00925a33u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a34: 57 PUSH
        batch_guest_pc = 0x00925a34u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a35: 6a00 PUSH
        batch_guest_pc = 0x00925a35u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a37: 6a04 PUSH
        batch_guest_pc = 0x00925a37u;
        t4a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a39: 8bf1 MOV
        t5 = state.regs[1];
        state.regs[6] = t5;
    // 0x00925a3b: 6a0c PUSH
        batch_guest_pc = 0x00925a3bu;
        t6a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a3d: 68f4020000 PUSH
        batch_guest_pc = 0x00925a3du;
        t7a = 0x000002f4u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a42: 8dbe38010000 LEA
        t8 = static_cast<std::uint32_t>(state.regs[6] + 0x00000138u);
        state.regs[7] = t8;
    // 0x00925a48: 57 PUSH
        batch_guest_pc = 0x00925a48u;
        t9a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a49: 8d4c241c LEA
        t10 = static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu);
        state.regs[1] = t10;
    // 0x00925a4d: c744241c00000000 MOV
        batch_guest_pc = 0x00925a4du;
        t11 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00925a55: e806b8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00921260u, 0x00925a5au)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00921260(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00925a5au) return BatchLiftStatus::invalid_control_flow;
    // 0x00925a5a: 897c2410 MOV
        batch_guest_pc = 0x00925a5au;
        t13 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00925a5e: 8d4634 LEA
        t14 = static_cast<std::uint32_t>(state.regs[6] + 0x00000034u);
        state.regs[0] = t14;
    // 0x00925a61: 81c7f4020000 ADD
        t15a = state.regs[7];
        t15b = 0x000002f4u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[7] = t15r;
    // 0x00925a67: 6a40 PUSH
        batch_guest_pc = 0x00925a67u;
        t16a = 0x00000040u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a69: 897c2418 MOV
        batch_guest_pc = 0x00925a69u;
        t17 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00925a6d: c744241c0c000000 MOV
        batch_guest_pc = 0x00925a6du;
        t18 = 0x0000000cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925a75: 89442420 MOV
        batch_guest_pc = 0x00925a75u;
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00925a79: e8c2b8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00921340u, 0x00925a7eu)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_00921340(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00925a7eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925a7e: 83c404 ADD
        t21a = state.regs[4];
        t21b = 0x00000004u;
        t21r = static_cast<std::uint32_t>(t21a + t21b) & 0xffffffffu;
        batch_set_add_flags(state, t21a, t21b, t21r, 32u);
        state.regs[4] = t21r;
    // 0x00925a81: 8d4c2408 LEA
        t22 = static_cast<std::uint32_t>(state.regs[4] + 0x00000008u);
        state.regs[1] = t22;
    // 0x00925a85: 51 PUSH
        batch_guest_pc = 0x00925a85u;
        t23a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a86: 8b4c242c MOV
        batch_guest_pc = 0x00925a86u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00925a8a: 8d54242c LEA
        t25 = static_cast<std::uint32_t>(state.regs[4] + 0x0000002cu);
        state.regs[2] = t25;
    // 0x00925a8e: 52 PUSH
        batch_guest_pc = 0x00925a8eu;
        t26a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t26a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a8f: 51 PUSH
        batch_guest_pc = 0x00925a8fu;
        t27a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a90: 8d542434 LEA
        t28 = static_cast<std::uint32_t>(state.regs[4] + 0x00000034u);
        state.regs[2] = t28;
    // 0x00925a94: 52 PUSH
        batch_guest_pc = 0x00925a94u;
        t29a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a95: 8b542434 MOV
        batch_guest_pc = 0x00925a95u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000034u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t30;
    // 0x00925a99: 8d4c2438 LEA
        t31 = static_cast<std::uint32_t>(state.regs[4] + 0x00000038u);
        state.regs[1] = t31;
    // 0x00925a9d: 51 PUSH
        batch_guest_pc = 0x00925a9du;
        t32a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t32a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a9e: 52 PUSH
        batch_guest_pc = 0x00925a9eu;
        t33a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
    // 0x00925a9f: 50 PUSH
        batch_guest_pc = 0x00925a9fu;
        t34a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
    // 0x00925aa0: 8bce MOV
        t35 = state.regs[6];
        state.regs[1] = t35;
    // 0x00925aa2: e8e9f9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00925490u, 0x00925aa7u)) return BatchLiftStatus::invalid_memory;
        t36_call_status = spore_lift_00925490(memory, state);
        if (t36_call_status != BatchLiftStatus::returned) return t36_call_status;
        if (state.eip != 0x00925aa7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925aa7: f30f100520063f01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013f0620u)) return BatchLiftStatus::invalid_memory;
    // 0x00925aaf: f30f11442408 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00925ab5: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x00925abd: 8b4c2408 MOV
        batch_guest_pc = 0x00925abdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t40)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t40;
    // 0x00925ac1: f30f1144240c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00925ac7: 8b54240c MOV
        batch_guest_pc = 0x00925ac7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t42;
    // 0x00925acb: 33c0 XOR
        t43a = state.regs[0];
        t43b = state.regs[0];
        t43r = (t43a ^ t43b) & 0xffffffffu;
        batch_set_logic_flags(state, t43r, 32u);
        state.regs[0] = t43r;
    // 0x00925acd: 894e10 MOV
        batch_guest_pc = 0x00925acdu;
        t44 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t44)) return BatchLiftStatus::invalid_memory;
    // 0x00925ad0: 895614 MOV
        batch_guest_pc = 0x00925ad0u;
        t45 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t45)) return BatchLiftStatus::invalid_memory;
    // 0x00925ad3: 89442410 MOV
        batch_guest_pc = 0x00925ad3u;
        t46 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t46)) return BatchLiftStatus::invalid_memory;
    // 0x00925ad7: 894618 MOV
        batch_guest_pc = 0x00925ad7u;
        t47 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x00925ada: 8b460c MOV
        batch_guest_pc = 0x00925adau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00925add: 50 PUSH
        batch_guest_pc = 0x00925addu;
        t49a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t49a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ade: 8d4c240c LEA
        t50 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[1] = t50;
    // 0x00925ae2: e8d9b8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009213c0u, 0x00925ae7u)) return BatchLiftStatus::invalid_memory;
        t51_call_status = spore_lift_009213c0(memory, state);
        if (t51_call_status != BatchLiftStatus::returned) return t51_call_status;
        if (state.eip != 0x00925ae7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925ae7: 3b4608 CMP
        batch_guest_pc = 0x00925ae7u;
        t52a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t52b)) return BatchLiftStatus::invalid_memory;
        t52r = static_cast<std::uint32_t>(t52a - t52b) & 0xffffffffu;
        batch_set_sub_flags(state, t52a, t52b, t52r, 32u);
    // 0x00925aea: 7608 JBE
        if (((state.eflags & 0x001u) != 0u) || ((state.eflags & 0x040u) != 0u)) goto L_00925af4;
    // 0x00925aec: 50 PUSH
        batch_guest_pc = 0x00925aecu;
        t54a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t54a)) return BatchLiftStatus::invalid_memory;
    // 0x00925aed: 8bce MOV
        t55 = state.regs[6];
        state.regs[1] = t55;
    // 0x00925aef: e87cf8ffff CALL
        if (!batch_guest_call32(memory, state, 0x00925370u, 0x00925af4u)) return BatchLiftStatus::invalid_memory;
        t56_call_status = spore_lift_00925370(memory, state);
        if (t56_call_status != BatchLiftStatus::returned) return t56_call_status;
        if (state.eip != 0x00925af4u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925af4: 5f POP
    L_00925af4:
        batch_guest_pc = 0x00925af4u;
        if (!memory.load32(state.regs[4], t57a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t57a;
    // 0x00925af5: 8bc6 MOV
        t58 = state.regs[6];
        state.regs[0] = t58;
    // 0x00925af7: 5e POP
        batch_guest_pc = 0x00925af7u;
        if (!memory.load32(state.regs[4], t59a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t59a;
    // 0x00925af8: 83c418 ADD
        t60a = state.regs[4];
        t60b = 0x00000018u;
        t60r = static_cast<std::uint32_t>(t60a + t60b) & 0xffffffffu;
        batch_set_add_flags(state, t60a, t60b, t60r, 32u);
        state.regs[4] = t60r;
    // 0x00925afb: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
