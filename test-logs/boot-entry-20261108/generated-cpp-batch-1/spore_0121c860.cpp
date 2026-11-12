#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121c860(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121c860u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121c860: 55 PUSH
        batch_guest_pc = 0x0121c860u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121c861: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121c863: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c86b: f30f1105f0145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14f0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c873: f30f10055c104701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x0147105cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c87b: f30f1105f4145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14f4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c883: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c88b: f30f1105f8145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14f8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c893: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121c89b: f30f1105fc145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121c8a3: 5d POP
        batch_guest_pc = 0x0121c8a3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121c8a4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
