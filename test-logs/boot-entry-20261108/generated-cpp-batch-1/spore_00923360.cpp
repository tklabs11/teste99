#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00f47380(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923360(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923360u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;

    // 0x00923360: f644240401 TEST
        batch_guest_pc = 0x00923360u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000001u;
        t0r = (t0a & t0b) & 0x000000ffu;
        batch_set_logic_flags(state, t0r, 8u);
    // 0x00923365: 56 PUSH
        batch_guest_pc = 0x00923365u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923366: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00923368: c7067cdc4301 MOV
        batch_guest_pc = 0x00923368u;
        t3 = 0x0143dc7cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x0092336e: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00923379;
    // 0x00923370: 56 PUSH
        batch_guest_pc = 0x00923370u;
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00923371: e80a406200 CALL
        if (!batch_guest_call32(memory, state, 0x00f47380u, 0x00923376u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_00f47380(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00923376u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923376: 83c404 ADD
        t7a = state.regs[4];
        t7b = 0x00000004u;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[4] = t7r;
    // 0x00923379: 8bc6 MOV
    L_00923379:
        t8 = state.regs[6];
        state.regs[0] = t8;
    // 0x0092337b: 5e POP
        batch_guest_pc = 0x0092337bu;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t9a;
    // 0x0092337c: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
