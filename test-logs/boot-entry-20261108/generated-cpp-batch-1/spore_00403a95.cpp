#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00403ac5(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004044f4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_004200b0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00403a95(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00403a95u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0, t22b = 0, t22r = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24 = 0;
    BatchLiftStatus t25_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;
    std::uint32_t t28a = 0;

    // 0x00403a95: 31c0 XOR
        t0a = state.regs[0];
        t0b = state.regs[0];
        t0r = (t0a ^ t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
        state.regs[0] = t0r;
    // 0x00403a97: e9580a0000 JMP
        state.eip = 0x004044f4u;
        return spore_lift_004044f4(memory, state);
    // 0x00403a9c: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00403a9d: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00403a9e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00403a9f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00403aa0: 55 PUSH
        t6a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00403aa1: 8bec MOV
        t7 = state.regs[4];
        state.regs[5] = t7;
    // 0x00403aa3: 83ec0c SUB
        t8a = state.regs[4];
        t8b = 0x0000000cu;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x00403aa6: 894df4 MOV
        t9 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00403aa9: c745f808000000 MOV
        t10 = 0x00000008u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00403ab0: 8b45f4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00403ab3: 8945fc MOV
        t12 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00403ab6: b92c000000 MOV
        t13 = 0x0000002cu;
        state.regs[1] = t13;
    // 0x00403abb: 0faf4df8 IMUL
        t14a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t14b)) return BatchLiftStatus::invalid_memory;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t14a)) * static_cast<std::int32_t>(t14b);
        state.regs[1] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x00403abf: 034dfc ADD
        t15a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15b)) return BatchLiftStatus::invalid_memory;
        t15r = static_cast<std::uint32_t>(t15a + t15b) & 0xffffffffu;
        batch_set_add_flags(state, t15a, t15b, t15r, 32u);
        state.regs[1] = t15r;
    // 0x00403ac2: 894dfc MOV
        t16 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00403ac5: 8b55f8 MOV
    L_00403ac5:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t17;
    // 0x00403ac8: 83ea01 SUB
        t18a = state.regs[2];
        t18b = 0x00000001u;
        t18r = static_cast<std::uint32_t>(t18a - t18b) & 0xffffffffu;
        batch_set_sub_flags(state, t18a, t18b, t18r, 32u);
        state.regs[2] = t18r;
    // 0x00403acb: 8955f8 MOV
        t19 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00403ace: 7813 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_00403ae3;
    // 0x00403ad0: 8b45fc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00403ad3: 83e82c SUB
        t22a = state.regs[0];
        t22b = 0x0000002cu;
        t22r = static_cast<std::uint32_t>(t22a - t22b) & 0xffffffffu;
        batch_set_sub_flags(state, t22a, t22b, t22r, 32u);
        state.regs[0] = t22r;
    // 0x00403ad6: 8945fc MOV
        t23 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00403ad9: 8b4dfc MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00403adc: e8cfc50100 CALL
        if (!batch_guest_call32(memory, state, 0x004200b0u, 0x00403ae1u)) return BatchLiftStatus::invalid_memory;
        t25_call_status = spore_lift_004200b0(memory, state);
        if (t25_call_status != BatchLiftStatus::returned) return t25_call_status;
        if (state.eip != 0x00403ae1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00403ae1: ebe2 JMP
        goto L_00403ac5;
    // 0x00403ae3: 8be5 MOV
    L_00403ae3:
        t27 = state.regs[5];
        state.regs[4] = t27;
    // 0x00403ae5: 5d POP
        if (!memory.load32(state.regs[4], t28a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t28a;
    // 0x00403ae6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
