#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926340(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926340u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00926340: 8b442404 MOV
        batch_guest_pc = 0x00926340u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926344: 50 PUSH
        batch_guest_pc = 0x00926344u;
        t1a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00926345: ff15d4c23c01 CALL
        t2_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!DeleteCriticalSection", 0x013cc2d4u, 0x0092634bu);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x0092634bu) return BatchLiftStatus::invalid_control_flow;
    // 0x0092634b: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
