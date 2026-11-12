#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223970(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223970u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223970: 55 PUSH
        batch_guest_pc = 0x01223970u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223971: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223973: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122397b: f30f1105b42b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bb4u)) return BatchLiftStatus::invalid_memory;
    // 0x01223983: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122398b: f30f1105b82b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bb8u)) return BatchLiftStatus::invalid_memory;
    // 0x01223993: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122399b: f30f1105bc2b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bbcu)) return BatchLiftStatus::invalid_memory;
    // 0x012239a3: 5d POP
        batch_guest_pc = 0x012239a3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012239a4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
