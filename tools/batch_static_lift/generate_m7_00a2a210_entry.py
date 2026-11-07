"""Generate PE-verified constructor prefixes to selected call boundaries."""

import argparse
import hashlib
import json
import struct
from pathlib import Path

import BatchStaticLift as lifter
import generate_call_closure as closure


ENTRY = 0x00A2A210
STOP = 0x00A2A24E
TARGET = 0x00921260
ROOT_CALL = 0x00A33817
ROOT_ENTRY = 0x00A33600
ROOT_STOP = 0x00A33831
ROOT_NEXT_TARGET = 0x00A2F210
ROOT_SECOND_STOP = 0x00A3384B
SECOND_CHILD_ENTRY = 0x00A2F210
ROOT_THIRD_STOP = 0x00A33865
ROOT_THIRD_TARGET = 0x00A2A310
ROOT_FOURTH_STOP = 0x00A3387F
ROOT_FIFTH_STOP = 0x00A3394F
FOURTH_CHILD_ENTRY = 0x00A2A310
FOURTH_CHILD_STOP = 0x00A2A34E
FOURTH_CHILD_NEXT_STOP = 0x00A2A375
FOURTH_CHILD_THIRD_STOP = 0x00A2A39E
FOURTH_CHILD_THIRD_TARGET = 0x00A23620
FOURTH_CHILD_FOLLOWING_STOP = 0x00A2A3E6
FOURTH_HELPER_ENTRY = 0x00A23620
FOURTH_HELPER_STOP = 0x00A23665
FOURTH_HELPER_FLOAT_STOP = 0x00A236B2
FOURTH_HELPER_ALLOCATOR_STOP = 0x00A236BD
FIFTH_CHILD_ENTRY = 0x00A30E10
FIFTH_CHILD_STOP = 0x00A30E4E
FIFTH_CHILD_NEXT_STOP = 0x00A30E75
FIFTH_CHILD_THIRD_STOP = 0x00A30E9E
FIFTH_CHILD_THIRD_TARGET = 0x00A236D0
FIFTH_CHILD_FOURTH_STOP = 0x00A30EE6
FIFTH_HELPER_ENTRY = 0x00A236D0
FIFTH_HELPER_STOP = 0x00A23715
ROOT_LEAF = 0x00743B50
NEXT_STOP = 0x00A2A275
NEXT_TARGET = 0x00921340
SECOND_STOP = 0x00A2A29E
SECOND_TARGET = 0x00A23570
LOOKUP_TARGET = 0x009212C0
THIRD_STOP = 0x00A2A2E6
THIRD_TARGET = 0x009213C0
FLOAT_BRANCH_STOP = 0x00A2A2EE
ALLOCATOR = 0x00A221B0
HELPERS = (0x00921300, 0x00921360)
MEMSET_THUNK = 0x011E073E
MEMSET_CALL_SITE = 0x00A221FC
MEMSET_IAT = 0x013CC478
TABLE_BASE = 0x0143D850
TABLE_SIZE = 0x404


