#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009258f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925b00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925b00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27a = 0;
    std::uint32_t t28a = 0;

    // 0x00925b00: 53 PUSH
        batch_guest_pc = 0x00925b00u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b01: 56 PUSH
        batch_guest_pc = 0x00925b01u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b02: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00925b04: c7460400000000 MOV
        batch_guest_pc = 0x00925b04u;
        t3 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00925b0b: c70600000000 MOV
        batch_guest_pc = 0x00925b0bu;
        t4 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00925b11: 57 PUSH
        batch_guest_pc = 0x00925b11u;
        t5a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925b12: c7461000000000 MOV
        batch_guest_pc = 0x00925b12u;
        t6 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00925b19: e8d2fdffff CALL
        if (!batch_guest_call32(memory, state, 0x009258f0u, 0x00925b1eu)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_009258f0(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00925b1eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925b1e: 8b5e10 MOV
        batch_guest_pc = 0x00925b1eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[3] = t8;
    // 0x00925b21: 8bf8 MOV
        t9 = state.regs[0];
        state.regs[7] = t9;
    // 0x00925b23: 3bfb CMP
        t10a = state.regs[7];
        t10b = state.regs[3];
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x00925b25: 741c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925b43;
    // 0x00925b27: 85ff TEST
        t12a = state.regs[7];
        t12b = state.regs[7];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x00925b29: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925b33;
    // 0x00925b2b: 8b07 MOV
        batch_guest_pc = 0x00925b2bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00925b2d: 8b10 MOV
        batch_guest_pc = 0x00925b2du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t15;
    // 0x00925b2f: 8bcf MOV
        t16 = state.regs[7];
        state.regs[1] = t16;
    // 0x00925b31: ffd2 CALL
        t17_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925b33u);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
    // 0x00925b33: 897e10 MOV
    L_00925b33:
        batch_guest_pc = 0x00925b33u;
        t18 = state.regs[7];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925b36: 85db TEST
        t19a = state.regs[3];
        t19b = state.regs[3];
        t19r = (t19a & t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
    // 0x00925b38: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925b43;
    // 0x00925b3a: 8b03 MOV
        batch_guest_pc = 0x00925b3au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000000u), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00925b3c: 8b5004 MOV
        batch_guest_pc = 0x00925b3cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t22)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t22;
    // 0x00925b3f: 8bcb MOV
        t23 = state.regs[3];
        state.regs[1] = t23;
    // 0x00925b41: ffd2 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00925b43u);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x00925b43: 5f POP
    L_00925b43:
        batch_guest_pc = 0x00925b43u;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t25a;
    // 0x00925b44: 8bc6 MOV
        t26 = state.regs[6];
        state.regs[0] = t26;
    // 0x00925b46: 5e POP
        batch_guest_pc = 0x00925b46u;
        if (!memory.load32(state.regs[4], t27a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t27a;
    // 0x00925b47: 5b POP
        batch_guest_pc = 0x00925b47u;
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t28a;
    // 0x00925b48: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
