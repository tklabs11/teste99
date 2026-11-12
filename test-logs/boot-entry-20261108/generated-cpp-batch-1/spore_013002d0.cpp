#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935b70(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_013002d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x013002d0u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0;

    // 0x013002d0: e89b5863ff CALL
        if (!batch_guest_call32(memory, state, 0x00935b70u, 0x013002d5u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_00935b70(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x013002d5u) return BatchLiftStatus::invalid_control_flow;
    // 0x013002d5: 68500f3c01 PUSH
        batch_guest_pc = 0x013002d5u;
        t1a = 0x013c0f50u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x013002da: e81005eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x013002dfu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_011e07ef(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x013002dfu) return BatchLiftStatus::invalid_control_flow;
    // 0x013002df: 59 POP
        batch_guest_pc = 0x013002dfu;
        if (!memory.load32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t3a;
    // 0x013002e0: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
