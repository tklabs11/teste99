// cpp / boot_entry_crt_original_x86.cpp / Windows x86 / original Spore PE entry bytes
#if !defined(_M_IX86)
#error This harness must run as a Windows x86 process.
#endif
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "cookie_reference_bytes.hpp"
#include "crt_reference_bytes.hpp"
#include "entry_bytes.hpp"

namespace {

constexpr std::uint32_t kPageBase = 0x011e0000u;
constexpr std::uint32_t kPageBytes = 0x2000u;
constexpr std::uint32_t kEntry = 0x011e11a0u;
constexpr std::uint32_t kCookieEntry = 0x011e1548u;
constexpr std::uint32_t kCookieInstructions = 53u;
constexpr std::uint32_t kStartupInfoDwords = 0x44u / 4u;
constexpr std::uint32_t kSeedStartupInfoCb = 0x44u;
// The startup lock lives in loader zero filled .data; the harness owns an
// equivalent zeroed block and rewrites the three absolute operands.
constexpr std::uint32_t kLockBlockOffset = 0x200u;
constexpr std::uint32_t kLockBlockBytes = 0x20u;
constexpr std::uint32_t kLockStateDelta = 0x0cu;
constexpr std::uint32_t kLockDelta = 0x10u;

volatile std::uint32_t g_before_call_esp = 0;
volatile std::uint32_t g_initial_ebp = 0;
volatile std::uint32_t g_saved_fs0 = 0;
volatile std::uint32_t g_ctx_esp = 0;
volatile std::uint32_t g_ctx_ebp = 0;
volatile std::uint32_t g_ctx_eax = 0;
volatile std::uint32_t g_ctx_ebx = 0;
volatile std::uint32_t g_ctx_ecx = 0;
volatile std::uint32_t g_ctx_edx = 0;
volatile std::uint32_t g_ctx_esi = 0;
volatile std::uint32_t g_ctx_edi = 0;
volatile std::uint32_t g_ctx_eflags = 0;
volatile std::uint32_t g_stub_entered = 0;
volatile std::uint32_t g_runtime_boundary = 0;
bool g_boundary_seen = false;
void* g_entry_pointer = nullptr;
std::uint32_t g_lock_state_address = 0;
std::uint32_t g_lock_address = 0;

std::uint32_t g_time_low = 0;
std::uint32_t g_pid = 0;
std::uint32_t g_tid = 0;
std::uint32_t g_tick = 0;
unsigned g_call_count = 0;
bool g_startupinfo_called = false;
const void* g_startupinfo_address = nullptr;
bool g_interlocked_called = false;
std::uint32_t g_interlocked_previous = 0;
std::uint32_t g_interlocked_destination = 0;
std::uint32_t g_interlocked_exchange = 0;
std::uint32_t g_interlocked_comparand = 0;

// The guest code installs its own SEH record while the original CRT prologue
// runs. The stub restores the real chain before raising the breakpoint so the
// dispatcher still finds this harness frame.
extern "C" __declspec(naked) void boundary_stub() {
    __asm {
        mov dword ptr [g_stub_entered], 1
        mov dword ptr [g_ctx_esp], esp
        mov dword ptr [g_ctx_eax], eax
        mov dword ptr [g_ctx_ebx], ebx
        mov dword ptr [g_ctx_ecx], ecx
        mov dword ptr [g_ctx_edx], edx
        mov dword ptr [g_ctx_esi], esi
        mov dword ptr [g_ctx_edi], edi
        mov dword ptr [g_ctx_ebp], ebp
        pushfd
        pop dword ptr [g_ctx_eflags]
        mov eax, dword ptr [g_saved_fs0]
        mov fs:[0], eax
        mov eax, dword ptr [g_ctx_eax]
        int 3
    }
}

void __stdcall record_time(LPFILETIME value) {
    GetSystemTimeAsFileTime(value);
    ++g_call_count;
    if (value != nullptr) g_time_low = value->dwLowDateTime;
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
    return result;
}

void __stdcall record_startup_info(LPSTARTUPINFOA value) {
    GetStartupInfoA(value);
    ++g_call_count;
    g_startupinfo_called = true;
    g_startupinfo_address = value;
}

LONG __stdcall record_interlocked_compare_exchange(
    LONG volatile* destination, LONG exchange, LONG comparand) {
    const LONG previous =
        InterlockedCompareExchange(destination, exchange, comparand);
    ++g_call_count;
    g_interlocked_called = true;
    g_interlocked_previous = static_cast<std::uint32_t>(previous);
    g_interlocked_destination = reinterpret_cast<std::uint32_t>(destination);
    g_interlocked_exchange = static_cast<std::uint32_t>(exchange);
    g_interlocked_comparand = static_cast<std::uint32_t>(comparand);
    return previous;
}

// A pointer the guest could dereference: committed readable memory holding a
// NUL-terminated string. The guest mock reports NULL for these instead.
bool is_readable_string(std::uint32_t address) {
    if (address == 0u) return true;
    std::uint32_t cursor = address;
    for (unsigned index = 0; index < 260u; ++index) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(reinterpret_cast<const void*>(
                             static_cast<std::uintptr_t>(cursor)),
                         &info, sizeof(info)) != sizeof(info)) {
            return false;
        }
        if (info.State != MEM_COMMIT
                || (info.Protect & (PAGE_NOACCESS | PAGE_GUARD)) != 0u) {
            return false;
        }
        const auto* byte = reinterpret_cast<const char*>(
            static_cast<std::uintptr_t>(cursor));
        if (*byte == '\0') return true;
        ++cursor;
    }
    return false;
}

