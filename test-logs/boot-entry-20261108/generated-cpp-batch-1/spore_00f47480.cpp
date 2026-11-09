#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00927860(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f47480(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f47480u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19 = 0;
    BatchLiftStatus t20_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t24a = 0, t24b = 0, t24r = 0;
    std::uint32_t t25a = 0;

    // 0x00f47480: 56 PUSH
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00f47481: 6830050000 PUSH
        t1a = 0x00000530u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00f47486: 6a00 PUSH
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00f47488: ff15b8c13c01 CALL
        t3_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetProcessHeap", 0x013cc1b8u, 0x00f4748eu);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x00f4748eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00f4748e: 50 PUSH
        t4a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4748f: ff15b4c13c01 CALL
        t5_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!HeapAlloc", 0x013cc1b4u, 0x00f47495u);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x00f47495u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f47495: 8bf0 MOV
        t6 = state.regs[0];
        state.regs[6] = t6;
    // 0x00f47497: 85f6 TEST
        t7a = state.regs[6];
        t7b = state.regs[6];
        t7r = (t7a & t7b) & 0xffffffffu;
        batch_set_logic_flags(state, t7r, 32u);
    // 0x00f47499: 7430 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00f474cb;
    // 0x00f4749b: 6a00 PUSH
        t9a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4749d: 6a00 PUSH
        t10a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00f4749f: 6a00 PUSH
        t11a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474a1: 6a01 PUSH
        t12a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474a3: 6a00 PUSH
        t13a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474a5: c7460400000000 MOV
        t14 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000004u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00f474ac: c70600000000 MOV
        t15 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
    // 0x00f474b2: 6a00 PUSH
        t16a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
    // 0x00f474b4: 8d4e18 LEA
        t17 = static_cast<std::uint32_t>(state.regs[6] + 0x00000018u);
        state.regs[1] = t17;
    // 0x00f474b7: c746105c2b0000 MOV
        t18 = 0x00002b5cu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t18)) return BatchLiftStatus::invalid_memory;
    // 0x00f474be: c6461400 MOV
        t19 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t19)) return BatchLiftStatus::invalid_memory;
    // 0x00f474c2: e899039eff CALL
        if (!batch_guest_call32(memory, state, 0x00927860u, 0x00f474c7u)) return BatchLiftStatus::invalid_memory;
        t20_call_status = spore_lift_00927860(memory, state);
        if (t20_call_status != BatchLiftStatus::returned) return t20_call_status;
        if (state.eip != 0x00f474c7u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f474c7: 8bc6 MOV
        t21 = state.regs[6];
        state.regs[0] = t21;
    // 0x00f474c9: 5e POP
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x00f474ca: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00f474cb: 33c0 XOR
    L_00f474cb:
        t24a = state.regs[0];
        t24b = state.regs[0];
        t24r = (t24a ^ t24b) & 0xffffffffu;
        batch_set_logic_flags(state, t24r, 32u);
        state.regs[0] = t24r;
    // 0x00f474cd: 5e POP
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t25a;
    // 0x00f474ce: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
