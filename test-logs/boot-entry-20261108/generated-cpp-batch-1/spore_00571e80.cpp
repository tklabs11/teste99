#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00571e80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00571e80u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    BatchLiftStatus t16_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22 = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;

    // 0x00571e80: 83ec08 SUB
        t0a = state.regs[4];
        t0b = 0x00000008u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[4] = t0r;
    // 0x00571e83: 56 PUSH
        batch_guest_pc = 0x00571e83u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00571e84: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00571e86: 837e1001 CMP
        batch_guest_pc = 0x00571e86u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000001u;
        t3r = static_cast<std::uint32_t>(t3a - t3b) & 0xffffffffu;
        batch_set_sub_flags(state, t3a, t3b, t3r, 32u);
    // 0x00571e8a: 7514 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_00571ea0;
    // 0x00571e8c: 0f31 RDTSC
        if (!batch_guest_rdtsc(state)) return BatchLiftStatus::invalid_control_flow;
    // 0x00571e8e: 8906 MOV
        batch_guest_pc = 0x00571e8eu;
        t6 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00571e90: 33c0 XOR
        t7a = state.regs[0];
        t7b = state.regs[0];
        t7r = (t7a ^ t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
        state.regs[0] = t7r;
    // 0x00571e92: 89460c MOV
        batch_guest_pc = 0x00571e92u;
        t8 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00571e95: 894608 MOV
        batch_guest_pc = 0x00571e95u;
        t9 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00571e98: 895604 MOV
        batch_guest_pc = 0x00571e98u;
        t10 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00571e9b: 5e POP
        batch_guest_pc = 0x00571e9bu;
        if (!memory.load32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t11a;
    // 0x00571e9c: 83c408 ADD
        t12a = state.regs[4];
        t12b = 0x00000008u;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[4] = t12r;
    // 0x00571e9f: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00571ea0: 8d442404 LEA
    L_00571ea0:
        t14 = static_cast<std::uint32_t>(state.regs[4] + 0x00000004u);
        state.regs[0] = t14;
    // 0x00571ea4: 50 PUSH
        batch_guest_pc = 0x00571ea4u;
        t15a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00571ea5: ff15b8c23c01 CALL
        t16_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!QueryPerformanceCounter", 0x013cc2b8u, 0x00571eabu);
        if (t16_call_status != BatchLiftStatus::returned) return t16_call_status;
        if (state.eip != 0x00571eabu) return BatchLiftStatus::invalid_control_flow;
    // 0x00571eab: 8b4c2404 MOV
        batch_guest_pc = 0x00571eabu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t17)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t17;
    // 0x00571eaf: 8b542408 MOV
        batch_guest_pc = 0x00571eafu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00571eb3: 33c0 XOR
        t19a = state.regs[0];
        t19b = state.regs[0];
        t19r = (t19a ^ t19b) & 0xffffffffu;
        batch_set_logic_flags(state, t19r, 32u);
        state.regs[0] = t19r;
    // 0x00571eb5: 890e MOV
        batch_guest_pc = 0x00571eb5u;
        t20 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t20)) return BatchLiftStatus::invalid_memory;
    // 0x00571eb7: 89460c MOV
        batch_guest_pc = 0x00571eb7u;
        t21 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000000cu), t21)) return BatchLiftStatus::invalid_memory;
    // 0x00571eba: 894608 MOV
        batch_guest_pc = 0x00571ebau;
        t22 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t22)) return BatchLiftStatus::invalid_memory;
    // 0x00571ebd: 895604 MOV
        batch_guest_pc = 0x00571ebdu;
        t23 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00571ec0: 5e POP
        batch_guest_pc = 0x00571ec0u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t24a;
    // 0x00571ec1: 83c408 ADD
        t25a = state.regs[4];
        t25b = 0x00000008u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[4] = t25r;
    // 0x00571ec4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
