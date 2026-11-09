#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926a60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926a60u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17a = 0;
    BatchLiftStatus t18_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20a = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t23a = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0;
    BatchLiftStatus t26_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t27 = 0;

    // 0x00926a60: 8b542404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00926a64: 32c0 XOR
        t1a = state.regs[0] & 0x000000ffu;
        t1b = state.regs[0] & 0x000000ffu;
        t1r = (t1a ^ t1b) & 0x000000ffu;
        batch_set_logic_flags(state, t1r, 8u);
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t1r << 0u) & 0x000000ffu);
    // 0x00926a66: 38420d CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000du), t2a)) return BatchLiftStatus::invalid_memory;
        t2b = state.regs[0] & 0x000000ffu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0x000000ffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 8u);
    // 0x00926a69: 750b JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00926a76;
    // 0x00926a6b: 38442408 CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = state.regs[0] & 0x000000ffu;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0x000000ffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 8u);
    // 0x00926a6f: 7432 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926aa3;
    // 0x00926a71: 38420e CMP
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[2] + 0x0000000eu), t6a)) return BatchLiftStatus::invalid_memory;
        t6b = state.regs[0] & 0x000000ffu;
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0x000000ffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 8u);
    // 0x00926a74: 742d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926aa3;
    // 0x00926a76: 8b4210 MOV
    L_00926a76:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x00926a79: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x00926a7b: 7416 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00926a93;
    // 0x00926a7d: 56 PUSH
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a7e: 8b7214 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000014u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t12;
    // 0x00926a81: 56 PUSH
        t13a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a82: 8b7208 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t14;
    // 0x00926a85: 56 PUSH
        t15a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a86: 52 PUSH
        t16a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a87: 51 PUSH
        t17a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a88: ffd0 CALL
        t18_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00926a8au);
        if (t18_call_status != BatchLiftStatus::returned) return t18_call_status;
    // 0x00926a8a: 83c410 ADD
        t19a = state.regs[4];
        t19b = 0x00000010u;
        t19r = static_cast<std::uint32_t>(t19a + t19b) & 0xffffffffu;
        batch_set_add_flags(state, t19a, t19b, t19r, 32u);
        state.regs[4] = t19r;
    // 0x00926a8d: 5e POP
        if (!memory.load32(state.regs[4], t20a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t20a;
    // 0x00926a8e: b001 MOV
        t21 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t21 << 0u) & 0x000000ffu);
    // 0x00926a90: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00926a93: 6800800000 PUSH
    L_00926a93:
        t23a = 0x00008000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t23a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a98: 6a00 PUSH
        t24a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a9a: 52 PUSH
        t25a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
    // 0x00926a9b: ff15c4c13c01 CALL
        t26_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!VirtualFree", 0x013cc1c4u, 0x00926aa1u);
        if (t26_call_status != BatchLiftStatus::returned) return t26_call_status;
        if (state.eip != 0x00926aa1u) return BatchLiftStatus::invalid_control_flow;
    // 0x00926aa1: b001 MOV
        t27 = 0x00000001u;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t27 << 0u) & 0x000000ffu);
    // 0x00926aa3: c20800 RET
    L_00926aa3:
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
