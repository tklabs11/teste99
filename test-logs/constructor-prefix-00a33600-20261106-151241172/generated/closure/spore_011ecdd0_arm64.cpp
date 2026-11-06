#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011ecdd0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011ecdd0: 833900 CMP
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
    // 0x011ecdd3: 740a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011ecddf;
    // 0x011ecdd5: 83c104 ADD
        t2a = state.regs[1];
        t2b = 0x00000004u;
        t2r = static_cast<std::uint32_t>(t2a + t2b) & 0xffffffffu;
        batch_set_add_flags(state, t2a, t2b, t2r, 32u);
        state.regs[1] = t2r;
    // 0x011ecdd8: 51 PUSH
        t3a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011ecdd9: ff15d8c23c01 CALL
        t4_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!EnterCriticalSection", 0x013cc2d8u, 0x011ecddfu);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x011ecddfu) return BatchLiftStatus::invalid_control_flow;
    // 0x011ecddf: c3 RET
    L_011ecddf:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
