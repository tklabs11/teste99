#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00921580(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00921880(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00923b80(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923b80u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4 = 0;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6a = 0;
    BatchLiftStatus t7_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t8 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t10a = 0;
    std::uint32_t t11a = 0;
    BatchLiftStatus t12_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    BatchLiftStatus t19_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    std::uint32_t t24a = 0;

    // 0x00923b80: 53 PUSH
        batch_guest_pc = 0x00923b80u;
        t0a = state.regs[3];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b81: 56 PUSH
        batch_guest_pc = 0x00923b81u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b82: 57 PUSH
        batch_guest_pc = 0x00923b82u;
        t2a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b83: 8b7c2414 MOV
        batch_guest_pc = 0x00923b83u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[7] = t3;
    // 0x00923b87: 8bf1 MOV
        t4 = state.regs[1];
        state.regs[6] = t4;
    // 0x00923b89: ff4e14 DEC
        batch_guest_pc = 0x00923b89u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t5a)) return BatchLiftStatus::invalid_memory;
        t5r = static_cast<std::uint32_t>(t5a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t5a, t5r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000014u), t5r)) return BatchLiftStatus::invalid_memory;
    // 0x00923b8c: 57 PUSH
        batch_guest_pc = 0x00923b8cu;
        t6a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b8d: e8eed9ffff CALL
        if (!batch_guest_call32(memory, state, 0x00921580u, 0x00923b92u)) return BatchLiftStatus::invalid_memory;
        t7_call_status = spore_lift_00921580(memory, state);
        if (t7_call_status != BatchLiftStatus::returned) return t7_call_status;
        if (state.eip != 0x00923b92u) return BatchLiftStatus::invalid_control_flow;
    // 0x00923b92: 8bd8 MOV
        t8 = state.regs[0];
        state.regs[3] = t8;
    // 0x00923b94: 8d4604 LEA
        t9 = static_cast<std::uint32_t>(state.regs[6] + 0x00000004u);
        state.regs[0] = t9;
    // 0x00923b97: 50 PUSH
        batch_guest_pc = 0x00923b97u;
        t10a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b98: 57 PUSH
        batch_guest_pc = 0x00923b98u;
        t11a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t11a)) return BatchLiftStatus::invalid_memory;
    // 0x00923b99: e8e2dcffff CALL
        if (!batch_guest_call32(memory, state, 0x00921880u, 0x00923b9eu)) return BatchLiftStatus::invalid_memory;
        t12_call_status = spore_lift_00921880(memory, state);
        if (t12_call_status != BatchLiftStatus::returned) return t12_call_status;
        if (state.eip != 0x00923b9eu) return BatchLiftStatus::invalid_control_flow;
    // 0x00923b9e: 8b4e18 MOV
        batch_guest_pc = 0x00923b9eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000018u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00923ba1: 8b11 MOV
        batch_guest_pc = 0x00923ba1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00923ba3: 8b420c MOV
        batch_guest_pc = 0x00923ba3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t15;
    // 0x00923ba6: 83c40c ADD
        t16a = state.regs[4];
        t16b = 0x0000000cu;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[4] = t16r;
    // 0x00923ba9: 6a18 PUSH
        batch_guest_pc = 0x00923ba9u;
        t17a = 0x00000018u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bab: 57 PUSH
        batch_guest_pc = 0x00923babu;
        t18a = state.regs[7];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00923bac: ffd0 CALL
        t19_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00923baeu);
        if (t19_call_status != BatchLiftStatus::returned) return t19_call_status;
    // 0x00923bae: 8b442410 MOV
        batch_guest_pc = 0x00923baeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t20;
    // 0x00923bb2: 5f POP
        batch_guest_pc = 0x00923bb2u;
        if (!memory.load32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[7] = t21a;
    // 0x00923bb3: 5e POP
        batch_guest_pc = 0x00923bb3u;
        if (!memory.load32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t22a;
    // 0x00923bb4: 8918 MOV
        batch_guest_pc = 0x00923bb4u;
        t23 = state.regs[3];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[0] + 0x00000000u), t23)) return BatchLiftStatus::invalid_memory;
    // 0x00923bb6: 5b POP
        batch_guest_pc = 0x00923bb6u;
        if (!memory.load32(state.regs[4], t24a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[3] = t24a;
    // 0x00923bb7: c20800 RET
        if (!batch_guest_return32(memory, state, 8u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
