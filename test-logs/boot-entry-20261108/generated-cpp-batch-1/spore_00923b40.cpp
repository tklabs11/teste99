#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923b40(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923b40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923b40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;

    // 0x00923b40: 53 PUSH
        batch_guest_pc = 0x00923b40u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b41: 56 PUSH
        batch_guest_pc = 0x00923b41u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b42: 8b74240c MOV
        batch_guest_pc = 0x00923b42u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t2;
    // 0x00923b46: 8bd9 MOV
        t3 = state.regs[1];
        state.regs[3] = t3;
    // 0x00923b48: 85f6 TEST
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00923b4a: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923b71;
    // 0x00923b4c: 57 PUSH
        batch_guest_pc = 0x00923b4cu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b4d: 8d4900 LEA
        t7 = static_cast<std::uint32_t>(state.regs[1] + 0x00000000u);
        state.regs[1] = t7;
    // 0x00923b50: 8b06 MOV
    L_00923b50:
        batch_guest_pc = 0x00923b50u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00923b52: 50 PUSH
        batch_guest_pc = 0x00923b52u;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b53: 8bcb MOV
        t10 = state.regs[3];
        state.regs[1] = t10;
    // 0x00923b55: e8e6ffffff CALL
        if (!batch_guest_call32(memory, state, 0x00923b40u, 0x00923b5au)) return BatchLiftStatus::invalid_memory;
        t11_call_status = spore_lift_00923b40(memory, state);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x00923b5au) return BatchLiftStatus::invalid_control_flow;
    // 0x00923b5a: 8b4b18 MOV
        batch_guest_pc = 0x00923b5au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[3] + 0x00000018u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x00923b5d: 8b11 MOV
        batch_guest_pc = 0x00923b5du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00923b5f: 8b420c MOV
        batch_guest_pc = 0x00923b5fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00923b62: 8b7e04 MOV
        batch_guest_pc = 0x00923b62u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t15;
    // 0x00923b65: 6a18 PUSH
        batch_guest_pc = 0x00923b65u;
        t16a = 0x00000018u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b67: 56 PUSH
        batch_guest_pc = 0x00923b67u;
        t17a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b68: ffd0 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923b6au);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x00923b6a: 8bf7 MOV
        t19 = state.regs[7];
        state.regs[6] = t19;
    // 0x00923b6c: 85ff TEST
        t20a = state.regs[7];
        t20b = state.regs[7];
        t20r = (t20a & t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
    // 0x00923b6e: 75e0 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00923b50;
    // 0x00923b70: 5f POP
        batch_guest_pc = 0x00923b70u;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t22a;
    // 0x00923b71: 5e POP
    L_00923b71:
        batch_guest_pc = 0x00923b71u;
        if (!memory.load32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t23a;
    // 0x00923b72: 5b POP
        batch_guest_pc = 0x00923b72u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t24a;
    // 0x00923b73: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
