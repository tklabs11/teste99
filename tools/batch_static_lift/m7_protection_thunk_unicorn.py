"""Bounded x86 execution of the original PE thunk with an explicit VirtualAlloc fixture."""

import argparse
import hashlib
import struct
from collections import deque
from pathlib import Path

from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_INVALID
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


def run(path: Path, max_instructions: int):
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
    stats = {"instructions": 0, "virtual_alloc_calls": 0}

    def on_code(emu, address, size, _):
        stats["instructions"] += 1
        recent.append(address)
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

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_INVALID, on_invalid)
    error = None
    try:
        uc.emu_start(ENTRY, RETURN_SENTINEL, timeout=20_000_000,
                     count=max_instructions)
    except (UcError, ValueError) as exc:
        error = str(exc)
    print(f"PE_SHA256={digest}")
    print("EXECUTION=original x86 PE bytes in Unicorn; VirtualAlloc is a bounded fixture")
    for ret, requested, length, flags, protection in events:
        print(f"VIRTUALALLOC ret=0x{ret:08x} address=0x{requested:08x} "
              f"size=0x{length:x} flags=0x{flags:x} protect=0x{protection:x}")
    print(f"INSTRUCTIONS={stats['instructions']} VIRTUALALLOC_CALLS={stats['virtual_alloc_calls']}")
    print(f"FINAL_EIP=0x{uc.reg_read(UC_X86_REG_EIP):08x} "
          f"EAX=0x{uc.reg_read(UC_X86_REG_EAX):08x} "
          f"ESP=0x{uc.reg_read(UC_X86_REG_ESP):08x} ERROR={error or 'none'}")
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
    args = parser.parse_args()
    raise SystemExit(run(args.exe, args.max_instructions))
