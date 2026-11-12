#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009245e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009245e0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;

    // 0x009245e0: 668b8e1c020000 MOV
        batch_guest_pc = 0x009245e0u;
        if (!memory.load16(static_cast<std::uint32_t>(state.regs[6] + 0x0000021cu), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffff0000u) | ((t0 << 0u) & 0x0000ffffu);
    // 0x009245e7: 6689881c020000 MOV
        batch_guest_pc = 0x009245e7u;
        t1 = state.regs[1] & 0x0000ffffu;
        if (!memory.store16(static_cast<std::uint32_t>(state.regs[0] + 0x0000021cu), t1)) return BatchLiftStatus::invalid_memory;
    // 0x009245ee: 8b9620020000 MOV
        batch_guest_pc = 0x009245eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000220u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x009245f4: 899020020000 MOV
        batch_guest_pc = 0x009245f4u;
        t3 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000220u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x009245fa: 5e POP
        batch_guest_pc = 0x009245fau;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t4a;
    // 0x009245fb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
