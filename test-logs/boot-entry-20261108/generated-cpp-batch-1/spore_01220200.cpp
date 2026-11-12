#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01220200(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01220200u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01220200: 55 PUSH
        batch_guest_pc = 0x01220200u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01220201: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01220203: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122020b: f30f1105b4205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20b4u)) return BatchLiftStatus::invalid_memory;
    // 0x01220213: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122021b: f30f1105b8205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20b8u)) return BatchLiftStatus::invalid_memory;
    // 0x01220223: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122022b: f30f1105bc205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20bcu)) return BatchLiftStatus::invalid_memory;
    // 0x01220233: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122023b: f30f1105c0205d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d20c0u)) return BatchLiftStatus::invalid_memory;
    // 0x01220243: 5d POP
        batch_guest_pc = 0x01220243u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01220244: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