LONG CALLBACK report_fault(EXCEPTION_POINTERS* exception) {
    if (exception != nullptr && exception->ExceptionRecord != nullptr
            && exception->ExceptionRecord->ExceptionCode != EXCEPTION_BREAKPOINT
            && exception->ContextRecord != nullptr) {
        std::printf("DIAG fault code=0x%08x address=0x%08x eip=0x%08x "
                    "esp=0x%08x eax=0x%08x ecx=0x%08x edx=0x%08x\n",
                    static_cast<unsigned>(
                        exception->ExceptionRecord->ExceptionCode),
                    reinterpret_cast<std::uint32_t>(
                        exception->ExceptionRecord->ExceptionAddress),
                    exception->ContextRecord->Eip,
                    exception->ContextRecord->Esp,
                    exception->ContextRecord->Eax,
                    exception->ContextRecord->Ecx,
                    exception->ContextRecord->Edx);
        std::fflush(stdout);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

int capture_boundary(EXCEPTION_POINTERS* exception) {    const auto stub_entry = reinterpret_cast<std::uint32_t>(&boundary_stub);
    if (exception == nullptr || exception->ExceptionRecord == nullptr
            || exception->ContextRecord == nullptr
            || exception->ExceptionRecord->ExceptionCode != EXCEPTION_BREAKPOINT
            || g_stub_entered == 0u
            || exception->ContextRecord->Eip < stub_entry
            || exception->ContextRecord->Eip >= stub_entry + 0x100u) {
        return EXCEPTION_CONTINUE_SEARCH;
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
            mov dword ptr [g_initial_ebp], ebp
            mov eax, dword ptr fs:[0]
            mov dword ptr [g_saved_fs0], eax
            push 0x202
            popfd
            mov eax, 0x11111111
            mov dword ptr [esp-70h], 44h
            mov dword ptr [g_before_call_esp], esp
            call dword ptr [g_entry_pointer]
        }
    } __except (capture_boundary(GetExceptionInformation())) {
        // The boundary stub captured every register before raising the trap.
    }
}

}  // namespace

