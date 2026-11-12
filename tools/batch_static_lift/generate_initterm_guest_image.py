#!/usr/bin/env python3
"""Emit the guest memory image the CRT initializer closure reads and writes.

Running ``_initterm_e`` reaches three initializers (``0x011e10bf``,
``0x011e1304``, ``0x011e135a``) that touch absolute guest addresses: the PE
headers at ``0x00400000``, the import cells they read as data, the initializer
table, the security cookie and the CRT globals the loader leaves zero-filled.

Each window is either copied from the original PE or emitted as zeros after
proving that the loader would zero-fill it. Any absolute address used by the
generated closure sources that no window covers is an error, so the guest
cannot silently read unmapped memory.
"""

import argparse
import json
import re
from pathlib import Path

import BatchStaticLift as lifter


# (address, size, name, writable, reason)
WINDOWS = [
    (0x00400000, 0x400, "pe_headers", False,
     "the __cinit application-type probe reads the DOS and NT headers"),
    (0x0110af9c, 0x04, "adjust_fdiv_cell", False,
     "the _adjust_fdiv import is read through its IAT pointer"),
    (0x013cc000, 0x800, "import_cells", True,
     "the whole IAT: the loader rewrites every slot with a resolved address, "
     "so the guest may read any of them as data"),
    (0x013cc80c, 0x1e884, "cpp_initializer_table", False,
     "the C++ initializer table between the bound the CRT pushes (0x013cc80c) and "
     "the C table that follows it (0x013eb090): initializers read it as data to "
     "register further work, so a shorter window is a wall per slot"),
    (0x013eb090, 0x20, "initializer_table", False,
     "the table _initterm_e walks"),
    (0x015cfe70, 0x18, "security_cookie", True,
     "the security cookie and the two CRT initializer guards"),
    (0x015cff00, 0x08, "fmode_commode", True,
     "guest stand-in for the MSVCR90 _fmode and _commode ints"),
    (0x015cff40, 0x40, "argv_envp", True,
     "guest argv/envp arrays and the program name string __getmainargs builds"),
    (0x0154df38, 0x04, "initializer_flag", True,
     "the CRT flag the second C++ initializer toggles"),
    (0x0154df84, 0x10, "engine_registry_flags", True,
     "the four .data words the object subsystem's registry code reads and "
     "updates: the file holds zeros there, so nothing is synthesized"),
    (0x015d0690, 0x04, "initializer_state", True,
     "the CRT state word the fifth C++ initializer toggles"),
    (0x01667c00, 0x18, "initializer_critical_section", True,
     "the loader-zeroed critical section the first initializer initializes"),
    (0x016f4e98, 0x18, "initializer_critical_section_2", True,
     "the loader-zeroed critical section the fourth initializer initializes"),
    (0x016f2600, 0x60, "crt_globals", True,
     "_fmode/_commode defaults, the app-type flag and the app-type address"),
    (0x0143e830, 0x20, "engine_format_strings", False,
     "the two format strings the single-instance guard passes to sprintf and wsprintfA"),
    (0x0143e050, 0x24, "engine_object_vtable", False,
     "the nine-slot vtable the allocated object's first field points at: the "
     "walk reads slot 0 and calls it, so the table must be the original bytes"),
    (0x014082f0, 0x5c, "engine_class_vtable", False,
     "a run of 23 method pointers the walk indexes by class: reading slot 5 of "
     "the table at 0x01408310 is what the new body does, and the run ends at the "
     "string that follows it"),
    (0x01408240, 0xb0, "engine_class_names", False,
     "the class-name strings the registry compares byte by byte: the block starts "
     "at the first name and ends where the method table begins, both observed in "
     "the file"),
    (0x0143dc78, 0x14, "engine_class_descriptor", False,
     "a class descriptor out of .rdata: the -1 sentinel the walk reads first, "
     "followed by four method pointers, bounded by the string that follows"),
    (0x0093a2b8, 0x20, "engine_switch_table", False,
     "the eight-entry jump table a switched body indexes out of .text: the run "
     "sits between a non-pointer word and the int3 padding, both observed",),
    (0x0143dcc4, 0x174, "engine_class_registry_tables", False,
     "the 93-slot run of method pointers the class registry indexes by name: the "
     "run is bounded by the ASCII string before it and the EATrace string after "
     "it, both observed in the file"),
    (0x01669930, 0x18, "engine_guard_globals", True,
     "the guard's node pointer, node count and the second counter"),
    (0x015fd8c4, 0x04, "engine_singleton_word_a", True,
     "a loader-zeroed .data word the batch tests before building its object"),
    (0x01600508, 0x04, "engine_singleton_word_b", True,
     "a loader-zeroed .data word the batch tests before building its object"),
    (0x016c8b40, 0x10, "cpp_initializer_engine_state", True,
     "the three .data words the seventh initializer and its factory test"),
    (0x013eb130, 0x60, "initializer_helper_table", False,
     "the .rdata table the CRT float helpers index in this batch"),
    (0x013ec5b4, 0x04, "crt_helper_word_a", False,
     "a .rdata word a lifted helper reads directly"),
    (0x013ef548, 0x04, "crt_helper_word_b", False,
     "a .rdata word a lifted helper reads directly"),
    (0x013f1f0c, 0x04, "crt_helper_word_c", False,
     "a .rdata word a lifted helper reads directly"),
    (0x0143ea80, 0x20, "crt_helper_table_b", False,
     "the .rdata table a lifted helper reads directly"),
    (0x01470f14, 0x04, "crt_helper_word_d", False,
     "a .rdata word a lifted helper reads directly"),
    (0x0140f338, 0x08, "crt_double_constant_a", False,
     "a .rdata double a lifted helper loads as an 8-byte value"),
    (0x013f0620, 0x04, "crt_float_constant_b", False,
     "a .rdata float the float helpers load"),
    (0x013f4fd0, 0x04, "crt_float_constant_c", False,
     "a .rdata float the float helpers load"),
    (0x0147105c, 0x04, "crt_float_constant_d", False,
     "a .rdata float the float helpers load"),
    (0x01485370, 0x08, "crt_float_constants_e", False,
     "the .rdata floats the clamp helpers compare against"),
    (0x01485718, 0x08, "crt_float_constants_f", False,
     "the .rdata floats the clamp helpers compare against"),
    (0x01486108, 0x04, "crt_float_constant_g", False,
     "a .rdata float the float helpers load"),
    (0x01669950, 0x50, "engine_helper_state_c", True,
     "loader-zeroed .data words a lifted helper reads and writes"),
    (0x0154eae8, 0x10, "crt_runtime_flags", True,
     "the loader-zeroed .data flags a lifted helper tests before running"),
    (0x016699a0, 0x10, "engine_helper_state_b", True,
     "loader-zeroed .data words a lifted helper reads"),
    (0x0171e740, 0x30, "startup_state", True,
     "startup lock, startup state and the encoded null pointers"),
    (0x0143e0e4, 0x30, "rdata_0143e0e4", False,
     "the 12-entry run of code pointers the second class table holds; the walk "
     "reads them by index, so the run is mapped as the file has it"),
    (0x0143dff4, 0x0c, "rdata_block_0143dff4", False,
     "the block of data the guest reads at 0x0143dffc; it is bounded by the text and the code pointer runs around it"),
    (0x01668000, 0x1000, "data_page_01668000", True,
     "the loader-zeroed page the guest writes at 0x01668958; the file holds no bytes here, so the page is zero-filled at load time"),
    (0x0143d850, 0x208, "rdata_block_0143d850", False,
     "the block of data the guest reads at 0x0143da50; it is bounded by the text and the code pointer runs around it"),
    (0x013eb1bc, 0x20, "rdata_reads_013eb1bc", False,
     "the 8 word(s) a lifted body reads directly, from 0x013eb1bc to 0x013eb1d8; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb190, 0x04, "rdata_reads_013eb190", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb190 to 0x013eb190; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb194, 0x28, "rdata_strings_013eb198", False,
     "the string table the guest reads at 0x013eb1a8; it covers every adjacent word of text and stops at the first word that is not"),
    (0x013eb224, 0x30, "rdata_block_013eb224", False,
     "the block of data the guest reads at 0x013eb248; it is bounded by the text and the code pointer runs around it"),
    (0x015d0c00, 0x1400, "data_page_015d1000", True,
     "the loader-zeroed page the guest writes at 0x015d1288; the file holds no bytes here, so the page is zero-filled at load time"),
    (0x013eb220, 0x04, "rdata_reads_013eb220", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb220 to 0x013eb220; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb254, 0x04, "rdata_reads_013eb254", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb254 to 0x013eb254; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb260, 0x04, "rdata_reads_013eb260", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb260 to 0x013eb260; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb274, 0x04, "rdata_reads_013eb274", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb274 to 0x013eb274; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb27c, 0x04, "rdata_reads_013eb27c", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb27c to 0x013eb27c; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb284, 0x04, "rdata_reads_013eb284", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb284 to 0x013eb284; the addresses are the ones the image generator reported as unmapped"),
    (0x013eb298, 0x04, "rdata_reads_013eb298", False,
     "the 1 word(s) a lifted body reads directly, from 0x013eb298 to 0x013eb298; the addresses are the ones the image generator reported as unmapped"),
    (0x016f2974, 0x08, "data_reads_016f2974", True,
     "the 2 word(s) a lifted body reads directly, from 0x016f2974 to 0x016f2978; the addresses are the ones the image generator reported as unmapped"),
    (0x016f4ae4, 0x0c, "data_reads_016f4ae4", True,
     "the 3 word(s) a lifted body reads directly, from 0x016f4ae4 to 0x016f4aec; the addresses are the ones the image generator reported as unmapped"),
    (0x016f5bd0, 0x0c, "data_reads_016f5bd0", True,
     "the 3 word(s) a lifted body reads directly, from 0x016f5bd0 to 0x016f5bd8; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebba4, 0x50, "rdata_block_013ebba4", False,
     "the block of data the guest reads at 0x013ebbc8; it is bounded by the text and the code pointer runs around it"),
    (0x013ebba0, 0x04, "rdata_reads_013ebba0", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebba0 to 0x013ebba0; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebc00, 0x04, "rdata_reads_013ebc00", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebc00 to 0x013ebc00; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebc08, 0x04, "rdata_reads_013ebc08", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebc08 to 0x013ebc08; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebc10, 0x04, "rdata_reads_013ebc10", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebc10 to 0x013ebc10; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebc24, 0x04, "rdata_reads_013ebc24", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebc24 to 0x013ebc24; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebd24, 0x04, "rdata_reads_013ebd24", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebd24 to 0x013ebd24; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebd30, 0x04, "rdata_reads_013ebd30", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ebd30 to 0x013ebd30; the addresses are the ones the image generator reported as unmapped"),
    (0x013ec2dc, 0x04, "rdata_reads_013ec2dc", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ec2dc to 0x013ec2dc; the addresses are the ones the image generator reported as unmapped"),
    (0x013ec310, 0x04, "rdata_reads_013ec310", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ec310 to 0x013ec310; the addresses are the ones the image generator reported as unmapped"),
    (0x013ec318, 0x04, "rdata_reads_013ec318", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ec318 to 0x013ec318; the addresses are the ones the image generator reported as unmapped"),
    (0x013ec320, 0x04, "rdata_reads_013ec320", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ec320 to 0x013ec320; the addresses are the ones the image generator reported as unmapped"),
    (0x013ec334, 0x04, "rdata_reads_013ec334", False,
     "the 1 word(s) a lifted body reads directly, from 0x013ec334 to 0x013ec334; the addresses are the ones the image generator reported as unmapped"),
    (0x013ebcf0, 0x34, "rdata_block_013ebcf4", False,
     "the block of data the guest reads at 0x013ebd18 from 0x0121ff70; it is bounded by the text and the code pointer runs around it"),
    (0x015d2000, 0x1000, "data_page_015d2000", True,
     "the loader-zeroed page the guest writes at 0x015d2058 from 0x00401712; the file holds no bytes here, so the page is zero-filled at load time"),
    (0x013ec268, 0x34, "rdata_block_013ec26c", False,
     "the block of data the guest reads at 0x013ec290 from 0x01221b50; it is bounded by the text and the code pointer runs around it"),
    (0x013ec4d8, 0x40, "rdata_strings_013ec4d8", False,
     "the string table the guest reads at 0x013ec4dc from 0x00932ed6; it covers every adjacent word of text and stops at the first word that is not"),
    (0x013ec51c, 0x48, "rdata_block_013ec51c", False,
     "the block of data the guest reads at 0x013ec540 from 0x01223850; it is bounded by the text and the code pointer runs around it"),
]

# Offsets inside the PE32 optional header that __cinit's probe reads. EAX holds
# the PE signature address, so [EAX+0x74] is optional+0x5c and [EAX+0xe8] is
# optional+0xd0, the CLR runtime directory's VirtualAddress.
STACK_COMMIT_OFFSET = 0x5c
CLR_DIRECTORY_OFFSET = 0xd0


def classify(pe, address, size):
    """Return "raw", "bss" or "none" for one window in the parsed PE."""

    _, image_base, sections = pe
    rva = address - image_base
    for _, section_rva, virtual_size, _, raw_size in sections:
        if section_rva <= rva < section_rva + virtual_size:
            if rva + size > section_rva + raw_size:
                return "bss"
            return "raw"
    return "none"


def pe_header_window(pe, address, size):
    image, image_base, _ = pe
    if address != image_base:
        raise ValueError(
            "the PE header window must start at the image base "
            f"0x{image_base:08x}")
    if size > len(image):
        raise ValueError("the PE header window exceeds the file")
    data = bytes(image[:size])
    e_lfanew = int.from_bytes(data[0x3c:0x40], "little")
    if data[0:2] != b"MZ" or e_lfanew + 0x20 > size:
        raise ValueError("the PE header window is not a valid DOS header")
    if data[e_lfanew:e_lfanew + 4] != b"PE\0\0":
        raise ValueError("the PE header window has no NT signature")
    return data


def app_type_probe_flag(pe):
    """What __cinit computes and stores at 0x016f2628 for this PE.

    The PE32 branch accepts an image whose stack commit exceeds 0xe and whose
    CLR runtime directory declares a nonzero virtual address, then stores that
    single bit.
    """

    image, _, _ = pe
    e_lfanew = int.from_bytes(image[0x3c:0x40], "little")
    optional = e_lfanew + 0x18
    magic = int.from_bytes(image[optional:optional + 2], "little")
    if magic != 0x10b:
        raise ValueError(
            f"the image is not PE32 (magic 0x{magic:04x}), so the probe takes "
            "the other branch and this model would be wrong")
    stack_commit = int.from_bytes(
        image[optional + STACK_COMMIT_OFFSET:
              optional + STACK_COMMIT_OFFSET + 4], "little")
    if stack_commit <= 0xe:
        return 0
    clr_directory = int.from_bytes(
        image[optional + CLR_DIRECTORY_OFFSET:
              optional + CLR_DIRECTORY_OFFSET + 4], "little")
    return 1 if clr_directory != 0 else 0


def closure_addresses(closure_directories):
    """Absolute guest addresses the generated closure sources access.

    ``memory.load32(0x...)`` operands are memory accesses and must be mapped.
    The runtime helpers that take an address as an argument (``MOVSS`` load,
    ``FLD``/``FSTP``, the x87 compare and the SSE memory forms) are memory
    accesses too, so a literal in image range inside a ``batch_guest_*`` call
    counts as one. An immediate the next statement pushes (``PUSH imm32``) is an
    argument, and the callee decides whether it is dereferenced, so those are
    returned separately as ``pushed``.
    """

    memory_pattern = re.compile(
        r"memory\.(?:load|store)(?:8|16|32)\((0x[0-9a-f]{8})u")
    helper_literal = re.compile(r"0x([0-9a-f]{8})u")
    # Only these helpers take a guest memory address as an argument; other
    # batch_guest_* calls carry code addresses (dispatch targets, body notes).
    address_helpers = (
        "batch_guest_movss_load(",
        "batch_guest_movss_store(",
        "batch_guest_fld32(",
        "batch_guest_fld64(",
        "batch_guest_fst32(",
        "batch_guest_fstp32(",
        "batch_guest_fstp64(",
        "batch_guest_fistp64(",
        "batch_guest_fild32(",
        "batch_guest_fild64(",
        "batch_guest_x87_float32_arithmetic(",
        "batch_guest_x87_compare_memory(",
        "batch_guest_ucomiss_memory(",
        "batch_guest_xorps_memory(",
        "batch_guest_cvttss2si_memory(",
        "batch_guest_cvtsi2ss_memory(",
    )
    push_pattern = re.compile(
        r"^\s+t\d+a = (0x[0-9a-f]{8})u;\n"
        r"\s+state\.regs\[4\] = static_cast<std::uint32_t>\(\s*"
        r"state\.regs\[4\] - 4u\);",
        re.MULTILINE)
    addresses = {}
    pushed = {}
    for directory in closure_directories:
        for path in sorted(directory.glob("spore_*.cpp")):
            text = path.read_text(encoding="utf-8")
            for match in memory_pattern.finditer(text):
                address = int(match.group(1), 16)
                # Reading the null page is a real fault on Windows too, so the
                # guest keeps it unmapped and fails closed if it is ever reached.
                if address == 0:
                    continue
                addresses.setdefault(address, set()).add(path.stem)
            for line in text.splitlines():
                if not any(name in line for name in address_helpers):
                    continue
                for match in helper_literal.finditer(line):
                    address = int(match.group(1), 16)
                    if not (0x00400000 <= address < 0x02000000):
                        continue
                    addresses.setdefault(address, set()).add(path.stem)
            for match in push_pattern.finditer(text):
                value = int(match.group(1), 16)
                if 0x00400000 <= value < 0x80000000:
                    pushed.setdefault(value, set()).add(path.stem)
    return addresses, pushed


def import_slots(pe):
    """Return (slot, symbol) for every import cell the image maps, in order.

    The slots come from the PE import table, so a slot is only listed when the
    original image names it. ``_adjust_fdiv`` is a data import: the loader
    stores the address of the variable, not of code, so its slot keeps the file
    bytes instead of receiving a trampoline.
    """

    window = next(item for item in WINDOWS if item[2] == "import_cells")
    base, size = window[0], window[1]
    imports = lifter.parse_pe_iat_imports(pe)
    data_imports = {"MSVCR90.dll!_adjust_fdiv"}
    slots = []
    for address in range(base, base + size, 4):
        symbol = imports.get(address)
        if symbol is None:
            continue
        if symbol in data_imports:
            continue
        slots.append((address, symbol))
    if not slots:
        raise SystemExit("no import slot inside the mapped import window")
    return slots


def hex_literal_lines(blob, width=120):
    """Return the blob as quoted hex string literals, one per line.

    The caller concatenates the literals, so the result must decode back to
    exactly ``blob``: the transport is text only, and a decoder that receives a
    short or padded string would map bytes the region table never described.
    """

    text = blob.hex()
    if len(text) != len(blob) * 2:
        raise SystemExit("hex transport is not two characters per byte")
    return [f'    "{text[start:start + width]}"'
            for start in range(0, len(text), width)]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--closure", type=Path, required=True, nargs="+",
                        help="directories holding the generated sources")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()

    reference_hash = lifter.sha256_file(args.reference)
    if reference_hash != lifter.EXPECTED_SHA256:
        parser.error("reference PE hash does not match the verified build")
    reference = lifter.parse_pe(args.reference)
    candidate = lifter.parse_pe(args.candidate)

    windows = []
    blob = bytearray()
    for address, size, name, writable, reason in WINDOWS:
        # The headers sit before the first section, so they are validated by
        # pe_header_window instead of the section table.
        if name == "pe_headers":
            kind = "raw"
        else:
            kind = classify(reference, address, size)
        if kind == "none":
            parser.error(
                f"window {name} at 0x{address:08x} is outside every section")
        if name != "pe_headers" and kind != classify(candidate, address, size):
            parser.error(f"window {name} differs between the two PE builds")
        if kind == "raw":
            if name == "pe_headers":
                data = pe_header_window(reference, address, size)
            else:
                _, _, data = lifter.read_pe_bytes(reference, address, size)
                _, _, other = lifter.read_pe_bytes(candidate, address, size)
                if data != other:
                    parser.error(
                        f"window {name} bytes differ between the two builds")
        else:
            data = bytes(size)
        windows.append({
            "address": address,
            "offset": len(blob),
            "size": size,
            "name": name,
            "writable": writable,
            "source": kind,
            "reason": reason,
        })
        blob += data

    used, pushed = closure_addresses(args.closure)
    if not used:
        parser.error("no absolute guest address was found in the closure")
    unmapped = [
        (address, sorted(names)) for address, names in sorted(used.items())
        if not any(item["address"] <= address
                   and address + 4 <= item["address"] + item["size"]
                   for item in windows)
    ]
    if unmapped:
        detail = ", ".join(
            f"0x{address:08x} ({'/'.join(names)})"
            for address, names in unmapped)
        parser.error(f"the closure reads unmapped guest addresses: {detail}")

    probe_flag = app_type_probe_flag(reference)
    slots = import_slots(reference)
    literal_slots = "\n".join(
        f'    {{0x{address:08x}u, "{symbol}"}},'
        for address, symbol in slots)
    # The image travels as hex text and is decoded once at startup. A byte-array
    # literal costs about seven characters per byte and dominated compile time
    # once the initializer table pushed the image past a hundred kilobytes; hex is
    # two, needs no alphabet table to verify, and works with both `cl` and `clang`
    # (`.incbin` is not available to MSVC).
    literals = "\n".join(hex_literal_lines(blob))
    regions = "\n".join(
        f"    {{0x{item['address']:08x}u, 0x{item['offset']:08x}u, "
        f"0x{item['size']:08x}u, {'true' if item['writable'] else 'false'}}},"
        for item in windows
    )
    header = "\n".join([
        "#pragma once",
        "#include <array>",
        "#include <cstdint>",
        "#include <string_view>",
        "",
        "// One flat copy of every guest window the CRT initializers touch;",
        "// each region below indexes into it.",
        "struct BatchGuestImageRegion {",
        "    std::uint32_t address;",
        "    std::uint32_t offset;",
        "    std::uint32_t size;",
        "    bool writable;",
        "};",
        "",
        f"inline constexpr std::uint32_t kBatchGuestImageBytes = "
        f"0x{len(blob):08x}u;",
        "// The same bytes as hex text, two characters per byte.",
        "inline constexpr std::string_view kBatchGuestImageHex =",
        literals + ";",
        "",
        "inline constexpr BatchGuestImageRegion kBatchGuestImageRegions[]{",
        regions,
        "};",
        "",
        f"inline constexpr std::uint32_t kExpectAppTypeProbeFlag = "
        f"{probe_flag}u;",
        "",
        "// The loader resolves every import slot to an address before the first",
        "// instruction runs. Slots whose imported name is a data variable keep",
        "// the file bytes: no verified address exists for them, and the closure",
        "// only copies their contents.",
        f"inline constexpr std::uint32_t kGuestImportSlotCount = "
        f"{len(slots)}u;",
        "inline constexpr BatchImportSlot kGuestImportSlots[]{",
        literal_slots,
        "};",
    ]) + "\n"

    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "initterm_guest_image.hpp").write_text(
        header, encoding="utf-8")
    (args.output / "manifest.json").write_text(json.dumps({
        "reference_sha256": reference_hash,
        "candidate_sha256": lifter.sha256_file(args.candidate),
        "image_bytes": len(blob),
        "regions": windows,
        "closure_addresses": [f"0x{address:08x}" for address in sorted(used)],
        "pushed_addresses": [f"0x{address:08x}" for address in sorted(pushed)],
        "app_type_probe_flag": probe_flag,
        "import_slots": [
            {"address": f"0x{address:08x}", "symbol": symbol}
            for address, symbol in slots
        ],
    }, indent=2) + "\n", encoding="utf-8")
    raw_count = sum(1 for item in windows if item["source"] == "raw")
    print(f"generated guest image: {len(windows)} regions "
          f"({raw_count} from the PE, {len(windows) - raw_count} "
          f"zero-filled), {len(blob)} bytes, {len(used)} closure addresses "
          f"covered, app_type_flag={probe_flag}")


if __name__ == "__main__":
    main()
