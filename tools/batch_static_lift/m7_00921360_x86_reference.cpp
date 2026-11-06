#include "closure_reference_bytes.hpp"
#include "m7_float_data.hpp"
#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

static_assert(sizeof(void*) == 4, "native x86 build required");

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(0x30000000u), 0x1000,
        MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* table = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x01430000u), 0x10000,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* constant = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x013f0000u), 0x10000,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* object = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x20000000u), 0x1000,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!code || table != reinterpret_cast<void*>(0x01430000u) ||
        constant != reinterpret_cast<void*>(0x013f0000u) ||
        object != reinterpret_cast<void*>(0x20000000u)) {
        std::printf("map_failure code=%p table=%p constant=%p object=%p\n",
                    code, table, constant, object);
        return 2;
    }
    std::memcpy(table + 0xd850, kM7TableData.data(), kM7TableData.size());
    std::memcpy(constant + 0x4fd0, kM7Correction.data(), kM7Correction.size());
    for (const auto& instruction : kSporeInstructions_00921300)
        std::memcpy(code + instruction.address - 0x00921300u,
                    instruction.bytes.data(), instruction.length);
#if defined(M7_C0)
    for (const auto& instruction : kSporeInstructions_009213c0)
#else
    for (const auto& instruction : kSporeInstructions_00921360)
#endif
        std::memcpy(code + instruction.address - 0x00921300u,
                    instruction.bytes.data(), instruction.length);
    struct Case { std::uint32_t key, factor; };
    constexpr Case cases[] = {{0, 0x3f800000u}, {5, 0x3f000000u},
                              {0xffffffffu, 0x3eaaaaabu}, {0x80000000u, 0x3f800000u}};
    for (std::size_t i = 0; i < 4; ++i) {
        std::memset(object, 0, 16);
        std::memcpy(object, &cases[i].factor, 4);
#if defined(M7_C0)
        auto* entry = code + 0xc0;
#else
        auto* entry = code + 0x60;
#endif
        auto key_value = cases[i].key;
        std::uint32_t eax_value = 0, flags = 0, output = 0;
        __asm {
            mov ecx, object
            push key_value
            mov eax, entry
            call eax
            mov eax_value, eax
            pushfd
            pop flags
        }
        std::memcpy(&output, object + 8, 4);
        std::printf("case=%zu eax=%08x output=%08x flags=%08x\n",
                    i, eax_value, output, flags & 0x8d5u);
    }
    VirtualFree(object, 0, MEM_RELEASE);
    VirtualFree(constant, 0, MEM_RELEASE);
    VirtualFree(table, 0, MEM_RELEASE);
    VirtualFree(code, 0, MEM_RELEASE);
}
