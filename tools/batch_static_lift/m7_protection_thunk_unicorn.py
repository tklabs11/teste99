"""Bounded x86 execution of the original PE thunk with an explicit VirtualAlloc fixture."""

import argparse
import hashlib
import struct
from collections import deque
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_INVALID, UC_HOOK_MEM_READ
from unicorn.x86_const import (
    UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ECX,
    UC_X86_REG_EDI, UC_X86_REG_EDX, UC_X86_REG_EFLAGS, UC_X86_REG_EIP,
    UC_X86_REG_ESI, UC_X86_REG_ESP,
)

import BatchStaticLift as lifter


IMAGE_BASE = 0x00400000
ENTRY = 0x011E073E
VIRTUAL_ALLOC_IAT = 0x013CC1C8
VIRTUAL_ALLOC_STUB = 0x50000000
HEAP_BASE = 0x30000000
BUFFER_BASE = 0x20000000
STACK_BASE = 0x70000000
RETURN_SENTINEL = 0x7000F000


def u32(value):
    return struct.pack("<I", value)


def read32(uc, address):
    return struct.unpack("<I", uc.mem_read(address, 4))[0]


def run(path: Path, max_instructions: int, probe_peb: bool = False,
        probe_module: bool = False, probe_dll: Path | None = None,
        probe_ntdll: Path | None = None, probe_post_limit: int = 10000,
        probe_missing_file: bool = False, probe_second_alloc: bool = False,
        probe_after_second_alloc: bool = False,
        dump_rtl_input: Path | None = None,
        probe_rtl_output: Path | None = None,
        probe_fixed_alloc_failure: bool = False,
        probe_fallback_alloc_success: bool = False,
        probe_small_alloc_success: bool = False,
        probe_read_check: bool = False,
        probe_user32: Path | None = None):
    if probe_user32 is not None and not probe_read_check:
        raise ValueError("USER32 export probe requires read check fixture")
    if probe_read_check and not probe_small_alloc_success:
        raise ValueError("read check probe requires small allocation fixture")
    if probe_small_alloc_success and not probe_fallback_alloc_success:
        raise ValueError("small allocation probe requires fallback allocation fixture")
    if probe_fallback_alloc_success and not probe_fixed_alloc_failure:
        raise ValueError("fallback allocation probe requires fixed-address failure fixture")
    if probe_fixed_alloc_failure and probe_rtl_output is None:
        raise ValueError("fixed-address allocation probe requires RTL result fixture")
    if probe_rtl_output is not None and not probe_after_second_alloc:
        raise ValueError("RTL result fixture requires post-second-allocation probe")
    if dump_rtl_input is not None and not probe_after_second_alloc:
        raise ValueError("RTL input dump requires post-second-allocation probe")
    if probe_after_second_alloc and not probe_second_alloc:
        raise ValueError("post-second-allocation probe requires first RW allocation fixture")
    if probe_second_alloc and not probe_missing_file:
        raise ValueError("second allocation probe requires file-failure probe")
    if probe_missing_file and probe_ntdll is None:
        raise ValueError("file probe requires KERNEL32 and NTDLL export probes")
    if probe_ntdll is not None and probe_dll is None:
        raise ValueError("NTDLL probe requires the KERNEL32 probe")
    if probe_dll is not None:
        probe_peb = probe_module = True
    if probe_module and not probe_peb:
        raise ValueError("module probe requires PEB probe")
    file = path.read_bytes()
    digest = hashlib.sha256(file).hexdigest()
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE SHA-256 mismatch: {digest}")
    pe = lifter.parse_pe(path)
    if pe[1] != IMAGE_BASE:
        raise ValueError("unexpected PE image base")
    pe_header = struct.unpack_from("<I", file, 0x3C)[0]
    optional = pe_header + 24
    image_size = struct.unpack_from("<I", file, optional + 56)[0]
    header_size = struct.unpack_from("<I", file, optional + 60)[0]
    imports = lifter.parse_pe_iat_imports(pe)
    if imports.get(VIRTUAL_ALLOC_IAT) != "KERNEL32.dll!VirtualAlloc":
        raise ValueError("unexpected IAT import")
    section, _, thunk = lifter.read_pe_bytes(pe, ENTRY, 5)
    if section != ".text" or thunk != bytes.fromhex("e9d10f22ff"):
        raise ValueError("unexpected thunk bytes")

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(IMAGE_BASE, (image_size + 0xFFF) & ~0xFFF)
    uc.mem_write(IMAGE_BASE, file[:header_size])
    for _, rva, _, offset, raw_size in pe[2]:
        if not raw_size:
            continue
        if offset + raw_size > len(file) or rva + raw_size > image_size:
            raise ValueError("section exceeds PE image")
        uc.mem_write(IMAGE_BASE + rva, file[offset:offset + raw_size])
    uc.mem_map(VIRTUAL_ALLOC_STUB, 0x1000)
    uc.mem_write(VIRTUAL_ALLOC_STUB, b"\xcc")
    uc.mem_write(VIRTUAL_ALLOC_IAT, u32(VIRTUAL_ALLOC_STUB))
    uc.mem_map(HEAP_BASE, 0xC0000)
    uc.mem_map(BUFFER_BASE, 0x1000)
    uc.mem_write(BUFFER_BASE, bytes([0xA5]) * 64)
    uc.mem_map(STACK_BASE, 0x10000)
    dll_base = 0x51000000
    dll_size = 0
    dll_digest = None
    ntdll_base = 0x52000000
    ntdll_size = 0
    ntdll_digest = None
    user32_base = 0x53000000
    user32_size = 0
    user32_digest = None
    if probe_dll is not None:
        dll_file = probe_dll.read_bytes()
        dll_digest = hashlib.sha256(dll_file).hexdigest()
        dll_pe = lifter.parse_pe(probe_dll)
        dll_header = struct.unpack_from("<I", dll_file, 0x3C)[0] + 24
        dll_size = struct.unpack_from("<I", dll_file, dll_header + 56)[0]
        dll_header_size = struct.unpack_from("<I", dll_file, dll_header + 60)[0]
        uc.mem_map(dll_base, (dll_size + 0xFFF) & ~0xFFF)
        uc.mem_write(dll_base, dll_file[:dll_header_size])
        for _, rva, _, offset, raw_size in dll_pe[2]:
            if raw_size:
                uc.mem_write(dll_base + rva,
                             dll_file[offset:offset + raw_size])
    if probe_ntdll is not None:
        ntdll_file = probe_ntdll.read_bytes()
        ntdll_digest = hashlib.sha256(ntdll_file).hexdigest()
        ntdll_pe = lifter.parse_pe(probe_ntdll)
        ntdll_header = struct.unpack_from("<I", ntdll_file, 0x3C)[0] + 24
        ntdll_size = struct.unpack_from("<I", ntdll_file, ntdll_header + 56)[0]
        ntdll_header_size = struct.unpack_from("<I", ntdll_file, ntdll_header + 60)[0]
        uc.mem_map(ntdll_base, (ntdll_size + 0xFFF) & ~0xFFF)
        uc.mem_write(ntdll_base, ntdll_file[:ntdll_header_size])
        for _, rva, _, offset, raw_size in ntdll_pe[2]:
            if raw_size:
                uc.mem_write(ntdll_base + rva,
                             ntdll_file[offset:offset + raw_size])
    if probe_user32 is not None:
        user32_file = probe_user32.read_bytes()
        user32_digest = hashlib.sha256(user32_file).hexdigest()
        user32_pe = lifter.parse_pe(probe_user32)
        user32_header = struct.unpack_from("<I", user32_file, 0x3C)[0] + 24
        user32_size = struct.unpack_from("<I", user32_file, user32_header + 56)[0]
        user32_header_size = struct.unpack_from("<I", user32_file, user32_header + 60)[0]
        uc.mem_map(user32_base, (user32_size + 0xFFF) & ~0xFFF)
        uc.mem_write(user32_base, user32_file[:user32_header_size])
        for _, rva, _, offset, raw_size in user32_pe[2]:
            if raw_size:
                uc.mem_write(user32_base + rva,
                             user32_file[offset:offset + raw_size])
    if probe_second_alloc:
        uc.mem_map(0x32000000, 0x60000)
    if probe_after_second_alloc:
        uc.mem_map(0x33000000, 0x11A000)
    if probe_fallback_alloc_success:
        uc.mem_map(0x34000000, 0x85000)
    if probe_small_alloc_success:
        uc.mem_map(0x35000000, 0x1000)
    rtl_result = None
    if probe_rtl_output is not None:
        rtl_result = probe_rtl_output.read_bytes()
        if (len(rtl_result) != 0x80C00 or
                hashlib.sha256(rtl_result).hexdigest() !=
                "bfb1830574c58bea1674e3735174c52155c1af1cc134880581b294fad189dd36"):
            raise ValueError("RTL result fixture hash or size mismatch")
    if probe_peb:
        # Unicorn uses a zero FS base here. These are synthetic pointers only;
        # no Windows loader state or module list is being modeled.
        uc.mem_map(0, 0x1000)
        uc.mem_map(0x60000000, 0x4000)
        uc.mem_write(0x30, u32(0x60000000))
        uc.mem_write(0x6000000C, u32(0x60001000))
        if probe_module:
            # Deliberately synthetic, single-entry loader list for dependency
            # discovery. Its layout and contents are not a captured process.
            head = 0x60001014
            link = 0x60002008
            second = 0x60002208 if probe_ntdll is not None else head
            uc.mem_write(head, u32(link) + u32(second if probe_ntdll is not None else link))
            uc.mem_write(link, u32(second) + u32(head))
            if probe_ntdll is not None:
                uc.mem_write(second, u32(head) + u32(link))
            uc.mem_write(0x60002018,
                         u32(dll_base if probe_dll is not None else IMAGE_BASE))
            uc.mem_write(0x60002020,
                         u32(dll_size if probe_dll is not None else image_size))
            name = ("kernel32.dll" if probe_dll is not None else
                    "SporeApp.exe").encode("utf-16le")
            uc.mem_write(0x60002100, name + b"\0\0")
            for offset in (0x24, 0x2C):
                uc.mem_write(0x60002000 + offset,
                             struct.pack("<HHI", len(name), len(name) + 2,
                                         0x60002100))
            if probe_ntdll is not None:
                uc.mem_write(0x60002218, u32(ntdll_base))
                uc.mem_write(0x60002220, u32(ntdll_size))
                ntdll_name = "ntdll.dll".encode("utf-16le")
                uc.mem_write(0x60002300, ntdll_name + b"\0\0")
                for offset in (0x24, 0x2C):
                    uc.mem_write(0x60002200 + offset,
                                 struct.pack("<HHI", len(ntdll_name),
                                             len(ntdll_name) + 2, 0x60002300))
    esp = STACK_BASE + 0x8000
    buffer = BUFFER_BASE + 8
    uc.mem_write(esp, u32(RETURN_SENTINEL) + u32(buffer) + u32(0) + u32(16))
    for register, value in (
        (UC_X86_REG_EIP, ENTRY), (UC_X86_REG_ESP, esp), (UC_X86_REG_EFLAGS, 0x202),
        (UC_X86_REG_EAX, 0), (UC_X86_REG_ECX, 0), (UC_X86_REG_EDX, 0),
        (UC_X86_REG_ESI, buffer), (UC_X86_REG_EDI, 16),
    ):
        uc.reg_write(register, value)

    events = []
    recent = deque(maxlen=12)
    post_peb_trace = []
    post_peb_recent = deque(maxlen=48)
    post_peb_unique = {}
    stats = {"instructions": 0, "virtual_alloc_calls": 0, "after_peb": None,
             "probe_limit": False, "dll_entry": None, "candidate_name": None,
             "dll_reads": 0, "dll_read_sites": [], "dll_stack": None,
             "dll_wide_path": None, "dll_ascii_path": None,
             "file_stub_calls": 0,
             "second_alloc_calls": 0, "third_alloc_calls": 0,
             "rtl_result_calls": 0, "fixed_alloc_calls": 0,
             "fallback_alloc_calls": 0, "small_alloc_calls": 0,
             "read_check_calls": 0, "user32_load_calls": 0}

    def on_code(emu, address, size, _):
        stats["instructions"] += 1
        recent.append(address)
        if ((probe_dll is not None and dll_base <= address < dll_base + dll_size)
                or (probe_ntdll is not None and ntdll_base <= address < ntdll_base + ntdll_size)
                or (probe_user32 is not None and user32_base <= address < user32_base + user32_size)):
            stats["dll_entry"] = address
            stack = emu.reg_read(UC_X86_REG_ESP)
            stats["dll_stack"] = [read32(emu, stack + 4 * index)
                                  for index in range(8)]
            pointer = stats["dll_stack"][1]
            try:
                raw = bytes(emu.mem_read(pointer, 512))
                if address == 0x51032310:
                    stats["dll_ascii_path"] = raw.split(b"\0", 1)[0][:256].decode(
                        "ascii", "backslashreplace")
                chars = []
                for offset in range(0, len(raw), 2):
                    codepoint = int.from_bytes(raw[offset:offset + 2], "little")
                    if not codepoint:
                        break
                    chars.append(chr(codepoint))
                stats["dll_wide_path"] = "".join(chars)
            except UcError:
                stats["dll_wide_path"] = "unmapped"
                if address == 0x51032310:
                    stats["dll_ascii_path"] = "unmapped"
            if (probe_missing_file and address == 0x5101EA50 and
                    stats["dll_wide_path"] == "C:\\Mirc\\mirc.ini" and
                    stats["dll_stack"][2:8] ==
                    [0x80000000, 1, 0, 3, 0, 0]):
                stats["file_stub_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0xFFFFFFFF)
                emu.reg_write(UC_X86_REG_ESP, stack + 32)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_second_alloc and address == 0x510165F0 and
                    stats["dll_stack"][1:5] ==
                    [0, 0x5DD98, 0x3000, 0x4]):
                stats["second_alloc_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0x32000000)
                emu.reg_write(UC_X86_REG_ESP, stack + 20)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_after_second_alloc and address == 0x510165F0 and
                    stats["dll_stack"][1:5] ==
                    [0, 0x1198C8, 0x3000, 0x4]):
                stats["third_alloc_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0x33000000)
                emu.reg_write(UC_X86_REG_ESP, stack + 20)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (rtl_result is not None and address == 0x520F0510 and
                    stats["dll_stack"][1:6] ==
                    [0x102, 0x33000000, 0x1198C8, 0x32000000, 0x5DD98]):
                compressed = bytes(emu.mem_read(0x32000000, 0x5DD98))
                if hashlib.sha256(compressed).hexdigest() != (
                        "5ee782dd0f80d0bbce6cb8997644bdfa15ea162c3ca80edd3fb61b2ac03c1e95"):
                    raise ValueError("RTL input changed before result fixture")
                stats["rtl_result_calls"] += 1
                emu.mem_write(0x33000000, rtl_result)
                emu.mem_write(stats["dll_stack"][6], u32(len(rtl_result)))
                emu.reg_write(UC_X86_REG_EAX, 0)
                emu.reg_write(UC_X86_REG_ESP, stack + 28)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_fixed_alloc_failure and address == 0x510165F0 and
                    stats["dll_stack"][1:5] ==
                    [0x10000000, 0x85000, 0x1000, 0x4]):
                stats["fixed_alloc_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0)
                emu.reg_write(UC_X86_REG_ESP, stack + 20)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_fallback_alloc_success and address == 0x510165F0 and
                    stats["dll_stack"][1:5] ==
                    [0, 0x85000, 0x1000, 0x4]):
                stats["fallback_alloc_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0x34000000)
                emu.reg_write(UC_X86_REG_ESP, stack + 20)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_small_alloc_success and address == 0x510165F0 and
                    stats["dll_stack"][1:5] ==
                    [0, 0x14, 0x3000, 0x4]):
                stats["small_alloc_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0x35000000)
                emu.reg_write(UC_X86_REG_ESP, stack + 20)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_read_check and address == 0x5101CA70 and
                    stats["dll_stack"][1:3] == [0x340755A0, 0x14] and
                    stats["read_check_calls"] == 0):
                # The whole range belongs to the explicit readable allocation.
                emu.mem_read(0x340755A0, 0x14)
                stats["read_check_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, 0)
                emu.reg_write(UC_X86_REG_ESP, stack + 12)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            if (probe_user32 is not None and address == 0x51032310 and
                    stats["dll_ascii_path"] == "USER32.dll" and
                    stats["user32_load_calls"] == 0):
                stats["user32_load_calls"] += 1
                emu.reg_write(UC_X86_REG_EAX, user32_base)
                emu.reg_write(UC_X86_REG_ESP, stack + 8)
                emu.reg_write(UC_X86_REG_EIP, stats["dll_stack"][0])
                stats["dll_entry"] = None
                return
            emu.emu_stop()
            return
        if probe_peb and address == 0x3005F021 and stats["candidate_name"] is None:
            stack = emu.reg_read(UC_X86_REG_ESP)
            raw = bytes(emu.mem_read(stack + 0x14, 64))
            chars = []
            for offset in range(0, len(raw), 2):
                codepoint = int.from_bytes(raw[offset:offset + 2], "little")
                if codepoint == 0:
                    break
                chars.append(chr(codepoint))
            stats["candidate_name"] = "".join(chars)
        if probe_peb and address == 0x3005ED82:
            stats["after_peb"] = stats["instructions"]
        if probe_peb and stats["after_peb"] is not None and len(post_peb_trace) < 128:
            post_peb_trace.append(address)
        if probe_peb and stats["after_peb"] is not None:
            post_peb_recent.append(address)
            if len(post_peb_unique) < 256:
                post_peb_unique[address] = None
        if (probe_peb and stats["after_peb"] is not None and
                stats["instructions"] - stats["after_peb"] >= probe_post_limit):
            stats["probe_limit"] = True
            emu.emu_stop()
            return
        if address != VIRTUAL_ALLOC_STUB:
            return
        stack = emu.reg_read(UC_X86_REG_ESP)
        ret, requested, length, flags, protection = (
            read32(emu, stack + offset) for offset in (0, 4, 8, 12, 16)
        )
        stats["virtual_alloc_calls"] += 1
        events.append((ret, requested, length, flags, protection))
        if requested or length > 0xC0000 or flags != 0x3000 or protection != 0x40:
            raise ValueError("VirtualAlloc arguments differ from bounded fixture")
        emu.reg_write(UC_X86_REG_EAX, HEAP_BASE)
        emu.reg_write(UC_X86_REG_ESP, stack + 20)  # stdcall: return plus 4 arguments
        emu.reg_write(UC_X86_REG_EIP, ret)

    def on_invalid(emu, access, address, size, value, _):
        print(f"INVALID_MEMORY access={access} address=0x{address:08x} size={size} "
              f"eip=0x{emu.reg_read(UC_X86_REG_EIP):08x}")
        return False

    def on_read(emu, access, address, size, value, _):
        if ((probe_dll is not None and dll_base <= address < dll_base + dll_size)
                or (probe_ntdll is not None and ntdll_base <= address < ntdll_base + ntdll_size)
                or (probe_user32 is not None and user32_base <= address < user32_base + user32_size)):
            stats["dll_reads"] += 1
            if len(stats["dll_read_sites"]) < 16:
                stats["dll_read_sites"].append(
                    (emu.reg_read(UC_X86_REG_EIP), address, size)
                )

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_INVALID, on_invalid)
    if probe_dll is not None:
        uc.hook_add(UC_HOOK_MEM_READ, on_read)
    error = None
    try:
        uc.emu_start(ENTRY, RETURN_SENTINEL,
                     timeout=(120_000_000 if probe_after_second_alloc else
                              60_000_000 if probe_missing_file else 20_000_000),
                     count=max_instructions)
    except (UcError, ValueError) as exc:
        error = str(exc)
    print(f"PE_SHA256={digest}")
    print("EXECUTION=original x86 PE bytes in Unicorn; VirtualAlloc is a bounded fixture")
    if probe_peb:
        module_count = 2 if probe_ntdll is not None else (1 if probe_module else 0)
        print(f"PEB_PROBE=synthetic FS:0x30 and PEB.Ldr; "
              f"loader_entries={module_count}; not a Windows process reference")
    if probe_dll is not None:
        print(f"MODULE_PROBE=disk PE export data only; path={probe_dll} "
              f"sha256={dll_digest} mapped_base=0x{dll_base:08x}; "
              "execution stops before DLL code")
    if probe_ntdll is not None:
        print(f"MODULE_PROBE_NTDLL=disk PE export data only; path={probe_ntdll} "
              f"sha256={ntdll_digest} mapped_base=0x{ntdll_base:08x}")
    if probe_missing_file:
        print("FILE_PROBE=explicit fixture: CreateFileW('C:\\Mirc\\mirc.ini') "
              "returns INVALID_HANDLE_VALUE; not Windows DLL execution")
    if probe_second_alloc:
        print("SECOND_ALLOC_PROBE=explicit fixture: VirtualAlloc(0,0x5dd98,0x3000,0x4) "
              "returns 0x32000000; not Windows DLL execution")
    if probe_after_second_alloc:
        print("THIRD_ALLOC_PROBE=explicit fixture: VirtualAlloc(0,0x1198c8,0x3000,0x4) "
              "returns 0x33000000; not Windows DLL execution")
    if rtl_result is not None:
        print("RTL_RESULT_PROBE=recorded Windows x86 RtlDecompressBuffer output; "
              f"file={probe_rtl_output} sha256={hashlib.sha256(rtl_result).hexdigest()}; "
              "synthetic loader and allocation state remain")
    if probe_fixed_alloc_failure:
        print("FIXED_ALLOC_FAILURE_PROBE=explicit fixture: "
              "VirtualAlloc(0x10000000,0x85000,0x1000,0x4) returns zero")
    if probe_fallback_alloc_success:
        print("FALLBACK_ALLOC_SUCCESS_PROBE=explicit fixture: "
              "VirtualAlloc(0,0x85000,0x1000,0x4) returns 0x34000000")
    if probe_small_alloc_success:
        print("SMALL_ALLOC_SUCCESS_PROBE=explicit fixture: "
              "VirtualAlloc(0,0x14,0x3000,0x4) returns 0x35000000")
    if probe_read_check:
        print("READ_CHECK_PROBE=explicit fixture: "
              "IsBadReadPtr(0x340755a0,0x14) returns zero for mapped readable range")
    if probe_user32 is not None:
        print(f"USER32_LOAD_PROBE=explicit fixture: LoadLibraryA('USER32.dll') "
              f"returns 0x{user32_base:08x}; image={probe_user32} "
              f"sha256={user32_digest}; export data only")
    for ret, requested, length, flags, protection in events:
        print(f"VIRTUALALLOC ret=0x{ret:08x} address=0x{requested:08x} "
              f"size=0x{length:x} flags=0x{flags:x} protect=0x{protection:x}")
    print(f"INSTRUCTIONS={stats['instructions']} VIRTUALALLOC_CALLS={stats['virtual_alloc_calls']}")
    if probe_peb:
        print(f"PEB_PROBE_REACHED={stats['after_peb'] is not None} "
              f"PROBE_LIMIT={stats['probe_limit']} "
              f"POST_PEB_INSTRUCTIONS={stats['instructions'] - stats['after_peb'] if stats['after_peb'] is not None else 0}")
        if probe_dll is not None:
            print(f"MODULE_PROBE_DLL_ENTRY={('0x%08x' % stats['dll_entry']) if stats['dll_entry'] is not None else 'none'}")
            if stats["dll_stack"] is not None:
                print("MODULE_PROBE_CALL_STACK=" + ",".join(
                    f"0x{value:08x}" for value in stats["dll_stack"]
                ))
                print(f"MODULE_PROBE_WIDE_PATH={stats['dll_wide_path']!r}")
            if stats["dll_ascii_path"] is not None:
                print(f"MODULE_PROBE_ASCII_PATH={stats['dll_ascii_path']!r}")
            if probe_missing_file:
                print(f"FILE_PROBE_STUB_CALLS={stats['file_stub_calls']}")
            if probe_second_alloc:
                print(f"SECOND_ALLOC_PROBE_STUB_CALLS={stats['second_alloc_calls']}")
            if probe_after_second_alloc:
                print(f"THIRD_ALLOC_PROBE_STUB_CALLS={stats['third_alloc_calls']}")
            if rtl_result is not None:
                print(f"RTL_RESULT_PROBE_STUB_CALLS={stats['rtl_result_calls']}")
            if probe_fixed_alloc_failure:
                print(f"FIXED_ALLOC_FAILURE_STUB_CALLS={stats['fixed_alloc_calls']}")
            if probe_fallback_alloc_success:
                print(f"FALLBACK_ALLOC_SUCCESS_STUB_CALLS={stats['fallback_alloc_calls']}")
            if probe_small_alloc_success:
                print(f"SMALL_ALLOC_SUCCESS_STUB_CALLS={stats['small_alloc_calls']}")
            if probe_read_check:
                print(f"READ_CHECK_STUB_CALLS={stats['read_check_calls']}")
            if probe_user32 is not None:
                print(f"USER32_LOAD_STUB_CALLS={stats['user32_load_calls']}")
            print(f"MODULE_PROBE_DLL_READS={stats['dll_reads']} " + ",".join(
                f"0x{site:08x}->0x{address:08x}:{size}"
                for site, address, size in stats["dll_read_sites"]
            ))
        print(f"PEB_PROBE_CANDIDATE_NAME={stats['candidate_name']!r}")
        print("PEB_PROBE_TRACE=" + ",".join(f"0x{address:08x}" for address in post_peb_trace))
        print("PEB_PROBE_TAIL=" + ",".join(f"0x{address:08x}" for address in post_peb_recent))
        disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
        for address in dict.fromkeys(post_peb_trace[:40]):
            decoded = next(disassembler.disasm(
                bytes(uc.mem_read(address, 15)), address, count=1
            ), None)
            if decoded:
                print(f"PEB_PROBE_DISASM 0x{address:08x} "
                      f"{decoded.mnemonic} {decoded.op_str}")
        for address in dict.fromkeys(post_peb_recent):
            decoded = next(disassembler.disasm(
                bytes(uc.mem_read(address, 15)), address, count=1
            ), None)
            if decoded:
                print(f"PEB_PROBE_TAIL_DISASM 0x{address:08x} "
                      f"{decoded.mnemonic} {decoded.op_str}")
        for address in post_peb_unique:
            decoded = next(disassembler.disasm(
                bytes(uc.mem_read(address, 15)), address, count=1
            ), None)
            if decoded:
                print(f"PEB_PROBE_FLOW_DISASM 0x{address:08x} "
                      f"{decoded.mnemonic} {decoded.op_str}")
    print(f"FINAL_EIP=0x{uc.reg_read(UC_X86_REG_EIP):08x} "
          f"EAX=0x{uc.reg_read(UC_X86_REG_EAX):08x} "
          f"ESP=0x{uc.reg_read(UC_X86_REG_ESP):08x} ERROR={error or 'none'}")
    if probe_after_second_alloc and stats["dll_entry"] == 0x520F0510:
        call = stats["dll_stack"]
        if call is None or call[1:6] != [0x102, 0x33000000, 0x1198C8,
                                         0x32000000, 0x5DD98]:
            raise ValueError("RtlDecompressBuffer call differs from bounded probe")
        compressed = bytes(uc.mem_read(0x32000000, 0x5DD98))
        print("RTL_DECOMPRESS_ARGS=format:0x102 output:0x33000000 "
              "output_size:0x1198c8 input:0x32000000 input_size:0x5dd98 "
              f"final_size_ptr:0x{call[6]:08x}")
        print(f"RTL_COMPRESSED_SHA256={hashlib.sha256(compressed).hexdigest()} "
              f"nonzero_bytes={sum(byte != 0 for byte in compressed)} "
              f"head={compressed[:32].hex()}")
        if dump_rtl_input is not None:
            dump_rtl_input.parent.mkdir(parents=True, exist_ok=True)
            with dump_rtl_input.open("xb") as output:
                output.write(compressed)
            print(f"RTL_COMPRESSED_DUMP={dump_rtl_input}")
    print("REGISTERS=" + " ".join(
        f"{name}:0x{uc.reg_read(register):08x}" for name, register in (
            ("EAX", UC_X86_REG_EAX), ("EBX", UC_X86_REG_EBX),
            ("ECX", UC_X86_REG_ECX), ("EDX", UC_X86_REG_EDX),
            ("ESI", UC_X86_REG_ESI), ("EDI", UC_X86_REG_EDI),
            ("EBP", UC_X86_REG_EBP), ("ESP", UC_X86_REG_ESP))))
    final_eip = uc.reg_read(UC_X86_REG_EIP)
    if HEAP_BASE <= final_eip < HEAP_BASE + 0xC0000:
        for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(
            bytes(uc.mem_read(final_eip, 24)), final_eip, count=4
        ):
            print(f"DISASM 0x{instruction.address:08x} {instruction.mnemonic} {instruction.op_str}")
        if final_eip == 0x3005ED82:
            print("NEXT_BYTES=" + bytes(uc.mem_read(0x3005FEFE, 96)).hex())
            for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(
                bytes(uc.mem_read(0x3005FEFE, 96)), 0x3005FEFE, count=18
            ):
                print(f"NEXT 0x{instruction.address:08x} {instruction.mnemonic} {instruction.op_str}")
    print("RECENT_EIP=" + ",".join(f"0x{a:08x}" for a in recent))
    print("BUFFER=" + bytes(uc.mem_read(BUFFER_BASE, 64)).hex())
    print("ALLOCATED_CODE_HEAD=" + bytes(uc.mem_read(HEAP_BASE, 32)).hex())
    return 0 if not error and uc.reg_read(UC_X86_REG_EIP) == RETURN_SENTINEL else 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--max-instructions", type=int, default=1_000_000)
    parser.add_argument("--probe-peb", action="store_true")
    parser.add_argument("--probe-module", action="store_true")
    parser.add_argument("--probe-dll", type=Path)
    parser.add_argument("--probe-ntdll", type=Path)
    parser.add_argument("--probe-post-limit", type=int, default=10000)
    parser.add_argument("--probe-missing-file", action="store_true")
    parser.add_argument("--probe-second-alloc", action="store_true")
    parser.add_argument("--probe-after-second-alloc", action="store_true")
    parser.add_argument("--dump-rtl-input", type=Path)
    parser.add_argument("--probe-rtl-output", type=Path)
    parser.add_argument("--probe-fixed-alloc-failure", action="store_true")
    parser.add_argument("--probe-fallback-alloc-success", action="store_true")
    parser.add_argument("--probe-small-alloc-success", action="store_true")
    parser.add_argument("--probe-read-check", action="store_true")
    parser.add_argument("--probe-user32", type=Path)
    args = parser.parse_args()
    raise SystemExit(run(args.exe, args.max_instructions, args.probe_peb,
                         args.probe_module, args.probe_dll, args.probe_ntdll,
                         args.probe_post_limit, args.probe_missing_file,
                         args.probe_second_alloc, args.probe_after_second_alloc,
                         args.dump_rtl_input, args.probe_rtl_output,
                         args.probe_fixed_alloc_failure,
                         args.probe_fallback_alloc_success,
                         args.probe_small_alloc_success,
                         args.probe_read_check, args.probe_user32))
