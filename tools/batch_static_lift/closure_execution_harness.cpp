#include "BatchStaticLiftRuntime.hpp"
#include "closure_reference_bytes.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#if defined(_M_IX86)
#include <Windows.h>
#include <intrin.h>

static_assert(sizeof(void*) == sizeof(std::uint32_t), "x86 process required");
#endif

BatchLiftStatus spore_lift_00921e00(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_00921e60(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_00921f00(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_00922150(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_009222a0(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_009225d0(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_00922620(BatchLiftMemory&, BatchLiftState&);
BatchLiftStatus spore_lift_00922820(BatchLiftMemory&, BatchLiftState&);

namespace {

constexpr std::uint32_t kObjectBase = 0x20000000u;
constexpr std::size_t kObjectSize = 0x400u;
constexpr std::uint32_t kStackBase = 0x71000000u;
constexpr std::size_t kStackSize = 0x4000u;
constexpr std::size_t kStackTopOffset = 0x3000u;
constexpr std::size_t kStackEntryFrameBytes = 3u * sizeof(std::uint32_t);
constexpr std::size_t kCriticalSectionSpinCountOffset =
    5u * sizeof(std::uint32_t);
constexpr std::uint32_t kReturnAddress = 0x00a3366fu;
constexpr std::uint32_t kObjectCanary = 0x8badf00du;
constexpr std::uint32_t kStackCanary = 0x8badf00du;
constexpr std::uint32_t kCodeBase = 0x00921e00u;
constexpr std::size_t kCodeSize = 0x1000u;

struct NativeCall {
    std::string symbol;
    std::uint32_t return_address{};
    std::array<std::uint32_t, 4> arguments{};
    std::uint32_t argument_count{};
    std::uint32_t result{};
    std::uint32_t last_error{};
};

struct NativeObserver {
    std::vector<NativeCall> calls;
};

struct Snapshot {
    std::array<std::uint32_t, 8> registers{};
    std::uint32_t eflags{};
    std::uint32_t esp_delta{};
    std::array<std::uint8_t, kObjectSize> object{};
    std::array<std::uint8_t, kStackSize> stack{};
    std::string calls;
    std::string object_hex;
    std::string stack_entry_frame_hex;
};

std::string hex_bytes(const std::uint8_t* bytes, std::size_t size) {
    static constexpr char digits[] = "0123456789abcdef";
    std::string result(size * 2u, '0');
    for (std::size_t index = 0; index < size; ++index) {
        result[index * 2u] = digits[bytes[index] >> 4u];
        result[index * 2u + 1u] = digits[bytes[index] & 0x0fu];
    }
    return result;
}

std::string hex_word(std::uint32_t value) {
    std::ostringstream stream;
    stream << std::hex << std::setfill('0') << std::setw(8) << value;
    return stream.str();
}

std::uint32_t load_word(const std::uint8_t* bytes) {
    std::uint32_t value{};
    std::memcpy(&value, bytes, sizeof(value));
    return value;
}

void store_word(std::uint8_t* bytes, std::uint32_t value) {
    std::memcpy(bytes, &value, sizeof(value));
}

template <std::size_t N>
bool copy_verified_instructions(
    std::uint8_t* image,
    std::size_t image_size,
    const std::array<SporeVerifiedInstruction, N>& instructions) {
    for (const SporeVerifiedInstruction& instruction : instructions) {
        if (instruction.address < kCodeBase) return false;
        const std::size_t offset =
            static_cast<std::size_t>(instruction.address - kCodeBase);
        if (offset > image_size
            || instruction.length > image_size - offset) {
            return false;
        }
        std::memcpy(
            image + offset, instruction.bytes.data(), instruction.length);
    }
    return true;
}

void initialize_object(std::array<std::uint8_t, kObjectSize>& object) {
    object.fill(0u);
    store_word(object.data() + kObjectSize - sizeof(std::uint32_t), kObjectCanary);
}

bool initialize_guest_memory(
    BatchLiftMemory& memory,
    std::array<std::uint8_t, kObjectSize>& object,
    std::array<std::uint8_t, kStackSize>& stack,
    BatchLiftState& state,
    BatchGuestRuntime& runtime) {
    initialize_object(object);
    stack.fill(0u);
    if (!memory.map_region(kObjectBase, object.data(), object.size(), true)
        || !memory.map_region(kStackBase, stack.data(), stack.size(), true)
        || !memory.store32(kStackBase, kStackCanary)) {
        std::cerr << "ERROR could not map closure guest state\n";
        return false;
    }

    const std::uint32_t entry_esp = kStackBase
        + static_cast<std::uint32_t>(kStackTopOffset - 12u);
    state.regs[0] = 0x87654321u;
    state.regs[1] = kObjectBase + 0x28u;
    state.regs[2] = 0x12345678u;
    state.regs[3] = 0u;
    state.regs[4] = entry_esp;
    state.regs[5] = 0x55667788u;
    state.regs[6] = kObjectBase;
    state.regs[7] = 1u;
    state.eflags = 0x202u;
    state.eip = kSporeEntry_00921f00;
    state.imports = &runtime;
    if (!memory.store32(entry_esp, kReturnAddress)
        || !memory.store32(entry_esp + 4u, 0u)
        || !memory.store32(entry_esp + 8u, 1u)) {
        std::cerr << "ERROR could not initialize closure entry stack\n";
        return false;
    }
    return true;
}

#if defined(_M_IX86)

constexpr std::uint32_t kIatBase = 0x013cc000u;

thread_local NativeObserver* g_native_observer{};
volatile std::uint32_t g_native_code_base{};
volatile std::uint32_t g_native_entry{};
volatile std::uint32_t g_native_object_base{};
volatile std::uint32_t g_native_stack_base{};
volatile std::uint32_t g_native_stack_top{};
volatile std::uint32_t g_native_saved_esp{};
volatile std::uint32_t g_native_entry_esp{};
volatile std::uint32_t g_native_final_esp{};
volatile std::uint32_t g_native_regs[8]{};
volatile std::uint32_t g_native_eflags{};

std::uint32_t address32(const void* pointer) {
    return static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(pointer));
}

std::uint32_t guest_return_address(const void* return_address) {
    const std::uint32_t address = address32(return_address);
    const std::uint32_t code_base = g_native_code_base;
    if (address < code_base || address - code_base >= kCodeSize) return 0u;
    return kCodeBase + (address - code_base);
}

void record_native_call(
    NativeCall call,
    const void* return_address) {
    if (g_native_observer == nullptr) return;
    call.return_address = guest_return_address(return_address);
    std::cerr << "NATIVE_IMPORT " << call.symbol << " site=0x"
              << hex_word(call.return_address) << " args=";
    for (std::size_t index = 0; index < call.argument_count; ++index) {
        if (index != 0u) std::cerr << ',';
        std::cerr << "0x" << hex_word(call.arguments[index]);
    }
    std::cerr << " result=0x" << hex_word(call.result)
              << " error=" << call.last_error << "\n";
    if (call.symbol == "KERNEL32.dll!InitializeCriticalSection") {
        std::cerr << "NATIVE_CRITICAL_SECTION_OFFSET=0x"
                  << hex_word(call.arguments[0] - g_native_object_base)
                  << "\n";
    }
    g_native_observer->calls.push_back(std::move(call));
}

LONG CALLBACK report_native_exception(EXCEPTION_POINTERS* exception) {
    const CONTEXT* context = exception->ContextRecord;
    std::cerr << "NATIVE_EXCEPTION code=0x"
              << hex_word(exception->ExceptionRecord->ExceptionCode)
              << " address=0x"
              << hex_word(address32(exception->ExceptionRecord->ExceptionAddress))
              << " eip=0x" << hex_word(context->Eip)
              << " esp=0x" << hex_word(context->Esp) << "\n";
    return EXCEPTION_CONTINUE_SEARCH;
}

extern "C" __declspec(noinline) char* __cdecl observed_strncpy(
    char* destination,
    const char* source,
    std::size_t count) {
    const void* return_address = _ReturnAddress();
    NativeCall call{};
    call.symbol = "MSVCR90.dll!strncpy";
    call.argument_count = 3u;
    call.arguments[0] = address32(destination);
    call.arguments[1] = address32(source);
    call.arguments[2] = static_cast<std::uint32_t>(count);
#pragma warning(push)
#pragma warning(disable: 4996)
    char* result = std::strncpy(destination, source, count);
#pragma warning(pop)
    call.result = address32(result);
    record_native_call(std::move(call), return_address);
    return result;
}

extern "C" __declspec(noinline) HANDLE WINAPI observed_create_mutex(
    LPSECURITY_ATTRIBUTES attributes,
    BOOL initial_owner,
    LPCSTR name) {
    const void* return_address = _ReturnAddress();
    SetLastError(0u);
    HANDLE result = CreateMutexA(attributes, initial_owner, name);
    const DWORD last_error = GetLastError();
    NativeCall call{};
    call.symbol = "KERNEL32.dll!CreateMutexA";
    call.argument_count = 3u;
    call.arguments[0] = address32(attributes);
    call.arguments[1] = static_cast<std::uint32_t>(initial_owner);
    call.arguments[2] = address32(name);
    call.result = address32(result);
    call.last_error = last_error;
    record_native_call(std::move(call), return_address);
    return result;
}

extern "C" __declspec(noinline) HANDLE WINAPI observed_create_semaphore(
    LPSECURITY_ATTRIBUTES attributes,
    LONG initial_count,
    LONG maximum_count,
    LPCSTR name) {
    const void* return_address = _ReturnAddress();
    SetLastError(0u);
    HANDLE result = CreateSemaphoreA(
        attributes, initial_count, maximum_count, name);
    const DWORD last_error = GetLastError();
    NativeCall call{};
    call.symbol = "KERNEL32.dll!CreateSemaphoreA";
    call.argument_count = 4u;
    call.arguments[0] = address32(attributes);
    call.arguments[1] = static_cast<std::uint32_t>(initial_count);
    call.arguments[2] = static_cast<std::uint32_t>(maximum_count);
    call.arguments[3] = address32(name);
    call.result = address32(result);
    call.last_error = last_error;
    record_native_call(std::move(call), return_address);
    return result;
}

extern "C" __declspec(noinline) void WINAPI observed_initialize_critical_section(
    LPCRITICAL_SECTION section) {
    const void* return_address = _ReturnAddress();
    InitializeCriticalSection(section);
    NativeCall call{};
    call.symbol = "KERNEL32.dll!InitializeCriticalSection";
    call.argument_count = 1u;
    call.arguments[0] = address32(section);
    record_native_call(std::move(call), return_address);
}

struct NativeImage {
    std::uint8_t* code{};
    std::uint8_t* iat{};

    ~NativeImage() {
        if (code != nullptr) VirtualFree(code, 0u, MEM_RELEASE);
        if (iat != nullptr) VirtualFree(iat, 0u, MEM_RELEASE);
    }

    bool initialize() {
        std::array<std::uint8_t, kCodeSize> bytes{};
        bytes.fill(0xccu);
        if (!copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00921e00)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00921e60)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00921f00)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00922150)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_009222a0)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_009225d0)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00922620)
            || !copy_verified_instructions(
                bytes.data(), bytes.size(), kSporeInstructions_00922820)) {
            return false;
        }
        code = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, kCodeSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        iat = static_cast<std::uint8_t*>(VirtualAlloc(
            nullptr, 0x1000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
        if (code == nullptr || iat == nullptr) return false;
        std::memcpy(code, bytes.data(), bytes.size());
        const auto install_import = [this](
            std::uint32_t site,
            std::uint32_t original_iat,
            std::uintptr_t target) {
            const std::size_t iat_offset = original_iat - kIatBase;
            if (iat_offset > 0x1000u - sizeof(std::uint32_t)) return false;
            const std::uint32_t target_address =
                static_cast<std::uint32_t>(target);
            std::memcpy(iat + iat_offset, &target_address, sizeof(target_address));
            const std::uint32_t relocated_iat =
                address32(iat + iat_offset);
            std::memcpy(
                code + (site - kCodeBase) + 2u,
                &relocated_iat,
                sizeof(relocated_iat));
            return true;
        };
        if (!install_import(
                0x00921e18u, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&observed_strncpy))
            || !install_import(
                0x0092216cu, 0x013cc2d0u,
                reinterpret_cast<std::uintptr_t>(
                    observed_initialize_critical_section))
            || !install_import(
                0x00922189u, 0x013cc180u,
                reinterpret_cast<std::uintptr_t>(observed_create_mutex))
            || !install_import(
                0x009225efu, 0x013cc4f4u,
                reinterpret_cast<std::uintptr_t>(&observed_strncpy))
            || !install_import(
                0x0092266du, 0x013cc198u,
                reinterpret_cast<std::uintptr_t>(
                    &observed_create_semaphore))) {
            return false;
        }
        DWORD previous_protection{};
        if (!VirtualProtect(
                code, kCodeSize, PAGE_EXECUTE_READ, &previous_protection)) {
            return false;
        }
        FlushInstructionCache(GetCurrentProcess(), code, kCodeSize);
        return true;
    }
};

