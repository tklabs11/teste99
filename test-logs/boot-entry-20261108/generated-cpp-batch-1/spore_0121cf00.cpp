#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_004013f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121cf00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121cf00u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;

    // 0x0121cf00: 55 PUSH
        batch_guest_pc = 0x0121cf00u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf01: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121cf03: 83ec10 SUB
        t2a = state.regs[4];
        t2b = 0x00000010u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x0121cf06: 8d45f0 LEA
        t3 = static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u);
        state.regs[0] = t3;
    // 0x0121cf09: 50 PUSH
        batch_guest_pc = 0x0121cf09u;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf0a: e8e1441eff CALL
        if (!batch_guest_call32(memory, state, 0x004013f0u, 0x0121cf0fu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_004013f0(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121cf0fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121cf0f: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121cf12: f30f1045f0 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff0u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cf17: f30f110594145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1494u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf1f: f30f1045f4 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cf24: f30f110598145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d1498u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf2c: f30f1045f8 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u))) return BatchLiftStatus::invalid_memory;
    // 0x0121cf31: f30f11059c145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d149cu)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf39: f30f1045fc MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu))) return BatchLiftStatus::invalid_memory;
    // 0x0121cf3e: f30f1105a0145d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d14a0u)) return BatchLiftStatus::invalid_memory;
    // 0x0121cf46: 8be5 MOV
        t15 = state.regs[5];
        state.regs[4] = t15;
    // 0x0121cf48: 5d POP
        batch_guest_pc = 0x0121cf48u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t16a;
    // 0x0121cf49: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
