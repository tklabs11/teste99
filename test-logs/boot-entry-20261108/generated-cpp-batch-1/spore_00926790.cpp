#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926790(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926790u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;

    // 0x00926790: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926794: 83c008 ADD
        t1a = state.regs[0];
        t1b = 0x00000008u;
        t1r = static_cast<std::uint32_t>(t1a + t1b) & 0xffffffffu;
        batch_set_add_flags(state, t1a, t1b, t1r, 32u);
        state.regs[0] = t1r;
    // 0x00926797: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
