# Expanded Candidate Validation Status

## Scope

This document records evidence from Unicorn emulation of exact PE32 x86 bodies and a native
Windows x86 comparison against reconstructed C++ candidates. It is not evidence of Android game
boot or native gameplay integration.

## Lower-bound candidate

- PE RVA: `0x22430`
- PE VA: `0x422430`
- Body size: 122 bytes
- Exact-function bytes SHA-256: `9e462a2ba95704cea43e451fb223991e23e9167f9c0d5e74d96074a2fc406947`

The `lower-bound-emulation-expanded.json` report contains 142 cases and `failed: 0`.

Coverage includes:

- empty arrays;
- zero, first, middle, absent and maximum keys;
- duplicate keys;
- signed boundary values represented as 32-bit unsigned values;
- small, medium and large arrays;
- deterministic random arrays of up to 256 records.

The independent oracle is an unsigned-style lower-bound over the first `uint32_t` of each 12-byte
record. The exact x86 return pointer matched the oracle index in every case.

## Array candidate

- PE RVA: `0xD58BE0`
- PE VA: `0x1158BE0`
- Body size: 125 bytes
- Exact-function bytes SHA-256: `b6cce7942199ded10ee6c417247d8dd505897c9ce31c29720aeb6163c1ed11cb`

The `array-kernel-emulation-expanded.json` report contains 13 cases and `failed: 0` against a
float32 oracle. That check only compared the requested output elements; it did not inspect memory
outside the logical destination range.

Coverage includes:

- counts 0, 1, 3, 4, 5, 7, 9, 16, 64 and 257;
- ordinary random float32 vectors;
- zero and signed zero;
- positive and negative subnormals;
- maximum finite float32 values;
- positive and negative infinity;
- NaN values;
- comparison by float32 bit pattern rather than floating equality.

The exact x86 destination bits matched the independent float32 oracle in the reported elements.
The later native x86 differential test found that a zero count still writes four elements to
`destination[-4]` through `destination[-1]`; therefore the old zero-count result is not evidence
of safe empty-array behavior, and zero count is excluded from the candidate-equivalence pass
until caller evidence establishes its validity.

## Native Windows x86 candidate comparison

Run `tools\run_x86_candidate_differential.ps1`. The script requires the known reference PE
SHA-256 (`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`) and compiles a
temporary x86 harness with Visual Studio. The harness independently checks the exact byte
sequences at both RVAs before executing them, then compares the original x86 routines with
`lifted_lower_bound.cpp` and `lifted_array_kernel.cpp`.

- Lower-bound: 146 passing cases, including empty input, duplicates, unsigned boundary keys,
  and deterministic arrays up to 256 records.
- Array kernel: 12 passing cases with nonzero counts, comparing every destination bit and
  checking guard regions and source immutability.
- Boundary probe: with count zero, the original writes four elements before the supplied
  destination while the reconstructed candidate does not. This is reported as an observed
  mismatch, not counted as an equivalence pass; do not call the original with zero until its
  caller contract is known.

These candidates are hand-reconstructed C++, not generated output from the static lifter. The
test validates semantics on Windows x86 only; it does not execute these routines on ARM64 or
connect them to the Spore boot path.

## Caller evidence for lower-bound

Direct calls are present at:

- source VA `0x412B7B`;
- source VA `0x412B92`;
- source VA `0x461557`.

The caller at `0x461557` pushes four stack values and cleans `0x10` bytes:

```text
push byte-derived    ; extra value, not read by the callee at 0x422430
push ecx             ; candidate key pointer, becomes [ebp + 0x10]
push edx             ; candidate end pointer, becomes [ebp + 0x0c]
push eax             ; candidate begin pointer, becomes [ebp + 0x08]
call 0x422430
```

The callee disassembly reads only its effective first three arguments and returns with `ret`,
not `ret 4`, `ret 8`, or `ret 12`. The extra fourth value pushed by this caller therefore does
not change the confirmed lower-bound signature. Its purpose at the caller remains unconfirmed.

## Remaining blockers

- Names and owner types are not recovered.
- The array candidate has no confirmed caller.
- The lower-bound and array candidates still need automated x86-versus-ARM64
  bit-for-bit comparison.
- Neither candidate is connected to the executable boot path.
- No Android Win32, CRT, D3D, audio, filesystem or input adapter exists yet.

## Separate generated-lift x86 differential check

- `tools/run_x86_lift_differential.ps1` verifies the reference PE SHA-256 and
  the exact 23 bytes at VA `0x0091E020`, then compiles the existing generated
  C++ lift for Windows x86 and executes both it and the original x86 function.
- The comparison passed 674 cases on the Windows x86 host, including null and
  non-null object targets, boundary values, and deterministic randomized
  arguments. The test-only memory adapter is isolated in
  `tools/x86_lift_differential/`.
- This is a semantics check of the existing generated lift, not a pcrecomp
  differential test, not an ARM64 execution test, and not a test of the
  lower-bound/array candidates or the Spore runtime.

## Physical ARM64 validation

The connected device reported ABI `arm64-v8a`, Android release 14 and kernel architecture
`aarch64`. The rebuilt `lifting_harness_arm64`, `lifted_array_kernel_arm64` and
`lifted_lower_bound_arm64` ELF binaries were pushed and executed successfully.

The independent device report is stored in `arm64-physical-validation.json`:

- lower-bound: 8 device cases, 0 failures;
- lower-bound keys matched indices 0, 1, 1, 2, 2, 3, 4 and 4;
- array kernel: device checksum `4AEFF165`;
- independent Python checksum: `4AEFF165`.

This proves AArch64 toolchain and harness execution on the physical device. It does not prove
that the lifted routines are connected to the original game bootstrap or replace the x86 code.
