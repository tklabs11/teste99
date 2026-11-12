#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00923630(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00923630u);
    std::uint32_t t0 = 0;
    std::uint32_t t1a = 0, t1b = 0, t1r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t5a = 0, t5b = 0, t5r = 0;
    std::uint32_t t7 = 0;
    std::uint32_t t9a = 0, t9b = 0, t9r = 0;
    std::uint32_t t11 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t17a = 0, t17b = 0, t17r = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t20 = 0;

    // 0x00923630: 8b442404 MOV
        batch_guest_pc = 0x00923630u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[4] + 0x00000004u), t0)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t0;
    // 0x00923634: 83f80a CMP
        t1a = state.regs[0];
        t1b = 0x0000000au;
        t1r = static_cast<std::uint32_t>(t1a - t1b) & 0xffffffffu;
        batch_set_sub_flags(state, t1a, t1b, t1r, 32u);
    // 0x00923637: 7f08 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00923641;
    // 0x00923639: b8c0dc4301 MOV
        t3 = 0x0143dcc0u;
        state.regs[0] = t3;
    // 0x0092363e: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923641: 83f819 CMP
    L_00923641:
        t5a = state.regs[0];
        t5b = 0x00000019u;
        t5r = static_cast<std::uint32_t>(t5a - t5b) & 0xffffffffu;
        batch_set_sub_flags(state, t5a, t5b, t5r, 32u);
    // 0x00923644: 7f08 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_0092364e;
    // 0x00923646: b820a04001 MOV
        t7 = 0x0140a020u;
        state.regs[0] = t7;
    // 0x0092364b: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092364e: 83f832 CMP
    L_0092364e:
        t9a = state.regs[0];
        t9b = 0x00000032u;
        t9r = static_cast<std::uint32_t>(t9a - t9b) & 0xffffffffu;
        batch_set_sub_flags(state, t9a, t9b, t9r, 32u);
    // 0x00923651: 7f08 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_0092365b;
    // 0x00923653: b82c764101 MOV
        t11 = 0x0141762cu;
        state.regs[0] = t11;
    // 0x00923658: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x0092365b: 83f864 CMP
    L_0092365b:
        t13a = state.regs[0];
        t13b = 0x00000064u;
        t13r = static_cast<std::uint32_t>(t13a - t13b) & 0xffffffffu;
        batch_set_sub_flags(state, t13a, t13b, t13r, 32u);
    // 0x0092365e: 7f08 JG
        if (!((state.eflags & 0x040u) != 0u) && (((state.eflags & 0x080u) != 0u) == ((state.eflags & 0x800u) != 0u))) goto L_00923668;
    // 0x00923660: b8b8dc4301 MOV
        t15 = 0x0143dcb8u;
        state.regs[0] = t15;
    // 0x00923665: c20400 RET
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
    // 0x00923668: 3d96000000 CMP
    L_00923668:
        t17a = state.regs[0];
        t17b = 0x00000096u;
        t17r = static_cast<std::uint32_t>(t17a - t17b) & 0xffffffffu;
        batch_set_sub_flags(state, t17a, t17b, t17r, 32u);
    // 0x0092366d: b8b48c3f01 MOV
        t18 = 0x013f8cb4u;
        state.regs[0] = t18;
    // 0x00923672: 7e05 JLE
        if (((state.eflags & 0x040u) != 0u) || (((state.eflags & 0x080u) != 0u) != ((state.eflags & 0x800u) != 0u))) goto L_00923679;
    // 0x00923674: b8b0dc4301 MOV
        t20 = 0x0143dcb0u;
        state.regs[0] = t20;
    // 0x00923679: c20400 RET
    L_00923679:
        if (!batch_guest_return32(memory, state, 4u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
