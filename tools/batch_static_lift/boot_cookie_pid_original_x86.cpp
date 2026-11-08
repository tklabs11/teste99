// cpp / boot_cookie_pid_original_x86.cpp / Windows x86 / original Spore PE bytes
#if !defined(_M_IX86)
#error This harness must run as a Windows x86 process.
#endif

#include <Windows.h>

#include <cstdint>
#include <cstdio>
#include <cstring>

#include "cookie_reference_bytes.hpp"
#if defined(BOOT_ENTRY_CHAIN)
#include "entry_bytes.hpp"
#endif

namespace {

constexpr std::uint32_t kEntry = 0x011e1548u;
constexpr std::uint32_t kProgramEntry = 0x011e11a0u;
constexpr std::uint32_t kPePageBase = 0x011e1000u;
constexpr bool kPidCallExecuted =
    kCookieBoundaryAddress > kCookieProcessIdCallAddress;
constexpr bool kTidCallExecuted =
    kCookieBoundaryAddress > kCookieThreadIdCallAddress;
constexpr bool kTickCallExecuted =
    kCookieBoundaryAddress > kCookieTickCountCallAddress;
constexpr bool kQpcCallExecuted =
    kCookieBoundaryAddress > kCookiePerformanceCounterCallAddress;
constexpr bool kPidMixed =
    kCookieBoundaryAddress > kCookieProcessIdXorAddress;
constexpr bool kTidMixed =
    kCookieBoundaryAddress > kCookieThreadIdXorAddress;
constexpr bool kTickMixed =
    kCookieBoundaryAddress > kCookieTickCountXorAddress;
constexpr bool kQpcMixed =
    kCookieBoundaryAddress > kCookiePerformanceCounterXorAddress;

constexpr std::uint32_t executed_instruction_count() {
    switch (kCookieBoundaryAddress) {
        case 0x011e158bu: return 20u;
        case 0x011e1591u: return 21u;
        case 0x011e1593u: return 22u;
        case 0x011e1599u: return 23u;
        case 0x011e159bu: return 24u;
        case 0x011e15a1u: return 25u;
        case 0x011e15a3u: return 26u;
        case 0x011e15a6u: return 27u;
        case 0x011e15a7u: return 28u;
        case 0x011e15adu: return 29u;
        case 0x011e15b0u: return 30u;
        case 0x011e15b3u: return 31u;
        case 0x011e15b5u: return 32u;
        default: return 0u;
    }
}

volatile std::uint32_t g_before_call_esp = 0;
volatile std::uint32_t g_initial_ebp = 0;
volatile std::uint32_t g_runtime_boundary = 0;
CONTEXT g_boundary_context{};
std::uint32_t g_stack_words[10]{};
bool g_boundary_seen = false;
void* g_entry_pointer = nullptr;

// Recording thunks: the original bytes still reach the real Windows APIs, and
// the harness learns the exact value each API returned.
std::uint32_t g_time_low = 0;
std::uint32_t g_time_high = 0;
std::uint32_t g_pid = 0;
std::uint32_t g_tid = 0;
std::uint32_t g_tick = 0;
std::uint32_t g_qpc_low = 0;
std::uint32_t g_qpc_high = 0;
unsigned g_call_count = 0;

void __stdcall record_time(LPFILETIME value) {
    GetSystemTimeAsFileTime(value);
    ++g_call_count;
    if (value != nullptr) {
        g_time_low = value->dwLowDateTime;
        g_time_high = value->dwHighDateTime;
    }
}

std::uint32_t __stdcall record_process_id() {
    g_pid = GetCurrentProcessId();
    ++g_call_count;
    return g_pid;
}

std::uint32_t __stdcall record_thread_id() {
    g_tid = GetCurrentThreadId();
    ++g_call_count;
    return g_tid;
}

std::uint32_t __stdcall record_tick_count() {
    g_tick = GetTickCount();
    ++g_call_count;
    return g_tick;
}

std::int32_t __stdcall record_performance_counter(LARGE_INTEGER* value) {
    const std::int32_t result = QueryPerformanceCounter(value);
    ++g_call_count;
    if (result != 0 && value != nullptr) {
        g_qpc_low = static_cast<std::uint32_t>(
            static_cast<std::uint64_t>(value->QuadPart));
        g_qpc_high = static_cast<std::uint32_t>(
            static_cast<std::uint64_t>(value->QuadPart) >> 32u);
    }
    return result;
}

#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
// Executed by the function's own RET: the pushed return address points here.
extern "C" __declspec(naked) void cookie_return_stub() {
    __asm int 3
}
void* g_return_stub = nullptr;
#endif

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
#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
            push dword ptr [g_return_stub]
            jmp dword ptr [g_entry_pointer]
#else
            call dword ptr [g_entry_pointer]
#endif
        }
    } __except (capture_boundary(GetExceptionInformation())) {
        // The boundary snapshot was captured before leaving the original code.
    }
}

