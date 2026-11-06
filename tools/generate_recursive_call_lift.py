import argparse
import hashlib
import struct
from pathlib import Path


EXPECTED_SHA256 = "6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b"
FUNCTION_VA = 0x006237A0
FUNCTION_SIZE = 0x21
EXPECTED_CODE = bytes.fromhex(
    "56 8b f1 8b 4e 30 85 c9 74 0e e8 f1 ff ff ff "
    "8b c8 8b 46 34 03 c1 5e c3 8b 46 34 33 c9 "
    "03 c1 5e c3"
)


def _read_u16(data: bytes, offset: int) -> int:
    if offset < 0 or offset + 2 > len(data):
        raise ValueError("PE field lies outside the file")
    return struct.unpack_from("<H", data, offset)[0]


def _read_u32(data: bytes, offset: int) -> int:
    if offset < 0 or offset + 4 > len(data):
        raise ValueError("PE field lies outside the file")
    return struct.unpack_from("<I", data, offset)[0]


def extract_function(pe_path: Path) -> bytes:
    data = pe_path.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != EXPECTED_SHA256:
        raise ValueError(f"unexpected SporeApp.exe SHA-256: {digest}")
    if data[:2] != b"MZ":
        raise ValueError("reference file has no DOS header")

    pe_offset = _read_u32(data, 0x3C)
    if _read_u32(data, pe_offset) != 0x00004550:
        raise ValueError("reference file has no PE signature")
    if _read_u16(data, pe_offset + 4) != 0x014C:
        raise ValueError("reference PE is not x86")

    section_count = _read_u16(data, pe_offset + 6)
    optional_size = _read_u16(data, pe_offset + 20)
    optional_offset = pe_offset + 24
    if _read_u16(data, optional_offset) != 0x010B:
        raise ValueError("reference PE is not PE32")
    image_base = _read_u32(data, optional_offset + 28)
    if image_base != 0x00400000 or FUNCTION_VA < image_base:
        raise ValueError("unexpected PE image base")

    rva = FUNCTION_VA - image_base
    section_table = optional_offset + optional_size
    for index in range(section_count):
        section = section_table + index * 40
        virtual_size = _read_u32(data, section + 8)
        virtual_address = _read_u32(data, section + 12)
        raw_size = _read_u32(data, section + 16)
        raw_offset = _read_u32(data, section + 20)
        if rva < virtual_address or rva - virtual_address >= max(virtual_size, raw_size):
            continue
        within_section = rva - virtual_address
        if within_section + FUNCTION_SIZE > raw_size:
            raise ValueError("function body is not fully file-backed")
        start = raw_offset + within_section
        code = data[start : start + FUNCTION_SIZE]
        if len(code) != FUNCTION_SIZE or code != EXPECTED_CODE:
            raise ValueError("function bytes differ from the reviewed x86 body")
        call_offset = 0x0A
        if code[call_offset] != 0xE8:
            raise ValueError("expected direct CALL opcode was not found")
        displacement = struct.unpack_from("<i", code, call_offset + 1)[0]
        call_target = FUNCTION_VA + call_offset + 5 + displacement
        if call_target != FUNCTION_VA:
            raise ValueError(f"unexpected recursive CALL target: 0x{call_target:08x}")
        return code
    raise ValueError("function VA is not mapped by a PE section")


