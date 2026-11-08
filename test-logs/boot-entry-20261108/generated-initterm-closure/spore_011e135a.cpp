#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e135a(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;

    // 0x011e135a: 6818131e01 PUSH
        t0a = 0x011e1318u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e135f: ff1550c13c01 CALL
        t1_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SetUnhandledExceptionFilter", 0x013cc150u, 0x011e1365u);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x011e1365u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1365: 33c0 XOR
        t2a = state.regs[0];
        t2b = state.regs[0];
        t2r = (t2a ^ t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[0] = t2r;
    // 0x011e1367: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
