#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e5830(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e5840(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e5850(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011eaaa0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011eaaa0u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;

    // 0x011eaaa0: 6860d61e01 PUSH
        batch_guest_pc = 0x011eaaa0u;
        t0a = 0x011ed660u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaaa5: e886adffff CALL
        if (!batch_guest_call32(memory, state, 0x011e5830u, 0x011eaaaau)) return BatchLiftStatus::invalid_memory;
        t1_call_status = spore_lift_011e5830(memory, state);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x011eaaaau) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaaaa: 6870d61e01 PUSH
        batch_guest_pc = 0x011eaaaau;
        t2a = 0x011ed670u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaaaf: e88cadffff CALL
        if (!batch_guest_call32(memory, state, 0x011e5840u, 0x011eaab4u)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011e5840(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x011eaab4u) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaab4: 6880d61e01 PUSH
        batch_guest_pc = 0x011eaab4u;
        t4a = 0x011ed680u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaab9: e892adffff CALL
        if (!batch_guest_call32(memory, state, 0x011e5850u, 0x011eaabeu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011e5850(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x011eaabeu) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaabe: 83c40c ADD
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x011eaac1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
