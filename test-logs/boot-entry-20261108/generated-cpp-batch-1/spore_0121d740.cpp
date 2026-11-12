#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121d740(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121d740u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121d740: 55 PUSH
        batch_guest_pc = 0x0121d740u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121d741: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121d743: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d74b: f30f1105b4115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11b4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d753: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d75b: f30f1105b8115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11b8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d763: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d76b: f30f1105bc115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11bcu)) return BatchLiftStatus::invalid_memory;
    // 0x0121d773: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d77b: f30f1105c0115d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d11c0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121d783: 5d POP
        batch_guest_pc = 0x0121d783u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121d784: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
