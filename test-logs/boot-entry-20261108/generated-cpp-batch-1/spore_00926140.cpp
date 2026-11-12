#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926140(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926140u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;

    // 0x00926140: 8b442404 MOV
        batch_guest_pc = 0x00926140u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926144: ff4818 DEC
        batch_guest_pc = 0x00926144u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t1a)) return BatchLiftStatus::invalid_memory;
        t1r = static_cast<std::uint32_t>(t1a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t1a, t1r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t1r)) return BatchLiftStatus::invalid_memory;
    // 0x00926147: 56 PUSH
        batch_guest_pc = 0x00926147u;
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00926148: 8b7018 MOV
        batch_guest_pc = 0x00926148u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x0092614b: 50 PUSH
        batch_guest_pc = 0x0092614bu;
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092614c: ff15dcc23c01 CALL
        t5_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00926152u);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00926152u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926152: 8bc6 MOV
        t6 = state.regs[6];
        state.regs[0] = t6;
    // 0x00926154: 5e POP
        batch_guest_pc = 0x00926154u;
        if (!memory.load32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t7a;
    // 0x00926155: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
