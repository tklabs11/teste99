#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e1545(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e1545u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;

    // 0x011e1545: 33c0 XOR
        t0a = state.regs[0];
        t0b = state.regs[0];
        t0r = (t0a ^ t0b) & 0xffffffffu;
        batch_set_logic_flags(state, t0r, 32u);
        state.regs[0] = t0r;
    // 0x011e1547: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
