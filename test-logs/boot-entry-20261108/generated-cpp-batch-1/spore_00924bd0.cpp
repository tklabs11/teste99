#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922130(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00ae6970(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00e25bd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924bd0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924bd0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    BatchLiftStatus t22_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25 = 0;
    std::uint32_t t26a = 0, t26b = 0, t26r = 0;
    std::uint32_t t28 = 0;
    std::uint32_t t29 = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    std::uint32_t t32a = 0, t32b = 0, t32r = 0;
    std::uint32_t t34 = 0;
    std::uint32_t t35 = 0;
    BatchLiftStatus t36_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t37 = 0;
    BatchLiftStatus t38_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t39a = 0;
    std::uint32_t t40 = 0;
    std::uint32_t t41 = 0;
    std::uint32_t t42a = 0;
    std::uint32_t t43a = 0;

    // 0x00924bd0: 53 PUSH
        batch_guest_pc = 0x00924bd0u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924bd1: 56 PUSH
        batch_guest_pc = 0x00924bd1u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924bd2: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00924bd4: 8b460c MOV
        batch_guest_pc = 0x00924bd4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00924bd7: 57 PUSH
        batch_guest_pc = 0x00924bd7u;
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924bd8: 50 PUSH
        batch_guest_pc = 0x00924bd8u;
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00924bd9: c70620dd4301 MOV
        batch_guest_pc = 0x00924bd9u;
        t6 = 0x0143dd20u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00924bdf: c7460404dd4301 MOV
        batch_guest_pc = 0x00924bdfu;
        t7 = 0x0143dd04u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00924be6: e895276200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00924bebu)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00f47380(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00924bebu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924beb: 83c404 ADD
        t9a = state.regs[4];
        t9b = 0x00000004u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x00924bee: 8d5e38 LEA
        t10 = static_cast<std::uint32_t>(state.regs[6] + 0x00000038u);
        state.regs[3] = t10;
    // 0x00924bf1: 6878dc4301 PUSH
        batch_guest_pc = 0x00924bf1u;
        t11a = 0x0143dc78u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00924bf6: 8bcb MOV
        t12 = state.regs[3];
        state.regs[1] = t12;
    // 0x00924bf8: e8b3d5ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00924bfdu)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_009221b0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00924bfdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924bfd: 8b4e1c MOV
        batch_guest_pc = 0x00924bfdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000001cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t14;
    // 0x00924c00: 8b5618 MOV
        batch_guest_pc = 0x00924c00u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00924c03: 8d7e18 LEA
        t16 = static_cast<std::uint32_t>(state.regs[6] + 0x00000018u);
        state.regs[7] = t16;
    // 0x00924c06: 51 PUSH
        batch_guest_pc = 0x00924c06u;
        t17a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00924c07: 52 PUSH
        batch_guest_pc = 0x00924c07u;
        t18a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00924c08: 8bcf MOV
        t19 = state.regs[7];
        state.regs[1] = t19;
    // 0x00924c0a: e8c10f5000 CALL
        if (!batch_guest_call32(memory, state, 0x00e25bd0u, 0x00924c0fu)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_00e25bd0(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00924c0fu) return BatchLiftStatus::invalid_control_flow;
    // 0x00924c0f: 8bcb MOV
        t21 = state.regs[3];
        state.regs[1] = t21;
    // 0x00924c11: e85ad6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00924c16u)) return BatchLiftStatus::invalid_memory;
        t22_call_status = spore_lift_00922270(memory, state);
        if (t22_call_status != BatchLiftStatus::returned) return t22_call_status;
        if (state.eip != 0x00924c16u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924c16: 8bcb MOV
        t23 = state.regs[3];
        state.regs[1] = t23;
    // 0x00924c18: e813d5ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922130u, 0x00924c1du)) return BatchLiftStatus::invalid_memory;
        t24_call_status = spore_lift_00922130(memory, state);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
        if (state.eip != 0x00924c1du) return BatchLiftStatus::invalid_control_flow;
    // 0x00924c1d: 8b4e30 MOV
        batch_guest_pc = 0x00924c1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000030u), t25)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t25;
    // 0x00924c20: 85c9 TEST
        t26a = state.regs[1];
        t26b = state.regs[1];
        t26r = (t26a & t26b) & 0xffffffffu;
        batch_set_logic_flags(state, t26r, 32u);
    // 0x00924c22: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924c2b;
    // 0x00924c24: 8b01 MOV
        batch_guest_pc = 0x00924c24u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t28)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t28;
    // 0x00924c26: 8b5004 MOV
        batch_guest_pc = 0x00924c26u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t29)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t29;
    // 0x00924c29: ffd2 CALL
        t30_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924c2bu);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
    // 0x00924c2b: 8b4e2c MOV
    L_00924c2b:
        batch_guest_pc = 0x00924c2bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000002cu), t31)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t31;
    // 0x00924c2e: 85c9 TEST
        t32a = state.regs[1];
        t32b = state.regs[1];
        t32r = (t32a & t32b) & 0xffffffffu;
        batch_set_logic_flags(state, t32r, 32u);
    // 0x00924c30: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924c39;
    // 0x00924c32: 8b01 MOV
        batch_guest_pc = 0x00924c32u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t34)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t34;
    // 0x00924c34: 8b5004 MOV
        batch_guest_pc = 0x00924c34u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t35)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t35;
    // 0x00924c37: ffd2 CALL
        t36_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924c39u);
        if (t36_call_status != BatchLiftStatus::returned) return t36_call_status;
    // 0x00924c39: 8bcf MOV
    L_00924c39:
        t37 = state.regs[7];
        state.regs[1] = t37;
    // 0x00924c3b: e8301d1c00 CALL
        if (!batch_guest_call32(memory, state, 0x00ae6970u, 0x00924c40u)) return BatchLiftStatus::invalid_memory;
        t38_call_status = spore_lift_00ae6970(memory, state);
        if (t38_call_status != BatchLiftStatus::returned) return t38_call_status;
        if (state.eip != 0x00924c40u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924c40: 5f POP
        batch_guest_pc = 0x00924c40u;
        if (!memory.load32(state.regs[4], t39a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t39a;
    // 0x00924c41: c7460438b93e01 MOV
        batch_guest_pc = 0x00924c41u;
        t40 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t40)) return BatchLiftStatus::invalid_memory;
    // 0x00924c48: c70638b93e01 MOV
        batch_guest_pc = 0x00924c48u;
        t41 = 0x013eb938u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t41)) return BatchLiftStatus::invalid_memory;
    // 0x00924c4e: 5e POP
        batch_guest_pc = 0x00924c4eu;
        if (!memory.load32(state.regs[4], t42a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t42a;
    // 0x00924c4f: 5b POP
        batch_guest_pc = 0x00924c4fu;
        if (!memory.load32(state.regs[4], t43a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t43a;
    // 0x00924c50: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