def generate(exe: Path, batches: list[Path], output: Path,
             through_first_call: bool = False,
             through_second_call: bool = False,
             through_third_call: bool = False,
             through_memset: bool = False,
             through_float_call: bool = False,
             through_child_return: bool = False,
             through_second_child_return: bool = False,
             through_third_child_return: bool = False,
             through_fourth_child_entry: bool = False,
             through_fourth_first_call: bool = False,
             through_fourth_second_call: bool = False,
             through_fourth_third_entry: bool = False,
             through_fourth_third_first_call: bool = False,
             through_fourth_helper_float_call: bool = False,
             through_fourth_helper_allocator_call: bool = False,
             through_fourth_child_return: bool = False,
             through_fifth_child_entry: bool = False,
             through_fifth_first_call: bool = False,
             through_fifth_second_call: bool = False,
             through_fifth_third_entry: bool = False):
    through_fifth_second_call = (
        through_fifth_second_call or through_fifth_third_entry)
    through_fifth_first_call = (
        through_fifth_first_call or through_fifth_second_call)
    through_fifth_child_entry = (
        through_fifth_child_entry or through_fifth_first_call)
    through_fourth_child_return = (
        through_fourth_child_return or through_fifth_child_entry)
    through_fourth_helper_allocator_call = (
        through_fourth_helper_allocator_call or through_fourth_child_return)
    through_fourth_helper_float_call = (
        through_fourth_helper_float_call
        or through_fourth_helper_allocator_call)
    through_fourth_third_first_call = (
        through_fourth_third_first_call or through_fourth_helper_float_call)
    through_fourth_third_entry = (
        through_fourth_third_entry or through_fourth_third_first_call)
    through_fourth_second_call = (
        through_fourth_second_call or through_fourth_third_entry)
    through_fourth_first_call = (
        through_fourth_first_call or through_fourth_second_call)
    through_fourth_child_entry = (
        through_fourth_child_entry or through_fourth_first_call)
    through_third_child_return = (
        through_third_child_return or through_fourth_child_entry)
    through_second_child_return = (
        through_second_child_return or through_third_child_return)
    through_child_return = through_child_return or through_second_child_return
    through_float_call = through_float_call or through_child_return
    through_memset = through_memset or through_float_call
    through_third_call = through_third_call or through_memset
    through_second_call = through_second_call or through_third_call
    through_first_call = through_first_call or through_second_call
    digest = lifter.sha256_file(exe)
    if digest != lifter.EXPECTED_SHA256:
        raise ValueError(f"PE hash mismatch: {digest}")
    exported = closure.load_exported_functions(batches, digest)
    if any(address not in exported for address in
           (ENTRY, TARGET, ROOT_ENTRY, ROOT_NEXT_TARGET, ROOT_LEAF,
            NEXT_TARGET, SECOND_TARGET, LOOKUP_TARGET, THIRD_TARGET,
            ALLOCATOR, *HELPERS)):
        raise ValueError("a required constructor entry or call target is absent")
    if through_fourth_third_entry and FOURTH_HELPER_ENTRY not in exported:
        raise ValueError("the fourth child helper is absent")
    if through_fifth_child_entry and FIFTH_CHILD_ENTRY not in exported:
        raise ValueError("the fifth child entry is absent")
    if through_fifth_third_entry and FIFTH_HELPER_ENTRY not in exported:
        raise ValueError("the fifth helper entry is absent")
    root_stop = (ROOT_FIFTH_STOP if through_fifth_child_entry
                 else ROOT_FOURTH_STOP if through_fourth_child_entry
                 else ROOT_THIRD_STOP if through_third_child_return
                 else ROOT_SECOND_STOP if through_second_child_return
                 else ROOT_STOP)
    root_next_target = (0x00A2A410 if through_fifth_child_entry
                        else FIFTH_CHILD_ENTRY if through_fourth_child_entry
                        else ROOT_THIRD_TARGET if through_third_child_return
                        else ENTRY if through_second_child_return
                        else ROOT_NEXT_TARGET)
    pe = lifter.parse_pe(exe)
    if through_memset:
        _, _, thunk_bytes = lifter.read_pe_bytes(pe, MEMSET_THUNK, 5)
        _, _, call_bytes = lifter.read_pe_bytes(pe, MEMSET_CALL_SITE, 5)
        imports = lifter.parse_pe_iat_imports(pe)
        if thunk_bytes != bytes.fromhex("e9d10f22ff"):
            raise ValueError("unexpected unresolved memset thunk bytes")
        if (call_bytes != bytes.fromhex("e83de57b00") or
                imports.get(MEMSET_IAT) != "MSVCR90.dll!memset"):
            raise ValueError("memset callsite or IAT does not match reference PE")
    verified = lifter.validate_function_bytes(exported[ENTRY], pe)
    target_verified = lifter.validate_function_bytes(exported[TARGET], pe)
    lifter.validate_function_bytes(exported[ROOT_ENTRY], pe)
    lifter.validate_function_bytes(exported[ROOT_LEAF], pe)
    leaf_source, _ = lifter.translate_function(exported[ROOT_LEAF])
    stop = FLOAT_BRANCH_STOP if through_float_call else (
        THIRD_STOP if through_third_call else (SECOND_STOP if through_second_call else (
        NEXT_STOP if through_first_call else STOP)
        ))
    expected_target = THIRD_TARGET if through_third_call else (SECOND_TARGET if through_second_call else (
        NEXT_TARGET if through_first_call else TARGET)
        )
    if through_child_return:
        source, diagnostics = lifter.translate_function(
            exported[ENTRY], set(exported),
            stop_call_sites={0x00A2A2F3})
        blocked = [item for item in diagnostics if item["status"] == "blocked"]
        if len(blocked) != 1 or blocked[0]["target"] != "0x00a22220":
            raise ValueError(f"unexpected guarded child CALL: {blocked}")
        prefix = verified
    else:
        source, diagnostics = lifter.translate_function_prefix(
            exported[ENTRY], stop, set(exported) if through_first_call else None,
            allow_branch_boundary=through_float_call,
        )
        blocked = [item for item in diagnostics if item["status"] == "blocked"]
        if (len(blocked) != 1 or
                (through_float_call and blocked[0]["mnemonic"] != "JBE") or
                (not through_float_call and
                 blocked[0]["target"] != f"0x{expected_target:08x}")):
            raise ValueError(f"unexpected boundary: {blocked}")
        prefix = [item for item in verified
                  if lifter.parse_address(item["address"]) < stop]
    encoded = b"".join(bytes.fromhex(item["bytes"]) for item in prefix)
    expected_count = None if through_third_call else (
        42 if through_second_call else (26 if through_first_call else 18))
    if (expected_count is not None and len(prefix) != expected_count) or (
            len(encoded) != (
                0x00A2A30D - ENTRY if through_child_return else stop - ENTRY)):
        raise ValueError("unexpected instruction count or prefix byte length")
    target_encoded = b"".join(bytes.fromhex(item["bytes"])
                              for item in target_verified)
    if through_first_call and len(target_verified) != 38:
        raise ValueError("unexpected first-call target instruction count")
    target_source = None
    if through_first_call:
        target_source, _ = lifter.translate_function(exported[TARGET])
    next_source = lookup_source = None
    next_encoded = lookup_encoded = table_bytes = b""
    if through_second_call:
        next_verified = lifter.validate_function_bytes(exported[NEXT_TARGET], pe)
        lookup_verified = lifter.validate_function_bytes(exported[LOOKUP_TARGET], pe)
        if len(next_verified) != 8 or len(lookup_verified) != 26:
            raise ValueError("unexpected lookup function instruction count")
        next_encoded = b"".join(bytes.fromhex(item["bytes"])
                                for item in next_verified)
        lookup_encoded = b"".join(bytes.fromhex(item["bytes"])
                                  for item in lookup_verified)
        next_source, _ = lifter.translate_function(
            exported[NEXT_TARGET], set(exported))
        lookup_source, _ = lifter.translate_function(exported[LOOKUP_TARGET])
        _, _, table_bytes = lifter.read_pe_bytes(pe, TABLE_BASE, TABLE_SIZE)
    third_sources = {}
    third_encoded = {}
    float_call_source = None
    float_call_encoded = b""
    second_child_source = None
    second_child_encoded = b""
    fourth_child_source = None
    fourth_child_encoded = b""
    fourth_child_blocked = None
    fourth_helper_source = None
    fourth_helper_encoded = b""
    fourth_helper_blocked = None
    fifth_child_source = None
    fifth_child_encoded = b""
    fifth_child_blocked = None
    fifth_helper_source = None
    fifth_helper_encoded = b""
    fifth_helper_blocked = None
    scale_bytes = correction_bytes = post_float_bytes = b""
    if through_third_call:
        _, _, scale_bytes = lifter.read_pe_bytes(pe, 0x01470F14, 4)
        _, _, correction_bytes = lifter.read_pe_bytes(pe, 0x013F4FD0, 4)
        if through_memset:
            _, _, post_float_bytes = lifter.read_pe_bytes(pe, 0x013F0620, 4)
        for address in (SECOND_TARGET, ALLOCATOR, *HELPERS):
            records = lifter.validate_function_bytes(exported[address], pe)
            third_encoded[address] = b"".join(
                bytes.fromhex(item["bytes"]) for item in records)
            kwargs = ({"stop_call_sites": {0x00A221E9} if through_memset
                       else {0x00A221E9, MEMSET_CALL_SITE},
                       **({"direct_import_aliases": {
                           MEMSET_CALL_SITE: (MEMSET_THUNK,
                                              "MSVCR90.dll!memset", MEMSET_IAT)}}
                          if through_memset else {})}
                      if address == ALLOCATOR else {})
            third_sources[address], _ = lifter.translate_function(
                exported[address], set(exported), **kwargs)
        if through_float_call:
            float_verified = lifter.validate_function_bytes(
                exported[THIRD_TARGET], pe)
            if len(float_verified) != 39:
                raise ValueError("unexpected float-call instruction count")
            float_call_encoded = b"".join(
                bytes.fromhex(item["bytes"]) for item in float_verified)
            float_call_source, _ = lifter.translate_function(
                exported[THIRD_TARGET], set(exported))
        if through_second_child_return:
            second_verified = lifter.validate_function_bytes(
                exported[SECOND_CHILD_ENTRY], pe)
            if len(second_verified) != 71:
                raise ValueError("unexpected second child instruction count")
            second_child_encoded = b"".join(
                bytes.fromhex(item["bytes"]) for item in second_verified)
            second_child_source, second_diagnostics = lifter.translate_function(
                exported[SECOND_CHILD_ENTRY], set(exported),
                stop_call_sites={0x00A2F2F3})
            second_blocked = [
                item for item in second_diagnostics
                if item["status"] == "blocked"]
            if len(second_blocked) != 1 or (
                    second_blocked[0]["target"] != "0x00a22220"):
                raise ValueError(
                    f"unexpected guarded second child CALL: {second_blocked}")
        if through_fourth_child_entry:
            fourth_stop = (
                FOURTH_CHILD_FOLLOWING_STOP if through_fourth_third_entry
                else FOURTH_CHILD_THIRD_STOP if through_fourth_second_call
                else FOURTH_CHILD_NEXT_STOP if through_fourth_first_call
                else FOURTH_CHILD_STOP)
            fourth_verified = lifter.validate_function_bytes(
                exported[FOURTH_CHILD_ENTRY], pe)
            fourth_prefix = (
                fourth_verified if through_fourth_child_return else [
                    item for item in fourth_verified
                    if lifter.parse_address(item["address"]) < fourth_stop])
            expected_fourth_count = (
                71 if through_fourth_child_return
                else 58 if through_fourth_third_entry
                else 42 if through_fourth_second_call
                else 26 if through_fourth_first_call else 18)
            if len(fourth_prefix) != expected_fourth_count:
                raise ValueError("unexpected fourth child prefix count")
            fourth_child_encoded = b"".join(
                bytes.fromhex(item["bytes"]) for item in fourth_prefix)
            expected_fourth_bytes = (
                253 if through_fourth_child_return else
                fourth_stop - FOURTH_CHILD_ENTRY)
            if len(fourth_child_encoded) != expected_fourth_bytes:
                raise ValueError("unexpected fourth child prefix length")
            if through_fourth_child_return:
                fourth_child_source, fourth_diagnostics = (
                    lifter.translate_function(
                        exported[FOURTH_CHILD_ENTRY], set(exported),
                        stop_call_sites={0x00A2A3F3}))
            else:
                fourth_child_source, fourth_diagnostics = (
                    lifter.translate_function_prefix(
                        exported[FOURTH_CHILD_ENTRY], fourth_stop,
                        set(exported)))
            fourth_blocks = [
                item for item in fourth_diagnostics
                if item["status"] == "blocked"]
            expected_fourth_target = (
                "0x00a22220" if through_fourth_child_return
                else "0x009213c0" if through_fourth_third_entry
                else f"0x{FOURTH_CHILD_THIRD_TARGET:08x}"
                if through_fourth_second_call
                else "0x00921340" if through_fourth_first_call
                else "0x00921260")
            if len(fourth_blocks) != 1 or (
                    fourth_blocks[0]["target"] != expected_fourth_target):
                raise ValueError(
                    f"unexpected fourth child boundary: {fourth_blocks}")
            fourth_child_blocked = fourth_blocks[0]
            if through_fourth_third_entry:
                helper_verified = lifter.validate_function_bytes(
                    exported[FOURTH_HELPER_ENTRY], pe)
                helper_prefix = (
                    helper_verified if through_fourth_third_first_call else [
                        item for item in helper_verified
                        if lifter.parse_address(item["address"]) < FOURTH_HELPER_STOP])
                expected_helper_count = (
                    60 if through_fourth_third_first_call else 24)
                if len(helper_prefix) != expected_helper_count:
                    raise ValueError("unexpected fourth helper instruction count")
                fourth_helper_encoded = b"".join(
                    bytes.fromhex(item["bytes"]) for item in helper_prefix)
                expected_helper_bytes = (
                    174 if through_fourth_third_first_call else
                    FOURTH_HELPER_STOP - FOURTH_HELPER_ENTRY)
                if len(fourth_helper_encoded) != expected_helper_bytes:
                    raise ValueError("unexpected fourth helper prefix length")
                if through_fourth_third_first_call:
                    guarded_helper_calls = (
                        set() if through_fourth_helper_allocator_call else
                        {FOURTH_HELPER_ALLOCATOR_STOP}
                        if through_fourth_helper_float_call else
                        {FOURTH_HELPER_FLOAT_STOP,
                         FOURTH_HELPER_ALLOCATOR_STOP})
                    fourth_helper_source, helper_diagnostics = (
                        lifter.translate_function(
                            exported[FOURTH_HELPER_ENTRY], set(exported),
                            stop_call_sites=guarded_helper_calls))
                else:
                    fourth_helper_source, helper_diagnostics = (
                        lifter.translate_function_prefix(
                            exported[FOURTH_HELPER_ENTRY], FOURTH_HELPER_STOP,
                            set(exported)))
                helper_blocks = [item for item in helper_diagnostics
                                 if item["status"] == "blocked"]
                expected_blocks = (
                    {} if through_fourth_helper_allocator_call else
                    {FOURTH_HELPER_ALLOCATOR_STOP: "0x00a221b0"}
                    if through_fourth_helper_float_call else
                    {FOURTH_HELPER_FLOAT_STOP: "0x00921360",
                     FOURTH_HELPER_ALLOCATOR_STOP: "0x00a221b0"}
                    if through_fourth_third_first_call else
                    {FOURTH_HELPER_STOP: "0x00921260"})
                observed_blocks = {
                    lifter.parse_address(item["address"]): item["target"]
                    for item in helper_blocks}
                if observed_blocks != expected_blocks:
                    raise ValueError(
                        f"unexpected fourth helper boundary: {helper_blocks}")
                if not through_fourth_helper_allocator_call:
                    fourth_helper_blocked = next(
                        item for item in helper_blocks
                        if lifter.parse_address(item["address"]) == (
                            FOURTH_HELPER_ALLOCATOR_STOP
                            if through_fourth_helper_float_call
                            else FOURTH_HELPER_FLOAT_STOP
                            if through_fourth_third_first_call
                            else FOURTH_HELPER_STOP))
    if through_fifth_child_entry:
        fifth_stop = (FIFTH_CHILD_FOURTH_STOP if through_fifth_third_entry
                      else FIFTH_CHILD_THIRD_STOP if through_fifth_second_call
                      else FIFTH_CHILD_NEXT_STOP if through_fifth_first_call
                      else FIFTH_CHILD_STOP)
        fifth_verified = lifter.validate_function_bytes(
            exported[FIFTH_CHILD_ENTRY], pe)
        fifth_prefix = [item for item in fifth_verified
                        if lifter.parse_address(item["address"]) < fifth_stop]
        expected_fifth_count = (
            58 if through_fifth_third_entry else
            42 if through_fifth_second_call else
            26 if through_fifth_first_call else 18)
        if len(fifth_prefix) != expected_fifth_count:
            raise ValueError("unexpected fifth child prefix count")
        fifth_child_encoded = b"".join(
            bytes.fromhex(item["bytes"]) for item in fifth_prefix)
        if len(fifth_child_encoded) != fifth_stop - FIFTH_CHILD_ENTRY:
            raise ValueError("unexpected fifth child prefix length")
        fifth_child_source, fifth_diagnostics = (
            lifter.translate_function_prefix(
                exported[FIFTH_CHILD_ENTRY], fifth_stop,
                set(exported)))
        fifth_blocks = [item for item in fifth_diagnostics
                        if item["status"] == "blocked"]
        expected_fifth_target = (
            "0x009213c0" if through_fifth_third_entry else
            f"0x{FIFTH_CHILD_THIRD_TARGET:08x}"
            if through_fifth_second_call else
            "0x00921340" if through_fifth_first_call else "0x00921260")
        if len(fifth_blocks) != 1 or (
                fifth_blocks[0]["target"] != expected_fifth_target):
            raise ValueError(f"unexpected fifth child boundary: {fifth_blocks}")
        fifth_child_blocked = fifth_blocks[0]
        if through_fifth_third_entry:
            helper_verified = lifter.validate_function_bytes(
                exported[FIFTH_HELPER_ENTRY], pe)
            helper_prefix = [item for item in helper_verified
                             if lifter.parse_address(item["address"])
                             < FIFTH_HELPER_STOP]
            if len(helper_prefix) != 24:
                raise ValueError("unexpected fifth helper prefix count")
            fifth_helper_encoded = b"".join(
                bytes.fromhex(item["bytes"]) for item in helper_prefix)
            if len(fifth_helper_encoded) != (
                    FIFTH_HELPER_STOP - FIFTH_HELPER_ENTRY):
                raise ValueError("unexpected fifth helper prefix length")
            fifth_helper_source, helper_diagnostics = (
                lifter.translate_function_prefix(
                    exported[FIFTH_HELPER_ENTRY], FIFTH_HELPER_STOP,
                    set(exported)))
            helper_blocks = [item for item in helper_diagnostics
                             if item["status"] == "blocked"]
            if len(helper_blocks) != 1 or (
                    helper_blocks[0]["target"] != "0x00921260"):
                raise ValueError(
                    f"unexpected fifth helper boundary: {helper_blocks}")
            fifth_helper_blocked = helper_blocks[0]
    root_source, root_diagnostics = lifter.translate_function_prefix(
        exported[ROOT_ENTRY], root_stop, set(exported)
    )
    root_blocked = [item for item in root_diagnostics
                    if item["status"] == "blocked"]
    if len(root_blocked) != 1 or root_blocked[0]["target"] != (
            f"0x{root_next_target:08x}"):
        raise ValueError(f"unexpected constructor boundary: {root_blocked}")
    root_translated = [item for item in root_diagnostics
                       if item["status"] == "translated"]
    if not any(item["address"] == f"0x{ROOT_CALL:08x}"
               for item in root_translated):
        raise ValueError("constructor CALL was not translated")
    _, _, root_call = lifter.read_pe_bytes(pe, ROOT_CALL, 5)
    if root_call[0] != 0xE8 or (
        ROOT_CALL + 5 + struct.unpack_from("<i", root_call, 1)[0]
    ) != ENTRY:
        raise ValueError("constructor boundary does not call the selected entry")
    root_tail = b""
    if through_child_return:
        _, _, root_tail = lifter.read_pe_bytes(
            pe, ROOT_CALL, root_stop - ROOT_CALL)
        expected_tail_length = (
            0x138 if through_fifth_child_entry
            else 0x68 if through_fourth_child_entry
            else 0x4e if through_third_child_return
            else 0x34 if through_second_child_return else 0x1a)
        if root_tail[:5] != root_call or (
                len(root_tail) != expected_tail_length):
            raise ValueError("unexpected constructor tail bytes")
    if output.exists() and any(output.iterdir()):
        raise ValueError(f"output directory is not empty: {output}")
    output.mkdir(parents=True, exist_ok=True)
    (output / f"spore_{ENTRY:08x}_prefix.cpp").write_text(
        source + "\n", encoding="utf-8"
    )
    (output / f"spore_{ROOT_ENTRY:08x}_prefix.cpp").write_text(
        leaf_source + "\n\n" + root_source + "\n", encoding="utf-8"
    )
    if target_source is not None:
        (output / f"spore_{TARGET:08x}.cpp").write_text(
            target_source + "\n", encoding="utf-8"
        )
    if next_source is not None and lookup_source is not None:
        (output / f"spore_{NEXT_TARGET:08x}.cpp").write_text(
            next_source + "\n", encoding="utf-8")
        (output / f"spore_{LOOKUP_TARGET:08x}.cpp").write_text(
            lookup_source + "\n", encoding="utf-8")
    for address, body in third_sources.items():
        (output / f"spore_{address:08x}.cpp").write_text(
            body + "\n", encoding="utf-8")
    if float_call_source is not None:
        (output / f"spore_{THIRD_TARGET:08x}.cpp").write_text(
            float_call_source + "\n", encoding="utf-8")
    if second_child_source is not None:
        (output / f"spore_{SECOND_CHILD_ENTRY:08x}.cpp").write_text(
            second_child_source + "\n", encoding="utf-8")
    if fourth_child_source is not None:
        (output / f"spore_{FOURTH_CHILD_ENTRY:08x}_prefix.cpp").write_text(
            fourth_child_source + "\n", encoding="utf-8")
    if fourth_helper_source is not None:
        (output / f"spore_{FOURTH_HELPER_ENTRY:08x}_prefix.cpp").write_text(
            fourth_helper_source + "\n", encoding="utf-8")
    if fifth_child_source is not None:
        (output / f"spore_{FIFTH_CHILD_ENTRY:08x}_prefix.cpp").write_text(
            fifth_child_source + "\n", encoding="utf-8")
    if fifth_helper_source is not None:
        (output / f"spore_{FIFTH_HELPER_ENTRY:08x}_prefix.cpp").write_text(
            fifth_helper_source + "\n", encoding="utf-8")
    byte_values = ", ".join(f"0x{byte:02x}u" for byte in encoded)
    target_values = ", ".join(f"0x{byte:02x}u" for byte in target_encoded)
    third_array_names = {
        SECOND_TARGET: "kM7CfgBytes",
        0x00921300: "kM7Search2Bytes",
        0x00921360: "kM7FloatBytes",
        ALLOCATOR: "kM7AllocatorBytes",
        THIRD_TARGET: "kM7FloatCallBytes",
    }
    if through_float_call:
        third_encoded[THIRD_TARGET] = float_call_encoded
    third_arrays = "".join(
        f"inline constexpr std::array<std::uint8_t, {len(encoded)}> "
        f"{third_array_names[address]} = {{{', '.join(f'0x{byte:02x}u' for byte in encoded)}}};\n"
        for address, encoded in sorted(third_encoded.items()))
    (output / "m7_entry_reference_bytes.hpp").write_text(
        "#pragma once\n#include <array>\n#include <cstdint>\n"
        f"inline constexpr std::array<std::uint8_t, {len(encoded)}> "
        f"kM7EntryBytes = {{{byte_values}}};\n"
        f"inline constexpr std::array<std::uint8_t, 5> kM7RootCallBytes = "
        "{" + ", ".join(f"0x{byte:02x}u" for byte in root_call) + "};\n"
        + (f"inline constexpr std::array<std::uint8_t, {len(root_tail)}> "
           "kM7RootTailBytes = {"
           + ", ".join(f"0x{byte:02x}u" for byte in root_tail)
           + "};\n" if through_child_return else "")
        + (f"inline constexpr std::array<std::uint8_t, "
           f"{len(second_child_encoded)}> kM7SecondEntryBytes = "
           + "{" + ", ".join(
               f"0x{byte:02x}u" for byte in second_child_encoded)
           + "};\n" if through_second_child_return else "")
        + (f"inline constexpr std::array<std::uint8_t, "
           f"{len(fourth_child_encoded)}> kM7FourthEntryBytes = "
           + "{" + ", ".join(
               f"0x{byte:02x}u" for byte in fourth_child_encoded)
           + "};\n" if through_fourth_child_entry else "")
        + (f"inline constexpr std::array<std::uint8_t, "
           f"{len(fourth_helper_encoded)}> kM7FourthHelperBytes = "
           + "{" + ", ".join(
               f"0x{byte:02x}u" for byte in fourth_helper_encoded)
           + "};\n" if through_fourth_third_entry else "")
        + (f"inline constexpr std::array<std::uint8_t, "
           f"{len(fifth_child_encoded)}> kM7FifthEntryBytes = "
           + "{" + ", ".join(
               f"0x{byte:02x}u" for byte in fifth_child_encoded)
           + "};\n" if through_fifth_child_entry else "")
        + (f"inline constexpr std::array<std::uint8_t, "
           f"{len(fifth_helper_encoded)}> kM7FifthHelperBytes = "
           + "{" + ", ".join(
               f"0x{byte:02x}u" for byte in fifth_helper_encoded)
           + "};\n" if through_fifth_third_entry else "")
        + (f"inline constexpr std::array<std::uint8_t, {len(target_encoded)}> "
           f"kM7TargetBytes = {{{target_values}}};\n"
           if through_first_call else "")
        + (f"inline constexpr std::array<std::uint8_t, {len(next_encoded)}> "
           "kM7NextBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in next_encoded) + "};\n"
           f"inline constexpr std::array<std::uint8_t, {len(lookup_encoded)}> "
           "kM7LookupBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in lookup_encoded) + "};\n"
           f"inline constexpr std::array<std::uint8_t, {len(table_bytes)}> "
           "kM7TableBytes = {" + ", ".join(f"0x{byte:02x}u" for byte in table_bytes) + "};\n"
           if through_second_call else "")
        + ("inline constexpr std::array<std::uint8_t, 4> kM7ScaleBytes = {"
           + ", ".join(f"0x{byte:02x}u" for byte in scale_bytes) + "};\n"
           "inline constexpr std::array<std::uint8_t, 4> kM7CorrectionBytes = {"
           + ", ".join(f"0x{byte:02x}u" for byte in correction_bytes) + "};\n"
           if through_third_call else "")
        + ("inline constexpr std::array<std::uint8_t, 4> kM7PostFloatBytes = {"
           + ", ".join(f"0x{byte:02x}u" for byte in post_float_bytes) + "};\n"
           if through_memset else "")
        + third_arrays,
        encoding="utf-8",
    )
    report = {
        "schema": "spore-m7-00a2a210-entry-v1",
        "source_sha256": digest,
        "entry": f"0x{ENTRY:08x}",
        "boundary": (
            fifth_helper_blocked if through_fifth_third_entry
            else fifth_child_blocked if through_fifth_child_entry
            else root_blocked[0] if through_fourth_child_return
            else fourth_child_blocked if through_fourth_helper_allocator_call
            else fourth_helper_blocked if through_fourth_third_entry
            else fourth_child_blocked if through_fourth_child_entry
            else root_blocked[0] if through_child_return else blocked[0]),
        "boundary_executed": False,
        "translated_instruction_count": sum(
            item["status"] == "translated" for item in diagnostics),
        "verified_instruction_count": len(prefix),
        "first_call_executed": through_first_call,
        "second_call_executed": through_second_call,
        "third_call_in_generated_prefix": through_third_call,
        "post_resolution_memset_alias": through_memset,
        "float_call_executed_in_generated_prefix": through_float_call,
        "float_call_instruction_count": 39 if through_float_call else 0,
        "child_return_path_enabled": through_child_return,
        "second_child_return_path_enabled": through_second_child_return,
        "third_child_return_path_enabled": through_third_child_return,
        "fourth_child_entry_path_enabled": through_fourth_child_entry,
        "fourth_first_call_in_prefix": through_fourth_first_call,
        "fourth_second_call_in_prefix": through_fourth_second_call,
        "fourth_third_call_in_prefix": through_fourth_third_entry,
        "fourth_helper_first_call_in_prefix": through_fourth_third_first_call,
        "fourth_helper_float_call_in_prefix": through_fourth_helper_float_call,
        "fourth_helper_allocator_call_in_prefix": (
            through_fourth_helper_allocator_call),
        "fourth_child_return_path_enabled": through_fourth_child_return,
        "fifth_child_entry_path_enabled": through_fifth_child_entry,
        "fifth_first_call_in_prefix": through_fifth_first_call,
        "fifth_second_call_in_prefix": through_fifth_second_call,
        "fifth_third_call_in_prefix": through_fifth_third_entry,
        "fifth_helper_prefix_instruction_count": (
            24 if through_fifth_third_entry else 0),
        "fifth_child_prefix_instruction_count": (
            58 if through_fifth_third_entry else
            42 if through_fifth_second_call else
            26 if through_fifth_first_call else
            18 if through_fifth_child_entry else 0),
        "fourth_child_prefix_instruction_count": (
            71 if through_fourth_child_return
            else 58 if through_fourth_third_entry
            else 42 if through_fourth_second_call
            else 26 if through_fourth_first_call
            else 18 if through_fourth_child_entry else 0),
        "fourth_helper_prefix_instruction_count": (
            60 if through_fourth_third_first_call else
            24 if through_fourth_third_entry else 0),
        "second_child_instruction_count": (
            71 if through_second_child_return else 0),
        "guarded_call_site": "0x00a2a2f3" if through_child_return else None,
        "guarded_call_target": "0x00a22220" if through_child_return else None,
        "constructor_tail_bytes": root_tail.hex() if through_child_return else None,
        "memset_callsite": f"0x{MEMSET_CALL_SITE:08x}" if through_memset else None,
        "memset_thunk": f"0x{MEMSET_THUNK:08x}" if through_memset else None,
        "memset_iat": f"0x{MEMSET_IAT:08x}" if through_memset else None,
        "first_call_target_instruction_count": len(target_verified) if through_first_call else 0,
        "lookup_table_address": f"0x{TABLE_BASE:08x}" if through_second_call else None,
        "lookup_table_sha256": hashlib.sha256(table_bytes).hexdigest() if through_second_call else None,
        "scale_bytes": scale_bytes.hex() if through_third_call else None,
        "correction_bytes": correction_bytes.hex() if through_third_call else None,
        "post_float_bytes": post_float_bytes.hex() if through_memset else None,
        "verified_prefix_sha256": hashlib.sha256(encoded).hexdigest(),
        "verified_prefix_bytes": encoded.hex(),
        "constructor_call_address": f"0x{ROOT_CALL:08x}",
        "constructor_call_bytes": root_call.hex(),
        "constructor_generated_stop": f"0x{root_stop:08x}",
        "constructor_generated_instruction_count": len(root_translated),
        "constructor_generated_stop_reachable_in_fixture": (
            None if through_child_return else False),
        "last_executed_byte_if_reached": (
            f"0x{FIFTH_HELPER_STOP - 1:08x}"
            if through_fifth_third_entry
            else f"0x{FIFTH_CHILD_THIRD_STOP - 1:08x}"
            if through_fifth_second_call
            else f"0x{FIFTH_CHILD_NEXT_STOP - 1:08x}"
            if through_fifth_first_call
            else f"0x{FIFTH_CHILD_STOP - 1:08x}"
            if through_fifth_child_entry
            else f"0x{ROOT_FOURTH_STOP - 1:08x}"
            if through_fourth_child_return
            else f"0x{FOURTH_CHILD_FOLLOWING_STOP - 1:08x}"
            if through_fourth_helper_allocator_call
            else f"0x{FOURTH_HELPER_ALLOCATOR_STOP - 1:08x}"
            if through_fourth_helper_float_call
            else f"0x{FOURTH_HELPER_FLOAT_STOP - 1:08x}"
            if through_fourth_third_first_call
            else f"0x{FOURTH_HELPER_STOP - 1:08x}"
            if through_fourth_third_entry
            else f"0x{FOURTH_CHILD_THIRD_STOP - 1:08x}"
            if through_fourth_second_call
            else f"0x{FOURTH_CHILD_NEXT_STOP - 1:08x}"
            if through_fourth_first_call
            else f"0x{FOURTH_CHILD_STOP - 1:08x}"
            if through_fourth_child_entry
            else f"0x{root_stop - 1:08x}" if through_child_return
            else f"0x{stop - 1:08x}"),
    }
    (output / "report.json").write_text(
        json.dumps(report, indent=2) + "\n", encoding="utf-8"
    )
    print(f"Generated {len(prefix)} PE-verified instructions from "
          f"0x{ENTRY:08x}; boundary "
          + (f"0x{FIFTH_HELPER_STOP:08x} -> 0x00921260"
             if through_fifth_third_entry else
             f"0x{FIFTH_CHILD_THIRD_STOP:08x} -> "
             f"0x{FIFTH_CHILD_THIRD_TARGET:08x}"
             if through_fifth_second_call else
             f"0x{FIFTH_CHILD_NEXT_STOP:08x} -> 0x00921340"
             if through_fifth_first_call else
             f"0x{FIFTH_CHILD_STOP:08x} -> 0x00921260"
             if through_fifth_child_entry else
             f"0x{ROOT_FOURTH_STOP:08x} -> 0x00a30e10"
             if through_fourth_child_return else
             f"0x{FOURTH_CHILD_FOLLOWING_STOP:08x} -> 0x009213c0"
             if through_fourth_helper_allocator_call else
             f"0x{FOURTH_HELPER_ALLOCATOR_STOP:08x} -> 0x00a221b0"
             if through_fourth_helper_float_call else
             f"0x{FOURTH_HELPER_FLOAT_STOP:08x} -> 0x00921360"
             if through_fourth_third_first_call else
             f"0x{FOURTH_HELPER_STOP:08x} -> 0x{TARGET:08x}"
             if through_fourth_third_entry else
             f"0x{FOURTH_CHILD_THIRD_STOP:08x} -> "
             f"0x{FOURTH_CHILD_THIRD_TARGET:08x}"
             if through_fourth_second_call else
             f"0x{FOURTH_CHILD_NEXT_STOP:08x} -> 0x{NEXT_TARGET:08x}"
             if through_fourth_first_call else
             f"0x{FOURTH_CHILD_STOP:08x} -> 0x{TARGET:08x}"
             if through_fourth_child_entry else
             f"0x{root_stop:08x} -> 0x{root_next_target:08x}"
             if through_child_return else
             f"0x{stop:08x}" + (
                 " conditional branch" if through_float_call else
                 f" -> 0x{expected_target:08x}")))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--exe", required=True, type=Path)
    parser.add_argument("--batch", required=True, action="append", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--through-first-call", action="store_true")
    parser.add_argument("--through-second-call", action="store_true")
    parser.add_argument("--through-third-call", action="store_true")
    parser.add_argument("--through-memset", action="store_true")
    parser.add_argument("--through-float-call", action="store_true")
    parser.add_argument("--through-child-return", action="store_true")
    parser.add_argument("--through-second-child-return", action="store_true")
    parser.add_argument("--through-third-child-return", action="store_true")
    parser.add_argument("--through-fourth-child-entry", action="store_true")
    parser.add_argument("--through-fourth-first-call", action="store_true")
    parser.add_argument("--through-fourth-second-call", action="store_true")
    parser.add_argument("--through-fourth-third-entry", action="store_true")
    parser.add_argument("--through-fourth-third-first-call", action="store_true")
    parser.add_argument("--through-fourth-helper-float-call", action="store_true")
    parser.add_argument("--through-fourth-helper-allocator-call", action="store_true")
    parser.add_argument("--through-fourth-child-return", action="store_true")
    parser.add_argument("--through-fifth-child-entry", action="store_true")
    parser.add_argument("--through-fifth-first-call", action="store_true")
    parser.add_argument("--through-fifth-second-call", action="store_true")
    parser.add_argument("--through-fifth-third-entry", action="store_true")
    args = parser.parse_args()
    generate(args.exe, args.batch, args.output, args.through_first_call,
             args.through_second_call, args.through_third_call,
             args.through_memset, args.through_float_call,
             args.through_child_return, args.through_second_child_return,
             args.through_third_child_return,
             args.through_fourth_child_entry,
             args.through_fourth_first_call,
             args.through_fourth_second_call,
             args.through_fourth_third_entry,
             args.through_fourth_third_first_call,
             args.through_fourth_helper_float_call,
             args.through_fourth_helper_allocator_call,
             args.through_fourth_child_return,
             args.through_fifth_child_entry,
             args.through_fifth_first_call,
             args.through_fifth_second_call,
             args.through_fifth_third_entry)
