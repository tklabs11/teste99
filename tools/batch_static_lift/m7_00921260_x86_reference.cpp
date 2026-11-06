#include "closure_reference_bytes.hpp"

#include <Windows.h>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

static_assert(sizeof(void*) == 4, "native x86 build required");

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(nullptr, 0x1000,
        MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    if (!code) return 2;
    for (const auto& instruction : kSporeInstructions_00921260) {
        std::memcpy(code + instruction.address - kSporeEntry_00921260,
                    instruction.bytes.data(), instruction.length);
    }
    struct Case { std::uint32_t alignment, length, stride; };
    constexpr Case cases[] = {{4, 0x960, 12}, {1, 16, 4}, {0, 0, 4}};
    for (std::size_t i = 0; i < 3; ++i) {
        auto* object = static_cast<std::uint8_t*>(VirtualAlloc(
            reinterpret_cast<void*>(0x20000000u), 0x1000,
            MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        if (object != reinterpret_cast<void*>(0x20000000u)) return 3;
        std::uint32_t output = 0, result = 0, flags = 0;
        auto* entry = code;
        auto* output_ptr = &output;
        auto alignment = cases[i].alignment;
        auto item_length = cases[i].length;
        auto stride = cases[i].stride;
        __asm {
            mov ecx, output_ptr
            push 0
            push alignment
            push stride
            push item_length
            push object
            mov eax, entry
            call eax
            mov result, eax
            pushfd
            pop flags
        }
        std::printf("case=%zu result=%08x flags=%08x output=%08x object=",
                    i, result, flags & 0x8d5u, output);
        for (std::size_t j = 0; j < 0x1000; ++j) std::printf("%02x", object[j]);
        std::printf("\n");
        VirtualFree(object, 0, MEM_RELEASE);
    }
    VirtualFree(code, 0, MEM_RELEASE);
}
