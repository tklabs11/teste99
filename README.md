# Spore ARM64 static recompilation

The target is a native ARM64 port based on the user's own Spore PC installation:

1. Inspect the original x86 executable and its DLLs to discover functions,
   control flow, imports, and data dependencies.
2. Translate selected reachable x86 functions into portable C/C++ and validate
   their behavior against the original executable.
3. Compile the translated code and a purpose-built compatibility runtime with
   the Android NDK.
4. Use SDL2 for Android windowing, input, and audio. Spore's Direct3D 9 calls
   need a compatible D3D9 interface; DXVK-native is the planned D3D9-to-Vulkan
   backend.
5. Integrate and test small connected game paths on the ARM64 device before
   expanding coverage.

The Skyrim_Android project is an architectural reference for static
recompilation, runtime shims, SDL2, and D3D9-to-Vulkan. Its game-specific code
and data are not part of this project and are not directly reusable for Spore.

## Current status

### REA/Ghidra integration diagnosis — 2026-11-03

- The previous timeout occurs primarily during cold Ghidra startup and
  auto-analysis, not after the Headless bridge is ready.
- The logged cold analysis completed in 921 seconds. It reached
  `AutoAnalysisManager` completion and then started the REA bridge.
- REA imports the executable into an ephemeral temporary project and reports
  `import_mode: ephemeral-source-immutable`. The process used:
  `AnalyzeHeadless <temporary>/project rea-project -import
  <temporary>/target-6aec99cb2dc7.exe -readOnly -deleteProject`.
- Active Ghidra heap was configured at `-Xmx2G`. Observed private memory was
  about 1.82 GB and working set about 1.81 GB; no memory exhaustion or Java
  out-of-memory error was observed in the log.
- The startup deadline was raised to 1200000 ms because the default 330-second
  deadline was below the measured 921-second cold analysis.
- After analysis completed, the same persistent bridge session served:
  address-name lookup for `DAT_015fd918`, 470 xrefs, callers for
  `FUN_006a25a0`, and procedure metadata.
- Ghidra returned 100 direct callers of `FUN_006a25a0`, with partial callers
  coverage and 22 omitted call references explicitly reported.
- Rizin is not available as a working native executable in this installation,
  and IDA is not configured because `REA_IDA_MCP_CONFIG` is absent. No
  alternative replaced the current Ghidra environment.
- No existing Spore `.gpr` project was reused or modified. The temporary REA
  project is deleted on close, so annotations also remain session-local.

- The reference executable is
  `SPOREFILES/SporeBin/SporeApp.exe`, SHA-256
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
- Its PE import table contains 495 imports from 20 DLLs and no delay imports.
  The `d3d9.dll` entry is `Direct3DCreate9`; `d3dx9_27.dll` contributes nine
  imports. These declarations do not reveal which APIs execute at runtime, and
  D3D9 device methods are normally reached through COM vtables rather than
  separate PE imports. The expansion executable at
  `SPOREFILES/SporebinEP1/SporeApp.exe` has a different SHA-256
  (`ff8540f9d8a3b2d09b81d8e797f24e50ad5b5741ded6b819acf3692bb0a37956`) and
  is not the reference executable verified by the importer.
- The PE32 entry point is RVA `0x00de11a0` (VA `0x011e11a0`). It initializes
  the security cookie and transfers to the Visual C++ 2008 CRT startup at
  `0x011e0ee0`, which calls the application wrapper `FUN_00f48a20`. The wrapper
  runs `FUN_0092c1b0`, calls `FUN_00f48850`, then runs `FUN_005d7450`.
- `FUN_00f48850` creates the outer application object and calls
  `FUN_00f47ed0` for initialization. On success it enters `FUN_00f47580` and
  then calls `FUN_00f47700` for shutdown. The loop in `FUN_00f47580`
  repeatedly obtains the Canvas object through
  `FUN_0067dcf0` and calls its virtual slot `+0x84`, mapped by the Canvas
  vtable at `0x0141ca70` to `FUN_00848210`. That method pumps Windows messages
  with `PeekMessageW`, `TranslateMessage`, and `DispatchMessageW`, and returns
  false on `WM_QUIT`; the loop exits when this return value or the loop-state
  flag becomes false. This links the
  PE entry point to the owner/Canvas startup sequence traced below. This is
  static evidence; runtime execution remains unproven.
- `FUN_00f47ed0` begins with `SteamAPI_Init`. If it returns false, the routine
  calls `FUN_00c2e4e0` and returns false; `FUN_00f48850` then skips the main
  loop and application shutdown path. The next boolean call is to
  `FUN_00b1fbf0`, whose analyzed body returns `1`; current static evidence does
  not establish it as another failing startup gate.
- The reference PE's complete import table has exactly three imports from
  `steam_api.dll`: `SteamAPI_Init`, `SteamAPI_Shutdown`, and `SteamApps`, with
  no delay imports. The `SteamAPI_Init` thunk is at `0x006b4f20`, and the boot
  function calls it at `0x00f47ed9`. `SteamAPI_Shutdown` is called by
  `FUN_00f47700` during the application's shutdown path. `SteamApps` is called
  from `FUN_006866f0` at `0x00686c55`; its reachability from the boot sequence
  is not established by the resolved direct-call graph.
- The Android app's `app/src/main` sources contain no `steam_api.dll` or
  `SteamAPI_Init` integration. The static branch above is real, but it does not
  establish that a Steam client is required for this Spore build. The user has
  confirmed that their PC copy launches without opening the Steam client.
  Whether its local `steam_api.dll` initializes independently, or behaves
  differently from the reference import assumptions, has not been observed.
  Treat the return value as an unresolved runtime detail, not a confirmed
  Android boot blocker; do not add a shim based on the function name alone.
- After that gate, startup queries the registry value paths
  `HKEY_LOCAL_MACHINE\Software\Electronic Arts\SPORE\PlayerDir` and
  `HKEY_LOCAL_MACHINE\Software\Electronic Arts\SPORE\AppDir`, then passes the
  resulting buffers to the application object's virtual method at `+0x0c`.
  `FUN_006aba80` parses the root hive; `FUN_006ab840` opens the key with
  `RegOpenKeyExW`, queries its final path component with `RegQueryValueExW`,
  accepts `REG_DWORD` or `REG_SZ`, and closes the key. The startup code does
  not check these helper return values before continuing, so the exact
  fallback behavior when either registry value is absent remains unknown.
- The same application object's virtual method at `+0x10` is then called with
  `param_1` and `L"Spore_DDFList.txt"`. A false result enters cleanup and
  returns failure from `FUN_00f47ed0`, so this virtual initialization call is a
  pre-loop boot requirement. The caller at `0xf48068` dispatches through the
  object's vtable slot `+0x10` at `0xf48076`; the constructor for that object
  is `FUN_007e7630`, and its vtable at `0x1413ae0` points from slot `+0x10`
  (`0x1413af0`) to `0x7e8ba0`. The method at that target is not a
  Ghidra-defined function, but its code was decoded directly from the
  executable through its return at `0x7e92fa`. It stores the first argument
  in `DAT_015fd920` and performs broad application/configuration initialization.
  In the inspected body, the second argument—the DDF filename—is not read or
  passed to a file-opening call. Therefore the call's false return does **not**
  establish that `Spore_DDFList.txt` was resolved or loaded; the role of that
  string remains unknown.
- The same object's virtual method at `+0x0c` is `FUN_007e93d0`. It copies the
  two registry-derived directory strings into object fields at offsets
  `+0x138` and `+0x148`, appending a backslash to each. This establishes
  directory-path setup, but not how a subsequent resource lookup uses those
  paths.
- A recursive filename search found no loose `*DDF*` file in the installed
  game tree. The 23 DBPF package indices were then scanned: 154,576 entries
  across 90 TGI types. Lowercase FNV-1 and FNV-1a candidates for
  `Spore_DDFList.txt`, its extensionless basename, `DDFList`, `DDFMap`,
  `DDFMap.txt`, and several plausible relative paths produced no match in any
  TGI field. Decoded resources from text-like types `0x024A0E52` and
  `0x0248F226` also contained no literal `Spore_DDFList`, `DDFList`, or
  `Terrain/TerrainSystem` marker. These are bounded searches, not evidence that
  the file/resource is absent: another naming transform, type, or external path
  may be involved.
- The DDF directory manager at `FUN_008d7960` clarifies the file-access model.
  When its enable flag is set and its `+0x1c` path passes a directory check,
  it calls `FUN_008d6ed0`, which constructs `<that directory>\DDFMap.txt`,
  checks it with `GetFileAttributesW`, and opens it through a helper that calls
  `CreateFileW`. It then enumerates entries in the directory; the enumeration
  helper `FUN_0092e730` calls `FindFirstFileW`, and entries are passed to
  `FUN_008d77a0` for DDF processing. `FUN_008d7960` does not branch on the
  map-loader call's result before continuing. This is direct filesystem access,
  not evidence of DBPF virtual-file lookup. The connection between this
  manager's `+0x1c` path and the earlier `DDFLists/%ls` construction has not
  been established, nor whether this manager is reached during startup.
- The exact `DDFLists/%ls` string has one observed reference, at `0x7e91fe`,
  within the previously decoded initialization code; no additional string
  reference was found in Ghidra's defined-string inventory. The manager
  `FUN_008d7960` has no resolved direct callers in Ghidra's completed call
  graph. Its address occurs in two initialized data slots (`0x1436758` and
  `0x1482d88`), but these data references do not establish which object or
  runtime path dispatches to it. Indirect call sites may be unresolved, so the
  current evidence cannot prove the manager is unused or reached during boot.
- After the DDF-list gate, startup creates a component tagged
  `Terrain/TerrainSystem/cTerrainSystem`, registers it, and calls its virtual
  method at `+0x0c` with the same `param_1`. A false result also aborts
  initialization. Its constructor reads the settings singleton and calls
  `FUN_0075e6d0`; the meaning of that state and the subsystem's data
  requirements remain unresolved. These gates show why resolving only the
  `SteamAPI_Init` call would not establish a working Android boot.
- Ghidra 12.1.4 resolved the `Direct3DCreate9` import thunk at `0x120bb50` to
  one code reference in `FUN_011f84b0` (`0x11f84b0`), reached from
  `FUN_0075e830` (`0x75e830`). That routine checks `D3DXCheckVersion`, queries
  adapter count, capabilities, and display mode, then tests candidate formats
  through D3D9 interface calls and initializes display parameters.
- The device-creation call is in `FUN_011f8680` (`0x11f8680`), reached from
  `FUN_0075e900` (`0x75e900`) and `FUN_0075f030` (`0x75f030`). At `0x11f874e`,
  it calls the `IDirect3D9` vtable slot at offset `0x40`, which is
  `IDirect3D9::CreateDevice`. The observed arguments are the adapter and device
  type from the function's input structure, window handle `DAT_016f658c`,
  behavior flags assembled from configuration state, presentation parameters
  at `DAT_016f8b9c`, and the output device pointer `DAT_016f89d0`. The function
  then initializes and checks the created device. This is static evidence from
  the executable, not an observation of Spore running. Ghidra reports a PDB
  reference but cannot confirm it was loaded, so these function names are
  analysis-generated labels, not original symbols.
- The boot-to-device dispatch is now connected statically. After the renderer
  setup succeeds, `FUN_00f47ed0` calls the application object's vtable slot
  `+0x1c`; the application vtable at `0x01413ae0` maps that slot to
  `FUN_007e7380`. That function gets the Graphics object from
  `FUN_0067dd50` and calls its vtable slot `+0x14`, which maps to
  `FUN_0075f030`. `FUN_0075f030` calls `FUN_011f8680`, reaching
  `IDirect3D9::CreateDevice`. `FUN_007e7380` passes `640x480` to
  `FUN_0075f030`; the actual D3D presentation parameters are assembled by that
  callee from graphics/configuration state. It checks the result; if device
  creation fails, it reports
  “Could not create the Graphics Device. Direct X is unavailable.” When the
  Graphics singleton is null, this function skips that dispatch and continues
  through a separate component check, whose fallback behavior is not yet
  understood. After the initial setup, it may also call Graphics slot `+0x18`
  (`FUN_0075e900`) with the configured dimensions, which can run another
  device-creation path. This establishes statically connected, conditional
  boot callsites and their failure handling, not that they executed or that
  device creation succeeded at runtime. Earlier Steam, registry, window, and
  renderer conditions still gate reaching this application method.
- The first `Present` dispatch found on that startup path is in
  `FUN_007e7380`, after the initial device-creation check and additional
  component/configuration checks. It calls `FUN_011f8120` with
  `PTR_DAT_015d0838`. That wrapper checks the object's field at `+0x18`: when
  null, it dispatches the created device's vtable slot `+0x44` with four null
  arguments (`IDirect3DDevice9::Present`); otherwise it dispatches slot `+0x0c`
  on the alternate presentation object (consistent with a swap chain, though
  its exact type is not established here). The same wrapper is also called by
  `FUN_00760450`. This is a static callsite before the main loop, not evidence
  that Spore reached the call or presented a visible frame. The main loop
  `FUN_00f47580` calls an unresolved virtual slot `+0x84`; its connection to
  this presentation wrapper remains unproven.
- The graphics setup path `FUN_0075f030` gets the window handle from the
  singleton at `DAT_015fd89c`, through its virtual method at vtable offset
  `0x94` (`FUN_00f67d90`). The getter returns the object's field at offset
  `0x74`; its constructor, `FUN_00849a40`, initializes that field to zero.
  `FUN_0075f030` passes the returned handle to `FUN_011f8110`, which stores it
  in `DAT_016f658c`, later supplied to `IDirect3D9::CreateDevice`. The object
  methods use the same field in Win32 window calls. The routine at
  `FUN_008490d0` changes window styles and calls `SetWindowPos`.
- The executable has `CreateWindowExW` call sites at `0x849c1d`, `0xb63cf7`,
  and `0xb63dd7`, and a `CreateWindowExA` call at `0x92b07e`. The latter
  creates the `EAClipboard` helper window; `FUN_00b63c70` creates a `BUTTON`
  control. The object constructor sets its vtable to `0x141ca70`, whose slot
  `+0x4` points to `0x849b10`; `FUN_007e67a0` constructs this object and calls
  that virtual slot. In the method body, `0x849c1d` calls `CreateWindowExW`,
  and `0x849c29` stores its return value in `this + 0x74`. The same class's
  getter at vtable slot `+0x94` returns that field, which the graphics setup
  path passes through `DAT_016f658c` to `IDirect3D9::CreateDevice`. This closes
  the static HWND handoff: the created window is the window handle supplied
  for D3D9 device creation. Static analysis does not show the call's runtime
  success or prove what SDL2 integration should replace; the Android runtime
  still needs to provide a compatible handle or adapt this window-creation
  path.
- The window class registration in this method uses `RegisterClassExW` at
  `0x849be1`. The class-name field is set to the UTF-16 string `Canvas` at
  `0x849bc7`; the returned class atom is saved in `this + 0x70` at `0x849be9`
  and then passed as the class argument to `CreateWindowExW`. The call's
  arguments are: extended style from `this + 0x88`, that class atom, a null
  title, style from `this + 0x84`, `CW_USEDEFAULT` for x/y/width/height,
  parent window from `this + 0x78`, null menu, `GetModuleHandleA(NULL)` as the
  instance, and a null creation parameter. The constructor initially sets
  `this + 0x84` to `0xc80000` and zeroes `this + 0x88` and `this + 0x78`.
  The setup path calls the virtual method in slot `+0x4` first; its vtable
  target is `0x849b10`, the method that creates the window. Later, on the same
  object, it calls the method in slot `+0x20` with flags `0xe`; that target is
  the code at `0x849d20` (referenced by vtable data at `0x141ca90`, although
  Ghidra does not currently classify it as a procedure).
  For a non-`-1` argument, the decoded flag branches build style `0xcb0000`
  from base `0x80000`, the `0x2` branch's `0xa0000` assignment, the `0x4`
  branch's `0x10000` bit, and the `0x8` branch's `0xc00000` bits. The `0x1`
  branch is not taken for `0xe`, so it adds neither `0x40000` nor extended
  style `0x300`; the setter's extended-style field is zero. This confirms the
  `CreateWindowExW` call initially receives constructor style `0xc80000` and
  extended style zero, not the later `0xcb0000` value. After setting the fields,
  the setter checks whether `this + 0x74` contains a window and, if so, calls
  `FUN_008490d0`. That routine reads the existing Win32 style bits and applies
  the fields with `SetWindowLongA`, calls `SetWindowPos` with flags `0x23`, and
  restores the window's prior visible/hidden state. The parent field is zeroed
  in the constructor, but whether it changes before creation remains
  unverified.
- The class registers `FUN_00849230` as its window procedure. It reads the
  associated object with `GetWindowLongA(hwnd, -0x15)` (`GWL_USERDATA`); if
  that pointer is null, it immediately delegates to `DefWindowProcW`. If the
  object's callback field at `+0x5c` is non-null, it first dispatches an
  internal event with ID `0x1ee100c` through virtual slot `+0x14`; a callback
  can consume the message and return its supplied result. Otherwise the
  procedure dispatches Win32 messages to internal handlers and uses
  `DefWindowProcW` for unhandled messages.
  - Window/lifecycle dispatch includes `WM_MOVE` (`0x03`), `WM_SIZE` (`0x05`),
    `WM_ACTIVATE` (`0x06`), `WM_PAINT` (`0x0f`), `WM_CLOSE` (`0x10`),
    `WM_ERASEBKGND` (`0x14`), `WM_SETTINGCHANGE` (`0x1a`),
    `WM_SYSCOLORCHANGE` (`0x1c`), `WM_GETMINMAXINFO` (`0x24`),
    `WM_DISPLAYCHANGE` (`0x7e`), `WM_NCACTIVATE` (`0x86`),
    `WM_TIMER` (`0x113`), `WM_SIZING` (`0x214`),
    `WM_ENTERSIZEMOVE` (`0x231`), and `WM_EXITSIZEMOVE` (`0x232`).
  - Keyboard dispatch includes `WM_KEYDOWN`/`WM_SYSKEYDOWN`
    (`0x100`/`0x104`), `WM_KEYUP`/`WM_SYSKEYUP` (`0x101`/`0x105`), and
    `WM_CHAR` (`0x102`). Mouse dispatch includes move, left/right/middle
    button down/up/double-click, wheel, capture-change, and mouse-leave
    messages (`0x200`-`0x20a`, `0x215`, and `0x2a3`).
  - Cursor handling includes `WM_SETCURSOR` (`0x20`) and a private message
    `0x500` that stores and sets a cursor. Private message `0x501` moves the
    cursor to client coordinates only when this window is foreground. Message
    `0x231` also sets an object flag at offset `+0x0e`.
  This is a static dispatch map, not runtime evidence. Some internal handler
  bodies and callback payloads still need tracing before designing their SDL2
  equivalents.
- The candidate path from the main message pump toward frame work is
  `FUN_00848210` -> `DispatchMessageW` -> `FUN_00849230` on `WM_PAINT`
  (`0x0f`) -> `FUN_00848340`. The paint handler calls `BeginPaint`/`EndPaint`;
  when its paint-state flag is set and its fallback brush path is not selected,
  it routes an internal event record with ID `0x1ee100a` through
  `FUN_00847e70`. The registered listener's `FUN_00f47b10` handles that event
  by calling `FUN_00f47930` and then dispatching virtual slot `+0x80` on the
  object stored at listener offset `+0x20`. `FUN_00f47930` reads the
  performance counter, advances timing state, updates several subsystem
  objects, and dispatches additional virtual update methods. This statically
  connects window paint to application tick/update work. The `+0x80` target
  has not been resolved to a concrete function, so this does not yet prove that
  paint triggers the D3D9 `Present` wrapper; event delivery and runtime
  execution also remain unobserved.
- `WM_SIZE` is handled by `FUN_00848c20`. It starts the internal flags at
  `0x2`, adds `0x8` for `SIZE_MINIMIZED` (`wParam == 1`) and zeroes the
  rectangle payload, or adds `0x4` for `SIZE_MAXIMIZED` (`wParam == 2`).
  On a restored size (`wParam == 0`), if the object's state byte at `+0x0e`
  is set, it adds `0x10` and sets the byte at `+0x0f`. It refreshes cached
  geometry through `FUN_008484f0` and dispatches internal event
  `0x1ee1003`.
  - The geometry getter is the vtable method at offset `+0x3c`, whose observed
    target is `FUN_00848190`. It calls `GetClientRect`, transforms both
    corners using `ClientToScreen`, and returns left/top and right/bottom in
    screen coordinates. `FUN_008484f0` caches these four values at object
    offsets `+0x3c` through `+0x48` when its state/callback guards allow.
    The `FUN_00848c20` assembly shows the internal payload layout: a first
    dword of flags followed by the four geometry coordinates. The flags begin
    at `0x2`; minimized adds `0x8` and zeroes the coordinates, maximized adds
    `0x4`, and restored size may add `0x10` when the move/resize state is set.
    The handler's event structure contains the ID `0x1ee1003`, the Canvas
    object, and a pointer to this payload. Although the Win32 procedure passes
    the `WM_SIZE` parameters to the handler, its body reads `wParam` to select
    those flags and does not read the `lParam` words. The event payload is
    therefore synthesized from the client geometry queried on this path, not
    copied from the Win32 `lParam`.
    A separate event-handler method, `FUN_00f47b10`, contains a branch for
    event `0x1ee1003` only when the payload's first dword is `0x22` and
    `FUN_006a25a0(&DAT_0153c178)` returns true. At the callsite, the handler
    loads the object pointer from `DAT_015fd918` into `ECX`. The lookup uses
    that object's indexed boolean array when the key is in range, otherwise
    searches its record table and returns a boolean value. The semantic name
    of the object and key is not established, so this should not yet be
    described specifically as a graphics configuration option. The other
    observed reference to `DAT_0153c178`, at `0x12e80d0`, reads the same
    address as a scalar float and stores it at `0x16357d8`; this does not
    identify the key's meaning. The handler computes width and height from
    the payload's coordinate pairs, calls virtual slot `+0x94` on the associated
    object with those dimensions, then passes the returned value and dimensions
    to `FUN_011f8070`.
    Static investigation of the separate `.data` object `DAT_01639470` found
    four references: `0x7e76e9`, `0x7e8bcd`, `0x12f1f52`, and `0x13c0150`.
    The first two instructions push the address as constructor/storage state,
    while `0x12f1f52` loads it into `ECX` and then calls constructor thunk
    `0x13c0150`; that thunk puts the address in `ECX` and jumps to
    `FUN_006a1bd0`. `FUN_007e7630`, which references the address at
    `0x7e76e9`, constructs a 0x1f0-byte object allocated by `FUN_007e8950`,
    and initializes an embedded state object through
    `FUN_007e7260(&DAT_01639470, 0x3ebeecc, 1)`.
    This establishes that `0x1639470` is runtime storage in `.data` used by a
    constructor and embedded as an object field, but neither its class name nor
    its runtime contents are established. Its image bytes are zero and it has
    no exact Ghidra data type; the zeroes are the static initialization state,
    not proof that the object remains empty at runtime. The two references in
    the `0x12f...` block and the `0x13c0150` thunk are outside recognized
    function bodies, so their callers and enclosing context remain pending.
    Linear decoding of the virtual method entry at `0x007e8ba0` found a second,
    concrete object construction path. At `0x7e8e30`, the method calls factory
    thunk `0x00f473a0` and stores its returned pointer in `[esi + 0x14]` at
    `0x7e8e56`. The factory forwards a resource/model identifier, class/object
    allocation parameters, and additional arguments to `FUN_009289f0`; its
    observed arguments at this callsite are resource identifier
    `0x013ebc58`, size `0xc8`, and four zero arguments. After storing the
    returned pointer, the method calls virtual slot `+0x04` with `ECX = object`,
    virtual slot `+0x10` with arguments `4` and `0`, setter
    `0x00883870` with the object pointer, and setter `0x0067deb0` with the same
    pointer. These are direct static observations; assigning a UI or gameplay
    type name to this object remains unsupported.
    The returned object is initialized by `FUN_00884a20` on construction. That
    constructor sets its first vtable word to `0x01427920`, initializes
    multiple fields, and invokes initialization helper `FUN_00883f10`. A second
    constructor-like function, `FUN_00884fb0`, also copies `0x01427920`. This
    establishes the concrete object class identity only as the vtable address;
    original C++ class names and field meanings remain unknown. The same
    instruction patterns are followed by additional constructors at offsets
    `0x7e8ea3` (`[esi + 0x1c]`) and `0x7e8f20` (`[esi + 0x20]`), and therefore
    this method initializes at least three object/class fields in succession.
    Linear control-flow reconstruction also recovered the normal method exit:
    the main path converges at `0x007e92e2`, restores exception state and stack,
    and reaches `RET 8` at `0x007e92fa`. This gives an observed normal-code
    extent of approximately `0x7e8ba0–0x7e92fc`, while later SEH/unwind helper
    regions can be physically adjacent and must not be assumed to belong to the
    same Ghidra function without an exact body reference.
    The virtual vtable at `0x01413ae0` is written directly by two constructors:
    `MOV [ESI], 0x1413ae0` at `0x007e7666` in `FUN_007e7630` and at
    `0x007e78ed` in `FUN_007e78d0`. The constructor `0x00884a20` has two direct
    confirmed callers: `0x007e8e4d` in the virtual setup routine and
    `0x007fc35c` in `FUN_007fc330`. Constructor `0x00884fb0` is called directly
    at `0x00885393` by `FUN_00885390`.

    The object constructed by `FUN_00884a20` assigns vtable
    `PTR_FUN_01427920` and initializes fields through offsets as Ghidra words:
    offsets `0x08..0x2c` are cleared, then fields at words `0x1d`, `0x1e`,
    `0x1f`, `0x20`, `0x21`, and `0x22` receive initialization values or zero.
    Byte offsets `0xc0`, `0xc1`, `0xc2`, `0xc3`, `0xc4`, and `0xc5` include
    enabled booleans. These observations describe generated C-like pseudocode,
    not proof of C++ field names or runtime state.

    `FUN_00884fb0` is the destructor-like cleanup routine confirmed in the
    binary: it writes the same `0x01427920` vtable, calls
    `FUN_00884ae0`, `FUN_00922130`, `FUN_00693230`, and then conditionally
    releases the object referenced by fields represented as words `0x1d/0x1e`.
    Its direct caller is `FUN_00885390` at `0x885393`; Ghidra also reports an
    internal conditional jump within this cleanup routine.

    Linear reconstruction of the virtual method owner (`0x007e8ba0`) now
    confirms three constructed service objects:
    - `owner + 0x14`: factory `0x00f473a0`, followed by virtual initialization
      through `[*object] + 0x04`, virtual call through slot `+0x10` with
      arguments `(0, 4)`, plus registration through `FUN_00883870` and setter
      `FUN_0067deb0` into `DAT_015fd890`.
    - `owner + 0x1c`: factory `0x00f473a0` result, virtual initialization
      through `[*object] + 0x04`, direct call `FUN_008de1b0`, and setter
      `FUN_0067dec0` into `DAT_015fd894`.
    - `owner + 0x20`: constructor/cleanup path at `0x007e8f17`, virtual call
      through slot `+0x00`, direct call `FUN_008d5d10`, and setter
      `FUN_0067e090` into `DAT_015fd908`.
    Ghidra independently confirmed direct calls from the linear addresses to
    the three global setters.     It has also confirmed additional references:
    `DAT_015fd890` is read by code at `0x67dcc0`, while `0x67deb4` is the setter
    store. Separate getters are
    present at `0x67dcc0`, `0x67dcd0`, and `0x67dce0`; their semantic names
    remain unknown.