std::uint64_t filetime_now() {
    FILETIME now{};
    GetSystemTimeAsFileTime(&now);
    return static_cast<std::uint64_t>(now.dwLowDateTime) |
        (static_cast<std::uint64_t>(now.dwHighDateTime) << 32u);
}

}  // namespace

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* data = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (code == nullptr || data == nullptr) {
        std::puts("FAIL original_pid relocation allocation failed");
        return 1;
    }
    auto* cookie_code = code + (kEntry - kPePageBase);
#if defined(BOOT_ENTRY_CHAIN)
    auto* entry_code = code + (kProgramEntry - kPePageBase);
#endif
    std::memcpy(cookie_code, kCookieCodeBytes.data(), kCookieCodeBytes.size());
#if defined(BOOT_ENTRY_CHAIN)
    std::memcpy(entry_code, kVerifiedPeEntryBytes.data(),
                kVerifiedPeEntryBytes.size());
#endif
    // Relocate the PE's two data operands and both verified IAT slots. The
    // original indirect CALLs invoke the real Windows APIs through those slots.
    if (cookie_code[0x011e1550u - kEntry] != 0xa1u
            || cookie_code[0x011e1573u - kEntry] != 0xa3u) {
        std::puts("FAIL original_pid unexpected data operand encoding");
        return 1;
    }
    // Only instructions strictly below the boundary are copied and executed.
    const auto executes = [](std::uint32_t address) {
        return address < kCookieBoundaryAddress;
    };
    const auto encoded_call = [&](std::uint32_t address) {
        return !executes(address)
            || (cookie_code[address - kEntry] == 0xffu
                && cookie_code[address - kEntry + 1u] == 0x15u);
    };
    if (!encoded_call(kCookieTimeCallAddress)
            || !encoded_call(kCookieProcessIdCallAddress)
            || !encoded_call(kCookieThreadIdCallAddress)
            || !encoded_call(kCookieTickCountCallAddress)
            || !encoded_call(kCookiePerformanceCounterCallAddress)) {
        std::puts("FAIL original_pid unexpected instruction encoding");
        return 1;
    }
    const auto data_address = reinterpret_cast<std::uint32_t>(data);
    const auto complement_address = data_address + 4u;
    std::memcpy(cookie_code + (0x011e1550u - kEntry) + 1u, &data_address, 4);
    std::memcpy(cookie_code + (0x011e1573u - kEntry) + 1u,
                &complement_address, 4);
    // The cookie store at the end of the function also uses absolute operands.
    if (executes(0x011e15cbu) && executes(0x011e15d3u)) {
        if (cookie_code[0x011e15cbu - kEntry] != 0x89u
                || cookie_code[0x011e15cbu - kEntry + 1u] != 0x35u
                || cookie_code[0x011e15d3u - kEntry] != 0x89u
                || cookie_code[0x011e15d3u - kEntry + 1u] != 0x35u) {
            std::puts("FAIL original_pid unexpected cookie store encoding");
            return 1;
        }
        std::memcpy(cookie_code + (0x011e15cbu - kEntry) + 2u,
                    &data_address, 4u);
        std::memcpy(cookie_code + (0x011e15d3u - kEntry) + 2u,
                    &complement_address, 4u);
    }
    const auto install_slot = [&](std::uint32_t call_address,
                                  std::uint32_t slot_offset,
                                  const void* target) {
        if (!executes(call_address)) return;
        auto* slot = reinterpret_cast<std::uint32_t*>(data + slot_offset);
        *slot = reinterpret_cast<std::uint32_t>(target);
        const auto slot_address = reinterpret_cast<std::uint32_t>(slot);
        std::memcpy(cookie_code + (call_address - kEntry) + 2u,
                    &slot_address, 4u);
    };
    install_slot(kCookieTimeCallAddress, 0x100u, &record_time);
    install_slot(kCookieProcessIdCallAddress, 0x104u, &record_process_id);
    install_slot(kCookieThreadIdCallAddress, 0x108u, &record_thread_id);
    install_slot(kCookieTickCountCallAddress, 0x10cu, &record_tick_count);
    install_slot(kCookiePerformanceCounterCallAddress, 0x110u,
                 &record_performance_counter);
