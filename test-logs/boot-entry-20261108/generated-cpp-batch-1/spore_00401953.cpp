#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401970(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00402385(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00401953(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401953u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0, t11b = 0, t11r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18t = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20a = 0;

    // 0x00401953: 81c0afaafc00 ADD
        t0a = state.regs[0];
        t0b = 0x00fcaaafu;
        t0r = static_cast<std::uint32_t>(t0a + t0b) & 0xffffffffu;
        batch_set_add_flags(state, t0a, t0b, t0r, 32u);
        state.regs[0] = t0r;
    // 0x00401959: e9270a0000 JMP
        state.eip = 0x00402385u;
        return spore_lift_00402385(memory, state);
    // 0x0040195e: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x0040195f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00401960: 55 PUSH
        t4a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00401961: 8bec MOV
        t5 = state.regs[4];
        state.regs[5] = t5;
    // 0x00401963: 8b450c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00401966: 0faf4510 IMUL
        t7a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t7b)) return BatchLiftStatus::invalid_memory;
        {
        const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(t7a)) * static_cast<std::int32_t>(t7b);
        state.regs[0] = static_cast<std::uint32_t>(product);
        state.eflags &= ~0x801u;
        if (product < -2147483648ll || product > 2147483647ll) state.eflags |= 0x801u;
        }
    // 0x0040196a: 034508 ADD
        t8a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8b)) return BatchLiftStatus::invalid_memory;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x0040196d: 894508 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00401970: 8b4d10 MOV
    L_00401970:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t10;
    // 0x00401973: 83e901 SUB
        t11a = state.regs[1];
        t11b = 0x00000001u;
        t11r = static_cast<std::uint32_t>(t11a - t11b) & 0xffffffffu;
        batch_set_sub_flags(state, t11a, t11b, t11r, 32u);
        state.regs[1] = t11r;
    // 0x00401976: 894d10 MOV
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00401979: 7811 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_0040198c;
    // 0x0040197b: 8b5508 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x0040197e: 2b550c SUB
        t15a = state.regs[2];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t15b)) return BatchLiftStatus::invalid_memory;
        t15r = static_cast<std::uint32_t>(t15a - t15b) & 0xffffffffu;
        batch_set_sub_flags(state, t15a, t15b, t15r, 32u);
        state.regs[2] = t15r;
    // 0x00401981: 895508 MOV
        t16 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x00401984: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00401987: ff5514 CALL
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t18t)) return BatchLiftStatus::invalid_memory;
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t18t, 0x0040198au);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x0040198a: ebe4 JMP
        goto L_00401970;
    // 0x0040198c: 5d POP
    L_0040198c:
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t20a;
    // 0x0040198d: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
