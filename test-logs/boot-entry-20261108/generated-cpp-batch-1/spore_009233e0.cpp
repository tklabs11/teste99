#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009233e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009233e0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;

    // 0x009233e0: 668b442404 MOV
        batch_guest_pc = 0x009233e0u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffff0000u) | ((t0 << 0u) & 0x0000ffffu);
    // 0x009233e5: 6689811c020000 MOV
        batch_guest_pc = 0x009233e5u;
        t1 = state.regs[0] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[1] + 0x0000021cu), t1)) return BatchLiftStatus::invalid_memory;
    // 0x009233ec: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