### Direct-caller scan for the five decoded targets — 2026-11-03

The PE-relative mapping now uses VirtualAddress directly to image addresses
(`VA = 0x400000 + section.VirtualAddress + file_offset_within_section`) and
Capstone linear decoding only within mapped section ranges. This removes the
previous section-alignment ambiguity. A raw `E8 rel32` scan found the following
direct calls to the five pending targets:

- `FUN_008e20c0`: direct call at `0x007e8eba` from the owner setup routine.
  The constructor is reached only when allocation at `0x00926020` returned
  non-null; no allocation failure is altered in this static reconstruction.
- `FUN_008de1b0`: direct calls at `0x007e8eda` and `0x007e96e5`.
  In the setup routine, it receives `owner + 0x1c`, reads and updates
  `DAT_01667aa0`, and returns the previous value in `EAX`. This global is
  distinct from `DAT_015fd918` and does not establish which higher-level
  service the value represents.
- `FUN_006aedc0`: direct call at `0x007e8f17` from the owner setup routine,
  as the constructor selected after factory `0x00f473a0` returns non-null.
- `FUN_008d5d10`: direct calls at `0x007e649a` and `0x007e8f36`.
  The setup call receives `owner + 0x20`; the routine exchanges and updates
  `DAT_01667a88`.
- `FUN_007f18e0`: direct call only at `0x007e8f47` in the bounded scan.
  It is called after `owner + 0x20` setup and is not itself preceded by a null
  allocation check in the documented instruction sequence.

The targeted local scan confirms these calls, while not confirming indirect
dispatch targets. Additional unrecognized call bytes or calls through registers
remain excluded from direct-call conclusions.

Setter identity in the owner setup sequence is now precise:

- `owner + 0x14` passes a pointer to `FUN_0067deb0`, which stores it at
  `DAT_015fd890`.
- `owner + 0x1c` passes a pointer to `FUN_0067dec0`, which stores it at
  `DAT_015fd894`.
- `owner + 0x20` passes a pointer to `FUN_0067e090`, which stores it at
  `DAT_015fd908`.

Consequently, `DAT_015fd898` is handled by a separate setter,
`FUN_0067ded0`: direct binary calls to that routine occur at `0x007e6e40` and
`0x007e9652`. The setup routine at `0x007e8ba0` calls `FUN_0067e090`, not
`FUN_0067ded0`; therefore it does not provide direct evidence that the
`owner + 0x20` object is stored at `DAT_015fd898`. The previous ledger text
must be interpreted as an address assignment error for that field.

The same setters also participate in cleanup/destructor paths:

- `FUN_0067deb0` is called with null at `0x007e980b`, after the object at
  `owner + 0x14` is released and before that field is cleared.
- `FUN_0067dec0` is called with null at `0x007e96eb`, after release of
  `owner + 0x1c`, and before that field is cleared.
- `FUN_0067e090` is called with null at `0x007e64a0`, after virtual cleanup of
  `owner + 0x20`, and before that field is cleared. This establishes pointer
  replacement in `DAT_015fd908`, not simply object destruction.
- `FUN_0067ded0` is called with `owner + 0x18` at `0x007e6e40` and with null
  at `0x007e9652`. Thus it is associated with a separate `+0x18` object field,
  not the setup routine's `+0x20` field.

Additional decoded consumers establish a getter distinction, but counts are
high and names remain analysis-generated:

- Decoded direct calls to getter `FUN_0067dcc0` occur at 37 confirmed sites,
  including startup and graphics-related code.
- Decoded direct calls to getter `FUN_0067dcd0` occur at 19 confirmed sites.
- A direct-call scan did not find decoded direct callers of getter
  `FUN_0067dce0`; reads of it may use pointer-based dispatch, indirect calls,
  or be absent from the bounded executable section decode. This is not a claim
  that the getter is unused.

Ghidra independently resolves the direct getter/store pairs at each global:

- `DAT_015fd890`: getter `0x0067dcc0`, setter store `0x0067deb4`.
- `DAT_015fd894`: getter `0x0067dcd0`, setter store `0x0067dec4`.
- `DAT_015fd898`: getter `0x0067dce0`, setter store `0x0067ded4`.
- `DAT_015fd908`: getter `0x0067de70`, setter store `0x0067e094`.

For the tiny setter routines, Ghidra's procedure-caller inventory is incomplete:
`0x0067deb0` and `0x0067dec0` each omit two call references, and
`0x0067ded0` and `0x0067e090` omit one call reference each. The missing callers
must therefore be supplied by exact instruction-decoding or `xrefs`; the
documented cleanup/setup sites remain valid direct-call observations.

The global setter/getter families are therefore service registries, but static
analysis alone has not identified the application-level meaning of pointers
held in `DAT_015fd890`, `DAT_015fd894`, `DAT_015fd898`, `DAT_015fd908`, or
the surrounding globals. Cleanup calls with null are confirmed static writes;
they do not establish that cleanup has executed at runtime.

Singleton `DAT_015fd918`:

- Ghidra reports 470 references to this address.
- The setter is `FUN_0067e050`; decompilation proves:
  `DAT_015fd918 = param_1`.
- At `0x007e8bd2`, the proprietary setup path calls `FUN_0067e050`
  directly. The provider-decoded instruction also confirms the call target.
- The instruction write is at `0x0067e054`: `MOV [0x015fd918],EAX`.
- A focused absolute-address read check confirms direct reads in
  `FUN_0040a590` at `0x0040a827`, plus other startup/setup-like code sites.
- `FUN_0040a590` reads the singleton as a pointer and invokes the service at
  `DAT_015fd890` through `FUN_0067dcc0`, using a virtual call from the returned
  service object. This static path does not establish initialization order,
  lifecycle state or runtime non-null value.
- Exact `xrefs` to `FUN_0067e050` currently resolves only the direct call at
  `0x007e8bd2`. Additional indirect callers, aliases and unresolved call edges
  remain possible and are outside this direct-call conclusion.
- The bounded local instruction scan found eight direct reads but is not a
  complete global write inventory: the confirmed direct write is the setter at
  `0x0067e054`. Aliases, pointer arithmetic and indirect writes still require
  address-decoding coverage.
- Provider-decoded direct-read consumers confirmed independently so far:
  - `0x0040f407` in `FUN_0040f3f0`;
  - `0x00410144` in `FUN_0040fe00`;
  - `0x004158c2` in `FUN_004157d0`;
  - `0x0042fc46` in `FUN_0042fc40`;
  - `0x004300a8` in `FUN_0042ffb0`;
  - `0x00430459` in `FUN_00430450`;
  - `0x004330fd` in `FUN_00432f10`.
- The `FUN_0042ffb0` and `FUN_00430450` cases preserve the singleton in a local
  variable and use it later through a virtual-interface call or a null check.
  `FUN_00430450` also routes by graphics/configuration state; it does not prove
  that the singleton is valid or initialized at runtime.
- The `FUN_00432f10` case dereferences the singleton for a single resource
  capability check. Its code maps selected resource/type identifiers, while
  the path reached from one identifier verifies
  `*(DAT_015fd918->field_0x3c + 0x118)`. This is a static property lookup,
  not a runtime observation of object layout.

