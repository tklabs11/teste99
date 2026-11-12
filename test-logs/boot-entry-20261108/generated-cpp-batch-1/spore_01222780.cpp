#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222780(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222780u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222780: 55 PUSH
        batch_guest_pc = 0x01222780u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222781: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222783: f30f1005b4235d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d23b4u)) return BatchLiftStatus::invalid_memory;
    // 0x0122278b: f30f1105a8235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23a8u)) return BatchLiftStatus::invalid_memory;
    // 0x01222793: f30f1005b8235d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d23b8u)) return BatchLiftStatus::invalid_memory;
    // 0x0122279b: f30f1105ac235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23acu)) return BatchLiftStatus::invalid_memory;
    // 0x012227a3: f30f1005bc235d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d23bcu)) return BatchLiftStatus::invalid_memory;
    // 0x012227ab: f30f1105b0235d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d23b0u)) return BatchLiftStatus::invalid_memory;
    // 0x012227b3: 5d POP
        batch_guest_pc = 0x012227b3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x012227b4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
