#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e1219(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e07e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e07e0u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011e07e0: e8340a0000 CALL
        if (!batch_guest_call32(memory, state, 0x011e1219u, 0x011e07e5u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_011e1219(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x011e07e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07e5: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