#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
    // The complete function returns through its own RET to the stub.
    g_return_stub = reinterpret_cast<void*>(&cookie_return_stub);
    g_entry_pointer = cookie_code;
    g_runtime_boundary =
        reinterpret_cast<std::uint32_t>(&cookie_return_stub);
#else
    cookie_code[kCookieBoundaryAddress - kEntry] = 0xccu;
    g_entry_pointer =
#if defined(BOOT_ENTRY_CHAIN)
        entry_code;
#else
        cookie_code;
#endif
    g_runtime_boundary = reinterpret_cast<std::uint32_t>(
        cookie_code + kCookieBoundaryAddress - kEntry);
#endif
    std::memcpy(data, kCookieInitialData.data(), kCookieInitialData.size());
    FlushInstructionCache(GetCurrentProcess(), code, 0x1000u);

#if defined(SPORE_COOKIE_FUNCTION_COMPLETE)
    execute_original();
    const auto* cookie = reinterpret_cast<const std::uint32_t*>(data);
    const std::uint32_t cookie_low = cookie[0];
    const std::uint32_t cookie_high = cookie[1];
    // The stub address was pushed in place of a CALL, so the function's RET
    // consumes it and leaves ESP at the value captured before that push.
    const bool returned = g_boundary_seen &&
        g_boundary_context.Eip ==
            reinterpret_cast<std::uint32_t>(&cookie_return_stub) &&
        g_boundary_context.Esp == g_before_call_esp;
    const bool registers_restored =
        g_boundary_context.Ebx == 0x44444444u &&
        g_boundary_context.Ebp == g_initial_ebp &&
        g_boundary_context.Esi == 0x66666666u &&
        g_boundary_context.Edi == 0x77777777u;
    const bool cookie_consistent = cookie_low != 0u &&
        (cookie_low & 0xffff0000u) != 0u && cookie_high == ~cookie_low;
    const bool imports_match = g_call_count == 5u &&
        g_pid != 0u && g_tid != 0u && g_time_low != 0u;
    if (!returned || !registers_restored || !cookie_consistent ||
            !imports_match) {
        std::printf("FAIL original_cookie_complete boundary=%d "
                    "eip=0x%08x esp=0x%08x ebx=0x%08x esi=0x%08x "
                    "returned=%d regs=%d cookie=%d imports=%d calls=%u\n",
                    g_boundary_seen, g_boundary_context.Eip,
                    g_boundary_context.Esp, g_boundary_context.Ebx,
                    g_boundary_context.Esi, returned, registers_restored,
                    cookie_consistent, imports_match, g_call_count);
        return 1;
    }
    std::printf("PASS cookie_complete returned=1 esp_delta=4 "
                "regs_restored=1 cookie_consistent=1 cookie_high_word=1 "
                "guards=1 imports=5 instructions=53\n");
    std::printf("DETAIL cookie_complete cookie=0x%08x complement=0x%08x\n",
                cookie_low, cookie_high);
    return 0;
#else
    const std::uint64_t before = filetime_now();
    execute_original();
    const std::uint64_t after = filetime_now();
    const auto entry_esp = g_before_call_esp -
#if defined(BOOT_ENTRY_CHAIN)
        8u;
#else
        4u;
