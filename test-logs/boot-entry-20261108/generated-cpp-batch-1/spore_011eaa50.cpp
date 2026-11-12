#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011ed320(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011ed330(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011ed340(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011eaa50(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011eaa50u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;

    // 0x011eaa50: 6830d61e01 PUSH
        batch_guest_pc = 0x011eaa50u;
        t0a = 0x011ed630u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaa55: e8c6280000 CALL
        if (!batch_guest_call32(memory, state, 0x011ed320u, 0x011eaa5au)) return BatchLiftStatus::invalid_memory;
        t1_call_status = spore_lift_011ed320(memory, state);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x011eaa5au) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaa5a: 6840d61e01 PUSH
        batch_guest_pc = 0x011eaa5au;
        t2a = 0x011ed640u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaa5f: e8cc280000 CALL
        if (!batch_guest_call32(memory, state, 0x011ed330u, 0x011eaa64u)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011ed330(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x011eaa64u) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaa64: 6850d61e01 PUSH
        batch_guest_pc = 0x011eaa64u;
        t4a = 0x011ed650u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x011eaa69: e8d2280000 CALL
        if (!batch_guest_call32(memory, state, 0x011ed340u, 0x011eaa6eu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011ed340(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x011eaa6eu) return BatchLiftStatus::invalid_control_flow;
    // 0x011eaa6e: 83c40c ADD
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x011eaa71: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
