#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00a0fdf0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;

    // 0x00a0fdf0: 8bc1 MOV
        t0 = state.regs[1];
        state.regs[0] = t0;
    // 0x00a0fdf2: 33c9 XOR
        t1a = state.regs[1];
        t1b = state.regs[1];
        t1r = (t1a ^ t1b) & 0xffffffffu;
        batch_set_logic_flags(state, t1r, 32u);
        state.regs[1] = t1r;
    // 0x00a0fdf4: 8908 MOV
        t2 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t2)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fdf6: 894804 MOV
        t3 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t3)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fdf9: 894808 MOV
        t4 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000008u), t4)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fdfc: 89482c MOV
        t5 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000002cu), t5)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fdff: 894830 MOV
        t6 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000030u), t6)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe02: 894834 MOV
        t7 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000034u), t7)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe05: 894838 MOV
        t8 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000038u), t8)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe08: 89483c MOV
        t9 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000003cu), t9)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe0b: 894840 MOV
        t10 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000040u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe0e: 894844 MOV
        t11 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000044u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe11: 894848 MOV
        t12 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000048u), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe14: 89484c MOV
        t13 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x0000004cu), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00a0fe17: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