alignas(16) std::array<std::uint8_t, kObjectSize> g_native_object{};
alignas(16) std::array<std::uint8_t, kStackSize> g_native_stack{};

bool run_original_x86(
    NativeImage& image,
    NativeObserver& observer,
    Snapshot& snapshot) {
    initialize_object(g_native_object);
    g_native_stack.fill(0u);
    store_word(g_native_stack.data(), kStackCanary);
    const std::uint32_t stack_base = address32(g_native_stack.data());
    const std::uint32_t object_base = address32(g_native_object.data());
    const std::uint32_t stack_top =
        stack_base + static_cast<std::uint32_t>(kStackTopOffset);
    g_native_code_base = address32(image.code);
    g_native_entry = address32(image.code
        + (kSporeEntry_00921f00 - kCodeBase));
    g_native_object_base = object_base;
    g_native_stack_base = stack_base;
    g_native_stack_top = stack_top;
    g_native_observer = &observer;
    std::cerr << "NATIVE_LAYOUT object=0x" << hex_word(object_base)
              << " stack=0x" << hex_word(stack_base)
              << " code=0x" << hex_word(g_native_code_base)
              << " object_bytes=" << kObjectSize << "\n";
    g_native_entry_esp = 0u;
    g_native_final_esp = 0u;
    g_native_eflags = 0u;
    for (volatile std::uint32_t& reg : g_native_regs) reg = 0u;

    __asm {
        push ebx
        push ebp
        push esi
        push edi
        mov dword ptr [g_native_saved_esp], esp
        mov esp, dword ptr [g_native_stack_top]
        mov eax, 87654321h
        mov ebx, 0
        mov ecx, dword ptr [g_native_object_base]
        add ecx, 28h
        mov edx, 12345678h
        mov esi, dword ptr [g_native_object_base]
        mov edi, 1
        mov ebp, 55667788h
        push 202h
        popfd
        push 1
        push 0
        lea eax, [esp - 4]
        mov dword ptr [g_native_entry_esp], eax
        call dword ptr [g_native_entry]
        mov dword ptr [g_native_final_esp], esp
        mov dword ptr [g_native_regs + 0], eax
        mov dword ptr [g_native_regs + 4], ecx
        mov dword ptr [g_native_regs + 8], edx
        mov dword ptr [g_native_regs + 12], ebx
        mov dword ptr [g_native_regs + 16], esp
        mov dword ptr [g_native_regs + 20], ebp
        mov dword ptr [g_native_regs + 24], esi
        mov dword ptr [g_native_regs + 28], edi
        mov esp, dword ptr [g_native_saved_esp]
        pushfd
        pop dword ptr [g_native_eflags]
        pop edi
        pop esi
        pop ebp
        pop ebx
    }

    std::copy(g_native_object.begin(), g_native_object.end(),
        snapshot.object.begin());
    std::copy(g_native_stack.begin(), g_native_stack.end(),
        snapshot.stack.begin());
    for (std::size_t index = 0; index < snapshot.registers.size(); ++index) {
        snapshot.registers[index] = g_native_regs[index];
    }
    snapshot.eflags = g_native_eflags;
    snapshot.esp_delta = g_native_final_esp - stack_top;
    const std::size_t return_offset =
        static_cast<std::size_t>(g_native_entry_esp - stack_base);
    if (return_offset + sizeof(std::uint32_t) > snapshot.stack.size()) {
        g_native_observer = nullptr;
        return false;
    }
    store_word(snapshot.stack.data() + return_offset, kReturnAddress);
    g_native_observer = nullptr;
    return true;
}

