#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e8c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e8c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121e8c0: 55 PUSH
        batch_guest_pc = 0x0121e8c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e8c3: f30f100588b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb188u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8cb: f30f110534185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1834u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8d3: f30f100584b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb184u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8db: f30f110538185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1838u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8e3: f30f100580b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb180u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8eb: f30f11053c185d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d183cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e8f3: 5d POP
        batch_guest_pc = 0x0121e8f3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121e8f4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
