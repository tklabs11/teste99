#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x011e0ee0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011e0ee0: 6a58 PUSH
        t0a = 0x00000058u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ee2: 68a88c5001 PUSH
        t1a = 0x01508ca8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ee7: e8e8020000 CALL
        if (!batch_guest_call32(memory, state, 0x011e11d4u, 0x011e0eecu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_011e11d4(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x011e0eecu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e0eec: 33db XOR
        t3a = state.regs[3];
        t3b = state.regs[3];
        t3r = (t3a ^ t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[3] = t3r;
    // 0x011e0eee: 895de4 MOV
        t4 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef1: 895dfc MOV
        t5 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef4: 8d4598 LEA
        t6 = static_cast<std::uint32_t>(state.regs[5] + 0xffffff98u);
        state.regs[0] = t6;
    // 0x011e0ef7: 50 PUSH
        t7a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ef8: ff159cc23c01 CALL
        t8_call_status = batch_guest_import_call32(memory, state, "KERNEL32.dll!GetStartupInfoA", 0x013cc29cu, 0x011e0efeu);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x011e0efeu) return BatchLiftStatus::invalid_control_flow;
    state.eip = 0x011e0efeu;
    return BatchLiftStatus::unsupported_dependency;
    L_011e11d4:
    state.eip = 0x011e11d4u;
    return BatchLiftStatus::unsupported_dependency;
}
