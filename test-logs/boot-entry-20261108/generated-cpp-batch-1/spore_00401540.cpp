#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00401540(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401540u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t13a = 0, t13b = 0, t13r = 0;
    std::uint32_t t14 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t25a = 0, t25b = 0, t25r = 0;
    std::uint32_t t26 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t37 = 0;
    std::uint32_t t38a = 0;

    // 0x00401540: 55 PUSH
        batch_guest_pc = 0x00401540u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00401541: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00401543: 83ec08 SUB
        t2a = state.regs[4];
        t2b = 0x00000008u;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00401546: 8b4508 MOV
        batch_guest_pc = 0x00401546u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00401549: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401551: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401555: 8b4d08 MOV
        batch_guest_pc = 0x00401555u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00401558: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401560: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00401565: 8b5508 MOV
        batch_guest_pc = 0x00401565u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00401568: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401570: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00401575: 8b4508 MOV
        batch_guest_pc = 0x00401575u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00401578: 83c00c ADD
        t13a = state.regs[0];
        t13b = 0x0000000cu;
        t13r = static_cast<std::uint32_t>(t13a + t13b) & 0xffffffffu;
        batch_set_add_flags(state, t13a, t13b, t13r, 32u);
        state.regs[0] = t13r;
    // 0x0040157b: 8945fc MOV
        batch_guest_pc = 0x0040157bu;
        t14 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t14)) return BatchLiftStatus::invalid_memory;
    // 0x0040157e: 8b4dfc MOV
        batch_guest_pc = 0x0040157eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00401581: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401589: f30f1101 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x0040158d: 8b55fc MOV
        batch_guest_pc = 0x0040158du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00401590: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401598: f30f114204 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0040159d: 8b45fc MOV
        batch_guest_pc = 0x0040159du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x004015a0: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004015a8: f30f114008 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004015ad: 8b4d08 MOV
        batch_guest_pc = 0x004015adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x004015b0: 83c118 ADD
        t25a = state.regs[1];
        t25b = 0x00000018u;
        t25r = static_cast<std::uint32_t>(t25a + t25b) & 0xffffffffu;
        batch_set_add_flags(state, t25a, t25b, t25r, 32u);
        state.regs[1] = t25r;
    // 0x004015b3: 894df8 MOV
        batch_guest_pc = 0x004015b3u;
        t26 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t26)) return BatchLiftStatus::invalid_memory;
    // 0x004015b6: 8b55f8 MOV
        batch_guest_pc = 0x004015b6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x004015b9: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004015c1: f30f1102 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x004015c5: 8b45f8 MOV
        batch_guest_pc = 0x004015c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x004015c8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004015d0: f30f114004 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x004015d5: 8b4df8 MOV
        batch_guest_pc = 0x004015d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x004015d8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004015e0: f30f114108 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004015e5: 8b4508 MOV
        batch_guest_pc = 0x004015e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t36;
    // 0x004015e8: 8be5 MOV
        t37 = state.regs[5];
        state.regs[4] = t37;
    // 0x004015ea: 5d POP
        batch_guest_pc = 0x004015eau;
        if (!memory.load32(state.regs[4], t38a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t38a;
    // 0x004015eb: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
