#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220bb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220bb0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220bb0: 55 PUSH
        batch_guest_pc = 0x01220bb0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220bb1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220bb3: f30f1005541e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1e54u)) return BatchLiftStatus::invalid_memory;
    // 0x01220bbb: f30f1105481e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e48u)) return BatchLiftStatus::invalid_memory;
    // 0x01220bc3: f30f1005581e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1e58u)) return BatchLiftStatus::invalid_memory;
    // 0x01220bcb: f30f11054c1e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e4cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220bd3: f30f10055c1e5d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d1e5cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220bdb: f30f1105501e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e50u)) return BatchLiftStatus::invalid_memory;
    // 0x01220be3: 5d POP
        batch_guest_pc = 0x01220be3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220be4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
