#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223c40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223c40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01223c40: 55 PUSH
        batch_guest_pc = 0x01223c40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223c41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223c43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c4b: f30f1105ec2a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2aecu)) return BatchLiftStatus::invalid_memory;
    // 0x01223c53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c5b: f30f1105f02a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2af0u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c6b: f30f1105f42a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2af4u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c7b: f30f1105f82a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2af8u)) return BatchLiftStatus::invalid_memory;
    // 0x01223c83: 5d POP
        batch_guest_pc = 0x01223c83u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01223c84: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
