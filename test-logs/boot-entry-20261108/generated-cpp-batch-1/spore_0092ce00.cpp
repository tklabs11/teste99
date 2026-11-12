#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_0092ce00(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x0092ce00u);
    std::uint32_t t0 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0, t17r = 0;
    std::uint32_t t18a = 0, t18r = 0;
    std::uint32_t t19a = 0, t19b = 0, t19r = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t22a = 0;

    // 0x0092ce00: 8b442414 MOV
        batch_guest_pc = 0x0092ce00u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x0092ce04: dd442404 FLD
        if (!batch_guest_fld64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0092ce08: 8b4c2410 MOV
        batch_guest_pc = 0x0092ce08u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x0092ce0c: 8b54240c MOV
        batch_guest_pc = 0x0092ce0cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t3;
    // 0x0092ce10: 56 PUSH
        batch_guest_pc = 0x0092ce10u;
        t4a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x0092ce11: 50 PUSH
        batch_guest_pc = 0x0092ce11u;
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092ce12: 51 PUSH
        batch_guest_pc = 0x0092ce12u;
        t6a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x0092ce13: 52 PUSH
        batch_guest_pc = 0x0092ce13u;
        t7a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x0092ce14: 83ec08 SUB
        t8a = state.regs[4];
        t8b = 0x00000008u;
        t8r = static_cast<std::uint32_t>(t8a - t8b) & 0xffffffffu;
        batch_set_sub_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x0092ce17: dd1c24 FSTP
        if (!batch_guest_fstp64(memory, state, static_cast<std::uint32_t>(state.regs[4] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x0092ce1a: ff15d0c33c01 CALL
        t10_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_ecvt", 0x013cc3d0u, 0x0092ce20u);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x0092ce20u) return BatchLiftStatus::invalid_control_flow;
    // 0x0092ce20: 8b742430 MOV
        batch_guest_pc = 0x0092ce20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000030u), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t11;
    // 0x0092ce24: 83c414 ADD
        t12a = state.regs[4];
        t12b = 0x00000014u;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[4] = t12r;
    // 0x0092ce27: 8bd6 MOV
        t13 = state.regs[6];
        state.regs[2] = t13;
    // 0x0092ce29: 8da42400000000 LEA
        t14 = static_cast<std::uint32_t>(state.regs[4] + 0x00000000u);
        state.regs[4] = t14;
    // 0x0092ce30: 8a08 MOV
    L_0092ce30:
        batch_guest_pc = 0x0092ce30u;
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = (state.regs[1] & 0xffffff00u) | ((t15 << 0u) & 0x000000ffu);
    // 0x0092ce32: 880a MOV
        batch_guest_pc = 0x0092ce32u;
        t16 = state.regs[1] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t16)) return BatchLiftStatus::invalid_memory;
    // 0x0092ce34: 40 INC
        t17a = state.regs[0];
        t17r = static_cast<std::uint32_t>(t17a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t17a, t17r, 32u);
        state.regs[0] = t17r;
    // 0x0092ce35: 42 INC
        t18a = state.regs[2];
        t18r = static_cast<std::uint32_t>(t18a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t18a, t18r, 32u);
        state.regs[2] = t18r;
    // 0x0092ce36: 84c9 TEST
        t19a = state.regs[1] & 0x000000ffu;
        t19b = state.regs[1] & 0x000000ffu;
        t19r = (t19a & t19b) & 0x000000ffu;
        batch_set_logic_flags(state, t19r, 8u);
    // 0x0092ce38: 75f6 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_0092ce30;
    // 0x0092ce3a: 8bc6 MOV
        t21 = state.regs[6];
        state.regs[0] = t21;
    // 0x0092ce3c: 5e POP
        batch_guest_pc = 0x0092ce3cu;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x0092ce3d: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
