#!/usr/bin/env python3

import json
import subprocess
import struct
from pathlib import Path


ADB = Path.home() / "AppData" / "Local" / "Android" / "Sdk" / "platform-tools" / "adb.exe"
REMOTE = "/data/local/tmp"


def adb_shell(binary):
    result = subprocess.run(
        [str(ADB), "shell", f"unset LD_PRELOAD; {REMOTE}/{binary}"],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip().splitlines()


def lower_bound_python(values, key):
    low = 0
    high = len(values)
    while low < high:
        middle = low + ((high - low) >> 1)
        if values[middle][0] < key:
            low = middle + 1
        else:
            high = middle
    return low


def checksum_floats():
    values = [1.0, -2.0, 0.25, 8.0, 3.5, -0.125, 2.0, 0.0]
    source = [0.5, 2.0, -4.0, 0.125, -3.0, 7.0, 0.75, -9.0]
    scalar = 1.25
    result = 0x811C9DC5
    for index in range(len(values)):
        value = struct.unpack("<f", struct.pack("<f", values[index] + scalar * source[index]))[0]
        bits = struct.unpack("<I", struct.pack("<f", value))[0]
        result = ((result ^ bits) * 0x01000193) & 0xFFFFFFFF
    return result


def main():
    values = [0x00000000, 0x00000008, 0x00000010, 0x00000020, 0xFFFFFFFF]
    records = [(value, index * 10, index * 20) for index, value in enumerate(values)]
    lower_lines = adb_shell("lifted_lower_bound_arm64")
    lower_cases = []
    lower_failed = 0

    for line in lower_lines:
        if not line.startswith("lower_bound_"):
            continue
        _, rendered = line.rsplit("lower_bound_", 1)
        key_text, index_text = rendered.split("=")
        key = int(key_text, 16)
        actual = int(index_text)
        expected = lower_bound_python(records, key)
        passed = actual == expected
        lower_failed += not passed
        lower_cases.append({
            "key": f"0x{key:08X}",
            "actual_index": actual,
            "expected_index": expected,
            "passed": passed,
        })

    array_lines = adb_shell("lifted_array_kernel_arm64")
    array_checksum = next(
        line.rsplit("=", 1)[1].upper()
        for line in array_lines
        if line.startswith("array_multiply_add=")
    )
    expected_checksum = f"{checksum_floats():08X}"

    report = {
        "device_abi": subprocess.run(
            [str(ADB), "shell", "getprop", "ro.product.cpu.abi"],
            check=True,
            capture_output=True,
            text=True,
        ).stdout.strip(),
        "lower_bound": {
            "cases": lower_cases,
            "failed": lower_failed,
        },
        "array_kernel": {
            "actual_checksum": array_checksum,
            "expected_checksum": expected_checksum,
            "passed": array_checksum == expected_checksum,
        },
    }

    output = Path(__file__).with_name("arm64-physical-validation.json")
    output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2))
    return 1 if lower_failed or not report["array_kernel"]["passed"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
