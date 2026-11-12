#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223ab0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223ab0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223ab0: 55 PUSH
        batch_guest_pc = 0x01223ab0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223ab1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223ab3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223abb: f30f1105c02b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bc0u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ac3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223acb: f30f1105c42b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bc4u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ad3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223adb: f30f1105c82b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bc8u)) return BatchLiftStatus::invalid_memory;
    // 0x01223ae3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223aeb: f30f1105cc2b5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2bccu)) return BatchLiftStatus::invalid_memory;
    // 0x01223af3: 5d POP
        batch_guest_pc = 0x01223af3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223af4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
