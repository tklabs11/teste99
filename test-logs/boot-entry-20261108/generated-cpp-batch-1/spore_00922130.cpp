#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00922130(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00922130u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00922130: 80792400 CMP
        batch_guest_pc = 0x00922130u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000024u), t0a)) return BatchLiftStatus::invalid_memory;
        t0b = 0x00000000u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0x000000ffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 8u);
    // 0x00922134: 7408 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092213e;
    // 0x00922136: 51 PUSH
        batch_guest_pc = 0x00922136u;
        t2a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00922137: ff15d4c23c01 CALL
        t3_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!DeleteCriticalSection", 0x013cc2d4u, 0x0092213du);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x0092213du) return BatchLiftStatus::invalid_control_flow;
    // 0x0092213d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092213e: 8b01 MOV
    L_0092213e:
        batch_guest_pc = 0x0092213eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00922140: 50 PUSH
        batch_guest_pc = 0x00922140u;
        t6a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00922141: ff15c4c03c01 CALL
        t7_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!CloseHandle", 0x013cc0c4u, 0x00922147u);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00922147u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922147: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