#endif

std::uint32_t normalize_address(
    std::uint32_t value,
    std::uint32_t object_base,
    std::uint32_t stack_base,
    std::uint32_t code_base,
    const std::vector<std::pair<std::uint32_t, std::uint32_t>>& handles) {
    for (std::size_t index = 0; index < handles.size(); ++index) {
        if (value == handles[index].first) {
            return handles[index].second;
        }
    }
    if (value >= object_base && value - object_base < kObjectSize) {
        return kObjectBase + (value - object_base);
    }
    if (value >= stack_base && value - stack_base < kStackSize) {
        return kStackBase + (value - stack_base);
    }
    if (value >= code_base && value - code_base < kCodeSize) {
        return kCodeBase + (value - code_base);
    }
    return value;
}

template <typename Calls>
std::vector<std::pair<std::uint32_t, std::uint32_t>> collect_handles(
    const Calls& calls) {
    std::vector<std::pair<std::uint32_t, std::uint32_t>> handles;
    std::uint32_t next_handle_id = 1u;
    for (const auto& call : calls) {
        if (call.symbol != "KERNEL32.dll!CreateMutexA"
            && call.symbol != "KERNEL32.dll!CreateSemaphoreA") {
            continue;
        }
        if (call.result == 0u) continue;
        auto found = std::find_if(
            handles.begin(), handles.end(),
            [&call](const auto& entry) {
                return entry.first == call.result;
            });
        if (found == handles.end()) {
            handles.emplace_back(
                call.result, 0xc0000000u | next_handle_id++);
        }
    }
    return handles;
}

