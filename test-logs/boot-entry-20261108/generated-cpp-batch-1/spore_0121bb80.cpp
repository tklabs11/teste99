#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0121bb80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121bb80u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x0121bb80: 55 PUSH
        batch_guest_pc = 0x0121bb80u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb81: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121bb83: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb8b: f30f1105680c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c68u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb93: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bb9b: f30f11056c0c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c6cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121bba3: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbab: f30f1105700c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c70u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbb3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbbb: f30f1105740c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d0c74u)) return BatchLiftStatus::invalid_memory;
    // 0x0121bbc3: 5d POP
        batch_guest_pc = 0x0121bbc3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x0121bbc4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
