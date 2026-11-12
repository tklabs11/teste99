#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_012203e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x012203e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x012203e0: 55 PUSH
        batch_guest_pc = 0x012203e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x012203e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x012203e3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012203eb: f30f1105c81f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fc8u)) return BatchLiftStatus::invalid_memory;
    // 0x012203f3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012203fb: f30f1105cc1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fccu)) return BatchLiftStatus::invalid_memory;
    // 0x01220403: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122040b: f30f1105d01f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fd0u)) return BatchLiftStatus::invalid_memory;
    // 0x01220413: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122041b: f30f1105d41f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fd4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220423: 5d POP
        batch_guest_pc = 0x01220423u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220424: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
