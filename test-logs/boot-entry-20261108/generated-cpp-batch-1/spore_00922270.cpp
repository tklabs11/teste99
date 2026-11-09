#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00922270(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00922270u);
    std::uint32_t t0a = 0, t0r = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;

    // 0x00922270: ff4920 DEC
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000020u), t0a)) return BatchLiftStatus::invalid_memory;
        t0r = static_cast<std::uint32_t>(t0a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t0a, t0r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000020u), t0r)) return BatchLiftStatus::invalid_memory;
    // 0x00922273: 80792400 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000024u), t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000000u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0x000000ffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 8u);
    // 0x00922277: 56 PUSH
        t2a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00922278: 8b7120 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000020u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t3;
    // 0x0092227b: 740b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00922288;
    // 0x0092227d: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092227e: ff15dcc23c01 CALL
        t6_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!LeaveCriticalSection", 0x013cc2dcu, 0x00922284u);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x00922284u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922284: 8bc6 MOV
        t7 = state.regs[6];
        state.regs[0] = t7;
    // 0x00922286: 5e POP
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t8a;
    // 0x00922287: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00922288: 8b01 MOV
    L_00922288:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x0092228a: 50 PUSH
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0092228b: ff158cc13c01 CALL
        t12_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!ReleaseMutex", 0x013cc18cu, 0x00922291u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00922291u) return BatchLiftStatus::invalid_control_flow;
    // 0x00922291: 8bc6 MOV
        t13 = state.regs[6];
        state.regs[0] = t13;
    // 0x00922293: 5e POP
        if (!memory.load32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t14a;
    // 0x00922294: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
