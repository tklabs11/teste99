#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01224460(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01224460u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01224460: 55 PUSH
        batch_guest_pc = 0x01224460u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01224461: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01224463: f30f1005fc285d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d28fcu)) return BatchLiftStatus::invalid_memory;
    // 0x0122446b: f30f1105f0285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d28f0u)) return BatchLiftStatus::invalid_memory;
    // 0x01224473: f30f100500295d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d2900u)) return BatchLiftStatus::invalid_memory;
    // 0x0122447b: f30f1105f4285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d28f4u)) return BatchLiftStatus::invalid_memory;
    // 0x01224483: f30f100504295d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d2904u)) return BatchLiftStatus::invalid_memory;
    // 0x0122448b: f30f1105f8285d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d28f8u)) return BatchLiftStatus::invalid_memory;
    // 0x01224493: 5d POP
        batch_guest_pc = 0x01224493u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01224494: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