void canonicalize_memory(
    std::array<std::uint8_t, kObjectSize>& object,
    std::array<std::uint8_t, kStackSize>& stack,
    std::uint32_t native_object_base,
    std::uint32_t native_stack_base,
    std::uint32_t native_code_base,
    const std::vector<std::pair<std::uint32_t, std::uint32_t>>& handles,
    const std::vector<std::uint32_t>& critical_section_offsets) {
    for (std::size_t offset = 0; offset + sizeof(std::uint32_t) <= object.size();
         offset += sizeof(std::uint32_t)) {
        const std::uint32_t value = load_word(object.data() + offset);
        store_word(
            object.data() + offset,
            normalize_address(
                value, native_object_base, native_stack_base,
                native_code_base, handles));
    }
    for (std::uint32_t offset : critical_section_offsets) {
        if (offset <= object.size() - sizeof(std::uint32_t)) {
            store_word(object.data() + offset, 0u);
        }
        if (offset <= object.size() - kCriticalSectionSpinCountOffset
                - sizeof(std::uint32_t)) {
            store_word(
                object.data() + offset + kCriticalSectionSpinCountOffset, 0u);
        }
    }
    for (std::size_t offset = 0; offset + sizeof(std::uint32_t) <= stack.size();
         offset += sizeof(std::uint32_t)) {
        const std::uint32_t value = load_word(stack.data() + offset);
        store_word(
            stack.data() + offset,
            normalize_address(
                value, native_object_base, native_stack_base,
                native_code_base, handles));
    }
}

