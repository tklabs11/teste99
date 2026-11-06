#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e8b20(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e5d80(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8a = 0, t8b = 0, t8r = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;

    // 0x011e5d80: 8b442404 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x011e5d84: 56 PUSH
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e5d85: 8bf1 MOV
        t2 = state.regs[1];
        state.regs[6] = t2;
    // 0x011e5d87: 50 PUSH
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x011e5d88: 8d4e04 LEA
        t4 = static_cast<std::uint32_t>(state.regs[6] + 0x00000004u);
        state.regs[1] = t4;
    // 0x011e5d8b: 51 PUSH
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x011e5d8c: c70698294501 MOV
        t6 = 0x01452998u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x011e5d92: e8892d0000 CALL
        if (!batch_guest_call32(memory, state, 0x011e8b20u, 0x011e5d97u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_011e8b20(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x011e5d97u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e5d97: 83c408 ADD
        t8a = state.regs[4];
        t8b = 0x00000008u;
        t8r = static_cast<std::uint32_t>(t8a + t8b) & 0xffffffffu;
        batch_set_add_flags(state, t8a, t8b, t8r, 32u);
        state.regs[4] = t8r;
    // 0x011e5d9a: 8bc6 MOV
        t9 = state.regs[6];
        state.regs[0] = t9;
    // 0x011e5d9c: 5e POP
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t10a;
    // 0x011e5d9d: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
