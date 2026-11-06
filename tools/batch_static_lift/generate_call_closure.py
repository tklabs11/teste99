import argparse
import json
import struct
import sys
from pathlib import Path

import BatchStaticLift as lifter


def load_exported_functions(batch_paths, source_hash):
    functions = {}
    for batch_path in batch_paths:
        if batch_path.stat().st_size > lifter.MAX_BATCH_BYTES:
            raise ValueError(f"batch export exceeds the 128 MiB input limit: {batch_path}")
        batch = json.loads(batch_path.read_text(encoding="utf-8"))
        if batch.get("schema") != "spore-ghidra-function-batch-v1":
            raise ValueError(f"unsupported batch schema in {batch_path}")
        if batch.get("selected_source_sha256") != source_hash:
            raise ValueError(f"batch export source SHA-256 differs in {batch_path}")
        if batch.get("selected_source_is_phase4_build") is not True:
            raise ValueError(f"batch export does not identify the approved build: {batch_path}")
        if batch.get("user_confirmed_source_for_open_program") is not True:
            raise ValueError(f"batch export has no Ghidra source confirmation: {batch_path}")
        if batch.get("language_id") != lifter.EXPECTED_LANGUAGE:
            raise ValueError(f"unexpected Ghidra language in {batch_path}")
        if batch.get("functions_truncated") is not False:
            raise ValueError(f"batch function list is incomplete: {batch_path}")
        records = batch.get("functions")
        if not isinstance(records, list):
            raise ValueError(f"batch export is missing its function list: {batch_path}")
        for record in records:
            function = record.get("function")
            if not isinstance(function, dict):
                raise ValueError(f"batch entry is missing its function record: {batch_path}")
            entry = lifter.parse_address(function["entry"])
            if entry in functions:
                raise ValueError(f"duplicate exported function entry 0x{entry:08x}")
            functions[entry] = function
    return functions


def collect_call_closure(root_entries, exported_functions, pe):
    selected = set()
    pending = list(root_entries)
    verified = {}
    while pending:
        entry = pending.pop()
        if entry in selected:
            continue
        function = exported_functions.get(entry)
        if function is None:
            raise ValueError(f"function 0x{entry:08x} is not available in the supplied export")
        verified[entry] = lifter.validate_function_bytes(function, pe)
        selected.add(entry)
        for instruction in function.get("instructions", []):
            mnemonic = str(instruction.get("mnemonic", "")).upper()
            flow = str(instruction.get("flow", "")).upper()
            if mnemonic not in {"CALL", "CALLF"} and "CALL" not in flow:
                continue
            target = lifter.direct_call_target(instruction)
            if target not in exported_functions:
                raise ValueError(
                    f"direct call target 0x{target:08x} from "
                    f"{instruction.get('address')} is not present in the supplied exports"
                )
            pending.append(target)
    return selected, verified


def emit_reference_bytes_header(selected, verified):
    lines = [
        "#pragma once",
        "",
        "#include <array>",
        "#include <cstdint>",
        "",
        "#ifndef SPORE_VERIFIED_INSTRUCTION_DEFINED",
        "#define SPORE_VERIFIED_INSTRUCTION_DEFINED",
        "struct SporeVerifiedInstruction {",
        "    std::uint32_t address;",
        "    std::uint32_t length;",
        "    std::array<std::uint8_t, 15> bytes;",
        "};",
        "#endif",
        "",
    ]
    for entry in sorted(selected):
        instructions = verified[entry]
        lines.append(
            f"inline constexpr std::uint32_t kSporeEntry_{entry:08x} = "
            f"0x{entry:08x}u;"
        )
        lines.append(
            f"inline constexpr std::array<SporeVerifiedInstruction, "
            f"{len(instructions)}> kSporeInstructions_{entry:08x} = {{{{"
        )
        for instruction in instructions:
            encoded = bytes.fromhex(instruction["bytes"])
            if len(encoded) > 15:
                raise ValueError(
                    f"x86 instruction at {instruction['address']} exceeds 15 bytes"
                )
            padded = list(encoded) + [0] * (15 - len(encoded))
            byte_values = ", ".join(f"0x{value:02x}u" for value in padded)
            lines.append(
                f"    {{0x{int(instruction['address'], 16):08x}u, "
                f"{instruction['length']}u, {{{{{byte_values}}}}}}},"
            )
        lines += ["}};", ""]
    return "\n".join(lines)


