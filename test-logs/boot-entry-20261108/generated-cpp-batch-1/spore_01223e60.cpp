#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01223e60(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01223e60u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01223e60: 55 PUSH
        batch_guest_pc = 0x01223e60u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01223e61: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01223e63: f30f100594b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb194u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e6b: f30f1105082c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c08u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e73: f30f100590b13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb190u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e7b: f30f11050c2c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c0cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223e83: f30f10058cb13e01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x013eb18cu)) return BatchLiftStatus::invalid_memory;
    // 0x01223e8b: f30f1105102c5d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2c10u)) return BatchLiftStatus::invalid_memory;
    // 0x01223e93: 5d POP
        batch_guest_pc = 0x01223e93u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01223e94: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
