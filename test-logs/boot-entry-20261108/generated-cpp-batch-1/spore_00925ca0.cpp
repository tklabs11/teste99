#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009276c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925ca0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925ca0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00925ca0: 8b442404 MOV
        batch_guest_pc = 0x00925ca0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925ca4: 8b4904 MOV
        batch_guest_pc = 0x00925ca4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00925ca7: 50 PUSH
        batch_guest_pc = 0x00925ca7u;
        t2a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00925ca8: e8131a0000 CALL
        if (!batch_guest_call32(memory, state, 0x009276c0u, 0x00925cadu)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_009276c0(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x00925cadu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925cad: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
