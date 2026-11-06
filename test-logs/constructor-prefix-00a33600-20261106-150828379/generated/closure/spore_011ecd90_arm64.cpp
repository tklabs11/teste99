#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011ecd90(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;

    // 0x011ecd90: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011ecd91: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x011ecd93: 8d4604 LEA
        t2 = static_cast<std::uint32_t>(state.regs[6] + 0x00000004u);
        state.regs[0] = t2;
    // 0x011ecd96: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011ecd97: ff15d0c23c01 CALL
        t4_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSection", 0x013cc2d0u, 0x011ecd9du);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x011ecd9du) return BatchLiftStatus::invalid_control_flow;
    // 0x011ecd9d: c70601000000 MOV
        t5 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x011ecda3: 5e POP
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t6a;
    // 0x011ecda4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
