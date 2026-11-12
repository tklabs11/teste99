#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926100(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926100u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;

    // 0x00926100: 56 PUSH
        batch_guest_pc = 0x00926100u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00926101: 8b742408 MOV
        batch_guest_pc = 0x00926101u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t1;
    // 0x00926105: 33c0 XOR
        t2a = state.regs[0];
        t2b = state.regs[0];
        t2r = (t2a ^ t2b) & 0xffffffffu;
        batch_set_logic_flags(state, t2r, 32u);
        state.regs[0] = t2r;
    // 0x00926107: 3bf0 CMP
        t3a = state.regs[6];
        t3b = state.regs[0];
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x00926109: 740e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926119;
    // 0x0092610b: 6a0a PUSH
        batch_guest_pc = 0x0092610bu;
        t5a = 0x0000000au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092610d: 56 PUSH
        batch_guest_pc = 0x0092610du;
        t6a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092610e: 894618 MOV
        batch_guest_pc = 0x0092610eu;
        t7 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00926111: ff15c0c13c01 CALL
        t8_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!InitializeCriticalSectionAndSpinCount", 0x013cc1c0u, 0x00926117u);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x00926117u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926117: 8bc6 MOV
        t9 = state.regs[6];
        state.regs[0] = t9;
    // 0x00926119: 5e POP
    L_00926119:
        batch_guest_pc = 0x00926119u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x0092611a: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
