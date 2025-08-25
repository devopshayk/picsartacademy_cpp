# Minimal Example: Object Files (.o) and Static Libraries (.a)

This guide explains what `.o` and `.a` are using one smallest possible example with four files. No extra theory—just what you need to understand and use them confidently.

---

## 1) Project Files

These files are already in this folder:

- `mylib.h` — library header (declares functions)
- `file1.c` — implements `sum(int a, int b)`
- `file2.c` — implements `diff(int a, int b)`
- `main.c` — uses `sum` and `diff`

You do NOT need to open these files to follow the guide.

---

## 2) Build: from .c → .o → .a → executable

Step 1 — Compile sources to object files:

```bash
gcc -c file1.c -o file1.o
gcc -c file2.c -o file2.o
```

- Output: `file1.o`, `file2.o` — these are ELF relocatable object files containing machine code and metadata (symbols, relocations).

Step 2 — Create a static library (`.a`) from object files:

```bash
ar rcs libmylib.a file1.o file2.o
```

- Output: `libmylib.a` — an archive that bundles multiple `.o` files with a symbol index.

Step 3 — Build the final program by linking with the library:

```bash
gcc main.c -L. -lmylib -o app
```

- Output: `app` — the executable. The linker pulls needed object files from `libmylib.a` and resolves symbols used by `main.c`.

Run it:

```bash
./app
```

Expected output:

```
sum(6, 4) = 10
diff(6, 4) = 2
```

Clean (optional):

```bash
rm -f *.o *.a app
```

---

## 3) What happens at each step

- Compile (`gcc -c`):
  - Each `.c` becomes a `.o` (ELF relocatable object)
  - Contains: machine code for that translation unit, symbol table, and relocation entries
- Archive (`ar rcs`):
  - `libmylib.a` is created as an archive of object files with a fast symbol index
  - No code generation happens here—just packaging
- Link (`gcc main.c -L. -lmylib -o app`):
  - `main.c` calls `sum` and `diff` → they are undefined in `main.o`
  - The linker scans `libmylib.a`, extracts only required members (`file1.o`, `file2.o`), applies relocations, and produces the executable

Tip: order matters. Place libraries after the objects that use them (as shown above).

---

## 4) ELF essentials (just what you need)

Inside each `.o` (relocatable object), you’ll typically find:

- `.text` — function machine code (e.g., `sum`, `diff`)
- `.rodata` — read-only data (string literals, if any)
- `.data` / `.bss` — initialized / zero-initialized globals (none here)
- `.symtab` + `.strtab` — symbols and their names
- `.rel.*` / `.rela.*` — relocation entries telling the linker what addresses to fix up

Executables and shared objects add program headers (loader view), but relocatable `.o` files do not need them because they aren’t runnable on their own.

---

## 5) Inspect and verify (optional but useful)

Check symbols in an object file:

```bash
nm file1.o       # expect a T (text) symbol for sum
```

See sections in an object file:

```bash
readelf -S file1.o
```

List members of the static library:

```bash
ar t libmylib.a
```

Explain unresolved symbol problems:

```bash
nm main.o        # look for U (undefined) symbols: sum, diff
```

---

## 6) Troubleshooting

| Problem | Fix |
|--------|-----|
| `undefined reference to 'sum'` | Ensure `-lmylib` is provided and appears after `main.c` |
| `cannot find -lmylib` | Add `-L.` or specify the correct path to the library |
| Output didn’t change | Rebuild: `rm -f *.o *.a app` then repeat steps 1–3 |
| Wrong function picked | Ensure header prototypes match implementations and there are no duplicate symbols in other objects |

---

## 7) Why use a static library here?

- Faster rebuilds: only changed sources recompile to new `.o`
- Reuse: link the same `libmylib.a` into many programs
- Simplicity: no runtime dependencies on shared libraries
- Trade-off: larger executables (the library code is copied into each program)
