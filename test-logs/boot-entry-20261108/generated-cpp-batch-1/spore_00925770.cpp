#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925540(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473d0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925770(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925770u);
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
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;

    // 0x00925770: 6a00 PUSH
        batch_guest_pc = 0x00925770u;
        t0a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925772: 6a00 PUSH
        batch_guest_pc = 0x00925772u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00925774: 6a00 PUSH
        batch_guest_pc = 0x00925774u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925776: 6a00 PUSH
        batch_guest_pc = 0x00925776u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925778: 68d8884101 PUSH
        batch_guest_pc = 0x00925778u;
        t4a = 0x014188d8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092577d: 6a00 PUSH
        batch_guest_pc = 0x0092577du;
        t5a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092577f: 6a04 PUSH
        batch_guest_pc = 0x0092577fu;
        t6a = 0x00000004u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925781: 6a14 PUSH
        batch_guest_pc = 0x00925781u;
        t7a = 0x00000014u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925783: e8481c6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473d0u, 0x00925788u)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00f473d0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00925788u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925788: 83c420 ADD
        t9a = state.regs[4];
        t9b = 0x00000020u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x0092578b: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x0092578d: 7407 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925796;
    // 0x0092578f: 8bc8 MOV
        t12 = state.regs[0];
        state.regs[1] = t12;
    // 0x00925791: e9aafdffff JMP
        state.eip = 0x00925540u;
        return spore_lift_00925540(memory, state);
    // 0x00925796: 33c0 XOR
    L_00925796:
        t14a = state.regs[0];
        t14b = state.regs[0];
        t14r = (t14a ^ t14b) & 0xffffffffu;
        batch_set_logic_flags(state, t14r, 32u);
        state.regs[0] = t14r;
    // 0x00925798: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
