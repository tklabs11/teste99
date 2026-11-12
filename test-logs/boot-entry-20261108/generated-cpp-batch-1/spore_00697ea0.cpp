#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00698010(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_009236c0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00697ea0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00697ea0u);
    std::uint32_t t0a = 0, t0b = 0, t0r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;

    // 0x00697ea0: 83e904 SUB
        t0a = state.regs[1];
        t0b = 0x00000004u;
        t0r = static_cast<std::uint32_t>(t0a - t0b) & 0xffffffffu;
        batch_set_sub_flags(state, t0a, t0b, t0r, 32u);
        state.regs[1] = t0r;
    // 0x00697ea3: e968010000 JMP
        state.eip = 0x00698010u;
        return spore_lift_00698010(memory, state);
    // 0x00697ea8: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697ea9: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eaa: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eab: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eac: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697ead: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eae: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eaf: cc INT3
        return BatchLiftStatus::debug_trap;
    // 0x00697eb0: 83e904 SUB
        t10a = state.regs[1];
        t10b = 0x00000004u;
        t10r = static_cast<std::uint32_t>(t10a - t10b) & 0xffffffffu;
        batch_set_sub_flags(state, t10a, t10b, t10r, 32u);
        state.regs[1] = t10r;
    // 0x00697eb3: e908b82800 JMP
        state.eip = 0x009236c0u;
        return spore_lift_009236c0(memory, state);
}
