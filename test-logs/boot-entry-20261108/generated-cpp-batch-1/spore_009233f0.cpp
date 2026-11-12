#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009233f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009233f0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;

    // 0x009233f0: 8b442404 MOV
        batch_guest_pc = 0x009233f0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x009233f4: 8b400c MOV
        batch_guest_pc = 0x009233f4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x009233f7: 8b11 MOV
        batch_guest_pc = 0x009233f7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x009233f9: 89442404 MOV
        batch_guest_pc = 0x009233f9u;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x009233fd: 8b4214 MOV
        batch_guest_pc = 0x009233fdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000014u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00923400: ffe0 JMP
        t5a = state.regs[0];
        state.eip = t5a;
        return state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_tail_call(memory, state, t5a);
}
