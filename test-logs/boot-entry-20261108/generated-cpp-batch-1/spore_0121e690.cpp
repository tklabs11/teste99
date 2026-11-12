#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121e690(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e690u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121e690: 55 PUSH
        batch_guest_pc = 0x0121e690u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e691: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e693: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e69b: f30f1105d81a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ad8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6ab: f30f1105dc1a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1adcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6bb: f30f1105e01a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ae0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6cb: f30f1105e41a5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1ae4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121e6d3: 5d POP
        batch_guest_pc = 0x0121e6d3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121e6d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
