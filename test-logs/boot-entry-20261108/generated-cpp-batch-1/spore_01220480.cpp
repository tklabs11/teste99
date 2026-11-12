#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220480(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220480u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220480: 55 PUSH
        batch_guest_pc = 0x01220480u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220481: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220483: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122048b: f30f1105881f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f88u)) return BatchLiftStatus::invalid_memory;
    // 0x01220493: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0122049b: f30f11058c1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f8cu)) return BatchLiftStatus::invalid_memory;
    // 0x012204a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012204ab: f30f1105901f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f90u)) return BatchLiftStatus::invalid_memory;
    // 0x012204b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012204bb: f30f1105941f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1f94u)) return BatchLiftStatus::invalid_memory;
    // 0x012204c3: 5d POP
        batch_guest_pc = 0x012204c3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x012204c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
