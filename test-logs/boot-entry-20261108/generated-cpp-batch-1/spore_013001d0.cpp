#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925a30(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_013001d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x013001d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5 = 0;
    BatchLiftStatus t6_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t7a = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;

    // 0x013001d0: 51 PUSH
        batch_guest_pc = 0x013001d0u;
        t0a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x013001d1: 8d442403 LEA
        t1 = static_cast<std::uint32_t>(state.regs[4] + 0x00000003u);
        state.regs[0] = t1;
    // 0x013001d5: 50 PUSH
        batch_guest_pc = 0x013001d5u;
        t2a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x013001d6: 8d4c2407 LEA
        t3 = static_cast<std::uint32_t>(state.regs[4] + 0x00000007u);
        state.regs[1] = t3;
    // 0x013001da: 51 PUSH
        batch_guest_pc = 0x013001dau;
        t4a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x013001db: b960896601 MOV
        t5 = 0x01668960u;
        state.regs[1] = t5;
    // 0x013001e0: e84b5862ff CALL
        if (!batch_guest_call32(memory, state, 0x00925a30u, 0x013001e5u)) return BatchLiftStatus::invalid_memory;
        t6_call_status = spore_lift_00925a30(memory, state);
        if (t6_call_status != BatchLiftStatus::returned) return t6_call_status;
        if (state.eip != 0x013001e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x013001e5: 68200e3c01 PUSH
        batch_guest_pc = 0x013001e5u;
        t7a = 0x013c0e20u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x013001ea: e80006eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x013001efu)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_011e07ef(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x013001efu) return BatchLiftStatus::invalid_control_flow;
    // 0x013001ef: 83c408 ADD
        t9a = state.regs[4];
        t9b = 0x00000008u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x013001f2: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
