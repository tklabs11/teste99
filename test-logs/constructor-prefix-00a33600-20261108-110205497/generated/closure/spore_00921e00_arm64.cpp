#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00921e00(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t19a = 0;

    // 0x00921e00: 8a442404 MOV
        if (!memory.load8(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = (state.regs[0] & 0xffffff00u) | ((t0 << 0u) & 0x000000ffu);
    // 0x00921e04: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e05: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x00921e07: 8806 MOV
        t3 = state.regs[0] & 0x000000ffu;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00921e09: 8b44240c MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00921e0d: 85c0 TEST
        t5a = state.regs[0];
        t5b = state.regs[0];
        t5r = (t5a & t5b) & 0xffffffffu;
        batch_set_logic_flags(state, t5r, 32u);
    // 0x00921e0f: 741a JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_00921e2b;
    // 0x00921e11: 6a0f PUSH
        t7a = 0x0000000fu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e13: 50 PUSH
        t8a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e14: 8d4e01 LEA
        t9 = static_cast<std::uint32_t>(state.regs[6] + 0x00000001u);
        state.regs[1] = t9;
    // 0x00921e17: 51 PUSH
        t10a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00921e18: ff15f4c43c01 CALL
        t11_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!strncpy", 0x013cc4f4u, 0x00921e1eu);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
        if (state.eip != 0x00921e1eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00921e1e: 83c40c ADD
        t12a = state.regs[4];
        t12b = 0x0000000cu;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[4] = t12r;
    // 0x00921e21: c6461000 MOV
        t13 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000010u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00921e25: 8bc6 MOV
        t14 = state.regs[6];
        state.regs[0] = t14;
    // 0x00921e27: 5e POP
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t15a;
    // 0x00921e28: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00921e2b: c6460100 MOV
    L_00921e2b:
        t17 = 0x00000000u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000001u), t17)) return BatchLiftStatus::invalid_memory;
    // 0x00921e2f: 8bc6 MOV
        t18 = state.regs[6];
        state.regs[0] = t18;
    // 0x00921e31: 5e POP
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x00921e32: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
