#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401933(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00401953(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00401923(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401923u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12t = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0;

    // 0x00401923: 50 PUSH
        t0a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00401924: fff1 PUSH
        t1a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00401926: 8b442410 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x0040192a: e924000000 JMP
        state.eip = 0x00401953u;
        return spore_lift_00401953(memory, state);
    // 0x0040192f: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00401930: 55 PUSH
        t5a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00401931: 8bec MOV
        t6 = state.regs[4];
        state.regs[5] = t6;
    // 0x00401933: 8b4510 MOV
    L_00401933:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t7;
    // 0x00401936: 83e801 SUB
        t8a = state.regs[0];
        t8b = 0x00000001u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[0] = t8r;
    // 0x00401939: 894510 MOV
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000010u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0040193c: 7811 JS
        if (((state.eflags & 0x080u) != 0u)) goto L_0040194f;
    // 0x0040193e: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x00401941: ff5514 CALL
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000014u), t12t)) return BatchLiftStatus::invalid_memory;
        t12_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, t12t, 0x00401944u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
    // 0x00401944: 8b4d08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00401947: 034d0c ADD
        t14a = state.regs[1];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x0000000cu), t14b)) return BatchLiftStatus::invalid_memory;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[1] = t14r;
    // 0x0040194a: 894d08 MOV
        t15 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x0040194d: ebe4 JMP
        goto L_00401933;
    // 0x0040194f: 5d POP
    L_0040194f:
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t17a;
    // 0x00401950: c21000 RET
        if (!batch_guest_return32(memory, state, 16u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
