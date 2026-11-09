#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921df0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00921df0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00921df0: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00921df4: 8b08 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00921df6: 6a01 PUSH
        t2a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00921df8: 51 PUSH
        t3a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00921df9: ff157cc13c01 CALL
        t4_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!SleepEx", 0x013cc17cu, 0x00921dffu);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x00921dffu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921dff: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
