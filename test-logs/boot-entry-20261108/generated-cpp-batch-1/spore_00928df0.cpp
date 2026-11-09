#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00928df0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00928df0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;

    // 0x00928df0: 83ec24 SUB
        t0a = state.regs[4];
        t0b = 0x00000024u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00928df3: 8d0424 LEA
        t1 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[0] = t1;
    // 0x00928df6: 50 PUSH
        t2a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00928df7: ff15dcc03c01 CALL
        t3_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetSystemInfo", 0x013cc0dcu, 0x00928dfdu);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x00928dfdu) return BatchLiftStatus::invalid_control_flow;
    // 0x00928dfd: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00928e01: 83c424 ADD
        t5a = state.regs[4];
        t5b = 0x00000024u;
        t5r = static_cast<std::uint32_t>(t5a + t5b) & 0xffffffffu;
        batch_set_add_flags(state, t5a, t5b, t5r, 32u);
        state.regs[4] = t5r;
    // 0x00928e04: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
