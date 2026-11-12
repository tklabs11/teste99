#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224a80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224a80u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01224a80: 55 PUSH
        batch_guest_pc = 0x01224a80u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224a81: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224a83: f30f1005c8b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224a8b: f30f1105c82a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ac8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224a93: f30f1005c4b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224a9b: f30f1105cc2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2accu)) return BatchLiftStatus::invalid_memory;
    // 0x01224aa3: f30f1005c0b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1c0u)) return BatchLiftStatus::invalid_memory;
    // 0x01224aab: f30f1105d02a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ad0u)) return BatchLiftStatus::invalid_memory;
    // 0x01224ab3: 5d POP
        batch_guest_pc = 0x01224ab3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01224ab4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
