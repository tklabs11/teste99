#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221ef0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221ef0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221ef0: 55 PUSH
        batch_guest_pc = 0x01221ef0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221ef1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221ef3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221efb: f30f110580255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2580u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f03: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f0b: f30f110584255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2584u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f13: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f1b: f30f110588255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2588u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f23: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f2b: f30f11058c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d258cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221f33: 5d POP
        batch_guest_pc = 0x01221f33u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221f34: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
