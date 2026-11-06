#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00b8dab0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00bb9b70(BatchLiftMemory& memory, BatchLiftState& state) {
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;

    // 0x00bb9b70: e83b3ffdff CALL
        if (!batch_guest_call32(memory, state, 0x00b8dab0u, 0x00bb9b75u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_00b8dab0(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x00bb9b75u) return BatchLiftStatus::invalid_control_flow;
    // 0x00bb9b75: 83f805 CMP
        t1a = state.regs[0];
        t1b = 0x00000005u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00bb9b78: 0f94c0 SETZ
        state.regs[0] = (state.regs[0] & 0xffffff00u) | (((((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x00bb9b7b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
