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
    (0x013cc300, 0x60, "import_cells", True,
     "the CRT import slots, which the loader rewrites with resolved addresses"),
    (0x013cc80c, 0x400, "cpp_initializer_head", False,
     "the first 256 slots of the C++ initializer table _initterm walks"),
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
    (0x015d0690, 0x04, "initializer_state", True,
     "the CRT state word the fifth C++ initializer toggles"),
    (0x01667c00, 0x18, "initializer_critical_section", True,
     "the loader-zeroed critical section the first initializer initializes"),
    (0x016f4e98, 0x18, "initializer_critical_section_2", True,
     "the loader-zeroed critical section the fourth initializer initializes"),
    (0x016f2600, 0x60, "crt_globals", True,
     "_fmode/_commode defaults, the app-type flag and the app-type address"),
    (0x0171e740, 0x30, "startup_state", True,
     "startup lock, startup state and the encoded null pointers"),
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


def closure_addresses(closure_directory):
    """Absolute guest addresses the generated closure sources access.

    ``memory.load32(0x...)`` operands are memory accesses and must be mapped.
    An immediate the next statement pushes (``PUSH imm32``) is an argument, and
    the callee decides whether it is dereferenced, so those are returned
    separately as ``pushed``.
    """

    memory_pattern = re.compile(
        r"memory\.(?:load|store)(?:8|16|32)\((0x[0-9a-f]{8})u")
    push_pattern = re.compile(
        r"^\s+t\d+a = (0x[0-9a-f]{8})u;\n"
        r"\s+state\.regs\[4\] = static_cast<std::uint32_t>\(\s*"
        r"state\.regs\[4\] - 4u\);",
        re.MULTILINE)
    addresses = {}
    pushed = {}
    for path in sorted(closure_directory.glob("spore_*.cpp")):
        text = path.read_text(encoding="utf-8")
        for match in memory_pattern.finditer(text):
            addresses.setdefault(int(match.group(1), 16), set()).add(path.stem)
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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--reference", type=Path, required=True)
    parser.add_argument("--candidate", type=Path, required=True)
    parser.add_argument("--closure", type=Path, required=True,
                        help="directory holding the generated closure sources")
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
    literals = "\n    ".join(
        ", ".join(f"0x{value:02x}u" for value in blob[start:start + 12]) + ","
        for start in range(0, len(blob), 12))
    regions = "\n".join(
        f"    {{0x{item['address']:08x}u, 0x{item['offset']:08x}u, "
        f"0x{item['size']:08x}u, {'true' if item['writable'] else 'false'}}},"
        for item in windows
    )
    header = "\n".join([
        "#pragma once",
        "#include <array>",
        "#include <cstdint>",
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
        "inline constexpr std::array<std::uint8_t, kBatchGuestImageBytes> "
        "kBatchGuestImage{",
        f"    {literals}",
        "};",
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
