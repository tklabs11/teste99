#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0093c3e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0093c3e0u);
    std::uint32_t t0a = 0, t0r = 0;
    std::uint32_t t1 = 0;

    // 0x0093c3e0: ff4104 INC
        batch_guest_pc = 0x0093c3e0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t0a)) return BatchLiftStatus::invalid_memory;
        t0r = static_cast<std::uint32_t>(t0a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t0a, t0r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t0r)) return BatchLiftStatus::invalid_memory;
    // 0x0093c3e3: 8b4104 MOV
        batch_guest_pc = 0x0093c3e3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x0093c3e6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
