#include "../../x86_lift_differential/BatchStaticLiftRuntime.hpp"

BatchLiftStatus spore_lift_006237a0(
    BatchLiftMemory& memory,
    BatchLiftState& state) {
    std::uint32_t internal_call_depth{};
    for (;;) {
        switch (state.eip) {
        case 0x006237a0u:
            if (!batch_guest_push32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.regs[6] = state.regs[1];
            state.eip = 0x006237a3u;
            break;
        case 0x006237a3u:
            if (!memory.load32(state.regs[6] + 0x30u, state.regs[1])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237a6u;
            break;
        case 0x006237a6u:
            batch_set_logic_flags(state, state.regs[1], 32u);
            state.eip = 0x006237a8u;
            break;
        case 0x006237a8u:
            state.eip = (state.eflags & (1u << 6u)) != 0u
                ? 0x006237b8u : 0x006237aau;
            break;
        case 0x006237aau:
            if (!batch_guest_call32(
                    memory, state, 0x006237a0u, 0x006237afu)) {
                return BatchLiftStatus::invalid_memory;
            }
            ++internal_call_depth;
            break;
        case 0x006237afu:
            state.regs[1] = state.regs[0];
            state.eip = 0x006237b1u;
            break;
        case 0x006237b1u:
            if (!memory.load32(state.regs[6] + 0x34u, state.regs[0])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237b4u;
            break;
        case 0x006237b4u:
            state.regs[0] = batch_guest_add32(
                state, state.regs[0], state.regs[1]);
            state.eip = 0x006237b6u;
            break;
        case 0x006237b6u:
            if (!batch_guest_pop32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237b7u;
            break;
        case 0x006237b7u:
            if (!batch_guest_return32(memory, state)) {
                return BatchLiftStatus::invalid_memory;
            }
            if (internal_call_depth == 0u) {
                return BatchLiftStatus::returned;
            }
            --internal_call_depth;
            break;
        case 0x006237b8u:
            if (!memory.load32(state.regs[6] + 0x34u, state.regs[0])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237bbu;
            break;
        case 0x006237bbu:
            state.regs[1] = 0u;
            batch_set_logic_flags(state, 0u, 32u);
            state.eip = 0x006237bdu;
            break;
        case 0x006237bdu:
            state.regs[0] = batch_guest_add32(
                state, state.regs[0], state.regs[1]);
            state.eip = 0x006237bfu;
            break;
        case 0x006237bfu:
            if (!batch_guest_pop32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237c0u;
            break;
        case 0x006237c0u:
            if (!batch_guest_return32(memory, state)) {
                return BatchLiftStatus::invalid_memory;
            }
            if (internal_call_depth == 0u) {
                return BatchLiftStatus::returned;
            }
            --internal_call_depth;
            break;
        default:
            return BatchLiftStatus::invalid_control_flow;
        }
    }
}
