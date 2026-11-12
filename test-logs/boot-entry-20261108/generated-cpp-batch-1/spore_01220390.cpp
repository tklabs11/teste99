#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220390(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220390u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220390: 55 PUSH
        batch_guest_pc = 0x01220390u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220391: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220393: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122039b: f30f1105e01f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fe0u)) return BatchLiftStatus::invalid_memory;
    // 0x012203a3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x012203ab: f30f1105e41f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fe4u)) return BatchLiftStatus::invalid_memory;
    // 0x012203b3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012203bb: f30f1105e81f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fe8u)) return BatchLiftStatus::invalid_memory;
    // 0x012203c3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x012203cb: f30f1105ec1f5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1fecu)) return BatchLiftStatus::invalid_memory;
    // 0x012203d3: 5d POP
        batch_guest_pc = 0x012203d3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x012203d4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
