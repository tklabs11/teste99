#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_00925dc0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00925f90(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925f90u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8a = 0;
    std::uint32_t t9a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t12a = 0, t12r = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15a = 0;
    std::uint32_t t16 = 0;
    std::uint32_t t17a = 0;
    std::uint32_t t18a = 0;
    std::uint32_t t19a = 0;
    std::uint32_t t20 = 0;
    std::uint32_t t21a = 0;
    std::uint32_t t22a = 0;
    std::uint32_t t23 = 0;
    BatchLiftStatus t24_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t25a = 0;

    // 0x00925f90: 8b442404 MOV
        batch_guest_pc = 0x00925f90u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00925f94: 3b4114 CMP
        batch_guest_pc = 0x00925f94u;
        t1a = state.regs[0];
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000014u), t1b)) return BatchLiftStatus::invalid_memory;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00925f97: 7717 JA
        if (!((state.eflags & 0x001u) != 0u) && !((state.eflags & 0x040u) != 0u)) goto L_00925fb0;
    // 0x00925f99: 8b54240c MOV
        batch_guest_pc = 0x00925f99u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t3;
    // 0x00925f9d: 6a00 PUSH
        batch_guest_pc = 0x00925f9du;
        t4a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925f9f: 6a00 PUSH
        batch_guest_pc = 0x00925f9fu;
        t5a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fa1: 52 PUSH
        batch_guest_pc = 0x00925fa1u;
        t6a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fa2: 8b542414 MOV
        batch_guest_pc = 0x00925fa2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t7)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t7;
    // 0x00925fa6: 52 PUSH
        batch_guest_pc = 0x00925fa6u;
        t8a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t8a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fa7: 50 PUSH
        batch_guest_pc = 0x00925fa7u;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fa8: e813feffff CALL
        if (!batch_guest_call32(memory, state, 0x00925dc0u, 0x00925fadu)) return BatchLiftStatus::invalid_memory;
        t10_call_status = spore_lift_00925dc0(memory, state);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
        if (state.eip != 0x00925fadu) return BatchLiftStatus::invalid_control_flow;
    // 0x00925fad: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00925fb0: ff411c INC
    L_00925fb0:
        batch_guest_pc = 0x00925fb0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t12a)) return BatchLiftStatus::invalid_memory;
        t12r = static_cast<std::uint32_t>(t12a + 1u) & 0xffffffffu;
        batch_set_inc_flags(state, t12a, t12r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[1] + 0x0000001cu), t12r)) return BatchLiftStatus::invalid_memory;
    // 0x00925fb3: 8b4904 MOV
        batch_guest_pc = 0x00925fb3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000004u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t13;
    // 0x00925fb6: 8b11 MOV
        batch_guest_pc = 0x00925fb6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t14)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t14;
    // 0x00925fb8: 56 PUSH
        batch_guest_pc = 0x00925fb8u;
        t15a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t15a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fb9: 8b742410 MOV
        batch_guest_pc = 0x00925fb9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t16)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t16;
    // 0x00925fbd: 6a00 PUSH
        batch_guest_pc = 0x00925fbdu;
        t17a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t17a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fbf: 6a00 PUSH
        batch_guest_pc = 0x00925fbfu;
        t18a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t18a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fc1: 56 PUSH
        batch_guest_pc = 0x00925fc1u;
        t19a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fc2: 8b742418 MOV
        batch_guest_pc = 0x00925fc2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t20)) return BatchLiftStatus::invalid_memory;
        state.regs[6] = t20;
    // 0x00925fc6: 56 PUSH
        batch_guest_pc = 0x00925fc6u;
        t21a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t21a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fc7: 50 PUSH
        batch_guest_pc = 0x00925fc7u;
        t22a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t22a)) return BatchLiftStatus::invalid_memory;
    // 0x00925fc8: 8b4204 MOV
        batch_guest_pc = 0x00925fc8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000004u), t23)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t23;
    // 0x00925fcb: ffd0 CALL
        t24_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925fcdu);
        if (t24_call_status != BatchLiftStatus::returned) return t24_call_status;
    // 0x00925fcd: 5e POP
        batch_guest_pc = 0x00925fcdu;
        if (!memory.load32(state.regs[4], t25a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t25a;
    // 0x00925fce: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
