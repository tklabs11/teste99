#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221330(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221330u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221330: 55 PUSH
        batch_guest_pc = 0x01221330u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221331: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221333: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122133b: f30f11055c1c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c5cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221343: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122134b: f30f1105601c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c60u)) return BatchLiftStatus::invalid_memory;
    // 0x01221353: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122135b: f30f1105641c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c64u)) return BatchLiftStatus::invalid_memory;
    // 0x01221363: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122136b: f30f1105681c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c68u)) return BatchLiftStatus::invalid_memory;
    // 0x01221373: 5d POP
        batch_guest_pc = 0x01221373u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221374: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
