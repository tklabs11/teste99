// cpp / boot_entry_crt_harness.cpp / x86 and aarch64-linux-android29 / Spore PE entry to CRT
#include "BatchStaticLiftRuntime.hpp"
#include "batch_entries.hpp"
#include "closure_entries.hpp"
#include "cookie_reference_bytes.hpp"
#include "crt_reference_bytes.hpp"
#include "initterm_guest_image.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

BatchLiftStatus spore_lift_011e11a0(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_011e1548(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_011e0ee0(BatchLiftMemory&, BatchLiftState&);

namespace {

constexpr std::uint32_t kDataAddress = 0x015cfe70u;
constexpr std::uint32_t kEntry = 0x011e11a0u;
constexpr std::uint32_t kCookieInstructions = 53u;
constexpr std::uint32_t kGuestTebAddress = 0x7ffdf000u;
constexpr std::uint32_t kGuestTebBytes = 0x40u;
// TEB+0x04 is the thread stack base. The CRT lock uses it as the owner id, so
// the guest models the top of its own mapped stack.
constexpr std::uint32_t kGuestStackBase =
    BatchLiftMemory::kStackBase + BatchLiftMemory::kStackBytes;
constexpr std::uint32_t kStartupInfoDwords = 0x44u / 4u;
constexpr std::uint32_t kSeedStartupInfoCb = 0x44u;
// The prologue takes EBP = entry_esp - 4 and the caller passes EBP - 0x68.
constexpr std::uint32_t kStartupInfoAddress =
    BatchLiftMemory::kEntryEsp - 4u - 0x68u;
// Two CRT pushes, then the SEH prologue: seven pushes and the 0x58 byte frame.
// Its RET pops the return address, and the later pushes all net out, so every
// boundary from the GetStartupInfoA call on sits 0x7c bytes below entry.
constexpr std::uint32_t kStartupInfoEsp = BatchLiftMemory::kEntryEsp - 0x7cu;
// The two table-bound PUSHes before the _initterm_e call add 8 more bytes.
constexpr std::uint32_t kInittermEsp = BatchLiftMemory::kEntryEsp - 0x84u;
constexpr std::uint32_t kBoundaryEsp = BatchLiftMemory::kEntryEsp - 8u;
// How many recent lifted bodies the walk detail prints on a failure.
constexpr std::size_t kBodyTracePrinted = 32u;

// The batch stage reuses the same verified prefix and then drives the
// _initterm call itself with the batch's lifted bodies registered.
constexpr bool kCppWalk = kCppWalkEnabled;
// After the table walk the CRT pops both push arguments, so the boundary sits
// where the GetStartupInfoA call left the stack.
constexpr bool kInittermExecuted = kCrtStop == 0x011e0f85u;
// With __native_startup_state at __initializing the CRT walks the C++ table.
constexpr bool kInittermWalkExecuted =
    kCrtStop == 0x011e0f98u && !kCppWalk;
constexpr bool kGuestImageMapped =
    kInittermExecuted || kInittermWalkExecuted || kCppWalk;

constexpr std::uint32_t boundary_esp() {
    return kInittermCallIsBoundary ? kInittermEsp : kStartupInfoEsp;
}

constexpr std::uint32_t executed_instructions() {
    return 1u + kCookieInstructions + kCrtPrefixExecutedInstructions +
        (kSehPrologExecuted ? kSehPrologInstructions : 0u);
}

struct StartupInfoSnapshot {
    std::array<std::uint32_t, kStartupInfoDwords> words{};
    bool readable = false;
};

StartupInfoSnapshot read_startupinfo(BatchLiftMemory& memory) {
    StartupInfoSnapshot snapshot;
    snapshot.readable = true;
    for (std::size_t index = 0; index < snapshot.words.size(); ++index) {
        if (!memory.load32(kStartupInfoAddress
                               + static_cast<std::uint32_t>(index * 4u),
                           snapshot.words[index])) {
            snapshot.readable = false;
            break;
        }
    }
    return snapshot;
}

bool startupinfo_contract_holds(BatchLiftMemory& memory, bool& zeroed) {
    const auto snapshot = read_startupinfo(memory);
    const auto& words = snapshot.words;
    zeroed = snapshot.readable && words[4] == 0u && words[5] == 0u &&
        words[6] == 0u && words[7] == 0u && words[8] == 0u &&
        words[9] == 0u && words[10] == 0u && words[11] == 0u &&
        words[12] == 0u && words[14] == 0u && words[15] == 0u &&
        words[16] == 0u;
    // The guest has no inherited desktop, title, reserved string or handle, so
    // it reports NULL where the real API reports the parent's values.
    return snapshot.readable && words[0] == kSeedStartupInfoCb &&
        words[1] == 0u && words[2] == 0u && words[3] == 0u &&
        words[13] == 0u && (words[12] >> 16u) == 0u;
}

// Both shims must refuse destinations outside writable guest memory without
// consuming arguments or moving the program counter.
bool imports_reject_invalid_destinations(BatchLiftMemory& memory) {
    constexpr std::uint32_t kProbeEsp = BatchLiftMemory::kEntryEsp - 0x100u;
    constexpr std::uint32_t kUnmappedArgument = 0x0000f000u;
    BatchGuestRuntime probe_imports;
    BatchLiftState probe_state{};
    probe_state.imports = &probe_imports;
    probe_state.regs[4] = kProbeEsp;
    probe_state.eip = kStartupInfoCall;
    if (!memory.store32(kProbeEsp, kCrtStop)
            || !memory.store32(kProbeEsp + 4u, kUnmappedArgument)
            || !memory.store32(kProbeEsp + 8u, 1u)
            || !memory.store32(kProbeEsp + 12u, 0u)) {
        return false;
    }
    if (probe_imports.invoke_import(
            memory, probe_state, "KERNEL32.dll!GetStartupInfoA",
            0x013cc29cu) != BatchLiftStatus::invalid_memory
            || probe_state.regs[4] != kProbeEsp
            || probe_state.eip != kStartupInfoCall) {
        return false;
    }
    probe_state.eip = kInterlockedCall;
    return probe_imports.invoke_import(
               memory, probe_state, "KERNEL32.dll!InterlockedCompareExchange",
               0x013cc194u) == BatchLiftStatus::invalid_memory
        && probe_state.regs[4] == kProbeEsp
        && probe_state.eip == kInterlockedCall;
}

// The expected import order once _initterm_e runs the three initializers, with
// the argument shape that proves each call site is the one the PE declares.
struct ExpectedCall {
    const char* symbol;
    std::uint32_t argument_count;
    std::uint32_t first_argument;
};

constexpr ExpectedCall kInitializerCalls[] = {
    {"MSVCR90.dll!__set_app_type", 1u, 2u},
    {"MSVCR90.dll!_encode_pointer", 1u, 0xffffffffu},
    {"MSVCR90.dll!__p__fmode", 0u, 0u},
    {"MSVCR90.dll!__p__commode", 0u, 0u},
    // 0x011e151a asks for 53-bit x87 precision through _controlfp_s.
    {"MSVCR90.dll!_controlfp_s", 3u, 0u},
    {"KERNEL32.dll!SetUnhandledExceptionFilter", 1u, 0x011e1318u},
};

// The encoded null the CRT stores at 0x0171e75c and 0x0171e760.
std::uint32_t encode_pointer(std::uint32_t pointer, std::uint32_t cookie) {
    if (pointer == 0u) return 0u;
    const std::uint32_t shift = cookie & 0x1fu;
    const std::uint32_t mixed = pointer ^ cookie;
    return shift == 0u ? mixed
                       : (mixed << shift) | (mixed >> (32u - shift));
}

bool initializer_calls_match(
    const std::vector<BatchGuestImportCall>& calls,
    std::uint32_t& matched) {
    matched = 0;
    // The seven API calls before the table walk are covered by the earlier
    // stages; this checks the run that starts at _initterm_e itself.
    std::size_t start = calls.size();
    for (std::size_t index = 0; index < calls.size(); ++index) {
        if (calls[index].symbol == "MSVCR90.dll!_initterm_e") {
            start = index;
            break;
        }
    }
    if (start == calls.size()) return false;
    for (const auto& expected : kInitializerCalls) {
        const std::size_t next = start + 1u + matched;
        if (next >= calls.size()) return false;
        const auto& actual = calls[next];
        if (actual.symbol != expected.symbol
                || actual.arguments.size() != expected.argument_count
                || (expected.argument_count != 0u
                    && actual.arguments[0] != expected.first_argument)) {
            return false;
        }
        ++matched;
    }
    return matched == std::size(kInitializerCalls);
}

// First eight-digit hex address inside a diagnostic message, or zero.
std::uint32_t first_hex_address(const std::string& text) {
    const std::size_t marker = text.find("0x");
    if (marker == std::string::npos || marker + 10u > text.size()) return 0u;
    std::uint32_t value = 0;
    for (std::size_t index = marker + 2u; index < marker + 10u; ++index) {
        const char digit = text[index];
        std::uint32_t nibble = 0xffffffffu;
        if (digit >= '0' && digit <= '9') {
            nibble = static_cast<std::uint32_t>(digit - '0');
        } else if (digit >= 'a' && digit <= 'f') {
            nibble = static_cast<std::uint32_t>(digit - 'a' + 10);
        }
        if (nibble == 0xffffffffu) return 0u;
        value = (value << 4u) | nibble;
    }
    return value;
}

std::uint32_t g_initializer_log[4]{};
// The single-instance guard's globals in the original image.
inline constexpr std::uint32_t kGuardNodeAddress = 0x01669930u;
inline constexpr std::uint32_t kGuardCounterAddress = 0x01669934u;

// A NUL-terminated guest string, or an empty one when it is not mapped.
[[maybe_unused]] std::string read_guest_text(
    const BatchLiftMemory& memory, std::uint32_t address) {
    std::string text;
    for (std::uint32_t offset = 0; offset < 260u; ++offset) {
        std::uint32_t byte = 0;
        if (!memory.load8(address + offset, byte) || byte == 0u) break;
        text.push_back(static_cast<char>(byte));
    }
    return text;
}std::uint32_t g_initializer_calls = 0;
// Results of the C++ table probe: the first initializer the shim called and
// the first one it refused to call because no body exists. Only the stage that
// reaches the walk uses them.
[[maybe_unused]] std::uint32_t g_walk_called = 0;
[[maybe_unused]] std::uint32_t g_walk_missing = 0;

BatchLiftStatus probe_initializer_one(
    BatchLiftMemory& memory, BatchLiftState& state) {
    g_initializer_log[g_initializer_calls++] = 1u;
    state.regs[0] = 0u;
    if (!batch_guest_return32(memory, state, 0u)) {
        return BatchLiftStatus::invalid_memory;
    }
    return BatchLiftStatus::returned;
}

BatchLiftStatus probe_initializer_two(
    BatchLiftMemory& memory, BatchLiftState& state) {
    g_initializer_log[g_initializer_calls++] = 2u;
    state.regs[0] = 7u;
    if (!batch_guest_return32(memory, state, 0u)) {
        return BatchLiftStatus::invalid_memory;
    }
    return BatchLiftStatus::returned;
}

// _initterm_e skips null entries, stops at the first nonzero result and refuses
// to call an address without a compiled body.
bool initterm_shim_contract(BatchLiftMemory& memory) {
    constexpr std::uint32_t kProbeEsp = BatchLiftMemory::kEntryEsp - 0x140u;
    constexpr std::uint32_t kProbeTable = 0x7ffe0000u;
    BatchGuestRuntime probe_imports;
    probe_imports.register_guest_function(0x011e10bfu, &probe_initializer_one);
    probe_imports.register_guest_function(0x011e1304u, &probe_initializer_two);
    if (!memory.store32(kProbeEsp, kCrtStop)
            || !memory.store32(kProbeEsp + 4u, kProbeTable)
            || !memory.store32(kProbeEsp + 8u, kProbeTable + 12u)
            || !memory.store32(kProbeTable, 0u)
            || !memory.store32(kProbeTable + 4u, 0x011e10bfu)
            || !memory.store32(kProbeTable + 8u, 0x011e1304u)) {
        return false;
    }
    BatchLiftState probe_state{};
    probe_state.imports = &probe_imports;
    probe_state.regs[4] = kProbeEsp;
    probe_state.eip = kInittermCall;
    const auto status = probe_imports.invoke_import(
        memory, probe_state, "MSVCR90.dll!_initterm_e", 0x013cc31cu);
    if (status != BatchLiftStatus::returned
            || probe_state.regs[0] != 7u
            || probe_state.eip != kCrtStop
            // _initterm_e is __cdecl, so only the return address is popped and
            // the caller keeps its two table arguments.
            || probe_state.regs[4] != kProbeEsp + 4u
            || g_initializer_calls != 2u
            || g_initializer_log[0] != 1u || g_initializer_log[1] != 2u) {
        return false;
    }
    // An unregistered initializer must fail closed and name its address before
    // any guest routine runs.
    if (!memory.store32(kProbeTable + 4u, 0x011e135au)) {
        return false;
    }
    probe_state.regs[4] = kProbeEsp;
    probe_state.eip = kInittermCall;
    const auto missing = probe_imports.invoke_import(
        memory, probe_state, "MSVCR90.dll!_initterm_e", 0x013cc31cu);
    const std::string& diagnostic = probe_imports.last_error();
    return missing == BatchLiftStatus::unsupported_dependency
        && diagnostic.find("011e135a") != std::string::npos
        && probe_state.regs[4] == kProbeEsp
        && probe_state.eip == kInittermCall;
}

// _initterm walks the real C++ initializer table: it skips the leading null,
// calls the first entry that has a body and fails closed naming the next one,
// which has none. No constructor body is faked here.
// Only the stage that reaches the C++ walk uses this probe, so the other
// stages must not warn about an unused helper.
[[maybe_unused]] bool initterm_walk_shim_contract(
    BatchLiftMemory& memory,
    std::uint32_t& called_first,
    std::uint32_t& missing_first) {
    constexpr std::uint32_t kProbeEsp = BatchLiftMemory::kEntryEsp - 0x160u;
    constexpr std::uint32_t kProbeStart = 0x013cc80cu;
    called_first = 0;
    missing_first = 0;
    std::uint32_t first_target = 0, second_target = 0;
    if (!memory.load32(kProbeStart + 4u, first_target)
            || !memory.load32(kProbeStart + 8u, second_target)
            || first_target == 0u || second_target == 0u) {
        std::puts("FAIL crt_entry the C++ initializer table head changed");
        return false;
    }
    if (!memory.store32(kProbeEsp, kCrtStop)
            || !memory.store32(kProbeEsp + 4u, kProbeStart)
            || !memory.store32(kProbeEsp + 8u, kProbeStart + 12u)) {
        return false;
    }
    BatchGuestRuntime probe_imports;
    g_initializer_calls = 0;
    probe_imports.register_guest_function(first_target, &probe_initializer_one);
    BatchLiftState probe_state{};
    probe_state.imports = &probe_imports;
    probe_state.regs[4] = kProbeEsp;
    probe_state.eip = kInittermWalkCall;
    const auto missing = probe_imports.invoke_import(
        memory, probe_state, "MSVCR90.dll!_initterm", 0x013cc320u);
    const std::string& diagnostic = probe_imports.last_error();
    called_first = first_target;
    missing_first = first_hex_address(diagnostic);
    return missing == BatchLiftStatus::unsupported_dependency
        && g_initializer_calls == 1u && g_initializer_log[0] == 1u
        && missing_first == second_target
        && probe_state.regs[4] == kProbeEsp;
}

}  // namespace

int main() {
    BatchLiftMemory memory;
    // map_region keeps the pointers, so every backing buffer must outlive the
    // run; only the initial contents depend on the stage.
    std::array<std::uint8_t, kBatchGuestImageBytes> image_data{};
    std::array<std::uint8_t, 8> cookie_data = kCookieInitialData;
    std::array<std::uint8_t, kStartupLockRegionBytes> lock_data{};
    // The initializer walk needs the real PE headers, import cells and CRT
    // globals; the earlier stages only need the cookie and the lock.
    if constexpr (kGuestImageMapped) {
        std::memcpy(image_data.data(), kBatchGuestImage.data(),
                    image_data.size());
        for (const auto& region : kBatchGuestImageRegions) {
            if (!memory.map_region(region.address,
                                   image_data.data() + region.offset,
                                   region.size, region.writable)) {
                std::puts("FAIL crt_entry map_guest_image");
                return 1;
            }
        }
    } else {
        if (!memory.map_region(kDataAddress, cookie_data.data(),
                               cookie_data.size(), true)
                || !memory.map_region(kStartupLockRegion, lock_data.data(),
                                      lock_data.size(), true)) {
            std::puts("FAIL crt_entry map_data");
            return 1;
        }
    }
    std::array<std::uint8_t, kGuestTebBytes> teb_data{};
    std::array<std::uint8_t, 16> probe_table_data{};
    std::array<std::uint8_t, kGuestHeapBytes> heap_data{};
    if (!memory.map_region(kGuestTebAddress, teb_data.data(),
                           teb_data.size(), true)
            || !memory.map_region(0x7ffe0000u, probe_table_data.data(),
                                  probe_table_data.size(), true)
            || !memory.map_region(kGuestHeapBase, heap_data.data(),
                                  heap_data.size(), true)) {
        std::puts("FAIL crt_entry map_regions");
        return 1;
    }
    // Minimal x86 TEB: SEH chain end, stack base, and the self pointer that
    // FS:[0x18] must yield.
    if (!memory.store32(kGuestTebAddress, 0xffffffffu)
            || !memory.store32(kGuestTebAddress + 4u, kGuestStackBase)
            || !memory.store32(kGuestTebAddress + 0x18u, kGuestTebAddress)) {
        std::puts("FAIL crt_entry teb_model");
        return 1;
    }
    // Both sides seed cb before the call so preservation is observable.
    if (!memory.store32(kStartupInfoAddress, kSeedStartupInfoCb)) {
        std::puts("FAIL crt_entry seed_startupinfo");
        return 1;
    }
    BatchLiftState state{};
    BatchGuestRuntime imports;
    state.imports = &imports;
    state.fs_base = kGuestTebAddress;
    constexpr std::array<std::uint32_t, 8> initial{
        0x11111111u, 0x22222222u, 0x33333333u, 0x44444444u,
        BatchLiftMemory::kEntryEsp, 0x55555555u, 0x66666666u, 0x77777777u,
    };
    if constexpr (kGuestImageMapped) {
        // The image holds the file's pre-fixup import slots; apply the same
        // address fixup the loader performs before anything executes.
        if (!imports.install_import_trampolines(
                memory, kGuestImportSlots, kGuestImportSlotCount)) {
            std::printf("FAIL crt_entry import_slot_fixup %s\n",
                        imports.last_error().c_str());
            return 1;
        }
        imports.register_guest_function(kCrtInitializer0,
                                        &spore_lift_011e10bf);
        imports.register_guest_function(kCrtInitializer1,
                                        &spore_lift_011e1304);
        imports.register_guest_function(kCrtInitializer2,
                                        &spore_lift_011e135a);
    }
    if constexpr (kCppWalk) {
        for (const auto& body : kBatchBodyTable) {
            imports.register_guest_function(body.entry, body.body);
        }
        imports.reset_tls_indexes();
    }
    for (std::size_t index = 0; index < initial.size(); ++index) {
        state.regs[index] = initial[index];
    }
    state.eflags = 0x202u;
    state.eip = kEntry;
    const auto status = spore_lift_011e11a0(memory, state);
    if (!imports_reject_invalid_destinations(memory)) {
        std::puts("FAIL crt_entry an invalid import destination was accepted");
        return 1;
    }
    if (!initterm_shim_contract(memory)) {
        std::puts("FAIL crt_entry the _initterm_e shim broke its contract");
        return 1;
    }
    if constexpr (kInittermWalkExecuted) {
        if (!initterm_walk_shim_contract(memory, g_walk_called, g_walk_missing)) {
            std::puts("FAIL crt_entry the _initterm shim broke its contract");
            return 1;
        }
    }

    // The batch stage drives the table walk itself: the prefix stopped on the
    // CALL, so pushing the return address and invoking the import runs the
    // real _initterm semantics over the guest table.
    BatchLiftStatus walk_status = BatchLiftStatus::returned;
    std::uint32_t walk_esp = 0, walk_stopped_at = 0;
    std::uint32_t prefix_eip = 0, prefix_esi = 0, prefix_edi = 0;
    if constexpr (kCppWalk) {
        // The walk drives the guest past the boundary and leaves the initializer
        // registers behind, so the prefix result is captured here.
        prefix_eip = state.eip;
        prefix_esi = state.regs[6];
        prefix_edi = state.regs[7];
        walk_esp = state.regs[4];
        const auto walk_call = batch_guest_import_call32(
            memory, state, "MSVCR90.dll!_initterm", 0x013cc320u, 0x011e0f9du);
        walk_status = walk_call;
        walk_stopped_at = first_hex_address(imports.last_error());
    }

    std::uint32_t cookie_low = 0, cookie_high = 0;
    const bool cookie_readable =
        memory.load32(kDataAddress, cookie_low) &&
        memory.load32(kDataAddress + 4u, cookie_high);
    const bool cookie_consistent = cookie_readable && cookie_low != 0u &&
        (cookie_low & 0xffff0000u) != 0u && cookie_high == ~cookie_low;
    const auto& calls = imports.calls();

    if constexpr (kCrtStop == 0x011e0ee7u) {
        std::uint32_t pushed_handler = 0, pushed_size = 0;
        const bool stack_readable =
            memory.load32(BatchLiftMemory::kEntryEsp - 8u, pushed_handler) &&
            memory.load32(BatchLiftMemory::kEntryEsp - 4u, pushed_size);
        const bool stack_matches = stack_readable &&
            pushed_handler == 0x01508ca8u && pushed_size == 0x00000058u;
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            state.eip == kCrtStop && state.regs[4] == kBoundaryEsp;
        const bool registers_unchanged = state.regs[3] == initial[3] &&
            state.regs[5] == initial[5] && state.regs[6] == initial[6] &&
            state.regs[7] == initial[7];
        const bool imports_match = calls.size() == 5u &&
            calls[0].symbol == "KERNEL32.dll!GetSystemTimeAsFileTime" &&
            calls[1].symbol == "KERNEL32.dll!GetCurrentProcessId" &&
            calls[2].symbol == "KERNEL32.dll!GetCurrentThreadId" &&
            calls[3].symbol == "KERNEL32.dll!GetTickCount" &&
            calls[4].symbol == "KERNEL32.dll!QueryPerformanceCounter";
        if (!reached_boundary || !stack_matches || !registers_unchanged ||
                !cookie_consistent || !imports_match) {
            std::printf("FAIL crt_entry status=%u eip=0x%08x esp=0x%08x "
                        "stack=%d registers=%d cookie=%d imports=%d "
                        "calls=%u cookie_low=0x%08x cookie_high=0x%08x\n",
                        static_cast<unsigned>(status), state.eip, state.regs[4],
                        stack_matches, registers_unchanged, cookie_consistent,
                        imports_match, static_cast<unsigned>(calls.size()),
                        cookie_low, cookie_high);
            return 1;
        }
        std::printf("PASS crt_entry stop=0x%08x executed=%u esp_delta=-8 "
                    "stack=0x58,0x1508ca8 callee_saved=restored "
                    "cookie=consistent imports=5\n",
                    state.eip, executed_instructions());
        std::printf("DETAIL crt_entry cookie=0x%08x complement=0x%08x\n",
                    cookie_low, cookie_high);
        return 0;
    } else if constexpr (kCrtStop == 0x011e0efe) {
        bool startupinfo_zeroed = false;
        const bool startupinfo_ok =
            startupinfo_contract_holds(memory, startupinfo_zeroed);
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            state.eip == kCrtStop && state.regs[4] == kStartupInfoEsp;
        const bool frame_matches =
            state.regs[5] == BatchLiftMemory::kEntryEsp - 4u;
        const bool ebx_cleared = state.regs[3] == 0u;
        const bool saves_restored = state.regs[6] == initial[6] &&
            state.regs[7] == initial[7];
        const bool imports_match = calls.size() == 6u &&
            calls[4].symbol == "KERNEL32.dll!QueryPerformanceCounter" &&
            calls[5].symbol == "KERNEL32.dll!GetStartupInfoA" &&
            calls[5].arguments.size() == 1u &&
            calls[5].arguments[0] == kStartupInfoAddress;
        if (!reached_boundary || !frame_matches || !ebx_cleared ||
                !saves_restored || !cookie_consistent ||
                !imports_match || !startupinfo_ok || !startupinfo_zeroed) {
            std::printf("FAIL crt_startupinfo status=%u eip=0x%08x "
                        "esp=0x%08x ebp=0x%08x ebx=0x%08x boundary=%d "
                        "frame=%d ebx_ok=%d saved=%d cookie=%d imports=%d "
                        "calls=%u startupinfo=%d zeroed=%d\n",
                        static_cast<unsigned>(status), state.eip, state.regs[4],
                        state.regs[5], state.regs[3], reached_boundary,
                        frame_matches, ebx_cleared, saves_restored,
                        cookie_consistent, imports_match,
                        static_cast<unsigned>(calls.size()), startupinfo_ok,
                        startupinfo_zeroed);
            return 1;
        }
        std::printf("PASS crt_startupinfo stop=0x%08x executed=%u "
                    "esp_delta=-124 ebp=entry-4 ebx=0 "
                    "callee_saved=restored cookie=consistent imports=6 "
                    "startupinfo=cb,ptrs_valid,reserved_null\n",
                    state.eip, executed_instructions());
        std::printf("DETAIL crt_startupinfo cookie=0x%08x complement=0x%08x\n",
                    cookie_low, cookie_high);
        return 0;
    } else if constexpr (kInittermExecuted) {
        std::uint32_t lock_value = 0, state_value = 0, try_level = 0;
        const bool lock_ok = memory.load32(kStartupLock, lock_value);
        const bool state_ok = memory.load32(kStartupLockState, state_value);
        const bool frame_readable = memory.load32(
            BatchLiftMemory::kEntryEsp - 4u - 4u, try_level);
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            state.eip == kCrtStop && state.regs[4] == kStartupInfoEsp;
        const bool frame_matches =
            state.regs[5] == BatchLiftMemory::kEntryEsp - 4u;
        const bool ebx_cleared = state.regs[3] == 0u;
        const bool esi_is_one = state.regs[6] == 1u;
        const bool edi_is_lock = state.regs[7] == kStartupLock;
        // _initterm_e reports success, so the JZ is the taken branch and EAX
        // still holds zero on the boundary.
        const bool initterm_returned_zero = state.regs[0] == 0u;
        bool startupinfo_zeroed = false;
        const bool startupinfo_ok =
            startupinfo_contract_holds(memory, startupinfo_zeroed);
        const bool lock_owner_installed =
            lock_ok && lock_value == kGuestStackBase;
        const bool state_written = state_ok && state_value == 1u;
        const bool try_level_is_one = frame_readable && try_level == 1u;

        // What the three initializers left behind in guest memory.
        std::uint32_t app_type_flag = 0, fmode = 0, commode = 0;
        std::uint32_t encoded_low = 0, encoded_high = 0;
        std::uint32_t adjust_cell = 0, adjust_pointer = 0, sse2_info = 0;
        const bool globals_readable =
            memory.load32(0x016f2628u, app_type_flag)
            && memory.load32(kGuestFmodeAddress, fmode)
            && memory.load32(kGuestCommodeAddress, commode)
            && memory.load32(0x0171e75cu, encoded_low)
            && memory.load32(0x0171e760u, encoded_high)
            && memory.load32(0x0171e748u, adjust_cell)
            && memory.load32(0x0171e754u, sse2_info)
            && memory.load32(0x013cc310u, adjust_pointer);
        std::uint32_t adjust_value = 0;
        const bool adjust_readable =
            globals_readable && memory.load32(adjust_pointer, adjust_value);
        const bool app_type_matches =
            app_type_flag == kExpectAppTypeProbeFlag;
        const bool file_mode_copied = fmode == 0u && commode == 0u;
        const bool encoded_null_consistent = encoded_low == encoded_high
            && encoded_low == encode_pointer(0xffffffffu, cookie_low);
        const bool adjust_copied =
            adjust_readable && adjust_cell == adjust_value;
        const bool sse2_reported = sse2_info == 1u;
        std::uint32_t initializer_calls = 0;
        const bool calls_match =
            initializer_calls_match(calls, initializer_calls)
            && calls.size() == 14u;
        const bool app_type_stored = state.app_type == 2u;
        const bool filter_installed = state.unhandled_filter == 0x011e1318u;
        const bool precision_set = state.x87_control_word == 0x0001027fu;

        if (!reached_boundary || !frame_matches || !ebx_cleared ||
                !esi_is_one || !edi_is_lock || !initterm_returned_zero ||
                !cookie_consistent || !startupinfo_ok ||
                !startupinfo_zeroed || !lock_owner_installed ||
                !state_written || !try_level_is_one || !globals_readable ||
                !app_type_matches || !file_mode_copied ||
                !encoded_null_consistent || !adjust_copied ||
                !sse2_reported || !calls_match || !app_type_stored ||
                !filter_installed || !precision_set) {
            std::printf("FAIL crt_initterm_executed status=%u eip=0x%08x "
                        "esp=0x%08x ebp=0x%08x eax=0x%08x ebx=0x%08x "
                        "esi=0x%08x edi=0x%08x boundary=%d frame=%d "
                        "cookie=%d startupinfo=%d lock=%d state=%d try=%d "
                        "globals=%d app_type=%u/%d fmode=%u,%u/%d "
                        "encoded=%08x,%08x/%d adjust=%08x/%d sse2=%u/%d "
                        "calls=%u/%d app_type_arg=%u/%d filter=%08x/%d "
                        "fpucw=%08x/%d\n",
                        static_cast<unsigned>(status), state.eip, state.regs[4],
                        state.regs[5], state.regs[0], state.regs[3],
                        state.regs[6], state.regs[7], reached_boundary,
                        frame_matches, cookie_consistent, startupinfo_ok,
                        lock_owner_installed, state_written,
                        try_level_is_one, globals_readable, app_type_flag,
                        app_type_matches, fmode, commode, file_mode_copied,
                        encoded_low, encoded_high, encoded_null_consistent,
                        adjust_cell, adjust_copied, sse2_info, sse2_reported,
                        static_cast<unsigned>(calls.size()), calls_match,
                        state.app_type, app_type_stored,
                        state.unhandled_filter, filter_installed,
                        state.x87_control_word, precision_set);
            return 1;
        }
        std::printf("PASS crt_initterm_executed stop=0x%08x executed=%u "
                    "esp_delta=-124 ebp=entry-4 eax=0 esi=1 edi=lock_reg "
                    "cookie=consistent imports=14 initterm=walked "
                    "initializers=3/3 app_type=%u fmode=0,0 "
                    "encoded_null=consistent adjust_fdiv=propagated "
                    "sse2=1 filter=0x011e1318 fpucw=0x%08x\n",
                    state.eip, executed_instructions(), state.app_type,
                    state.x87_control_word);
        std::printf("DETAIL crt_initterm_executed cookie=0x%08x "
                    "complement=0x%08x lock=0x%08x state=0x%08x "
                    "encoded_null=0x%08x adjust=0x%08x\n",
                    cookie_low, cookie_high, lock_value, state_value,
                    encoded_low, adjust_cell);
        return 0;
    } else if constexpr (kInittermWalkExecuted) {
        std::uint32_t lock_value = 0, state_value = 0, try_level = 0;
        std::uint32_t table_begin = 0, table_end = 0;
        const bool lock_ok = memory.load32(kStartupLock, lock_value);
        const bool state_ok = memory.load32(kStartupLockState, state_value);
        const bool frame_readable = memory.load32(
            BatchLiftMemory::kEntryEsp - 4u - 4u, try_level);
        // Both table pushes are still on the stack when the CALL is reached.
        const bool table_readable =
            memory.load32(kInittermEsp, table_begin) &&
            memory.load32(kInittermEsp + 4u, table_end);
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            state.eip == kCrtStop && state.regs[4] == kInittermEsp;
        const bool frame_matches =
            state.regs[5] == BatchLiftMemory::kEntryEsp - 4u;
        const bool ebx_cleared = state.regs[3] == 0u;
        const bool esi_is_one = state.regs[6] == 1u;
        const bool edi_is_lock = state.regs[7] == kStartupLock;
        // The state read equals __initializing, so CMP leaves ZF set and the
        // JNZ falls through into the C++ initializer walk.
        const bool state_read_is_one = state.regs[0] == 1u;
        const bool compare_set_equal = (state.eflags & 0x040u) != 0u;
        bool startupinfo_zeroed = false;
        const bool startupinfo_ok =
            startupinfo_contract_holds(memory, startupinfo_zeroed);
        const bool lock_owner_installed =
            lock_ok && lock_value == kGuestStackBase;
        const bool state_still_initializing = state_ok && state_value == 1u;
        const bool try_level_is_one = frame_readable && try_level == 1u;
        const bool table_matches = table_readable
            && table_begin == kCppInitTable && table_end == kCppInitTableEnd;
        const bool app_type_stored = state.app_type == 2u;
        const bool filter_installed = state.unhandled_filter == 0x011e1318u;
        const bool precision_set = state.x87_control_word == 0x0001027fu;
        std::uint32_t initializer_calls = 0;
        const bool calls_match =
            initializer_calls_match(calls, initializer_calls)
            && calls.size() == 14u;

        if (!reached_boundary || !frame_matches || !ebx_cleared ||
                !esi_is_one || !edi_is_lock || !state_read_is_one ||
                !compare_set_equal || !cookie_consistent || !startupinfo_ok ||
                !startupinfo_zeroed || !lock_owner_installed ||
                !state_still_initializing || !try_level_is_one ||
                !table_matches || !app_type_stored || !filter_installed ||
                !precision_set || !calls_match) {
            std::printf("FAIL crt_startup_state_initializing status=%u "
                        "eip=0x%08x esp=0x%08x ebp=0x%08x eax=0x%08x "
                        "ebx=0x%08x esi=0x%08x edi=0x%08x boundary=%d "
                        "frame=%d cookie=%d startupinfo=%d lock=%d state=%u/%d "
                        "try=%d table=%d,%08x,%08x/%d cmp=%d calls=%u/%d "
                        "app_type=%u/%d filter=%08x/%d fpucw=%08x/%d\n",
                        static_cast<unsigned>(status), state.eip, state.regs[4],
                        state.regs[5], state.regs[0], state.regs[3],
                        state.regs[6], state.regs[7], reached_boundary,
                        frame_matches, cookie_consistent, startupinfo_ok,
                        lock_owner_installed, state_value,
                        state_still_initializing, try_level_is_one,
                        table_readable, table_begin, table_end, table_matches,
                        compare_set_equal,
                        static_cast<unsigned>(calls.size()), calls_match,
                        state.app_type, app_type_stored,
                        state.unhandled_filter, filter_installed,
                        state.x87_control_word, precision_set);
            return 1;
        }
        std::printf("PASS crt_startup_state_initializing stop=0x%08x "
                    "executed=%u esp_delta=-132 ebp=entry-4 eax=1 esi=1 "
                    "edi=lock_reg cookie=consistent imports=14 "
                    "initterm_e=walked state=initializing cmp=equal "
                    "table=0x%08x..0x%08x app_type=%u fpucw=0x%08x\n",
                    state.eip, executed_instructions(), table_begin, table_end,
                    state.app_type, state.x87_control_word);
        std::printf("DETAIL crt_startup_state_initializing cookie=0x%08x "
                    "complement=0x%08x lock=0x%08x state=0x%08x "
                    "walk_called=0x%08x walk_missing=0x%08x\n",
                    cookie_low, cookie_high, lock_value, state_value,
                    g_walk_called, g_walk_missing);
        return 0;
    } else if constexpr (kCppWalk) {
        std::uint32_t lock_value = 0, state_value = 0, try_level = 0;
        std::uint32_t table_begin = 0, table_end = 0;
        const bool lock_ok = memory.load32(kStartupLock, lock_value);
        const bool state_ok = memory.load32(kStartupLockState, state_value);
        const bool frame_readable = memory.load32(
            BatchLiftMemory::kEntryEsp - 4u - 4u, try_level);
        const bool table_readable =
            memory.load32(kInittermEsp, table_begin) &&
            memory.load32(kInittermEsp + 4u, table_end);
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            prefix_eip == kCrtStop && walk_esp == kInittermEsp;
        const bool frame_matches =
            state.regs[5] == BatchLiftMemory::kEntryEsp - 4u;
        const bool esi_is_one = prefix_esi == 1u;
        const bool edi_is_lock = prefix_edi == kStartupLock;
        const bool table_matches = table_readable
            && table_begin == kCppInitTable && table_end == kCppInitTableEnd;
        bool startupinfo_zeroed = false;
        const bool startupinfo_ok =
            startupinfo_contract_holds(memory, startupinfo_zeroed);
        const bool lock_owner_installed =
            lock_ok && lock_value == kGuestStackBase;
        const bool state_still_initializing = state_ok && state_value == 1u;
        const bool try_level_is_one = frame_readable && try_level == 1u;

        // The walk ran the batch and stopped at a requirement it cannot meet:
        // the following table entry, a body this batch left out, or a memory
        // read the guest has no mapping for. Each is reported by address.
        bool pending_stop = false;
        for (std::uint32_t index = 0; index < kBatchPendingBodyCount; ++index) {
            if (walk_stopped_at == kBatchPendingBodies[index]) {
                pending_stop = true;
            }
        }
        const bool walk_stopped =
            (walk_status == BatchLiftStatus::unsupported_dependency
                && (walk_stopped_at == kBatchNextInitializer || pending_stop))
            || (walk_status == BatchLiftStatus::invalid_memory
                && state.eip != 0u);

        // __getmainargs built the documented guest argv/envp; the pointers come
        // from the recorded call, not from CRT globals the guest also mirrors.
        std::uint32_t argc_pointer = 0, argv_pointer = 0, envp_pointer = 0;
        std::uint32_t argc = 0, argv = 0, envp = 0, argv0 = 0, envp0 = 1u;
        std::uint32_t first_char = 0;
        std::uint32_t main_args = 0, main_args_args = 0;
        for (const auto& call : calls) {
            if (call.symbol != "MSVCR90.dll!__getmainargs") continue;
            ++main_args;
            main_args_args = static_cast<std::uint32_t>(call.arguments.size());
            argc_pointer = call.arguments[0];
            argv_pointer = call.arguments[1];
            envp_pointer = call.arguments[2];
        }
        const bool args_readable = main_args == 1u && main_args_args == 5u
            && memory.load32(argc_pointer, argc)
            && memory.load32(argv_pointer, argv)
            && memory.load32(envp_pointer, envp)
            && memory.load32(kGuestArgvArray, argv0)
            && memory.load32(kGuestEnvpArray, envp0)
            && memory.load8(kGuestProgramName, first_char);
        const bool args_match = args_readable
            && argc == 1u && argv == kGuestArgvArray && envp == kGuestEnvpArray
            && argv0 == kGuestProgramName && envp0 == 0u
            && first_char == 'S';

        // Every InitializeCriticalSection target keeps a valid guest layout.
        // A section the walk entered legitimately holds LockCount 0, so both
        // the initialized (-1) and the held (0) states are accepted.
        std::uint32_t sections = 0, sections_ready = 0;
        for (const auto& call : calls) {
            if (call.symbol != "KERNEL32.dll!InitializeCriticalSection"
                    && call.symbol
                        != "KERNEL32.dll!InitializeCriticalSectionAndSpinCount") {
                continue;
            }
            ++sections;
            std::uint32_t lock_count = 0, recursion = 0;
            if (memory.load32(call.arguments[0] + 4u, lock_count)
                    && memory.load32(call.arguments[0] + 8u, recursion)
                    && (lock_count == 0xffffffffu || lock_count == 0u)
                    && recursion <= 1u) {
                ++sections_ready;
            }
        }
        const bool sections_initialised =
            sections >= 3u && sections_ready == sections;

        // TlsAlloc handed out indices from zero, in call order.
        std::uint32_t tls_calls = 0, tls_next = 0;
        bool tls_ok = true;
        for (const auto& call : calls) {
            if (call.symbol != "KERNEL32.dll!TlsAlloc") continue;
            if (call.result != tls_next) tls_ok = false;
            ++tls_next;
            ++tls_calls;
        }
        tls_ok = tls_ok && tls_calls == 2u;

        // Initializer #5 is the engine's single-instance guard: the exact call
        // order it performs is the evidence that the guard ran to completion.
        static const char* const kGuardOrder[] = {
            "KERNEL32.dll!GetCurrentProcessId",
            "USER32.dll!wsprintfA",
            "KERNEL32.dll!CreateMutexA",
            "KERNEL32.dll!WaitForSingleObject",
            "KERNEL32.dll!GetEnvironmentVariableA",
            "KERNEL32.dll!GetProcessHeap",
            "KERNEL32.dll!HeapAlloc",
            "KERNEL32.dll!InitializeCriticalSection",
            "MSVCR90.dll!sprintf",
            "KERNEL32.dll!SetEnvironmentVariableA",
            "KERNEL32.dll!ReleaseMutex",
            "KERNEL32.dll!CloseHandle",
        };
        std::size_t guard_matched = 0;
        bool guard_order_ok = false;
        {
            std::size_t cursor = 0;
            for (const auto& call : calls) {
                if (cursor >= std::size(kGuardOrder)) break;
                if (call.symbol == kGuardOrder[cursor]) ++cursor;
            }
            guard_matched = cursor;
            guard_order_ok = cursor == std::size(kGuardOrder);
        }

        // The mutex name, the sprintf result and the environment value are the
        // three guest strings the guard builds, so a formatter regression shows
        // up as a name mismatch instead of a silent pass.
        std::string mutex_name, encoded_node, environment_value;
        std::uint32_t mutex_name_pointer = 0;
        for (const auto& call : calls) {
            if (call.symbol == "KERNEL32.dll!CreateMutexA") {
                mutex_name_pointer = call.arguments[2];
                mutex_name = call.text;
            }
            if (call.symbol == "MSVCR90.dll!sprintf") {
                encoded_node = call.text;
            }
            if (call.symbol == "KERNEL32.dll!SetEnvironmentVariableA") {
                environment_value = call.text;
            }
        }
        std::string printed_name;
        for (const auto& call : calls) {
            if (call.symbol == "USER32.dll!wsprintfA") {
                printed_name = call.text;
            }
        }
        std::uint32_t guard_node = 0, guard_counter = 0;
        std::uint32_t node_next = 0, node_previous = 0, node_count = 0;
        std::uint32_t node_lock_count = 0;
        const bool guard_readable =
            memory.load32(kGuardNodeAddress, guard_node)
            && memory.load32(kGuardCounterAddress, guard_counter)
            && guard_node != 0u
            && memory.load32(guard_node, node_next)
            && memory.load32(guard_node + 4u, node_previous)
            && memory.load32(guard_node + 8u, node_count)
            && memory.load32(guard_node + 0x10u, node_lock_count);
        // The guard built its node once. Code the walk reaches afterwards may
        // legitimately append nodes and enter the critical section, so only the
        // facts the guard owns are checked here: where the node lives, that it
        // is a real heap block, and that its lock field is a valid state.
        const bool guard_state_ok = guard_readable
            && guard_node == kGuestHeapBase + 0x10u
            && node_count >= 1u
            && (node_lock_count == 0xffffffffu || node_lock_count == 0u)
            && guard_counter >= 1u
            && mutex_name == "SingleMgrMutex00001234"
            && printed_name == mutex_name
            && encoded_node == "5e000010"
            && environment_value == encoded_node;

        // Every lifted body records itself, so the ring names the chain that
        // reached the failing instruction instead of leaving it to inference.
        std::printf("DETAIL crt_cpp_walk_bodies total=%llu\n",
                    static_cast<unsigned long long>(
                        batch_guest_body_trace.total));
        {
            std::uint32_t bodies[kGuestBodyTraceCapacity]{};
            const std::size_t shown = batch_guest_body_trace_read(
                bodies, kBodyTracePrinted);
            for (std::size_t index = 0; index < shown; ++index) {
                std::printf("DETAIL crt_cpp_walk_body %u 0x%08x\n",
                            static_cast<unsigned>(index), bodies[index]);
            }
        }
        std::printf("DETAIL crt_cpp_walk_calls count=%u\n",
                    static_cast<unsigned>(calls.size()));
        const std::size_t first_call =
            calls.size() > 16u ? calls.size() - 16u : 0u;
        for (std::size_t index = first_call; index < calls.size(); ++index) {
            std::printf("DETAIL crt_cpp_walk_call %u %s arg0=0x%08x "
                        "result=0x%08x\n",
                        static_cast<unsigned>(index),
                        calls[index].symbol.c_str(),
                        calls[index].arguments.empty()
                            ? 0u : calls[index].arguments[0],
                        calls[index].result);
        }

        if (!reached_boundary || !frame_matches || !esi_is_one ||
                !edi_is_lock || !table_matches || !cookie_consistent ||
                !startupinfo_ok || !startupinfo_zeroed ||
                !lock_owner_installed || !state_still_initializing ||
                !try_level_is_one || !walk_stopped || !args_match ||
                !sections_initialised || !tls_ok || !guard_order_ok ||
                !guard_state_ok) {
            std::printf("FAIL crt_cpp_walk status=%u eip=0x%08x esp=0x%08x "
                        "ebp=0x%08x eax=0x%08x edx=0x%08x boundary=%d frame=%d table=%d cookie=%d "
                        "startupinfo=%d lock=%d state=%d try=%d walk=%u "
                        "stopped=0x%08x/%d args=%d argc=%u argv=0x%08x "
                        "envp=0x%08x argv0=0x%08x sections=%u/%u tls=%u/%d "
                        "prefix=0x%08x esp=0x%08x kInittermEsp=0x%08x "
                        "guard=%d,%u/%u node=0x%08x/%d counter=%u/%d "
                        "name=%s name_ptr=0x%08x name_len=%u "
                        "encoded=%s env=%s error=%s\n",
                        static_cast<unsigned>(status), state.eip, state.regs[4],
                        state.regs[5], state.regs[0], state.regs[2], reached_boundary, frame_matches,
                        table_matches, cookie_consistent, startupinfo_ok,
                        lock_owner_installed, state_still_initializing,
                        try_level_is_one, static_cast<unsigned>(walk_status),
                        walk_stopped_at, walk_stopped, args_match, argc, argv,
                        envp, argv0, sections_ready, sections, tls_calls,
                        tls_ok, prefix_eip, walk_esp, kInittermEsp,
                        guard_order_ok, static_cast<unsigned>(guard_matched),
                        static_cast<unsigned>(std::size(kGuardOrder)),
                        guard_node, guard_state_ok, guard_counter,
                        guard_counter >= 1u, mutex_name.c_str(),
                        mutex_name_pointer,
                        static_cast<unsigned>(mutex_name.size()),
                        encoded_node.c_str(), environment_value.c_str(),
                        imports.last_error().c_str());
            return 1;
        }
        std::printf("PASS crt_cpp_walk stop=0x%08x failed_at=0x%08x executed=%u "
                    "esp_delta=-136 ebp=entry-4 cookie=consistent "
                    "imports=%u initializers=%u walk=stopped_at_0x%08x "
                    "args=argc1,argv_guest,envp_empty sections=%u tls=%u "
                    "guard=single_instance node=0x%08x count=%u mutex=%s "
                    "encoded=%s\n",
                    prefix_eip, state.eip, executed_instructions(),
                    static_cast<unsigned>(calls.size()),
                    kBatchInitializerCount, walk_stopped_at, sections,
                    tls_calls, guard_node, static_cast<unsigned>(guard_counter),
                    mutex_name.c_str(), encoded_node.c_str());
        std::printf("DETAIL crt_cpp_walk cookie=0x%08x complement=0x%08x "
                    "lock=0x%08x state=0x%08x argv=0x%08x envp=0x%08x "
                    "name=0x%08x\n",
                    cookie_low, cookie_high, lock_value, state_value, argv,
                    envp, argv0);
        return 0;
    } else {
        std::uint32_t lock_value = 0, state_value = 0, try_level = 0;
        const bool lock_ok = memory.load32(kStartupLock, lock_value);
        const bool state_ok = memory.load32(kStartupLockState, state_value);
        const bool frame_readable = memory.load32(
            BatchLiftMemory::kEntryEsp - 4u - 4u, try_level);
        const bool reached_boundary =
            status == BatchLiftStatus::unsupported_dependency &&
            state.eip == kCrtStop && state.regs[4] == boundary_esp();
        const bool frame_matches =
            state.regs[5] == BatchLiftMemory::kEntryEsp - 4u;
        const bool ebx_cleared = state.regs[3] == 0u;
        bool startupinfo_zeroed = false;
        const bool startupinfo_ok =
            startupinfo_contract_holds(memory, startupinfo_zeroed);
        const bool imports_match = calls.size() == 7u &&
            calls[5].symbol == "KERNEL32.dll!GetStartupInfoA" &&
            calls[6].symbol == "KERNEL32.dll!InterlockedCompareExchange" &&
            calls[6].arguments.size() == 3u &&
            calls[6].arguments[0] == kStartupLock &&
            calls[6].arguments[1] == kGuestStackBase &&
            calls[6].arguments[2] == 0u;
        // The lock was free, so the compare-exchange installs this thread as
        // owner and returns zero: the JZ path is the one that runs.
        const bool icc_acquired = state.regs[0] == 0u;
        const bool owner_is_stack_base =
            state.regs[6] == kGuestStackBase;
        const bool try_level_is_one = frame_readable && try_level == 1u;
        const bool edi_is_lock = state.regs[7] == kStartupLock;
        const bool lock_owner_installed = lock_ok && lock_value == kGuestStackBase;
        const bool state_untouched = state_ok && state_value == 0u;

        if constexpr (kCrtStop == 0x011e0f24u) {
            if (!reached_boundary || !frame_matches || !ebx_cleared ||
                    !edi_is_lock || !cookie_consistent ||
                    !imports_match || !startupinfo_ok ||
                    !startupinfo_zeroed || !icc_acquired ||
                    !owner_is_stack_base || !lock_owner_installed ||
                    !state_untouched || !try_level_is_one) {
                std::printf("FAIL crt_interlocked status=%u eip=0x%08x "
                            "esp=0x%08x ebp=0x%08x ebx=0x%08x eax=0x%08x "
                            "esi=0x%08x boundary=%d frame=%d ebx_ok=%d "
                            "edi_ok=%d cookie=%d imports=%d calls=%u "
                            "lock=0x%08x state=0x%08x try=%d startupinfo=%d\n",
                            static_cast<unsigned>(status), state.eip,
                            state.regs[4], state.regs[5], state.regs[3],
                            state.regs[0], state.regs[6], reached_boundary,
                            frame_matches, ebx_cleared, edi_is_lock,
                            cookie_consistent, imports_match,
                            static_cast<unsigned>(calls.size()), lock_value,
                            state_value, try_level_is_one, startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_interlocked stop=0x%08x executed=%u "
                        "esp_delta=-124 ebp=entry-4 ebx=0 edi=lock_reg "
                        "cookie=consistent imports=7 icc=acquired previous=0 "
                        "owner=stack_base lock=owner try_level=1 "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        state.eip, executed_instructions());
            std::printf("DETAIL crt_interlocked cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "owner=0x%08x\n",
                        cookie_low, cookie_high, lock_value, state_value,
                        state.regs[6]);
            return 0;
        } else if constexpr (kCrtStop == 0x011e0f43u) {
            const bool esi_is_one = state.regs[6] == 1u;
            const bool state_read_is_zero = state.regs[0] == 0u;
            if (!reached_boundary || !frame_matches || !ebx_cleared ||
                    !esi_is_one || !edi_is_lock || !cookie_consistent ||
                    !imports_match || !startupinfo_ok ||
                    !startupinfo_zeroed || !icc_acquired ||
                    !lock_owner_installed || !state_untouched ||
                    !try_level_is_one || !state_read_is_zero) {
                std::printf("FAIL crt_startup_lock status=%u eip=0x%08x "
                            "esp=0x%08x ebp=0x%08x ebx=0x%08x eax=0x%08x "
                            "esi=0x%08x boundary=%d frame=%d esi_ok=%d "
                            "edi_ok=%d cookie=%d imports=%d calls=%u "
                            "lock=0x%08x state=0x%08x try=%d startupinfo=%d\n",
                            static_cast<unsigned>(status), state.eip,
                            state.regs[4], state.regs[5], state.regs[3],
                            state.regs[0], state.regs[6], reached_boundary,
                            frame_matches, esi_is_one, edi_is_lock,
                            cookie_consistent, imports_match,
                            static_cast<unsigned>(calls.size()), lock_value,
                            state_value, try_level_is_one, startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_startup_lock stop=0x%08x executed=%u "
                        "esp_delta=-124 ebp=entry-4 ebx=0 esi=1 "
                        "edi=lock_reg cookie=consistent imports=7 "
                        "icc=acquired owner=stack_base lock=owner state=0 "
                        "try_level=1 "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        state.eip, executed_instructions());
            std::printf("DETAIL crt_startup_lock cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "owner=0x%08x\n",
                        cookie_low, cookie_high, lock_value, state_value,
                        kGuestStackBase);
            return 0;
        } else {
            std::uint32_t table_begin = 0, table_end = 0;
            const bool table_readable =
                memory.load32(boundary_esp(), table_begin) &&
                memory.load32(boundary_esp() + 4u, table_end);
            const bool esi_is_one = state.regs[6] == 1u;
            const bool state_written = state_ok && state_value == 1u;
            if (!reached_boundary || !frame_matches || !ebx_cleared ||
                    !esi_is_one || !edi_is_lock || !cookie_consistent ||
                    !imports_match || !startupinfo_ok ||
                    !startupinfo_zeroed || !icc_acquired ||
                    !lock_owner_installed || !state_written ||
                    !try_level_is_one || !table_readable ||
                    table_begin != kInittermTable ||
                    table_end != kInittermTableEnd) {
                std::printf("FAIL crt_initterm_call status=%u eip=0x%08x "
                            "esp=0x%08x ebp=0x%08x ebx=0x%08x eax=0x%08x "
                            "esi=0x%08x boundary=%d frame=%d esi_ok=%d "
                            "edi_ok=%d cookie=%d imports=%d calls=%u "
                            "lock=0x%08x state=0x%08x try=%d table=%d,%08x,"
                            "%08x startupinfo=%d\n",
                            static_cast<unsigned>(status), state.eip,
                            state.regs[4], state.regs[5], state.regs[3],
                            state.regs[0], state.regs[6], reached_boundary,
                            frame_matches, esi_is_one, edi_is_lock,
                            cookie_consistent, imports_match,
                            static_cast<unsigned>(calls.size()), lock_value,
                            state_value, try_level_is_one, table_readable,
                            table_begin, table_end, startupinfo_ok);
                return 1;
            }
            std::printf("PASS crt_initterm_call stop=0x%08x executed=%u "
                        "esp_delta=-132 ebp=entry-4 ebx=0 esi=1 "
                        "edi=lock_reg cookie=consistent imports=7 "
                        "icc=acquired owner=stack_base lock=owner state=1 "
                        "try_level=1 table=0x13eb09c..0x13eb0ac "
                        "startupinfo=cb,ptrs_valid,reserved_null\n",
                        state.eip, executed_instructions());
            std::printf("DETAIL crt_initterm_call cookie=0x%08x "
                        "complement=0x%08x lock=0x%08x state=0x%08x "
                        "table=%08x,%08x\n",
                        cookie_low, cookie_high, lock_value, state_value,
                        table_begin, table_end);
            return 0;
        }
    }
}
