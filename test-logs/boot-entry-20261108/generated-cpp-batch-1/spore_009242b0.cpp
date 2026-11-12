#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009242b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009242b0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t20 = 0;

    // 0x009242b0: 8b542404 MOV
        batch_guest_pc = 0x009242b0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x009242b4: 8bc1 MOV
        t1 = state.regs[1];
        state.regs[0] = t1;
    // 0x009242b6: 8b4a0c MOV
        batch_guest_pc = 0x009242b6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x009242b9: f6410801 TEST
        batch_guest_pc = 0x009242b9u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000001u;
        t3r = (t3a & t3b) & 0x000000ffu;
        batch_set_logic_flags(state, t3r, 8u);
    // 0x009242bd: 7424 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242e3;
    // 0x009242bf: 80780c00 CMP
        batch_guest_pc = 0x009242bfu;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t5a)) return BatchLiftStatus::invalid_memory;
        t5b = 0x00000000u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0x000000ffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 8u);
    // 0x009242c3: 741e JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242e3;
    // 0x009242c5: 8b4804 MOV
        batch_guest_pc = 0x009242c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t7;
    // 0x009242c8: 85c9 TEST
        t8a = state.regs[1];
        t8b = state.regs[1];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x009242ca: 7417 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242e3;
    // 0x009242cc: 83780800 CMP
        batch_guest_pc = 0x009242ccu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t10a)) return BatchLiftStatus::invalid_memory;
        t10b = 0x00000000u;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
    // 0x009242d0: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009242e3;
    // 0x009242d2: 8b01 MOV
        batch_guest_pc = 0x009242d2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x009242d4: 52 PUSH
        batch_guest_pc = 0x009242d4u;
        t13a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009242d5: 8b5010 MOV
        batch_guest_pc = 0x009242d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x009242d8: ffd2 CALL
        t15_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[2], 0x009242dau);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
    // 0x009242da: 84c0 TEST
        t16a = state.regs[0] & 0x000000ffu;
        t16b = state.regs[0] & 0x000000ffu;
        t16r = (t16a & t16b) & 0x000000ffu;
        batch_set_logic_flags(state, t16r, 8u);
    // 0x009242dc: 7505 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009242e3;
    // 0x009242de: 33c0 XOR
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = (t18a ^ t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[0] = t18r;
    // 0x009242e0: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009242e3: b801000000 MOV
    L_009242e3:
        t20 = 0x00000001u;
        state.regs[0] = t20;
    // 0x009242e8: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