template <typename Calls>
std::string canonical_call_trace(
    const Calls& calls,
    std::uint32_t object_base,
    std::uint32_t stack_base,
    std::uint32_t code_base,
    const std::vector<std::pair<std::uint32_t, std::uint32_t>>& handles) {
    std::ostringstream stream;
    for (const auto& call : calls) {
        const std::size_t argument_count = [&call]() {
            if constexpr (std::is_same_v<
                    std::decay_t<decltype(call)>, NativeCall>) {
                return static_cast<std::size_t>(call.argument_count);
            } else {
                return call.arguments.size();
            }
        }();
        stream << call.symbol << '@' << hex_word(call.return_address) << '(';
        for (std::size_t index = 0; index < argument_count; ++index) {
            if (index != 0u) stream << ',';
            stream << hex_word(normalize_address(
                call.arguments[index], object_base, stack_base,
                code_base, handles));
        }
        stream << ")->" << hex_word(normalize_address(
            call.result, object_base, stack_base, code_base, handles));
        if (call.symbol == "KERNEL32.dll!CreateMutexA"
            || call.symbol == "KERNEL32.dll!CreateSemaphoreA") {
            stream << '!' << call.last_error;
        }
        stream << ';';
    }
    return stream.str();
}

void finish_snapshot(
    Snapshot& snapshot,
    std::uint32_t native_object_base,
    std::uint32_t native_stack_base,
    std::uint32_t native_code_base,
    const std::vector<std::uint32_t>& critical_section_offsets,
    const std::vector<std::pair<std::uint32_t, std::uint32_t>>& handles,
    const std::string& calls) {
    for (std::uint32_t& reg : snapshot.registers) {
        reg = normalize_address(
            reg, native_object_base, native_stack_base,
            native_code_base, handles);
    }
    canonicalize_memory(
        snapshot.object, snapshot.stack,
        native_object_base, native_stack_base, native_code_base,
        handles, critical_section_offsets);
    snapshot.calls = calls;
    snapshot.object_hex = hex_bytes(
        snapshot.object.data(), snapshot.object.size());
    snapshot.stack_entry_frame_hex = hex_bytes(
        snapshot.stack.data() + kStackTopOffset - kStackEntryFrameBytes,
        kStackEntryFrameBytes);
}

