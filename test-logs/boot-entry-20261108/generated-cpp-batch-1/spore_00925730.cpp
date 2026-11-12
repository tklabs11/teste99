#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f473d0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925730(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925730u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;

    // 0x00925730: 6a00 PUSH
        batch_guest_pc = 0x00925730u;
        t0a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925732: 6a00 PUSH
        batch_guest_pc = 0x00925732u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925734: 6a00 PUSH
        batch_guest_pc = 0x00925734u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925736: 6a00 PUSH
        batch_guest_pc = 0x00925736u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925738: 68d8884101 PUSH
        batch_guest_pc = 0x00925738u;
        t4a = 0x014188d8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092573d: 6a00 PUSH
        batch_guest_pc = 0x0092573du;
        t5a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092573f: 6a04 PUSH
        batch_guest_pc = 0x0092573fu;
        t6a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925741: 6a14 PUSH
        batch_guest_pc = 0x00925741u;
        t7a = 0x00000014u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925743: e8881c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473d0u, 0x00925748u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00f473d0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00925748u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925748: 83c420 ADD
        t9a = state.regs[4];
        t9b = 0x00000020u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x0092574b: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x0092574d: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925764;
    // 0x0092574f: c7400400000000 MOV
        batch_guest_pc = 0x0092574fu;
        t12 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00925756: c70000000000 MOV
        batch_guest_pc = 0x00925756u;
        t13 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x0092575c: c7401001000000 MOV
        batch_guest_pc = 0x0092575cu;
        t14 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00925763: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925764: 33c0 XOR
    L_00925764:
        t16a = state.regs[0];
        t16b = state.regs[0];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x00925766: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
