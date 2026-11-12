#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012212e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012212e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012212e0: 55 PUSH
        batch_guest_pc = 0x012212e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012212e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012212e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012212eb: f30f1105781c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c78u)) return BatchLiftStatus::invalid_memory;
    // 0x012212f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012212fb: f30f11057c1c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c7cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221303: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122130b: f30f1105801c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c80u)) return BatchLiftStatus::invalid_memory;
    // 0x01221313: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122131b: f30f1105841c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c84u)) return BatchLiftStatus::invalid_memory;
    // 0x01221323: 5d POP
        batch_guest_pc = 0x01221323u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221324: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
