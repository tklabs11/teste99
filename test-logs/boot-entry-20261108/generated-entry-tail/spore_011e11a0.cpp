#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1548(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e11a0(BatchLiftMemory& memory, BatchLiftState& state) {
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011e11a0: e8a3030000 CALL
        if (!batch_guest_call32(memory, state, 0x011e1548u, 0x011e11a5u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_011e1548(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x011e11a5u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e11a5: e936fdffff JMP
        state.eip = 0x011e0ee0u;
        return spore_lift_011e0ee0(memory, state);
}
