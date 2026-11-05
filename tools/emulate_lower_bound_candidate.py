#!/usr/bin/env python3

import argparse
import json
import random
import struct
from pathlib import Path

import pefile
from unicorn import UC_ARCH_X86, UC_MODE_32, Uc, UC_HOOK_CODE


IMAGE_BASE = 0x00400000
FUNCTION_RVA = 0x22430
FUNCTION_VA = IMAGE_BASE + FUNCTION_RVA
FUNCTION_SIZE = 122
RETURN_VA = 0x00500000
STACK_TOP = 0x00100000
STACK_SIZE = 0x00100000
DATA_VA = 0x00200000


def lower_bound_python(records, key):
    low = 0
    high = len(records)
    while low < high:
        middle = low + ((high - low) >> 1)
        if records[middle][0] < key:
            low = middle + 1
        else:
            high = middle
    return low


def emulate_once(uc, function_bytes, records, key):
    records_start = DATA_VA + 0x1000
    records_end = records_start + len(records) * 12
    key_address = DATA_VA + 0x8000

    uc.mem_write(records_start, b"".join(
        struct.pack("<III", record[0], record[1], record[2])
        for record in records
    ))
    uc.mem_write(key_address, struct.pack("<I", key & 0xFFFFFFFF))

    uc.reg_write(__import__("unicorn.x86_const").x86_const.UC_X86_REG_ESP, STACK_TOP - 4)
    uc.mem_write(STACK_TOP - 4, struct.pack("<I", RETURN_VA))
    uc.mem_write(STACK_TOP, struct.pack("<IIII",
        records_start, records_end, key_address, 0))

    uc.reg_write(__import__("unicorn.x86_const").x86_const.UC_X86_REG_EBP, 0)
    uc.emu_start(FUNCTION_VA, RETURN_VA, timeout=1_000_000, count=5000)
    eax = uc.reg_read(__import__("unicorn.x86_const").x86_const.UC_X86_REG_EAX)
    return eax, (eax - records_start) // 12 if records_start <= eax <= records_end else -1


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("pe", type=Path)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()

    pe = pefile.PE(str(args.pe.resolve()), fast_load=False)
    function_bytes = pe.get_data(FUNCTION_RVA, FUNCTION_SIZE)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(IMAGE_BASE, 0x02000000)
    uc.mem_map(DATA_VA, 0x10000)
    uc.mem_map(STACK_TOP - STACK_SIZE, STACK_SIZE + 0x1000)
    uc.mem_write(FUNCTION_VA, function_bytes)
    uc.mem_write(RETURN_VA, b"\xc3\x90")

    cases = []
    vectors = [
        ([], 0x00000000),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0x00000000),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0xFFFFFFFF),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0xFFFFFFFE),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0x00000007),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0x00000008),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0x00000018),
        ([0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF], 0xFFFFFFFF),
    ]
    duplicate_vectors = [
        ([0, 0, 1, 1, 1, 2, 2, 3], key)
        for key in (0, 1, 2, 3, 4, 0xFFFFFFFF)
    ]
    vectors.extend(duplicate_vectors)
    rng = random.Random(0x5A17)
    for _ in range(128):
        count = rng.choice((1, 2, 3, 8, 31, 64, 127, 256))
        if rng.random() < 0.25:
            values = [rng.choice((0, 1, 2, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF))
                      for _ in range(count)]
            values.sort()
        else:
            values = sorted(rng.sample(range(0x00000000, 0x00100000), count))
        vectors.append((values, rng.choice([
            values[0] - 1 if values[0] > 0 else 0,
            values[-1] + 1 if values[-1] < 0xFFFFFFFF else 0xFFFFFFFF,
            rng.randint(0, 0x0000FFFF),
            rng.choice(values),
        ])))

    failed = 0
    for keys, key in vectors:
        records = [(value, index * 10, index * 20) for index, value in enumerate(keys)]
        eax, emulated_index = emulate_once(uc, function_bytes, records, key)
        python_index = lower_bound_python(records, key)
        passed = emulated_index == python_index
        failed += not passed
        cases.append({
            "key": f"0x{key:08X}",
            "record_count": len(records),
            "eax": f"0x{eax:08X}",
            "emulated_index": emulated_index,
            "python_index": python_index,
            "passed": passed,
        })

        uc.reg_write(__import__("unicorn.x86_const").x86_const.UC_X86_REG_ESP, STACK_TOP - 4)

    report = {
        "executable": str(args.pe.resolve()),
        "sha256": __import__("hashlib").sha256(args.pe.read_bytes()).hexdigest(),
        "function_rva": "0x22430",
        "function_va": "0x422430",
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
