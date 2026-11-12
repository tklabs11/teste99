#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00924270(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924270u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13 = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t19 = 0;

    // 0x00924270: 8b542404 MOV
        batch_guest_pc = 0x00924270u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00924274: f6420801 TEST
        batch_guest_pc = 0x00924274u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000001u;
        t1r = (t1a & t1b) & 0x000000ffu;
        batch_set_logic_flags(state, t1r, 8u);
    // 0x00924278: 8bc1 MOV
        t2 = state.regs[1];
        state.regs[0] = t2;
    // 0x0092427a: 7424 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242a0;
    // 0x0092427c: 80780c00 CMP
        batch_guest_pc = 0x0092427cu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000000u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0x000000ffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 8u);
    // 0x00924280: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242a0;
    // 0x00924282: 8b4804 MOV
        batch_guest_pc = 0x00924282u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00924285: 85c9 TEST
        t7a = state.regs[1];
        t7b = state.regs[1];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x00924287: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242a0;
    // 0x00924289: 83780800 CMP
        batch_guest_pc = 0x00924289u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = 0x00000000u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x0092428d: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242a0;
    // 0x0092428f: 8b01 MOV
        batch_guest_pc = 0x0092428fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00924291: 52 PUSH
        batch_guest_pc = 0x00924291u;
        t12a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00924292: 8b5014 MOV
        batch_guest_pc = 0x00924292u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000014u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t13;
    // 0x00924295: ffd2 CALL
        t14_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x00924297u);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
    // 0x00924297: 84c0 TEST
        t15a = state.regs[0] & 0x000000ffu;
        t15b = state.regs[0] & 0x000000ffu;
        t15r = (t15a & t15b) & 0x000000ffu;
        batch_set_logic_flags(state, t15r, 8u);
    // 0x00924299: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009242a0;
    // 0x0092429b: 33c0 XOR
        t17a = state.regs[0];
        t17b = state.regs[0];
        t17r = (t17a ^ t17b) & 0xffffffffu;
        batch_set_logic_flags(state, t17r, 32u);
        state.regs[0] = t17r;
    // 0x0092429d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009242a0: b801000000 MOV
    L_009242a0:
        t19 = 0x00000001u;
        state.regs[0] = t19;
    // 0x009242a5: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
