#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e136e(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    BatchLiftStatus t11_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12b = 0, t12r = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16a = 0;

    // 0x011e136e: 8bff MOV
        t0 = state.regs[7];
        state.regs[7] = t0;
    // 0x011e1370: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1371: b830914f01 MOV
        t2 = 0x014f9130u;
        state.regs[0] = t2;
    // 0x011e1376: be30914f01 MOV
        t3 = 0x014f9130u;
        state.regs[6] = t3;
    // 0x011e137b: 57 PUSH
        t4a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x011e137c: 8bf8 MOV
        t5 = state.regs[0];
        state.regs[7] = t5;
    // 0x011e137e: 3bc6 CMP
        t6a = state.regs[0];
        t6b = state.regs[6];
        t6r = static_cast<std::uint32_t>(t6a - t6b) & 0xffffffffu;
        batch_set_sub_flags(state, t6a, t6b, t6r, 32u);
    // 0x011e1380: 730f JNC
        if (!((state.eflags & 0x001u) != 0u)) goto L_011e1391;
    // 0x011e1382: 8b07 MOV
    L_011e1382:
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[7] + 0x00000000u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x011e1384: 85c0 TEST
        t9a = state.regs[0];
        t9b = state.regs[0];
        t9r = (t9a & t9b) & 0xffffffffu;
        batch_set_logic_flags(state, t9r, 32u);
    // 0x011e1386: 7402 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e138a;
    // 0x011e1388: ffd0 CALL
        t11_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x011e138au);
        if (t11_call_status != BatchLiftStatus::returned) return t11_call_status;
    // 0x011e138a: 83c704 ADD
    L_011e138a:
        t12a = state.regs[7];
        t12b = 0x00000004u;
        t12r = static_cast<std::uint32_t>(t12a + t12b) & 0xffffffffu;
        batch_set_add_flags(state, t12a, t12b, t12r, 32u);
        state.regs[7] = t12r;
    // 0x011e138d: 3bfe CMP
        t13a = state.regs[7];
        t13b = state.regs[6];
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x011e138f: 72f1 JC
        if (((state.eflags & 0x001u) != 0u)) goto L_011e1382;
    // 0x011e1391: 5f POP
    L_011e1391:
        if (!memory.load32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t15a;
    // 0x011e1392: 5e POP
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x011e1393: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
