#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009289f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925c40(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925c40u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00925c40: 8b442408 MOV
        batch_guest_pc = 0x00925c40u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925c44: 8b54240c MOV
        batch_guest_pc = 0x00925c44u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t1;
    // 0x00925c48: 8b4904 MOV
        batch_guest_pc = 0x00925c48u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t2;
    // 0x00925c4b: 6a2a PUSH
        batch_guest_pc = 0x00925c4bu;
        t3a = 0x0000002au;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c4d: 68a8e04301 PUSH
        batch_guest_pc = 0x00925c4du;
        t4a = 0x0143e0a8u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c52: 50 PUSH
        batch_guest_pc = 0x00925c52u;
        t5a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c53: 8b442410 MOV
        batch_guest_pc = 0x00925c53u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t6;
    // 0x00925c57: 6a00 PUSH
        batch_guest_pc = 0x00925c57u;
        t7a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c59: 52 PUSH
        batch_guest_pc = 0x00925c59u;
        t8a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c5a: 50 PUSH
        batch_guest_pc = 0x00925c5au;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00925c5b: e8902d0000 CALL
        if (!batch_guest_call32(memory, state, 0x009289f0u, 0x00925c60u)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_009289f0(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x00925c60u) return BatchLiftStatus::invalid_control_flow;
    // 0x00925c60: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
