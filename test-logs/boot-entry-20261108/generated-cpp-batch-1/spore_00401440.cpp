#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00401440(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401440u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;

    // 0x00401440: 55 PUSH
        batch_guest_pc = 0x00401440u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00401441: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00401443: 8b4508 MOV
        batch_guest_pc = 0x00401443u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00401446: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0040144e: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401452: 8b4d08 MOV
        batch_guest_pc = 0x00401452u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00401455: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0040145d: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00401462: 8b5508 MOV
        batch_guest_pc = 0x00401462u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00401465: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0040146d: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00401472: 8b4508 MOV
        batch_guest_pc = 0x00401472u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00401475: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0040147d: f30f11400c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00401482: 8b4508 MOV
        batch_guest_pc = 0x00401482u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00401485: 5d POP
        batch_guest_pc = 0x00401485u;
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t15a;
    // 0x00401486: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
