#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121f680(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121f680u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121f680: 55 PUSH
        batch_guest_pc = 0x0121f680u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121f681: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121f683: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f68b: f30f110514175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1714u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f693: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f69b: f30f110518175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6ab: f30f11051c175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d171cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6bb: f30f110520175d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1720u)) return BatchLiftStatus::invalid_memory;
    // 0x0121f6c3: 5d POP
        batch_guest_pc = 0x0121f6c3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121f6c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
