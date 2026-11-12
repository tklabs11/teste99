#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00935c80(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_01300150(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01300150u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0, t6b = 0, t6r = 0;

    // 0x01300150: 68c05b9200 PUSH
        batch_guest_pc = 0x01300150u;
        t0a = 0x00925bc0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01300155: 68e385a4ee PUSH
        batch_guest_pc = 0x01300155u;
        t1a = 0xeea485e3u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x0130015a: e8215b63ff CALL
        if (!batch_guest_call32(memory, state, 0x00935c80u, 0x0130015fu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_00935c80(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x0130015fu) return BatchLiftStatus::invalid_control_flow;
    // 0x0130015f: 68a00d3c01 PUSH
        batch_guest_pc = 0x0130015fu;
        t3a = 0x013c0da0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x01300164: a39c8e6601 MOV
        batch_guest_pc = 0x01300164u;
        t4 = state.regs[0];
        if (!memory.store32(0x01668e9cu, t4)) return BatchLiftStatus::invalid_memory;
    // 0x01300169: e88106eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x0130016eu)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011e07ef(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x0130016eu) return BatchLiftStatus::invalid_control_flow;
    // 0x0130016e: 83c40c ADD
        t6a = state.regs[4];
        t6b = 0x0000000cu;
        t6r = static_cast<std::uint32_t>(t6a + t6b) & 0xffffffffu;
        batch_set_add_flags(state, t6a, t6b, t6r, 32u);
        state.regs[4] = t6r;
    // 0x01300171: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
