#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00926a10(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00926a10u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;

    // 0x00926a10: 8b442404 MOV
        batch_guest_pc = 0x00926a10u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00926a14: 8b4818 MOV
        batch_guest_pc = 0x00926a14u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00926a17: 8b501c MOV
        batch_guest_pc = 0x00926a17u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00926a1a: 89511c MOV
        batch_guest_pc = 0x00926a1au;
        t3 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00926a1d: 8b481c MOV
        batch_guest_pc = 0x00926a1du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x0000001cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t4;
    // 0x00926a20: 8b5018 MOV
        batch_guest_pc = 0x00926a20u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000018u), t5)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t5;
    // 0x00926a23: 895118 MOV
        batch_guest_pc = 0x00926a23u;
        t6 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000018u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00926a26: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
