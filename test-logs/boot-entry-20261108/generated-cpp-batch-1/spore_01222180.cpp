#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222180(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222180u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222180: 55 PUSH
        batch_guest_pc = 0x01222180u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222181: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222183: f30f100594b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb194u)) return BatchLiftStatus::invalid_memory;
    // 0x0122218b: f30f11055c265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d265cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222193: f30f100590b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb190u)) return BatchLiftStatus::invalid_memory;
    // 0x0122219b: f30f110560265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2660u)) return BatchLiftStatus::invalid_memory;
    // 0x012221a3: f30f10058cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb18cu)) return BatchLiftStatus::invalid_memory;
    // 0x012221ab: f30f110564265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2664u)) return BatchLiftStatus::invalid_memory;
    // 0x012221b3: 5d POP
        batch_guest_pc = 0x012221b3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012221b4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
