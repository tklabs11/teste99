#include "BatchStaticLiftRuntime.hpp"
#include "closure_reference_bytes.hpp"
#include "m7_cfg_data.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

#if defined(_M_IX86)
#include <Windows.h>
#endif

constexpr std::uint32_t kObject = 0x20000000u;
constexpr std::uint32_t kInput = 0x20010000u;
constexpr std::uint32_t kBuffer = 0x20010100u;
#if defined(M7_THROUGH_ALLOCATOR)
constexpr std::uint32_t kBoundary = 0x00a221fcu;
#else
constexpr std::uint32_t kBoundary = 0x00a2360du;
#endif
constexpr std::uint32_t kCodeBase = 0x00921260u;
constexpr std::size_t kCodeSize = 0x120000u;

void dump_snapshot(const char* kind, std::uint32_t eax, std::uint32_t ecx,
                   std::uint32_t edx, std::uint32_t ebx, std::int32_t esp_delta,
                   std::uint32_t ebp, std::uint32_t esi, std::uint32_t edi,
                   std::uint32_t flags, const std::uint8_t* object) {
    std::printf("kind=%s boundary=%08x eax=%08x ecx=%08x edx=%08x ebx=%08x "
                "esp_delta=%d ebp=%08x esi=%08x edi=%08x flags=%08x fields=",
                kind, kBoundary, eax, ecx, edx, ebx, esp_delta, ebp, esi, edi,
                flags & 0x8d5u);
    for (std::size_t offset = 0; offset <= 0x34; offset += 4) {
        std::uint32_t value = 0;
        std::memcpy(&value, object + offset, 4);
        std::printf("%s%08x", offset ? "," : "", value);
    }
    std::printf(" buffer=");
    for (std::size_t offset = 0; offset < 32; ++offset)
        std::printf("%02x", object[0x10100 + offset]);
    std::putchar('\n');
}

#if defined(_M_IX86)
static_assert(sizeof(void*) == 4, "Windows x86 reference required");
static volatile std::uint32_t g_entry = 0;
static volatile std::uint32_t g_entry_esp = 0;
static volatile std::uint32_t g_boundary_runtime = 0;
static CONTEXT g_context{};
static volatile std::uint32_t g_exception = 0;

static int capture(EXCEPTION_POINTERS* pointers) {
    g_exception = pointers->ExceptionRecord->ExceptionCode;
    g_context = *pointers->ContextRecord;
    return EXCEPTION_EXECUTE_HANDLER;
}

static int invoke(std::uint8_t* object) {
    const auto input = kInput;
    __try {
        __asm {
            push input
            push 0
            push 0
            push 0
            push 0
            push 0
            push 2
            mov ecx, object
            lea eax, [esp - 4]
            mov dword ptr [g_entry_esp], eax
            mov eax, dword ptr [g_entry]
            call eax
            int 3
        }
        return 2;
    } __except(capture(GetExceptionInformation())) {
        return 0;
    }
}

template<std::size_t N>
void copy_instructions(std::uint8_t* code,
                       const std::array<SporeVerifiedInstruction, N>& instructions) {
    for (const auto& instruction : instructions)
        std::memcpy(code + instruction.address - kCodeBase,
                    instruction.bytes.data(), instruction.length);
}