#endif
    const auto& state = g_boundary_context;
    const bool registers_match =
        state.Ebx == 0xffff0000u && state.Esp == entry_esp - 32u &&
        state.Ebp == entry_esp - 4u && state.Edi == 0xbb40e64eu;
    const bool stack_matches =
        g_stack_words[0] == 0x66666666u &&
        g_stack_words[1] == 0x77777777u &&
        g_stack_words[2] == 0x44444444u &&
        g_stack_words[7] == g_initial_ebp;
    const bool entry_call_matches =
#if defined(BOOT_ENTRY_CHAIN)
        g_stack_words[8] == reinterpret_cast<std::uint32_t>(
            entry_code + 5u);
#else
        true;
#endif
    const bool data_matches = std::memcmp(
        data, kCookieInitialData.data(), kCookieInitialData.size()) == 0;
    // [EBP-8] holds the FILETIME the API wrote: words[5] low, words[6] high.
    const std::uint32_t time_low = g_time_low;
    const std::uint32_t time_high = g_time_high;
    const std::uint64_t filetime =
        static_cast<std::uint64_t>(time_low) |
        (static_cast<std::uint64_t>(time_high) << 32u);
    const bool time_matches =
        time_low != 0u && before <= filetime && filetime <= after &&
        g_stack_words[5] == time_low && g_stack_words[6] == time_high;
    // [EBP-0x10] holds the performance counter: words[3] low, words[4] high.
    const bool qpc_matches = !kQpcCallExecuted ||
        (g_qpc_low == g_stack_words[3] && g_qpc_high == g_stack_words[4]);
    const bool arguments_match = g_call_count ==
        (1u + (kPidCallExecuted ? 1u : 0u) + (kTidCallExecuted ? 1u : 0u)
         + (kTickCallExecuted ? 1u : 0u) + (kQpcCallExecuted ? 1u : 0u));
    const bool ids_present =
        (!kPidCallExecuted || g_pid != 0u) &&
        (!kTidCallExecuted || g_tid != 0u) &&
        (!kTickCallExecuted || g_tick != 0u);

    std::uint32_t expected_esi = time_low ^ time_high;
    if (kPidMixed) expected_esi ^= g_pid;
    if (kTidMixed) expected_esi ^= g_tid;
    if (kTickMixed) expected_esi ^= g_tick;
    if (kQpcMixed) expected_esi ^= g_qpc_low ^ g_qpc_high;
    const bool esi_matches = state.Esi == expected_esi;
    if (!g_boundary_seen || !registers_match || !stack_matches ||
            !entry_call_matches || !data_matches || !time_matches ||
            !qpc_matches || !arguments_match || !ids_present ||
            !esi_matches) {
        std::printf("FAIL original_pid boundary=%d eip=0x%08x "
                    "eax=0x%08x esp=0x%08x esi=0x%08x regs=%d stack=%d "
                    "entry_call=%d data=%d time=%d qpc=%d args=%d ids=%d "
                    "esi_mix=%d\n",
                    g_boundary_seen, state.Eip, state.Eax, state.Esp,
                    state.Esi, registers_match, stack_matches,
                    entry_call_matches, data_matches, time_matches,
                    qpc_matches, arguments_match, ids_present, esi_matches);
        return 1;
    }
    std::printf("PASS pid_prefix boundary=0x%08x executed=%u "
                "pid_call_executed=%u esp_delta=-32 ebp_delta=-4 "
                "ebx=0x%08x edi=0x%08x esi_mix=verified "
                "filetime=within_host_window data=unchanged\n",
                kCookieBoundaryAddress, executed_instruction_count(),
                kPidCallExecuted ? 1u : 0u, state.Ebx, state.Edi);
    const std::uint64_t qpc_value =
        static_cast<std::uint64_t>(g_qpc_low) |
        (static_cast<std::uint64_t>(g_qpc_high) << 32u);
    std::printf("DETAIL pid_prefix filetime_mix=0x%08x pid=0x%08x "
                "tid=0x%08x tick=0x%08x qpc=0x%016llx imports=%u\n",
                time_low ^ time_high, g_pid, g_tid, g_tick,
                static_cast<unsigned long long>(qpc_value), g_call_count);
#endif  // SPORE_COOKIE_FUNCTION_COMPLETE
}
