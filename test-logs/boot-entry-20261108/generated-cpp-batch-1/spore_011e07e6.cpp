#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e07e6(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e07e6u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;

    // 0x011e07e6: 6a08 PUSH
        t0a = 0x00000008u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e07e8: e8d3090000 CALL
        t1_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_unlock", 0x013cc358u, 0x011e07edu);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x011e07edu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e07ed: 59 POP
        if (!memory.load32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t2a;
    // 0x011e07ee: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
