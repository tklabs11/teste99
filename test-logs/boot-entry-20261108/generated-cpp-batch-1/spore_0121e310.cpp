#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e310(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e310u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e310: 55 PUSH
        batch_guest_pc = 0x0121e310u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e311: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e313: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e31b: f30f110574195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1974u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e323: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e32b: f30f110578195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1978u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e333: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e33b: f30f11057c195d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d197cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e343: 5d POP
        batch_guest_pc = 0x0121e343u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e344: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
