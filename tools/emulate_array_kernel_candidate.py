#!/usr/bin/env python3

import argparse
import json
import random
import struct
from pathlib import Path

import pefile
from unicorn import UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE, Uc
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_ESP


IMAGE_BASE = 0x00400000
FUNCTION_RVA = 0xD58BE0
FUNCTION_VA = IMAGE_BASE + FUNCTION_RVA
FUNCTION_SIZE = 125
RETURN_VA = 0x00500000
STACK_TOP = 0x00100000
STACK_SIZE = 0x00100000
DATA_VA = 0x00200000


def f32(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]


def python_kernel(count, scalar, source, destination):
    scalar = f32(scalar)
    output = list(destination)
    for index in range(count):
        output[index] = f32(float(f32(scalar * f32(source[index]) + f32(destination[index]))))
    return output


def pack_floats(values):
    return struct.pack("<" + "f" * len(values), *values)


def float_bits(value):
    return struct.unpack("<I", struct.pack("<f", value))[0]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("pe", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()

    pe = pefile.PE(str(args.pe.resolve()), fast_load=False)
    function_bytes = pe.get_data(FUNCTION_RVA, FUNCTION_SIZE)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(IMAGE_BASE, 0x02000000)
    uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE + 0x1000)
    uc.mem_map(DATA_VA, 0x10000)
    uc.mem_write(FUNCTION_VA, function_bytes)
    uc.mem_write(RETURN_VA, b"\xc3\x90")

    rng = random.Random(0xA77A)
    vectors = []
    for count in (0, 1, 3, 4, 5, 7, 9, 16, 64, 257):
        source = [f32(rng.uniform(-4, 4)) for _ in range(count)]
        destination = [f32(rng.uniform(-4, 4)) for _ in range(count)]
        vectors.append((count, f32(rng.uniform(-2, 2)), source, destination))

    edge_values = [
        0.0, -0.0, float.fromhex("0x1p-149"), float.fromhex("-0x1p-149"),
        float.fromhex("0x1.fffffep127"), float.fromhex("-0x1.fffffep127"),
        float("inf"), float("-inf"), float("nan"),
    ]
    for count in (4, 17, 64):
        source = [edge_values[index % len(edge_values)] for index in range(count)]
        destination = [edge_values[(index * 3 + 1) % len(edge_values)] for index in range(count)]
        vectors.append((count, edge_values[count % len(edge_values)], source, destination))

    cases = []
    failed = 0
    for count, scalar, source, destination in vectors:
        source_address = DATA_VA + 0x1000
        destination_address = DATA_VA + 0x4000
        scalar_address = DATA_VA + 0x8000
        uc.mem_write(source_address, pack_floats(source))
        uc.mem_write(destination_address, pack_floats(destination))
        uc.mem_write(scalar_address, struct.pack("<f", scalar))

        uc.reg_write(UC_X86_REG_ESP, STACK_TOP - 4)
        uc.reg_write(UC_X86_REG_EBP, 0)
        uc.mem_write(STACK_TOP - 4, struct.pack("<I", RETURN_VA))
        uc.mem_write(STACK_TOP, struct.pack("<IfII",
            count, scalar, source_address, destination_address))

        uc.emu_start(FUNCTION_VA, RETURN_VA, timeout=1_000_000, count=10000)
        actual = list(struct.unpack("<" + "f" * count,
            uc.mem_read(destination_address, count * 4))) if count else []
        expected = python_kernel(count, scalar, source, destination)
        exact = (
            len(actual) == len(expected)
            and all(float_bits(actual_value) == float_bits(expected_value)
                    for actual_value, expected_value in zip(actual, expected))
        )
        failed += not exact
        cases.append({
            "count": count,
            "scalar": f"0x{struct.unpack('<I', struct.pack('<f', scalar))[0]:08X}",
            "actual": [f"0x{struct.unpack('<I', struct.pack('<f', value))[0]:08X}" for value in actual],
            "expected": [f"0x{struct.unpack('<I', struct.pack('<f', value))[0]:08X}" for value in expected],
            "passed": exact,
        })

    report = {
        "executable": str(args.pe.resolve()),
        "sha256": __import__("hashlib").sha256(args.pe.read_bytes()).hexdigest(),
        "function_rva": "0xD58BE0",
        "function_va": "0x1158BE0",
        "function_size": FUNCTION_SIZE,
        "function_bytes_sha256": __import__("hashlib").sha256(function_bytes).hexdigest(),
        "cases": cases,
        "failed": failed,
    }
    rendered = json.dumps(report, indent=2) + "\n"
    print(rendered)
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(rendered, encoding="utf-8")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
