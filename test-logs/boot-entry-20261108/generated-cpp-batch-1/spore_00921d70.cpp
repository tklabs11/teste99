#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921d70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921d70u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00921d70: ff15b0c03c01 CALL
        t0_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetCurrentThread", 0x013cc0b0u, 0x00921d76u);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x00921d76u) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d76: 50 PUSH
        t1a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921d77: ff15acc03c01 CALL
        t2_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetThreadPriority", 0x013cc0acu, 0x00921d7du);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x00921d7du) return BatchLiftStatus::invalid_control_flow;
    // 0x00921d7d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
