#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_009236d0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x009236d0u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2 = 0;
    std::uint32_t t3a = 0, t3b = 0, t3r = 0;
    std::uint32_t t4a = 0, t4b = 0, t4r = 0;
    std::uint32_t t5a = 0, t5r = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t8 = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13 = 0;
    std::uint32_t t14a = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;

    // 0x009236d0: 8d5134 LEA
        t0 = static_cast<std::uint32_t>(state.regs[1] + 0x00000034u);
        state.regs[2] = t0;
    // 0x009236d3: 56 PUSH
        batch_guest_pc = 0x009236d3u;
        t1a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x009236d4: 8bf2 MOV
        t2 = state.regs[2];
        state.regs[6] = t2;
    // 0x009236d6: 83c8ff OR
        t3a = state.regs[0];
        t3b = 0xffffffffu;
        t3r = (t3a | t3b) & 0xffffffffu;
        batch_set_logic_flags(state, t3r, 32u);
        state.regs[0] = t3r;
    // 0x009236d9: f00fc106 XADD.LOCK
        batch_guest_pc = 0x009236d9u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4a)) return BatchLiftStatus::invalid_memory;
        t4b = state.regs[0];
        t4r = static_cast<std::uint32_t>(t4a + t4b) & 0xffffffffu;
        batch_set_add_flags(state, t4a, t4b, t4r, 32u);
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[6] + 0x00000000u), t4r)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t4a;
    // 0x009236dd: 48 DEC
        t5a = state.regs[0];
        t5r = static_cast<std::uint32_t>(t5a - 1u) & 0xffffffffu;
        batch_set_dec_flags(state, t5a, t5r, 32u);
        state.regs[0] = t5r;
    // 0x009236de: 5e POP
        batch_guest_pc = 0x009236deu;
        if (!memory.load32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t6a;
    // 0x009236df: 7516 JNZ
        if (!((state.eflags & 0x040u) != 0u)) goto L_009236f7;
    // 0x009236e1: b801000000 MOV
        t8 = 0x00000001u;
        state.regs[0] = t8;
    // 0x009236e6: 8702 XCHG
        if (!batch_guest_xchg32(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x009236e8: 85c9 TEST
        t10a = state.regs[1];
        t10b = state.regs[1];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x009236ea: 7409 JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009236f5;
    // 0x009236ec: 8b11 MOV
        batch_guest_pc = 0x009236ecu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[1] + 0x00000000u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t12;
    // 0x009236ee: 8b4208 MOV
        batch_guest_pc = 0x009236eeu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[2] + 0x00000008u), t13)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t13;
    // 0x009236f1: 6a01 PUSH
        batch_guest_pc = 0x009236f1u;
        t14a = 0x00000001u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t14a)) return BatchLiftStatus::invalid_memory;
    // 0x009236f3: ffd0 CALL
        t15_call_status = state.imports == nullptr ? BatchLiftStatus::unsupported_import : state.imports->invoke_guest_call(memory, state, state.regs[0], 0x009236f5u);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
    // 0x009236f5: 33c0 XOR
    L_009236f5:
        t16a = state.regs[0];
        t16b = state.regs[0];
        t16r = (t16a ^ t16b) & 0xffffffffu;
        batch_set_logic_flags(state, t16r, 32u);
        state.regs[0] = t16r;
    // 0x009236f7: c3 RET
    L_009236f7:
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
