#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_00401720(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x00401720u);
    std::uint32_t t0a = 0;
    std::uint32_t t1 = 0;
    std::uint32_t t2a = 0, t2b = 0, t2r = 0;
    std::uint32_t t3 = 0;
    std::uint32_t t6 = 0;
    std::uint32_t t9 = 0;
    std::uint32_t t12 = 0;
    std::uint32_t t15 = 0;
    std::uint32_t t16a = 0, t16b = 0, t16r = 0;
    std::uint32_t t17 = 0;
    std::uint32_t t18 = 0;
    std::uint32_t t21 = 0;
    std::uint32_t t24 = 0;
    std::uint32_t t27 = 0;
    std::uint32_t t30 = 0;
    std::uint32_t t31a = 0, t31b = 0, t31r = 0;
    std::uint32_t t32 = 0;
    std::uint32_t t33 = 0;
    std::uint32_t t36 = 0;
    std::uint32_t t39 = 0;
    std::uint32_t t42 = 0;
    std::uint32_t t45 = 0;
    std::uint32_t t46a = 0, t46b = 0, t46r = 0;
    std::uint32_t t47 = 0;
    std::uint32_t t48 = 0;
    std::uint32_t t51 = 0;
    std::uint32_t t54 = 0;
    std::uint32_t t57 = 0;
    std::uint32_t t60 = 0;
    std::uint32_t t61 = 0;
    std::uint32_t t62a = 0;

    // 0x00401720: 55 PUSH
        batch_guest_pc = 0x00401720u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x00401721: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x00401723: 83ec0c SUB
        t2a = state.regs[4];
        t2b = 0x0000000cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x00401726: 8b4508 MOV
        batch_guest_pc = 0x00401726u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x00401729: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401731: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401735: 8b4d08 MOV
        batch_guest_pc = 0x00401735u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00401738: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401740: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00401745: 8b5508 MOV
        batch_guest_pc = 0x00401745u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00401748: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401750: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00401755: 8b4508 MOV
        batch_guest_pc = 0x00401755u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00401758: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401760: f30f11400c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00401765: 8b4d08 MOV
        batch_guest_pc = 0x00401765u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00401768: 83c110 ADD
        t16a = state.regs[1];
        t16b = 0x00000010u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x0040176b: 894dfc MOV
        batch_guest_pc = 0x0040176bu;
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0040176e: 8b55fc MOV
        batch_guest_pc = 0x0040176eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00401771: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401779: f30f1102 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x0040177d: 8b45fc MOV
        batch_guest_pc = 0x0040177du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00401780: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401788: f30f114004 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0040178d: 8b4dfc MOV
        batch_guest_pc = 0x0040178du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00401790: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401798: f30f114108 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0040179d: 8b55fc MOV
        batch_guest_pc = 0x0040179du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x004017a0: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004017a8: f30f11420c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x004017ad: 8b4508 MOV
        batch_guest_pc = 0x004017adu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x004017b0: 83c020 ADD
        t31a = state.regs[0];
        t31b = 0x00000020u;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[0] = t31r;
    // 0x004017b3: 8945f8 MOV
        batch_guest_pc = 0x004017b3u;
        t32 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x004017b6: 8b4df8 MOV
        batch_guest_pc = 0x004017b6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x004017b9: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004017c1: f30f1101 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x004017c5: 8b55f8 MOV
        batch_guest_pc = 0x004017c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x004017c8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004017d0: f30f114204 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x004017d5: 8b45f8 MOV
        batch_guest_pc = 0x004017d5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x004017d8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004017e0: f30f114008 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004017e5: 8b4df8 MOV
        batch_guest_pc = 0x004017e5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x004017e8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004017f0: f30f11410c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x004017f5: 8b5508 MOV
        batch_guest_pc = 0x004017f5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x004017f8: 83c230 ADD
        t46a = state.regs[2];
        t46b = 0x00000030u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[2] = t46r;
    // 0x004017fb: 8955f4 MOV
        batch_guest_pc = 0x004017fbu;
        t47 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x004017fe: 8b45f4 MOV
        batch_guest_pc = 0x004017feu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x00401801: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401809: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x0040180d: 8b4df4 MOV
        batch_guest_pc = 0x0040180du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x00401810: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401818: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0040181d: 8b55f4 MOV
        batch_guest_pc = 0x0040181du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t54;
    // 0x00401820: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401828: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0040182d: 8b45f4 MOV
        batch_guest_pc = 0x0040182du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x00401830: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401838: f30f11400c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x0040183d: 8b4508 MOV
        batch_guest_pc = 0x0040183du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x00401840: 8be5 MOV
        t61 = state.regs[5];
        state.regs[4] = t61;
    // 0x00401842: 5d POP
        batch_guest_pc = 0x00401842u;
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t62a;
    // 0x00401843: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
