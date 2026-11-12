#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121adc0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121adc0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x0121adc0: 55 PUSH
        batch_guest_pc = 0x0121adc0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121adc1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121adc3: f30f100588b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb188u)) return BatchLiftStatus::invalid_memory;
    // 0x0121adcb: f30f1105880d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d88u)) return BatchLiftStatus::invalid_memory;
    // 0x0121add3: f30f100584b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb184u)) return BatchLiftStatus::invalid_memory;
    // 0x0121addb: f30f11058c0d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d8cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121ade3: f30f100580b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb180u)) return BatchLiftStatus::invalid_memory;
    // 0x0121adeb: f30f1105900d5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0d90u)) return BatchLiftStatus::invalid_memory;
    // 0x0121adf3: 5d POP
        batch_guest_pc = 0x0121adf3u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x0121adf4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
