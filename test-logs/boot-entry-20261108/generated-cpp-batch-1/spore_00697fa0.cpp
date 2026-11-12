#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00697e00(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697fa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697fa0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;
    BatchLiftStatus t21_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25 = 0;
    std::uint32_t t26 = 0;
    BatchLiftStatus t27_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    std::uint32_t t30 = 0;
    BatchLiftStatus t31_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t32 = 0;
    std::uint32_t t33a = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35a = 0, t35b = 0, t35r = 0;

    // 0x00697fa0: 6aff PUSH
        batch_guest_pc = 0x00697fa0u;
        t0a = 0xffffffffu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fa2: 689ad32001 PUSH
        batch_guest_pc = 0x00697fa2u;
        t1a = 0x0120d39au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fa7: 64a100000000 MOV
        batch_guest_pc = 0x00697fa7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00697fad: 50 PUSH
        batch_guest_pc = 0x00697fadu;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fae: 64892500000000 MOV
        batch_guest_pc = 0x00697faeu;
        t4 = state.regs[4];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00697fb5: 51 PUSH
        batch_guest_pc = 0x00697fb5u;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fb6: 56 PUSH
        batch_guest_pc = 0x00697fb6u;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fb7: 33f6 XOR
        t7a = state.regs[6];
        t7b = state.regs[6];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[6] = t7r;
    // 0x00697fb9: 56 PUSH
        batch_guest_pc = 0x00697fb9u;
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fba: 56 PUSH
        batch_guest_pc = 0x00697fbau;
        t9a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fbb: 56 PUSH
        batch_guest_pc = 0x00697fbbu;
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fbc: 56 PUSH
        batch_guest_pc = 0x00697fbcu;
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fbd: 684c834001 PUSH
        batch_guest_pc = 0x00697fbdu;
        t12a = 0x0140834cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fc2: 68f8000000 PUSH
        batch_guest_pc = 0x00697fc2u;
        t13a = 0x000000f8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00697fc7: e8d4f38a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x00697fccu)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00f473a0(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00697fccu) return BatchLiftStatus::invalid_control_flow;
    // 0x00697fcc: 83c418 ADD
        t15a = state.regs[4];
        t15b = 0x00000018u;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[4] = t15r;
    // 0x00697fcf: 89442404 MOV
        batch_guest_pc = 0x00697fcfu;
        t16 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00697fd3: 89742410 MOV
        batch_guest_pc = 0x00697fd3u;
        t17 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00697fd7: 3bc6 CMP
        t18a = state.regs[0];
        t18b = state.regs[6];
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
    // 0x00697fd9: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00697fe4;
    // 0x00697fdb: 8bc8 MOV
        t20 = state.regs[0];
        state.regs[1] = t20;
    // 0x00697fdd: e81efeffff CALL
        if (!batch_guest_call32(memory, state, 0x00697e00u, 0x00697fe2u)) return BatchLiftStatus::invalid_memory;
        t21_call_status = spore_lift_00697e00(memory, state);
        if (t21_call_status != BatchLiftStatus::returned) return t21_call_status;
        if (state.eip != 0x00697fe2u) return BatchLiftStatus::invalid_control_flow;
    // 0x00697fe2: 8bf0 MOV
        t22 = state.regs[0];
        state.regs[6] = t22;
    // 0x00697fe4: 8b06 MOV
    L_00697fe4:
        batch_guest_pc = 0x00697fe4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00697fe6: 8b5014 MOV
        batch_guest_pc = 0x00697fe6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t24;
    // 0x00697fe9: 8bce MOV
        t25 = state.regs[6];
        state.regs[1] = t25;
    // 0x00697feb: c7442410ffffffff MOV
        batch_guest_pc = 0x00697febu;
        t26 = 0xffffffffu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x00697ff3: ffd2 CALL
        t27_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697ff5u);
        if (t27_call_status != BatchLiftStatus::returned) return t27_call_status;
    // 0x00697ff5: 8b06 MOV
        batch_guest_pc = 0x00697ff5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00697ff7: 8b5010 MOV
        batch_guest_pc = 0x00697ff7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x00697ffa: 8bce MOV
        t30 = state.regs[6];
        state.regs[1] = t30;
    // 0x00697ffc: ffd2 CALL
        t31_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00697ffeu);
        if (t31_call_status != BatchLiftStatus::returned) return t31_call_status;
    // 0x00697ffe: 8b4c2408 MOV
        batch_guest_pc = 0x00697ffeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t32)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t32;
    // 0x00698002: 5e POP
        batch_guest_pc = 0x00698002u;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t33a;
    // 0x00698003: 64890d00000000 MOV
        batch_guest_pc = 0x00698003u;
        t34 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.fs_base + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
    // 0x0069800a: 83c410 ADD
        t35a = state.regs[4];
        t35b = 0x00000010u;
        t35r = static_cast<std::uint32_t>(t35a + t35b) & 0xffffffffu;
        batch_set_add_flags(state, t35a, t35b, t35r, 32u);
        state.regs[4] = t35r;
    // 0x0069800d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
