#!/usr/bin/env python3

import argparse
import hashlib
import json
import sys
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as closure


def _function_bytes(function, verified, start, end):
    instructions = sorted(
        verified[lifter.parse_address(function["entry"])],
        key=lambda item: lifter.parse_address(item["address"]),
    )
    cursor = start
    result = bytearray()
    for instruction in instructions:
        address = lifter.parse_address(instruction["address"])
        if address < start or address >= end:
            continue
        if address != cursor:
            raise ValueError(
                f"verified bytes for {function['entry']} have a gap at "
                f"0x{cursor:08x}"
            )
        encoded = bytes.fromhex(instruction["bytes"])
        result.extend(encoded)
        cursor += len(encoded)
    if cursor != end:
        raise ValueError(
            f"verified bytes for {function['entry']} end at 0x{cursor:08x}, "
            f"expected 0x{end:08x}"
        )
    return bytes(result)


def _bytes_array(name, encoded):
    values = ", ".join(f"0x{byte:02x}u" for byte in encoded)
    return (
        f"inline constexpr std::array<std::uint8_t, {len(encoded)}> "
        f"{name} = {{{values}}};"
    )


def _parse_data_range(value):
    address_text, separator, length_text = value.partition(":")
    if not separator or not address_text or not length_text:
        raise ValueError(
            f"invalid PE data range {value!r}; expected ADDRESS:LENGTH"
        )
    address = lifter.parse_address(address_text)
    try:
        length = int(length_text, 0)
    except ValueError as error:
        raise ValueError(
            f"invalid PE data range length in {value!r}"
        ) from error
    if length <= 0 or address + length > 0x100000000:
        raise ValueError(f"PE data range {value!r} is outside the x86 address space")
    return address, length


def _verified_data_ranges(pe, data_ranges):
    records = []
    previous_end = -1
    for address, length in sorted(data_ranges):
        if address < previous_end:
            raise ValueError("PE data ranges must not overlap")
        section, file_offset, encoded = lifter.read_pe_bytes(
            pe, address, length
        )
        records.append({
            "address": address,
            "length": length,
            "section": section,
            "file_offset": file_offset,
            "bytes": encoded,
            "sha256": hashlib.sha256(encoded).hexdigest(),
        })
        previous_end = address + length
    return records


def _reference_header(
    entry, stop, root_bytes, child_entry, child_bytes,
    included_call_site, included_call_target,
    data_ranges=(),
):
    lines = [
        "#pragma once",
        "",
        "#include <array>",
        "#include <cstdint>",
        "",
        "struct SporeVerifiedDataRange {",
        "    std::uint32_t address;",
        "    std::uint32_t length;",
        "    const std::uint8_t* bytes;",
        "};",
        "",
        f"inline constexpr std::uint32_t kSporePrefixEntry = 0x{entry:08x}u;",
        f"inline constexpr std::uint32_t kSporePrefixStop = 0x{stop:08x}u;",
        f"inline constexpr std::uint32_t kSporeChildEntry = 0x{child_entry:08x}u;",
        "inline constexpr std::uint32_t kSporeIncludedCallOffset = "
        f"0x{included_call_site - entry:08x}u;",
        f"inline constexpr std::uint32_t kSporeIncludedCallTarget = "
        f"0x{included_call_target:08x}u;",
        _bytes_array("kSporePrefixBytes", root_bytes),
        _bytes_array("kSporeChildBytes", child_bytes),
        "",
    ]
    for item in data_ranges:
        suffix = f"{item['address']:08x}"
        lines += [
            f"inline constexpr std::uint32_t "
            f"kSporePrefixDataRange_{suffix}_address = "
            f"0x{item['address']:08x}u;",
            _bytes_array(
                f"kSporePrefixDataRange_{suffix}_bytes", item["bytes"]
            ),
            "",
        ]
    lines.append(
        f"inline constexpr std::array<SporeVerifiedDataRange, "
        f"{len(data_ranges)}> kSporePrefixDataRanges = {{{{"
    )
    for item in data_ranges:
        suffix = f"{item['address']:08x}"
        lines.append(
            f"    {{0x{item['address']:08x}u, {item['length']}u, "
            f"kSporePrefixDataRange_{suffix}_bytes.data()}},"
        )
    lines += ["}};", ""]
    return "\n".join(lines)


