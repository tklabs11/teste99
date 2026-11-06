#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <initializer_list>

static_assert(sizeof(void*) == 4, "native x86 build required");

struct DivResult {
    std::uint32_t quotient = 0;
    std::uint32_t remainder = 0;
    std::uint32_t exception = 0;
};

__declspec(noinline) DivResult native_div(
    std::uint32_t upper, std::uint32_t bottom, std::uint32_t divisor) {
    DivResult result{};
    __try {
        __asm {
            mov edx, upper
            mov eax, bottom
            mov ecx, divisor
            div ecx
            mov result.quotient, eax
            mov result.remainder, edx
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        result.exception = GetExceptionCode();
    }
    return result;
}

__declspec(noinline) void native_imul(
    std::uint32_t left, std::uint32_t right,
    std::uint32_t* result, std::uint32_t* flags) {
    __asm {
        mov eax, left
        mov ecx, right
        imul eax, ecx
        mov edx, result
        mov [edx], eax
        pushfd
        pop eax
        mov edx, flags
        mov [edx], eax
    }
}

__declspec(noinline) void native_sar(
    std::uint32_t value, std::uint32_t shift,
    std::uint32_t* result, std::uint32_t* flags) {
    __asm {
        mov eax, value
        mov ecx, shift
        sar eax, cl
        mov edx, result
        mov [edx], eax
        pushfd
        pop eax
        mov edx, flags
        mov [edx], eax
    }
}

int main() {
    struct DivCase { std::uint32_t high, low, divisor; };
    constexpr DivCase div_cases[] = {
        {0, 0xffffffffu, 1}, {1, 0, 2}, {0, 10, 3},
        {0, 10, 0}, {1, 0, 1}, {0xffffffffu, 0xffffffffu, 1},
    };
    for (std::size_t i = 0; i < 6; ++i) {
        auto test = div_cases[i];
        const auto native = native_div(test.high, test.low, test.divisor);
        const std::uint64_t dividend = (std::uint64_t{test.high} << 32u) | test.low;
        const bool error = test.divisor == 0 ||
            (test.divisor != 0 && dividend / test.divisor > 0xffffffffull);
        const bool equal = error
            ? native.exception == (test.divisor == 0
                ? EXCEPTION_INT_DIVIDE_BY_ZERO : EXCEPTION_INT_OVERFLOW)
            : native.exception == 0 && native.quotient == dividend / test.divisor &&
              native.remainder == dividend % test.divisor;
        std::printf("%s DIV case=%zu exception=%08x quotient=%08x remainder=%08x\n",
                    equal ? "PASS" : "FAIL", i, native.exception,
                    native.quotient, native.remainder);
        if (!equal) return 2;
    }
    struct MulCase { std::uint32_t left, right; };
    constexpr MulCase mul_cases[] = {
        {0, 0}, {1, 0xffffffffu}, {0x7fffffffu, 2},
        {0x80000000u, 1}, {0x80000000u, 0xffffffffu},
    };
    for (std::size_t i = 0; i < 5; ++i) {
        auto test = mul_cases[i];
        std::uint32_t result = 0, flags = 0;
        native_imul(test.left, test.right, &result, &flags);
        const std::int64_t product =
            static_cast<std::int64_t>(static_cast<std::int32_t>(test.left)) *
            static_cast<std::int32_t>(test.right);
        const bool overflow = product < -2147483648ll || product > 2147483647ll;
        const bool equal = result == static_cast<std::uint32_t>(product) &&
            (flags & 0x801u) == (overflow ? 0x801u : 0u);
        std::printf("%s IMUL case=%zu result=%08x cf_of=%03x\n",
                    equal ? "PASS" : "FAIL", i, result, flags & 0x801u);
        if (!equal) return 3;
    }
    constexpr std::uint32_t shift_values[] = {0, 1, 2, 0x7fffffffu,
                                               0x80000000u, 0xffffffffu};
    for (auto count : {1u, 2u}) {
        for (auto value : shift_values) {
            std::uint32_t result = 0, flags = 0;
            native_sar(value, count, &result, &flags);
            const std::uint32_t expected = (value >> count) |
                ((value & 0x80000000u) ? (0xffffffffu << (32u-count)) : 0u);
            const bool carry = (value & (1u << (count-1u))) != 0u;
            const bool sign = (expected & 0x80000000u) != 0u;
            const bool zero = expected == 0u;
            std::uint8_t bits = static_cast<std::uint8_t>(expected);
            bits ^= bits >> 4u;
            bits ^= bits >> 2u;
            bits ^= bits >> 1u;
            const bool parity = (bits & 1u) == 0u;
            const std::uint32_t expected_flags = (carry ? 1u : 0u) |
                (parity ? 4u : 0u) | (zero ? 0x40u : 0u) | (sign ? 0x80u : 0u);
            const bool equal = result == expected &&
                (flags & 0xc5u) == expected_flags &&
                (count != 1u || (flags & 0x800u) == 0u);
            std::printf("%s SAR count=%u value=%08x result=%08x flags=%03x\n",
                        equal ? "PASS" : "FAIL", count, value, result, flags & 0x8c5u);
            if (!equal) return 4;
        }
    }
}
