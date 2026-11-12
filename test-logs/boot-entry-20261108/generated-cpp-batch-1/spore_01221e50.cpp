#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221e50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221e50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221e50: 55 PUSH
        batch_guest_pc = 0x01221e50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221e51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221e53: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e5b: f30f1105bc225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01221e63: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e6b: f30f1105c0225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22c0u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e73: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e7b: f30f1105c4225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22c4u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e8b: f30f1105c8225d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d22c8u)) return BatchLiftStatus::invalid_memory;
    // 0x01221e93: 5d POP
        batch_guest_pc = 0x01221e93u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221e94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
