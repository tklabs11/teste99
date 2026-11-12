#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220250(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220250u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220250: 55 PUSH
        batch_guest_pc = 0x01220250u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220251: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220253: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122025b: f30f1105381e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e38u)) return BatchLiftStatus::invalid_memory;
    // 0x01220263: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122026b: f30f11053c1e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e3cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220273: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122027b: f30f1105401e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e40u)) return BatchLiftStatus::invalid_memory;
    // 0x01220283: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122028b: f30f1105441e5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1e44u)) return BatchLiftStatus::invalid_memory;
    // 0x01220293: 5d POP
        batch_guest_pc = 0x01220293u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220294: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
