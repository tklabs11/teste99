#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009236d0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697ed0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697ed0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;

    // 0x00697ed0: 83e904 SUB
        t0a = state.regs[1];
        t0b = 0x00000004u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00697ed3: e9f8b72800 JMP
        state.eip = 0x009236d0u;
        return spore_lift_009236d0(memory, state);
}
