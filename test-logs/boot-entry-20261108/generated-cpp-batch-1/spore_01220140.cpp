#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220140(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220140u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01220140: 55 PUSH
        batch_guest_pc = 0x01220140u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220141: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220143: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122014b: f30f1105c4205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20c4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220153: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122015b: f30f1105c8205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20c8u)) return BatchLiftStatus::invalid_memory;
    // 0x01220163: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122016b: f30f1105cc205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20ccu)) return BatchLiftStatus::invalid_memory;
    // 0x01220173: 5d POP
        batch_guest_pc = 0x01220173u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01220174: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
