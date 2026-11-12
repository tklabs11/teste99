#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221f40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221f40u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221f40: 55 PUSH
        batch_guest_pc = 0x01221f40u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221f41: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221f43: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f4b: f30f110540255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2540u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f53: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f5b: f30f110544255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2544u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f63: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f6b: f30f110548255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2548u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f73: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221f7b: f30f11054c255d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d254cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221f83: 5d POP
        batch_guest_pc = 0x01221f83u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221f84: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
