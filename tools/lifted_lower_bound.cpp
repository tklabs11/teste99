#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

extern "C" {

struct SporeKeyRecord {
    std::uint32_t key;
    std::uint32_t payload_a;
    std::uint32_t payload_b;
};

const SporeKeyRecord* spore_lower_bound_candidate(
    const SporeKeyRecord* begin,
    const SporeKeyRecord* end,
    const std::uint32_t* key) {
    std::size_t count = static_cast<std::size_t>(end - begin);
    while (count > 0) {
        std::size_t half = count >> 1;
        const SporeKeyRecord* middle = begin + half;
        if (middle->key < *key) {
            begin = middle + 1;
            count -= half + 1;
        } else {
            count = half;
        }
    }
    return begin;
}

} // extern "C"

#ifndef SPORE_CANDIDATE_LIBRARY
static std::uint32_t checksum_pointer(const SporeKeyRecord* base, const SporeKeyRecord* found) {
    return static_cast<std::uint32_t>(found - base);
}

int main() {
    const SporeKeyRecord records[] = {
        {0x00000000u, 10u, 20u},
        {0x00000008u, 11u, 21u},
        {0x00000010u, 12u, 22u},
        {0x00000020u, 13u, 23u},
        {0xFFFFFFFFu, 14u, 24u},
    };
    constexpr std::size_t count = sizeof(records) / sizeof(records[0]);

    const std::uint32_t keys[] = {0u, 7u, 8u, 9u, 16u, 24u, 0xFFFFFFFFu, 0xFFFFFFFEu};
    for (std::size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i) {
        const SporeKeyRecord* found =
            spore_lower_bound_candidate(records, records + count, &keys[i]);
        std::printf("lower_bound_%08X=%u\n", keys[i], checksum_pointer(records, found));
    }
    return 0;
}
#endif
