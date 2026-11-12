#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00928a30(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f473d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f473d0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    std::uint32_t t10 = 0;
    std::uint32_t t11a = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14a = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    BatchLiftStatus t17_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00f473d0: 8b442420 MOV
        batch_guest_pc = 0x00f473d0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000020u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00f473d4: 8b4c241c MOV
        batch_guest_pc = 0x00f473d4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00f473d8: 8b542410 MOV
        batch_guest_pc = 0x00f473d8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00f473dc: 50 PUSH
        batch_guest_pc = 0x00f473dcu;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473dd: 8b44241c MOV
        batch_guest_pc = 0x00f473ddu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00f473e1: 51 PUSH
        batch_guest_pc = 0x00f473e1u;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473e2: 8b4c241c MOV
        batch_guest_pc = 0x00f473e2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000001cu), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00f473e6: 52 PUSH
        batch_guest_pc = 0x00f473e6u;
        t7a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473e7: 8b542418 MOV
        batch_guest_pc = 0x00f473e7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00f473eb: 50 PUSH
        batch_guest_pc = 0x00f473ebu;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473ec: 8b442418 MOV
        batch_guest_pc = 0x00f473ecu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t10)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t10;
    // 0x00f473f0: 51 PUSH
        batch_guest_pc = 0x00f473f0u;
        t11a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473f1: 8b4c2418 MOV
        batch_guest_pc = 0x00f473f1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x00f473f5: 52 PUSH
        batch_guest_pc = 0x00f473f5u;
        t13a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473f6: 50 PUSH
        batch_guest_pc = 0x00f473f6u;
        t14a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473f7: 51 PUSH
        batch_guest_pc = 0x00f473f7u;
        t15a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473f8: 8b0d448b6c01 MOV
        batch_guest_pc = 0x00f473f8u;
        if (!memory.load32(0x016c8b44u, t16)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t16;
    // 0x00f473fe: e82d169eff CALL
        if (!batch_guest_call32(memory, state, 0x00928a30u, 0x00f47403u)) return BatchLiftStatus::invalid_memory;
        t17_call_status = spore_lift_00928a30(memory, state);
        if (t17_call_status != BatchLiftStatus::returned) return t17_call_status;
        if (state.eip != 0x00f47403u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f47403: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