def generate_call_closure(
    executable, batch_paths, root_entries, output_dir, report_path,
    byte_header_path=None,
):
    source_hash = lifter.sha256_file(executable)
    if source_hash != lifter.EXPECTED_SHA256:
        raise ValueError(
            f"PE SHA-256 mismatch: expected {lifter.EXPECTED_SHA256}, got {source_hash}"
        )
    exported_functions = load_exported_functions(batch_paths, source_hash)
    pe = lifter.parse_pe(executable)
    selected, verified = collect_call_closure(
        root_entries, exported_functions, pe
    )
    functions = [exported_functions[entry] for entry in sorted(selected)]
    translations = lifter.translate_function_set(functions)
    rejected = {
        entry: result["reasons"]
        for entry, result in translations.items()
        if result["source"] is None
    }
    if rejected:
        details = "; ".join(
            f"0x{entry:08x}: {', '.join(reasons)}"
            for entry, reasons in sorted(rejected.items())
        )
        raise ValueError(f"call closure contains unsupported functions: {details}")

    if output_dir.exists() and any(output_dir.iterdir()):
        raise ValueError(f"output directory is not empty: {output_dir}")
    if report_path.exists():
        raise ValueError(f"report already exists; preserve it before rerunning: {report_path}")
    if byte_header_path is not None and byte_header_path.exists():
        raise ValueError(
            f"reference-byte header already exists; preserve it before rerunning: "
            f"{byte_header_path}"
        )

    generated_files = {}
    report_functions = []
    for entry in sorted(selected):
        function = exported_functions[entry]
        call_targets = lifter.function_call_targets(function)
        filename = f"spore_{entry:08x}_arm64.cpp"
        generated_files[filename] = translations[entry]["source"] + "\n"
        report_functions.append({
            "address": f"0x{entry:08x}",
            "name": function["name"],
            "generated_source": filename,
            "instruction_count": len(function["instructions"]),
            "verified_instruction_bytes": sum(
                item["length"] for item in verified[entry]
            ),
            "direct_call_targets": [f"0x{target:08x}" for target in call_targets],
        })

    report = {
        "schema": "spore-static-lift-call-closure-v1",
        "source_sha256": source_hash,
        "batch_exports": [str(path) for path in batch_paths],
        "root_entries": [f"0x{entry:08x}" for entry in root_entries],
        "function_count": len(selected),
        "reference_bytes_header": (
            str(byte_header_path) if byte_header_path is not None else None
        ),
        "functions": report_functions,
    }
    output_dir.mkdir(parents=True, exist_ok=True)
    report_path.parent.mkdir(parents=True, exist_ok=True)
    for filename, source in generated_files.items():
        (output_dir / filename).write_text(source, encoding="utf-8")
    if byte_header_path is not None:
        byte_header_path.parent.mkdir(parents=True, exist_ok=True)
        byte_header_path.write_text(
            emit_reference_bytes_header(selected, verified),
            encoding="utf-8",
            newline="\n",
        )
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return report


def main():
    parser = argparse.ArgumentParser(
        description="Generate byte-verified lifts for selected functions and their direct-call closure."
    )
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--batch", type=Path, action="append", required=True)
    parser.add_argument("--entry", type=str, action="append", required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("--byte-header", type=Path)
    args = parser.parse_args()
    try:
        entries = [lifter.parse_address(value) for value in args.entry]
        report = generate_call_closure(
            args.exe, args.batch, entries, args.output_dir, args.report,
            args.byte_header,
        )
    except (
        OSError, ValueError, KeyError, TypeError, json.JSONDecodeError, struct.error
    ) as error:
        print(f"call-closure lift failed: {error}", file=sys.stderr)
        return 1
    print(
        f"Generated {report['function_count']} byte-verified function(s) "
        f"from {len(report['root_entries'])} root(s)."
    )
    for function in report["functions"]:
        print(
            f"{function['address']} {function['name']}: "
            f"{function['instruction_count']} instructions, "
            f"calls={','.join(function['direct_call_targets']) or 'none'}"
        )
    print(f"Report: {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