bool finish_lifted_snapshot(
    Snapshot& snapshot,
    const std::array<std::uint8_t, kObjectSize>& object,
    const std::array<std::uint8_t, kStackSize>& stack,
    const BatchLiftState& state,
    const BatchGuestRuntime& runtime) {
    if (state.eip != kReturnAddress
        || state.regs[4] != kStackBase
            + static_cast<std::uint32_t>(kStackTopOffset)) {
        std::cerr << "ERROR closure did not return to its caller: eip=0x"
                  << hex_word(state.eip) << " esp=0x"
                  << hex_word(state.regs[4]) << " diagnostic="
                  << runtime.last_error() << "\n";
        return false;
    }
    std::copy(object.begin(), object.end(), snapshot.object.begin());
    std::copy(stack.begin(), stack.end(), snapshot.stack.begin());
    std::copy(std::begin(state.regs), std::end(state.regs),
        snapshot.registers.begin());
    snapshot.eflags = state.eflags;
    snapshot.esp_delta = state.regs[4]
        - (kStackBase + static_cast<std::uint32_t>(kStackTopOffset));

    const std::vector<std::pair<std::uint32_t, std::uint32_t>> handles =
        collect_handles(runtime.calls());
    std::vector<std::uint32_t> critical_section_offsets;
    for (const BatchGuestImportCall& call : runtime.calls()) {
        if (call.symbol != "KERNEL32.dll!InitializeCriticalSection"
            || call.arguments.empty()
            || call.arguments[0] < kObjectBase
            || call.arguments[0] - kObjectBase >= kObjectSize) {
            continue;
        }
        critical_section_offsets.push_back(call.arguments[0] - kObjectBase);
    }
    finish_snapshot(
        snapshot, kObjectBase, kStackBase, kCodeBase,
        critical_section_offsets, handles,
        canonical_call_trace(
            runtime.calls(), kObjectBase, kStackBase, kCodeBase, handles));
    return true;
}

#if defined(_M_IX86)
bool finish_native_snapshot(
    Snapshot& snapshot,
    const NativeObserver& observer) {
    std::vector<std::uint32_t> critical_section_offsets;
    for (const NativeCall& call : observer.calls) {
        if (call.symbol != "KERNEL32.dll!InitializeCriticalSection"
            || call.arguments[0] < g_native_object_base
            || call.arguments[0] - g_native_object_base >= kObjectSize) {
            continue;
        }
        critical_section_offsets.push_back(
            call.arguments[0] - g_native_object_base);
    }
    const std::vector<std::pair<std::uint32_t, std::uint32_t>> handles =
        collect_handles(observer.calls);
    finish_snapshot(
        snapshot, g_native_object_base, g_native_stack_base,
        g_native_code_base, critical_section_offsets, handles,
        canonical_call_trace(
            observer.calls, g_native_object_base,
            g_native_stack_base, g_native_code_base, handles));
    return true;
}
#endif

