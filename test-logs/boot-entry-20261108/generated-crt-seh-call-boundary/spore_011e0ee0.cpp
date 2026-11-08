#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;

    // 0x011e0ee0: 6a58 PUSH
        t0a = 0x00000058u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e0ee2: 68a88c5001 PUSH
        t1a = 0x01508ca8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    state.eip = 0x011e0ee7u;
    return BatchLiftStatus::unsupported_dependency;
}
