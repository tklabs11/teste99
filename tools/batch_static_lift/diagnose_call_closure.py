import argparse
import json
import struct
import sys
from collections import deque
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as generator


def _rva_to_offset(pe, rva, size):
    image, _, sections = pe
    for _, section_rva, _, raw_offset, raw_size in sections:
        if section_rva <= rva and rva + size <= section_rva + raw_size:
            return raw_offset + rva - section_rva
    if rva < len(image) and rva + size <= len(image):
        return rva
    raise ValueError(f"PE RVA 0x{rva:08x} is not backed by file data")


def parse_import_thunks(pe):
    image, image_base, sections = pe
    pe_offset = struct.unpack_from("<I", image, 0x3c)[0]
    optional = pe_offset + 24
    directory_count = struct.unpack_from("<I", image, optional + 92)[0]
    if directory_count <= 1:
        return {}
    import_rva, import_size = struct.unpack_from(
        "<II", image, optional + 96 + 8
    )
    if import_rva == 0 or import_size == 0:
        return {}

    slots = {}
    descriptor_offset = _rva_to_offset(pe, import_rva, 20)
    descriptor_end = descriptor_offset + import_size
    while descriptor_offset + 20 <= min(descriptor_end, len(image)):
        original_thunk, _, _, name_rva, first_thunk = struct.unpack_from(
            "<IIIII", image, descriptor_offset
        )
        if not any((original_thunk, name_rva, first_thunk)):
            break
        dll_offset = _rva_to_offset(pe, name_rva, 1)
        dll_end = image.find(b"\0", dll_offset)
        if dll_end < 0:
            raise ValueError("unterminated DLL name in PE import descriptor")
        dll_name = image[dll_offset:dll_end].decode("ascii", "replace")
        lookup_rva = original_thunk or first_thunk
        index = 0
        while True:
            thunk_offset = _rva_to_offset(pe, lookup_rva + index * 4, 4)
            thunk_value = struct.unpack_from("<I", image, thunk_offset)[0]
            if thunk_value == 0:
                break
            if thunk_value & 0x80000000:
                symbol = f"ordinal_{thunk_value & 0xffff}"
            else:
                import_name_offset = _rva_to_offset(pe, thunk_value, 3)
                name_offset = import_name_offset + 2
                name_end = image.find(b"\0", name_offset)
                if name_end < 0:
                    raise ValueError("unterminated function name in PE import table")
                symbol = image[name_offset:name_end].decode("ascii", "replace")
            iat_va = image_base + first_thunk + index * 4
            slots[iat_va] = f"{dll_name}!{symbol}"
            index += 1
        descriptor_offset += 20

    stubs = {}
    for name, section_rva, _, raw_offset, raw_size in sections:
        if name != ".text":
            continue
        section_bytes = image[raw_offset:raw_offset + raw_size]
        for offset in range(max(0, len(section_bytes) - 5)):
            if section_bytes[offset:offset + 2] != b"\xff\x25":
                continue
            iat_va = struct.unpack_from("<I", section_bytes, offset + 2)[0]
            imported_symbol = slots.get(iat_va)
            if imported_symbol is not None:
                stub_va = image_base + section_rva + offset
                stubs[stub_va] = {
                    "symbol": imported_symbol,
                    "iat_address": f"0x{iat_va:08x}",
                }
    return stubs


def build_export_index(batch_paths, source_hash):
    index = {}
    names = {}
    for batch_path in batch_paths:
        if batch_path.stat().st_size > lifter.MAX_BATCH_BYTES:
            raise ValueError(
                f"batch export exceeds the 128 MiB input limit: {batch_path}"
            )
        batch = json.loads(batch_path.read_text(encoding="utf-8"))
        generator._validate_batch(batch, batch_path, source_hash)
        for record in batch["functions"]:
            function = record["function"]
            entry = lifter.parse_address(function["entry"])
            if entry in index:
                raise ValueError(f"duplicate exported function entry 0x{entry:08x}")
            index[entry] = batch_path
            names[entry] = function.get("name", f"FUN_{entry:08x}")
    return index, names


def load_selected_functions(batch_path, source_hash, selected_entries):
    functions = generator.load_exported_functions([batch_path], source_hash)
    return {
        entry: functions[entry]
        for entry in selected_entries
        if entry in functions
    }


def _is_call(instruction):
    mnemonic = str(instruction.get("mnemonic", "")).upper()
    flow = str(instruction.get("flow", "")).upper()
    return mnemonic in {"CALL", "CALLF"} or "CALL" in flow


def _call_references(instruction):
    references = []
    for reference in instruction.get("references", []):
        if reference.get("is_call") and reference.get("to"):
            try:
                target = lifter.parse_address(reference["to"])
            except ValueError:
                continue
            references.append(target)
    return references


