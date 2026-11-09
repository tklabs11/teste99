#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e12a2(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e1304(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e1304u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;

    // 0x011e1304: e899ffffff CALL
        if (!batch_guest_call32(memory, state, 0x011e12a2u, 0x011e1309u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_011e12a2(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x011e1309u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1309: a354e77101 MOV
        t1 = state.regs[0];
        if (!memory.store32(0x0171e754u, t1)) return BatchLiftStatus::invalid_memory;
    // 0x011e130e: 33c0 XOR
        t2a = state.regs[0];
        t2b = state.regs[0];
        t2r = (t2a ^ t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[0] = t2r;
    // 0x011e1310: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