These points consolidate static evidence for the singleton. They are not
runtime observations, and no consumer is classified until its containing
function and instruction access are independently decoded.

    Independent decoding of Ghidra's complete 470-reference inventory found
    470 instructions that decode as absolute `MOV` operands targeting
    `0x015fd918`: 469 direct reads and one direct write. The write is the
    confirmed setter at `0x0067e054`; the remaining 469 reads include the
    previously focused sites
    `0x40a827`, `0x40f407`, `0x410144`, `0x4158c2`, `0x42fc46`,
    `0x4300a8`, `0x430459` and `0x4330fd`. This independent result covers
    every provider source address in the current inventory, without relying
    only on Ghidra's operand rendering. The count rules out additional direct
    `MOV` stores in this inventory; writes through aliases, pointer arithmetic,
    copies, or indirect initialization still require separate coverage.
    Offline grouping of those 470 source addresses by the nearest prior
    Ghidra function entry produced 330 candidate procedures. Body-range
    validation confirmed the two largest reviewed groups:
    `FUN_007b7ac0` (21 sites) and `FUN_00b3c1a0` (7 sites). The seven sites
    previously grouped with `FUN_005d74c0` were false positives; its real body
    range has no reference to `DAT_015fd918`. Exact containment checks confirmed
    `0x007b7c3c` in `FUN_007b7ac0` and `0x00b3c210` in `FUN_00b3c1a0`.
    The nearest-entry grouping is preliminary; complete body-range validation
    is still required across all 330 groups.
    `FUN_007b7ac0` contains the static virtual call
    `(**(code **)(*DAT_015fd918 + 0x28))()`. Its returned object is inspected
    through fields at `+0x12` and `+4`. This confirms a static vtable slot
    use, not that the call executed at runtime.
    `FUN_00fa5610` is also a confirmed consumer. Its real body range is
    `0x00fa5610-0x00fa5cbd`, and all five provider sites are real:
    boolean property lookups at `0x00fa56a2` and `0x00fa578d`, plus float
    property lookups at `0x00fa579d`, `0x00fa57b5`, and `0x00fa57c9`. Static
    assembly confirms the singleton pointer is loaded immediately before calls
    to `FUN_006a25a0` and `FUN_006a2710`; this is not runtime proof.
    `FUN_005812b0` has a verified contiguous range of
    `0x005812b0-0x005816ed`. Four provider sites are inside it:
    integer getters at `0x005812b9` and `0x005812c9`, a virtual slot call at
    `0x005812e9`, and a boolean getter at `0x0058132d`. Hashes
    `0x5893ee8` and `0x5893ed4` are reused integer properties. Provider site
    `0x005817e1` is not contained in any function body and is excluded.
    `FUN_00585d40` has a verified contiguous range of
    `0x00585d40-0x00586401`, and all five provider sites are real. Assembly
    confirms integer getters at `0x00585d96` and `0x00585df5`, an integer getter
    plus float getter at `0x00585e49` and `0x00585e59`, and a float getter at
    `0x00585ffa`.
    `FUN_006b37d0` has a verified range of `0x006b37d0-0x006b400f`;
    all four sites are contained. Three read a singleton-owned field through
    offsets `+0x3c` and `+0x118`, while the fourth invokes the boolean getter
    `FUN_006a25a0` for the `UseBigPackedDatabases` property hash
    `0x811c9dc5`.
    `FUN_006e8810` has a verified range of `0x006e8810-0x006e8d6c`;
    all four sites are property getters: float `0x637fee8`, integer
    `0x628708c`, and booleans `0x6395f06` and `0x6395efa`.
    `FUN_00b35300` has a verified range of `0x00b35300-0x00b35857`;
    all four sites are contained. It uses integer property hash `0x1d1176d`
    twice and performs singleton field/vtable accesses, including a virtual
    call at slot `+0x24`.
    `FUN_005c7500` has a verified range of `0x005c7500-0x005c7b45`;
    all three sites are contained. Each reads the singleton-owned field path
    through offsets `+0x3c` and `+0x118`, consistent with the related checks
    in `FUN_006b37d0`.
    `FUN_005dfd00` has a verified range of `0x005dfd00-0x005dffbe`,
    containing all three provider sites. Each site reads the same singleton
    field path (`+0x3c`, then `+0x118`) in branches handling separate
    input/event cases. This is a static state check, not runtime evidence.
    `FUN_0064bcd0` has a verified body range of
    `0x0064bcd0-0x0064c0a4`; all three provider sites are contained. Each
    checks the same singleton field path (`+0x3c`, then `+0x118`) in branches
    that handle different hashed cases.
    `FUN_0066daf0` has a verified range of `0x0066daf0-0x0066ee2b`,
    containing all three provider sites. They include a singleton-owned field
    check through `+0x3c` and `+0x118`, a boolean getter for hash
    `0xb4daca6a`, and a float getter for hash `0x678aff6`.
    `FUN_006a30c0` has a verified range of `0x006a30c0-0x006a316a`;
    all three sites are contained. The sites call property setters
    `FUN_006a17e0`, `FUN_006a1880`, and `FUN_006a1910` with values read from
    boolean, integer, and float data, respectively.
    `FUN_006a9790` has a verified range of `0x006a9790-0x006a9b53`.
    Only `0x006a97ae` is inside that body; it loads the singleton and calls
    its vtable's slot `+0`. The other clustered sites, `0x006a9ba6` and
    `0x006a9c26`, are outside the body and exact address resolution finds no
    containing procedure.
    `FUN_006f0b90` has a verified range of `0x006f0b90-0x006f0fa3`;
    all three sites are contained. Two perform null-checked singleton calls
    through vtable slot `+0x24`; the third reads the float property hash
    `0x637fee8` with `FUN_006a2710`.
    `FUN_0070ec80` has a verified range of `0x0070ec80-0x0070ee99`,
    containing all three sites. They are null-checked virtual getter calls
    through slot `+0x24`, for property hashes `0x5fb85a3`, `0x5fb85a4`,
    and `0x179ada3`. The returned property types are checked before values
    are copied into global state or used to select a path.
    `FUN_0075e900` is non-contiguous: its verified ranges are
    `0x0075e900-0x0075ea89` and `0x0075ea90-0x0075ec9b`. All three
    references are inside those ranges: an integer getter (`0xd77e98`), a
    boolean getter (`0x5dd4647`), and a null-checked virtual getter at slot
    `+0x24` for hash `0x54d9bc3`.
    `FUN_007b3340` occupies `0x007b3340-0x007b3517`; all three sites are
    inside it. The two integer getters request hashes `0x5893ee8` and
    `0x5893ed4`; the third calls the singleton's virtual slot `+0x28` for
    hash `0x5d2c54b`, then selects/unwraps the returned value by its type.
    `FUN_007e67a0` occupies `0x007e67a0-0x007e70a1`; all three references
    are contained. One calls the singleton's vtable slot `+0` during the
    routine's initialization sequence. The other two call the property setter
    for boolean hash `0xd77e97` with values `1` and `0`, respectively, when
    command-line lookups for `vSync` and `noVSync` succeed. This is static
    setter evidence, not proof either option was supplied or the code ran.
    `FUN_00e8d790` has a verified body range of `0x00e8d790-0x00e8d879`
    and no singleton reference in that body. Its three nearest-entry sites
    (`0x00e8d9e7`, `0x00e8da2b`, and `0x00e8da93`) are all outside the body,
    and exact address resolution finds no containing procedure for them.
    They remain unclassified instead of being assigned to this function.
    `FUN_00eb25d0` is a short routine with body `0x00eb25d0-0x00eb25fe`;
    it invokes a virtual method with hash-like argument `0x487b104` and
    releases a referenced object, but does not access the singleton. Its
    nearest-entry sites (`0x00eb2655`, `0x00eb26db`, and `0x00eb26f5`) are
    outside the body, and exact address resolution finds no procedure at
    those sites.
    `FUN_00ef0570` occupies `0x00ef0570-0x00ef0669` and contains all three
    references. They are null-checked virtual property gets through slot
    `+0x24`: hash `0x7f2231b` with expected type `1`, then hashes
    `0xe2598dcf` and `0x5908481` with expected float type `0xd`. The retrieved
    values feed global settings and a square-root-based scale calculation;
    property names and runtime values are not established by this static
    evidence.
    `FUN_00fb0e00` has three non-contiguous body ranges
    (`0x00fb0e00-0x00fb0fbd`, `0x00fb0fc0-0x00fb1017`, and
    `0x00fb1020-0x00fb177b`); all three sites are contained. The first passes
    the singleton and hash `0xd81e2934` to `FUN_0040cf10`, which performs a
    null-checked virtual `+0x24` lookup and copies a float if the result has
    type `0xd`. The other sites call the boolean getter for hash
    `0xf3ea2b1d` and the float getter for hash `0x7580d2c2`.
    `FUN_004c5200` has a verified range of `0x004c5200-0x004c58a9`;
    both provider sites are contained. They call the integer getter for hash
    `0xb8864eac` and boolean getter for hash `0x2853e342`, respectively.
    `FUN_004cb340` has a verified range of `0x004cb340-0x004cb81c`;
    both sites are contained in its processing path. It reads a float with
    hash `0xa0304059` through `FUN_006a2710` and an integer with hash
    `0x4f6a84fd` through `FUN_006a2660`; both results are subsequently used
    by the routine. The semantic property names are not established here.
    `FUN_004efb20` has a verified body range of `0x004efb20-0x004f01e0`;
    both provider sites are contained. The sites load the singleton pointer
    along separate control-flow paths. Ghidra's decompilation uses a shared
    temporary for an interface object, but does not preserve a clear property
    getter or vtable call at these particular sites; their downstream meaning
    remains uncertain and is not inferred here.
    `FUN_00521ba0` occupies `0x00521ba0-0x00521d68`; both references are
    contained. They pass the singleton to `FUN_0040cf10` to read float
    properties with hashes `0x75cd84e9` and `0xeaf2bc95`; each result
    scales a dimension stored in the associated object. `FUN_0040cf10`
    performs the null check, virtual `+0x24` property lookup, and float-type
    check.
    `FUN_00579ce0` ends at `0x00579d30` and has no singleton reference in
    its body. The two nearby sites (`0x00579d7e` and `0x00579dae`) are
    outside the body; exact resolution reports no containing procedure for
    either, so they are excluded from this function's group.
    `FUN_00584300` occupies `0x00584300-0x00585325`; both sites are
    contained. The first loads the singleton before calling `FUN_006a17e0`
    with an argument `0x43` and value `0`; the exact property semantics are
    not established. The second reads the singleton-owned field path at
    `+0x3c` then `+0x118` and tests it for nonzero.
    `FUN_00587a20` occupies `0x00587a20-0x0058856a`; both sites are
    contained. One calls `FUN_006a1880` with hash `0xb` and a value from the
    current object; the other checks the singleton-owned `+0x3c`/`+0x118`
    field path for nonzero.
    `FUN_0058ac10` occupies `0x0058ac10-0x0058b53c`; both sites are
    contained. They check fields beneath the singleton's `+0x3c` object
    (`+0xcc` with `+0xd8`, or `+0xcc` with `+0xd0`) and conditionally call
    setters for hashes `0x36` or `0x34`. These branches establish static
    configuration checks and updates, not runtime execution.
    `FUN_005c0cd0` occupies `0x005c0cd0-0x005c0d14`; its entry site is
    contained and reads the singleton's `+0x3c`/`+0x118` field path to select
    one of two constants passed to `FUN_0064bc50`. The other nearby site,
    `0x005c0d6b`, lies outside this short body and exact resolution finds no
    containing procedure for it.
    `FUN_005c4500` occupies `0x005c4500-0x005c4de1`; both references are
    contained. They check the singleton-owned `+0x3c`/`+0x118` field path,
    once before invoking `FUN_005c2aa0` and once in a later branch.
    `FUN_005ffa00` has a short body ending at `0x005ffa26` with no singleton
    reference. The nearby sites `0x005ffbe7` and `0x005ffc78` are outside that
    body, and exact address resolution finds no containing procedure for them.
    `FUN_00601fd0` has two body ranges (`0x00601fd0-0x0060253c` and
    `0x00602540-0x006026eb`), and both sites fall within them. The first
    checks the singleton-owned `+0x3c`/`+0x118` path; the second calls the
    boolean getter for hash `0x61b67b6`.
    `FUN_00603260` occupies `0x00603260-0x006035c4`; both sites are
    contained and read the same singleton-owned field path at `+0x3c` then
    `+0x118`; no more specific domain meaning is inferred here.
    `FUN_00674620` ends at `0x0067463b` and has no singleton reference.
    Sites `0x00674775` and `0x0067489f` do not resolve to a containing
    procedure, so they are not assigned to it. In contrast,
    `FUN_006eae40` has two body ranges (`0x006eae40-0x006eaf48` and
    `0x006eaf50-0x006eb6d0`); both sites are in the second range. Each reads
    the singleton's `+0x3c` object's float at `+0xe0`, used as a comparison
    threshold while iterating over records. This describes the observed data
    flow without assigning a higher-level domain meaning to the field.
    `FUN_00780270` spans `0x00780270-0x00780699`, containing both of its
    singleton sites. At `0x0078028b`, it reads the singleton, checks it for
    null, and calls virtual slot `+0x24` with hash `0x276ac00`; if the returned
    object has type `9`, it obtains a value through `FUN_0041e990`. At
    `0x00780391`, it calls the boolean getter `FUN_006a25a0` with hash
    `0x5879277`. The property names and higher-level semantics are not
    established by these observations.
    `FUN_00780ab0` spans `0x00780ab0-0x00780b6f`, and both sites are
    contained. Its first site calls the boolean getter with hash `0x276abef`;
    the second begins calls using hashes `0x33cb1dac`, `0x276abf8`, and
    `0x65a8c87`, then conditionally invokes `FUN_00780270`. These calls are
    guarded by earlier boolean getter results (`0x276abf0`) and a zero check
    on the object field at `+0x1bc`. Hash names and domain semantics remain
    unresolved.
    `FUN_00780b70` spans `0x00780b70-0x007819cf`; both references are
    contained. Its first site calls the boolean getter for hashes `0x276abef`
    and `0x276abf0`. At the second, the code reads singleton fields `+0x30`
    and `+0x34`, conditionally calls `FUN_006237a0` when the `+0x30` value is
    nonzero, and compares the sum with an object field at `+0x1b8`. No
    higher-level meaning is inferred for these fields.
    `FUN_007a5370` (`0x007a5370-0x007a540a`) and `FUN_007a5410`
    (`0x007a5410-0x007a54aa`) each contain both of their sites. Both use the
    integer getter `FUN_006a2660` with hashes `0x5893ed4` and `0x5893ee8`,
    multiply the returned values, and pass the product twice to a virtual
    method at slot `+0x10`. Their respective virtual `+0x48` calls use the
    strings `AnimGIFExportRTT` and `EditGIFExportRTT`; successful results are
    stored in different object fields. The strings and call sequence are
    observed; the property names and resource semantics remain unverified.
    `FUN_007abc90` has three body ranges
    (`0x007abc90-0x007abf0c`, `0x007abf10-0x007ac01c`, and
    `0x007ac020-0x007ac078`), and both sites fall within them. The first
    reads an integer property using hash `0x101de7d` and stores a positive
    result at object offset `+0xc8`. The second calls virtual slot `+0x24`
    with hash `0x2840048`; when the returned value's type is `9`, it obtains
    a default through `FUN_0041e990` and writes it at `+0xcc`. The property
    names and domain-level meaning remain unknown.
    `FUN_007cb590` spans `0x007cb590-0x007cbcf1`, containing both sites.
    The first calls the boolean getter with hash `0x38d0a09` and stores its
    result as a float at object offset `+0x38`. The second calls the getter
    with hash `0x668d4fa1` and stores either `0.0` or `1.0` at `+0x70`.
    No property names are established.
    `FUN_00809c50` spans `0x00809c50-0x00809da3`; both sites are contained.
    The first checks the singleton `+0x3c` / `+0x118` path before performing
    conditional virtual calls involving global state. The second checks that
    same field path before a branch guarded by two global byte flags. The
    disassembly shows the returned object and related global pointers being
    updated; the higher-level role of this code and its fields is not
    established.
    `FUN_007e5e10` spans `0x007e5e10-0x007e5e6d`, and both sites lie within
    the body. After a foreground-window/process check, it calls the singleton's
    virtual slot `+0x1c` with argument `0x4b`; if true, it calls integer
    getter `FUN_006a2660` with the same argument and stores the result in
    `DAT_0153fb30`. A positive stored value is passed to `FUN_00921df0`.
    The argument's property meaning is not established.
    `FUN_00b2dac0` spans `0x00b2dac0-0x00b2e006`, containing both sites.
    At the first, the code queries hash `0x2979cd6` through virtual slot
    `+0x24`; if the returned value has type `0xd`, it obtains a float default
    with `FUN_0041ea70`. At the second, a changed set of three global float
    values leads to a null-checked call to `FUN_00410370` with hash
    `0x28bd2fd` and a pointer to object offset `+0x154`. Property meaning is
    not established.
    `FUN_00b328e0` spans `0x00b328e0-0x00b3294a`, and both sites are
    contained. The first calls the boolean getter with hash `0x66439bf9`;
    when true, a switch on the input selects a boolean value and the setter
    `FUN_006a17e0` is called with hash `0xc3f9e250`. The second is that setter
    call. `FUN_00b32a10` spans `0x00b32a10-0x00b32a98`; both sites are also
    contained. It calls the same boolean getter and, if true, calls the same
    setter with zero. These observations establish a guarded set/clear path,
    but not the property name or user-visible meaning.
    `FUN_00b84270` spans `0x00b84270-0x00b84725`, containing both sites.
    At the first, the code checks the field at singleton offset `+0x3c` plus
    `+0xf0`; if nonzero, it calls virtual slot `+0xa4` on the object returned
    by `FUN_0067de00`, passing two float constants. At the second, it calls
    the boolean getter with hash `0x5404855`; the true branch queries another
    object via `FUN_0067dd80` and virtual slot `+0x1c` with hash `0x3fbae24`.
    No higher-level field/property meaning is assigned.
    `FUN_00efe110` spans `0x00efe110-0x00efe23b`, and both sites lie within
    the body. Each conditionally queries the singleton via virtual slot
    `+0x24` using hashes `0xbc2db1cd` and `0xfd290b85`. When the returned
    value has type `1`, it reads a byte through `FUN_0041e920` into adjacent
    globals `DAT_016c7b8c` and `DAT_016c7b8d`. The property names are unknown.
    `FUN_00f06d40` spans `0x00f06d40-0x00f072a7`; both sites are contained.
    They pass the singleton to `FUN_004af210` with hashes `0x456f975` and
    `0x456f976`, writing into adjacent object fields at `+0x3c` and `+0x40`.
    No names or further semantics for the hash-selected values are inferred.
    `FUN_00f97960` spans `0x00f97960-0x00f97c20`; both sites are contained.
    The first calls the boolean getter with hash `0x2fbb4880`; when false,
    execution reads floats at offsets `+0x84`, `+0x88`, and `+0x8c` from the
    singleton-owned object at `+0x3c` and uses them in the function's
    calculations. The hash's property name and the exact domain meaning of
    those fields are not established.
    `FUN_00f9b8c0` spans `0x00f9b8c0-0x00f9ba3e`, containing both sites.
    They query hashes `0x31989aaf` and `0xab52b057` through virtual slot
    `+0x24`. If the first result is type `1`, a byte value from
    `FUN_0041e920` is stored at object offset `+0x108`. If the second result
    is type `9`, an integer default from `FUN_0041e990` is converted to float
    and stored at `+0x10c`. Hash names and property semantics are unresolved.
    `FUN_00fa3860` spans `0x00fa3860-0x00fa3b21`, containing both sites.
    The first calls the boolean getter with hash `0x1cb22fe0` and gates
    updates to several global values and a loop over entries. The second calls
    the getter with hash `0x552b4af`; if true, it calls `FUN_0067ddb0` and
    virtual slot `+0x60` with three global data addresses and the function's
    argument. No user-facing meanings are inferred for these hashes or globals.
    `FUN_00fc5900` spans `0x00fc5900-0x00fc5dd9`; both sites are contained.
    They call the boolean getter with hashes `0xd8349603` and `0xc8cf2af5`.
    When the first returns false, the code calls setup routines with the
    labels `writeForce` and `DAT_00fc4eb0`; when the second returns false, it
    calls setup routines with the label `coriolis` and `LAB_00fc5480`.
    Those strings and conditional calls are observed, but their feature-level
    meaning is not established.
    `FUN_00fc6640` spans `0x00fc6640-0x00fc6850`; both sites are contained.
    They load the singleton pointer into two separate 16-byte object records,
    at offsets `+0xb0` and `+0xc0`. Each record also receives a distinct
    integer tag (`0x3ffad0a` and `0x588bf6d`) and a null field, followed by
    calls to `FUN_007e6720` and `FUN_00dea7b0` respectively when the pointer
    is non-null. This is the observed initialization sequence; record
    semantics are not inferred.
    In `FUN_01060150` (`0x01060150-0x01060de0`), both sites call the boolean
    getter `FUN_006a25a0` with the same hash `0x149a7260`. A true result gates
    processing of two collections built through `FUN_00b21340`, using different
    code/data arguments at each site. This records the getter and control-flow
    relationship only; the hash's meaning is unknown.
    `FUN_0040a590` spans `0x0040a590-0x0040a9bf` and contains the site
    `0x0040a827`. There, it loads the singleton and calls the boolean getter
    `FUN_006a25a0` with hash `0x26cd3a5`. A true result is one of the conditions
    for a later virtual call at slot `+0x1c`; the code's higher-level meaning
    and the hash's property name are unknown.
    `FUN_0040f3f0` spans `0x0040f3f0-0x0040f49d`; its site `0x0040f407`
    calls the boolean getter with hash `0x1a91189c`. The result selects between
    virtual calls at slots `+0xbc` and `+0xc8`; the hash's meaning is unknown.
    `FUN_0040fe00` spans `0x0040fe00-0x0041036a` and contains site
    `0x00410144`. After a prior call sets a local value, the singleton boolean
    getter with hash `0x26cd3c9` gates calls to `FUN_007b10d0` and virtual slot
    `+0x54`. `FUN_004157d0` spans `0x004157d0-0x00416179`; at `0x004158c2`,
    the same hash `0x26cd3a5` is queried only when a flag bit is clear. A true
    result gates additional virtual checks at slots `+0x1c` and `+0x38`.
    No property names or higher-level meanings are inferred for these hashes.
    `FUN_0042fc40` spans `0x0042fc40-0x0042fef7` and contains the site
    `0x0042fc46`. It loads the singleton pointer into a stack local; the
    decompiled body shows no subsequent use of that local, so no behavior is
    attributed to this read.
    `FUN_0042ffb0` spans `0x0042ffb0-0x004301df` and contains site
    `0x004300a8`. It null-checks the singleton, then queries virtual slot
    `+0x24` with hash `0x444d5b0`. If the result has type `0xd`, a float
    default from `FUN_0041ea70` replaces a local initialized to `1.0`, and
    that value is passed to `FUN_00729300`. The hash meaning remains unknown.
    `FUN_00430450` spans `0x00430450-0x004308f1`; its site `0x00430459`
    loads the singleton into a local that the decompiled function does not
    subsequently use. No behavior is attributed to that read.
    `FUN_00432f10` has two body ranges (`0x00432f10-0x0043312d` and
    `0x00433130-0x0043320e`), and its site `0x004330fd` lies in the latter.
    The code reads a nonzero value from the singleton's `+0x3c` object at
    offset `+0x118` and uses the resulting boolean in later logic; no more
    specific meaning is established.
    `FUN_004bafc0` spans `0x004bafc0-0x004bb487` and contains `0x004bb3a0`.
    There, it calls the boolean getter with hash `0x26cd3c9`; a true result
    gates `FUN_006b2000` on a newly prepared object. The hash's meaning is
    unknown.
    `FUN_004ebe20` spans `0x004ebe20-0x004eceb2` and contains site
    `0x004ecbdf`. The instruction reads the singleton pointer into a stack
    local, which is not subsequently used in the decompiled body; no behavior
    is attributed to the load.
    `FUN_004ef880` spans `0x004ef880-0x004efb1e` and contains `0x004efa63`.
    It loads the singleton pointer into a stack local, but the decompiled body
    does not show a subsequent use; no behavior is attributed to this read.
    `FUN_004f3de0` spans `0x004f3de0-0x004f56ef` and contains site
    `0x004f3e0e`. It calls the boolean getter with hash `0x55d7ca1`. A false
    result enters a series of checks on input flags and helper-computed values;
    a true result bypasses that sequence. The hash's meaning is unknown.
    `FUN_00518cf0` spans `0x00518cf0-0x00518eff` and contains `0x00518d03`.
    It calls the float getter with hash `0xc19db33`, substitutes `5.0` if the
    result is zero, and uses one third of that value in a subsequent
    calculation. The hash's property name and the calculation's domain meaning
    are not established.
    `FUN_00519640` spans `0x00519640-0x0051a342`; its site `0x005198a6`
    calls the float getter with hash `0x1c76d9b5`. A zero value is replaced
    with `1.0`, and the resulting local is multiplied by another float later
    in the function. The hash's property name and semantic meaning are unknown.
    `FUN_0051c6a0` spans `0x0051c6a0-0x0051cfdd` and contains `0x0051ccf1`.
    After two local conditions hold, it calls the boolean getter with hash
    `0x26cd3c9`; a true result gates `FUN_007b10d0` and a virtual call at
    slot `+0x54`. The hash meaning remains unknown.
    `FUN_00521d70` spans `0x00521d70-0x00522719` and contains `0x00521f43`.
    It calls the integer getter with hash `0xb8864eac`; the result is clamped
    to at least `0x40` before being passed to a virtual call. The hash's
    property name and semantic meaning are not established.
    `FUN_00522b40` spans `0x00522b40-0x0052356a` and contains site
    `0x0052349b`. It calls the boolean getter with hash `0x2853e342` and stores
    the returned byte at object offset `+0x7e`; no property name or higher-level
    meaning is inferred.
    `FUN_005288f0` spans `0x005288f0-0x00528e1b` and contains `0x00528cbd`.
    It checks the integer at offset `+0x110` of the object reached through the
    singleton's `+0x3c` field. The check selects between two calculations;
    no higher-level meaning is assigned to the field.
    `FUN_0054c780` spans `0x0054c780-0x0054dd26` and contains site
    `0x0054cbbc`. It tests the integer at offset `+0x118` of the singleton's
    `+0x3c` object. When that field is nonzero and a local value equals `10`,
    execution takes a distinct branch; its domain meaning is unknown.
    `FUN_00573070` spans `0x00573070-0x005732e9` and contains `0x0057323d`.
    After two local checks, it queries the boolean getter with hash
    `0x677d3ea`; that true result and an additional call to `FUN_008d3200`
    gate later comparisons and control flow. The hash's meaning is unknown.
    `FUN_005745c0` spans `0x005745c0-0x00574848` and contains `0x005745d3`.
    When the object's field at `+0x98` is nonzero, it calls the boolean getter
    with hash `0x677d3ea`; the result controls whether two of several local
    ratios are calculated and whether related virtual calls are made. The hash
    meaning remains unknown.
    `FUN_00575270` spans `0x00575270-0x005754b7` and contains `0x00575277`.
    It calls the boolean getter with hash `0x677d3ea` but does not use the
    returned value in the decompiled body. No behavior is attributed to that
    call.
    `FUN_0057a710` spans `0x0057a710-0x0057a95b` and contains `0x0057a739`.
    It tests the integer at offset `+0x118` of the singleton's `+0x3c` object.
    Zero and nonzero results take different branches, but the field's higher-
    level meaning is unknown.
    `FUN_0057aaa0` spans `0x0057aaa0-0x0057abf7` and contains `0x0057aaa6`.
    It queries the boolean getter with hash `0x55d7ca1`; the result is used
    with two object flags to select among return values and helper checks. The
    hash's meaning is unknown.
    `FUN_0057ac00` spans `0x0057ac00-0x0057ae03` and contains `0x0057ac09`.
    It queries the same boolean hash `0x55d7ca1`; when true, it clears the
    four-word output structure and returns. Its higher-level effect is unknown.
    `FUN_0057e480` spans `0x0057e480-0x0057e78b` and contains `0x0057e481`.
    It checks the integer at offset `+0xdc` of the object reached through the
    singleton's `+0x3c` field before evaluating several local conditions.
    The field's higher-level meaning is unknown.
    `FUN_00583900` spans `0x00583900-0x00583c44` and contains `0x00583936`.
    It queries the singleton via virtual slot `+0x28` with hash `0x5d2cbfb`.
    If the returned value has type `0xd` or `0x10`, its float is selected;
    otherwise a global default is used. That value feeds subsequent
    calculations. The hash's meaning is unknown.
    `FUN_00584070` spans `0x00584070-0x00584159` and contains `0x00584085`.
    It calls the integer getter with hash `0x5893ee8`, squares the returned
    value, stores it at object offset `+0x3fc`, then uses it as a loop bound.
    The hash's meaning is not established.
    `FUN_00585330` spans `0x00585330-0x005855a6` and contains `0x00585398`.
    It tests the integer at offset `+0xdc` of the object reached through the
    singleton's `+0x3c` field; a nonzero result gates branches selected by
    another input value. The field meaning remains unknown.
    `FUN_005855b0` spans `0x005855b0-0x005857b4` and contains `0x005855ed`.
    It queries the boolean getter with hash `0x68df418`; the result selects
    whether a bit is copied from the object's current flags into a local
    bitfield, which is later used to update flags. The hash's meaning is
    unknown.
    `FUN_0058a1e0` spans `0x0058a1e0-0x0058a346` and contains `0x0058a2fb`.
    It queries the boolean getter with hash `0x677d3ea`. A true result plus
    two checks on object fields changes the value at `+0x58` from
    `0xdfad9f51` to `0x9ea3031a`. The hash and these constants' higher-level
    meanings are unknown.
    `FUN_0058a5a0` spans `0x0058a5a0-0x0058a94c` and contains `0x0058a78c`.
    It queries the boolean getter with hash `0x55d7ca1`. A false result gates
    an update of bit `0x10` in the object's field at `+0x48`, based on another
    function's result. The hash's meaning is unknown.
    `FUN_00598e90` spans `0x00598e90-0x00599031` and contains `0x00598fa6`.
    It tests the integer at offset `+0x118` of the object reached through the
    singleton's `+0x3c` field. When that field is nonzero (or a local float is
    at least `1.0`), a conditional flag update follows. The field meaning is
    unknown.
    `FUN_0059dc70` has four body ranges (`0x0059dc70-0x0059dd14`,
    `0x0059dd20-0x0059df4c`, `0x0059df50-0x0059e0ac`, and
    `0x0059e0b0-0x0059e352`), containing site `0x0059dc9b` in the first range.
    It checks the integer at offset `+0xdc` of the singleton's `+0x3c` object,
    along with conditions on the input record; a nonzero field is required for
    the guarded block. Its meaning is unknown.
    `FUN_0059e580` spans `0x0059e580-0x0059e8ca` and contains `0x0059e589`.
    It calls the boolean getter with hash `0x677d3ea`, but the decompiled body
    does not use its result. No behavior is attributed to that call.
    `FUN_0059e8d0` spans `0x0059e8d0-0x0059eb39` and contains `0x0059e9f5`.
    It queries the boolean getter with hash `0x677d3ea`; the inverted result
    controls whether aggregate values are checked through virtual slot `+0xc`.
    The hash's meaning is unknown.
    The site `0x005a2fb8` is outside `FUN_005a2ed0`'s analyzed body
    (`0x005a2ed0-0x005a2f1e`), despite that function being its nearest prior
    entry. The instruction map confirms a singleton load at the site, but it
    is not assigned to a procedure without containing-body evidence.
    `FUN_005a9200` spans `0x005a9200-0x005a94c0` and contains `0x005a9427`.
    It checks the integer at offset `+0x118` of the singleton's `+0x3c` object;
    when that value is zero and a local selector is nonzero, calls to
    `FUN_00675250` and `FUN_00676ed0` follow. The field meaning is unknown.
    Site `0x005c18c7` is outside `FUN_005c1570`'s analyzed body
    (`0x005c1570-0x005c1868`). The instruction map confirms a singleton load
    there, but it is not assigned to a procedure without containing-body
    evidence.
    `FUN_005c3000` spans `0x005c3000-0x005c31b6` and contains `0x005c304d`.
    A nonzero integer at `+0x118` of the singleton's `+0x3c` object triggers
    a call to `FUN_005c2aa0`; a result below `1` clears a local boolean.
    The field's higher-level meaning is unknown.
    `FUN_005c6010` spans `0x005c6010-0x005c6337` and contains `0x005c6283`.
    After another local pointer and a nonempty collection are checked, a
    nonzero singleton `+0x3c` object's `+0x118` field gates subsequent
    collection processing. The field meaning is unknown.
    `FUN_005c6810` spans `0x005c6810-0x005c6a2f` and contains `0x005c68a6`.
    When the singleton's `+0x3c` object's `+0x118` field is nonzero and the
    second argument is negative, it stores `0xa2e50993` at object offset
    `+0x24` and returns true. The field and constant meanings are unknown.
    The two sites near `thunk_FUN_011e2690` (`0x00763d6d` and
    `0x00763df0`) also resolve to no containing procedure and remain
    unassigned.
    The nearby `FUN_006040b0` body ends at `0x006041ea` and contains no
    singleton references; neither `0x006043c0` nor `0x006043f8` resolves to
    a containing procedure.
    `FUN_007e34a0` occupies `0x007e34a0-0x007e34e8` and has no singleton
    reference in its body. The three sites nearest its entry
    (`0x007e374e`, `0x007e3806`, and `0x007e3837`) are not in any analyzed
    procedure according to exact address resolution, so they are excluded
    rather than attributed to `FUN_007e34a0`.
    The three sites nearest `FUN_0063de20` (`0x0063e425`,
    `0x0063e43b`, and `0x0063e473`) are outside its actual body
    (`0x0063de20-0x0063e0f9`); exact address resolution finds no containing
    function for them. `FUN_0063de20` itself has no singleton reference in its
    analyzed body.
    Three nearest-entry clusters were rejected by exact body containment:
    the four sites near `FUN_0058ba60` lie beyond its body
    (`0x0058ba60-0x0058be45`), the four sites near `FUN_00591690` lie beyond
    its two body ranges (`0x00591690-0x00591bfc` and
    `0x00591c00-0x00591f92`), and the four sites near `FUN_006e7410` lie
    beyond its body (`0x006e7410-0x006e7441`). They remain provider xrefs but
    are not attributed to those functions. All four sites near
    `FUN_00814d50` are also outside its real body
    (`0x00814d50-0x00814e34`), and exact resolution reports no containing
    function for those addresses. Address-by-address containment also
    found no procedure for the seven sites previously grouped near
    `FUN_005d74c0`, the three sites beyond the verified `FUN_00b3c1a0` ranges,
    `0x005817e1`, and the three sites nearest `FUN_007e34a0`. Together these
    checks account for 54 of the 470 provider sites that are not in an analyzed
    function body. This count includes `0x00579d7e`, `0x00579dae`,
    `0x005c0d6b`, `0x005ffbe7`, `0x005ffc78`, `0x006043c0`, and
    `0x006043f8`, `0x00674775`, `0x0067489f`, `0x00763d6d`, and
    `0x00763df0`, all of which exact address resolution finds outside any
    procedure. The remaining 416 sites
    are assigned to preliminary function groups, and most still need individual
    body-range validation.
    supplements, rather than replaces, the provider xref search. When that
    routine's global graphics state `DAT_0171243c` is `2`, it stores the
    dimensions for its current target and runs graphics reconfiguration
    paths. The Canvas-generated flags (`0x2`, `0x6`, `0xa`,
    or `0x12`) do not satisfy the `0x22` check, so this branch is not the
    direct consumer of the standard `WM_SIZE` event payload.
    - `0x1ee1003` is also emitted by the window's `WM_MOVE` path
      (`FUN_00849230` -> `FUN_008491a0`) and `WM_EXITSIZEMOVE` path
      (`FUN_00849230` -> `FUN_00848cb0`). `WM_CAPTURECHANGED` can reach
      `FUN_00848cb0` through `FUN_00848e40` when the window's state byte at
      `+0x0e` is set. These helpers dispatch the event through
      `FUN_00847e70` with a geometry record. `FUN_00848cb0` computes a local
      mask of `0x20`, optionally adding `0x2` and `0x1`; that value could be
      `0x22`. In both helpers, however, the decoded stack layout saves a
      pointer to the payload's first dword, while the computed mask is written
      at payload offset `+4`; the first geometry coordinate is then copied
      over that same `+4` dword. No store in either helper initializes the
      payload's first dword. The corresponding `FUN_008491a0` local value
      (`0x1` or `0x11`) has the same offset/overwrite pattern. Thus these
      paths do not intentionally provide the `0x22` value that
      `FUN_00f47b10` compares at payload offset `+0`; its contents there are
      not established by these routines. This differs from `FUN_00848c20`,
      whose assembly places the flags at payload offset `+0` and the four
      geometry coordinates at `+4` through `+0x10`. The origin of a valid
      `0x22` payload remains unresolved.
    - `FUN_00f47b10` is the `+0x14` method in the vtable at `0x148d804`.
      `FUN_00f48850` installs that vtable at offset `+0x4` of an initialized
      object. The Canvas vtable at `0x141ca70` has a setter at `+0x68`,
      whose target `FUN_00a16a30` stores its argument in the Canvas field
      `+0x5c`. The startup routine `FUN_007e67a0` creates the Canvas with
      `FUN_00849a40` and invokes that setter with the owning object's field
      `+0x14`. The owner is created by `FUN_00f47ed0` through
      `FUN_007e8950`/`FUN_007e7630` and stored at the outer object's `+0x20`;
      its constructor initializes the owner field `+0x14` to null
      (`FUN_007e7630`, `0x7e767d`, after zeroing `EBX`). The initial bounded
      byte-pattern search of initialized code at `0x7e0000`–`0x7f0000` found
      no confirmed writer to this owner; a later focused trace found a store
      at `0x7e8e56` in code not recognized as a procedure. The
      apparent match at `0x7e7e13` is inside the `CALL` instruction beginning
      at `0x7e7e12`; the store at `0x7e6420` is through a separately returned
      object in `FUN_007e6210`, not proven to be this owner. Another candidate,
      `FUN_007ef2a0`, stores to its own `this + 0x14`, but its observed vtable
      reference is `0x1414920`, distinct from the owner's `0x1413ae0` vtable;
      no direct callers were found. Other same-offset candidates in this range
      also resolve to different objects: `FUN_007ec0a0` writes the value `1`
      into a class with vtable `0x14142e4`, `FUN_007ec5e0` initializes a
      different class with vtable `0x1414388`, and `FUN_007edd50` clears a
      byte-sized state flag. The match at `0x7e1bc9` is an immediate embedded
      in a store to `[EDI]`, not a field-offset store; `0x7e0f5a` is a
      byte-sized clear outside a recognized procedure. The store at
      `0x7e8e56` is stronger than an offset-only match: the owner constructor
      `FUN_007e7630` installs vtable `0x1413ae0`, whose `+0x10` entry at
      `0x1413af0` points to `0x7e8ba0`. The code at that entry begins with an
      x86 exception prologue and saves `ECX` in `ESI`; the continuous sequence
      reaches `0x7e8e56`, where it stores the newly constructed manager in
      `[ESI + 0x14]`. This identifies the store as the `this+0x14` field in
      the owner class's `+0x10` method. The owner vtable
      also has `FUN_007e67a0` at `+0x14`; the application startup path creates
      that owner with `FUN_007e8950` and invokes its `+0x14` method.
      Ghidra does not recognize a procedure at `0x7e8ba0` or around the store,
      so the full method boundary remains unavailable. However,
      `FUN_00f47ed0` first creates this owner through `FUN_007e8950` and stores
      it at `[in_ECX + 0x20]`; its assembly then loads that same field as
      `ECX` and calls the owner's vtable slot `+0x10` at `0xf48076`. Later in
      the same startup routine, it again loads `[in_ECX + 0x20]` and calls
      slot `+0x14` at `0xf481f4`, which is `FUN_007e67a0`. This establishes
      statically that the same owner instance receives both calls, and that
      its `+0x10` initialization precedes Canvas setup. `FUN_00847e70`
      decompiles the Canvas callback
      invocation as virtual slot `+0x14` with `(event_id, event_record, 0)`;
      this matches the event-manager dispatch call shape and reinforces the
      field link. In particular,
      the listener initialized by `FUN_00f48850` is a distinct object role:
      its `FUN_00f47b10` handler is registered with the manager, not passed
      directly to the Canvas setter. A complete Canvas-to-listener path is
      therefore established by the static startup sequence, subject to the
      normal limitation that static analysis does not prove runtime execution.
      The listener object is linked to the global event-manager singleton
      `DAT_015fd890`: its getter is `FUN_0067dcc0`, and its setter
      `FUN_0067deb0` writes that global. The two observed direct calls to the
      setter at `0x7e8e84` and `0x7e980b` are outside Ghidra-recognized
      procedures, so their initialization context and the concrete type of the
      supplied object remain unresolved. In the sequence around `0x7e8e4d`,
      code calls `FUN_00884a20`, whose constructor installs vtable
      `0x1427920`. The returned pointer is stored in `[ESI + 0x14]` at
      `0x7e8e56`; the sequence then loads that field, passes it to
      `FUN_00883870`, reloads it, and passes it to the singleton setter at
      `0x7e8e84`. The vtable evidence above associates the store's `ESI` with
      the owner class's `+0x10` method, although the missing procedure boundary
      and runtime observation leave its execution for the Canvas owner instance
      unconfirmed. The constructor `FUN_00884a20` installs
      `0x1427920` directly as the manager object's vptr. Reading that table
      establishes `FUN_008839e0` at `+0x20`, `0x8839a0` at `+0x24`,
      `0x883a30` at `+0x28`, `0x883aa0` at `+0x2c` and `+0x30`,
      `FUN_00884700` at `+0x38`, `FUN_0098f5a0` at `+0x3c`,
      `FUN_00883ab0` at `+0x40`, `FUN_00884c80` at `+0x44`, and
      `FUN_008845d0` at `+0x48`. `FUN_008839e0` builds a listener/event
      record, conditionally calls the listener's virtual `+8` method
      (consistent with retaining it), then forwards the record through
      manager slot `+0x44`, the insertion routine. Slot `+0x48` is the
      matching-record removal routine. The code at `0x8839a0` is not a
      recognized procedure, but its decoded instructions also forward through
      manager slot `+0x44`. Slot `+0x14` points to `0x8853b0`, without a
      recognized procedure. This manager vtable does not identify the
      separate callback object passed by `FUN_007e67a0`. At `0x7e980b`,
      the argument is `EBX`. In the latter sequence, `EBX` is passed to
      `FUN_00883870` and
      `FUN_0067deb0`, then compared with the existing `[ESI + 0x14]`. If the
      pointers differ, the old object's first virtual slot is called with `1`;
      afterward (or immediately when equal), `EBX` is stored into
      `[ESI + 0x14]`. This sequence supports a
      reference-release interpretation for that virtual call, but does not
      identify the object's class. It establishes that this code updates an
      object field and the manager singleton with the same pointer, but does
      not by itself connect that object to the Canvas owner. `FUN_00883870`
      returns the previous value of the separate global `DAT_016514cc` in
      `EAX` and stores
      its argument there; it does not construct the event manager. The object
      initialized around `FUN_00f48850` has vtable pointers `0x148d814` at
      offset `0` and `0x148d804` at offset `+4`. `FUN_00f47b10` is present at
      slot `+4` of the primary vtable (entry stored at `0x148d818`) and at
      slot `+0x14` of the secondary vtable (also stored at `0x148d818`,
      relative to `0x148d804`); its event-ID/payload arguments and this layout
      support it being an event callback. The object initialized by
      `FUN_00f48850` is allocated at `0xf48954`; its primary vptr is set to
      `0x148d814` at `0xf48974`, its secondary vptr to `0x148d804` at
      `0xf48990`, and its address is saved in `ESI` at `0xf489b3`. The caller
      then passes that same `ESI` as `this` to `FUN_00f47ed0` at
      `0xf489bb`–`0xf489bd`.
      In `FUN_00f47ed0`, the global manager getter `FUN_0067dcc0` is followed
      by calls through manager slot `+0x24`, passing that same `ESI` and event
      IDs `0x1ee100a`, `0x1ee1003`, and `0x44edd9c`. The `0x1ee1003` call is
      at `0xf48292`–`0xf4829a`. The code at `0x8839a0`, reached through
      manager slot `+0x24`, forwards the listener/event record through slot
      `+0x44`, which points to `FUN_00884c80`. That routine looks up an
      event-ID bucket and inserts the listener record into its linked list;
      `FUN_00884260` performs the sorted-list insertion. Thus the guarded
      startup path does request registration of the object whose primary
      vtable has `FUN_00f47b10` at slot `+4` for event `0x1ee1003` (and the
      other two IDs). This establishes the static registration path, not that
      the branch ran or that a later event was dispatched at runtime.
      The queue-processing routine `FUN_00884700` occupies slot `+0x38`
      (not `+0x34`); it removes queued records through `FUN_00884550` and
      routes them onward. When per-record callback fields are null, it calls
      the manager's virtual slot `+0x14` with the event value, payload pointer
      and a null third argument. This establishes a queue-to-dispatch path, but
      the destination `0x8853b0` for slot `+0x14` is not a Ghidra-recognized
      procedure. Decoded instructions show that a non-null third argument is
      treated as a callback object and invoked through its virtual slot `+4`.
      The queue passes null, selecting the path beginning at `0x8853e5`. That
      path hashes the event ID into the manager's bucket table, finds the
      matching event list, and walks its listener records. For the ordinary
      path (manager flags `+0xc0` and `+0xc1` clear), it invokes each non-null
      listener through virtual slot `+4`, passing the event ID and payload;
      the called slot is visible at `0x8854a2`–`0x8854b0`. Additional branches
      use per-record callback fields and manager flags, so this is not a claim
      that every state takes the same callback path.
      The queue's ordinary listener path calls each non-null listener through
      virtual slot `+4`, passing event ID and payload; therefore the registered
      object's `FUN_00f47b10` method is a compatible dispatch target. The
      dispatch remains a static path, not evidence that the callback ran.
      Separately, `FUN_00815dd0` calls the same singleton's virtual slot
      `+0x20` with its object at `this + 0x214` and several event IDs,
      including `0x1ee1003` just before the call at `0x816147`. Slot `+0x20`
      is `FUN_008839e0`, which forwards records to insertion slot `+0x44`;
      these are registration requests, not removals. The identity of the
      object at `this + 0x214` relative to the listener created in
      `FUN_00f48850` remains unknown. Slot `+0x3c` points to
      `FUN_0098f5a0`, which returns `this + 8`. The registered listener is
      not itself the Canvas callback: `FUN_007e67a0` passes the separate
      owner's `+0x14` field to the Canvas setter. The startup call to the
      owner's `+0x10` method precedes its Canvas setup call to `+0x14`, and
      the former stores the constructed event manager into that same field.
      This closes the static Canvas-to-manager-to-registered-listener link;
      runtime dispatch remains unobserved. The Canvas
      constructor `FUN_00849a40`
      initializes both callback fields `+0x5c` and `+0x64` to null; the
      constructor alone does not establish whether another path fills the
      fallback field before dispatch.
      The `0x22` condition still prevents `FUN_00f47b10`'s graphics-resize
      branch from handling the payload produced by this Canvas `WM_SIZE` path.
    The meaning of payload type `0x22` is also still unknown. These are static
    findings, not runtime observations.
