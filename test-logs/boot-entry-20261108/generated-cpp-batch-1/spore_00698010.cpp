#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00697ee0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00698010(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00698010u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;

    // 0x00698010: 56 PUSH
        batch_guest_pc = 0x00698010u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00698011: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00698013: e8c8feffff CALL
        if (!batch_guest_call32(memory, state, 0x00697ee0u, 0x00698018u)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_00697ee0(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x00698018u) return BatchLiftStatus::invalid_control_flow;
    // 0x00698018: f644240801 TEST
        batch_guest_pc = 0x00698018u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000001u;
        t3r = (t3a & t3b) & 0x000000ffu;
        batch_set_logic_flags(state, t3r, 8u);
    // 0x0069801d: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00698028;
    // 0x0069801f: 56 PUSH
        batch_guest_pc = 0x0069801fu;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00698020: e85bf38a00 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00698025u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_00f47380(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00698025u) return BatchLiftStatus::invalid_control_flow;
    // 0x00698025: 83c404 ADD
        t7a = state.regs[4];
        t7b = 0x00000004u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[4] = t7r;
    // 0x00698028: 8bc6 MOV
    L_00698028:
        t8 = state.regs[6];
        state.regs[0] = t8;
    // 0x0069802a: 5e POP
        batch_guest_pc = 0x0069802au;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x0069802b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
