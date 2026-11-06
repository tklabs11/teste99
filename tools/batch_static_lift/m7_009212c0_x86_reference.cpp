#include "closure_reference_bytes.hpp"
#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

static_assert(sizeof(void*) == 4, "native x86 build required");

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, 0x1000,
        MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* object = static_cast<std::uint32_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x20000000u), 0x1000,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!code || object != reinterpret_cast<void*>(0x20000000u)) return 2;
    for (const auto& instruction : kSporeInstructions_009212c0)
        std::memcpy(code + instruction.address - kSporeEntry_009212c0,
                    instruction.bytes.data(), instruction.length);
    constexpr std::uint32_t keys[] = {0, 5, 10, 5};
    constexpr std::uint32_t counts[] = {5, 5, 5, 0};
    for (std::size_t i = 0; i < 4; ++i) {
        for (unsigned j = 0; j < 5; ++j) object[j] = 2u*j+1u;
        std::uint32_t key = keys[i];
        std::uint32_t result = 0, flags = 0, saved_esi = 0, saved_edi = 0;
        auto* entry = code;
        auto* object_end = object + counts[i];
        auto* key_ptr = &key;
        __asm {
            mov esi, 0x66666666
            mov edi, 0x77777777
            push key_ptr
            push object_end
            push object
            mov eax, entry
            call eax
            mov result, eax
            pushfd
            pop flags
            add esp, 12
            mov saved_esi, esi
            mov saved_edi, edi
        }
        std::printf("case=%zu eax=%08x flags=%08x esi=%08x edi=%08x\n",
                    i, result, flags & 0x8d5u, saved_esi, saved_edi);
    }
    VirtualFree(object, 0, MEM_RELEASE);
    VirtualFree(code, 0, MEM_RELEASE);
}
