#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012204d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012204d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012204d0: 55 PUSH
        batch_guest_pc = 0x012204d0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012204d1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012204d3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012204db: f30f1105481d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d48u)) return BatchLiftStatus::invalid_memory;
    // 0x012204e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012204eb: f30f11054c1d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d4cu)) return BatchLiftStatus::invalid_memory;
    // 0x012204f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012204fb: f30f1105501d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d50u)) return BatchLiftStatus::invalid_memory;
    // 0x01220503: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122050b: f30f1105541d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1d54u)) return BatchLiftStatus::invalid_memory;
    // 0x01220513: 5d POP
        batch_guest_pc = 0x01220513u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220514: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
