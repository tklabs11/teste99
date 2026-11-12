#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004013f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121cd50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121cd50u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;

    // 0x0121cd50: 55 PUSH
        batch_guest_pc = 0x0121cd50u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd51: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121cd53: 83ec10 SUB
        t2a = state.regs[4];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121cd56: 8d45f0 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[0] = t3;
    // 0x0121cd59: 50 PUSH
        batch_guest_pc = 0x0121cd59u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd5a: e891461eff CALL
        if (!batch_guest_call32(memory, state, 0x004013f0u, 0x0121cd5fu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_004013f0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121cd5fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121cd5f: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121cd62: f30f1045f0 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cd67: f30f1105cc125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12ccu)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd6f: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cd74: f30f1105d0125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12d0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd7c: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cd81: f30f1105d4125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12d4u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd89: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121cd8e: f30f1105d8125d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d12d8u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cd96: 8be5 MOV
        t15 = state.regs[5];
        state.regs[4] = t15;
    // 0x0121cd98: 5d POP
        batch_guest_pc = 0x0121cd98u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t16a;
    // 0x0121cd99: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
