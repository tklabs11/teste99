#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011eaaa0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e2050(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e2050u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;

    // 0x011e2050: a178296f01 MOV
        batch_guest_pc = 0x011e2050u;
        if (!memory.load32(0x016f2978u, t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x011e2055: 56 PUSH
        batch_guest_pc = 0x011e2055u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e2056: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x011e2058: 8b0d78296f01 MOV
        batch_guest_pc = 0x011e2058u;
        if (!memory.load32(0x016f2978u, t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t3;
    // 0x011e205e: 41 INC
        t4a = state.regs[1];
        t4r = static_cast<std::uint32_t>(t4a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t4a, t4r, 32u);
        state.regs[1] = t4r;
    // 0x011e205f: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x011e2061: 890d78296f01 MOV
        batch_guest_pc = 0x011e2061u;
        t6 = state.regs[1];
        if (!memory.store32(0x016f2978u, t6)) return BatchLiftStatus::invalid_memory;
    // 0x011e2067: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_011e206e;
    // 0x011e2069: e8328a0000 CALL
        if (!batch_guest_call32(memory, state, 0x011eaaa0u, 0x011e206eu)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_011eaaa0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x011e206eu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e206e: 8bc6 MOV
    L_011e206e:
        t9 = state.regs[6];
        state.regs[0] = t9;
    // 0x011e2070: 5e POP
        batch_guest_pc = 0x011e2070u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x011e2071: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
