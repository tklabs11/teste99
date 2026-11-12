#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221d70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221d70u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221d70: 55 PUSH
        batch_guest_pc = 0x01221d70u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221d71: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221d73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d7b: f30f11052c235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d232cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221d83: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221d8b: f30f110530235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2330u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d93: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221d9b: f30f110534235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2334u)) return BatchLiftStatus::invalid_memory;
    // 0x01221da3: 5d POP
        batch_guest_pc = 0x01221da3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01221da4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
