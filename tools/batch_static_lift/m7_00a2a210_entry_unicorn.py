"""Execute original x86 bytes of the FUN_00a2a210 entry fixture."""

import argparse
import hashlib
import struct
from pathlib import Path

from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_32
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_INVALID
from unicorn.x86_const import (
    UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX, UC_X86_REG_ECX,
    UC_X86_REG_EDI, UC_X86_REG_EDX, UC_X86_REG_EFLAGS, UC_X86_REG_EIP,
    UC_X86_REG_ESI, UC_X86_REG_ESP,
)

import BatchStaticLift as lifter
import generate_call_closure as closure


ENTRY = 0x00A2A210
STOP = 0x00A2A24E
OBJECT = 0x20000000
ESP = 0x70000200


def u32(value):
    return struct.pack("<I", value)


def run(exe: Path, batch: Path):
    image = exe.read_bytes()
    digest = hashlib.sha256(image).hexdigest()
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE SHA-256 mismatch: {digest}")
    pe = lifter.parse_pe(exe)
    function = closure.load_exported_functions([batch], digest)[ENTRY]
    verified = lifter.validate_function_bytes(function, pe)
    allowed = {int(item["address"], 16) for item in verified
               if int(item["address"], 16) < STOP}
    header = struct.unpack_from("<I", image, 0x3C)[0] + 24
    image_size = struct.unpack_from("<I", image, header + 56)[0]
    header_size = struct.unpack_from("<I", image, header + 60)[0]
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(pe[1], (image_size + 0xFFF) & ~0xFFF)
    uc.mem_write(pe[1], image[:header_size])
    for _, rva, _, offset, raw_size in pe[2]:
        if raw_size:
            uc.mem_write(pe[1] + rva, image[offset:offset + raw_size])
    uc.mem_map(0, 0x1000)  # synthetic FS base zero for this harness only
    uc.mem_write(0, u32(0xFFFFFFFF))
    uc.mem_map(OBJECT, 0x1000)
    uc.mem_write(OBJECT + 0x20, u32(0xABCDEF01))
    uc.mem_map(0x70000000, 0x1000)
    uc.mem_write(ESP, u32(0xF00DCAFE))
    for register, value in (
        (UC_X86_REG_EAX, 0x87654321), (UC_X86_REG_ECX, OBJECT),
        (UC_X86_REG_EDX, 0x12345678), (UC_X86_REG_EBX, 0x11223344),
        (UC_X86_REG_ESP, ESP), (UC_X86_REG_EBP, 0x55667788),
        (UC_X86_REG_ESI, 0x99AABBCC), (UC_X86_REG_EDI, 0xDDEEFF00),
        (UC_X86_REG_EFLAGS, 0x202), (UC_X86_REG_EIP, ENTRY),
    ):
        uc.reg_write(register, value)
    state = {"count": 0, "reached": False, "error": None}

    def on_code(emu, address, size, _):
        if address == STOP:
            state["reached"] = True
            emu.emu_stop()
        elif address not in allowed:
            state["error"] = f"unverified instruction 0x{address:08x}"
            emu.emu_stop()
        else:
            state["count"] += 1

    def on_invalid(emu, access, address, size, value, _):
        state["error"] = (f"invalid memory access={access} address=0x{address:08x} "
                          f"eip=0x{emu.reg_read(UC_X86_REG_EIP):08x}")
        return False

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_INVALID, on_invalid)
    try:
        uc.emu_start(ENTRY, 0xF00DCAFE, count=1000)
    except UcError as error:
        state["error"] = state["error"] or str(error)
    regs = [uc.reg_read(register) for register in (
        UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_EBX,
        UC_X86_REG_ESP, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI,
    )]
    stack = bytes(uc.mem_read(regs[4], 64)).hex()
    print(f"PE_SHA256={digest} EXECUTION=original_x86_bytes_in_Unicorn "
          "fixture=isolated_synthetic_FS")
    print(f"instructions={state['count']}")
    print(f"kind=original_x86 boundary={STOP:08x} eax={regs[0]:08x} "
          f"ecx={regs[1]:08x} edx={regs[2]:08x} ebx={regs[3]:08x} "
          f"esp_delta={regs[4] - ESP} ebp={regs[5]:08x} "
          f"esi={regs[6]:08x} edi={regs[7]:08x} "
          f"flags={uc.reg_read(UC_X86_REG_EFLAGS) & 0x8D5:08x} "
          f"fs_head={struct.unpack('<I', uc.mem_read(0, 4))[0]:08x} "
          f"stack={stack}")
    print(f"boundary_reached={state['reached']} "
          f"final_eip=0x{uc.reg_read(UC_X86_REG_EIP):08x} "
          f"error={state['error'] or 'none'}")
    return 0 if state["reached"] and not state["error"] else 1


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, type=Path)
    args = parser.parse_args()
    raise SystemExit(run(args.exe, args.batch))