def generate_function_prefix(
    executable,
    batch_paths,
    entry,
    stop_address,
    included_call_targets,
    output_dir,
    report_path,
    byte_header_path,
    allowed_call_targets=(),
    data_ranges=(),
):
    source_hash = lifter.sha256_file(executable)
    if source_hash != lifter.EXPECTED_SHA256:
        raise ValueError(
            f"PE SHA-256 mismatch: expected {lifter.EXPECTED_SHA256}, "
            f"got {source_hash}"
        )
    exported = closure.load_exported_functions(batch_paths, source_hash)
    pe = lifter.parse_pe(executable)
    verified_data_ranges = _verified_data_ranges(pe, data_ranges)
    entry = lifter.parse_address(entry)
    stop_address = lifter.parse_address(stop_address)
    included_call_targets = {
        lifter.parse_address(value) for value in included_call_targets
    }
    allowed_call_targets = {
        lifter.parse_address(value) for value in allowed_call_targets
    }
    prefix_call_targets = included_call_targets | allowed_call_targets
    if entry not in exported:
        raise ValueError(f"root 0x{entry:08x} is absent from the supplied exports")
    root = exported[entry]
    missing_included = prefix_call_targets.difference(exported)
    if missing_included:
        raise ValueError(
            "allowed prefix call targets are absent from the supplied exports: "
            + ", ".join(f"0x{address:08x}" for address in sorted(missing_included))
        )
    verified = {
        address: lifter.validate_function_bytes(exported[address], pe)
        for address in {entry, *prefix_call_targets}
    }

    root_source, prefix_diagnostics = lifter.translate_function_prefix(
        root, stop_address, prefix_call_targets
    )
    stop_instruction = next(
        instruction for instruction in root["instructions"]
        if lifter.parse_address(instruction["address"]) == stop_address
    )
    stop_target = lifter.direct_call_target(stop_instruction)
    if stop_target not in exported:
        raise ValueError(
            f"boundary target 0x{stop_target:08x} is absent from the supplied exports"
        )
    verified[stop_target] = lifter.validate_function_bytes(
        exported[stop_target], pe
    )

    included_functions = [
        exported[address] for address in sorted(included_call_targets)
    ]
    included_translations = lifter.translate_function_set(included_functions)
    rejected_included = {
        address: result["reasons"]
        for address, result in included_translations.items()
        if result["source"] is None
    }
    if rejected_included:
        detail = "; ".join(
            f"0x{address:08x}: {', '.join(reasons)}"
            for address, reasons in sorted(rejected_included.items())
        )
        raise ValueError(f"an included prefix dependency is not translatable: {detail}")

    boundary_diagnostic = {
        "address": f"0x{stop_target:08x}",
        "name": exported[stop_target].get("name"),
        "classification": "exported_function",
    }
    try:
        _, target_diagnostics = lifter.translate_function(exported[stop_target])
        boundary_diagnostic.update({
            "translation_status": "supported",
            "instruction_diagnostics": target_diagnostics,
        })
    except lifter.LiftRejected as error:
        boundary_diagnostic.update({
            "translation_status": "rejected",
            "reasons": error.reasons,
            "instruction_diagnostics": error.instruction_diagnostics,
        })

    prefix_end = stop_address + int(stop_instruction["length"])
    root_bytes = _function_bytes(
        root, verified, entry, prefix_end
    )
    child_entry = next(iter(included_call_targets)) if len(included_call_targets) == 1 else None
    if child_entry is None:
        raise ValueError("the x86 differential harness currently requires one included call target")
    child = exported[child_entry]
    child_instructions = verified[child_entry]
    child_end = max(
        lifter.parse_address(instruction["address"]) + int(instruction["length"])
        for instruction in child_instructions
    )
    child_bytes = _function_bytes(
        child, verified, child_entry, child_end
    )
    included_call_sites = [
        instruction
        for instruction in root["instructions"]
        if lifter.parse_address(instruction["address"]) < stop_address
        and instruction.get("flow", "").upper() == "UNCONDITIONAL_CALL"
        and lifter.direct_call_target(instruction) in included_call_targets
    ]
    if len(included_call_sites) != 1:
        raise ValueError(
            "the x86 differential harness currently requires exactly one "
            "included direct call"
        )
    included_call_site = lifter.parse_address(
        included_call_sites[0]["address"]
    )
    included_call_target = lifter.direct_call_target(included_call_sites[0])

    if output_dir.exists() and any(output_dir.iterdir()):
        raise ValueError(f"output directory is not empty: {output_dir}")
    for path in (report_path, byte_header_path):
        if path.exists():
            raise ValueError(f"output file already exists; preserve it: {path}")

    source_path = output_dir / f"spore_{entry:08x}_prefix.cpp"
    source = "\n\n".join([
        included_translations[address]["source"]
        for address in sorted(included_call_targets)
    ] + [root_source])
    source_path.parent.mkdir(parents=True, exist_ok=True)
    source_path.write_text(source + "\n", encoding="utf-8", newline="\n")
    byte_header_path.parent.mkdir(parents=True, exist_ok=True)
    byte_header_path.write_text(
        _reference_header(
            entry,
            stop_address,
            root_bytes,
            child_entry,
            child_bytes,
            included_call_site,
            included_call_target,
            verified_data_ranges,
        ),
        encoding="utf-8",
        newline="\n",
    )

    report = {
        "schema": "spore-static-lift-function-prefix-v1",
        "source_sha256": source_hash,
        "batch_exports": [str(path) for path in batch_paths],
        "root": {
            "address": f"0x{entry:08x}",
            "name": root.get("name"),
            "exported_instruction_count": len(root["instructions"]),
            "translated_prefix_instruction_count": sum(
                item["status"] == "translated" for item in prefix_diagnostics
            ),
            "function_complete": False,
            "translation_scope": "linear prefix with explicitly included direct callees",
        },
        "included_call_targets": [
            {
                "address": f"0x{address:08x}",
                "name": exported[address].get("name"),
                "instruction_count": len(exported[address]["instructions"]),
            }
            for address in sorted(included_call_targets)
        ],
        "allowed_call_targets": [
            {
                "address": f"0x{address:08x}",
                "name": exported[address].get("name"),
                "generated_in_prefix": address in included_call_targets,
            }
            for address in sorted(prefix_call_targets)
        ],
        "boundary": {
            "address": f"0x{stop_address:08x}",
            "bytes": stop_instruction["bytes"],
            "target": f"0x{stop_target:08x}",
            "target_diagnostic": boundary_diagnostic,
            "runtime_status": "unsupported_dependency",
            "function_complete": False,
        },
        "x86_reference_relocation": {
            "kind": "CALL rel32",
            "call_site": f"0x{included_call_site:08x}",
            "original_target": f"0x{included_call_target:08x}",
            "purpose": (
                "preserve the original direct-call target when the verified "
                "x86 bytes are mapped at a harness-selected address"
            ),
        },
        "prefix_diagnostics": prefix_diagnostics,
        "generated_source": str(source_path),
        "reference_bytes_header": str(byte_header_path),
        "reference_byte_ranges": [
            {
                "address": f"0x{entry:08x}",
                "length": len(root_bytes),
                "sha256": hashlib.sha256(root_bytes).hexdigest(),
                "purpose": "original root bytes through the boundary CALL",
            },
            {
                "address": f"0x{child_entry:08x}",
                "length": len(child_bytes),
                "sha256": hashlib.sha256(child_bytes).hexdigest(),
                "purpose": "complete directly called child body",
            },
        ],
        "data_ranges": [
            {
                "address": f"0x{item['address']:08x}",
                "length": item["length"],
                "section": item["section"],
                "file_offset": item["file_offset"],
                "sha256": item["sha256"],
            }
            for item in verified_data_ranges
        ],
    }
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(
        json.dumps(report, indent=2) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    return report


def main():
    parser = argparse.ArgumentParser(
        description=(
            "Generate a byte-verified, explicitly partial static-lift prefix "
            "stopping before a selected direct call."
        )
    )
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--batch", type=Path, action="append", required=True)
    parser.add_argument("--entry", required=True)
    parser.add_argument("--stop-at", required=True)
    parser.add_argument(
        "--include-call-target", action="append", default=[]
    )
    parser.add_argument(
        "--allow-call-target", action="append", default=[]
    )
    parser.add_argument(
        "--data-range", action="append", default=[],
        help="verified PE data range as ADDRESS:LENGTH (length accepts 0x...)",
    )
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--byte-header", type=Path, required=True)
    args = parser.parse_args()
    try:
        report = generate_function_prefix(
            args.exe,
            args.batch,
            args.entry,
            args.stop_at,
            args.include_call_target,
            args.output_dir,
            args.report,
            args.byte_header,
            args.allow_call_target,
            [_parse_data_range(value) for value in args.data_range],
        )
    except (
        OSError, ValueError, KeyError, TypeError, json.JSONDecodeError,
        lifter.LiftRejected,
    ) as error:
        print(f"function-prefix lift failed: {error}", file=sys.stderr)
        return 1
    print(
        f"Generated partial prefix for {report['root']['address']}: "
        f"{report['root']['translated_prefix_instruction_count']} root "
        "instructions; stopped before "
        f"{report['boundary']['address']} -> {report['boundary']['target']}."
    )
    print(f"Report: {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
