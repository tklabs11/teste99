#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

extern "C" {

// Candidate reconstructed from PE RVA 0xD58BE0 / VA 0x1158BE0.
// x86 stack offsets observed by direct disassembly: count=[ebp+8],
// scalar=[ebp+12], source=[ebp+16], destination=[ebp+20].
void spore_array_multiply_add_candidate(
    std::size_t count,
    float scalar,
    const float* source,
    float* destination) {
    if (source == nullptr || destination == nullptr) {
        return;
    }
    for (std::size_t i = 0; i < count; ++i) {
        destination[i] += scalar * source[i];
    }
}

} // extern "C"

#ifndef SPORE_CANDIDATE_LIBRARY
static std::uint32_t checksum_floats(const float* values, std::size_t count) {
    std::uint32_t result = 0x811C9DC5u;
    for (std::size_t i = 0; i < count; ++i) {
        std::uint32_t bits = 0;
        std::memcpy(&bits, &values[i], sizeof(bits));
        result ^= bits;
        result *= 0x01000193u;
    }
    return result;
}

int main() {
    float destination[] = {1.0f, -2.0f, 0.25f, 8.0f, 3.5f, -0.125f, 2.0f, 0.0f};
    float source[] = {0.5f, 2.0f, -4.0f, 0.125f, -3.0f, 7.0f, 0.75f, -9.0f};
    constexpr float scalar = 1.25f;
    constexpr std::size_t count = sizeof(destination) / sizeof(destination[0]);

    spore_array_multiply_add_candidate(count, scalar, source, destination);
    std::printf("array_multiply_add=%08X\n", checksum_floats(destination, count));
    return 0;
}
#endif
