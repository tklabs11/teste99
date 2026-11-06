#include <Windows.h>
#include <xmmintrin.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

static_assert(sizeof(void*) == 4, "native x86 build required");

int main() {
    unsigned short control = 0;
    __asm fnstcw control
    std::printf("x87_control=%04x mxcsr=%08x\n", control, _mm_getcsr());
    constexpr std::uint32_t values[] = {0, 1, 0x7fffffff, 0x80000000u,
                                         0xffffffffu, 0x12345678u};
    constexpr std::uint32_t factors[] = {0x3f800000u, 0x3f000000u,
                                          0x3eaaaaabu, 0x4f000000u};
    const float correction = 4294967296.0f;
    for (auto bits : factors) {
        float factor = 0;
        std::memcpy(&factor, &bits, 4);
        for (auto value : values) {
            float result = 0;
            __asm {
                fild value
                mov eax, value
                test eax, eax
                jge nonnegative
                fadd correction
            nonnegative:
                fmul factor
                fstp result
            }
            std::uint32_t result_bits = 0;
            std::memcpy(&result_bits, &result, 4);
            const long double precise = static_cast<long double>(value) *
                static_cast<long double>(factor);
            const float expected = static_cast<float>(precise);
            std::uint32_t expected_bits = 0;
            std::memcpy(&expected_bits, &expected, 4);
            std::printf("%s value=%08x factor=%08x x87=%08x precise=%08x\n",
                        result_bits == expected_bits ? "PASS" : "DIFF",
                        value, bits, result_bits, expected_bits);
        }
    }
}
