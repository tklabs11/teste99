#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009250b0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009250b0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x009250b0: 8b01 MOV
        batch_guest_pc = 0x009250b0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009250b2: 8b5104 MOV
        batch_guest_pc = 0x009250b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x009250b5: 8b4010 MOV
        batch_guest_pc = 0x009250b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x009250b8: 52 PUSH
        batch_guest_pc = 0x009250b8u;
        t3a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x009250b9: ffd0 CALL
        t4_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009250bbu);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
    // 0x009250bb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
