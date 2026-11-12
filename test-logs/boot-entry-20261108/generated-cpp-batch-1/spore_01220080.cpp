#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220080(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220080u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220080: 55 PUSH
        batch_guest_pc = 0x01220080u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220081: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220083: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122008b: f30f11059c1d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d9cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220093: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122009b: f30f1105a01d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1da0u)) return BatchLiftStatus::invalid_memory;
    // 0x012200a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012200ab: f30f1105a41d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1da4u)) return BatchLiftStatus::invalid_memory;
    // 0x012200b3: 5d POP
        batch_guest_pc = 0x012200b3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012200b4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
