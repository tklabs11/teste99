import argparse
import json
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as closure


EXPECTED_PE_SHA256 = (
    "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"
)
SOURCE_FUNCTION = 0x011E64F0
SOURCE_INSTRUCTION = 0x011E65C1
TEST_ENTRY = 0x00FEE000
EXPECTED_INSTRUCTION_BYTES = bytes.fromhex("894c862c")


def generate(executable, batch_path, output_path):
    source_hash = lifter.sha256_file(executable)
    if source_hash != EXPECTED_PE_SHA256:
        raise ValueError(f"unexpected PE SHA-256: {source_hash}")
    functions = closure.load_exported_functions(
        [batch_path], source_hash
    )
    source_function = functions.get(SOURCE_FUNCTION)
    if source_function is None:
        raise ValueError("verified batch is missing FUN_011e64f0")
    verified = lifter.validate_function_bytes(
        source_function, lifter.parse_pe(executable)
    )
    instruction_records = {
        lifter.parse_address(item["address"]): item
        for item in source_function["instructions"]
    }
    original = instruction_records.get(SOURCE_INSTRUCTION)
    if original is None:
        raise ValueError("FUN_011e64f0 is missing instruction 0x011e65c1")
    encoded = bytes.fromhex(original["bytes"])
    if encoded != EXPECTED_INSTRUCTION_BYTES:
        raise ValueError(
            "unexpected bytes at 0x011e65c1: " + encoded.hex()
        )
    if not any(
        lifter.parse_address(item["address"]) == SOURCE_INSTRUCTION
        and bytes.fromhex(item["bytes"]) == EXPECTED_INSTRUCTION_BYTES
        for item in verified
    ):
        raise ValueError("the indexed store was not included in byte verification")

    translated_instruction = dict(original)
    translated_instruction["address"] = f"0x{TEST_ENTRY:08x}"
    return_instruction = {
        "address": f"0x{TEST_ENTRY + len(encoded):08x}",
        "bytes": "c3",
        "length": 1,
        "mnemonic": "RET",
        "operands": [],
        "flow": "TERMINAL",
        "flows_to": [],
        "references": [],
    }
    test_function = {
        "entry": f"0x{TEST_ENTRY:08x}",
        "name": "FUN_indexed_store_regression",
        "body_address_count": len(encoded) + 1,
        "instructions": [translated_instruction, return_instruction],
        "instruction_count_exported": 2,
        "instructions_truncated": False,
        "references_truncated": False,
    }
    source, diagnostics = lifter.translate_function(test_function)
    if any(item["status"] != "translated" for item in diagnostics):
        raise ValueError("generated indexed-store regression was rejected")
    if "state.eflags =" in source:
        raise ValueError("MOV indexed-store lift unexpectedly changes flags")

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(source + "\n", encoding="utf-8")
    return source_hash


def main():
    parser = argparse.ArgumentParser(
        description="Generate a regression from a byte-verified x86 MOV."
    )
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    arguments = parser.parse_args()
    try:
        source_hash = generate(
            arguments.exe, arguments.batch, arguments.output
        )
    except (
        OSError, ValueError, KeyError, TypeError, json.JSONDecodeError,
    ) as error:
        parser.exit(1, f"indexed-memory test generation failed: {error}\n")
    print(
        "Generated indexed MOV differential test for "
        f"0x{SOURCE_INSTRUCTION:08x} bytes=894c862c "
        f"source_sha256={source_hash}"
    )


if __name__ == "__main__":
    main()
