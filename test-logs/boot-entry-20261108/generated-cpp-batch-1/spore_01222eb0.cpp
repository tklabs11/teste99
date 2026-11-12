#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222eb0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222eb0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222eb0: 55 PUSH
        batch_guest_pc = 0x01222eb0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222eb1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222eb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ebb: f30f1105d4215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21d4u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ec3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ecb: f30f1105d8215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21d8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ed3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222edb: f30f1105dc215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21dcu)) return BatchLiftStatus::invalid_memory;
    // 0x01222ee3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01222eeb: f30f1105e0215d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d21e0u)) return BatchLiftStatus::invalid_memory;
    // 0x01222ef3: 5d POP
        batch_guest_pc = 0x01222ef3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222ef4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