- `WM_SIZING` (`0x214`) is conditionally adjusted by `FUN_00847cc0`: when bit
  `0x1` in the object's flags at `+0x8` is set, it reads the current
  outer-window rectangle and modifies the proposed rectangle according to the
  dragged edge/corner to preserve the current aspect ratio. The startup path
  initializes this field to `0x2a` and later assigns `0x2a` or `0x6a`, with
  an optional `0x80` bit; all observed values leave bit `0x1` clear. A
  separate helper, `FUN_0073a800`, can OR bit `0x1` into an object's field at
  `+0x8`, but its observed callers do not establish that it receives this
  window object. Thus aspect correction is off in the observed startup
  configuration, while later mutation of this window's flag remains
  unresolved. `WM_ENTERSIZEMOVE` sets the object state byte at `+0x0e`;
  `WM_EXITSIZEMOVE` clears resize-related state and runs the exit/geometry
  notification path.
- The `WM_CLOSE` handler at `0x848b60` sends internal event `0x1ee1009` through
  `FUN_00847e70`, with a local allow flag initially set to `1`. If dispatch
  leaves that flag nonzero, it calls `ShowWindow(hwnd, 0)` (`SW_HIDE`) and
  `PostQuitMessage(0)`. Thus close can be vetoed by the internal callback and,
  when accepted, hides the window before requesting application-loop exit.
  `FUN_00847e70` routes ordinary events through the object's callback at
  `+0x5c` (virtual slot `+0x14`) or, if absent, the function pointer at `+0x64`;
  event `0x1ee1001` has a separate route through `+0x60` (virtual slot `+0x30`).
  Preserve the cancellable-close distinction in any SDL event adaptation.
- 45 reachable x86 functions have passed controlled x86-versus-ARM64 tests,
  totaling 124 passing cases. The report and comparison manifest are in
  `SPORE_PORT_RESEARCH/BATCH_STATIC_LIFT_PILOT.md` and
  `SPORE_PORT_RESEARCH/batch_static_lift_reachable_execution_comparison.json`
  in the local Spore workspace.
