#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e07ef(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_013001b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x013001b0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    BatchLiftStatus t3_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t4a = 0;
    BatchLiftStatus t5_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t6a = 0;

    // 0x013001b0: 6a01 PUSH
        batch_guest_pc = 0x013001b0u;
        t0a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x013001b2: 6a00 PUSH
        batch_guest_pc = 0x013001b2u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x013001b4: b930896601 MOV
        t2 = 0x01668930u;
        state.regs[1] = t2;
    // 0x013001b9: e8e22062ff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x013001beu)) return BatchLiftStatus::invalid_memory;
        t3_call_status = spore_lift_009222a0(memory, state);
        if (t3_call_status != BatchLiftStatus::returned) return t3_call_status;
        if (state.eip != 0x013001beu) return BatchLiftStatus::invalid_control_flow;
    // 0x013001be: 68600d3c01 PUSH
        batch_guest_pc = 0x013001beu;
        t4a = 0x013c0d60u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x013001c3: e82706eeff CALL
        if (!batch_guest_call32(memory, state, 0x011e07efu, 0x013001c8u)) return BatchLiftStatus::invalid_memory;
        t5_call_status = spore_lift_011e07ef(memory, state);
        if (t5_call_status != BatchLiftStatus::returned) return t5_call_status;
        if (state.eip != 0x013001c8u) return BatchLiftStatus::invalid_control_flow;
    // 0x013001c8: 59 POP
        batch_guest_pc = 0x013001c8u;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[1] = t6a;
    // 0x013001c9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
