#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222000(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222000u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01222000: 55 PUSH
        batch_guest_pc = 0x01222000u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222001: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222003: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x0122200b: f30f110508245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2408u)) return BatchLiftStatus::invalid_memory;
    // 0x01222013: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122201b: f30f11050c245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d240cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222023: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122202b: f30f110510245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2410u)) return BatchLiftStatus::invalid_memory;
    // 0x01222033: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x0122203b: f30f110514245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2414u)) return BatchLiftStatus::invalid_memory;
    // 0x01222043: 5d POP
        batch_guest_pc = 0x01222043u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01222044: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
