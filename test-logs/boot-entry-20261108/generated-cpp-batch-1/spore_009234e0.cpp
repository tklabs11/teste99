#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009250e0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009234e0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009234e0u);
    BatchLiftStatus t0_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;

    // 0x009234e0: e8fb1b0000 CALL
        if (!batch_guest_call32(memory, state, 0x009250e0u, 0x009234e5u)) return BatchLiftStatus::invalid_memory;
        t0_call_status = spore_lift_009250e0(memory, state);
        if (t0_call_status != BatchLiftStatus::returned) return t0_call_status;
        if (state.eip != 0x009234e5u) return BatchLiftStatus::invalid_control_flow;
    // 0x009234e5: 8b10 MOV
        batch_guest_pc = 0x009234e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x009234e7: 8bc8 MOV
        t2 = state.regs[0];
        state.regs[1] = t2;
    // 0x009234e9: 8b4214 MOV
        batch_guest_pc = 0x009234e9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000014u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x009234ec: ffe0 JMP
        t4a = state.regs[0];
        state.eip = t4a;
        return state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_tail_call(memory, state, t4a);
}
