#if !defined(_M_IX86)
#error This harness must run as a Windows x86 process.
#endif

#include <Windows.h>

#include <cstdint>
#include <cstdio>
#include <cstring>

#include "cookie_reference_bytes.hpp"
#include "entry_bytes.hpp"

namespace {

constexpr std::uint32_t kEntry = 0x011e1548u;
constexpr std::uint32_t kBoundary = 0x011e157fu;
constexpr std::uint32_t kProgramEntry = 0x011e11a0u;
constexpr std::uint32_t kPePageBase = 0x011e1000u;
constexpr std::uint32_t kComparableFlags = 0x8d5u;

volatile std::uint32_t g_before_call_esp = 0;
volatile std::uint32_t g_initial_ebp = 0;
volatile std::uint32_t g_runtime_boundary = 0;
CONTEXT g_boundary_context{};
std::uint32_t g_stack_words[10]{};
bool g_boundary_seen = false;
void* g_entry_pointer = nullptr;

int capture_boundary(EXCEPTION_POINTERS* exception) {
    if (exception == nullptr || exception->ExceptionRecord == nullptr
            || exception->ContextRecord == nullptr
            || exception->ExceptionRecord->ExceptionCode != EXCEPTION_BREAKPOINT
            || exception->ContextRecord->Eip != g_runtime_boundary) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    g_boundary_context = *exception->ContextRecord;
    auto* stack = reinterpret_cast<const std::uint32_t*>(
        static_cast<std::uintptr_t>(g_boundary_context.Esp));
    for (unsigned index = 0; index < 10; ++index) {
        g_stack_words[index] = stack[index];
    }
    g_boundary_seen = true;
    return EXCEPTION_EXECUTE_HANDLER;
}

__declspec(noinline) void execute_original() {
    __try {
        __asm {
            mov ecx, 0x22222222
            mov edx, 0x33333333
            mov ebx, 0x44444444
            mov esi, 0x66666666
            mov edi, 0x77777777
            mov g_initial_ebp, ebp
            mov eax, 0x11111111
            push 0x202
            popfd
            mov g_before_call_esp, esp
            call dword ptr [g_entry_pointer]
        }
    } __except (capture_boundary(GetExceptionInformation())) {
        // The boundary snapshot was captured before the original API call.
    }
}

}  // namespace

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* data = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (code == nullptr || data == nullptr) {
        std::puts("FAIL original_cookie relocation allocation failed");
        return 1;
    }
    auto* cookie_code = code + (kEntry - kPePageBase);
    auto* entry_code = code + (kProgramEntry - kPePageBase);
    std::memcpy(cookie_code, kCookieCodeBytes.data(), kCookieCodeBytes.size());
    std::memcpy(entry_code, kVerifiedPeEntryBytes.data(),
                kVerifiedPeEntryBytes.size());
    // The PE has absolute [0x015cfe70]/[0x015cfe74] operands. Relocate only
    // those two addresses to the copied data and replace the boundary CALL
    // with INT3 so that the Win32 API is never invoked by this harness.
    if (cookie_code[0x011e1550u - kEntry] != 0xa1u
            || cookie_code[0x011e1573u - kEntry] != 0xa3u
            || cookie_code[kBoundary - kEntry] != 0xffu) {
        std::puts("FAIL original_cookie unexpected instruction encoding");
        return 1;
    }
    const auto data_address = reinterpret_cast<std::uint32_t>(data);
    const auto complement_address = data_address + 4u;
    std::memcpy(cookie_code + (0x011e1550u - kEntry) + 1u, &data_address, 4);
    std::memcpy(cookie_code + (0x011e1573u - kEntry) + 1u,
                &complement_address, 4);
    cookie_code[kBoundary - kEntry] = 0xccu;
    std::memcpy(data, kCookieInitialData.data(), kCookieInitialData.size());
    g_entry_pointer =
#if defined(BOOT_ENTRY_CHAIN)
        entry_code;
#else
        cookie_code;
#endif
    g_runtime_boundary = reinterpret_cast<std::uint32_t>(
        cookie_code + kBoundary - kEntry);
    FlushInstructionCache(GetCurrentProcess(), code, 0x1000u);

    execute_original();
    const auto entry_esp = g_before_call_esp -
#if defined(BOOT_ENTRY_CHAIN)
        8u;
#else
        4u;
#endif
    const auto& state = g_boundary_context;
    const bool registers_match =
        state.Eax == entry_esp - 12u &&
        state.Ecx == 0x22222222u && state.Edx == 0x33333333u &&
        state.Ebx == 0xffff0000u && state.Esp == entry_esp - 36u &&
        state.Ebp == entry_esp - 4u && state.Esi == 0x66666666u &&
        state.Edi == 0xbb40e64eu;
    const bool stack_matches =
        g_stack_words[0] == entry_esp - 12u &&
        g_stack_words[1] == 0x66666666u &&
        g_stack_words[2] == 0x77777777u &&
        g_stack_words[3] == 0x44444444u &&
        g_stack_words[6] == 0u &&
        g_stack_words[7] == 0u &&
        g_stack_words[8] == g_initial_ebp;
    const bool entry_call_matches =
#if defined(BOOT_ENTRY_CHAIN)
        g_stack_words[9] == reinterpret_cast<std::uint32_t>(
            entry_code + 5u);
#else
        true;
#endif
    const bool data_matches = std::memcmp(
        data, kCookieInitialData.data(), kCookieInitialData.size()) == 0;
    if (!g_boundary_seen || !registers_match || !stack_matches ||
            !entry_call_matches ||
            !data_matches || (state.EFlags & kComparableFlags) != 0x44u) {
        std::printf("FAIL original_cookie boundary=%d eip=0x%08x "
                    "eax=0x%08x esp=0x%08x flags=0x%08x regs=%d stack=%d data=%d\n",
                    g_boundary_seen, state.Eip, state.Eax, state.Esp,
                    state.EFlags, registers_match, stack_matches, data_matches);
        return 1;
    }
#if defined(BOOT_ENTRY_CHAIN)
    std::printf("PASS boot_entry_prefix boundary=0x%08x executed=17 "
#else
    std::printf("PASS cookie_prefix boundary=0x%08x executed=16 "
#endif
                "eax_stack_delta=-12 esp_delta=-36 ebp_delta=-4 "
                "ebx=0x%08x edi=0x%08x flags=0x%03x "
                "locals=zero data=unchanged\n",
                kBoundary, state.Ebx, state.Edi,
                state.EFlags & kComparableFlags);
}
