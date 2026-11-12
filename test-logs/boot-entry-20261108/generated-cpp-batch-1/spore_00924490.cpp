#include "BatchStaticLiftRuntime.hpp"
BatchLiftStatus spore_lift_009243d0(BatchLiftMemory& memory, BatchLiftState& state);
BatchLiftStatus spore_lift_00f473a0(BatchLiftMemory& memory, BatchLiftState& state);


BatchLiftStatus spore_lift_00924490(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00924490u);
    std::uint32_t t0a = 0;
    std::uint32_t t1a = 0;
    std::uint32_t t2a = 0;
    std::uint32_t t3a = 0;
    std::uint32_t t4a = 0;
    std::uint32_t t5a = 0;
    std::uint32_t t6a = 0;
    std::uint32_t t7 = 0;
    BatchLiftStatus t8_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t10a = 0, t10b = 0, t10r = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0;
    std::uint32_t t14 = 0;
    BatchLiftStatus t15_call_status = BatchLiftStatus::invalid_control_flow;
    std::uint32_t t16a = 0;
    std::uint32_t t18a = 0, t18b = 0, t18r = 0;
    std::uint32_t t19a = 0;

    // 0x00924490: 56 PUSH
        batch_guest_pc = 0x00924490u;
        t0a = state.regs[6];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00924491: 6a00 PUSH
        batch_guest_pc = 0x00924491u;
        t1a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t1a)) return BatchLiftStatus::invalid_memory;
    // 0x00924493: 6a00 PUSH
        batch_guest_pc = 0x00924493u;
        t2a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t2a)) return BatchLiftStatus::invalid_memory;
    // 0x00924495: 6a00 PUSH
        batch_guest_pc = 0x00924495u;
        t3a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t3a)) return BatchLiftStatus::invalid_memory;
    // 0x00924497: 6a00 PUSH
        batch_guest_pc = 0x00924497u;
        t4a = 0x00000000u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t4a)) return BatchLiftStatus::invalid_memory;
    // 0x00924499: 6838de4301 PUSH
        batch_guest_pc = 0x00924499u;
        t5a = 0x0143de38u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t5a)) return BatchLiftStatus::invalid_memory;
    // 0x0092449e: 6830100000 PUSH
        batch_guest_pc = 0x0092449eu;
        t6a = 0x00001030u;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t6a)) return BatchLiftStatus::invalid_memory;
    // 0x009244a3: 8bf1 MOV
        t7 = state.regs[1];
        state.regs[6] = t7;
    // 0x009244a5: e8f62e6200 CALL
        if (!batch_guest_call32(memory, state, 0x00f473a0u, 0x009244aau)) return BatchLiftStatus::invalid_memory;
        t8_call_status = spore_lift_00f473a0(memory, state);
        if (t8_call_status != BatchLiftStatus::returned) return t8_call_status;
        if (state.eip != 0x009244aau) return BatchLiftStatus::invalid_control_flow;
    // 0x009244aa: 83c418 ADD
        t9a = state.regs[4];
        t9b = 0x00000018u;
        t9r = static_cast<std::uint32_t>(t9a + t9b) & 0xffffffffu;
        batch_set_add_flags(state, t9a, t9b, t9r, 32u);
        state.regs[4] = t9r;
    // 0x009244ad: 85c0 TEST
        t10a = state.regs[0];
        t10b = state.regs[0];
        t10r = (t10a & t10b) & 0xffffffffu;
        batch_set_logic_flags(state, t10r, 32u);
    // 0x009244af: 740d JZ
        if (((state.eflags & 0x040u) != 0u)) goto L_009244be;
    // 0x009244b1: 8b4e08 MOV
        batch_guest_pc = 0x009244b1u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[6] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t12;
    // 0x009244b4: 51 PUSH
        batch_guest_pc = 0x009244b4u;
        t13a = state.regs[1];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t13a)) return BatchLiftStatus::invalid_memory;
    // 0x009244b5: 8bc8 MOV
        t14 = state.regs[0];
        state.regs[1] = t14;
    // 0x009244b7: e814ffffff CALL
        if (!batch_guest_call32(memory, state, 0x009243d0u, 0x009244bcu)) return BatchLiftStatus::invalid_memory;
        t15_call_status = spore_lift_009243d0(memory, state);
        if (t15_call_status != BatchLiftStatus::returned) return t15_call_status;
        if (state.eip != 0x009244bcu) return BatchLiftStatus::invalid_control_flow;
    // 0x009244bc: 5e POP
        batch_guest_pc = 0x009244bcu;
        if (!memory.load32(state.regs[4], t16a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t16a;
    // 0x009244bd: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x009244be: 33c0 XOR
    L_009244be:
        t18a = state.regs[0];
        t18b = state.regs[0];
        t18r = (t18a ^ t18b) & 0xffffffffu;
        batch_set_logic_flags(state, t18r, 32u);
        state.regs[0] = t18r;
    // 0x009244c0: 5e POP
        batch_guest_pc = 0x009244c0u;
        if (!memory.load32(state.regs[4], t19a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[6] = t19a;
    // 0x009244c1: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
