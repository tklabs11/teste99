#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00927a50(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009289e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009289e0u);

    // 0x009289e0: e96bf0ffff JMP
        state.eip = 0x00927a50u;
        return spore_lift_00927a50(memory, state);
}