bool run_lifted(Snapshot& snapshot) {
    BatchLiftMemory memory;
    std::array<std::uint8_t, kObjectSize> object{};
    std::array<std::uint8_t, kStackSize> stack{};
    BatchLiftState state{};
    BatchGuestRuntime runtime;
    if (!initialize_guest_memory(memory, object, stack, state, runtime)) {
        return false;
    }
    const BatchLiftStatus status = spore_lift_00921f00(memory, state);
    if (status != BatchLiftStatus::returned) {
        std::cerr << "ERROR lifted closure stopped: status="
                  << static_cast<unsigned>(status) << " eip=0x"
                  << hex_word(state.eip) << " diagnostic="
                  << runtime.last_error() << "\n";
        return false;
    }
    std::uint32_t canary{};
    if (!memory.load32(
            kObjectBase + static_cast<std::uint32_t>(kObjectSize - 4u),
            canary)
        || canary != kObjectCanary) {
        std::cerr << "ERROR closure overwrote the object boundary canary\n";
        return false;
    }
    if (!memory.load32(kStackBase, canary) || canary != kStackCanary) {
        std::cerr << "ERROR closure overwrote the guest stack boundary canary\n";
        return false;
    }
    for (std::size_t offset = 0; offset < stack.size(); ++offset) {
        std::uint32_t byte{};
        if (!memory.load8(
                kStackBase + static_cast<std::uint32_t>(offset), byte)) {
            std::cerr << "ERROR could not snapshot guest stack\n";
            return false;
        }
        stack[offset] = static_cast<std::uint8_t>(byte);
    }
    return finish_lifted_snapshot(
        snapshot, object, stack, state, runtime);
}

void print_snapshot(const char* variant, const Snapshot& snapshot) {
    std::cout << "{\"variant\":\"" << variant
              << "\",\"status\":\"returned\",\"eip\":\""
              << hex_word(kReturnAddress)
              << "\",\"esp_delta\":\"" << hex_word(snapshot.esp_delta)
              << "\",\"eflags\":\"" << hex_word(snapshot.eflags)
              << "\",\"registers\":\"";
    for (std::size_t index = 0; index < snapshot.registers.size(); ++index) {
        if (index != 0u) std::cout << ',';
        std::cout << hex_word(snapshot.registers[index]);
    }
    std::cout << "\",\"calls\":\"" << snapshot.calls
              << "\",\"object\":\"" << snapshot.object_hex
              << "\",\"stack_entry_frame\":\""
              << snapshot.stack_entry_frame_hex << "\"}\n";
}

} // namespace

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: closure_execution_harness --lift"
#if defined(_M_IX86)
                  << " | --native"
#endif
                  << "\n";
        return 2;
    }

    Snapshot snapshot{};
    if (std::string(argv[1]) == "--lift") {
        if (!run_lifted(snapshot)) return 1;
        print_snapshot(
#if defined(_M_IX86)
            "lift_x86",
#else
            "lift_arm64",
#endif
            snapshot);
        return 0;
    }

#if defined(_M_IX86)
    if (std::string(argv[1]) == "--native") {
        NativeImage image;
        NativeObserver observer;
        PVOID exception_handler =
            AddVectoredExceptionHandler(1u, report_native_exception);
        if (exception_handler == nullptr) {
            std::cerr << "ERROR could not install native exception observer\n";
            return 1;
        }
        if (!image.initialize()) {
            RemoveVectoredExceptionHandler(exception_handler);
            std::cerr << "ERROR could not map byte-verified x86 closure: "
                      << GetLastError() << "\n";
            return 1;
        }
        if (!run_original_x86(image, observer, snapshot)) {
            RemoveVectoredExceptionHandler(exception_handler);
            std::cerr << "ERROR original x86 closure execution failed\n";
            return 1;
        }
        RemoveVectoredExceptionHandler(exception_handler);
        std::uint32_t canary = load_word(
            snapshot.object.data() + kObjectSize - sizeof(std::uint32_t));
        if (canary != kObjectCanary) {
                std::cerr << "ERROR original closure overwrote object canary "
                      << "value=0x" << hex_word(canary) << " tail=0x"
                          << hex_bytes(snapshot.object.data() + kObjectSize - 0x80u,
                              0x80u) << "\n";
                return 1;
            }
            if (load_word(snapshot.stack.data()) != kStackCanary) {
                std::cerr << "ERROR original closure overwrote native stack canary "
                          << "value=0x" << hex_word(load_word(snapshot.stack.data()))
                          << "\n";
                return 1;
            }
        finish_native_snapshot(snapshot, observer);
        print_snapshot("native_x86", snapshot);
        return 0;
    }
#endif

    std::cerr << "ERROR unsupported execution mode\n";
    return 2;
}
