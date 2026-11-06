#include <Windows.h>
#include <cstdint>
#include <cstdio>

static void* early_mapping = nullptr;

extern "C" void __cdecl mainCRTStartup();

extern "C" void __cdecl early_entry() {
    MEMORY_BASIC_INFORMATION region{};
    VirtualQuery(reinterpret_cast<void*>(0x00400000u), &region, sizeof(region));
    if (region.AllocationBase == reinterpret_cast<void*>(0x00400000u) &&
        region.Type == MEM_MAPPED) {
        UnmapViewOfFile(region.AllocationBase);
    }
    early_mapping = VirtualAlloc(reinterpret_cast<void*>(0x00400000u), 0x03f33000u,
                                 MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    mainCRTStartup();
}

int main() {
    MEMORY_BASIC_INFORMATION region{};
    VirtualQuery(reinterpret_cast<void*>(0x00400000u), &region, sizeof(region));
    std::printf("early_mapping=%p error=%lu occupied_base=%p state=%08lx type=%08lx\n",
                early_mapping, GetLastError(), region.AllocationBase, region.State, region.Type);
    std::uintptr_t address = 0x00400000u;
    int found = 0;
    while (address < 0x04333000u && found < 20) {
        MEMORY_BASIC_INFORMATION part{};
        if (!VirtualQuery(reinterpret_cast<void*>(address), &part, sizeof(part))) break;
        if (part.State != MEM_FREE) {
            std::printf("occupied=%p size=%zu state=%08lx type=%08lx\n",
                        part.BaseAddress, static_cast<std::size_t>(part.RegionSize),
                        part.State, part.Type);
            ++found;
        }
        const auto next = reinterpret_cast<std::uintptr_t>(part.BaseAddress) + part.RegionSize;
        if (next <= address) break;
        address = next;
    }
    return early_mapping == reinterpret_cast<void*>(0x00400000u) ? 0 : 1;
}
