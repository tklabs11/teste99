#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00924390(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924390u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20a = 0, t20b = 0, t20r = 0;
    std::uint32_t t22 = 0;

    // 0x00924390: 8b542404 MOV
        batch_guest_pc = 0x00924390u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00924394: 8b420c MOV
        batch_guest_pc = 0x00924394u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00924397: f6400802 TEST
        batch_guest_pc = 0x00924397u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = 0x00000002u;
        t2r = (t2a & t2b) & 0x000000ffu;
        batch_set_logic_flags(state, t2r, 8u);
    // 0x0092439b: 7428 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009243c5;
    // 0x0092439d: 80790c00 CMP
        batch_guest_pc = 0x0092439du;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = 0x00000000u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0x000000ffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 8u);
    // 0x009243a1: 7422 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009243c5;
    // 0x009243a3: 8b4104 MOV
        batch_guest_pc = 0x009243a3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x009243a6: 85c0 TEST
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x009243a8: 741b JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009243c5;
    // 0x009243aa: 83790800 CMP
        batch_guest_pc = 0x009243aau;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t9a)) return BatchLiftStatus::invalid_memory;
        t9b = 0x00000000u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x009243ae: 7415 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009243c5;
    // 0x009243b0: 56 PUSH
        batch_guest_pc = 0x009243b0u;
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x009243b1: 8b30 MOV
        batch_guest_pc = 0x009243b1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x009243b3: 52 PUSH
        batch_guest_pc = 0x009243b3u;
        t13a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009243b4: 8b5610 MOV
        batch_guest_pc = 0x009243b4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x009243b7: 8bc8 MOV
        t15 = state.regs[0];
        state.regs[1] = t15;
    // 0x009243b9: ffd2 CALL
        t16_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009243bbu);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
    // 0x009243bb: 5e POP
        batch_guest_pc = 0x009243bbu;
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t17a;
    // 0x009243bc: 84c0 TEST
        t18a = state.regs[0] & 0x000000ffu;
        t18b = state.regs[0] & 0x000000ffu;
        t18r = (t18a & t18b) & 0x000000ffu;
        batch_set_logic_flags(state, t18r, 8u);
    // 0x009243be: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009243c5;
    // 0x009243c0: 33c0 XOR
        t20a = state.regs[0];
        t20b = state.regs[0];
        t20r = (t20a ^ t20b) & 0xffffffffu;
        batch_set_logic_flags(state, t20r, 32u);
        state.regs[0] = t20r;
    // 0x009243c2: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009243c5: b801000000 MOV
    L_009243c5:
        t22 = 0x00000001u;
        state.regs[0] = t22;
    // 0x009243ca: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
