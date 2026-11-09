#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401899(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00401714(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401714u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00401714: e880010000 CALL
        if (!batch_guest_call32(memory, state, 0x00401899u, 0x00401719u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_00401899(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x00401719u) return BatchLiftStatus::invalid_control_flow;
    // 0x00401719: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
