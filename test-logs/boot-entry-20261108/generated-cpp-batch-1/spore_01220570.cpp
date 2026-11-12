#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220570(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220570u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220570: 55 PUSH
        batch_guest_pc = 0x01220570u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220571: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220573: f30f100588b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb188u)) return BatchLiftStatus::invalid_memory;
    // 0x0122057b: f30f11057c1d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d7cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220583: f30f100584b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb184u)) return BatchLiftStatus::invalid_memory;
    // 0x0122058b: f30f1105801d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d80u)) return BatchLiftStatus::invalid_memory;
    // 0x01220593: f30f100580b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb180u)) return BatchLiftStatus::invalid_memory;
    // 0x0122059b: f30f1105841d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d84u)) return BatchLiftStatus::invalid_memory;
    // 0x012205a3: 5d POP
        batch_guest_pc = 0x012205a3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012205a4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
