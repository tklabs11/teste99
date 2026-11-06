"""Execute verified original x86 bytes to the FUN_00a23570 call boundary."""

import argparse
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path

from unicorn import Uc, UcError, UC_ARCH_X86, UC_HOOK_CODE, UC_HOOK_MEM_INVALID, UC_MODE_32
from unicorn.x86_const import (
    UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ECX,
    UC_X86_REG_EDI, UC_X86_REG_EDX, UC_X86_REG_EFLAGS, UC_X86_REG_EIP,
    UC_X86_REG_ESI, UC_X86_REG_ESP, UC_X86_REG_FPCW, UC_X86_REG_MXCSR,
)

import BatchStaticLift as lifter
import generate_call_closure as closure


ENTRIES = (0x00921260, 0x00921300, 0x00921360, 0x00A23570)
BOUNDARY = 0x00A2360D
ALLOCATOR = 0x00A221B0
ALLOCATOR_BOUNDARY = 0x00A221FC
OTHER_MISSING_CALL = 0x00A221E9
OBJECT = 0x20000000
INPUT = 0x20010000
BUFFER = 0x20010100
STACK = 0x70000000
ESP = 0x70000200


def u32(value):
    return struct.pack("<I", value)


def run(exe: Path, batches: list[Path], through_allocator: bool = False):
    boundary = ALLOCATOR_BOUNDARY if through_allocator else BOUNDARY
    image = exe.read_bytes()
    digest = hashlib.sha256(image).hexdigest()
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE hash mismatch: {digest}")
    pe = lifter.parse_pe(exe)
    exports = closure.load_exported_functions(batches, digest)
    allowed = set()
    owner = {}
    for entry in (*ENTRIES, *((ALLOCATOR,) if through_allocator else ())):
        function = exports[entry]
        lifter.validate_function_bytes(function, pe)
        for item in function["instructions"]:
            address = int(item["address"], 16)
            allowed.add(address)
            owner[address] = entry
    pe_offset = struct.unpack_from("<I", image, 0x3C)[0]
    optional = pe_offset + 24
    image_size = struct.unpack_from("<I", image, optional + 56)[0]
    header_size = struct.unpack_from("<I", image, optional + 60)[0]
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(pe[1], (image_size + 0xFFF) & ~0xFFF)
    uc.mem_write(pe[1], image[:header_size])
    for _, rva, _, offset, raw_size in pe[2]:
        if raw_size:
            uc.mem_write(pe[1] + rva, image[offset:offset + raw_size])
    uc.mem_map(OBJECT, 0x20000)
    uc.mem_write(INPUT, u32(BUFFER))
    uc.mem_write(INPUT + 0x14, u32(0x12345678))
    uc.mem_map(STACK, 0x4000)
    uc.mem_write(ESP, u32(0xF00DCAFE) + u32(2) + u32(0) * 5 + u32(INPUT))
    for register, value in (
        (UC_X86_REG_EAX, 0x87654321), (UC_X86_REG_ECX, OBJECT),
        (UC_X86_REG_EDX, 0x12345678), (UC_X86_REG_EBX, 0x11223344),
        (UC_X86_REG_ESP, ESP), (UC_X86_REG_EBP, 0x55667788),
        (UC_X86_REG_ESI, 0x99AABBCC), (UC_X86_REG_EDI, 0xDDEEFF00),
        (UC_X86_REG_EFLAGS, 0x202), (UC_X86_REG_EIP, 0x00A23570),
        (UC_X86_REG_FPCW, 0x027F), (UC_X86_REG_MXCSR, 0x1F80),
    ):
        uc.reg_write(register, value)
    state = {"count": 0, "boundary": False, "error": None}
    executed = Counter()

    def on_code(emu, address, size, _):
        if address == boundary:
            state["boundary"] = True
            emu.emu_stop()
            return
        if through_allocator and address == OTHER_MISSING_CALL:
            state["error"] = "conditional missing call 0x00a221e9 reached"
            emu.emu_stop()
            return
        if address not in allowed:
            state["error"] = f"unverified instruction 0x{address:08x}"
            emu.emu_stop()
            return
        state["count"] += 1
        executed[owner[address]] += 1

    def on_invalid(emu, access, address, size, value, _):
        state["error"] = (f"invalid memory access={access} address=0x{address:08x} "
                          f"at=0x{emu.reg_read(UC_X86_REG_EIP):08x}")
        return False

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_INVALID, on_invalid)
    try:
        uc.emu_start(0x00A23570, 0xF00DCAFE, timeout=10_000_000, count=100_000)
    except UcError as error:
        state["error"] = state["error"] or str(error)
    regs = [uc.reg_read(register) for register in (
        UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBX,
        UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI,
    )]
    fields = [struct.unpack("<I", uc.mem_read(OBJECT + offset, 4))[0]
              for offset in range(0, 0x38, 4)]
    buffer = bytes(uc.mem_read(BUFFER, 32)).hex()
    print(f"PE_SHA256={digest} EXECUTION=original_x86_bytes_in_Unicorn")
    print(f"instructions={state['count']} executed_functions=" +
          ",".join(f"0x{entry:08x}:{executed[entry]}" for entry in sorted(executed)))
    print(f"kind=original_x86 boundary={boundary:08x} "
          f"eax={regs[0]:08x} ecx={regs[1]:08x} edx={regs[2]:08x} "
          f"ebx={regs[3]:08x} esp_delta={regs[4] - ESP} "
          f"ebp={regs[5]:08x} esi={regs[6]:08x} edi={regs[7]:08x} "
          f"flags={uc.reg_read(UC_X86_REG_EFLAGS) & 0x8D5:08x} fields=" +
          ",".join(f"{value:08x}" for value in fields) + f" buffer={buffer}")
    print(f"boundary_reached={state['boundary']} final_eip=0x{uc.reg_read(UC_X86_REG_EIP):08x} "
          f"error={state['error'] or 'none'}")
    return 0 if state["boundary"] and not state["error"] else 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, action="append", type=Path)
    parser.add_argument("--through-allocator", action="store_true")
    args = parser.parse_args()
    raise SystemExit(run(args.exe, args.batch, args.through_allocator))
