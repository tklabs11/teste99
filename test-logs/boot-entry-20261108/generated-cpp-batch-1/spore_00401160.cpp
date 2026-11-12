#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00401160(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401160u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;

    // 0x00401160: 55 PUSH
        batch_guest_pc = 0x00401160u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00401161: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00401163: 8b4508 MOV
        batch_guest_pc = 0x00401163u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00401166: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0040116e: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401172: 8b4d08 MOV
        batch_guest_pc = 0x00401172u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t5;
    // 0x00401175: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0040117d: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00401182: 8b4508 MOV
        batch_guest_pc = 0x00401182u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00401185: 5d POP
        batch_guest_pc = 0x00401185u;
        if (!memory.load32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t9a;
    // 0x00401186: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
