#include <cstdint>
#include <cstdio>

extern "C" {

std::uint32_t lifting_add(std::uint32_t a, std::uint32_t b) {
    return a + b;
}

std::uint32_t lifting_mul(std::uint32_t a, std::uint32_t b) {
    return a * b;
}

std::uint32_t lifting_mix(std::uint32_t a, std::uint32_t b) {
    return (a << 3u) ^ ((b >> 2u) + 0x9E3779B9u);
}

std::uint32_t lifting_accumulate(const std::uint32_t* values, std::size_t count) {
    std::uint32_t result = 0;
    for (std::size_t i = 0; i < count; ++i) {
        result = lifting_mix(result, values[i]);
    }
    return result;
}

} // extern "C"

int main() {
    const std::uint32_t values[] = {0u, 1u, 0x7FFFFFFFu, 0x80000000u, 0xFFFFFFFFu};
    std::printf("add=%08X\n", lifting_add(0xFFFFFFFFu, 2u));
    std::printf("mul=%08X\n", lifting_mul(0x80000000u, 3u));
    std::printf("mix=%08X\n", lifting_mix(0x12345678u, 0xABCDEF01u));
    std::printf("accumulate=%08X\n", lifting_accumulate(values, 5u));
    return 0;
}
