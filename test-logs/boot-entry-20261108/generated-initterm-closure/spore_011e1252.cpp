#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_011e11d4(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_011e1219(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_011e1252(BatchLiftMemory& memory, BatchLiftState& state) {
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    BatchLiftStatus t2_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t5 = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t8 = 0;
    BatchLiftStatus t9_call_status = BatchLiftStatus::invalid_control_flow;

    // 0x011e1252: 6a0c PUSH
        t0a = 0x0000000cu;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1254: 68d08c5001 PUSH
        t1a = 0x01508cd0u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x011e1259: e876ffffff CALL
        if (!batch_guest_call32(memory, state, 0x011e11d4u, 0x011e125eu)) return BatchLiftStatus::invalid_memory;
        t2_call_status = spore_lift_011e11d4(memory, state);
        if (t2_call_status != BatchLiftStatus::returned) return t2_call_status;
        if (state.eip != 0x011e125eu) return BatchLiftStatus::invalid_control_flow;
    // 0x011e125e: 8365fc00 AND
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3a)) return BatchLiftStatus::invalid_memory;
        t3b = 0x00000000u;
        t3r = (t3a & t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t3r)) return BatchLiftStatus::invalid_memory;
    // 0x011e1262: 660f28c1 MOVAPD
        if (!batch_guest_movapd(state, 0u, 1u)) return BatchLiftStatus::invalid_control_flow;
    // 0x011e1266: c745e401000000 MOV
        t5 = 0x00000001u;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t5)) return BatchLiftStatus::invalid_memory;
    // 0x011e126d: eb23 JMP
        goto L_011e1292;
    // 0x011e1292: c745fcfeffffff MOV
    L_011e1292:
        t7 = 0xfffffffeu;
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t7)) return BatchLiftStatus::invalid_memory;
    // 0x011e1299: 8b45e4 MOV
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xffffffe4u), t8)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t8;
    // 0x011e129c: e878ffffff CALL
        if (!batch_guest_call32(memory, state, 0x011e1219u, 0x011e12a1u)) return BatchLiftStatus::invalid_memory;
        t9_call_status = spore_lift_011e1219(memory, state);
        if (t9_call_status != BatchLiftStatus::returned) return t9_call_status;
        if (state.eip != 0x011e12a1u) return BatchLiftStatus::invalid_control_flow;
    // 0x011e12a1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
