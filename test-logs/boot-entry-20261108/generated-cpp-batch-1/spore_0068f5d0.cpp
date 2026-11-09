#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00922740(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0068f5d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0068f5d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0;

    // 0x0068f5d0: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5d1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x0068f5d3: 397604 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[6];
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x0068f5d6: 7424 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f5fc;
    // 0x0068f5d8: 8b06 MOV
    L_0068f5d8:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x0068f5da: 8b4804 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x0068f5dd: 3bc8 CMP
        t6a = state.regs[1];
        t6b = state.regs[0];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x0068f5df: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0068f5f7;
    // 0x0068f5e1: 8b10 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x0068f5e3: 8911 MOV
        t9 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5e5: 894a04 MOV
        t10 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5e8: 6a01 PUSH
        t11a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5ea: 8d4808 LEA
        t12 = static_cast<std::uint32_t>(state.regs[0] + 0x00000008u);
        state.regs[1] = t12;
    // 0x0068f5ed: 8900 MOV
        t13 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5ef: 894004 MOV
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0068f5f2: e849312900 CALL
        t15_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, 0x00922740u, 0x0068f5f7u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x0068f5f7u) return BatchLiftStatus::invalid_control_flow;
    // 0x0068f5f7: 397604 CMP
    L_0068f5f7:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t16a)) return BatchLiftStatus::invalid_memory;
        t16b = state.regs[6];
        t16r = static_cast<std::uint32_t>(t16a - t16b) & 0xffffffffu;
        batch_set_sub_flags(state, t16a, t16b, t16r, 32u);
    // 0x0068f5fa: 75dc JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0068f5d8;
    // 0x0068f5fc: 5e POP
    L_0068f5fc:
        if (!memory.load32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t18a;
    // 0x0068f5fd: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
