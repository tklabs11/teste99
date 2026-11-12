#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221380(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221380u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221380: 55 PUSH
        batch_guest_pc = 0x01221380u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221381: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221383: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122138b: f30f11054c1c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c4cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221393: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122139b: f30f1105501c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c50u)) return BatchLiftStatus::invalid_memory;
    // 0x012213a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012213ab: f30f1105541c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c54u)) return BatchLiftStatus::invalid_memory;
    // 0x012213b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012213bb: f30f1105581c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1c58u)) return BatchLiftStatus::invalid_memory;
    // 0x012213c3: 5d POP
        batch_guest_pc = 0x012213c3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x012213c4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
