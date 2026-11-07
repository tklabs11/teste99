#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <cstdio>

int main() {
    constexpr SIZE_T allocation_size = 0x85000;
    constexpr SIZE_T offset = 0x755a0;
    constexpr UINT_PTR read_size = 0x14;
    auto* allocation = static_cast<unsigned char*>(
        VirtualAlloc(nullptr, allocation_size, MEM_RESERVE | MEM_COMMIT,
                     PAGE_READWRITE));
    if (allocation == nullptr) {
        std::printf("ALLOC_FAILED error=%lu\n", GetLastError());
        return 1;
    }
    const BOOL result = IsBadReadPtr(allocation + offset, read_size);
    std::printf("WIN32_X86_ISBADREADPTR offset=0x%zx size=0x%zx result=%d\n",
                offset, static_cast<SIZE_T>(read_size), result);
    const HMODULE user32 = LoadLibraryA("USER32.dll");
    std::printf("WIN32_X86_LOADLIBRARYA name=USER32.dll success=%d\n",
                user32 != nullptr);
    if (user32 != nullptr) {
        FreeLibrary(user32);
    }
    const BOOL released = VirtualFree(allocation, 0, MEM_RELEASE);
    return result == 0 && user32 != nullptr && released ? 0 : 1;
}
