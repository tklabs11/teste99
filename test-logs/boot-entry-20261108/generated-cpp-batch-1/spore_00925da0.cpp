#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00925da0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00925da0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t7a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t9a = 0;
    BatchLiftStatus t10_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00925da0: 8b54240c MOV
        batch_guest_pc = 0x00925da0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x0000000cu), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t0;
    // 0x00925da4: 8b01 MOV
        batch_guest_pc = 0x00925da4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t1;
    // 0x00925da6: 8b4004 MOV
        batch_guest_pc = 0x00925da6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[0] + 0x00000004u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t2;
    // 0x00925da9: 6a00 PUSH
        batch_guest_pc = 0x00925da9u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dab: 6a00 PUSH
        batch_guest_pc = 0x00925dabu;
        t4a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dad: 52 PUSH
        batch_guest_pc = 0x00925dadu;
        t5a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00925dae: 8b542414 MOV
        batch_guest_pc = 0x00925daeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t6;
    // 0x00925db2: 52 PUSH
        batch_guest_pc = 0x00925db2u;
        t7a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00925db3: 8b542414 MOV
        batch_guest_pc = 0x00925db3u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00925db7: 52 PUSH
        batch_guest_pc = 0x00925db7u;
        t9a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00925db8: ffd0 CALL
        t10_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x00925dbau);
        if (t10_call_status != BatchLiftStatus::returned) return t10_call_status;
    // 0x00925dba: c20c00 RET
        if (!batch_guest_return32(memory, state, 12u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
