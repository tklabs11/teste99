#if !defined(_M_IX86)
#error This harness must run as a Windows x86 process.
#endif

#include <Windows.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "entry_bytes.hpp"

namespace {

volatile std::uint8_t cookie_seen = 0;
volatile std::uint8_t crt_seen = 0;

void write_marker_stub(std::uint8_t* destination, volatile std::uint8_t* marker) {
    // MOV byte ptr [absolute],1; RET. Both instructions preserve EFLAGS.
    std::array<std::uint8_t, 8> stub{0xc6, 0x05, 0, 0, 0, 0, 0x01, 0xc3};
    const auto pointer = reinterpret_cast<std::uint32_t>(marker);
    std::memcpy(stub.data() + 2, &pointer, sizeof(pointer));
    std::memcpy(destination, stub.data(), stub.size());
}

}  // namespace

int main() {
    constexpr std::uintptr_t region_address = 0x011e0000u;
    auto* region = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(region_address), 0x2000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    if (region != reinterpret_cast<void*>(region_address)) {
        std::puts("FAIL original_x86 fixed PE address unavailable");
        return 1;
    }

    // Generated from both verified PE files; cookie/CRT are test stubs.
    std::memcpy(reinterpret_cast<void*>(0x011e11a0u),
                kVerifiedPeEntryBytes.data(), kVerifiedPeEntryBytes.size());
    write_marker_stub(reinterpret_cast<std::uint8_t*>(0x011e1548u), &cookie_seen);
    write_marker_stub(reinterpret_cast<std::uint8_t*>(0x011e0ee0u), &crt_seen);
    FlushInstructionCache(GetCurrentProcess(), region, 0x2000u);

    using Entry = void(__cdecl*)();
    Entry entry = reinterpret_cast<Entry>(0x011e11a0u);
    std::uint32_t esp_before = 0, esp_after = 0;
    std::uint32_t flags_before = 0, flags_after = 0;
    __asm {
        stc
        pushfd
        pop eax
        mov flags_before, eax
        mov esp_before, esp
        mov eax, entry
        call eax
        mov esp_after, esp
        pushfd
        pop eax
        mov flags_after, eax
    }
    constexpr std::uint32_t comparable_flags = 0x8d5u;
    if (cookie_seen != 1 || crt_seen != 1 || esp_before != esp_after
            || ((flags_before ^ flags_after) & comparable_flags) != 0u) {
        std::printf("FAIL original_x86 cookie=%u crt=%u esp_before=0x%08x "
                    "esp_after=0x%08x flags_before=0x%08x flags_after=0x%08x\n",
                    cookie_seen, crt_seen, esp_before, esp_after,
                    flags_before, flags_after);
        return 1;
    }
    std::puts("PASS original_x86 entry_bytes=10 cookie=1 crt=1 "
              "stack=restored flags=preserved");
}
