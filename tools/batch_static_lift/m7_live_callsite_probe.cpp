#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <string>

static_assert(sizeof(void*) == 4, "Windows x86 debugger build required");

constexpr std::uintptr_t kImageBase = 0x00400000u;
constexpr std::uintptr_t kCallsite = 0x00a221fcu;
constexpr std::uintptr_t kReturnSite = 0x00a22201u;
constexpr std::uintptr_t kThunkEntry = 0x011e073eu;
constexpr std::array<unsigned char, 5> kExpectedCall = {0xe8, 0x3d, 0xe5, 0x7b, 0x00};
constexpr std::array<unsigned char, 5> kExpectedThunk = {0xe9, 0xd1, 0x0f, 0x22, 0xff};

bool read_remote(HANDLE process, std::uintptr_t address, void* out, SIZE_T size) {
    SIZE_T read = 0;
    return ReadProcessMemory(process, reinterpret_cast<const void*>(address),
                             out, size, &read) && read == size;
}

bool patch_byte(HANDLE process, std::uintptr_t address,
                unsigned char expected, unsigned char replacement) {
    unsigned char original = 0;
    if (!read_remote(process, address, &original, 1) || original != expected)
        return false;
    DWORD old_protection = 0;
    if (!VirtualProtectEx(process, reinterpret_cast<void*>(address), 1,
                          PAGE_EXECUTE_READWRITE, &old_protection))
        return false;
    SIZE_T written = 0;
    const bool success = WriteProcessMemory(process,
        reinterpret_cast<void*>(address), &replacement, 1, &written) && written == 1;
    FlushInstructionCache(process, reinterpret_cast<void*>(address), 1);
    DWORD ignored = 0;
    VirtualProtectEx(process, reinterpret_cast<void*>(address), 1,
                     old_protection, &ignored);
    return success;
}

void print_buffer_head(const char* label, const unsigned char* data, SIZE_T size) {
    std::printf("%s=", label);
    for (SIZE_T index = 0; index < size; ++index)
        std::printf("%02x", data[index]);
    std::printf("\n");
}

void print_region(HANDLE process, const char* label, std::uintptr_t address) {
    MEMORY_BASIC_INFORMATION info{};
    const SIZE_T queried = VirtualQueryEx(process,
        reinterpret_cast<const void*>(address), &info, sizeof(info));
    if (!queried) {
        std::printf("%s_QUERY_FAILED error=%lu\n", label, GetLastError());
        return;
    }
    std::printf("%s address=0x%08x base=0x%08x size=0x%zx "
                "state=0x%08lx protect=0x%08lx type=0x%08lx\n",
        label, static_cast<unsigned>(address),
        static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(info.BaseAddress)),
        info.RegionSize, info.State, info.Protect, info.Type);
    std::array<unsigned char, 64> head{};
    if (read_remote(process, address, head.data(), head.size()))
        print_buffer_head((std::string(label) + "_HEAD").c_str(),
                          head.data(), head.size());
}

