#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220610(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220610u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t4a = 0;

    // 0x01220610: 55 PUSH
        batch_guest_pc = 0x01220610u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220611: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220613: f30f100508bd3e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013ebd08u)) return BatchLiftStatus::invalid_memory;
    // 0x0122061b: f30f11051c205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d201cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220623: 5d POP
        batch_guest_pc = 0x01220623u;
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t4a;
    // 0x01220624: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
