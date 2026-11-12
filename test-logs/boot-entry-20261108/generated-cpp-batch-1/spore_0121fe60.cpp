#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e2000(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121fe60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121fe60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;

    // 0x0121fe60: 55 PUSH
        batch_guest_pc = 0x0121fe60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121fe63: b9a4195d01 MOV
        t2 = 0x015d19a4u;
        state.regs[1] = t2;
    // 0x0121fe68: e89321fcff CALL
        if (!batch_guest_call32(memory, state, 0x011e2000u, 0x0121fe6du)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011e2000(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0121fe6du) return BatchLiftStatus::invalid_control_flow;
    // 0x0121fe6d: 68b0c93b01 PUSH
        batch_guest_pc = 0x0121fe6du;
        t4a = 0x013bc9b0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121fe72: e87809fcff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0121fe77u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011e07ef(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121fe77u) return BatchLiftStatus::invalid_control_flow;
    // 0x0121fe77: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121fe7a: 5d POP
        batch_guest_pc = 0x0121fe7au;
        if (!memory.load32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t7a;
    // 0x0121fe7b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
