#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00924bd0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924cf0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924cf0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;

    // 0x00924cf0: 56 PUSH
        batch_guest_pc = 0x00924cf0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924cf1: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00924cf3: e8d8feffff CALL
        if (!batch_guest_call32(memory, state, 0x00924bd0u, 0x00924cf8u)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_00924bd0(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x00924cf8u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924cf8: f644240801 TEST
        batch_guest_pc = 0x00924cf8u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000001u;
        t3r = (t3a & t3b) & 0x000000ffu;
        batch_set_logic_flags(state, t3r, 8u);
    // 0x00924cfd: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924d08;
    // 0x00924cff: 56 PUSH
        batch_guest_pc = 0x00924cffu;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00924d00: e87b266200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00924d05u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_00f47380(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00924d05u) return BatchLiftStatus::invalid_control_flow;
    // 0x00924d05: 83c404 ADD
        t7a = state.regs[4];
        t7b = 0x00000004u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[4] = t7r;
    // 0x00924d08: 8bc6 MOV
    L_00924d08:
        t8 = state.regs[6];
        state.regs[0] = t8;
    // 0x00924d0a: 5e POP
        batch_guest_pc = 0x00924d0au;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x00924d0b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
