#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009289f0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00f473a0u);
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
    std::uint32_t t10a = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t12a = 0;
    BatchLiftStatus t13_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x00f473a0: 8b442418 MOV
        batch_guest_pc = 0x00f473a0u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000018u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00f473a4: 8b4c2414 MOV
        batch_guest_pc = 0x00f473a4u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t1)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t1;
    // 0x00f473a8: 8b542408 MOV
        batch_guest_pc = 0x00f473a8u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000008u), t2)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t2;
    // 0x00f473ac: 50 PUSH
        batch_guest_pc = 0x00f473acu;
        t3a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473ad: 8b442414 MOV
        batch_guest_pc = 0x00f473adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t4)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4;
    // 0x00f473b1: 51 PUSH
        batch_guest_pc = 0x00f473b1u;
        t5a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473b2: 8b4c2414 MOV
        batch_guest_pc = 0x00f473b2u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000014u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00f473b6: 52 PUSH
        batch_guest_pc = 0x00f473b6u;
        t7a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t7a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473b7: 8b542410 MOV
        batch_guest_pc = 0x00f473b7u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000010u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t8;
    // 0x00f473bb: 50 PUSH
        batch_guest_pc = 0x00f473bbu;
        t9a = state.regs[0];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t9a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473bc: 51 PUSH
        batch_guest_pc = 0x00f473bcu;
        t10a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t10a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473bd: 8b0d448b6c01 MOV
        batch_guest_pc = 0x00f473bdu;
        if (!memory.load32(0x016c8b44u, t11)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t11;
    // 0x00f473c3: 52 PUSH
        batch_guest_pc = 0x00f473c3u;
        t12a = state.regs[2];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t12a)) return BatchLiftStatus::invalid_memory;
    // 0x00f473c4: e827169eff CALL
        if (!batch_guest_call32(memory, state, 0x009289f0u, 0x00f473c9u)) return BatchLiftStatus::invalid_memory;
        t13_call_status = spore_lift_009289f0(memory, state);
        if (t13_call_status != BatchLiftStatus::returned) return t13_call_status;
        if (state.eip != 0x00f473c9u) return BatchLiftStatus::invalid_control_flow;
    // 0x00f473c9: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
