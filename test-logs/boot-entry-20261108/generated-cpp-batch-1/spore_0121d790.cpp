#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d790(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d790u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121d790: 55 PUSH
        batch_guest_pc = 0x0121d790u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d791: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d793: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d79b: f30f1105a4115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11a4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7a3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7ab: f30f1105a8115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11a8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7bb: f30f1105ac115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11acu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7cb: f30f1105b0115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11b0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d7d3: 5d POP
        batch_guest_pc = 0x0121d7d3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121d7d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
