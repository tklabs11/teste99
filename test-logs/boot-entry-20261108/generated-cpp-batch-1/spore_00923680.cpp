#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923680(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923680u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t9a = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t14a = 0, t14b = 0, t14r = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;

    // 0x00923680: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00923682: 8b4c2404 MOV
        batch_guest_pc = 0x00923682u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00923686: 81f9a134ab23 CMP
        t2a = state.regs[1];
        t2b = 0x23ab34a1u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
    // 0x0092368c: 7425 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009236b3;
    // 0x0092368e: 81f9e4a87c6c CMP
        t4a = state.regs[1];
        t4b = 0x6c7ca8e4u;
        t4r = static_cast<std::uint32_t>(t4a - t4b) & 0xffffffffu;
        batch_set_sub_flags(state, t4a, t4b, t4r, 32u);
    // 0x00923694: 7411 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009236a7;
    // 0x00923696: 33d2 XOR
        t6a = state.regs[2];
        t6b = state.regs[2];
        t6r = (t6a ^ t6b) & 0xffffffffu;
        batch_set_logic_flags(state, t6r, 32u);
        state.regs[2] = t6r;
    // 0x00923698: 81f96e513fee CMP
        t7a = state.regs[1];
        t7b = 0xee3f516eu;
        t7r = static_cast<std::uint32_t>(t7a - t7b) & 0xffffffffu;
        batch_set_sub_flags(state, t7a, t7b, t7r, 32u);
    // 0x0092369e: 0f95c2 SETNZ
        state.regs[2] = (state.regs[2] & 0xffffff00u) | (((!((state.eflags & 0x040u) != 0u) ? 1u : 0u) << 0u) & 0x000000ffu);
    // 0x009236a1: 4a DEC
        t9a = state.regs[2];
        t9r = static_cast<std::uint32_t>(t9a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t9a, t9r, 32u);
        state.regs[2] = t9r;
    // 0x009236a2: 23c2 AND
        t10a = state.regs[0];
        t10b = state.regs[2];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
        state.regs[0] = t10r;
    // 0x009236a4: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009236a7: 85c0 TEST
    L_009236a7:
        t12a = state.regs[0];
        t12b = state.regs[0];
        t12r = (t12a & t12b) & 0xffffffffu;
        batch_set_logic_flags(state, t12r, 32u);
    // 0x009236a9: 7406 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009236b1;
    // 0x009236ab: 83c004 ADD
        t14a = state.regs[0];
        t14b = 0x00000004u;
        t14r = static_cast<std::uint32_t>(t14a + t14b) & 0xffffffffu;
        batch_set_add_flags(state, t14a, t14b, t14r, 32u);
        state.regs[0] = t14r;
    // 0x009236ae: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009236b1: 33c0 XOR
    L_009236b1:
        t16a = state.regs[0];
        t16b = state.regs[0];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x009236b3: c20400 RET
    L_009236b3:
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
