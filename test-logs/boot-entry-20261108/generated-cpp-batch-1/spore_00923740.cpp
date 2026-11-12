#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923740(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923740u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;

    // 0x00923740: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00923742: 80780c00 CMP
        batch_guest_pc = 0x00923742u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t1a)) return BatchLiftStatus::invalid_memory;
        t1b = 0x00000000u;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0x000000ffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 8u);
    // 0x00923746: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092376a;
    // 0x00923748: 8b4804 MOV
        batch_guest_pc = 0x00923748u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t3;
    // 0x0092374b: 85c9 TEST
        t4a = state.regs[1];
        t4b = state.regs[1];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x0092374d: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092376a;
    // 0x0092374f: 83780800 CMP
        batch_guest_pc = 0x0092374fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t6a)) return BatchLiftStatus::invalid_memory;
        t6b = 0x00000000u;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x00923753: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_0092376a;
    // 0x00923755: 8b01 MOV
        batch_guest_pc = 0x00923755u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00923757: 8b542404 MOV
        batch_guest_pc = 0x00923757u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x0092375b: 8b4010 MOV
        batch_guest_pc = 0x0092375bu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x0092375e: 52 PUSH
        batch_guest_pc = 0x0092375eu;
        t11a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x0092375f: ffd0 CALL
        t12_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923761u);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
    // 0x00923761: 84c0 TEST
        t13a = state.regs[0] & 0x000000ffu;
        t13b = state.regs[0] & 0x000000ffu;
        t13r = (t13a & t13b) & 0x000000ffu;
        batch_set_logic_flags(state, t13r, 8u);
    // 0x00923763: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092376a;
    // 0x00923765: 33c0 XOR
        t15a = state.regs[0];
        t15b = state.regs[0];
        t15r = (t15a ^ t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
        state.regs[0] = t15r;
    // 0x00923767: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092376a: b801000000 MOV
    L_0092376a:
        t17 = 0x00000001u;
        state.regs[0] = t17;
    // 0x0092376f: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