int main() {
    auto* code = static_cast<std::uint8_t*>(VirtualAlloc(
        nullptr, kCodeSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
    auto* object = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(kObject), 0x20000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* initial = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x01480000u), 0x10000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* scale = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x01470000u), 0x10000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* table = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x01430000u), 0x10000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    auto* correction = static_cast<std::uint8_t*>(VirtualAlloc(
        reinterpret_cast<void*>(0x013f0000u), 0x10000u,
        MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
    if (!code || object != reinterpret_cast<void*>(kObject) ||
        initial != reinterpret_cast<void*>(0x01480000u) ||
        scale != reinterpret_cast<void*>(0x01470000u) ||
        table != reinterpret_cast<void*>(0x01430000u) ||
        correction != reinterpret_cast<void*>(0x013f0000u)) {
        std::printf("map_failure code=%p object=%p initial=%p scale=%p table=%p correction=%p\n",
                    code, object, initial, scale, table, correction);
        return 2;
    }
    std::memcpy(initial + 0x5718, kM7CfgInitialFloat.data(), 4);
    std::memcpy(scale + 0x0f14, kM7CfgScaleFloat.data(), 4);
    std::memcpy(table + 0xd850, kM7CfgLookupTable.data(), kM7CfgLookupTable.size());
    std::memcpy(correction + 0x4fd0, kM7CfgCorrection.data(), 4);
    std::memcpy(object + 0x10000, &kBuffer, 4);
    const std::uint32_t marker = 0x12345678u;
    std::memcpy(object + 0x10014, &marker, 4);
    copy_instructions(code, kSporeInstructions_00921260);
    copy_instructions(code, kSporeInstructions_00921300);
    copy_instructions(code, kSporeInstructions_00921360);
    copy_instructions(code, kSporeInstructions_00a23570);
#if defined(M7_THROUGH_ALLOCATOR)
    copy_instructions(code, kSporeInstructions_00a221b0);
#endif
    code[kBoundary - kCodeBase] = 0xccu;
    g_entry = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        code + 0x00a23570u - kCodeBase));
    g_boundary_runtime = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
        code + kBoundary - kCodeBase));
    const int result = invoke(object);
    if (result || g_exception != EXCEPTION_BREAKPOINT ||
        g_context.Eip != g_boundary_runtime + 1u) {
        std::printf("capture_failure result=%d exception=%08x eip=%08x expected=%08x\n",
                    result, g_exception, g_context.Eip, g_boundary_runtime + 1u);
        return 3;
    }
    dump_snapshot("original_x86", g_context.Eax, g_context.Ecx,
                  g_context.Edx, g_context.Ebx,
                  static_cast<std::int32_t>(g_context.Esp - g_entry_esp),
                  g_context.Ebp, g_context.Esi, g_context.Edi,
                  g_context.EFlags, object);
    return 0;
}

#else
BatchLiftStatus spore_lift_00a23570(BatchLiftMemory&, BatchLiftState&);

int main() {
    BatchLiftMemory memory;
    std::array<std::uint8_t, 0x20000> object{};
    auto initial = kM7CfgInitialFloat;
    auto scale = kM7CfgScaleFloat;
    auto table = kM7CfgLookupTable;
    auto correction = kM7CfgCorrection;
    if (!memory.map_region(kObject, object.data(), object.size(), true) ||
        !memory.map_region(0x01485718u, initial.data(), initial.size(), false) ||
        !memory.map_region(0x01470f14u, scale.data(), scale.size(), false) ||
        !memory.map_region(0x0143d850u, table.data(), table.size(), false) ||
        !memory.map_region(0x013f4fd0u, correction.data(), correction.size(), false))
        return 2;
    memory.store32(kInput, kBuffer);
    memory.store32(kInput + 0x14u, 0x12345678u);
    BatchLiftState state{};
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObject;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0x11223344u;
    state.regs[4] = BatchLiftMemory::kEntryEsp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = 0x99aabbccu;
    state.regs[7] = 0xddeeff00u;
    state.eflags = 0x202u;
    state.eip = 0x00a23570u;
    const auto esp = state.regs[4];
    memory.store32(esp, BatchLiftMemory::kReturnSentinel);
    for (std::uint32_t offset = 4; offset <= 24; offset += 4)
        memory.store32(esp + offset, offset == 4 ? 2u : 0u);
    memory.store32(esp + 28u, kInput);
    const auto status = spore_lift_00a23570(memory, state);
    if (status != BatchLiftStatus::unsupported_dependency ||
        state.eip != kBoundary) {
        std::printf("lift_failure status=%u eip=%08x\n",
                    static_cast<unsigned>(status), state.eip);
        return 3;
    }
#if defined(__aarch64__) || defined(_M_ARM64)
    constexpr auto* kLiftKind = "lift_android_arm64";
#else
    constexpr auto* kLiftKind = "lift_x86_host";
#endif
    dump_snapshot(kLiftKind, state.regs[0], state.regs[1],
                  state.regs[2], state.regs[3],
                  static_cast<std::int32_t>(state.regs[4] - esp),
                  state.regs[5], state.regs[6], state.regs[7],
                  state.eflags, object.data());
    return 0;
}
#endif
