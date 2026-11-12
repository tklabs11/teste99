#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_01222740(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x01222740u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t8a = 0;

    // 0x01222740: 55 PUSH
        batch_guest_pc = 0x01222740u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x01222741: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x01222743: f30f10056c225d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d226cu)) return BatchLiftStatus::invalid_memory;
    // 0x0122274b: f30f110578245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2478u)) return BatchLiftStatus::invalid_memory;
    // 0x01222753: f30f100570225d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d2270u)) return BatchLiftStatus::invalid_memory;
    // 0x0122275b: f30f11057c245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d247cu)) return BatchLiftStatus::invalid_memory;
    // 0x01222763: f30f100574225d01 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x015d2274u)) return BatchLiftStatus::invalid_memory;
    // 0x0122276b: f30f110580245d01 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, 0x015d2480u)) return BatchLiftStatus::invalid_memory;
    // 0x01222773: 5d POP
        batch_guest_pc = 0x01222773u;
        if (!memory.load32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t8a;
    // 0x01222774: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
