#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923d40(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009259d0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697e00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697e00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30a = 0;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;

    // 0x00697e00: 6aff PUSH
        batch_guest_pc = 0x00697e00u;
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00697e02: 686cd32001 PUSH
        batch_guest_pc = 0x00697e02u;
        t1a = 0x0120d36cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00697e07: 64a100000000 MOV
        batch_guest_pc = 0x00697e07u;
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00697e0d: 50 PUSH
        batch_guest_pc = 0x00697e0du;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00697e0e: 64892500000000 MOV
        batch_guest_pc = 0x00697e0eu;
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00697e15: 51 PUSH
        batch_guest_pc = 0x00697e15u;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00697e16: 56 PUSH
        batch_guest_pc = 0x00697e16u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00697e17: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x00697e19: 89742404 MOV
        batch_guest_pc = 0x00697e19u;
        t8 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00697e1d: e81ebf2800 CALL
        if (!batch_guest_call32(memory, state, 0x00923d40u, 0x00697e22u)) return BatchLiftStatus::invalid_memory;
        t9_call_status = spore_lift_00923d40(memory, state);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x00697e22u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697e22: c70610834001 MOV
        batch_guest_pc = 0x00697e22u;
        t10 = 0x01408310u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00697e28: c74604f4824001 MOV
        batch_guest_pc = 0x00697e28u;
        t11 = 0x014082f4u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00697e2f: b8ac7b6601 MOV
        t12 = 0x01667bacu;
        state.regs[0] = t12;
    // 0x00697e34: b9ae7b6601 MOV
        t13 = 0x01667baeu;
        state.regs[1] = t13;
    // 0x00697e39: c744241000000000 MOV
        batch_guest_pc = 0x00697e39u;
        t14 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00697e41: 894668 MOV
        batch_guest_pc = 0x00697e41u;
        t15 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000068u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00697e44: 89466c MOV
        batch_guest_pc = 0x00697e44u;
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000006cu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00697e47: 894e70 MOV
        batch_guest_pc = 0x00697e47u;
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000070u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00697e4a: 894678 MOV
        batch_guest_pc = 0x00697e4au;
        t18 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000078u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00697e4d: 89467c MOV
        batch_guest_pc = 0x00697e4du;
        t19 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000007cu), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00697e50: 898e80000000 MOV
        batch_guest_pc = 0x00697e50u;
        t20 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000080u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00697e56: 898688000000 MOV
        batch_guest_pc = 0x00697e56u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000088u), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00697e5c: 89868c000000 MOV
        batch_guest_pc = 0x00697e5cu;
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000008cu), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00697e62: 898e90000000 MOV
        batch_guest_pc = 0x00697e62u;
        t23 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000090u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00697e68: 8d8ea0000000 LEA
        t24 = static_cast<std::uint32_t>(state.regs[6] + 0x000000a0u);
        state.regs[1] = t24;
    // 0x00697e6e: c644241003 MOV
        batch_guest_pc = 0x00697e6eu;
        t25 = 0x00000003u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t25)) return BatchLiftStatus::invalid_memory;
    // 0x00697e73: c6869800000001 MOV
        batch_guest_pc = 0x00697e73u;
        t26 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000098u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00697e7a: e851db2800 CALL
        if (!batch_guest_call32(memory, state, 0x009259d0u, 0x00697e7fu)) return BatchLiftStatus::invalid_memory;
        t27_call_status = spore_lift_009259d0(memory, state);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
        if (state.eip != 0x00697e7fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697e7f: 8b4c2408 MOV
        batch_guest_pc = 0x00697e7fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t28;
    // 0x00697e83: 8bc6 MOV
        t29 = state.regs[6];
        state.regs[0] = t29;
    // 0x00697e85: 5e POP
        batch_guest_pc = 0x00697e85u;
        if (!memory.load32(state.regs[4], t30a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t30a;
    // 0x00697e86: 64890d00000000 MOV
        batch_guest_pc = 0x00697e86u;
        t31 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t31)) return BatchLiftStatus::invalid_memory;
    // 0x00697e8d: 83c410 ADD
        t32a = state.regs[4];
        t32b = 0x00000010u;
        t32r = static_cast<std::uint32_t>(t32a + t32b) & 0xffffffffu;
        batch_set_add_flags(state, t32a, t32b, t32r, 32u);
        state.regs[4] = t32r;
    // 0x00697e90: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
