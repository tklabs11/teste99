#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e730(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e730u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e730: 55 PUSH
        batch_guest_pc = 0x0121e730u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e731: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e733: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e73b: f30f1105801a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a80u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e743: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e74b: f30f1105841a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a84u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e753: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e75b: f30f1105881a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a88u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e763: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e76b: f30f11058c1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1a8cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e773: 5d POP
        batch_guest_pc = 0x0121e773u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e774: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
