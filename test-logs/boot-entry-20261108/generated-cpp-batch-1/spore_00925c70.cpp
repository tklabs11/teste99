#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00928a30(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925c70(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925c70u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    std::uint32_t t13a = 0;
    BatchLiftStatus t14_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00925c70: 8b442408 MOV
        batch_guest_pc = 0x00925c70u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925c74: 8b54240c MOV
        batch_guest_pc = 0x00925c74u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x00925c78: 8b4904 MOV
        batch_guest_pc = 0x00925c78u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x00925c7b: 6a31 PUSH
        batch_guest_pc = 0x00925c7bu;
        t3a = 0x00000031u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c7d: 68a8e04301 PUSH
        batch_guest_pc = 0x00925c7du;
        t4a = 0x0143e0a8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c82: 50 PUSH
        batch_guest_pc = 0x00925c82u;
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c83: 8b442420 MOV
        batch_guest_pc = 0x00925c83u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00925c87: 6a00 PUSH
        batch_guest_pc = 0x00925c87u;
        t7a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c89: 52 PUSH
        batch_guest_pc = 0x00925c89u;
        t8a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c8a: 8b542424 MOV
        batch_guest_pc = 0x00925c8au;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000024u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00925c8e: 50 PUSH
        batch_guest_pc = 0x00925c8eu;
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c8f: 8b44241c MOV
        batch_guest_pc = 0x00925c8fu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t11)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t11;
    // 0x00925c93: 52 PUSH
        batch_guest_pc = 0x00925c93u;
        t12a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c94: 50 PUSH
        batch_guest_pc = 0x00925c94u;
        t13a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c95: e8962d0000 CALL
        if (!batch_guest_call32(memory, state, 0x00928a30u, 0x00925c9au)) return BatchLiftStatus::invalid_memory;
        t14_call_status = spore_lift_00928a30(memory, state);
        if (t14_call_status != BatchLiftStatus::returned) return t14_call_status;
        if (state.eip != 0x00925c9au) return BatchLiftStatus::invalid_control_flow;
    // 0x00925c9a: c21400 RET
        if (!batch_guest_return32(memory, state, 20u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
