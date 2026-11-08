#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e151a(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7a = 0, t7b = 0, t7r = 0;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0;

    // 0x011e151a: 8bff MOV
        t0 = state.regs[7];
        state.regs[7] = t0;
    // 0x011e151c: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e151d: 6800000300 PUSH
        t2a = 0x00030000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1522: 6800000100 PUSH
        t3a = 0x00010000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1527: 33f6 XOR
        t4a = state.regs[6];
        t4b = state.regs[6];
        t4r = (t4a ^ t4b) & 0xffffffffu;
        batch_set_logic_flags(state, t4r, 32u);
        state.regs[6] = t4r;
    // 0x011e1529: 56 PUSH
        t5a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x011e152a: e8c7010000 CALL
        t6_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_controlfp_s", 0x013cc2f0u, 0x011e152fu);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x011e152fu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e152f: 83c40c ADD
        t7a = state.regs[4];
        t7b = 0x0000000cu;
        t7r = static_cast<std::uint32_t>(t7a + t7b) & 0xffffffffu;
        batch_set_add_flags(state, t7a, t7b, t7r, 32u);
        state.regs[4] = t7r;
    // 0x011e1532: 85c0 TEST
        t8a = state.regs[0];
        t8b = state.regs[0];
        t8r = (t8a & t8b) & 0xffffffffu;
        batch_set_logic_flags(state, t8r, 32u);
    // 0x011e1534: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_011e1543;
    // 0x011e1536: 56 PUSH
        t10a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1537: 56 PUSH
        t11a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1538: 56 PUSH
        t12a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1539: 56 PUSH
        t13a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x011e153a: 56 PUSH
        t14a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x011e153b: e8b0010000 CALL
        t15_call_status = batch_guest_import_call32(memory, state, "MSVCR90.dll!_invoke_watson", 0x013cc2f4u, 0x011e1540u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x011e1540u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1540: 83c414 ADD
        t16a = state.regs[4];
        t16b = 0x00000014u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[4] = t16r;
    // 0x011e1543: 5e POP
    L_011e1543:
        if (!memory.load32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t17a;
    // 0x011e1544: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
