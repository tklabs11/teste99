#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004012c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121fc90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121fc90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;

    // 0x0121fc90: 55 PUSH
        batch_guest_pc = 0x0121fc90u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fc91: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121fc93: 6824175d01 PUSH
        batch_guest_pc = 0x0121fc93u;
        t2a = 0x015d1724u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fc98: e823161eff CALL
        if (!batch_guest_call32(memory, state, 0x004012c0u, 0x0121fc9du)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_004012c0(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0121fc9du) return BatchLiftStatus::invalid_control_flow;
    // 0x0121fc9d: 83c404 ADD
        t4a = state.regs[4];
        t4b = 0x00000004u;
        t4r = static_cast<std::uint32_t>(t4a + t4b) & 0xffffffffu;
        batch_set_add_flags(state, t4a, t4b, t4r, 32u);
        state.regs[4] = t4r;
    // 0x0121fca0: 5d POP
        batch_guest_pc = 0x0121fca0u;
        if (!memory.load32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t5a;
    // 0x0121fca1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
