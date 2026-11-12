#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00924350(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924350u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;

    // 0x00924350: 8b542404 MOV
        batch_guest_pc = 0x00924350u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00924354: f6420802 TEST
        batch_guest_pc = 0x00924354u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000002u;
        t1r = (t1a & t1b) & 0x000000ffu;
        batch_set_logic_flags(state, t1r, 8u);
    // 0x00924358: 7428 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924382;
    // 0x0092435a: 80790c00 CMP
        batch_guest_pc = 0x0092435au;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000000u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0x000000ffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 8u);
    // 0x0092435e: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924382;
    // 0x00924360: 8b4104 MOV
        batch_guest_pc = 0x00924360u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t5;
    // 0x00924363: 85c0 TEST
        t6a = state.regs[0];
        t6b = state.regs[0];
        t6r = (t6a & t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
    // 0x00924365: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924382;
    // 0x00924367: 83790800 CMP
        batch_guest_pc = 0x00924367u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t8a)) return BatchLiftStatus::invalid_memory;
        t8b = 0x00000000u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
    // 0x0092436b: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00924382;
    // 0x0092436d: 56 PUSH
        batch_guest_pc = 0x0092436du;
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x0092436e: 8b30 MOV
        batch_guest_pc = 0x0092436eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x00924370: 8bc8 MOV
        t12 = state.regs[0];
        state.regs[1] = t12;
    // 0x00924372: 8b4614 MOV
        batch_guest_pc = 0x00924372u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x00924375: 52 PUSH
        batch_guest_pc = 0x00924375u;
        t14a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00924376: ffd0 CALL
        t15_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00924378u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
    // 0x00924378: 5e POP
        batch_guest_pc = 0x00924378u;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x00924379: 84c0 TEST
        t17a = state.regs[0] & 0x000000ffu;
        t17b = state.regs[0] & 0x000000ffu;
        t17r = (t17a & t17b) & 0x000000ffu;
        batch_set_logic_flags(state, t17r, 8u);
    // 0x0092437b: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00924382;
    // 0x0092437d: 33c0 XOR
        t19a = state.regs[0];
        t19b = state.regs[0];
        t19r = (t19a ^ t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[0] = t19r;
    // 0x0092437f: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00924382: b801000000 MOV
    L_00924382:
        t21 = 0x00000001u;
        state.regs[0] = t21;
    // 0x00924387: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
