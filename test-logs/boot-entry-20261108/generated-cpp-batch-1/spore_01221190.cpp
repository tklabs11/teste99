#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221190(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221190u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01221190: 55 PUSH
        batch_guest_pc = 0x01221190u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221191: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221193: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0122119b: f30f11053c1c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c3cu)) return BatchLiftStatus::invalid_memory;
    // 0x012211a3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x012211ab: f30f1105401c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c40u)) return BatchLiftStatus::invalid_memory;
    // 0x012211b3: f30f1005bcb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb1bcu)) return BatchLiftStatus::invalid_memory;
    // 0x012211bb: f30f1105441c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c44u)) return BatchLiftStatus::invalid_memory;
    // 0x012211c3: 5d POP
        batch_guest_pc = 0x012211c3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012211c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
