#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223c90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223c90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223c90: 55 PUSH
        batch_guest_pc = 0x01223c90u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223c91: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223c93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c9b: f30f1105d42a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ad4u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ca3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cab: f30f1105d82a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ad8u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cb3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cbb: f30f1105dc2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2adcu)) return BatchLiftStatus::invalid_memory;
    // 0x01223cc3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ccb: f30f1105e02a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2ae0u)) return BatchLiftStatus::invalid_memory;
    // 0x01223cd3: 5d POP
        batch_guest_pc = 0x01223cd3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223cd4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
