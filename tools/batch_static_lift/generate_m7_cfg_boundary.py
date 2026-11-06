"""Generate the byte-verified FUN_00a23570 path stopping before 00a221b0."""

import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as closure


ROOT = 0x00A23570
STOP = 0x00A2360D
ALLOCATOR = 0x00A221B0
ALLOCATOR_STOPS = {0x00A221E9, 0x00A221FC}
CHILDREN = (0x00921260, 0x00921300, 0x00921360)
DATA = (
    ("kM7CfgInitialFloat", 0x01485718, 4),
    ("kM7CfgScaleFloat", 0x01470F14, 4),
    ("kM7CfgLookupTable", 0x0143D850, 0x404),
    ("kM7CfgCorrection", 0x013F4FD0, 4),
)


def generate(exe: Path, batches: list[Path], output: Path,
             through_allocator: bool = False):
    digest = lifter.sha256_file(exe)
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE hash mismatch: {digest}")
    exported = closure.load_exported_functions(batches, digest)
    selected = {ROOT, *CHILDREN}
    if through_allocator:
        selected.add(ALLOCATOR)
    missing = selected.difference(exported)
    if missing:
        raise ValueError(f"missing selected functions: {sorted(missing)}")
    pe = lifter.parse_pe(exe)
    verified = {
        entry: lifter.validate_function_bytes(exported[entry], pe)
        for entry in selected
    }
    root_source, root_diagnostics = lifter.translate_function(
        exported[ROOT], selected,
        stop_call_site=None if through_allocator else STOP,
    )
    allocator_source = None
    allocator_diagnostics = []
    if through_allocator:
        allocator_source, allocator_diagnostics = lifter.translate_function(
            exported[ALLOCATOR], selected, stop_call_sites=ALLOCATOR_STOPS
        )
    children = lifter.translate_function_set(
        [exported[entry] for entry in CHILDREN]
    )
    rejected = {f"0x{entry:08x}": result["reasons"]
                for entry, result in children.items() if result["source"] is None}
    if rejected:
        raise ValueError(f"child translation rejected: {rejected}")
    boundaries = [item for item in root_diagnostics + allocator_diagnostics
                  if item["status"] == "blocked"]
    expected = (
        {"0x00a221e9": "0x00f473a0", "0x00a221fc": "0x011e073e"}
        if through_allocator else {"0x00a2360d": "0x00a221b0"}
    )
    if {item["address"]: item["target"] for item in boundaries} != expected:
        raise ValueError(f"unexpected generated boundaries: {boundaries}")
    if output.exists() and any(output.iterdir()):
        raise ValueError(f"output directory is not empty: {output}")
    output.mkdir(parents=True, exist_ok=True)
    (output / f"spore_{ROOT:08x}_arm64.cpp").write_text(
        root_source + "\n", encoding="utf-8"
    )
    if through_allocator:
        (output / f"spore_{ALLOCATOR:08x}_arm64.cpp").write_text(
            allocator_source + "\n", encoding="utf-8"
        )
    for entry in CHILDREN:
        (output / f"spore_{entry:08x}_arm64.cpp").write_text(
            children[entry]["source"] + "\n", encoding="utf-8"
        )
    (output / "closure_reference_bytes.hpp").write_text(
        closure.emit_reference_bytes_header(selected, verified) + "\n",
        encoding="utf-8",
    )
    data_lines = ["#pragma once", "#include <array>", "#include <cstdint>", ""]
    data_records = []
    for name, address, length in DATA:
        _, _, encoded = lifter.read_pe_bytes(pe, address, length)
        data_records.append({"address": f"0x{address:08x}", "length": length,
                             "bytes": encoded.hex()})
        data_lines.append(
            f"inline constexpr std::array<std::uint8_t, {length}> {name} = {{{{"
        )
        for offset in range(0, length, 16):
            data_lines.append("    " + ", ".join(
                f"0x{byte:02x}u" for byte in encoded[offset:offset + 16]
            ) + ",")
        data_lines.extend(["}};", ""])
    (output / "m7_cfg_data.hpp").write_text(
        "\n".join(data_lines), encoding="utf-8"
    )
    report = {
        "schema": "spore-m7-cfg-call-boundary-v2" if through_allocator
                  else "spore-m7-cfg-call-boundary-v1",
        "source_sha256": digest,
        "root": f"0x{ROOT:08x}",
        "boundaries": boundaries if through_allocator else None,
        "boundary": None if through_allocator else boundaries[0],
        "boundary_executed": False,
        "root_instruction_count": len(exported[ROOT]["instructions"]),
        "pe_backed_data": data_records,
        "functions": [
            {"address": f"0x{entry:08x}",
             "verified_bytes": sum(item["length"] for item in verified[entry]),
             "instruction_count": len(exported[entry]["instructions"])}
            for entry in sorted(selected)
        ],
    }
    (output / "report.json").write_text(
        json.dumps(report, indent=2) + "\n", encoding="utf-8"
    )
    print(f"Generated {len(selected)} verified functions; stop sites: " +
          ", ".join(item["address"] for item in boundaries))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, action="append", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--through-allocator", action="store_true")
    args = parser.parse_args()
    generate(args.exe, args.batch, args.output, args.through_allocator)
