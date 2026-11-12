#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01221db0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01221db0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t10a = 0;

    // 0x01221db0: 55 PUSH
        batch_guest_pc = 0x01221db0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01221db1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01221db3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221dbb: f30f110514265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2614u)) return BatchLiftStatus::invalid_memory;
    // 0x01221dc3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221dcb: f30f110518265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2618u)) return BatchLiftStatus::invalid_memory;
    // 0x01221dd3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221ddb: f30f11051c265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d261cu)) return BatchLiftStatus::invalid_memory;
    // 0x01221de3: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x01221deb: f30f110520265d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2620u)) return BatchLiftStatus::invalid_memory;
    // 0x01221df3: 5d POP
        batch_guest_pc = 0x01221df3u;
        if (!memory.load32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t10a;
    // 0x01221df4: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