int wmain(int argc, wchar_t** argv) {
    if (argc < 2 || argc > 3 ||
        (argc == 3 && std::wstring(argv[2]) != L"--through-return" &&
         std::wstring(argv[2]) != L"--first-thunk-entry" &&
         std::wstring(argv[2]) != L"--first-thunk-return")) {
        std::printf("usage: m7_live_callsite_probe.exe <SporeApp.exe> "
                    "[--through-return|--first-thunk-entry|--first-thunk-return]\n");
        return 2;
    }
    const bool through_return = argc == 3 &&
        (std::wstring(argv[2]) == L"--through-return" ||
         std::wstring(argv[2]) == L"--first-thunk-return");
    const bool first_thunk = argc == 3 &&
        (std::wstring(argv[2]) == L"--first-thunk-entry" ||
         std::wstring(argv[2]) == L"--first-thunk-return");
    const std::uintptr_t breakpoint_address = first_thunk ? kThunkEntry : kCallsite;
    const auto& expected_bytes = first_thunk ? kExpectedThunk : kExpectedCall;
    const std::wstring exe = argv[1];
    const auto separator = exe.find_last_of(L"\\/");
    if (separator == std::wstring::npos) return 2;
    const std::wstring directory = exe.substr(0, separator);
    std::wstring command = L"\"" + exe + L"\"";
    STARTUPINFOW startup{};
    startup.cb = sizeof(startup);
    startup.dwFlags = STARTF_USESHOWWINDOW;
    startup.wShowWindow = SW_HIDE;
    PROCESS_INFORMATION process{};
    if (!CreateProcessW(exe.c_str(), command.data(), nullptr, nullptr, FALSE,
                        DEBUG_ONLY_THIS_PROCESS, nullptr, directory.c_str(),
                        &startup, &process)) {
        std::printf("CREATE_PROCESS_FAILED error=%lu\n", GetLastError());
        return 1;
    }
    const DWORD timeout_ms = through_return ? 60000 : 30000;
    std::printf("PROCESS_CREATED pid=%lu timeout_ms=%lu through_return=%d\n",
                process.dwProcessId, timeout_ms, through_return);

    bool patched = false;
    bool reached = false;
    bool return_armed = false;
    bool return_reached = false;
    bool stop_requested = false;
    bool exited = false;
    bool initial_breakpoint = false;
    DWORD exit_code = 0;
    DWORD event_count = 0;
    std::uintptr_t buffer_address = 0;
    SIZE_T buffer_size = 0;
    std::uintptr_t return_site = kReturnSite;
    std::array<unsigned char, 0x400> buffer_before{};
    bool buffer_before_read = false;
    std::uintptr_t object_address = 0;
    std::array<unsigned char, 0x1100> object_before{};
    bool object_before_read = false;
    const ULONGLONG deadline = GetTickCount64() + timeout_ms;
    while (GetTickCount64() < deadline && !exited && !stop_requested &&
           !(through_return ? return_reached : reached)) {
        DEBUG_EVENT event{};
        if (!WaitForDebugEvent(&event, 1000)) {
            if (GetLastError() != ERROR_SEM_TIMEOUT) {
                std::printf("WAIT_FAILED error=%lu\n", GetLastError());
                break;
            }
            continue;
        }
        ++event_count;
        DWORD disposition = DBG_CONTINUE;
        if (event.dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT) {
            if (event.u.CreateProcessInfo.hFile)
                CloseHandle(event.u.CreateProcessInfo.hFile);
            const auto base = reinterpret_cast<std::uintptr_t>(
                event.u.CreateProcessInfo.lpBaseOfImage);
            std::printf("IMAGE_BASE=0x%08x\n", static_cast<unsigned>(base));
            std::array<unsigned char, 5> original{};
            if (base == kImageBase &&
                read_remote(process.hProcess, breakpoint_address,
                            original.data(), original.size()) &&
                original == expected_bytes) {
                patched = patch_byte(process.hProcess, breakpoint_address,
                                     expected_bytes[0], 0xcc);
            }
            std::printf("BREAKPOINT_TARGET=0x%08x bytes=%02x%02x%02x%02x%02x patched=%d\n",
                static_cast<unsigned>(breakpoint_address),
                original[0], original[1], original[2], original[3], original[4], patched);
            if (!patched) {
                ContinueDebugEvent(event.dwProcessId, event.dwThreadId, disposition);
                break;
            }
        } else if (event.dwDebugEventCode == LOAD_DLL_DEBUG_EVENT) {
            if (event.u.LoadDll.hFile) CloseHandle(event.u.LoadDll.hFile);
        } else if (event.dwDebugEventCode == EXCEPTION_DEBUG_EVENT) {
            const auto& info = event.u.Exception;
            const auto code = info.ExceptionRecord.ExceptionCode;
            const auto address = reinterpret_cast<std::uintptr_t>(
                info.ExceptionRecord.ExceptionAddress);
            if (code == EXCEPTION_BREAKPOINT && address == breakpoint_address) {
                HANDLE thread = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT,
                                           FALSE, event.dwThreadId);
                CONTEXT context{};
                context.ContextFlags = CONTEXT_FULL;
                if (thread && GetThreadContext(thread, &context)) {
                    reached = true;
                    std::printf("%s_REACHED thread=%lu eip=0x%08x "
                        "eax=0x%08x ebx=0x%08x ecx=0x%08x edx=0x%08x "
                        "esi=0x%08x edi=0x%08x ebp=0x%08x esp=0x%08x "
                        "eflags=0x%08x\n",
                        first_thunk ? "THUNK_ENTRY" : "CALLSITE",
                        event.dwThreadId, context.Eip, context.Eax, context.Ebx,
                        context.Ecx, context.Edx, context.Esi, context.Edi,
                        context.Ebp, context.Esp, context.EFlags);
                    std::array<std::uint32_t, 8> stack{};
                    if (read_remote(process.hProcess, context.Esp,
                                    stack.data(), sizeof(stack))) {
                        std::printf("STACK_TOP=");
                        for (auto value : stack) std::printf(" %08x", value);
                        std::printf("\n");
                        if (through_return &&
                            ((first_thunk && stack[3] == 0x400 &&
                              stack[0] == 0x0092789a) ||
                             (!first_thunk && stack[2] == 0x31c))) {
                            buffer_address = first_thunk ? stack[1] : stack[0];
                            buffer_size = first_thunk ? 0x400 : 0x31c;
                            if (first_thunk) return_site = stack[0];
                            buffer_before_read = read_remote(process.hProcess,
                                buffer_address, buffer_before.data(), buffer_size);
                            std::printf("BUFFER_BEFORE_READ=%d address=0x%08x size=0x%zx\n",
                                buffer_before_read, static_cast<unsigned>(buffer_address),
                                buffer_size);
                            if (buffer_before_read)
                                print_buffer_head("BUFFER_BEFORE_HEAD", buffer_before.data(), 64);
                            if (!first_thunk && buffer_address >= 0x438) {
                                object_address = buffer_address - 0x438;
                                object_before_read = read_remote(process.hProcess,
                                    object_address, object_before.data(), object_before.size());
                                std::printf("OBJECT_BEFORE_READ=%d address=0x%08x size=0x%zx\n",
                                    object_before_read, static_cast<unsigned>(object_address),
                                    object_before.size());
                            }
                        }
                    }
                    if (through_return) {
                        print_region(process.hProcess, "BEFORE_10000000", 0x10000000);
                        print_region(process.hProcess, "BEFORE_00401714", 0x00401714);
                        print_region(process.hProcess, "BEFORE_011E073E", kThunkEntry);
                        const bool restored = patch_byte(process.hProcess,
                            breakpoint_address, 0xcc, expected_bytes[0]);
                        const bool return_patched = restored && patch_byte(
                            process.hProcess, return_site, 0x83, 0xcc);
                        context.Eip = static_cast<DWORD>(breakpoint_address);
                        return_armed = return_patched && SetThreadContext(thread, &context);
                        std::printf("RETURN_BREAKPOINT address=0x%08x armed=%d "
                                    "entry_restored=%d\n",
                            static_cast<unsigned>(return_site), return_armed, restored);
                        if (!return_armed) stop_requested = true;
                    }
                } else {
                    std::printf("CONTEXT_FAILED error=%lu\n", GetLastError());
                }
                if (thread) CloseHandle(thread);
            } else if (code == EXCEPTION_BREAKPOINT && return_armed &&
                       address == return_site) {
                HANDLE thread = OpenThread(THREAD_GET_CONTEXT, FALSE, event.dwThreadId);
                CONTEXT context{};
                context.ContextFlags = CONTEXT_FULL;
                if (thread && GetThreadContext(thread, &context)) {
                    return_reached = true;
                    std::printf("THUNK_RETURN_REACHED thread=%lu eip=0x%08x "
                        "eax=0x%08x ebx=0x%08x ecx=0x%08x edx=0x%08x "
                        "esi=0x%08x edi=0x%08x ebp=0x%08x esp=0x%08x "
                        "eflags=0x%08x\n",
                        event.dwThreadId, context.Eip, context.Eax, context.Ebx,
                        context.Ecx, context.Edx, context.Esi, context.Edi,
                        context.Ebp, context.Esp, context.EFlags);
                    std::array<std::uint32_t, 8> stack{};
                    if (read_remote(process.hProcess, context.Esp,
                                    stack.data(), sizeof(stack))) {
                        std::printf("RETURN_STACK_TOP=");
                        for (auto value : stack) std::printf(" %08x", value);
                        std::printf("\n");
                    }
                    std::array<unsigned char, 0x400> buffer_after{};
                    if (buffer_before_read && read_remote(process.hProcess,
                            buffer_address, buffer_after.data(), buffer_size)) {
                        SIZE_T changed = 0;
                        for (SIZE_T index = 0; index < buffer_size; ++index)
                            changed += buffer_before[index] != buffer_after[index];
                        std::printf("BUFFER_CHANGED_BYTES=%zu\n", changed);
                        print_buffer_head("BUFFER_AFTER_HEAD", buffer_after.data(), 64);
                    }
                    std::array<unsigned char, 0x1100> object_after{};
                    if (object_before_read && read_remote(process.hProcess,
                            object_address, object_after.data(), object_after.size())) {
                        SIZE_T changed = 0;
                        for (SIZE_T index = 0; index < object_after.size(); ++index)
                            changed += object_before[index] != object_after[index];
                        std::printf("OBJECT_CHANGED_BYTES=%zu\n", changed);
                    }
                    print_region(process.hProcess, "AFTER_10000000", 0x10000000);
                    print_region(process.hProcess, "AFTER_00401714", 0x00401714);
                    print_region(process.hProcess, "AFTER_011E073E", kThunkEntry);
                } else {
                    std::printf("RETURN_CONTEXT_FAILED error=%lu\n", GetLastError());
                    stop_requested = true;
                }
                if (thread) CloseHandle(thread);
            } else if (code == EXCEPTION_BREAKPOINT && !initial_breakpoint) {
                initial_breakpoint = true;
                std::printf("INITIAL_BREAKPOINT address=0x%08x\n",
                            static_cast<unsigned>(address));
            } else {
                disposition = DBG_EXCEPTION_NOT_HANDLED;
                if (!info.dwFirstChance) {
                    std::printf("LAST_CHANCE_EXCEPTION code=0x%08lx "
                                "address=0x%08x\n", code,
                                static_cast<unsigned>(address));
                }
            }
        } else if (event.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT) {
            exited = true;
            exit_code = event.u.ExitProcess.dwExitCode;
            std::printf("PROCESS_EXIT code=0x%08lx\n", exit_code);
        }
        ContinueDebugEvent(event.dwProcessId, event.dwThreadId, disposition);
    }
    if (!exited) {
        std::printf("TEST_PROCESS_STOP reason=%s\n", return_reached ? "thunk_return" :
                    reached && first_thunk ? "first_thunk_entry" :
                    reached && !through_return ? "callsite" : "timeout_or_error");
        TerminateProcess(process.hProcess,
                         return_reached || (reached && !through_return) ? 0 : 1);
        WaitForSingleObject(process.hProcess, 5000);
    }
    std::printf("RESULT reached=%d return_armed=%d return_reached=%d "
                "patched=%d exited=%d events=%lu\n",
                reached, return_armed, return_reached, patched, exited, event_count);
    CloseHandle(process.hThread);
    CloseHandle(process.hProcess);
    return (through_return ? return_reached : reached) ? 0 : 1;
}
