#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925d60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925d60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0, t15b = 0, t15r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    std::uint32_t t20a = 0;

    // 0x00925d60: 56 PUSH
        batch_guest_pc = 0x00925d60u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d61: 8bf1 MOV
        t1 = state.regs[1];
        state.regs[6] = t1;
    // 0x00925d63: 8b460c MOV
        batch_guest_pc = 0x00925d63u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00925d66: c706f4e04301 MOV
        batch_guest_pc = 0x00925d66u;
        t3 = 0x0143e0f4u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00925d6c: 85c0 TEST
        t4a = state.regs[0];
        t4b = state.regs[0];
        t4r = (t4a & t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
    // 0x00925d6e: 7419 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00925d89;
    // 0x00925d70: 8b08 MOV
    L_00925d70:
        batch_guest_pc = 0x00925d70u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00925d72: 894e0c MOV
        batch_guest_pc = 0x00925d72u;
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00925d75: 8b4e04 MOV
        batch_guest_pc = 0x00925d75u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t8;
    // 0x00925d78: 8b11 MOV
        batch_guest_pc = 0x00925d78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00925d7a: 6a00 PUSH
        batch_guest_pc = 0x00925d7au;
        t10a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d7c: 50 PUSH
        batch_guest_pc = 0x00925d7cu;
        t11a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00925d7d: 8b420c MOV
        batch_guest_pc = 0x00925d7du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00925d80: ffd0 CALL
        t13_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925d82u);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
    // 0x00925d82: 8b460c MOV
        batch_guest_pc = 0x00925d82u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t14;
    // 0x00925d85: 85c0 TEST
        t15a = state.regs[0];
        t15b = state.regs[0];
        t15r = (t15a & t15b) & 0xffffffffu;
        batch_set_logic_flags(state, t15r, 32u);
    // 0x00925d87: 75e7 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00925d70;
    // 0x00925d89: c7460800000000 MOV
    L_00925d89:
        batch_guest_pc = 0x00925d89u;
        t17 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00925d90: c7460c00000000 MOV
        batch_guest_pc = 0x00925d90u;
        t18 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00925d97: c70634394001 MOV
        batch_guest_pc = 0x00925d97u;
        t19 = 0x01403934u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00925d9d: 5e POP
        batch_guest_pc = 0x00925d9du;
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00925d9e: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