def emit_source() -> str:
    return """#include "../../x86_lift_differential/BatchStaticLiftRuntime.hpp"

BatchLiftStatus spore_lift_006237a0(
    BatchLiftMemory& memory,
    BatchLiftState& state) {
    std::uint32_t internal_call_depth{};
    for (;;) {
        switch (state.eip) {
        case 0x006237a0u:
            if (!batch_guest_push32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.regs[6] = state.regs[1];
            state.eip = 0x006237a3u;
            break;
        case 0x006237a3u:
            if (!memory.load32(state.regs[6] + 0x30u, state.regs[1])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237a6u;
            break;
        case 0x006237a6u:
            batch_set_logic_flags(state, state.regs[1], 32u);
            state.eip = 0x006237a8u;
            break;
        case 0x006237a8u:
            state.eip = (state.eflags & (1u << 6u)) != 0u
                ? 0x006237b8u : 0x006237aau;
            break;
        case 0x006237aau:
            if (!batch_guest_call32(
                    memory, state, 0x006237a0u, 0x006237afu)) {
                return BatchLiftStatus::invalid_memory;
            }
            ++internal_call_depth;
            break;
        case 0x006237afu:
            state.regs[1] = state.regs[0];
            state.eip = 0x006237b1u;
            break;
        case 0x006237b1u:
            if (!memory.load32(state.regs[6] + 0x34u, state.regs[0])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237b4u;
            break;
        case 0x006237b4u:
            state.regs[0] = batch_guest_add32(
                state, state.regs[0], state.regs[1]);
            state.eip = 0x006237b6u;
            break;
        case 0x006237b6u:
            if (!batch_guest_pop32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237b7u;
            break;
        case 0x006237b7u:
            if (!batch_guest_return32(memory, state)) {
                return BatchLiftStatus::invalid_memory;
            }
            if (internal_call_depth == 0u) {
                return BatchLiftStatus::returned;
            }
            --internal_call_depth;
            break;
        case 0x006237b8u:
            if (!memory.load32(state.regs[6] + 0x34u, state.regs[0])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237bbu;
            break;
        case 0x006237bbu:
            state.regs[1] = 0u;
            batch_set_logic_flags(state, 0u, 32u);
            state.eip = 0x006237bdu;
            break;
        case 0x006237bdu:
            state.regs[0] = batch_guest_add32(
                state, state.regs[0], state.regs[1]);
            state.eip = 0x006237bfu;
            break;
        case 0x006237bfu:
            if (!batch_guest_pop32(memory, state, state.regs[6])) {
                return BatchLiftStatus::invalid_memory;
            }
            state.eip = 0x006237c0u;
            break;
        case 0x006237c0u:
            if (!batch_guest_return32(memory, state)) {
                return BatchLiftStatus::invalid_memory;
            }
            if (internal_call_depth == 0u) {
                return BatchLiftStatus::returned;
            }
            --internal_call_depth;
            break;
        default:
            return BatchLiftStatus::invalid_control_flow;
        }
    }
}
"""


def emit_bytes_header() -> str:
    byte_lines = []
    for offset in range(0, len(EXPECTED_CODE), 8):
        byte_lines.append(
            "    " + ", ".join(f"0x{byte:02x}u" for byte in EXPECTED_CODE[offset : offset + 8])
        )
    return (
        "#pragma once\n\n"
        "#include <array>\n"
        "#include <cstdint>\n\n"
        f"inline constexpr std::uint32_t kSporeFunctionVa = 0x{FUNCTION_VA:08x}u;\n"
        f"inline constexpr std::array<std::uint8_t, {FUNCTION_SIZE}> "
        "kSporeFunctionBytes = {\n"
        + ",\n".join(byte_lines)
        + "\n};\n"
    )


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate the reviewed FUN_006237a0 recursive-call lift"
    )
    parser.add_argument(
        "--pe",
        type=Path,
        default=Path(r"C:\SporeAnalysis\SporeApp.exe"),
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path(__file__).parent
        / "call_chain_lift"
        / "generated"
        / "spore_006237a0_arm64.cpp",
    )
    parser.add_argument(
        "--byte-header",
        type=Path,
        default=Path(__file__).parent
        / "call_chain_lift"
        / "generated"
        / "spore_006237a0_bytes.hpp",
    )
    args = parser.parse_args()
    extract_function(args.pe)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(emit_source(), encoding="utf-8", newline="\n")
    args.byte_header.parent.mkdir(parents=True, exist_ok=True)
    args.byte_header.write_text(emit_bytes_header(), encoding="utf-8", newline="\n")
    print(f"reference_sha256={EXPECTED_SHA256}")
    print(f"function_va=0x{FUNCTION_VA:08x} bytes={FUNCTION_SIZE}")
    print("direct_call=0x006237aa->0x006237a0")
    print(f"generated={args.output.resolve()}")
    print(f"verified_bytes_header={args.byte_header.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
