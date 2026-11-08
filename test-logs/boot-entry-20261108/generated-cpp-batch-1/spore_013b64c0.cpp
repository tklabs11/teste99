#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_013b64c0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    BatchLiftStatus t1_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;

    // 0x013b64c0: 68984e6f01 PUSH
        t0a = 0x016f4e98u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x013b64c5: ff15d0c23c01 CALL
        t1_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSection", 0x013cc2d0u, 0x013b64cbu);
        if (t1_call_status != BatchLiftStatus::returned) return t1_call_status;
        if (state.eip != 0x013b64cbu) return BatchLiftStatus::invalid_control_flow;
    // 0x013b64cb: 6820b63c01 PUSH
        t2a = 0x013cb620u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x013b64d0: e81aa3e2ff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x013b64d5u)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_011e07ef(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x013b64d5u) return BatchLiftStatus::invalid_control_flow;
    // 0x013b64d5: 59 POP
        if (!memory.load32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t4a;
    // 0x013b64d6: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
