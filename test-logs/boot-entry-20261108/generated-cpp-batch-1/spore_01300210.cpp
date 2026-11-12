#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_01300210(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01300210u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;

    // 0x01300210: 68900e3c01 PUSH
        batch_guest_pc = 0x01300210u;
        t0a = 0x013c0e90u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01300215: e8d505eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0130021au)) return BatchLiftStatus::invalid_memory;
        t1_call_status = spore_lift_011e07ef(memory, state);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x0130021au) return BatchLiftStatus::invalid_control_flow;
    // 0x0130021a: 59 POP
        batch_guest_pc = 0x0130021au;
        if (!memory.load32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t2a;
    // 0x0130021b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
