#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_004011c0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004011c0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;

    // 0x004011c0: 55 PUSH
        batch_guest_pc = 0x004011c0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004011c1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004011c3: 8b4508 MOV
        batch_guest_pc = 0x004011c3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x004011c6: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x004011ce: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x004011d2: 8b4d08 MOV
        batch_guest_pc = 0x004011d2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x004011d5: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004011dd: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x004011e2: 8b5508 MOV
        batch_guest_pc = 0x004011e2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x004011e5: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004011ed: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004011f2: 8b4508 MOV
        batch_guest_pc = 0x004011f2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x004011f5: 5d POP
        batch_guest_pc = 0x004011f5u;
        if (!memory.load32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t12a;
    // 0x004011f6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
