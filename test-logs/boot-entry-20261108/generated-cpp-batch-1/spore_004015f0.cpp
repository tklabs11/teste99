#include "BatchStaticLiftRuntime.hpp"


BatchLiftStatus spore_lift_004015f0(BatchLiftMemory& memory, BatchLiftState& state) {
    batch_guest_note_body(0x004015f0u);
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

    // 0x004015f0: 55 PUSH
        batch_guest_pc = 0x004015f0u;
        t0a = state.regs[5];
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] - 4u);
        if (!memory.store32(state.regs[4], t0a)) return BatchLiftStatus::invalid_memory;
    // 0x004015f1: 8bec MOV
        t1 = state.regs[4];
        state.regs[5] = t1;
    // 0x004015f3: 83ec0c SUB
        t2a = state.regs[4];
        t2b = 0x0000000cu;
        t2r = static_cast<std::uint32_t>(t2a - t2b) & 0xffffffffu;
        batch_set_sub_flags(state, t2a, t2b, t2r, 32u);
        state.regs[4] = t2r;
    // 0x004015f6: 8b4508 MOV
        batch_guest_pc = 0x004015f6u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t3)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t3;
    // 0x004015f9: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00401601: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401605: 8b4d08 MOV
        batch_guest_pc = 0x00401605u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t6)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t6;
    // 0x00401608: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401610: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x00401615: 8b5508 MOV
        batch_guest_pc = 0x00401615u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t9)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t9;
    // 0x00401618: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401620: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x00401625: 8b4508 MOV
        batch_guest_pc = 0x00401625u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t12)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t12;
    // 0x00401628: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401630: f30f11400c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x00401635: 8b4d08 MOV
        batch_guest_pc = 0x00401635u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t15)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t15;
    // 0x00401638: 83c110 ADD
        t16a = state.regs[1];
        t16b = 0x00000010u;
        t16r = static_cast<std::uint32_t>(t16a + t16b) & 0xffffffffu;
        batch_set_add_flags(state, t16a, t16b, t16r, 32u);
        state.regs[1] = t16r;
    // 0x0040163b: 894dfc MOV
        batch_guest_pc = 0x0040163bu;
        t17 = state.regs[1];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t17)) return BatchLiftStatus::invalid_memory;
    // 0x0040163e: 8b55fc MOV
        batch_guest_pc = 0x0040163eu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t18)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t18;
    // 0x00401641: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401649: f30f1102 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x0040164d: 8b45fc MOV
        batch_guest_pc = 0x0040164du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t21)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t21;
    // 0x00401650: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00401658: f30f114004 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x0040165d: 8b4dfc MOV
        batch_guest_pc = 0x0040165du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t24)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t24;
    // 0x00401660: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401668: f30f114108 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x0040166d: 8b55fc MOV
        batch_guest_pc = 0x0040166du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffffcu), t27)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t27;
    // 0x00401670: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401678: f30f11420c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x0040167d: 8b4508 MOV
        batch_guest_pc = 0x0040167du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t30)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t30;
    // 0x00401680: 83c020 ADD
        t31a = state.regs[0];
        t31b = 0x00000020u;
        t31r = static_cast<std::uint32_t>(t31a + t31b) & 0xffffffffu;
        batch_set_add_flags(state, t31a, t31b, t31r, 32u);
        state.regs[0] = t31r;
    // 0x00401683: 8945f8 MOV
        batch_guest_pc = 0x00401683u;
        t32 = state.regs[0];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t32)) return BatchLiftStatus::invalid_memory;
    // 0x00401686: 8b4df8 MOV
        batch_guest_pc = 0x00401686u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t33)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t33;
    // 0x00401689: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x00401691: f30f1101 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x00401695: 8b55f8 MOV
        batch_guest_pc = 0x00401695u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t36)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t36;
    // 0x00401698: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004016a0: f30f114204 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x004016a5: 8b45f8 MOV
        batch_guest_pc = 0x004016a5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t39)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t39;
    // 0x004016a8: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x004016b0: f30f114008 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004016b5: 8b4df8 MOV
        batch_guest_pc = 0x004016b5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff8u), t42)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t42;
    // 0x004016b8: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004016c0: f30f11410c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x004016c5: 8b5508 MOV
        batch_guest_pc = 0x004016c5u;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t45)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t45;
    // 0x004016c8: 83c230 ADD
        t46a = state.regs[2];
        t46b = 0x00000030u;
        t46r = static_cast<std::uint32_t>(t46a + t46b) & 0xffffffffu;
        batch_set_add_flags(state, t46a, t46b, t46r, 32u);
        state.regs[2] = t46r;
    // 0x004016cb: 8955f4 MOV
        batch_guest_pc = 0x004016cbu;
        t47 = state.regs[2];
        if (!memory.store32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t47)) return BatchLiftStatus::invalid_memory;
    // 0x004016ce: 8b45f4 MOV
        batch_guest_pc = 0x004016ceu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t48)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t48;
    // 0x004016d1: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004016d9: f30f1100 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x00000000u))) return BatchLiftStatus::invalid_memory;
    // 0x004016dd: 8b4df4 MOV
        batch_guest_pc = 0x004016ddu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t51)) return BatchLiftStatus::invalid_memory;
        state.regs[1] = t51;
    // 0x004016e0: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004016e8: f30f114104 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[1] + 0x00000004u))) return BatchLiftStatus::invalid_memory;
    // 0x004016ed: 8b55f4 MOV
        batch_guest_pc = 0x004016edu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t54)) return BatchLiftStatus::invalid_memory;
        state.regs[2] = t54;
    // 0x004016f0: f30f100570534801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485370u)) return BatchLiftStatus::invalid_memory;
    // 0x004016f8: f30f114208 MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[2] + 0x00000008u))) return BatchLiftStatus::invalid_memory;
    // 0x004016fd: 8b45f4 MOV
        batch_guest_pc = 0x004016fdu;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0xfffffff4u), t57)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t57;
    // 0x00401700: f30f100518574801 MOVSS
        if (!batch_guest_movss_load(memory, state, 0u, 0x01485718u)) return BatchLiftStatus::invalid_memory;
    // 0x00401708: f30f11400c MOVSS
        if (!batch_guest_movss_store(memory, state, 0u, static_cast<std::uint32_t>(state.regs[0] + 0x0000000cu))) return BatchLiftStatus::invalid_memory;
    // 0x0040170d: 8b4508 MOV
        batch_guest_pc = 0x0040170du;
        if (!memory.load32(static_cast<std::uint32_t>(state.regs[5] + 0x00000008u), t60)) return BatchLiftStatus::invalid_memory;
        state.regs[0] = t60;
    // 0x00401710: 8be5 MOV
        t61 = state.regs[5];
        state.regs[4] = t61;
    // 0x00401712: 5d POP
        batch_guest_pc = 0x00401712u;
        if (!memory.load32(state.regs[4], t62a)) return BatchLiftStatus::invalid_memory;
        state.regs[4] = static_cast<std::uint32_t>(state.regs[4] + 4u);
        state.regs[5] = t62a;
    // 0x00401713: c3 RET
        if (!batch_guest_return32(memory, state, 0u)) return BatchLiftStatus::invalid_memory;
        return BatchLiftStatus::returned;
}
