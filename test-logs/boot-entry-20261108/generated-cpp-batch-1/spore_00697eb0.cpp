#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009236c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697eb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697eb0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;

    // 0x00697eb0: 83e904 SUB
        t0a = state.regs[1];
        t0b = 0x00000004u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00697eb3: e908b82800 JMP
        state.eip = 0x009236c0u;
        return spore_lift_009236c0(memory, state);
}
