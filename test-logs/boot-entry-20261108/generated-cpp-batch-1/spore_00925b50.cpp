#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009221b0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009257e0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925b50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925b50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    BatchLiftStatus t23_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;
    std::uint32_t t29a = 0;
    BatchLiftStatus t30_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t31 = 0;
    BatchLiftStatus t32_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t33a = 0;
    std::uint32_t t34a = 0;

    // 0x00925b50: 56 PUSH
        batch_guest_pc = 0x00925b50u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b51: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925b53: 57 PUSH
        batch_guest_pc = 0x00925b53u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b54: 8d7e20 LEA
        t3 = static_cast<std::uint32_t>(state.regs[6] + 0x00000020u);
        state.regs[7] = t3;
    // 0x00925b57: 68fcdf4301 PUSH
        batch_guest_pc = 0x00925b57u;
        t4a = 0x0143dffcu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b5c: 8bcf MOV
        t5 = state.regs[7];
        state.regs[1] = t5;
    // 0x00925b5e: e84dc6ffff CALL
        if (!batch_guest_call32(memory, state, 0x009221b0u, 0x00925b63u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_009221b0(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00925b63u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925b63: 8b4e04 MOV
        batch_guest_pc = 0x00925b63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x00925b66: 8b44240c MOV
        batch_guest_pc = 0x00925b66u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00925b6a: 894820 MOV
        batch_guest_pc = 0x00925b6au;
        t9 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000020u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00925b6d: 8d4e08 LEA
        t10 = static_cast<std::uint32_t>(state.regs[6] + 0x00000008u);
        state.regs[1] = t10;
    // 0x00925b70: c6400101 MOV
        batch_guest_pc = 0x00925b70u;
        t11 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000001u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00925b74: c6400200 MOV
        batch_guest_pc = 0x00925b74u;
        t12 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[0] + 0x00000002u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00925b78: 8b5104 MOV
        batch_guest_pc = 0x00925b78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00925b7b: 8944240c MOV
        batch_guest_pc = 0x00925b7bu;
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00925b7f: 3b5108 CMP
        batch_guest_pc = 0x00925b7fu;
        t15a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t15b)) return BatchLiftStatus::invalid_memory;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
    // 0x00925b82: 7318 JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_00925b9c;
    // 0x00925b84: 8d7204 LEA
        t17 = static_cast<std::uint32_t>(state.regs[2] + 0x00000004u);
        state.regs[6] = t17;
    // 0x00925b87: 897104 MOV
        batch_guest_pc = 0x00925b87u;
        t18 = state.regs[6];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925b8a: 85d2 TEST
        t19a = state.regs[2];
        t19b = state.regs[2];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x00925b8c: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925ba7;
    // 0x00925b8e: 8bcf MOV
        t21 = state.regs[7];
        state.regs[1] = t21;
    // 0x00925b90: 8902 MOV
        batch_guest_pc = 0x00925b90u;
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00925b92: e8d9c6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00925b97u)) return BatchLiftStatus::invalid_memory;
        t23_call_status = spore_lift_00922270(memory, state);
        if (t23_call_status != BatchLiftStatus::returned) return t23_call_status;
        if (state.eip != 0x00925b97u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925b97: 5f POP
        batch_guest_pc = 0x00925b97u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t24a;
    // 0x00925b98: 5e POP
        batch_guest_pc = 0x00925b98u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t25a;
    // 0x00925b99: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925b9c: 8d44240c LEA
    L_00925b9c:
        t27 = static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu);
        state.regs[0] = t27;
    // 0x00925ba0: 50 PUSH
        batch_guest_pc = 0x00925ba0u;
        t28a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ba1: 52 PUSH
        batch_guest_pc = 0x00925ba1u;
        t29a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t29a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ba2: e839fcffff CALL
        if (!batch_guest_call32(memory, state, 0x009257e0u, 0x00925ba7u)) return BatchLiftStatus::invalid_memory;
        t30_call_status = spore_lift_009257e0(memory, state);
        if (t30_call_status != BatchLiftStatus::returned) return t30_call_status;
        if (state.eip != 0x00925ba7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925ba7: 8bcf MOV
    L_00925ba7:
        t31 = state.regs[7];
        state.regs[1] = t31;
    // 0x00925ba9: e8c2c6ffff CALL
        if (!batch_guest_call32(memory, state, 0x00922270u, 0x00925baeu)) return BatchLiftStatus::invalid_memory;
        t32_call_status = spore_lift_00922270(memory, state);
        if (t32_call_status != BatchLiftStatus::returned) return t32_call_status;
        if (state.eip != 0x00925baeu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925bae: 5f POP
        batch_guest_pc = 0x00925baeu;
        if (!memory.load32(state.regs[4], t33a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t33a;
    // 0x00925baf: 5e POP
        batch_guest_pc = 0x00925bafu;
        if (!memory.load32(state.regs[4], t34a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t34a;
    // 0x00925bb0: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
