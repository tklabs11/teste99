#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_009259d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009259d0u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    BatchLiftStatus t4_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9 = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0;

    // 0x009259d0: 56 PUSH
        batch_guest_pc = 0x009259d0u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x009259d1: 6a01 PUSH
        batch_guest_pc = 0x009259d1u;
        t1a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009259d3: 6a00 PUSH
        batch_guest_pc = 0x009259d3u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x009259d5: 8bf1 MOV
        t3 = state.regs[1];
        state.regs[6] = t3;
    // 0x009259d7: e8c4c8ffff CALL
        if (!batch_guest_call32(memory, state, 0x009222a0u, 0x009259dcu)) return BatchLiftStatus::invalid_memory;
        t4_call_status = spore_lift_009222a0(memory, state);
        if (t4_call_status != BatchLiftStatus::returned) return t4_call_status;
        if (state.eip != 0x009259dcu) return BatchLiftStatus::invalid_control_flow;
    // 0x009259dc: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x009259e4: f30f114640 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00000040u))) return BatchLiftStatus::invalid_memory;
    // 0x009259e9: f30f1005140f4701 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01470f14u)) return BatchLiftStatus::invalid_memory;
    // 0x009259f1: f30f114644 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[6] + 0x00000044u))) return BatchLiftStatus::invalid_memory;
    // 0x009259f6: c7464800000000 MOV
        batch_guest_pc = 0x009259f6u;
        t9 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t9)) return BatchLiftStatus::invalid_memory;
    // 0x009259fd: c7463801000000 MOV
        batch_guest_pc = 0x009259fdu;
        t10 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000038u), t10)) return BatchLiftStatus::invalid_memory;
    // 0x00925a04: c7463428df5401 MOV
        batch_guest_pc = 0x00925a04u;
        t11 = 0x0154df28u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000034u), t11)) return BatchLiftStatus::invalid_memory;
    // 0x00925a0b: c7463c00000000 MOV
        batch_guest_pc = 0x00925a0bu;
        t12 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x0000003cu), t12)) return BatchLiftStatus::invalid_memory;
    // 0x00925a12: c7464800000000 MOV
        batch_guest_pc = 0x00925a12u;
        t13 = 0x00000000u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000048u), t13)) return BatchLiftStatus::invalid_memory;
    // 0x00925a19: c6465001 MOV
        batch_guest_pc = 0x00925a19u;
        t14 = 0x00000001u;
        if (!memory.store8(static_cast<std::uint32_t>(state.regs[6] + 0x00000050u), t14)) return BatchLiftStatus::invalid_memory;
    // 0x00925a1d: 8bc6 MOV
        t15 = state.regs[6];
        state.regs[0] = t15;
    // 0x00925a1f: 5e POP
        batch_guest_pc = 0x00925a1fu;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x00925a20: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
