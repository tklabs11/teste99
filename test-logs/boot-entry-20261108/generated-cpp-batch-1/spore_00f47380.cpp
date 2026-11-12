#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009276c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f47380u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00f47380: 8b442404 MOV
        batch_guest_pc = 0x00f47380u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00f47384: 85c0 TEST
        t1a = state.regs[0];
        t1b = state.regs[0];
        t1r = (t1a & t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
    // 0x00f47386: 740c JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f47394;
    // 0x00f47388: 8b0d448b6c01 MOV
        batch_guest_pc = 0x00f47388u;
        if (!memory.load32(0x016c8b44u, t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t3;
    // 0x00f4738e: 50 PUSH
        batch_guest_pc = 0x00f4738eu;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4738f: e82c039eff CALL
        if (!batch_guest_call32(memory, state, 0x009276c0u, 0x00f47394u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_009276c0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00f47394u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f47394: c3 RET
    L_00f47394:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
