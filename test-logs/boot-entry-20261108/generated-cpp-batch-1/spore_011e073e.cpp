#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00401714(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e073e(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e073eu);

    // 0x011e073e: e9d10f22ff JMP
        state.eip = 0x00401714u;
        return spore_lift_00401714(memory, state);
}
