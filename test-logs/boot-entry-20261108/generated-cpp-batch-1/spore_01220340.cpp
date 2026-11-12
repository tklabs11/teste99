#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220340(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220340u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220340: 55 PUSH
        batch_guest_pc = 0x01220340u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220341: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220343: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122034b: f30f110520205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2020u)) return BatchLiftStatus::invalid_memory;
    // 0x01220353: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122035b: f30f110524205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2024u)) return BatchLiftStatus::invalid_memory;
    // 0x01220363: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122036b: f30f110528205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2028u)) return BatchLiftStatus::invalid_memory;
    // 0x01220373: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122037b: f30f11052c205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d202cu)) return BatchLiftStatus::invalid_memory;
    // 0x01220383: 5d POP
        batch_guest_pc = 0x01220383u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220384: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