int main() {
    if (std::getenv("SPORE_HARNESS_DIAGNOSTICS") != nullptr) {
        AddVectoredExceptionHandler(1, &report_fault);
    }
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, kPageBytes, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* data = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (code == nullptr || data == nullptr) {
        std::puts("FAIL original_crt relocation allocation failed");
        return 1;
    }
    auto* entry_code = code + (kEntry - kPageBase);
    auto* cookie_code = code + (kCookieEntry - kPageBase);
    auto* crt_code = code + (kCrtEntry - kPageBase);
    auto* prolog_code = code + (kSehPrologEntry - kPageBase);
    std::memcpy(entry_code, kVerifiedPeEntryBytes.data(),
                kVerifiedPeEntryBytes.size());
    std::memcpy(cookie_code, kCookieCodeBytes.data(), kCookieCodeBytes.size());
    std::memcpy(crt_code, kCrtPrefixBytes.data(), kCrtPrefixBytes.size());
    std::memcpy(prolog_code, kSehPrologBytes.data(), kSehPrologBytes.size());

    // Relocate the four absolute cookie data operands.
    if (cookie_code[0x011e1550u - kCookieEntry] != 0xa1u
            || cookie_code[0x011e1573u - kCookieEntry] != 0xa3u
            || cookie_code[0x011e15cbu - kCookieEntry] != 0x89u
            || cookie_code[0x011e15d3u - kCookieEntry] != 0x89u) {
        std::puts("FAIL original_crt unexpected cookie encoding");
        return 1;
    }
    const auto data_address = reinterpret_cast<std::uint32_t>(data);
    const auto complement_address = data_address + 4u;
    std::memcpy(cookie_code + (0x011e1550u - kCookieEntry) + 1u,
                &data_address, 4);
    std::memcpy(cookie_code + (0x011e1573u - kCookieEntry) + 1u,
                &complement_address, 4);
    std::memcpy(cookie_code + (0x011e15cbu - kCookieEntry) + 2u,
                &data_address, 4u);
    std::memcpy(cookie_code + (0x011e15d3u - kCookieEntry) + 2u,
                &complement_address, 4u);

    // The prologue reads __security_cookie through an absolute operand.
    if (prolog_code[0x011e11f1u - kSehPrologEntry] != 0xa1u) {
        std::puts("FAIL original_crt unexpected prologue encoding");
        return 1;
    }
    std::memcpy(prolog_code + (0x011e11f1u - kSehPrologEntry) + 1u,
                &data_address, 4u);

    const auto install_slot = [&](std::uint32_t call_address,
                                  std::uint32_t slot_offset,
                                  const void* target) {
        auto* slot = reinterpret_cast<std::uint32_t*>(data + slot_offset);
        *slot = reinterpret_cast<std::uint32_t>(target);
        const auto slot_address = reinterpret_cast<std::uint32_t>(slot);
        std::memcpy(cookie_code + (call_address - kCookieEntry) + 2u,
                    &slot_address, 4u);
    };
    install_slot(0x011e157fu, 0x100u, &record_time);
    install_slot(0x011e158bu, 0x104u, &record_process_id);
    install_slot(0x011e1593u, 0x108u, &record_thread_id);
    install_slot(0x011e159bu, 0x10cu, &record_tick_count);
    install_slot(0x011e15a7u, 0x110u, &record_performance_counter);

    const auto install_crt_slot = [&](std::uint32_t call_address,
                                      std::uint32_t slot_offset,
                                      const void* target) {
        auto* slot = reinterpret_cast<std::uint32_t*>(data + slot_offset);
        *slot = reinterpret_cast<std::uint32_t>(target);
        const auto slot_address = reinterpret_cast<std::uint32_t>(slot);
        std::memcpy(crt_code + (call_address - kCrtEntry) + 2u,
                    &slot_address, 4u);
    };
    const auto prefix_has = [&](std::uint32_t address, std::uint32_t size) {
        return kCrtPrefixBytes.size()
            >= static_cast<std::size_t>(address - kCrtEntry) + size;
    };
    if constexpr (kSehPrologExecuted) {
        install_crt_slot(kStartupInfoCall, 0x114u, &record_startup_info);
    }
    if constexpr (kStartupLockExecuted) {
        install_crt_slot(kInterlockedCall, 0x118u,
                         &record_interlocked_compare_exchange);
        auto* lock_block = data + kLockBlockOffset;
        g_lock_state_address =
            reinterpret_cast<std::uint32_t>(lock_block + kLockStateDelta);
        g_lock_address =
            reinterpret_cast<std::uint32_t>(lock_block + kLockDelta);
        std::memset(lock_block, 0, kLockBlockBytes);
        // MOV EDI,0x171e750
        if (!prefix_has(0x011e0f16u, 4u)
                || crt_code[0x011e0f15u - kCrtEntry] != 0xbfu) {
            std::puts("FAIL original_crt unexpected lock pointer encoding");
            return 1;
        }
        std::memcpy(crt_code + (0x011e0f16u - kCrtEntry), &g_lock_address, 4u);
        // MOV EAX,[0x0171e74c] appears twice (0x011e0f43 and 0x011e0f56).
        for (const auto& site : {std::pair<std::uint32_t, std::uint32_t>{
                 0x011e0f43u, 0x011e0f44u},
                 {0x011e0f56u, 0x011e0f57u}}) {
            if (!prefix_has(site.second, 4u)) continue;
            if (crt_code[site.first - kCrtEntry] != 0xa1u) {
                std::puts("FAIL original_crt unexpected lock read encoding");
                return 1;
            }
            std::memcpy(crt_code + (site.second - kCrtEntry),
                        &g_lock_state_address, 4u);
        }
        // MOV [0x0171e74c],ESI
        if (prefix_has(0x011e0f61u, 4u)) {
            if (crt_code[0x011e0f5fu - kCrtEntry] != 0x89u
                    || crt_code[0x011e0f60u - kCrtEntry] != 0x35u) {
                std::puts("FAIL original_crt unexpected lock write encoding");
                return 1;
            }
            std::memcpy(crt_code + (0x011e0f61u - kCrtEntry),
                        &g_lock_state_address, 4u);
        }
    }

    // Redirect the boundary into the capture stub instead of trapping in place,
    // because the CRT prologue has just installed a guest SEH record.
    *reinterpret_cast<std::uint8_t*>(
        crt_code + (kCrtStop - kCrtEntry)) = 0xe9u;
    const auto stub_address = reinterpret_cast<std::uint32_t>(&boundary_stub);
    const auto jump_origin = reinterpret_cast<std::uint32_t>(
        crt_code + (kCrtStop - kCrtEntry) + 5u);
    const std::int32_t jump_offset = static_cast<std::int32_t>(
        stub_address - jump_origin);
    std::memcpy(crt_code + (kCrtStop - kCrtEntry) + 1u, &jump_offset, 4u);

    std::memcpy(data, kCookieInitialData.data(), kCookieInitialData.size());
    g_entry_pointer = entry_code;
    g_runtime_boundary = reinterpret_cast<std::uint32_t>(
        crt_code + (kCrtStop - kCrtEntry));
    FlushInstructionCache(GetCurrentProcess(), code, kPageBytes);

    execute_original();

    // The struct lives in the guest frame; snapshot it before any further call
    // reuses that stack.
    std::uint32_t startupinfo[kStartupInfoDwords]{};
    std::memcpy(startupinfo,
                reinterpret_cast<const void*>(
                    static_cast<std::uintptr_t>(g_ctx_ebp) - 0x68u),
                sizeof(startupinfo));
    // The CRT frame is dead as soon as this function returns, so snapshot the
    // recorded __try level before any further call reuses that stack.
    std::uint32_t try_level = 0;
    std::memcpy(&try_level,
                reinterpret_cast<const void*>(
                    static_cast<std::uintptr_t>(g_ctx_ebp) - 4u),
                sizeof(try_level));
    std::uint32_t boundary_stack[2]{};
    std::memcpy(boundary_stack,
                reinterpret_cast<const void*>(
                    static_cast<std::uintptr_t>(g_ctx_esp)),
                sizeof(boundary_stack));

    const std::uint32_t entry_esp = g_before_call_esp - 4u;
    const auto* cookie_words = reinterpret_cast<const std::uint32_t*>(data);
    const std::uint32_t cookie_low = cookie_words[0];
    const std::uint32_t cookie_high = cookie_words[1];
    const bool cookie_consistent = cookie_low != 0u &&
        (cookie_low & 0xffff0000u) != 0u && cookie_high == ~cookie_low;
    const bool callee_saved =
        g_ctx_esi == 0x66666666u && g_ctx_edi == 0x77777777u;
    const bool startupinfo_cb_preserved =
        startupinfo[0] == kSeedStartupInfoCb;
    // The real API reports the parent's inherited desktop, title and reserved
    // strings; the guest mock reports NULL. Both must satisfy the contract the
    // caller relies on.
    const bool startupinfo_pointers_valid =
        (startupinfo[1] == 0u || is_readable_string(startupinfo[1]))
        && (startupinfo[2] == 0u || is_readable_string(startupinfo[2]))
        && (startupinfo[3] == 0u || is_readable_string(startupinfo[3]));
    const bool startupinfo_reserved_null = startupinfo[13] == 0u &&
        (startupinfo[12] >> 16u) == 0u;
    const bool startupinfo_ok = startupinfo_cb_preserved &&
        startupinfo_pointers_valid && startupinfo_reserved_null;

    if constexpr (kCrtStop == 0x011e0ee7u) {
        const bool stack_matches = g_ctx_esp == entry_esp - 8u;
        const bool registers_unchanged = g_ctx_ebx == 0x44444444u &&
            g_ctx_ebp == g_initial_ebp;
        const bool imports_match = g_call_count == 5u && g_pid != 0u &&
            g_tid != 0u && g_time_low != 0u;
        const bool words_match = boundary_stack[0] == 0x01508ca8u
            && boundary_stack[1] == 0x00000058u;
        if (!g_boundary_seen || !stack_matches || !words_match ||
                !registers_unchanged || !callee_saved || !cookie_consistent
                || !imports_match) {
            std::printf("FAIL original_crt boundary=%d eip=0x%08x "
                        "esp=0x%08x ebp=0x%08x words=%08x,%08x stack=%d "
                        "registers=%d saved=%d cookie=%d imports=%d "
                        "calls=%u\n",
                        g_boundary_seen, g_runtime_boundary, g_ctx_esp,
                        g_ctx_ebp, boundary_stack[0], boundary_stack[1],
                        stack_matches, registers_unchanged, callee_saved,
                        cookie_consistent, imports_match, g_call_count);
            return 1;
        }
        std::printf("PASS crt_entry stop=0x%08x executed=%u esp_delta=-8 "
                    "stack=0x58,0x1508ca8 callee_saved=restored "
                    "cookie=consistent imports=5\n",
                    kCrtStop,
                    1u + kCookieInstructions + kCrtPrefixExecutedInstructions);
        std::printf("DETAIL crt_entry cookie=0x%08x complement=0x%08x\n",
                    cookie_low, cookie_high);
        return 0;
    } else if constexpr (kCrtStop == 0x011e0efe) {
        const bool stack_matches =
            g_ctx_esp == entry_esp - 0x7cu && g_ctx_ebp == entry_esp - 4u;
        const bool ebx_cleared = g_ctx_ebx == 0u;
        const bool imports_match = g_call_count == 6u && g_pid != 0u &&
            g_tid != 0u && g_time_low != 0u && g_startupinfo_called &&
            g_startupinfo_address != nullptr;
        if (!g_boundary_seen || !stack_matches || !ebx_cleared ||
                !callee_saved || !cookie_consistent || !imports_match ||
                !startupinfo_ok) {
            std::printf("FAIL original_crt_startupinfo boundary=%d "
                        "eip=0x%08x esp=0x%08x ebp=0x%08x ebx=0x%08x "
                        "stack=%d ebx_ok=%d saved=%d cookie=%d imports=%d "
                        "calls=%u cb=0x%08x ptrs=%d reserved=%d\n",
                        g_boundary_seen, g_runtime_boundary, g_ctx_esp,
                        g_ctx_ebp, g_ctx_ebx, stack_matches, ebx_cleared,
                        callee_saved, cookie_consistent, imports_match,
                        g_call_count, startupinfo[0],
                        startupinfo_pointers_valid,
                        startupinfo_reserved_null);
            return 1;
        }
        std::printf("PASS crt_startupinfo stop=0x%08x executed=%u "
                    "esp_delta=-124 ebp=entry-4 ebx=0 "
                    "callee_saved=restored cookie=consistent imports=6 "
                    "startupinfo=cb,ptrs_valid,reserved_null\n",
                    kCrtStop,
                    1u + kCookieInstructions + kCrtPrefixExecutedInstructions
                        + kSehPrologInstructions);
        std::printf("DETAIL crt_startupinfo cookie=0x%08x complement=0x%08x "
                    "cb=0x%08x flags=0x%08x show=0x%08x "
                    "handles=%08x,%08x,%08x\n",
                    cookie_low, cookie_high, startupinfo[0], startupinfo[11],
                    startupinfo[12], startupinfo[14], startupinfo[15],
                    startupinfo[16]);
        return 0;
    } else {
        // Both lock stages read TEB+4 through FS:[0x18]; the lock owner is this
        // thread's stack base, exactly as the guest models it.
        const std::uint32_t* teb = reinterpret_cast<const std::uint32_t*>(
            static_cast<std::uintptr_t>(__readfsdword(0x18)));
        const std::uint32_t stack_base = teb[1];
        const auto* lock_block = reinterpret_cast<const std::uint32_t*>(
            data + kLockBlockOffset);
        const std::uint32_t lock_state = lock_block[kLockStateDelta / 4u];
        const std::uint32_t lock_value = lock_block[kLockDelta / 4u];
        const bool stack_matches =
            g_ctx_esp == entry_esp - 0x7cu && g_ctx_ebp == entry_esp - 4u;
        const bool ebx_cleared = g_ctx_ebx == 0u;
        const bool edi_is_lock = g_ctx_edi == g_lock_address;
        const bool imports_match = g_call_count == 7u && g_pid != 0u &&
            g_tid != 0u && g_time_low != 0u && g_startupinfo_called &&
            g_interlocked_called && g_interlocked_destination == g_lock_address
            && g_interlocked_exchange == stack_base
            && g_interlocked_comparand == 0u;
        const bool icc_acquired = g_interlocked_previous == 0u;
        const bool owner_is_stack_base = g_ctx_esi == stack_base;
        const bool lock_owned = lock_value == stack_base && lock_state == 0u;
        const bool try_level_is_one = try_level == 1u;
        const bool stack_matches_initterm =
            g_ctx_esp == entry_esp - 0x84u && g_ctx_ebp == entry_esp - 4u;
        const bool state_written = lock_state == 1u;
        const bool table_matches = boundary_stack[0] == kInittermTable
            && boundary_stack[1] == kInittermTableEnd;

        if constexpr (kCrtStop == 0x011e0f24u) {
            if (!g_boundary_seen || !stack_matches || !ebx_cleared ||
                    !edi_is_lock || !cookie_consistent || !imports_match ||
                    !icc_acquired || !owner_is_stack_base || !lock_owned ||
                    !try_level_is_one || !startupinfo_ok) {
                std::printf("FAIL original_crt_interlocked boundary=%d "
                            "eip=0x%08x esp=0x%08x ebp=0x%08x ebx=0x%08x "
                            "eax=0x%08x esi=0x%08x stack_base=0x%08x "
                            "stack=%d ebx_ok=%d edi_ok=%d cookie=%d "
                            "imports=%d calls=%u lock=0x%08x state=0x%08x "
                            "try=0x%08x startupinfo=%d\n",
                            g_boundary_seen, g_runtime_boundary, g_ctx_esp,
                            g_ctx_ebp, g_ctx_ebx, g_ctx_eax, g_ctx_esi,
                            stack_base, stack_matches, ebx_cleared,
                            edi_is_lock, cookie_consistent, imports_match,
                            g_call_count, lock_value, lock_state, try_level,
                            startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_interlocked stop=0x%08x executed=%u "
                        "esp_delta=-124 ebp=entry-4 ebx=0 edi=lock_reg "
                        "cookie=consistent imports=7 icc=acquired previous=0 "
                        "owner=stack_base lock=owner try_level=1 "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        kCrtStop,
                        1u + kCookieInstructions
                            + kCrtPrefixExecutedInstructions
                            + kSehPrologInstructions);
            std::printf("DETAIL crt_interlocked cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "stack_base=0x%08x\n",
                        cookie_low, cookie_high, lock_value, lock_state,
                        stack_base);
            return 0;
        } else if constexpr (kCrtStop == 0x011e0f43u) {
            const bool esi_is_one = g_ctx_esi == 1u;
            const bool state_read_is_zero = g_ctx_eax == 0u;
            if (!g_boundary_seen || !stack_matches || !ebx_cleared ||
                    !esi_is_one || !edi_is_lock || !cookie_consistent ||
                    !imports_match || !icc_acquired || !lock_owned ||
                    !try_level_is_one || !state_read_is_zero ||
                    !startupinfo_ok) {
                std::printf("FAIL original_crt_startup_lock boundary=%d "
                            "eip=0x%08x esp=0x%08x ebp=0x%08x ebx=0x%08x "
                            "eax=0x%08x esi=0x%08x stack_base=0x%08x "
                            "stack=%d esi_ok=%d edi_ok=%d cookie=%d "
                            "imports=%d calls=%u lock=0x%08x state=0x%08x "
                            "try=0x%08x startupinfo=%d\n",
                            g_boundary_seen, g_runtime_boundary, g_ctx_esp,
                            g_ctx_ebp, g_ctx_ebx, g_ctx_eax, g_ctx_esi,
                            stack_base, stack_matches, esi_is_one,
                            edi_is_lock, cookie_consistent, imports_match,
                            g_call_count, lock_value, lock_state, try_level,
                            startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_startup_lock stop=0x%08x executed=%u "
                        "esp_delta=-124 ebp=entry-4 ebx=0 esi=1 "
                        "edi=lock_reg cookie=consistent imports=7 "
                        "icc=acquired owner=stack_base lock=owner state=0 "
                        "try_level=1 "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        kCrtStop,
                        1u + kCookieInstructions
                            + kCrtPrefixExecutedInstructions
                            + kSehPrologInstructions);
            std::printf("DETAIL crt_startup_lock cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "stack_base=0x%08x\n",
                        cookie_low, cookie_high, lock_value, lock_state,
                        stack_base);
            return 0;
        } else {
            const bool esi_is_one = g_ctx_esi == 1u;
            if (!g_boundary_seen || !stack_matches_initterm || !ebx_cleared
                    || !esi_is_one || !edi_is_lock || !cookie_consistent
                    || !imports_match || !icc_acquired || !state_written
                    || !try_level_is_one || !table_matches || !startupinfo_ok) {
                std::printf("FAIL original_crt_initterm_call boundary=%d "
                            "eip=0x%08x esp=0x%08x ebp=0x%08x ebx=0x%08x "
                            "eax=0x%08x esi=0x%08x stack_base=0x%08x "
                            "stack=%d esi_ok=%d edi_ok=%d cookie=%d "
                            "imports=%d calls=%u lock=0x%08x state=0x%08x "
                            "try=0x%08x table=%d,%08x,%08x startupinfo=%d\n",
                            g_boundary_seen, g_runtime_boundary, g_ctx_esp,
                            g_ctx_ebp, g_ctx_ebx, g_ctx_eax, g_ctx_esi,
                            stack_base, stack_matches_initterm, esi_is_one,
                            edi_is_lock, cookie_consistent, imports_match,
                            g_call_count, lock_value, lock_state, try_level,
                            table_matches, boundary_stack[0],
                            boundary_stack[1], startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_initterm_call stop=0x%08x executed=%u "
                        "esp_delta=-132 ebp=entry-4 ebx=0 esi=1 "
                        "edi=lock_reg cookie=consistent imports=7 "
                        "icc=acquired owner=stack_base lock=owner state=1 "
                        "try_level=1 table=0x13eb09c..0x13eb0ac "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        kCrtStop,
                        1u + kCookieInstructions
                            + kCrtPrefixExecutedInstructions
                            + kSehPrologInstructions);
            std::printf("DETAIL crt_initterm_call cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "table=%08x,%08x\n",
                        cookie_low, cookie_high, lock_value, lock_state,
                        boundary_stack[0], boundary_stack[1]);
            return 0;
        }
    }
}
