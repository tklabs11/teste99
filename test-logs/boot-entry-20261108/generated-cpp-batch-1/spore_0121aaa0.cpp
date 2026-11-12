#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121aaa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121aaa0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121aaa0: 55 PUSH
        batch_guest_pc = 0x0121aaa0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121aaa1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121aaa3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aaab: f30f1105440e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e44u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aab3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aabb: f30f1105480e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e48u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aac3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aacb: f30f11054c0e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e4cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121aad3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aadb: f30f1105500e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0e50u)) return BatchLiftStatus::invalid_memory;
    // 0x0121aae3: 5d POP
        batch_guest_pc = 0x0121aae3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121aae4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
