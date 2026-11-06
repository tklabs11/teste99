#include "BatchStaticLiftRuntime.hpp"
#include <cstdint>
#include <cstdio>
#include <cstring>

int main() {
    constexpr std::uint32_t inputs[] = {
        0x00000000u, 0x3f000000u, 0x3fc00000u, 0xbfc00000u,
        0x4f000000u, 0x7fc00000u, 0xbf800000u, 0x3f800000u,
    };
    for (std::size_t i = 0; i < sizeof(inputs)/sizeof(inputs[0]); ++i) {
        std::uint32_t result = 0, back = 0, flags = 0, moved = 0, truncated = 0;
        auto bits = inputs[i];
#if defined(_M_IX86)
        __asm {
            movss xmm0, bits
            cvttss2si edx, xmm0
            mov truncated, edx
            cvtss2si eax, xmm0
            mov result, eax
            cvtsi2ss xmm1, eax
            movss back, xmm1
            ucomiss xmm1, xmm0
            pushfd
            pop flags
            mov ecx, eax
            inc ecx
            // Restore UCOMISS flags before CMOVC.
            push flags
            popfd
            cmovc eax, ecx
            mov moved, eax
        }
#else
        BatchLiftState state{};
        state.xmm[0][0] = bits;
        BatchLiftMemory memory;
        memory.store32(BatchLiftMemory::kEntryEsp + 4u, bits);
        if (!batch_guest_cvttss2si_memory(memory, state, 2,
                BatchLiftMemory::kEntryEsp + 4u)) return 4;
        truncated = state.regs[2];
        if (!batch_guest_cvtss2si(state, 0, 0) ||
            !batch_guest_cvtsi2ss(state, 1, 0)) return 2;
        result = state.regs[0];
        back = state.xmm[1][0];
        if (!batch_guest_ucomiss(state, 1, 0)) return 3;
        flags = state.eflags;
        moved = (flags & 1u) ? result + 1u : result;
#endif
        std::printf("case=%zu input=%08x trunc=%08x result=%08x back=%08x flags=%03x moved=%08x\n",
                    i, bits, truncated, result, back, flags & 0x8c5u, moved);
    }
}