def _section_for_address(pe, address):
    _, image_base, sections = pe
    rva = address - image_base
    for name, section_rva, virtual_size, _, raw_size in sections:
        if section_rva <= rva < section_rva + max(virtual_size, raw_size):
            return name
    return None


def _target_record(target, export_index, import_stubs, pe):
    address = f"0x{target:08x}"
    if target in import_stubs:
        return {
            "address": address,
            "classification": "import_thunk",
            **import_stubs[target],
        }
    if target in export_index:
        return {"address": address, "classification": "exported_function"}
    section = _section_for_address(pe, target)
    if section == ".text":
        classification = "missing_internal_function"
    else:
        classification = "unresolved_destination"
    return {
        "address": address,
        "classification": classification,
        "section": section,
    }


def diagnose_call_closure(executable, batch_paths, root_entries):
    source_hash = lifter.sha256_file(executable)
    if source_hash != lifter.EXPECTED_SHA256:
        raise ValueError(
            f"PE SHA-256 mismatch: expected {lifter.EXPECTED_SHA256}, got {source_hash}"
        )
    pe = lifter.parse_pe(executable)
    import_stubs = parse_import_thunks(pe)
    export_index, names = build_export_index(batch_paths, source_hash)

    report_functions = {}
    missing_dependencies = {}
    indirect_calls = []
    unresolved_calls = []
    unsupported_instructions = []
    invalid_functions = []
    edges = []
    parent = {}
    pending = deque()
    for entry in root_entries:
        pending.append(entry)
        parent.setdefault(entry, None)

    while pending:
        requested_entries = []
        seen_in_wave = set()
        while pending:
            entry = pending.popleft()
            if entry not in report_functions and entry not in seen_in_wave:
                requested_entries.append(entry)
                seen_in_wave.add(entry)
        grouped = {}
        for entry in requested_entries:
            batch_path = export_index.get(entry)
            if batch_path is None:
                target = _target_record(entry, export_index, import_stubs, pe)
                missing_dependencies.setdefault(entry, {
                    **target,
                    "referenced_by": [],
                })
                continue
            grouped.setdefault(batch_path, set()).add(entry)

        for batch_path, selected_entries in grouped.items():
            functions = load_selected_functions(
                batch_path, source_hash, selected_entries
            )
            for entry in sorted(selected_entries):
                function = functions.get(entry)
                if function is None:
                    continue
                try:
                    verified = lifter.validate_function_bytes(function, pe)
                    validation_error = None
                except (KeyError, TypeError, ValueError) as error:
                    verified = []
                    validation_error = str(error)

                translation = None
                try:
                    _, diagnostics = lifter.translate_function(
                        function, set(export_index)
                    )
                    translation = {"diagnostics": diagnostics, "reasons": []}
                except lifter.LiftRejected as error:
                    translation = {
                        "diagnostics": error.instruction_diagnostics,
                        "reasons": error.reasons,
                    }

                function_report = {
                    "address": f"0x{entry:08x}",
                    "name": names[entry],
                    "batch": str(batch_path),
                    "instruction_count": len(function.get("instructions", [])),
                    "verified_byte_count": sum(
                        item["length"] for item in verified
                    ),
                    "byte_validation_error": validation_error,
                    "translation_reasons": translation["reasons"],
                    "direct_calls": [],
                }
                for diagnostic in translation["diagnostics"]:
                    if diagnostic.get("status") != "rejected":
                        continue
                    mnemonic = diagnostic.get("mnemonic", "UNKNOWN")
                    if mnemonic not in {"CALL", "CALLF"}:
                        unsupported_instructions.append({
                            "function": f"0x{entry:08x}",
                            "address": diagnostic.get("address"),
                            "mnemonic": mnemonic,
                            "reason": diagnostic.get("reason"),
                        })

                report_functions[entry] = function_report
                if validation_error is not None:
                    invalid_functions.append({
                        "function": f"0x{entry:08x}",
                        "reason": validation_error,
                    })

                for instruction in function.get("instructions", []):
                    if not _is_call(instruction):
                        continue
                    instruction_address = instruction.get("address")
                    call_record = {
                        "site": instruction_address,
                        "mnemonic": str(
                            instruction.get("mnemonic", "CALL")
                        ).upper(),
                        "operand": instruction.get("operands", []),
                    }
                    try:
                        target = lifter.direct_call_target(instruction)
                    except (KeyError, TypeError, ValueError) as error:
                        candidates = [
                            _target_record(candidate, export_index, import_stubs, pe)
                            for candidate in _call_references(instruction)
                        ]
                        record = {
                            "function": f"0x{entry:08x}",
                            **call_record,
                            "reason": str(error),
                            "resolution_status": "unresolved_runtime_target",
                            "destination_classification": (
                                "indirect_call_with_static_candidate"
                                if candidates else "unresolved_destination"
                            ),
                            "candidate_targets": candidates,
                        }
                        indirect_calls.append(record)
                        for candidate in candidates:
                            if candidate["classification"] == "exported_function":
                                candidate_entry = int(candidate["address"], 16)
                                edges.append({
                                    "from": f"0x{entry:08x}",
                                    "to": candidate["address"],
                                    "kind": "indirect_candidate",
                                    "site": instruction_address,
                                })
                        continue

                    target_record = _target_record(
                        target, export_index, import_stubs, pe
                    )
                    call_record["target"] = target_record
                    function_report["direct_calls"].append(call_record)
                    if target_record["classification"] == "exported_function":
                        edges.append({
                            "from": f"0x{entry:08x}",
                            "to": target_record["address"],
                            "kind": "direct",
                            "site": instruction_address,
                        })
                        if target not in report_functions:
                            if target not in parent:
                                parent[target] = entry
                            pending.append(target)
                    elif target_record["classification"] == "import_thunk":
                        continue
                    elif target_record["classification"] == "missing_internal_function":
                        missing = missing_dependencies.setdefault(target, {
                            **target_record,
                            "referenced_by": [],
                        })
                        missing["referenced_by"].append({
                            "function": f"0x{entry:08x}",
                            "site": instruction_address,
                        })
                    else:
                        unresolved_calls.append({
                            "function": f"0x{entry:08x}",
                            **call_record,
                        })

    function_list = [
        report_functions[entry]
        for entry in sorted(report_functions)
    ]
    report = {
        "schema": "spore-static-lift-call-diagnostic-v1",
        "source_sha256": source_hash,
        "batch_exports": [str(path) for path in batch_paths],
        "root_entries": [f"0x{entry:08x}" for entry in root_entries],
        "reachable_exported_function_count": len(function_list),
        "import_thunk_count_in_pe": len(import_stubs),
        "functions": function_list,
        "direct_call_edges": edges,
        "missing_dependencies": sorted(
            missing_dependencies.values(),
            key=lambda item: (item["classification"], item["address"]),
        ),
        "indirect_calls": indirect_calls,
        "unresolved_calls": unresolved_calls,
        "unsupported_instructions": unsupported_instructions,
        "invalid_functions": invalid_functions,
        "counts": {
            "missing_internal_functions": sum(
                item["classification"] == "missing_internal_function"
                for item in missing_dependencies.values()
            ),
            "import_thunk_call_sites": sum(
                call["target"]["classification"] == "import_thunk"
                for function in function_list
                for call in function["direct_calls"]
            ),
            "indirect_calls": len(indirect_calls),
            "unresolved_calls": len(unresolved_calls),
            "indirect_calls_without_candidates": sum(
                call["destination_classification"] == "unresolved_destination"
                for call in indirect_calls
            ),
            "unsupported_instructions": len(unsupported_instructions),
            "invalid_functions": len(invalid_functions),
        },
    }

    paths = {}
    for entry in report_functions:
        chain = []
        current = entry
        while current is not None:
            chain.append(f"0x{current:08x}")
            current = parent.get(current)
        paths[f"0x{entry:08x}"] = list(reversed(chain))
    report["shortest_direct_paths_from_roots"] = paths
    return report


def main():
    parser = argparse.ArgumentParser(
        description=(
            "Diagnose a direct-call closure without emitting translated code."
        )
    )
    parser.add_argument("--exe", type=Path, required=True)
    parser.add_argument("--batch-dir", type=Path, required=True)
    parser.add_argument("--batch-pattern", default="spore_batch_all_*.json")
    parser.add_argument("--root", action="append", required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    batch_paths = sorted(args.batch_dir.glob(args.batch_pattern))
    if not batch_paths:
        parser.error(f"no batch exports match {args.batch_dir / args.batch_pattern}")
    try:
        roots = [lifter.parse_address(value) for value in args.root]
        report = diagnose_call_closure(args.exe, batch_paths, roots)
    except (
        OSError, ValueError, KeyError, TypeError, json.JSONDecodeError, struct.error
    ) as error:
        print(f"call-closure diagnostic failed: {error}", file=sys.stderr)
        return 1
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(
        json.dumps(report, indent=2) + "\n", encoding="utf-8"
    )
    print(
        f"Diagnosed {report['reachable_exported_function_count']} exported "
        f"function(s); no code emitted."
    )
    print(f"Findings: {json.dumps(report['counts'], sort_keys=True)}")
    print(f"Report: {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