- A bounded evaluation of the MIT-licensed
  [`pcrecomp`](https://github.com/sp00nznet/pcrecomp) pipeline used revision
  `ef3f0da6e08a8eb7a3f869273f3df071ca8d7373` against this same verified PE.
  Its x86-32 lifter translated the already-tested leaf function
  `0x0091E020` (23 instruction bytes, 8 instructions, 3 basic blocks, no
  calls), and the generated C passed an Android ARM64 NDK syntax check.
  This is a lift/compile smoke test only: the function was not linked to the
  Android runtime or run through pcrecomp's x86-versus-C differential harness.
  No APK or game source was changed. Since the existing fail-closed Spore
  backend already generated 3,703 functions and validated 45 reachable ones
  in 124 cases, pcrecomp remains a candidate for broader instruction coverage,
  not a replacement. Its global-register and guest-memory runtime, function
  dispatch, imports, callbacks, and Windows/COM shims would need a separate
  compatibility review before integration.
- Follow-up on the public
  [NFSU1](https://github.com/codepdbh/nfsu1-recompiled) and
  [NFSU2 `pcrecomp` patches](https://github.com/codepdbh/nfsu2-recompiled/tree/main/patches/pcrecomp):
  the NFSU1 README confirms a Windows x86 host is used for validation and its
  patched `pcrecomp` comes from NFSU2. It reports 22,751 functions, 191
  vtables, three handwritten overrides, a Windows boot, and Android menu
  reachability. This is strong process prior art, not proof the same runtime
  or generated-code path will work for Spore.
- The NFSU2 patch series suggests several focused experiments rather than a
  wholesale lifter replacement: its strict unresolved-indirect-call hook
  reports the target and caller instead of silently returning zero; its
  SIMD emitter adds MMX/SSE/SSE2 coverage; and its x87 patch models TOP state.
  The native-address-range fallback is useful for differential debugging on
  an x86 Windows host, but is not itself an ARM64 solution. None of these
  patches directly resolves Spore's `FuncInfo`/SEH requirements.
- The Windows x86 validation idea is actionable on this workstation:
  Visual Studio Build Tools contains an x86 `cl.exe`. The existing README
  reports 45 functions and 124 controlled x86-versus-ARM64 cases, but the
  Android CMake/tools tree does not document a Windows-host x86 validation
  target, so whether those cases already use such a host is unverified.
  Reuse a small, call-free case to add or confirm that host path; keep
  unresolved calls fail-closed and record the PE and lifter identities. Do
  not infer that the NFSU patches would fix the earlier `0x0091E020` smoke
  test without reproducing it against the patched revision.
- A focused Windows x86 differential harness now executes the exact
  `0x0091E020` byte sequence from the SHA-256-verified PE and compares its
  output to the existing generated `spore_0091e020_arm64.cpp`, compiled for
  x86 using a small test-only guest-memory adapter. The test passed 674 cases,
  including null/non-null targets, boundary bit patterns, and deterministic
  randomized arguments; the script also rejects a different PE hash or
  function byte sequence. This validates this generated function's semantics
  on Windows x86, not the pcrecomp output, the ARM64 binary, or a full runtime.
  Run it with `tools/run_x86_lift_differential.ps1`; the temporary executable
  and object files are removed after the run.
- A second Windows x86 harness now executes the exact PE bodies at
  `0x00422430` and `0x01158BE0`, comparing them with the current reconstructed
  lower-bound and array C++ candidates. It passed 146 lower-bound cases and 12
  nonzero array-kernel cases, checking exact array bits, source immutability and
  guard regions. The zero-count boundary probe exposed original-code writes to
  `destination[-4]` through `destination[-1]` that the safe C++ candidate does
  not reproduce, so zero count is not considered equivalent until the caller
  contract is established.
  Run `tools/run_x86_candidate_differential.ps1`; it verifies the PE hash and
  exact function bytes and removes temporary build products. These are
  hand-reconstructed candidates, not generated static-lifter output, and this
  does not validate ARM64 execution or the game boot path.
- The user-provided `C:\Users\wesll\Documents\sporecompSporeVersion` folder is
  directly relevant: it contains Spore-specific Ghidra export/function-fix
  scripts plus a small PE scanner/catalog builder, not just a copy of
  `pcrecomp`. Its synthetic self-test passed. Running the scanner against the
  local PE with SHA-256
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`
  found 6,231 pointer runs, 1,013 structurally accepted MSVC `FuncInfo`
  records, and 55,299 combined candidate entry addresses. Merging with the
  existing `functions.csv` (57,964 records) yielded 32,743 entries not present
  as function starts and 3,077 entries inside existing function ranges;
  pointer runs were heuristically classified as 1,648 vtables, 4,446
  incomplete vtables, and 137 jump tables. These are leads for recovery, not
  validated functions or proof of dispatch. The CSV does not embed a PE hash,
  so the merged counts are provisional until regenerated from a hash-verified
  Ghidra project. I corrected `FixFunctions.java` to call
  `FunctionManager.getFunctionCount()` and fixed the local Ghidra/JDK paths in
  `rodar_ghidra.bat`. A no-BOM copy of the scripts then ran successfully in
  Ghidra 12.1.4 on a cloned project, leaving the user's main analysis project
  and its outputs untouched. This pass created 32,573 candidate functions and
  exported 90,872 function records; combining that export with the PE scanner
  left 30 entries without function records and 3,244 conflicts. It also
  reported 63 failed candidate decodes and 2,002 remaining executable gaps,
  so these counts are recovery leads, not proof every candidate is valid. The
  first temporary clone was removed after that test. A new isolated clone is
  now preserved at `C:\SporeAnalysis\SporecompUpdatePilot`.
- I reran the recovery and exports on that clone with the updated
  `sporecompupdate` tools, leaving `C:\SporeAnalysis\out` and
  `C:\SporeAnalysis\out_update` untouched. The updated catalog used the
  recovered 90,872-function CSV and the same-hash PE; it reports 30 extra
  entries and 3,191 conflicts. It classifies 3,004 complete vtable runs,
  3,095 incomplete vtable runs, and 132 jump-table runs. The scanner found
  6,231 pointer runs, 1,013 accepted MSVC `FuncInfo` records, and 55,299
  candidate addresses. The remaining 487 difference between Ghidra's
  `FunctionManager.getFunctionCount()` (91,359) and the function iterator /
  CSV (90,872) is still unexplained; the iterator exposed no external-space
  functions.
- The recovered CSV still gives `FUN_00e819b0` zero function callers, but
  address-level inspection resolves the missing context. `FixFunctions`
  recovered `FUN_00e81cf0` and `FUN_00e81f30` from adjacent entries at
  `0x01485560` and `0x01485564` in the same `.rdata` pointer run. Both
  functions pass `0x00e81c90` to an indirect virtual call; those callsites
  are at `0x00e81e09` and `0x00e8205e`. The recovered code at `0x00e81c90`
  checks event/state values and directly calls `FUN_00e819b0` at
  `0x00e81cba`, passing a boolean derived from the event payload. It can also
  call `FUN_00e81ba0` at `0x00e81cda`; that helper is called directly by
  `FUN_00e81f30` at `0x00e81f42`. Thus the Cell setup callback and its two
  registration methods are statically mapped; whether this registration or
  callback actually runs during boot remains unknown.
- The direct headless decompiler invocation failed in this environment, so
  `C:\SporeAnalysis\out_recovered_update\cell_assembly.txt` records the
  recovered instruction listing for these methods and the callback instead.
  All of this remains static analysis; it is not evidence that Spore booted or
  ran on Android.
- This Android Studio project is still an early launcher/import prototype.
  The current screen imports the user's game folder and verifies the reference
  executable. A separate SDL2 screen renders a test pattern through the
  Android SDL activity and ARM64 renderer. The prior Wine/Box64 bootstrap and
  OpenGL cell demo are not part of this test flow.
- SDL2 2.32.10 is built from the vendored upstream source in
  `app/src/main/cpp/SDL` and uses its upstream Android Java glue in
  `app/src/main/java/org/libsdl/app`. It is pinned to the upstream
  `release-2.32.10` tag (source archive SHA-256
  `7a3c207b8509edc487d658df357ad764cd852d68fe248d307b25c0741d52fdf0`); the
  upstream zlib license is included alongside that source.
- The SDL2 OpenGL ES 2 screen runs a native event loop and an accelerated
  renderer test pattern. Android Back returns to the importer. This does not
  test DXVK or translated Spore functions.
- A separate SDL2 + Vulkan test now creates an Android Vulkan surface, selects
  a physical device and presentation queue, creates a swapchain, and clears
  frames on-screen. On the connected phone, the probe passed on a Mali-G57 MC2
  (Vulkan API 1.3.278) with a 2400x1080 swapchain and five images. This is a
  graphics-path probe, not DXVK or D3D9 integration.
- DXVK Native is vendored at upstream commit
  `c8dc91fabd00cac11d697ccf07426e798393cd40` (`native-1.9.2b`), under its
  included zlib license. This upstream is archived and does not provide an
  Android build; the app builds its D3D9 target with the NDK, SDL2 WSI, and
  Android Vulkan loader. Shader headers are generated from the pinned shader
  sources by the NDK's `glslc`.
- A separate SDL2 + D3D9 screen now creates a DXVK-native D3D9 device, clears
  the target, and presents frames through Vulkan. On the connected phone, the
  colored test surface remained active, Android reported continuous surface
  buffer submission, and DXVK created its state cache inside the app's private
  files directory. The test reuses the active SDL Vulkan window because Android
  cannot rely on DXVK's desktop-style hidden dummy window.
- The NDK build required ARM64-safe fallbacks for DXVK Native's x86-only bit
  intrinsics. These local changes are limited to bit counting/comparison,
  spin-wait hints, SDL window selection, and reporting D3D9 initialization
  failures; they do not represent a complete Android port of DXVK.
- After adding DXVK Native, the OpenGL ES and Vulkan test activities still
  opened successfully and returned to the importer on the phone.
- `app/lint-baseline.xml` is restricted to diagnostics in the vendored SDL
  Android Java package; it does not baseline application-source findings.
- The current D3D9 screen is a graphics smoke test only. A first two-function
  Spore chain is now compiled into JNI and reads data from the imported PE, but
  it is not connected to the game boot path and this APK does not launch Spore.
- The game-folder importer copies a selected installation into app-private
  storage. The JNI runtime can now read a real DBPF resource as well as the
  verified PE string table, but DBPF lookup is not yet called from translated
  Spore code and package precedence is not implemented. The next milestone is
  to connect this reader to an actual resource-consuming Spore function and
  validate its behavior against the original executable.
- Where a user obtained their original game files is outside the port's
  technical scope. The PE SHA-256 check remains useful only to bind translated
  code addresses and behavior to the exact executable build; it is not a
  requirement that the files come from a particular store or installer.

The APK must not bundle the proprietary game executable, DLLs, or assets.
Testing should use a user-supplied installation.

## SDL2 Canvas event-shim scaffold — 2026-11-04

- The native CMake build keeps `spore_native_runtime` as the JNI library
  (`libspore_native_runtime.so`) and defines a separate `spore_sdl_main` target
  for SDL sources. Its output remains `libmain.so`, which the existing SDL
  Android activity loads. The SDL target links SDL2, DXVK Native, Vulkan, and
  the JNI runtime.
- `spore_sdl_bridge.h` defines the shared C ABI for `SporeCanvasAdapter`,
  size/activation events, and geometry/swapchain/activation hooks.
  `sdl_event_loop.cpp` polls SDL2 events; `spore_canvas_adapter.cpp` updates
  adapter state before invoking the optional hooks. Minimize sets dimensions
  to zero; swapchain resize is called only for positive dimensions. Hook
  failures are returned to the event loop instead of being silently ignored.
- The reference `WM_SIZE` path invokes `FUN_00848c20` with the Canvas instance
  in x86 `ECX` and four stack arguments (window handle, `wParam`, and the
  packed `lParam` width/height). The handler uses `wParam` for its state
  branches and queries Canvas geometry through a virtual method; it does not
  consume the supplied width/height values directly. The ARM64 adapter is a
  port-side contract, not a call to the x86 address or a proven translation
  of `FUN_008484f0`.
- The Canvas constructor `FUN_00849a40` initializes its vtable at
  `0x0141ca70` and zeros the four cached geometry values. Vtable slot `+0x3c`
  targets `FUN_00848190`, which reads the client rectangle for the window
  handle at object offset `+0x74`, converts both corners to screen coordinates,
  and returns `(left, top, right, bottom)`. `FUN_008484f0` conditionally copies
  those values to object offsets `+0x3c`, `+0x40`, `+0x44`, and `+0x48`.
  These are cached rectangle edges, not separately established width/height
  fields; dimensions are derived as `right - left` and `bottom - top`.
- The offsets above describe the original x86 object only. The Android project
  still has no concrete ARM64 Canvas layout, so the callback scaffold must not
  write those offsets into an assumed ARM64 object. A real port-side Canvas
  implementation must define its own state and connect the geometry hook.
- `spore_d3d9_bridge.cpp` provides `CreateSporeDxvkDevice` in the SDL/DXVK
  target, not in the JNI-only `spore_native_runtime`. It passes the
  `SDL_Window*` as the `HWND` token expected by this build's SDL2 WSI, sets
  `hDeviceWindow` to the same token, applies the original zero-dimension
  fallback, and returns both COM interfaces to the caller for explicit
  ownership. It deliberately does not call `SDL_GetWindowWMInfo`, force
  swap/depth/sync settings, or write to the original executable's absolute
  global addresses. The bridge is not yet wired into a lifted Spore startup
  path. The D3D9 test uses it to create the device, calls `Reset` when the
  drawable size changes, then renders and presents until shutdown. On the
  connected `arm64-v8a` Android 15 phone, the debug APK installed and the
  D3D9 test activity remained in the foreground. A captured frame showed a
  filled render surface, and SurfaceView buffer-queue telemetry reported
  roughly 46-48 fps. This is evidence of active surface presentation, but
  there was no explicit DXVK success log and device resize/`Reset` was not
  exercised.
- On the same `arm64-v8a` Android 15 phone, the JNI static recompilation test
  ran against the SHA-256-verified original `SporeApp.exe`: the lookup chain
  for key `0xB1C3E5B6` returned `mean` (sorted table index 76). The DBPF reader
  independently extracted TGI `0xDFAD9F51:0x00000000:0x7ADE24E1` from
  `Spore_Game.package`: 796 decoded bytes, SHA-256
  `ac291c1cd5cb91d78fbe8e4420a40e8c2aaaa1632d4c6b2d2edeb822174a2ec8`.
  This verifies the lifted lookup and original resource extraction on-device,
  but they are currently separate operations; no Spore routine consumes this
  resource yet, and neither result is rendered through the D3D9 test.
- This is scaffolding only: no concrete Canvas object, geometry refresh,
  activation listener, or swapchain-resize implementation exists yet, and
  `RunAndroidEventLoop` is not wired into `SDL_main`. The D3D9/Vulkan test
  activities retain their own loops. `:app:externalNativeBuildDebug`
  successfully compiled the bridge, event-loop, and adapter sources for
  `arm64-v8a`; device validation has not yet exercised resize, device reset,
  or swapchain recreation.

## Translated graphics boundary probe — 2026-11-05

The static boot dependencies relevant to graphics are ordered as follows:

1. `FUN_00f47ed0` calls `SteamAPI_Init` and exits on a false return. The user
   reports that this PC copy launches without opening the Steam client, so
   whether this call blocks the Android boot is unconfirmed; its actual return
   and the local library behavior need runtime evidence.
2. The routine initializes app/config state, reads registry-backed `PlayerDir`
   and `AppDir`, and calls application slots `+0x0c` and `+0x10`. Those paths
   include the unresolved DDF/config and file/resource requirements documented
   above.
3. Application slot `+0x14` (`FUN_007e67a0`) configures the Canvas and graphics
   manager, creates the original Win32 window, and initializes D3D9 through
   Graphics slot `+0x0c` (`FUN_0075e830`) and
   `FUN_011f84b0`/`Direct3DCreate9`.
4. Application slot `+0x1c` (`FUN_007e7380`) dispatches Graphics slot `+0x14`
   (`FUN_0075f030`) into `FUN_011f8680`/`IDirect3D9::CreateDevice`. Its call
   arguments include `640x480`; the callee assembles the actual D3D parameters
   from graphics/configuration state.
5. After conditional setup, `FUN_007e7380` calls `FUN_011f8120`; the null
   alternate-presenter branch dispatches `IDirect3DDevice9::Present`. The
   normal loop's message pump and later frame-render path have separate
   unresolved work.

The first connected executable increment is a **boundary probe**, not a boot
translation. `SporeGuestPresentParameters32` retains the x86
`D3DPRESENT_PARAMETERS` layout (`0x38` bytes, window token at `0x1c`,
presentation interval at `0x34`). Guest window/device pointers are 32-bit
opaque tokens, never truncated ARM64 pointers. At the explicit host boundary,
the window token maps to the supplied `SDL_Window*`, the fields are copied to
the host-width D3D9 structure, and `CreateSporeDxvkDevice` performs the call.
`SporeTranslatedPresent` mirrors the observed null alternate-presenter branch
and refuses an unimplemented non-null presenter instead of silently
substituting behavior.

The in-app option **“Translated Spore graphics boundary probe (manual
regression)”** seeds the guest state explicitly: `640x480` is passed by
`FUN_007e7380` to Graphics slot `+0x14`; adapter 0, HAL, hardware vertex
processing, windowed/discard, and interval-one are probe choices, not recovered
values from a run of the original. The SDL surface and window token are also
supplied by the harness. Steam, registry/configuration, DDF initialization,
Canvas construction, `Direct3DCreate9` initialization, and the original
application objects are bypassed; none is claimed to have booted.

Progress recorded on the connected `arm64-v8a` phone (model `2303ERA42L`):

| Increment | Result |
|---|---|
| Guest x86 layout compile-time checks | PASS |
| Prepared boundary state | PASS (`manual pre-boot state`) |
| Translated adapter -> bridge -> `CreateDevice` | PASS (`640x480`) |
| Translated null-presenter branch -> `Present` | PASS |
| Existing DXVK-native D3D9 regression | PASS (device create and resize to `2400x1080`) |
| Original Spore boot to `CreateDevice` | NOT RUN |
| First blocker for the real boot | Not established; Steam return behavior is unobserved. App/registry/DDF/window/renderer initialization is also not connected. |

These results prove that ARM64-translated boundary code can create and present
through the existing bridge from explicitly prepared state. They do not prove
that translated original startup functions reached those calls.

## Translated window-global increment — 2026-11-05

The original executable used for this increment is [SporeApp.exe](C:/Users/wesll/Downloads/SPORE-SteamRIP.com/SPORE/SporeBin/SporeApp.exe),
SHA-256 `290703b34fe4573b242c3e271cc90568992abe6fb3fa9333a7341044a759fc74`.
Static analysis confirms the following connected fragment:

1. `FUN_0075f030` gets a window handle through Canvas/window-manager virtual
   slot `+0x94`, then calls `FUN_011f8110(handle)`.
2. `FUN_011f8110` is a three-byte setter that stores its 32-bit argument in
   guest global `DAT_016f658c`.
3. `FUN_011f8680`, the `IDirect3D9::CreateDevice` wrapper, reads
   `DAT_016f658c` as the device window. `FUN_0075f030` reaches that wrapper in
   the graphics initialization path.

The new Android translation reproduces only this setter. The second test route
starts from the probe state but leaves
`SporeGuestPresentParameters32.device_window_token` unset. It passes the
manually mapped guest window token through the translated setter, stores it in
the 32-bit guest-global representation of `DAT_016f658c`, copies that global
into the guest presentation structure, then calls the existing
`CreateSporeDxvkDevice` bridge. The host `SDL_Window*` is still supplied
separately; no ARM64 pointer is stored in x86 state. The original manual
boundary probe remains a separate menu item and regression.

### Preparation inventory

“Original source” below is static evidence unless explicitly identified as
device-observed. The table covers the manually prepared probe state and the
Android adaptation boundary; it does not claim that the original constructors
or boot path ran.

| Manually prepared item | Original source / initializer | Dependencies and current status |
|---|---|---|
| Android `SDL_Window*`, Vulkan surface and drawable size | Original app creates a Win32 Canvas/window during application graphics initialization (`FUN_007e67a0` and its Canvas/window callees). | Android SDL/activity/surface. The probe creates these in its harness; the original Canvas/window chain is not connected. |
| Guest window token `0x00010001` | Original Canvas manager virtual slot `+0x94` supplies an HWND to `FUN_0075f030`; Android has no x86 HWND. | Token-to-`SDL_Window*` mapping is a test adaptation and remains manual. Only storage into the guest global is now translated. |
| `SporeGuestD3D9State32` object, zero initialization | Original objects are created by app/graphics constructors; `FUN_0075f030` fills a local 15-DWORD D3D setup block before `FUN_011f8680`. | Probe aggregate and lifetime are harness-created, not original object construction. x86 field offsets are asserted. |
| `adapter_ordinal = 0` | Original `FUN_011f8680` calls the D3D9 interface using graphics setup assembled by `FUN_0075f030`. | Adapter selection/capabilities and config are not recovered in this test; 0 is a probe choice. |
| `device_type = HAL` | Original D3D9 `CreateDevice` path in `FUN_011f8680`, reached after `FUN_0075e830` initializes the D3D9 interface. | The original argument was not runtime-captured; HAL is a probe choice. |
| `behavior_flags = HARDWARE_VERTEXPROCESSING` | `FUN_011f8680` computes flags from global renderer settings and device capability bits. | Those globals/caps are not initialized by the translated boot path; this flag is manually selected. |
| Present width/height | `FUN_007e7380` pushes `(0, 0, 480, 640)` before calling Graphics slot `+0x14`, so the callee receives `(640, 480, 0, 0)`. `FUN_0075f030` copies its first and second stack arguments from `[ESP+0xbc]` and `[ESP+0xc0]` to structure offsets `+8` and `+0xc`; `FUN_011f8680` consumes those offsets as width and height. | The device-global route translates the connected width/height pair. The other 12 DWORDs in `SporeGuestPresentParameters32` and the other D3D state fields remain prepared by the harness. |
| Present format `UNKNOWN`, count `1`, multisample type/quality `NONE/0`, swap effect `DISCARD`, windowed `TRUE`, auto-depth off, depth format `0`, flags `0`, refresh `0`, interval `ONE` | `FUN_0075f030` assembles configuration/renderer values and `FUN_011f8680` passes them to `IDirect3D9::CreateDevice`. | Full per-field source/value mapping depends on config, Canvas and D3D capabilities and is not translated. These values are probe choices; zero-valued fields come from aggregate initialization. |
| Initial guest globals `DAT_016f658c = 0`, `DAT_016f89d0 = 0` | Original `FUN_011f8110` first writes the window global; `CreateDevice` writes the device output global. Their initial zeroing/constructor path was not observed. | `SporeGuestMemory32::Clear` starts the Android guest map at zero. The host registry starts empty; the zero seed is manual harness state. |
| `DAT_016f658c` window-global representation | Original `FUN_011f8110` writes the HWND supplied by the Canvas manager; `FUN_011f8680` consumes it for `CreateDevice`. | Setter now translated. Its input token and association with the SDL window remain manual. |
| Guest device token, initially `0`, then `0x00010002` | Original `FUN_011f8680` obtains the COM device from `CreateDevice`. | Host device is produced by DXVK-native; the non-pointer guest token is assigned by the adapter after success. It is not a manual input. |
| `DAT_016f89d0` device-global representation | `FUN_011f8680` passes its address as the `CreateDevice` output; `FUN_011f8120` reads the global for `Present`. | The new adapter fragment stores the guest token here and checks it before `Present`. The host COM pointer remains separate and is supplied by the bridge. |
| Token-to-native-device association and COM lifetime | Original `CreateDevice` writes a COM pointer directly to `DAT_016f89d0`; it has no Android token registry. | Android-only adapter maps the guest token to the bridge device, holds an `AddRef`, resolves `Present` through that token, and invalidates/releases the association before device teardown. |
| `SporeGuestFrameOwner32` zero-initialized; alternate-presenter token at `+0x18` is `0` | Original `FUN_011f8680` initializes `PTR_DAT_015d0838` to `DAT_01712480`; `FUN_007e7380` passes that object to `FUN_011f8120`. | Original object's runtime contents are not captured. Zero selects the identified null-alternate-presenter branch for this probe; the frame owner is manual. |
| `Present(nullptr, nullptr, nullptr, nullptr)` | Original `FUN_011f8120` dispatches device `Present` on its null alternate-presenter branch. | Branch and host device are tested; the original app-owned wrapper object is not constructed. |
| Probe clear color and frame counter | Not claimed as Spore renderer state. | Harness-only visual output, unrelated to translated game initialization. |

### Steam boundary (separate from graphics)

The Android graphics adapter does not invoke `SteamAPI_Init`, does not invent a
successful result, and does not claim to reproduce Steam initialization. The
reference PE's `FUN_00f47ed0` calls it before other app initialization and
branches on failure, while the user reports that this PC copy launches without
opening the Steam client. The loaded DLL, the call's actual return in that run,
and any required initialization side effects are unknown. Treat this as a
separate platform-adaptation question. When the Android boot runner reaches
that boundary, determine the observed contract and implement only required
platform behavior, recording unsupported calls explicitly; a fabricated
success return alone is not equivalent to initialization.

### Device run status

The updated `arm64-v8a` APK built successfully and was installed on the
`2303ERA42L` phone (ADB serial `PJMZAEJRX4YLFIDI`, Android 15/API 35). Tested
APK SHA-256:
`0bfba261b800c0435b1f8c411bd17c34f341163aa2b87a6c57ae3d962491b7bd`.
Both the retained manual probe and the
new window-global increment ran through `CreateDevice` and `Present`; the
manual probe also exercised the `2177x987` to `2400x1080` reset. The original
D3D9 bridge regression also created a device successfully; that run began at
`2400x1080`, so it did not need a resize. The incremental results are:

| Step | Result |
|---|---|
| x86 device-window field/global start at zero | PASS |
| Translated `FUN_011f8110` store to guest global `0x016f658c` | PASS (`0x00010001`, supplied by the Android window-token adapter) |
| Guest presentation window field read from the translated global | PASS |
| Existing bridge `CreateDevice` | PASS (`640x480` guest backbuffer) |
| Translated null-presenter branch to `Present` | PASS |
| Original Spore boot/startup functions | NOT RUN |
| Stop point | Probe's SDL test loop immediately after `Present`; the original application/Canvas/renderer initialization remains disconnected |

Thus, this increment replaces one preparation: the presentation window token
now comes from translated game logic. The token-to-SDL mapping, 640x480,
adapter/type/flags, other presentation fields, and presenter state are still
manual as listed above. Unedited filtered logcat captures are saved in:

- [translated-graphics-manual-regression-2026-11-05.log](./test-logs/translated-graphics-manual-regression-2026-11-05.log)
- [translated-window-global-increment-2026-11-05.log](./test-logs/translated-window-global-increment-2026-11-05.log)
- [d3d9-bridge-regression-2026-11-05.log](./test-logs/d3d9-bridge-regression-2026-11-05.log)

In the new increment, the value written by translated game logic is the guest
global `DAT_016f658c`, set by translated `FUN_011f8110`. Its input
`0x00010001` is still manually supplied by the Android window-token adapter;
the 640x480 state, device options, remaining presentation fields, null
alternate presenter, app objects, Canvas, and Steam behavior remain outside
the translated path in this window-global increment. After `Present`,
execution stops in the probe's own SDL loop; the Spore boot path itself has
not run. The later device-global and dimension-pair increment is documented below.

## Translated device-global increment — 2026-11-05

The next connected fragment follows the created device into the original
`Present` wrapper:

1. `FUN_011f8680` passes the address of `DAT_016f89d0` to
   `IDirect3D9::CreateDevice` as the output location for the created device.
2. `FUN_011f8120` reads `DAT_016f89d0`; when its alternate-presenter field is
   null, it dispatches the device's `Present` method.
3. The Android adaptation keeps the guest global as a 32-bit opaque token
   (`0x00010002` at `DAT_016f89d0`). The host `IDirect3DDevice9*` returned by
   DXVK-native remains outside guest memory. The translated adapter checks the
   token against the created device token, then uses the bridge-returned host
   pointer.

The new device-global test is a separate route; the original manual probe and
the preceding window-global increment remain separate regressions. It
translates only the CreateDevice output-global handoff and the null-presenter
Present branch; it does not translate all of `FUN_011f8680` or
`FUN_011f8120`, execute the original boot, or resolve non-null alternate
presenters. The window token, device setup fields, frame-owner state, SDL
window, and host-device binding remain Android harness inputs.

The updated `arm64-v8a` APK built and ran on the `2303ERA42L` phone
(ADB serial `PJMZAEJRX4YLFIDI`, Android 15/API 35). APK SHA-256:
`C3B58B8B20A56FECDA611E6C713BB0AF32A29A4AE00E69BABECA0B6D65831274`.

| Step | Result |
|---|---|
| Guest device global begins at zero | PASS |
| Existing window-global setter and DXVK-native `CreateDevice` | PASS (`640x480` guest parameters) |
| CreateDevice output represented by guest token at `DAT_016f89d0` | PASS (`0x00010002`; no ARM64 pointer stored in guest state) |
| Present adapter validates and consumes the device-global token | PASS |
| Manual graphics probe, window-global increment, D3D9 bridge regression | PASS |
| Original Spore boot/startup functions | NOT RUN |
| Stop point | Probe SDL loop immediately after `Present`; original app/Canvas/renderer initialization remains disconnected |

The phone logs for this build are:

- [d3d9-bridge-regression-after-device-global-2026-11-05.log](./test-logs/d3d9-bridge-regression-after-device-global-2026-11-05.log)
- [translated-graphics-manual-regression-after-device-global-2026-11-05.log](./test-logs/translated-graphics-manual-regression-after-device-global-2026-11-05.log)
- [translated-window-global-increment-after-device-global-2026-11-05.log](./test-logs/translated-window-global-increment-after-device-global-2026-11-05.log)
- [translated-device-global-increment-2026-11-05.log](./test-logs/translated-device-global-increment-2026-11-05.log)

The source and documentation diff for this increment is
[graphics-device-global-2026-11-05.diff](./graphics-device-global-2026-11-05.diff).

## FUN_0075f030 dimension-pair increment — 2026-11-05

The earlier width-only probe incorrectly copied the second argument into the
width field. Its `480x480` test values concealed the inversion. That increment
is superseded; its dated source/log artifacts are preserved as historical
regressions, not evidence that the old field mapping was correct.

This pass checked the assembly of the current installed `SporeApp.exe`
(SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`):

- In `FUN_007e7380`, instructions `0x7e73bf`–`0x7e73d0` push `0, 0, 0x1e0,
  0x280` in right-to-left order before the virtual call at `+0x14`. The callee
  therefore receives width `640`, height `480`, and two zero arguments.
- `FUN_0075f030` reserves `0x9c` bytes in its prologue (`SUB ESP, 0x9c`) and
  calls `FUN_011f8340(2)` with the local structure at `[ESP+0x34]`. The
  initializer writes default dimensions at structure offsets `+8/+0xc`
  (`1024x768`). After that call, instructions `0x75f25e`–`0x75f28e` read
  width from `[ESP+0xbc]` and height from `[ESP+0xc0]`, then write those
  values to `[ESP+0x3c]` and `[ESP+0x40]`, the same structure's `+8/+0xc`.
- `FUN_011f8680` consumes width from `[ESI+8]` and height from `[ESI+0xc]`
  (instructions `0x11f879c` and `0x11f8792`, respectively). The x86 guest
  structure remains 32-bit; Android stores no ARM64 pointer in these fields.
- Before `CreateDevice`, `FUN_011f8680` calls `FUN_011f7d00` with this
  structure. `FUN_011f7d00` copies offsets `+8/+0xc` into
  `DAT_016f8b9c/DAT_016f8ba0` (width/height), replacing either zero with one.
  `FUN_011f8680` passes `&DAT_016f8b9c` to the D3D9 `CreateDevice` vtable call.
  The selected nonzero test dimensions therefore traverse both the connected
  structure fields and the device-creation presentation-parameter globals.

The connected translated block now copies both arguments together into
`back_buffer_width` and `back_buffer_height` immediately before the existing
CreateDevice/registry path. Its inputs are explicit harness values, not the
result of executing the complete `FUN_007e7380` call chain. The other 12 DWORDs
in `SporeGuestPresentParameters32`, other D3D state fields, window adaptation,
and D3D options remain manual.

For a differential check, `tools/test_graphics_parameter_x86_reference.cpp`
extracts and executes the original 49 x86 instruction bytes from
`FUN_0075f030` at `0x75f25e`–`0x75f28e` in a Windows x86 process. The shared
dimension-copy helper is compared with those reference outputs for `1280x720`
and `480x900`. This executes that original parameter-copy block only; it does
not run the game or claim a full Spore runtime observation. Run it with
`tools/test_graphics_parameter_x86_reference.ps1`.

The Android device-global probe now uses `1280x720` so width/height inversion
is observable. On the `2303ERA42L` phone (ADB serial `PJMZAEJRX4YLFIDI`,
Android 15/API 35; tested APK SHA-256
`8da9a118e04e0e25be9a34726d5d3b9c8d7f034f80ce3fa80dfc177c8404aeb1`), the
translated pair reached `CreateDevice` as `1280x720`. The first successful
`Present` followed a successful `Reset` to the phone's drawable size
`2400x1080`. A temporary display override produced a successful
`2400x1200` Reset; restoring the display size produced another successful
`2400x1080` Reset. The physical display size was restored to `1080x2400`.
Thus, the CreateDevice dimensions, each Reset input/result, and the first
successful Present are distinct observations; the phone-size Reset occurs
before the first Present.

The same device run rejected zero, unknown, and invalidated guest tokens
without dispatching Present to the device; it recorded 245 valid dispatches
before invalidation and three successful Resets. Regressions were rerun
separately: the D3D9 bridge smoke test, the manual translated graphics probe,
and the prior window-global translated probe all passed.

Static REA Evidence for this round, all for the executable digest above:
`ev_692aba3c06cdcc46ee18f3f7f09990fbab19a7aae35e9cc3ec470f88bd49793b`
(`FUN_007e7380`),
`ev_e7803d79515551d1e03f65ff7025438645655190c27e97d914cbea0edb4de433`
(`FUN_0075f030`),
`ev_d3fefb821720552103b691042b299ab439ba3a3a1e382164c332de8d5dae9e9f`
(`FUN_011f8680`), and
`ev_4cb21b0d6393e11826a3f9404530fddf1bdf89dff199b692189148b6df5b3b41`
(`FUN_011f8340`), plus
`ev_c5b9cbf94d9ffee7afe43919aa70a63218141e2973fcec3fd52fea4de6da0ae1`
(`FUN_011f7d00`). This is static mapping plus execution of the isolated
original x86 instruction block, not execution of the original game's startup.

The reproducible x86 differential log is
[translated-graphics-x86-reference-2026-11-05.log](./test-logs/translated-graphics-x86-reference-2026-11-05.log).
The phone device-global run and separate regressions are recorded in:

- [translated-device-global-dimensions-2026-11-05.log](./test-logs/translated-device-global-dimensions-2026-11-05.log)
- [d3d9-bridge-regression-after-dimension-pair-2026-11-05.log](./test-logs/d3d9-bridge-regression-after-dimension-pair-2026-11-05.log)
- [translated-graphics-manual-regression-after-dimension-pair-2026-11-05.log](./test-logs/translated-graphics-manual-regression-after-dimension-pair-2026-11-05.log)
- [translated-window-global-increment-after-dimension-pair-2026-11-05.log](./test-logs/translated-window-global-increment-after-dimension-pair-2026-11-05.log)

The earlier ADB blocker remains as historical context in
[translated-graphics-device-run-blocked-2026-11-05.log](./test-logs/translated-graphics-device-run-blocked-2026-11-05.log); it is superseded by
the successful device run above.

## FUN_0075f030 presentation-mode block and device recreation — 2026-11-05

This increment was checked against the selected local `SporeApp.exe`
(SHA-256
`fb66afc320730dec6f80b79301c7c525689859e3d0a99616b657559e8f11a1ae`).
After the already validated dimension writes, the x86 instructions at
`0x75f29f`–`0x75f2b6` write three adjacent dwords in the setup block:

| Setup offset | x86 value | Mapping / Android result |
|---|---:|---|
| `+0x14` | `0x16` | Preserved as `original_setup_field_14`; `FUN_011f7d00` does not use this field. |
| `+0x18` | `0x15` | `BackBufferFormat = D3DFMT_A8R8G8B8` (`21`). |
| `+0x1c` | `0x4b` | `AutoDepthStencilFormat = D3DFMT_D24S8` (`75`). |

`FUN_011f7d00` supplies the semantic mapping: it copies setup `+0x18` to
the D3D9 backbuffer format and setup `+0x1c` to the auto-depth format. The
translation writes only those two D3D fields and the observed, otherwise
unmapped guest dword. The x86 differential executes these exact 24 original
bytes and compares all three outputs. Surrounding sentinel fields remain
unchanged. This block has no conditional branch.

The Android device-global probe now replaces the previous manual
`BackBufferFormat = UNKNOWN` seed with this translated output. The translated
depth format is recorded as `75`, but `EnableAutoDepthStencil` remains the
harness's explicit `FALSE`; the original wrapper's separate initialization of
that field was not part of this block.

| Preparation | Status after this increment |
|---|---|
| Backbuffer width/height (`1280x720` in the phone run) | Translated from the dimensions block of `FUN_0075f030`; no longer seeded manually in the device-global probe. |
| Setup `+0x14`, backbuffer format, depth format | Translated as `0x16`, `21`, and `75`; `+0x14` has no identified D3D9 consumer. |
| Adapter `0`, device type `1`, behavior flags `0x40`, window token | Still supplied by the harness; the window token is resolved through the guest-window mapping. |
| Backbuffer count `1`, multisample/quality `0`, swap effect `1`, flags `0`, refresh `0`, interval `1` | Still prepared by the harness. |
| Device-global `Windowed` | Explicit harness input `TRUE`; no configuration key is currently connected to this field. The prior `0x00d77e9b` connection was incorrect and is removed. |
| `EnableAutoDepthStencil = FALSE` | Still explicit harness state; the separate original initialization is outside this block. |

Thus, this increment removes manual setup for the translated dimensions and
the three observed setup dwords. `Windowed` and `behavior_flags` remain
harness inputs pending translation of their complete original consumers.

### Device-token recreation regression

Guest device tokens are now allocated from a process-wide monotonic 32-bit
sequence rather than reusing `0x00010002`. Invalidation and device release do
not recycle IDs; allocation fails if the nonzero token space is exhausted.
Creating through the global adapter also requires the guest device global to
be zero, instead of silently clearing a possibly live token.

The phone regression performs create → invalidate/release → create again,
then tries the old token both through the guest global and directly through
the registry. On the `2303ERA42L` phone, old token `0x00010002` was rejected
without another Present dispatch, new token `0x00010003` presented
successfully, and the second token was rejected after its release. Zero and
unknown tokens remain rejected as before.

The final device run sent `CreateDevice` `1280x720`, format `21`, depth format
`75`; `EnableAutoDepthStencil` was `FALSE`, and refresh rate was `0`. It then
observed successful Resets at `2400x1080`, `2400x1200` under a temporary
display-size override, and `2400x1080` after restoring the physical size.
The first successful Present followed the first Reset. All three Resets and
the recreated-device Present succeeded. The physical display returned to
`1080x2400` and density to `440`.

`FUN_0075f030` also obtains the DWORD at guest key address `0x00d77e99`
through `FUN_006a2660`; that getter returns zero when no record is found.
`FUN_006a25a0` is the boolean getter used by the graphics path, and a missing
or unsupported typed record produces false. Earlier probe fixtures were
removed from the Android `CreateDevice` path; the original game's store remains
unloaded and its values are still unobserved.

## Correcting the graphics-property mapping — 2026-11-06

The prior Android consumer treated the boolean at key `0x00d77e9b` as
`D3DPRESENT_PARAMETERS.Windowed`. That association was incorrect. The
SporeModder FX property registry names `0x00d77e9b` as `HardwareVP` and
`0x038d0a09` as `fullscreen`; registry names are supporting evidence, not proof
that either key is queried at a particular callsite.

The x86 data flow in `FUN_0075f030` distinguishes the fields:

- `0x75f1cb: PUSH 0x00d77e9b` and `0x75f1d7: CALL 0x006a25a0` query
  `HardwareVP` as an immediate key.
- The getter result is packed into `uVar15`; `uStack_70` is set to
  `((char)(uVar15 >> 8) == 0)`. This is structure offset `+0x2c`, copied to
  global `DAT_01712470`.
- `FUN_011f8680` reads `DAT_01712470` at `0x11f8704` and `0x11f8760` while
  selecting `BehaviorFlags`. The branch also depends on `DAT_01712474` and
  device-capability bits at `[ESP+0x38]` (`0x10000` and `0x100000`); the
  property is therefore not itself a complete `BehaviorFlags` value.
- The wrapper pushes the returned-device pointer and presentation pointer at
  `0x11f8735` and `0x11f873a`, then pushes the selected `EAX` as
  `BehaviorFlags` at `0x11f873f`, followed by the focus window, device type
  and adapter. It dispatches `IDirect3D9::CreateDevice` through vtable offset
  `+0x40` at `0x11f874e`.
- The temporary structure's distinct `+0x24` field is assigned as
  `(uint)pvStack_c & 0xff`, where `pvStack_c` is the saved x86 exception-list
  pointer. `FUN_011f7d00` reads `[param+0x24]` at `0x11f7d50` and `0x11f7d6c`;
  it writes the zero-test result to `DAT_016f8bbc`, which is
  `D3DPRESENT_PARAMETERS.Windowed` at offset `+0x20`. The wrapper does not
  read the `+0x2c` field.
- A bounded scan of the 116 available JSON export files found no instruction
  operand `0x038d0a09`. This does not prove that no unexported or indirect
  path queries `fullscreen`; its connection to this `CreateDevice` chain is
  unverified.

The consumer was corrected: the Android device-global probe no longer feeds
the `HardwareVP` fixture to `Windowed`. It sets `Windowed=TRUE` explicitly as
harness state, and `behavior_flags=0x40` also remains a harness input until
the capability-dependent translated selection is implemented. No claim is
made that the community `fullscreen` ID substitutes for an original query.

The x86 regression keeps the previous getter cases: inline false/true and
noncanonical true, indirect true/false, cached false/true, unsupported type,
missing key, and uninitialized-store behavior. It now also executes the
original `FUN_011f7d00` wrapper with `+0x24` and `+0x2c` varied independently.
`Windowed` follows only `+0x24` across all four combinations. These are
isolated function tests, not game-startup execution.

`1280x720` remains test input through the already-validated dimensions block.
The translated depth format remains `75`, while
`EnableAutoDepthStencil=FALSE` remains explicit harness state. The prior phone
log with `HardwareVP` connected to `Windowed` is historical and is not
evidence for the corrected mapping.

Run the x86 regression against the analyzed PE with:

```powershell
.\tools\test_graphics_parameter_x86_reference.ps1 -PePath C:\SporeAnalysis\SporeApp.exe
```

The analyzed PE SHA-256 is
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`. The
same test also passed against the previously used PE
`fb66afc320730dec6f80b79301c7c525689859e3d0a99616b657559e8f11a1ae`.

The corrected debug APK ran on phone `2303ERA42L`. `CreateDevice` succeeded
with explicit harness values `Windowed=TRUE` and `BehaviorFlags=0x40`, and
translated dimensions `1280x720`, format `21`, and depth format `75`
(`EnableAutoDepthStencil=FALSE`). One `Reset` to `2400x1080` succeeded before
the first successful `Present`. On exit, the create → invalidate/release →
create regression also passed: the old token `0x00010004` was rejected and
the new token `0x00010005` presented successfully. The APK SHA-256 was
`3c21ea35be8809c564a16270407bd1fa956a208f99bb3ba6f26570a517e73e89`.

Logs:

- [graphics-property-mapping-x86-2026-11-06.log](./test-logs/graphics-property-mapping-x86-2026-11-06.log)
- [graphics-property-mapping-x86-legacy-2026-11-06.log](./test-logs/graphics-property-mapping-x86-legacy-2026-11-06.log)
- [graphics-property-mapping-device-2026-11-06.log](./test-logs/graphics-property-mapping-device-2026-11-06.log)

The Android debug build succeeded after the correction.

### Configuration-origin follow-up — 2026-11-05

The original executable was identified as `SporeApp.exe`
(SHA-256 `fb66afc320730dec6f80b79301c7c525689859e3d0a99616b657559e8f11a1ae`).
Static inspection confirms the query argument at the graphics consumer:
`0x75f1cb: PUSH 0xd77e9b`, `0x75f1d0: MOV ECX, ESI`, and
`0x75f1d7: CALL 0x006a25a0`. The key is an immediate value. This does not show
whether a matching record exists in a valid run, or where its value originates.
Earlier in the function, `ESI` is loaded from `DAT_015fd918`; that identifies
the static source of `ECX`, but not the runtime pointer value.

The bounded producer trace found:

- `FUN_006a2e20` has resolved direct callers `FUN_006a30c0`,
  `FUN_00bed460`, and `FUN_00bed920`; Ghidra marks this caller inventory
  partial and reports two omitted call references.
- `FUN_006a30c0` updates indexed values when the key is below the cached count
  and otherwise delegates to `FUN_006a2e20`. No direct code caller was
  resolved for this function; an xref points to data at `0x01408884`, which
  does not by itself establish the indirect caller.
- The two other resolved insertion callers pass key `0x049b48ee`, not
  `0x00d77e9b`. `FUN_0067e050` stores the configuration object in
  `DAT_015fd918`; that singleton assignment does not identify a producer for
  this record.

The requested runtime capture was not possible in this environment. The game
was not running; REA's local Frida device discovery failed because its native
binding is missing, Windows process capture is not supported by the available
REA host workflow, and no local x86 debugger command was found. Consequently
there is no runtime argument/`ECX`/return/record-presence observation. Neither
presence nor absence of the key is established. The insert/update call chain
is generic and does not establish a file, default, argument, or other startup
source for this key.

No initialization block was selected or integrated: substituting a guessed
default would not replace original initialization. The former Android
`origin=test-fixture` log described the now-removed `HardwareVP`-to-`Windowed`
connection; it is not current Android state. The x86 getter fixture remains a
test only. Next required evidence is a valid PC run captured at the getter,
followed by tracing the actual record producer (including indirect calls) or
confirming that the record is absent and the original false default is
consumed. See
[config-windowed-origin-static-2026-11-05.log](./test-logs/config-windowed-origin-static-2026-11-05.log)
for the instruction evidence, bounded producer results, Evidence IDs, and
capture limitation.

Static REA Evidence for the selected `fb66afc3...` executable:
`ev_7d1506aa29a5fffd7c02c0897950a6d96270373ed1929ce9c41874b09907c446`
(`FUN_0075f030`),
`ev_15f45565384cef85ec41742b66579ee99dd427d74ebd3432eb5f40648cdbf909`
(`FUN_011f8680`),
`ev_c5e9f77ecfe928ef9d212342e152db68b287cda28edc640a0dde5860608f5285`
(`FUN_011f7d00`),
`ev_00a03ac85115fff2e49126aeffd9b9819cb83b876616ddf89169f41f88a685e2`
(`FUN_006a2660`), and
`ev_f07c78705a4488c04400451914d0d9148471f91e0c752c3e61bad0d58123488d`
(`FUN_006a25a0`). The query/storage follow-up uses
`ev_aaa860779ea206790700990a744482184727c5d6379238e79df4e4901304e7e7`
(`FUN_006a25a0` assembly),
`ev_dcdf64b47221a9bafd9d2cf7adfe81592e60fa39175d94c6bc93fe4e30969f3f`
(`FUN_006a30c0`),
`ev_dbf48abdf9e99364426630af77b2e245f7139fc7733c00ab279f10927f93871`
(`FUN_006a2e20`),
`ev_7e44cbc4b6b2651d13b99f4b325c23fd2a84fbcb2a7638c5fd39daf923ad9661`
(`FUN_0067e050`), and
`ev_27179cee85a7e5ec23d2848738a077ed60fb93a9412b70a2a9e82a33ea99acbf`
(setter xrefs). This is static analysis plus execution of selected original
x86 instruction blocks; it is not execution of the Spore boot path.

The x86 differential and all three phone regressions were rerun against the
then-current debug APK. Its SHA-256 is
`e01675ee3ab095cb9cbd9e039e9179617d0096ef37c6541992684c9d7679b56a`.
The earlier incomplete recreation attempt is retained as a diagnostic log,
superseded by the successful recreation run below.

Logs:

- [translated-graphics-x86-reference-2026-11-05.log](./test-logs/translated-graphics-x86-reference-2026-11-05.log)
- [translated-presentation-mode-device-recreation-2026-11-05.log](./test-logs/translated-presentation-mode-device-recreation-2026-11-05.log)
- [translated-presentation-mode-device-recreation-failed-2026-11-05.log](./test-logs/translated-presentation-mode-device-recreation-failed-2026-11-05.log) (incomplete diagnostic attempt; not a pass)
- [d3d9-bridge-regression-presentation-mode-2026-11-05.log](./test-logs/d3d9-bridge-regression-presentation-mode-2026-11-05.log)
- [translated-graphics-manual-regression-presentation-mode-2026-11-05.log](./test-logs/translated-graphics-manual-regression-presentation-mode-2026-11-05.log)
- [translated-window-global-increment-presentation-mode-2026-11-05.log](./test-logs/translated-window-global-increment-presentation-mode-2026-11-05.log)

## Build

Open the project in Android Studio and sync Gradle. It targets Android API 34,
requires API 26 or newer, and currently filters native builds to `arm64-v8a`.
The debug APK uses application ID `dev.sporeport.cellstage.dev` so it can be
installed alongside an older build without replacing its app data.

On Windows, with Android Studio's JDK and SDK installed:

```powershell
$env:JAVA_HOME = "C:\Program Files\Android\Android Studio\jbr"
$env:ANDROID_HOME = "$env:LOCALAPPDATA\Android\Sdk"
.\gradlew.bat assembleDebug lintDebug
```

The DXVK D3D9 smoke test is available from the launcher's video-test selector
as **Direct3D 9 via DXVK-native + Vulkan**. The test stores its state cache in
SDL's app-private preference directory.

## First connected Spore function chain — 2026-11-04

- **Milestone 1 — first real engine execution:** run the ARM64 recompilation
  of string lookup `FUN_00461520` over the table read from the original
  `SporeApp.exe`. Acceptance criteria: known SHA-256; 91 original records;
  16 adjacent inversions before sorting; sorted order verified; key
  `0xB1C3E5B6` resolves to `mean` at index 76 on Android. This is a small,
  verifiable engine path, not a game boot. DDF/Cell remains out of scope until
  its call chain is established.
- The importer-verified executable is SHA-256
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
- Ghidra identifies a direct call from `FUN_00461520` at `0x461520` to
  `FUN_00422430` at `0x422430`; the call instruction is at `0x461557`.
  The caller body is 132 bytes and the callee body is 122 bytes. The callee
  searches 12-byte records by their first unsigned 32-bit field.
- `native_runtime.cpp` now contains ARM64 C++ translations for both functions.
  The JNI entry reads the real table and strings from the user's imported PE;
  it does not bundle Spore data. APK inventory confirmed no `.exe` or `.dll`
  was packaged. The launcher exposes the chain only after checking the
  executable SHA-256.
- An x86 emulation of the exact bodies from this executable, with key
  `0xB1C3E5B6`, returned `mean`. The original callee bytes hash to
  `9e462a2ba95704cea43e451fb223991e23e9167f9c0d5e74d96074a2fc406947`;
  the caller bytes hash to
  `5f4ed698b1aad316fdbbf3cba6c468b5ac18cf9c497d2c50a26b1cddea7710e5`.
- `:app:assembleDebug :app:lintDebug` succeeds and produces the `arm64-v8a`
  JNI library. The debug APK SHA-256 is
  `ba8e3fd500fc1af4da125f5a9ccf9a043f11d86afe114766382345c5096cefa1`.
- The APK was installed and the chain was invoked on a physical
  `arm64-v8a`, Android 15 device. The UI displayed
  `0x461520 -> 0x422430: mean`, matching the x86 result; the imported PE's
  on-device SHA-256 also matched the expected hash. No native crash was
  observed.
- This is a connected JNI call chain, not a game boot. The PE's raw table is
  not monotonically ordered; `FUN_00403AF0` calls `FUN_004274A0` with its bounds.
  At this point, the previous on-device lookup had not reproduced that
  initialization step.

## Reproducing the string-table initialization step — 2026-11-04

- The original PE contains 91 consecutive 12-byte records at `0x150C050`,
  ending at `0x150C494`. The exact x86 `FUN_004274A0` was executed against the
  mapped original image with those arguments; all 91 keys became monotonically
  ordered as unsigned 32-bit values, with no duplicate keys.
- After sorting the original table, the exact x86 lower-bound lookup for
  `0xB1C3E5B6` returned `mean` at sorted index 76.
- The ARM64 JNI path now translates the original sort: median-of-three
  quicksort (`0x42B2D0`), insertion sort (`0x42B4E0`), and the original
  heapsort fallback helpers (`0x42DD80`, `0x42EDD0`, `0x42EE60`). It sorts a
  copy of the verified PE table inside the translated `0x461520` lookup flow,
  before `0x422430`; it does not claim to execute the entire
  `FUN_00403AF0` initializer.
- Instrumenting the original x86 execution on these 91 records observed six
  entries to `0x42B2D0`, one to `0x42B4E0`, and none to the heapsort fallback.
  The ARM64 action returned the same `mean` at sorted index 76, and also checks
  that every adjacent key is in unsigned ascending order.
- The translation still reads the user's verified PE and packages no game
  executable or assets. This advances one initialization dependency but does
  not establish that the lookup is reached in the game's live boot path.
- `:app:assembleDebug :app:lintDebug` passed after the change. The APK SHA-256
  is `426edc77dd075c7436781075a199877fe4641f9ce8669e55df919a55b00df526`;
  APK inventory contains the ARM64 JNI libraries and no `.exe` or `.dll`.
- The debug APK's application ID is `dev.sporeport.cellstage.dev`; it was
  installed separately from the existing `dev.sporeport.cellstage` app. The
  previously present PE in debug-app storage had a different hash, so it was
  preserved as a sibling backup and the verified original PE was copied into
  the debug app's external files. Its on-device SHA-256 is
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
- On the connected `arm64-v8a` Xiaomi 2303ERA42L (Android 15), invoking the
  debug app's existing chain action displayed
  `ARM64 0x461520 -> 0x4274A0 -> 0x42B2D0/0x42B4E0 -> 0x422430 (index 76): mean`.
  The process remained alive; its PID-filtered log contained no fatal
  exception or native crash. This is native execution of the connected
  recompilation chain, not a game boot.
- The launcher action is now labelled Marco 1 and reports the verified PE hash,
  original record count, original ordering inversions, translated path, key,
  result index and string. It only displays PASS when the native function
  returns its success report. The updated APK was installed on the connected
  Xiaomi 2303ERA42L (`arm64-v8a`, Android 15) and the action was run again.
  The on-device UI reported `MARCO 1 — EXECUÇÃO REAL PASS`, the expected
  executable SHA-256, 91 records, 16 inversions, and `mean` at index 76. The
  app process remained alive; the recent PID-filtered log showed no fatal
  exception or native signal. A screenshot is saved as
  `files/marco1-android-pass.png` in the session artifacts. This verifies the
  updated result presentation and the connected native ARM64 lookup using the
  user's original Spore executable; it is still not a game boot.
- `:app:assembleDebug :app:lintDebug` passed after the Marco 1 UI/report
  update. The APK SHA-256 is
  `a3a4385b956b512458ac3722aef570bc648176e7e362a86dbf09e458ce8185e3`.
  APK inventory contains the ARM64 runtime libraries and no `.exe` or `.dll`;
  Spore data remains user-imported, not bundled.
- The same path now validates every real table key before reporting success:
  all 91 keys resolve through the translated lower-bound to their original
  record (including value pointer and reserved field), and `0xDEADBEEF` is
  confirmed absent and resolves to the original fallback string `unknown`.
  The updated APK passed `:app:assembleDebug :app:lintDebug`, has SHA-256
  `ea3f6c6587ce6b94c994bcf24ce776b514210696c52f210b15bf24d9c4de244a`,
  and was installed and executed on the same Android 15 device. The UI showed
  `91/91` and `unknown`; the app remained alive with no fatal exception or
  native signal in its PID-filtered log. Capture: `files/marco1-allkeys-pass.png`.
  This broadens verification of the same small lookup path; it does not add
  another engine subsystem or prove game boot.
- The table-sort translation is now shared in
  `app/src/main/cpp/spore_string_table.hpp`, used by the Android JNI path and a
  Windows x86 differential harness. `tools/run_x86_sort_differential.ps1`
  verifies the reference PE hash, maps its exact `.text` bytes without loading
  the game process, executes original `FUN_004274A0`, and compares its output
  with that same shared C++ implementation. The exact ordered records matched
  in 141 cases: the original 91-record table, sorted/reversed/rotated inputs,
  128 deterministic permutations, and small sizes around the insertion-sort
  boundary. Guard records also remained unchanged. This is a differential
  check of the actual sort function, not a game boot.
- After sharing the implementation, `:app:assembleDebug :app:lintDebug`
  passed and the new build was installed and executed on the Xiaomi 2303ERA42L.
  The screen again reported `91/91` real keys, missing-key fallback `unknown`,
  and `mean` at index 76; the app process remained alive and its filtered
  recent log had no fatal exception or native signal. The updated APK SHA-256
  is `6aa664b94f27286aef42286ce2f7e63b25896e75fabde1be170fa33693d2c4c3`.
  Capture: `files/marco1-sharedsort-pass.png`.

## Linking Editor initialization to the boot path

- On the same reference PE, `FUN_00F47ED0` calls `FUN_005D67F0` directly at
  `0x00F4810F`. In the surrounding pseudocode, it first requests a `0x48`-byte
  `"Editor"` object through `FUN_00F473A0`, calls the constructor when allocation
  succeeds, then passes the result to `FUN_00F47630`.
- `FUN_005D67F0` is a 73-byte constructor. It installs pointers based at
  `0x013F8BF4` and `0x013F8BF0` and initializes the object's remaining fields.
  The former table includes a pointer at `0x013F8C08` to code at `0x005D7520`.
- When the allocation succeeds and the new object differs from the currently
  stored object, `FUN_00F47630` dispatches the new object's vtable slot `+8`.
  With the constructor-installed table, that slot resolves to
  `FUN_00C6A960` (`0x00C6A960`), whose body increments the object's field at
  `+8`. This confirms a conditional, statically connected boot path through
  real Spore functions; it does not demonstrate that the path ran at runtime.
- This narrows the boot investigation to a real object-construction path, but
  does not prove that the method at `0x005D7520` is called during startup:
  Ghidra does not recognize it as a function, and the known direct call at
  `0x005D8240` targets `FUN_00417D10` instead. The surrounding
  `0x005D751A`–`0x005D87AF` code remains an unclassified region, so neither its
  complete function boundaries nor the method's boot-time reachability are
  established.
- The static decompilation shows `FUN_00F47ED0` returns failure when
  `SteamAPI_Init` fails, before reaching this constructor. The user's report
  that their PC copy launches without opening Steam means this is not yet a
  confirmed runtime blocker. No bypass or synthetic execution path was added.
  The new evidence therefore supports tracing the real initialization path,
  but does not yet justify integrating this constructor as an isolated Android
  test or claiming game startup.

## Reading a real DBPF resource on Android

- The Android JNI build now includes the existing `dbpf_reader` implementation.
  `nativeReadDbpfResource` opens a package from the imported game tree, resolves
  an exact TGI, and returns the decoded payload, with a 64 MiB per-resource
  output limit. The launcher exposes the operation for the known
  `cell_Eggkid` resource (`0xDFAD9F51:0x00000000:0x7ADE24E1`).
- `:app:assembleDebug :app:lintDebug` completed successfully for the
  `arm64-v8a` build. Lint reported warnings; its task succeeded.
- The resulting debug APK SHA-256 is
  `c35b46452b4981477c7ddaf31aa9e5db317f3730f2d78a99ebeef45be4bcc9b2`.
- The updated debug APK was installed over the existing
  `dev.sporeport.cellstage.dev` app on the physical Xiaomi 2303ERA42L
  (`arm64-v8a`, Android 15). It read
  `Spore/Data/Spore_Game.package` from the imported installation and reported
  796 decoded bytes with SHA-256
  `ac291c1cd5cb91d78fbe8e4420a40e8c2aaaa1632d4c6b2d2edeb822174a2ec8`,
  matching the independently verified PC result. The app process remained
  alive after the read.
- Rechecked on the same device on 2026-11-05: the installed app again reported
  the verified PE hash, `MARCO 1 — EXECUÇÃO REAL PASS` with 91/91 lookups and
  `mean` at index 76, then independently read the same 796-byte `cell_Eggkid`
  payload with the matching SHA-256. The app process remained alive. These
  buttons are separate paths; the DBPF reader is not called by the translated
  lookup or by the original game's Cell startup.
- This verifies DBPF parsing, TGI lookup, and resource decompression through
  the Android ARM64 JNI path on a real game package. The launcher button still
  invokes the reader directly; this is not yet a call from translated game
  code, package mounting/precedence, or a game boot.

## Following the actual DDF resource path

- On the same reference PE, Ghidra decompiles `FUN_008d7960` (`0x8D7960`) as
  the routine that conditionally loads `DDFMap.txt`, iterates parsed records,
  and sends them to `FUN_008d77a0`. The latter skips names `DDFMap` and
  `DDFList`, then passes other entries to `FUN_008d5e10`.
- The owning setup chain is now clearer: `FUN_00e819b0` calls
  `FUN_00e4cde0`, which reaches `FUN_00e4cad0` and creates the `"Simulator"`
  object using the `CellGame/` root. That setup appends `Binary/` and invokes
  the DDF object constructor `FUN_008d7400`; its stored base path is then used
  by the DDF loader. This establishes the expected loose-file location as
  `CellGame/Binary/DDFMap.txt` for this path, but not that the setup chain runs
  during application startup.
- `FUN_008d61e0` resolves names against the loaded DDF list, with a hexadecimal
  ID fallback. The related `FUN_00e4c440` enumerates `*.cel` files under the
  `CellGame/Binary/` path. These observed operations use filesystem helpers;
  they do not establish a DBPF lookup or a connection to the Android DBPF
  reader.
- `FUN_00e54270` is shared by `FUN_00e819b0` and `FUN_00e81120`. Its body
  initializes UI state and creates objects under `Simulator/Cell/UI`; the
  `FUN_00e81120` caller is an input/event handler, and its switch case `0x52`
  invokes `FUN_00e54270(0)`. This confirms that the UI helper participates in
  the Cell subsystem's event handling as well as the `FUN_00e819b0` setup
  chain. It does not show when that setup chain runs or connect it to the
  application boot path.
- The body of `FUN_008d7960` has no resolved direct callers in Ghidra's call
  graph. Its observed incoming references are data references, including the
  slot at `0x1436758`; these do not prove that the method runs during startup.
- The observed map path uses file-system helpers (`GetFileAttributesW` /
  `CreateFileW` in the path traced to `FUN_008d6ed0`). No evidence yet connects
  this path to DBPF lookup, so the DBPF reader must not be wired here by
  assumption.
- A typed incoming reference shows `0xE81CBA` directly calling
  `FUN_00e819b0`, but Ghidra assigns no containing procedure to that call site;
  it is outside the analyzed body of `FUN_00e819b0`. The code at `0xE81C90`
  loads an object from its second stack argument, checks fields against
  `0x01654C00` and `0x01654C08`, then calls `FUN_00e819b0` on the matching
  path. Its address is pushed as an immediate argument at `0xE81E04` and
  `0xE82059`, each immediately followed by a computed `CALL EAX`
  (`0xE81E09` and `0xE8205E`). Both call sites belong to the recovered methods
  `FUN_00e81cf0` and `FUN_00e81f30`. The vtable words at `0x1485560` and
  `0x1485564` point to those methods. Their object is created by
  `FUN_00e616c0`, which is called by raw vtable target `0x00b5c990` on the
  startup path described below; the constructor then passes the object and values
  `0x01654c00`/`0x014856d0` to an indirect manager method at slot `+0x20`.
  This links the handler object and its callback arguments to a conditional
  startup path, but the manager and callback call targets remain unresolved.
  It does not prove that `0x00e81c90` runs or that its conditional call to
  `FUN_00e819b0` is taken. The earlier description of `0xE81CBA` as a
  self-call was inaccurate.
- The remaining blocker is resolving the indirect manager/callback dispatch
  and whether the handler methods execute from startup. In addition,
  `FUN_00e81120` has no resolved external caller; its caller inventory reports
  two call references omitted from recognized procedures, at `0xE8195F` and
  `0xE8198E`. The DDF manager's relation to this startup path is also
  unresolved. Do not implement an Android bridge for this subsystem based on
  the current evidence alone.

## Tracing the PE entry point to the game bootstrap

- The reference is a PE32 x86 image with image base `0x400000` and entry RVA
  `0xDE11A0`, giving entry VA `0x11E11A0`. Ghidra identifies this as `entry`;
  it calls `___security_init_cookie` at `0x11E1548` and then
  `___tmainCRTStartup` at `0x11E0EE0`.
- The CRT startup calls `FUN_00f48a20` at `0xF48A20`, which calls
  `FUN_00f48850`; that function calls `FUN_00f47ed0` at `0xF47ED0`. This is a
  statically resolved chain from the PE entry into the game's startup
  routine, not runtime evidence.
- `FUN_00f47ed0` first calls `SteamAPI_Init` and returns zero immediately when
  it reports failure. This is the earliest explicit gate observed in the
  analyzed game-startup body. The user reports the tested PC copy launches
  without opening Steam; the call's actual return in that environment has not
  been traced, so this is not evidence that Steam is required at runtime.
- After that gate, `FUN_00f47ed0` initializes several managers and invokes
  virtual methods, including a method passed `Spore_DDFList.txt`, before
  registering/dispatching `AppInit`. The analyzed body contains no direct
  call to `FUN_00e819b0` or `FUN_00e81120`. Its virtual calls may dispatch
  dynamically, so this does not prove those functions are unreachable.
- One such startup branch is now resolved through its vtable dispatch:
  `FUN_00f47ed0` calls `FUN_00b5e020`, which constructs an object with vtable
  `0x1462810`; it stores that object at `[ESI+0x3c]`, then invokes its virtual
  slot `+0x24`. The vtable word at `0x1462834` points to raw code at
  `0x00b5c990` (Ghidra does not assign it to a containing function); its
  disassembly calls `FUN_00e616c0`, the constructor that installs the vtables
  previously tied to the Cell-related handlers. `FUN_00e616c0` allocates a
  `0x0c`-byte object,
  sets its primary vtable pointer to `0x1485550`, and passes it with
  `0x01654c00` and `"Game_Cell"` to the manager slot `+0x20`. The vtable words
  at `0x1485560`/`0x1485564` point to `FUN_00e81cf0`/`FUN_00e81f30`; these
  methods pass `0x00e81c90` to further indirect calls. A separate vtable word
  at `0x1485568` points to `0x00e552f0`.
  The manager also has a static selection path: `FUN_007d8360` compares the
  registered record name case-insensitively, then routes a matching index via
  slot `+0x40` (`FUN_007d8c80`) to `FUN_007d85b0`. That method updates the
  selected index and calls the selected record object's vtable slot `+0x18`.
  For the registered `Game_Cell` object, this slot resolves to `0x00e552f0`.
  The manager constructor initializes the selected-index field at `+0x28` to
  `-1`, so registration alone does not select or invoke the handler. The
  defined `"Game_Cell"` string at `0x14856d0` has one analyzed xref, from the
  registration call at `0x00e616f9`; no selection caller has been identified.
  Code at `0x00e552f0` calls `FUN_00e55120`; that function hashes and queries
  the names `cell_motion`, `cellgame_seed_music`, and `cell_amb` through
  `FUN_00e82620`. This establishes a concrete static registration-to-handler
  dispatch candidate, but runtime execution and a call to `FUN_00e819b0` remain
  unproven. The precise startup gate conditions and whether this path is taken
  at runtime remain unverified.
  Follow-up tracing shows that this helper is an audio-system path, not a
  direct DBPF lookup: `FUN_00e82620` hashes the name, calls the shared object's
  slot `+0x20` to dequeue a value, then routes the hash and value through
  `FUN_00435ed0` (or `FUN_00571f80` when its optional descriptor is present).
  `FUN_00a252b0` stores that object in `DAT_0166d9f4`; its constructor
  `FUN_00a32550` installs primary vtable `0x1452d28`. On that vtable, slots
  `+0x38` and `+0x40` are adjustor thunks into `FUN_00a102e0` and
  `FUN_00a10120`, which append typed records to a buffer; slot `+0x58` reaches
  `FUN_00a20ba0`, which invokes another virtual operation and performs cleanup.
  The slot `+0x20` implementation, `FUN_00a292d0`, also dequeues a value. The
  names used by Cell setup therefore do not establish that the Cell handler
  reads those DBPF resources; their exact audio meaning remains unknown.
  Other defined mode strings (`Game_Tribe`, `Game_Civ`, `Game_EditMode`,
  `Game_Creature`, and `Game_Space`) each have one analyzed reference in
  separate registration routines, which also call their supplied object's
  manager slot `+0x20`. The shared manager's name-lookup method is its vtable
  slot `+0x4c` (`0x14125e4` -> `FUN_007d8360`), and its matching-index
  selection method is slot `+0x40` (`0x14125d8` -> `FUN_007d8c80`). No
  resolved direct caller of `FUN_007d8360` is present in Ghidra's caller
  inventory; the callsites, if any, are indirect or otherwise unresolved.
  A bounded follow-up scanned the verified `.text` for the common
  `mov reg,[vtable+0x4c]; call reg` form and checked functions with references
  to `FUN_0067dd10`, the global-manager accessor. Of 416 incoming reference
  edges across 272 containing procedures, six procedures also contain a
  `+0x4c` virtual call, but the inspected register flows do not connect those
  calls to the accessor's returned manager pointer. This excludes only the
  checked call shape and register flows; cached or passed aliases, stack or
  memory flows, other instruction forms, and unresolved indirect calls remain
  possible. The selection caller is still unknown.
  Cross-checking the same 272 procedures for the manager's selection-slot
  instruction form (`mov reg,[vtable+0x40]; call reg`) found seven sites.
  The inspected sites dispatch on objects returned by another manager method
  (`+0x2c`) or by a separate helper; they do not establish a call to
  `FUN_007d8c80` on the manager itself. A separate scan found 17 such
  instruction forms in `.text` overall, so the shared vtable offset is not a
  reliable type identifier by itself. This remains a bounded static search;
  aliases and indirect flows can still hide the selection path.
  Raw code at `0x00b5c990` obtains the manager pointer through
  `FUN_0067dd10`, a load from global `0x15fd8b0`; the file-backed initial
  value is zero. Its initialization is now traced statically: `FUN_007e8ba0` calls
  `FUN_007d8dc0` at `0x7e9052`, stores the result at owner offset `+0xc8`,
  then calls setter `FUN_0067df00` at `0x7e9089` with that field. The factory
  allocates a `0x34`-byte object and installs primary vtable `0x1412598`.
  Teardown in `FUN_007e6470` calls the same setter with zero at `0x7e6572`.
  The manager's vtable slot `+0x20` (`0x14125b8`) points to `0x7d9260`.
  `FUN_00e616c0` creates the Cell-related handler and dispatches through that
  slot with the handler, `&DAT_01654c00`, and `"Game_Cell"`. Ghidra does not
  define `0x7d9260` as a procedure; its bytes were decoded from the verified
  PE instead. That method calls `FUN_007d90a0` on the manager's `+0x14`
  collection, which grows or updates an array of `0x18`-byte records. This
  establishes a concrete manager-backed registration path for the Cell
  handler, not a DBPF lookup or DDF file load. The startup branch is static
  evidence only; whether it executes at runtime and whether the registered
  handler later runs remain unverified.
- `FUN_00e819b0` is a distinct 484-byte analyzed function (`0xE819B0`–
  `0xE81B93`) that calls `FUN_00e4cde0`; its caller inventory has no resolved
  caller and reports one omitted call reference, matching the unclassified
  direct call at `0xE81CBA`. `FUN_00e81120` (`0xE81120`–`0xE8181F`) likewise
  has no resolved callers and two omitted references, at `0xE8195F` and
  `0xE8198E`. The tables at `0xE81820` and `0xE81880` are jump-table data for
  this event handler, not evidence of boot-time invocation.
- The startup trace now reaches a Cell-related constructor and resolves its
  manager's `+0x20` dispatch to the registration routine at `0x7d9260`. The
  next static step is finding the caller of the manager's name-lookup/selection
  path (`+0x4c`), followed by runtime confirmation. Neither DBPF consumption
  nor a call to `FUN_00e819b0` is proven. Do not wire the DDF path to Android
  DBPF based on this evidence alone.
  GNU `objdump` was unavailable in this environment; the PE entry RVA above
  was read from the image header and corroborated against Ghidra's `entry`
  function.
- Following the `CellGame/` preload further narrows that candidate: the
  `*.cel` enumerator `FUN_0092e730` builds a Windows path and calls
  `FindFirstFileW`; `FUN_0092e8e0` advances it with `FindNextFileW`, and
  `FUN_0092e9b0` closes the find handle. `FUN_00e4b870` probes this same
  directory for `*.cel`. In the local Steam install examined for this pass,
  the game data is in DBPF `.package` files and a recursive search found no
  loose `.cel` files or `CellGame` directory. This is evidence that this
  particular preload path expects files visible to Win32 directory
  enumeration; it does not show how or whether the shipped DBPF resources
  reach another Cell consumer. Treat this branch as a loose-file/development
  path, not as the first Android DBPF execution target. No device was
  connected during this pass, so there is no new runtime result.

## Applying the recovered `sporecomp2` catalog tools

- The supplied Python tools passed syntax checks, and `tools/selftest.py`
  passed. Running `build_catalog.py` against
  `C:\SporeAnalysis\out_recovered_update` produced a catalog for 90,872
  functions and identified 30 additional entries from the scanner/fix data.
- The recovered `fix_report.txt` confirms that `FUN_007d9260` was recovered
  from vtable `0x014125B8` and `FUN_00b5c990` from vtable `0x01462834`.
  Both are in the recovered `functions.csv`; neither existed in the earlier
  `out\functions.csv`. This directly resolves the two code addresses flagged
  in the supplied note. `0x0058DA6D` is a callsite, not a function entry; the
  strict clean project later confirmed it is inside `FUN_0058D430` and calls
  `FUN_004EB980`.
- `ExportLeaf.java` ran on the recovered Ghidra project and emitted 13,671
  candidates. `build_catalog.py --leaf` generated a queue with 6,917 tier-1
  integer-only candidates, 656 x87, 6,068 SSE/MMX, and 30 FS/special
  candidates. Outputs are under
  `C:\SporeAnalysis\sporecomp2_catalog_with_leaf`.
- This is a candidate inventory, not differential validation: the supplied
  folder does not include the pcrecomp lifter or a generic harness that consumes
  `lift_test_queue.csv`. The exporter also permits direct jumps, so tail-call
  thunks can enter the queue (for example `0x011E073E`); inspect/filter those
  before treating a row as an independent leaf test. No Android execution was
  performed.

### Strict clean-import comparison — 2026-11-05

- The `newtest` scripts were run on a fresh Ghidra project using
  `STRICT_ALIGN = true`: vtable runs with under 80% 16-byte-aligned targets were
  rejected, and only aligned targets in accepted runs were created as
  functions. The reference PE SHA-256 remained
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
- `FixFunctions` reports 31,704 created functions, all aligned to 16 bytes.
  The resulting catalog contains 89,921 functions, 743 candidate extra entries,
  and 1,046 conflicts; the prior recovered catalog had 90,872 functions, 30
  extras, and 3,191 conflicts. The scanner classified 3,167 runs as noise.
  These extras remain candidates, not verified function starts: the catalog
  builder also considers entries from accepted, mostly aligned runs.
- The report's function-manager total (`after=90,405`) differs from the
  89,921 rows exported to `functions.csv` by 484. This discrepancy is
  explained by 484 external functions: a read-only script against the saved
  project counted 90,405 total, 89,921 address-space functions returned by the
  export iterator, 495 external symbols, and 484 external function records.
  The remaining 11 imports are non-function symbols.
  `FUN_007d9260` (233 bytes) and `FUN_00b5c990` (55 bytes) are present at their
  expected addresses in both catalogs. `0x0058DA6D` is not an exact function
  entry; Ghidra confirms it is the `CALL 0x004EB980` instruction inside
  `FUN_0058D430`. The call is guarded by a conditional branch comparing
  `DAT_015DA6E4` with `BL`. This establishes a static callsite, not that the
  containing routine runs during startup or the Cell stage.
- The clean `ExportLeaf` run emitted 35,087 candidates versus 13,671 from the
  recovered project. Its queue has 18,393 tier-1, 912 tier-2, 15,749 tier-3,
  and 33 tier-4 candidates. This is a larger test inventory, not a differential
  or Android runtime result.
- Outputs are in `C:\SporeAnalysis\out_newtest_clean` and
  `C:\SporeAnalysis\sporecomp2_newtest_clean_catalog`. Ghidra resolved the
  `ExportSpore2` post-script from the global scripts directory rather than the
  staged copy, so its four reports were also written to `C:\SporeAnalysis\out`;
  those reports were copied into the clean output directory. The previous
  versions in `out` were overwritten, and no duplicate copies were found.

### Read-only boot call-closure and instruction-risk measurement — 2026-11-05

- `MeasureSporeBoot.java` opened the existing `SporeStrictClean` project with
  `-process -readOnly -noanalysis`. The source PE SHA-256 is
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
  The CSV reports are under
  `C:\SporeAnalysis\out_newtest_clean\boot_measurement`; the ad hoc script is
  session-local. The Ghidra project and game binary were not modified.
- Counts below are unique internal functions reached by following resolved,
  direct `CALL` references from each root. The traversal does not follow
  computed calls, vtable dispatches, tail-call jumps, or external function
  bodies. x87 counts use x87 mnemonics; SIMD/MMX counts use XMM/YMM/ZMM/MM
  operands plus the MMX/SSE state-control instructions; FS counts use
  instructions whose rendering contains an `FS:` access. The risk categories
  overlap and measure static instruction presence, not executed paths.

  | Root | Direct functions | Indirect call sites | x87 funcs / insns | SIMD/MMX funcs / insns | FS funcs / insns |
  | --- | ---: | ---: | ---: | ---: | ---: |
  | PE entry `0x11E11A0` | 623 | 501 | 19 / 158 | 50 / 459 | 62 / 214 |
  | App loop wrapper `FUN_00f48850` | 611 | 488 | 19 / 158 | 50 / 459 | 60 / 209 |
  | App entry wrapper `FUN_00f48a20` | 614 | 488 | 19 / 158 | 50 / 459 | 60 / 209 |
  | Init routine `FUN_00f47ed0` | 594 | 472 | 19 / 158 | 49 / 456 | 59 / 206 |

- These strict-project counts do not reproduce the previously cited 606.
  Until the root and inclusion rules behind that number are identified, treat
  it as unverified. The 611-function closure from `FUN_00f48850` is the useful
  direct-call baseline for the app loop, not a complete runtime closure:
  computed-call targets remain outside it.
- The PE contains six direct `D3DXCompileShader` callsites in five caller
  functions and one `Direct3DCreate9` callsite at `0x011f84be` in
  `FUN_011f84b0`. None of these callers is in any of the four direct-call
  closures above; this does not establish that the APIs are unreachable at
  runtime.
- The graphics dispatch chain is statically present: the pointer table at
  `0x0140dce8` has entries `0x0140dcf4 -> FUN_0075e830`,
  `0x0140dcfc -> FUN_0075f030`, and `0x0140dd00 -> FUN_0075e900`.
  `FUN_0075e830` directly calls `FUN_011f84b0`, which calls
  `Direct3DCreate9`; `FUN_0075f030` and `FUN_0075e900` directly call
  `FUN_011f8680` for device creation. The table entries are data references,
  not direct edges from the boot roots. The static dispatch chain is now
  connected through both stages:
  `FUN_00f47ed0` calls application slot `+0x14` (`FUN_007e67a0`), which
  obtains the Graphics manager through `FUN_007a67e0`, calls its slot `+0x08`
  (`FUN_007a4cb0`), constructs the `0x660`-byte Graphics object, and dispatches
  its slot `+0x0c` (`FUN_0075e830`) to initialize the D3D9 interface.
  `FUN_00f47ed0` then calls application slot `+0x1c` (`FUN_007e7380`).
  `FUN_007e7380` obtains the Graphics object from `FUN_0067dd50` and dispatches
  Graphics slot `+0x14` (`FUN_0075f030`), which reaches
  `FUN_011f8680` and `IDirect3D9::CreateDevice`; `FUN_007e7380` passes
  `640x480` arguments, but actual device parameters are assembled from
  graphics/configuration state inside `FUN_0075f030`. If that succeeds and
  the later component check passes,
  `FUN_007e7380` may dispatch slot `+0x18` (`FUN_0075e900`) using configured
  dimensions; that method also reaches `FUN_011f8680`. Device creation failure
  produces an error message, while a null Graphics singleton skips the first
  dispatch and follows a different branch. Therefore the static boot path
  contains conditional device-creation callsites before the main loop; it does
  not prove they execute or succeed at runtime. Whether any of the six
  shader-compilation callsites runs during startup remains unresolved. The
  first statically connected presentation dispatch on this startup path is
  `FUN_007e7380` -> `FUN_011f8120` -> device vtable slot `+0x44`
  (`IDirect3DDevice9::Present`) when the alternate presentation object is null.
  Otherwise the wrapper dispatches slot `+0x0c` on that object. This conditional
  call occurs before `FUN_00f47580`. The loop's slot `+0x84` resolves through
  the Canvas vtable to `FUN_00848210`, a Windows message pump; it does not
  itself call the presentation wrapper. A `WM_PAINT` dispatched by that pump
  reaches `FUN_00848340`, which routes event `0x1ee100a`; the registered
  listener handles it with `FUN_00f47930` (timing/subsystem updates) followed
  by an unresolved virtual slot `+0x80`. That slot is the next concrete
  rendering-path lead, but its target has not been identified as the presenter.
  Static callsites do not show whether any `Present` call executes successfully
  or produces a visible frame.

## Tracing the `cell_Eggkid` DBPF consumer

- For the PE currently analyzed in Ghidra (SHA-256
  `6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`),
  `FUN_00932e80` implements FNV-1 with optional lower/uppercase normalization.
  `FUN_00e50540` hashes the names `cell_EggkidSmall` and `cell_Eggkid` with
  lowercase normalization and compares each result to the value referenced by
  an object field at `+0x108`. Independently, lowercase FNV-1 of `cell_Eggkid`
  is `0x7ADE24E1`, matching the instance ID of the DBPF resource read on the
  Android device.
- This is a useful identity match, but not proof that `FUN_00e50540` looks up
  or consumes that DBPF entry. Its callers include `FUN_00e68470`, where the
  test participates in a conditional Cell-state/filtering path; the function
  compares an object's name hash, not a DBPF TGI or resource payload.
- A separate type-based path maps DBPF type `0xDFAD9F51` through
  `FUN_00432f10` to internal ID `0x1D2EC0A4`. `FUN_004e9ca0` and
  `FUN_004ea780` use a manager obtained from `FUN_0067de30` and call its
  virtual slot `+0x2C` with type/instance-like keys. `FUN_004ea780` has a
  special case involving type `0xDFAD9F51`, key `0x7A926123`, and another
  internal identifier; that key is not the tested `cell_Eggkid` instance
  `0x7ADE24E1`. The resolved call chain is
  `FUN_004eb980` -> `FUN_004ea920` -> `FUN_004ea190` ->
  `FUN_004e9ca0`; `FUN_004ea920` also calls `FUN_004ea780`, which has a
  recursive case-mapping path. The target and partial behavior of the virtual
  slot are resolved below, but this utility call chain has not been linked to
  the Cell boot path.
- A closer look at that path confirms a type-based resource-manager query, but
  not a payload read: `FUN_004e9ca0` maps `0xDFAD9F51` through
  `FUN_00432f10`, obtains the manager from `FUN_0067de30`, and calls its
  virtual slot `+0x2C` with the mapped type and `DAT_015daa00`. It then
  inspects fields of the returned object and enumerates associated records.
  `FUN_004ea780` uses the same manager slot for other type/key combinations.
  The only resolved caller of `FUN_004e9ca0` is a conditional branch in
  `FUN_004ea190`; its caller `FUN_004ea920` is reached by the initializer
  `FUN_004eb980`. A read-only inspection of the strict clean Ghidra project
  confirms `0x0058DA6D` is inside `FUN_0058D430` and directly calls
  `FUN_004EB980`; the call is conditionally reached based on
  `DAT_015DA6E4` versus `BL`. `FUN_0058D430` has no direct callers in the
  exported function inventory and is referenced by a table at `0x013F51B0`,
  which `FUN_0058E6D0` writes into an object at `0x0058E7D2`. This is evidence
  for a vtable-backed object path. The startup registration chain and remaining
  dispatch uncertainty are detailed below; actual execution of `FUN_0058D430`
  during startup or the Cell stage is still unproven. The manager
  implementation, exact resource identity returned, and whether this path
  reads the resource payload remain unknown.
- The virtual target is now resolved: the object factory `FUN_006ab650`
  constructs a `0x1EC`-byte object with vtable `0x014091E8`, whose slot
  `+0x2C` is `FUN_006a60b0`. That method searches a hash-bucket structure for
  a pair of 32-bit keys. On the cached path it returns a pointer stored in the
  matching record; on the other branch it forwards the request to an
  interface at object offset `+0x18`, slot `+0x0C`. The method does not itself
  show a DBPF read, file open, or `cell_Eggkid` TGI lookup. Its factory's
  result is stored in the engine object by `FUN_007e67a0` and published
  through `FUN_0067e040`; this establishes static initialization and
  registration, not that the initializer executes at game startup. The
  forwarded interface implementation and the code that populates that
  interface remain the concrete next gap.
- The strict clean project now narrows the upstream dispatch path. On the
  successful `FUN_00F47ED0` initialization path, `FUN_00F47550` calls
  `FUN_0057F3E0`. That routine allocates a `0x600`-byte object, calls
  `FUN_0057CE80`, then invokes the service returned by `FUN_0067DD10` through
  virtual slot `+0x20`, passing the object, `0x00DBDBA1`, and
  `0x013F58B8` (the string `"Editors"`). The constructor installs vtable
  `0x013F57F8`; its slot `+0x18` contains `FUN_0058E6D0`. That method installs
  vtable `0x013F51B0` on a child object, and the table's first slot points to
  `FUN_0058D430`, which contains the conditional call at `0x0058DA6D` to
  `FUN_004EB980`.
- The service path is now resolved conditionally from its global. The getter
  `FUN_0067DD10` reads `DAT_015FD8B0`; its setter has two observed callers:
  `FUN_007E6470` clears the global, while `FUN_007E8BA0` publishes the object
  at its `+0xC8` field. That method calls `FUN_007D8DC0`, which allocates a
  `0x34`-byte object and installs vtable `0x01412598`. The table's slot `+0x20`
  is `FUN_007D9260`, matching the three stack arguments at the
  `FUN_0057F3E0` callsite (`FUN_007D9260` returns with `RET 0xC`).
- `FUN_007D9260` takes the allocated object plus the two supplied keys,
  builds a record, and passes it to `FUN_007D90A0` for insertion into the
  service's collection at `+0x14`; the helper advances the collection by
  `0x18` bytes per record. If the getter returns the factory-created service,
  this call registers the `FUN_0057CE80` object under the supplied key/name.
  This does not prove that the global has that value at runtime, that the
  object is later dispatched through slot `+0x18`, or that the conditional
  `FUN_0058D430` path runs.
- The earlier candidate vtable at `0x01413AD0` is not the singleton service's
  table: the factory used for `DAT_015FD8B0` installs `0x01412598`. The
  remaining dispatch that invokes the registered object's slot `+0x18`, and
  the runtime conditions that reach `FUN_0058D430`, remain unresolved.
  `FUN_004EB980`'s 27 type/key queries still do not identify a
  `cell_Eggkid` payload read. Do not connect this path to the Android DBPF
  reader until those gaps are closed.
- The service's separate slot `+0x54` path does not close that dispatch gap.
  `FUN_007D8060` populates service offset `+0x2C` from `FUN_007C7700`, then
  calls that object's slot `+0x10` with `"camera"`. `FUN_007C7700` allocates a
  `0xB4`-byte object and calls `FUN_007C75E0`, whose constructor installs
  vtable pointers `0x014106A8` and `0x014106A4` at object offsets `0` and
  `+4`. This is a separate object from the `0x600`-byte `"Editors"` object
  registered by `FUN_0057F3E0` with vtable `0x013F57F8`; therefore,
  `FUN_007D8450` dispatching through the service's `+0x2C` pointer is not
  evidence that the registered object's slot `+0x18` is called. The observed
  collection iterators dispatch the registered objects through slots `+0x0C`,
  `+0x10`, and `+0x1C`; a call to its `+0x18` slot remains unresolved.
- The registered object's `+0x10` method is `FUN_00584300`. It creates
  several 0x14-byte helper objects whose `+0x10` field points back to the
  editor object, then calls the object returned by `FUN_0067DE20` through
  slot `+0x18` with editor-related keys. `FUN_0067DE20` returns
  `DAT_015FD8A4`, which startup populates with the `App/CheatManager` object
  built by `FUN_0067FB50`/`FUN_0067FAB0`. That manager's slot `+0x18` is
  `FUN_0067F470`; its body performs a string-key lookup and returns a stored
  value. These calls do not establish that the helpers are registered or
  dispatched, or that the editor object's `FUN_0058E6D0` slot is invoked.
  The helper lifecycle and any route from it to `FUN_0058D430` remain open.
- At the time of this static trace, no original-game call chain joined the exact
  TGI `0xDFAD9F51:0x00000000:0x7ADE24E1` to its payload and then to
  `FUN_00e819b0` or another proven boot-time consumer. The Android test below
  adds an explicit application-level hash-to-DBPF path; it does not establish
  that the original Cell/DDF startup path uses that path.

## Joining a Spore name hash to an original DBPF entry

- The saved Ghidra project identifies `FUN_00932e80` at `0x00932e80` as a
  174-byte x86 routine. Its mode-1 path calls the lowercase mapper through the
  global at `0x013cc2ec`, then updates the hash as
  `hash = hash * 0x01000193 ^ mapped_byte`, starting from the caller-provided
  seed. The whole-body disassembly was read from the exact reference PE; the
  installed Ghidra lacks `decompile.exe`, so this validation uses assembly
  evidence rather than pseudocode.
- `tools/run_x86_name_hash_differential.ps1` verifies the reference PE SHA-256
  and executes the original x86 body against `spore::fnv1_ascii_lower` in
  `dbpf_reader.cpp`. The harness rebinds the mode-1 mapper load to a simple
  ASCII lowercase shim and compares 2,057 ASCII cases, including empty input,
  mixed-case `cell_Eggkid`, and deterministic randomized strings. All passed;
  this does not establish non-ASCII/locale behavior or the game's runtime
  mapper initialization.
- The Android `cell_Eggkid` action now computes the instance ID natively from
  the name using that FNV-1 lowercase implementation, then uses the computed
  value in the DBPF TGI lookup. On the connected `arm64-v8a` Xiaomi, the
  result was `cell_Eggkid -> 0x7ADE24E1`, followed by a successful read of
  796 decompressed bytes from the imported original `Spore_Game.package`.
  The payload SHA-256 is
  `ac291c1cd5cb91d78fbe8e4420a40e8c2aaaa1632d4c6b2d2edeb822174a2ec8`,
  matching the independently verified PC result. The app remained alive and
  its recent PID-filtered log had no fatal exception or native signal.
- The Android path uses the tested C++ semantic implementation; it does not
  execute the original x86 instructions or a generated Spore lift on ARM64.
  The lookup is still explicitly initiated by the app button. Static evidence
  does not connect it to `FUN_00e50540`, the Cell/DDF setup path, startup, or
  gameplay, and no game boot is demonstrated.
- `:app:assembleDebug :app:lintDebug` succeeded. The APK SHA-256 is
  `175757260a43130368954479569339729be92e0fb9cdfebbbf61c44be59beed0`.
  The on-device capture is `files/marco2-fnv-dbpf-pass.png`.

## Recovered batch lifter: direct CALL/RET

The recovered historical backend is preserved under
[`tools/batch_static_lift/`](./tools/batch_static_lift/): the original
`BatchStaticLift.py`, its `BatchStaticLiftRuntime.hpp`, and its unit tests were
copied before modification. Direct near `CALL` now requires one immediate
operand, one matching call reference, and an exact target function in the
supplied export. Generated code pushes the real guest return address, calls
the translated target with the same memory/register/flags state, and verifies
that `RET` returned to that address. `RET` and `RET imm16` update guest ESP and
EIP through the historical runtime. Indirect/far calls, targets absent from the
export, rejected callees, and tail-call `JMP` transfers remain explicit
rejections. An indirect `CALL` is accepted only when its absolute operand is a
slot identified by the PE import table; the runtime dispatches that import by
its resolved symbol. Other indirect calls remain rejected, and no result is
substituted for a call.

The historical and recursive-pilot runtimes remain separate:

| Contract | Historical batch runtime | Existing recursive pilot runtime |
|---|---|---|
| State | `regs[8]`, `eflags`, `eip`; same three statuses | Same fields and statuses |
| Guest memory | Up to 8 mapped regions; 8/16/32-bit loads/stores | Fixed 64 KiB region at `0x1000`; 32-bit loads/stores |
| Stack | Dedicated guest stack at `0x70000000`, initialized with a return sentinel | Stack is explicitly laid out in the fixed memory array |
| Flags | Shared arithmetic/logical helpers for 8/16/32-bit operations | Smaller helper set used by the recursive pilot |
| CALL/RET | Added stack-based `batch_guest_call32` / `batch_guest_return32` | Existing push/pop/CALL/RET helpers unchanged |

`generate_call_closure.py` verifies each instruction's bytes against the
reference PE and generates the selected root plus its direct-call closure.
The first generated regression is `FUN_006237a0`, including its recursive
`CALL` at `0x006237aa`. The distinct-function regression is
`FUN_00bb9b70` at `0x00bb9b70`, which calls `FUN_00b8dab0` at `0x00b8dab0`;
the guest return address is `0x00bb9b75`. The callee reads the fixture field
`[ECX+0x194]`; values 4, 5, 6, and `0xffffffff` exercise both outcomes of the
caller's comparison and `SETZ`.

The generated-backend harness compares the reference x86 bytes with the
generated functions on Windows x86, including return values, relevant flags,
stack balance, and guest return addresses. It also compiles the same generated
functions for ARM64. An earlier `-BuildOnly` run on 2026-11-07 passed the
recursive and distinct-function cases; no authorized Android device was
connected during that run. Logs:

- [batch-static-lift-calls-final-2026-11-07.log](./test-logs/batch-static-lift-calls-final-2026-11-07.log)
- [batch-static-lift-unit-import-boundary-2026-11-07.log](./test-logs/batch-static-lift-unit-import-boundary-2026-11-07.log)
- [recursive-pilot-build-regression-2026-11-07.log](./test-logs/recursive-pilot-build-regression-2026-11-07.log)

In the subsequent device run, the same harness passed on the connected
`arm64-v8a` phone (ADB serial `PJMZAEJRX4YLFIDI`). The device reproduced all
four recursive cases and all four distinct-function call cases, including
return values, flags, balanced guest stack, and the callee/return address.
The run also repeated and passed the x86 differential checks and ARM64 compile.
Full output:
[batch-static-lift-device-2026-11-06.log](./test-logs/batch-static-lift-device-2026-11-06.log).

Reproduce byte verification, generation, x86 differential tests, and ARM64
compilation from PowerShell:

```powershell
.\tools\run_batch_static_lift_calls.ps1 -BuildOnly
```

With one authorized ARM64 device connected, run the same harness on-device:

```powershell
.\tools\run_batch_static_lift_calls.ps1 -DeviceSerial <serial>
```

This proves reusable direct-call execution for a recursive function and a
two-function chain; the additional startup-linked slice is documented below.

`FUN_00f47ed0` remains too broad to translate as a whole. Its first call,
`0x00f47ed9: CALL 0x006b4f20`, is now classified from the PE import table as
the `steam_api.dll!SteamAPI_Init` import thunk, rather than a missing internal
function. The thunk bytes `ff 25 04 c8 3c 01 cc cc` jump indirectly through IAT
slot `0x013cc804`. This diagnosis does not define an Android substitute or
claim that a success return reproduces Steam initialization.

## Initialization closure diagnosis and first translated slice — 2026-11-06

`diagnose_call_closure.py` walks the direct-call closure of
`FUN_00f47ed0` over all 116 available batch exports and writes a report only;
it never invokes code generation. It verified and examined 570 exported
functions. The report distinguishes exported bodies, PE import thunks, missing
functions in `.text`, and addresses outside known code/imports. The observed
totals are 118 import-thunk stubs in the PE, 72 direct calls to those stubs,
470 indirect calls (444 without even a static reference candidate), two
missing internal function bodies, 2,250 unsupported instruction records, and
two functions whose exported body byte counts do not match their decoded
instructions.

The two missing internal entries are `0x0081d470`, called by the initializer
at `0x00f47ef9`, and `0x011e073e`, referenced from 25 reachable callsites.
Indirect-call references are retained only as candidates, not treated as
resolved runtime targets. This is a direct-call closure, so it does not claim
to cover functions reachable only through those indirect calls. The complete
diagnostic, including callsites and instruction-level reasons, is
[startup-call-diagnostic-2026-11-06.json](./test-logs/startup-call-diagnostic-2026-11-06.json);
the concise interpretation is
[startup-call-diagnostic-2026-11-06.log](./test-logs/startup-call-diagnostic-2026-11-06.log).

The selected slice is
`FUN_011e5d80` → `FUN_011e8b20`. Its static direct-call path from the startup
initializer is `FUN_00f47ed0` → `FUN_00a45f30` → `FUN_00a459d0` →
`FUN_00a33600` → `FUN_00a247f0` → `FUN_011e5d80` → `FUN_011e8b20`;
the corresponding callsites are in the diagnostic JSON. In particular,
`FUN_00a247f0` calls the selected constructor at `0x00a24812`, and that
constructor calls the string-copy routine at `0x011e5d92`. This is static
linkage evidence, not proof those calls executed in a game session.

The two selected bodies total 28 instructions and 65 PE-verified bytes.
`FUN_011e5d80` sets the object vtable to `0x01452998`, passes the object's
inline string buffer and its source to `FUN_011e8b20`, and returns with
`RET 4`. The callee copies bytes through the NUL terminator. The backend
generated both functions with a real shared-state guest `CALL` and preserved
the callee's return address.

The harness deliberately starts at the internal constructor, not the game or
initializer entry. It supplies a zeroed object at guest `0x5000`, a
read-only source buffer at `0x6000`, the source pointer at `[ESP+4]`, a return
sentinel, and initialized guest registers/flags. Empty, one-byte, and
17-byte source fixtures exercised both loop outcomes. Windows x86 execution of
the byte-verified PE bodies matched the translated result, object contents,
flags, nested return address, and stack cleanup. The same source compiled for
ARM64 and ran on the reconnected `2303ERA42L` phone. All three string fixtures
passed on ARM64, along with the recursive and distinct-function regressions.
The successful run is
[startup-chain-device-2026-11-06.log](./test-logs/startup-chain-device-2026-11-06.log);
the earlier disconnected attempt is retained at
[startup-chain-device-disconnected-2026-11-06.log](./test-logs/startup-chain-device-disconnected-2026-11-06.log).
The standalone x86/build-only record is
[startup-chain-x86-arm64-build-2026-11-06.log](./test-logs/startup-chain-x86-arm64-build-2026-11-06.log).

The persistent generated sources and their byte-verification report are in
[`tools/batch_static_lift/generated/startup_init_string_copy/`](./tools/batch_static_lift/generated/startup_init_string_copy/).
Reproduce the full diagnostic with:

```powershell
python .\tools\batch_static_lift\diagnose_call_closure.py `
  --exe C:\SporeAnalysis\SporeApp.exe `
  --batch-dir C:\SporeAnalysis\spore_batch_all_parts `
  --root 0x00f47ed0 `
  --report .\test-logs\startup-call-diagnostic-2026-11-06.json
```

Reproduce generation, x86 differential checks, and ARM64 compilation with
`.\tools\run_batch_static_lift_calls.ps1 -BuildOnly`; add
`-DeviceSerial <serial>` to run the harness when an authorized device is
connected. These remain isolated compatibility tests, not game startup.

## Constructor closure and x86 SEH boundary — 2026-11-07

The bounded diagnosis of `FUN_00a247f0` and its direct-call descendants reaches
five exported functions, including `FUN_009222a0` and `FUN_00922150`. The
updated report is
[constructor-call-diagnostic-2026-11-07.json](./test-logs/constructor-call-diagnostic-2026-11-07.json).
It finds no missing direct-call bodies and no remaining unsupported
instructions after adding limited guest `FS:[disp]` memory access and `SBB`
lowering. These changes do not implement x86 exception dispatch: `FS:[0]` is
read and written through an explicit `BatchLiftState::fs_base` guest address,
which the harness must map in `BatchLiftMemory`; no host thread state is used.

The two indirect calls in `FUN_00922150` are resolved as PE IAT slots, not as
direct calls:

| Site | IAT slot | Resolved import | Local call contract |
|---|---:|---|---|
| `0x0092216c` | `0x013cc2d0` | `KERNEL32.dll!InitializeCriticalSection` | Receives `ESI` (`this`) and initializes the object's inline critical-section state. |
| `0x00922189` | `0x013cc180` | `KERNEL32.dll!CreateMutexA` | Receives `(NULL, FALSE, name-or-NULL)`; its handle is tested and stored at `[ESI]`. |

The import names and slots come from the PE import table. At the second call,
the guest code derives the optional mutex name from the supplied string and
returns success only if `CreateMutexA` returns a non-null handle. The first
call initializes synchronization state. The runtime now routes imports through
a common guest dispatcher. `InitializeCriticalSection` validates the guest
address, preserves the x86 24-byte structure layout, and associates that
address with a separate native recursive mutex; no host mutex is embedded in
guest memory. The guest lifecycle test initializes, enters twice, leaves twice,
and deletes the section. The Windows x86 comparison also executes the original
PE bytes and checks the constructor's object, stack return sites, stack balance,
and restored `FS:[0]`. It normalizes the Win32 debug pointer and separately
reports the host's opaque `SpinCount` (`0x020007d0` on this run versus zero in
the guest mirror); the remaining object bytes are compared.

The selected arguments `(0, 1)` exercise the `InitializeCriticalSection`
branch. `CreateMutexA` is still an explicit unsupported import: its separate
branch stops with a diagnostic if called, rather than returning a fabricated
handle. This rejection is tested on both x86 and ARM64. The original PE string
`"resman:"` at `0x01449334` is extracted by the generator and supplies the
constructor input; the native x86 harness maps the IAT and string at available
addresses and relocates only their pointer operands to avoid process address
collisions.

The five-function closure is generated and byte-verified, and runs on Windows
x86 and the connected ARM64 phone. On-device it passed the startup constructor,
the existing recursive and distinct-function call regressions, recursive
critical-section lifecycle, and explicit `CreateMutexA` rejection. This still
starts directly at internal `FUN_00a247f0`, not from the game entry point.
Exception handling is limited to installing and restoring the guest `FS:[0]`
chain on the ordinary return path; exception dispatch and unwinding remain
unsupported.

Persistent generated sources and the PE byte report are in
[`tools/batch_static_lift/generated/startup_resman/`](./tools/batch_static_lift/generated/startup_resman/).
The command `.\tools\run_batch_static_lift_calls.ps1` regenerates temporary
closures, runs the Windows x86 differential and ARM64 build, and executes the
ARM64 harness over ADB when one authorized device is connected. The complete
device run is
[batch-static-lift-import-boundary-2026-11-07.log](./test-logs/batch-static-lift-import-boundary-2026-11-07.log);
the 32 Python backend regressions pass with
`python -m unittest -v test_static_batch_lift`.

## Expanding the startup closure through `FUN_00a33600` — 2026-11-06 (historical snapshot)

> This section records the state after `MOVSS` support but before the
> `XORPS`/x87 work in commit `53db419`. The current root diagnosis and partial
> execution results are documented in the next section.

The diagnostic report for `FUN_00a33600` and its direct-call closure is
[call-closure-00a33600-after-sse-move-2026-11-06.json](./test-logs/call-closure-00a33600-after-sse-move-2026-11-06.json).
It reaches 86 exported functions; 46 still have translation blockers, with
224 unsupported instruction sites, one missing internal body (`0x011e073e`,
referenced at six callsites), and two indirect calls with no identified target.
The report separately recognizes 33 IAT callsites by PE import name and five
direct calls to import thunks. Recognizing an import does not mean its runtime
handler is implemented: the batch runtime currently handles critical-section
operations, explicitly rejects `CreateMutexA`, and reports other imports as
unsupported.

The root body itself has only four remaining unsupported instructions:
`XORPS XMM0,XMM0` at `0x00a33741` and `0x00a33c51`, plus x87
`FLD double ptr [0x01452f38]` and `FSTP double ptr [ESI+0x15b768]`.
These are SSE logical and x87 operations, not SSE arithmetic. The previous
51 root-body rejections and 376 closure-wide rejections fell to four and 224,
respectively, after adding scalar `MOVSS` transfers and absolute memory
operands. The lowering covers memory-to-XMM, XMM-to-XMM, and XMM-to-memory;
it preserves the appropriate upper lanes and leaves flags unchanged. It does
not implement `XORPS` or x87.

Other concrete blockers on the closure include the `XCHG` form in
`FUN_00921f00`, indexed memory access and an IAT `strncpy` call in
`FUN_011e64f0`, and unresolved `CALL EDX` / `CALL ECX` sites at
`0x0092805c` and `0x009276ab`. These are distinct from the calls whose IAT
slots are known. The diagnostic is not an executable closure: no generated
`FUN_00a33600` is claimed complete or run.

The static object route provides a bounded next-step target:

- `FUN_00a45f30` requests `0x15bf58` bytes and passes `0x0140a5a0` to
  `FUN_00f473a0`. The requested extent is `0x15bf58`; this is not yet a
  recovered C++ type size or layout.
- `FUN_00f473a0` reads the allocator singleton at `0x016c8b44` and reaches
  `FUN_009289f0` and the allocator's descendants. The pointer and allocation
  result have not been executed through this path.
- `FUN_00a459d0` passes the resulting object to `FUN_00a33600`. Before it
  reaches the already validated `FUN_00a247f0` at object offset `+0x198`,
  `FUN_00a33600` calls `FUN_00743b50` for `+0x20`, `FUN_00921f00` for
  `+0x28`, `FUN_009222a0` for `+0xb8`, and `FUN_011e64f0` for `+0xf8`.
  These real calls must run; their results are not replaced with fixtures.
- The largest root-body access observed is the eight-byte store at
  `+0x15b768` (ending at `+0x15b770`), within the caller's requested extent.
  This bounds that access but does not establish the complete object layout.
- Read-only constants used by the root reside in PE-backed `.rdata` at
  `0x01485718`, `0x01452f50`, `0x01470f14`, `0x01486108`, and `0x01452f38`.
  Mutable globals at `0x0166da00`, `0x0166da04`, `0x0166da08`, and the
  allocator singleton at `0x016c8b44` fall in the `.data` virtual range
  without corresponding raw file bytes. Their runtime values and initialization
  producers remain unestablished; they must not be guessed as harness state.

The two unclassified calls block allocator-path execution. In addition, the
closure contains imports that are named but lack handlers, including
`VirtualAlloc` (five callsites), `VirtualFree` (two), `VirtualQuery`,
`GetSystemInfo`, `InitializeCriticalSectionAndSpinCount`, `CreateSemaphoreA`,
`memmove`, and `strncpy` (three). Five direct `memcpy` import-thunk calls also
remain part of the closure. The existing five-function constructor run remains
the device regression; it does not validate this broader object path.

The backend's x86 scalar-transfer differential, ARM64 build, and the preserved
five-function phone regression passed. The Python backend suite now has 32
passing tests. The saved device log is
[batch-static-lift-movss-regression-2026-11-06.log](./test-logs/batch-static-lift-movss-regression-2026-11-06.log);
the Python test log is
[batch-static-lift-movss-unit-2026-11-06.log](./test-logs/batch-static-lift-movss-unit-2026-11-06.log).
Reproduce the closure diagnosis with:

```powershell
python .\tools\batch_static_lift\diagnose_call_closure.py `
  --exe C:\SporeAnalysis\SporeApp.exe `
  --batch-dir C:\SporeAnalysis\spore_batch_all_parts `
  --root 0x00a33600 `
  --report .\test-logs\call-closure-00a33600-after-sse-move-2026-11-06.json
```

Run the retained x86/build/device regressions with
`.\tools\run_batch_static_lift_calls.ps1 -DeviceSerial <serial>`. This does not
generate or execute the still-blocked `FUN_00a33600` closure.

## Verified partial execution of `FUN_00a33600` — 2026-11-06 (Marco 3 baseline)

The backend now has a reusable prefix mode: it translates only contiguous
fall-through instructions up to a selected direct-call boundary, and permits
ordinary guest `CALL`/`RET` only for explicitly included, byte-verified
dependencies. The generated report distinguishes this deliberately incomplete
prefix from a complete function. A boundary reached at runtime returns
`unsupported_dependency`; it cannot be reported as a successful full-function
execution.

The latest closure report,
[call-closure-00a33600-after-xorps-x87-2026-11-06.json](./test-logs/call-closure-00a33600-after-xorps-x87-2026-11-06.json),
shows that all 380 root instructions now translate: 41 `MOVSS`, two `XORPS`,
`FLD`, `FSTP`, and 34 direct `CALL`s are covered. The 34 calls have 21 distinct
targets, each present in the exports. The full 86-function closure remains
incomplete: 220 unsupported sites, one missing internal body (`0x011e073e`),
and two unresolved indirect-call candidates remain. It also contains 33
identified IAT callsites and five direct calls to import thunks. The earlier
report's 78 root rejections and the recovered Steam-folder pilot's three-function
list were stale-copy differences: Git history places `MOVSS` in `452a613` and
`XORPS`/x87 support in `53db419`; this repository retains its five-function
regression. The historical Steam-folder copy has no matching Git history to
establish why its runner list was shortened.

The focused test executes a 31-instruction prefix from an internal entry in
`FUN_00a33600`, including its real direct call to `FUN_00743b50`. It compares
the original x86 bytes against the generated lift on Windows x86, then compares
that lift with the same generated code on Android ARM64. The x86 harness
relocates only the included `CALL rel32` at `0x00a33656` to the mapped child
body; the target and call/return semantics are retained and the relocation is
recorded in the generated report. The output snapshots match exactly:
`EAX=0x20000020`, `ESP delta=-80`, `EFLAGS=0x44`, the tested object fields,
and the guest SEH-chain words. Guest `FS:[0]` lives in guest memory with the
documented sentinel; the native harness restores the host FS chain after
capturing the comparison state.

The object memory is a harness-provided mapping, not a game allocation. Its
`+0x20` field starts with a sentinel and is cleared by the executed
`FUN_00743b50`; no child result is substituted. This baseline execution stops
before the next call, at `0x00a3366a` to `FUN_00921f00`. At that time the
three direct callees were absent from the prefix runner's selected exports.
Marco 4 below records their recovery and the remaining runtime blockers. This
baseline is not a complete constructor, a game-startup run, or a full
`FUN_00a33600` execution.

## Marco 4 — `FUN_00921f00`, `XCHG`, and the remaining import boundary — 2026-11-06

The original PE and Ghidra batch export `spore_batch_all_0034.json` were used
to recover the requested direct callees. Their original instruction bytes
match the PE SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
Ghidra reports complete contiguous function bodies; the lifter's byte
validator accepted every exported instruction:

| Function | Body bytes | SHA-256 of concatenated verified instruction bytes |
|---|---:|---|
| `FUN_00922820` | 85 | `1b6507130ed2ffede3efd17754428ef20556667c283900c1c8a9e92d0b8c991e` |
| `FUN_009222a0` | 102 | `bc6d97dd20220daf2f881c32074bbd573d589bbeb301ed399fcdb5f90e7433e3` |
| `FUN_00921e60` | 147 | `873f85aba614f87c0bd9bf546118f3de14d4a4ecb3153c5b04153d5fc2df072d` |

`FUN_00921f00` itself is 121 verified bytes. Its complete direct-call closure
is eight functions, including `FUN_00922620`, `FUN_00922150`, `FUN_009225d0`,
and `FUN_00921e00`; no direct target is missing from this export set. The
closure report is
[call-closure-00921f00-after-xchg-2026-11-06.json](./test-logs/call-closure-00921f00-after-xchg-2026-11-06.json).
The byte-verified generated sources, reference-byte header, and call/import
manifest are in
[generated-00921f00-closure-20261106-121229438](./test-logs/generated-00921f00-closure-20261106-121229438/).

The backend now lowers the observed `87 01` at `0x00921f08`,
`XCHG dword ptr [ECX],EAX`. The guest memory abstraction serializes all reads,
writes, and 32-bit exchanges through a per-memory mutex; the exchange returns
the previous memory value into EAX and preserves EFLAGS. The supported form is
limited to one 32-bit memory operand and one 32-bit general-purpose register.
It rejects other widths and two-memory forms.

Differential tests compared the helper with native x86 locked `XCHG` for five
value pairs, including unaligned memory, and checked memory/register results,
unchanged flags, invalid and read-only memory rejection, and concurrent
exchanges. The 43 Python backend tests passed. The retained five-function
regression passed on x86 and the Android ARM64 target compiled successfully;
the generated eight-function closure also passed Android ARM64 syntax
compilation. The phone was not connected at this run (`adb devices -l` returned
no devices), so **no Marco 4 code was executed on the phone**. The requested
device run failed with `device 'PJMZAEJRX4YLFIDI' not found`; the successful
build-only log is
[five-function-buildonly-after-xchg-20261106-121250484.log](./test-logs/five-function-buildonly-after-xchg-20261106-121250484.log).

The closure's five IAT calls are identified:

| Call site | Import | Current runtime status |
|---|---|---|
| `0x00921e18`, `0x009225ef` | `MSVCR90.dll!strncpy` | No handler |
| `0x0092216c` | `KERNEL32.dll!InitializeCriticalSection` | Implemented |
| `0x00922189` | `KERNEL32.dll!CreateMutexA` | Explicitly rejected |
| `0x0092266d` | `KERNEL32.dll!CreateSemaphoreA` | No handler |

These are real import boundaries, not missing code bodies. The generated
closure compiles, but its runtime cannot faithfully continue through every
branch until the unsupported imports have real handlers. No import was
replaced with a prepared result. Because the phone was unavailable, the first
import actually reached by the original caller state was not observed. Thus
the `FUN_00a33600` prefix remains stopped before `0x00a3366a`; it has **not**
been widened or represented as a complete constructor.

Reproduce the focused closure diagnosis with:

```powershell
python .\tools\batch_static_lift\diagnose_call_closure.py `
  --exe C:\SporeAnalysis\SporeApp.exe `
  --batch-dir C:\SporeAnalysis\spore_batch_all_parts `
  --root 0x00921f00 `
  --report .\test-logs\call-closure-00921f00-after-xchg-2026-11-06.json
```

With the device connected, rerun the preserved regressions using
`.\tools\run_batch_static_lift_calls.ps1 -DeviceSerial <serial>`. This reruns
the five-function suite and the XCHG differential; it does not execute
`FUN_00921f00` until the import boundary and the original caller-state
comparison harness are addressed.

### Allocator singleton and initializer evidence

Static inspection of the supplied PE (SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`) supports
an initializer relationship, but does not prove that the game executed it:

- The `.rdata` entry at `0x013cc828` contains the code pointer
  `0x0138e640`; neighboring entries are also code pointers. The consumer and
  runtime invocation of this table have not been established.
- Code at `0x0138e640` checks `0x016c8b40` and calls `FUN_00f474d0` at
  `0x0138e649` when the global is null. It sets `0x016c8b48` based on that
  routine's boolean result, then pushes `0x013c9950` and calls `0x011e07ef`.
  The role of the final call is not fully established.
- `FUN_00f474d0` calls `FUN_00935c80` with hash `0xee9b7413` and callback
  address `0x00f47480` when `0x016c8b40` is null. It validates the returned
  record's `+0x10` value (`0x2b5c`) and `+0x14` byte, then stores its `+0x18`
  pointer in `0x016c8b44`; the failure branch calls `FUN_00f47430`.
  `FUN_00935c80` initializes/searches a registry and invokes the supplied
  callback on a miss while using the critical section at `0x013cc2d8`.
- Code at `0x00f47480` begins by obtaining `GetProcessHeap` and calling
  `HeapAlloc` for `0x530` bytes. Its complete function boundary and allocated
  object's type are not established.
- `0x016c8b40` and the adjacent globals are in the `.data` virtual range beyond
  its raw file-backed bytes. Their runtime values, callback execution, and
  normal-startup initialization remain unknown; no values were invented for
  the prefix test.

The successful focused run, generated source, byte header, and report are kept
in
[constructor-prefix-00a33600-20261106-111528511](./test-logs/constructor-prefix-00a33600-20261106-111528511/).
The reproducible command is
`.\tools\run_constructor_prefix_tests.ps1 -DeviceSerial <serial>`; it preserves
prior runs by creating a new timestamped directory. The five-function
x86/ARM64/device regression also passed on `PJMZAEJRX4YLFIDI`; its fresh log is
[five-function-regression-20261106-113845944.log](./test-logs/five-function-regression-20261106-113845944.log).
That earlier run had 41 Python tests. These results validate the implemented
prefix and preserve earlier behavior; they do not complete the allocator path
or initialize the game.

## Marco 5 — extended `FUN_00a33600` prefix (2026-11-06)

The verified prefix now reaches the call boundary at `0x00a33726` and stops
before calling `FUN_011e64f0` (`0x011e64f0`). This is a partial execution, not
completion of `FUN_00a33600`, game initialization, or gameplay.

The x86-to-ARM64 backend's `MOVSS` memory-store lowering was corrected to read
the XMM source operand rather than the memory base-register index. The added
regression covers this source selection. The prefix generator also accepts
explicit PE-backed data ranges and records their file offsets and SHA-256
hashes. The harness maps the verified `.rdata` bytes read-only at guest
addresses; for the Windows x86 reference, it maps host aliases and relocates
only the two validated absolute references at `0x00a336be` and `0x00a336cf`.
The guest address space retains the original PE virtual addresses.

The source PE SHA-256 is
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`. The two
file-backed data pages supplied to the run were:

- `0x01452000`, 4096 bytes, PE file offset `17110016`, SHA-256
  `31254c71d707cb3b42f92f1eefa554868f027cacaeef970f4c702e1442d3f567`.
- `0x01485000`, 4096 bytes, PE file offset `17318912`, SHA-256
  `bbbdc92c27935fd49f04ca0e427e25e64096845e3c733f673187388efa89984f`.

The x86 reference and generated x86 snapshots match, as do the generated x86
and ARM64 snapshots. The harness canonicalizes process-specific handle values
by import-creation order; it also aligns the reference stack's low byte and
captures stack fields relative to entry ESP so flags and stack snapshots
compare the same guest state. On device `PJMZAEJRX4YLFIDI`, the prefix ran on
ARM64 and recorded two `CreateSemaphoreA` calls and two
`InitializeCriticalSection` calls, each with `GetLastError() == 0`. The
`CreateMutexA` path was not reached by this prefix.

Validation:

- 46 Python backend tests passed:
  [batch-static-lift-unit-m5-20261106-135448303.log](./test-logs/batch-static-lift-unit-m5-20261106-135448303.log).
- Windows x86 original-versus-lift and x86-versus-ARM64 comparisons passed;
  the ARM64 device run passed and stopped at the declared boundary:
  [constructor-prefix-00a33600-20261106-134917041](./test-logs/constructor-prefix-00a33600-20261106-134917041/).
- The recursive, cross-function, five-function startup-import, XCHG, SSE,
  x87, and Android-device regressions passed again:
  [five-function-regression-m5-20261106-135149246.log](./test-logs/five-function-regression-m5-20261106-135149246.log).

At the Marco 5 checkpoint, `FUN_011e64f0` remained untranslated. Its
diagnostics included an unresolved indirect call at `0x011e653f`, unavailable
bodies at `0x011ecd90`, `0x011ecdd0`, and `0x011ecde0`, and an unsupported
indexed memory operand at `0x011e65c1`. Marco 6 resolves those specific
blockers; the following section records the verified result.

## Marco 6 — extended verified prefix (2026-11-06)

The original x86 prefix and its generated lift now execute through
`0x00a33816`, then stop before the direct call at `0x00a33817` to
`FUN_00a2a210`. The prefix contains 106 translated root instructions and
executes `FUN_00743b50`, `FUN_00921f00`, `FUN_009222a0`, `FUN_011e64f0`,
`FUN_00a247f0`, and six calls to `FUN_00a0fdf0`. This is still a bounded
partial prefix: `FUN_00a2a210` and the rest of `FUN_00a33600` were not run.

`FUN_011e64f0` and its verified dependencies are now part of the 16-function
generated closure. The indirect call at `0x011e653f` resolves to the PE IAT
entry for `MSVCR90.dll!strncpy`; the recovered helper bodies at `0x011ecd90`,
`0x011ecdd0`, and `0x011ecde0` are byte-verified against the selected PE.
`MOV dword ptr [ESI + EAX*4 + 0x2c], ECX` at `0x011e65c1` is implemented and
differentially tested, including 32-bit address wrap and an invalid index.

The prefix run uses the PE with SHA-256
`6aec99cb2dc7fd08851a1718e92a60f359fb3fccca3b244a890ae07e93cbe59b`.
It maps the verified `.rdata` page at `0x01486000` for the newly reached
`MOVSS` load at `0x00a337d3` (file offset `17323008`, SHA-256
`0cecfc05c963aab62a12978059a04ceb0db7bf4216062f03ef0f9e2ca2454fd3`).
The isolated comparison state is harness-provided: a zeroed 0x404-byte guest
object with the documented sentinel at `+0x20`, a guard word after the tracked
object, and PE-backed read-only data. It is not the game's allocator output or
normal startup state. The object extent was extended to include the verified
store at `+0x400`; the guard remains outside the compared object.

Windows x86 original-versus-lift snapshots match, and the lifted x86 snapshot
matches the run on Android ARM64 device `PJMZAEJRX4YLFIDI`. Stack-valued
registers are normalized relative to entry ESP; ECX and EDX are treated as
caller-saved for the cross-target comparison. The constructor is not complete;
this result does not establish game boot, rendering, or gameplay.

The first unresolved boundary is a dependency closure, not an unsupported
instruction in the root prefix. A targeted closure diagnostic for
`FUN_00a2a210` reaches 10 exported functions and reports 36 unsupported
instructions plus three target addresses absent from the selected exports; it
found no indirect calls.
The first direct call in that function is at `0x00a2a24e` to
`FUN_00921260`. That function contains unsupported `NOT`, `DIV`, and `IMUL`
operations and indexed `LEA` forms, including
`[EBX + EAX*0x1 + -0x1]` at `0x00921288`. Other closure blockers include x87
and conversion instructions in `FUN_009213c0`, `DIV` in `FUN_00a22220`, and
targets absent from the selected exports at `0x00f47380`, `0x00f473a0`, and
`0x011e073e`. See the saved
closure report for addresses and the complete classifications.

Validation and reproducible evidence:

- 48 Python backend tests passed:
  [batch-static-lift-unit-m6-20261106-152213352.log](./test-logs/batch-static-lift-unit-m6-20261106-152213352.log).
- x86 original-versus-lift, x86-versus-ARM64, and the device run passed:
  [prefix run](./test-logs/constructor-prefix-00a33600-20261106-152100431/),
  [comparison](./test-logs/constructor-prefix-00a33600-20261106-152100431/comparison.log),
  [generated prefix report](./test-logs/constructor-prefix-00a33600-20261106-152100431/generated/report.json),
  [next-closure diagnostic](./test-logs/constructor-prefix-00a33600-20261106-152100431/generated/closure-blocker-00a2a210.json).
- The recursive, cross-function, five-function startup-import, XCHG, SSE,
  x87, import, and critical-section regressions passed on the same device:
  [five-function regression](./test-logs/five-function-regression-m6-20261106-152213355.log).

The working tree is uncommitted; `HEAD` remains
`eadb54eb8c679f63a57102f350c8dbc82b5245d6`. The next bounded investigation is the minimum verified closure needed by
`FUN_00921260`, beginning with its unsupported arithmetic and indexed-address
forms. No broad closure beyond this target was added in Marco 6.

## Preserved one-function recursive-call pilot

The earlier recursive pilot and its runtime are retained unchanged as a
separate regression. `tools/generate_recursive_call_lift.py` remains
deliberately limited to `FUN_006237a0`; it independently verifies the
reference PE hash, the function's 33 bytes, and that the direct `CALL` at
`0x006237aa` targets `0x006237a0`. It emits the pre-existing pilot lift and
byte header; the recovered batch backend does not replace that runtime.

The translated body executes the recursive call through shared guest memory,
registers, EIP, and ESP. Each guest `CALL` pushes return address
`0x006237af`; nested-call depth distinguishes recursive returns from the
external return, which is also tested with the same address to prevent a
sentinel collision. The object fields read are `[ESI+0x30]` (the next-node
pointer) and `[ESI+0x34]` (the value); the harness supplies those objects as
explicit fixtures. The base case returns the current node's value; each
recursive caller adds its own value to the returned child sum. The routine
preserves ESI and leaves the object graph unchanged. Unknown control flow and
guest-memory failures return an error status rather than a prepared result.

Validation on 2026-11-06:

- The x86 harness executed the verified function bytes and compared them with
  the generated guest lift for chain depths 0 through 3. Return values, ECX,
  arithmetic flags, recursive call count and stack balance matched; the
  harness also checked native return addresses, callee-saved registers,
  unchanged object memory, guest stack canaries and the rejection paths.
- The same harness compiled successfully for `aarch64-linux-android29`.
- The ARM64 binary then ran successfully on the connected `2303ERA42L` phone.
  Depths 0 through 3, guest CALL/RET, the external return-address collision,
  stack canaries, and both rejection paths passed.
- The existing x86 graphics-parameter regression was rerun and passed,
  including the dimensions, presentation-mode and configuration-query fixture
  cases. Its configuration test still uses fixture stubs, not the original
  configuration loader:
  [graphics-parameter-x86-reference-2026-11-06.log](./test-logs/graphics-parameter-x86-reference-2026-11-06.log).
- On the phone, the D3D9 bridge, manual graphics probe, window-global probe,
  and device-global configuration-fixture/recreation regressions all passed:
  [D3D9](./test-logs/d3d9-bridge-regression-rerun-2026-11-06.log),
  [manual probe](./test-logs/translated-graphics-manual-regression-rerun-2026-11-06.log),
  [window-global](./test-logs/translated-window-global-increment-regression-rerun-2026-11-06.log),
  [fixture and stale-token recreation](./test-logs/config-windowed-device-regression-rerun-2026-11-06.log).
- This pilot is not wired into the Android graphics probe and does not replace
  the configuration fixture. Existing Android graphics and fixture
  sources/logs were left intact.

Reproduce the preserved pilot generation, x86 comparison and ARM64
compilation from PowerShell:

```powershell
.\tools\run_recursive_call_lift.ps1 -BuildOnly
```

With one authorized ARM64 device connected, run the same chain through ADB:

```powershell
.\tools\run_recursive_call_lift.ps1 -DeviceSerial <serial>
```

The earlier direct-call-only run records are
[call-chain-006237a0-2026-11-06.log](./test-logs/call-chain-006237a0-2026-11-06.log)
and
[call-chain-006237a0-device-2026-11-06.log](./test-logs/call-chain-006237a0-device-2026-11-06.log).
The separate recursive pilot remains unchanged. The recovered backend now has
a first tested initialization-linked closure, while startup from the game's
entry point and the `CreateMutexA` branch remain unimplemented.
