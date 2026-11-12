#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224b90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224b90u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01224b90: 55 PUSH
        batch_guest_pc = 0x01224b90u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224b91: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224b93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224b9b: f30f110520275d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2720u)) return BatchLiftStatus::invalid_memory;
    // 0x01224ba3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224bab: f30f110524275d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2724u)) return BatchLiftStatus::invalid_memory;
    // 0x01224bb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224bbb: f30f110528275d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2728u)) return BatchLiftStatus::invalid_memory;
    // 0x01224bc3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01224bcb: f30f11052c275d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d272cu)) return BatchLiftStatus::invalid_memory;
    // 0x01224bd3: 5d POP
        batch_guest_pc = 0x01224bd3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01224bd4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
