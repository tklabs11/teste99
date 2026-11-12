#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925dc0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925e70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925e70u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18 = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0;

    // 0x00925e70: 8b442404 MOV
        batch_guest_pc = 0x00925e70u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925e74: 3b4114 CMP
        batch_guest_pc = 0x00925e74u;
        t1a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000014u), t1b)) return BatchLiftStatus::invalid_memory;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00925e77: 7709 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00925e82;
    // 0x00925e79: 89442404 MOV
        batch_guest_pc = 0x00925e79u;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00925e7d: e93effffff JMP
        state.eip = 0x00925dc0u;
        return spore_lift_00925dc0(memory, state);
    // 0x00925e82: ff411c INC
    L_00925e82:
        batch_guest_pc = 0x00925e82u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t5a)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t5a, t5r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t5r)) return BatchLiftStatus::invalid_memory;
    // 0x00925e85: 8b4904 MOV
        batch_guest_pc = 0x00925e85u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00925e88: 8b11 MOV
        batch_guest_pc = 0x00925e88u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00925e8a: 56 PUSH
        batch_guest_pc = 0x00925e8au;
        t8a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e8b: 8b742418 MOV
        batch_guest_pc = 0x00925e8bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t9;
    // 0x00925e8f: 56 PUSH
        batch_guest_pc = 0x00925e8fu;
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e90: 8b742418 MOV
        batch_guest_pc = 0x00925e90u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x00925e94: 56 PUSH
        batch_guest_pc = 0x00925e94u;
        t12a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e95: 8b742418 MOV
        batch_guest_pc = 0x00925e95u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t13;
    // 0x00925e99: 56 PUSH
        batch_guest_pc = 0x00925e99u;
        t14a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e9a: 8b742418 MOV
        batch_guest_pc = 0x00925e9au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t15;
    // 0x00925e9e: 56 PUSH
        batch_guest_pc = 0x00925e9eu;
        t16a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00925e9f: 50 PUSH
        batch_guest_pc = 0x00925e9fu;
        t17a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ea0: 8b4204 MOV
        batch_guest_pc = 0x00925ea0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t18;
    // 0x00925ea3: ffd0 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925ea5u);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x00925ea5: 5e POP
        batch_guest_pc = 0x00925ea5u;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00925ea6: c21400 RET
        if (!batch_guest_return32(memory, state, 20u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
