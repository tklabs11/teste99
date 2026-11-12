#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e2000(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_0121e1e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0121e1e0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0;

    // 0x0121e1e0: 55 PUSH
        batch_guest_pc = 0x0121e1e0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e1e1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x0121e1e3: b9b5155d01 MOV
        t2 = 0x015d15b5u;
        state.regs[1] = t2;
    // 0x0121e1e8: e8133efcff CALL
        if (!batch_guest_call32(memory, state, 0x011e2000u, 0x0121e1edu)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011e2000(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0121e1edu) return BatchLiftStatus::invalid_control_flow;
    // 0x0121e1ed: 6890c93b01 PUSH
        batch_guest_pc = 0x0121e1edu;
        t4a = 0x013bc990u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0121e1f2: e8f825fcff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0121e1f7u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011e07ef(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0121e1f7u) return BatchLiftStatus::invalid_control_flow;
    // 0x0121e1f7: 83c404 ADD
        t6a = state.regs[4];
        t6b = 0x00000004u;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x0121e1fa: 5d POP
        batch_guest_pc = 0x0121e1fau;
        if (!memory.load32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t7a;
    // 0x0121e1fb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
