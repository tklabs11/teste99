#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_013000d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x013000d0u);
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;

    // 0x013000d0: 68007c6601 PUSH
        t0a = 0x01667c00u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x013000d5: ff15d0c23c01 CALL
        t1_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSection", 0x013cc2d0u, 0x013000dbu);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x013000dbu) return BatchLiftStatus::invalid_control_flow;
    // 0x013000db: 68400d3c01 PUSH
        t2a = 0x013c0d40u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x013000e0: e80a07eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x013000e5u)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011e07ef(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x013000e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x013000e5: 59 POP
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t4a;
    // 0x013000e6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
