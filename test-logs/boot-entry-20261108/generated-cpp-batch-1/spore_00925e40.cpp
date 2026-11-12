#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925e40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925e40u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0, t4r = 0;

    // 0x00925e40: 8b542404 MOV
        batch_guest_pc = 0x00925e40u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00925e44: 8b4108 MOV
        batch_guest_pc = 0x00925e44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00925e47: 895108 MOV
        batch_guest_pc = 0x00925e47u;
        t2 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00925e4a: 8902 MOV
        batch_guest_pc = 0x00925e4au;
        t3 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[2] + 0x00000000u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00925e4c: ff4910 DEC
        batch_guest_pc = 0x00925e4cu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t4a)) return BatchLiftStatus::invalid_memory;
        t4r = static_cast<std::uint32_t>(t4a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t4a, t4r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x00000010u), t4r)) return BatchLiftStatus::invalid_memory;
    // 0x00925e4f: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
