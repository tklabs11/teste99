#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00923680(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697ec0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697ec0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;

    // 0x00697ec0: 83e904 SUB
        t0a = state.regs[1];
        t0b = 0x00000004u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00697ec3: e9b8b72800 JMP
        state.eip = 0x00923680u;
        return spore_lift_00923680(memory, state);
}
