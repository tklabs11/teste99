"""Compare the Marco 7 bitwise/address operations with the exported x86 bytes.

Values supplied below are isolated instruction fixtures, not game startup state.
The closure diagnostic separately verifies these bytes against the source PE.
"""

import json
import unittest
from pathlib import Path

from unicorn import UC_ARCH_X86, UC_MODE_32, Uc
from unicorn.x86_const import (
    UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDI,
    UC_X86_REG_ESI, UC_X86_REG_EFLAGS,
)


EXPORT = Path(r"C:\SporeAnalysis\spore_batch_all_parts\spore_batch_all_0034.json")
REGS = {"EAX": UC_X86_REG_EAX, "EBX": UC_X86_REG_EBX,
        "ECX": UC_X86_REG_ECX, "EDI": UC_X86_REG_EDI,
        "ESI": UC_X86_REG_ESI}
MASK = 0xFFFFFFFF


def original_bytes(address):
    batch = json.loads(EXPORT.read_text(encoding="utf-8"))
    function = next(record["function"] for record in batch["functions"]
                    if record["function"]["entry"] == "0x00921260")
    instruction = next(item for item in function["instructions"]
                       if int(item["address"], 16) == address)
    return bytes.fromhex(instruction["bytes"])


def run_x86(code, initial):
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(0x100000, 0x1000)
    uc.mem_write(0x100000, code)
    for name, value in initial.items():
        uc.reg_write(REGS[name], value)
    flags = 0xAD7
    uc.reg_write(UC_X86_REG_EFLAGS, flags)
    uc.emu_start(0x100000, 0x100000 + len(code))
    return {name: uc.reg_read(register) for name, register in REGS.items()}, uc.reg_read(UC_X86_REG_EFLAGS)


class EffectiveAddressDifferential(unittest.TestCase):
    def test_original_not_preserves_flags_and_complements_32_bits(self):
        for address, register in [(0x0092127D, "EDI"), (0x0092128D, "EAX")]:
            code = original_bytes(address)
            for value in [0, 1, 0x7FFFFFFF, 0x80000000, MASK]:
                with self.subTest(address=hex(address), value=hex(value)):
                    initial = {register: value}
                    result, flags = run_x86(code, initial)
                    self.assertEqual(result[register], (~value) & MASK)
                    self.assertEqual(flags & 0x8D5, 0xAD7 & 0x8D5)

    def test_not_width_fixtures_preserve_other_register_bits(self):
        # Synthetic opcode fixtures for widths absent from FUN_00921260.
        for code, width in [(bytes.fromhex("f6d0"), 8),
                            (bytes.fromhex("66f7d0"), 16)]:
            mask = (1 << width) - 1
            for value in [0, 0x12345678, MASK]:
                with self.subTest(width=width, value=hex(value)):
                    result, flags = run_x86(code, {"EAX": value})
                    expected = (value & ~mask) | ((~value) & mask)
                    self.assertEqual(result["EAX"], expected)
                    self.assertEqual(flags & 0x8D5, 0xAD7 & 0x8D5)

    def test_original_indexed_lea_wraps_without_changing_flags(self):
        cases = [
            (0x00921288, "ESI", "EBX", "EAX", -1),
            (0x009212A5, "ECX", "ESI", "EDI", 0),
        ]
        for address, dest, base, index, displacement in cases:
            code = original_bytes(address)
            for left, right in [(0, 0), (1, 2), (MASK, 2), (0x80000000, MASK)]:
                with self.subTest(address=hex(address), left=hex(left), right=hex(right)):
                    result, flags = run_x86(code, {base: left, index: right})
                    self.assertEqual(result[dest], (left + right + displacement) & MASK)
                    self.assertEqual(flags & 0x8D5, 0xAD7 & 0x8D5)


if __name__ == "__main__":
    unittest.main()
