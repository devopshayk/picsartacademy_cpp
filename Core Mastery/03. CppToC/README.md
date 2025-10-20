## C++ ➜ C: Translating a Small OOP Example

This mini-project shows how an object-oriented C++ snippet can be expressed in plain C.

- **Files**:
  - `main.cpp`: C++ version using a `Person` class, constructors, method overloading, and iostreams.
  - `main.c`: C version using a `struct`, init functions, standalone getters/setters, and stdio.

### What the example does
Both programs represent a `Person` with three fields — `name`, `age`, `height` — and demonstrate:

- constructing/initializing a person
- printing information (with and without height in C++)
- updating a field and reading it back

### Design translation at a glance

| Concept | C++ (`main.cpp`) | C (`main.c`) |
|---|---|---|
| Type definition | `class Person { ... };` | `typedef struct { ... } Person;` |
| Construction | Constructors (`Person()`, `Person(n,a,h)`) | Init functions (`person_def_init`, `person_param_init`) |
| Encapsulation | Private fields + public methods | Public fields by convention; encapsulation via API discipline |
| Getters/Setters | `getName()`, `setAge(int)` | `getName(Person*)`, `setAge(Person*, int)` |
| Method overloading | `printInfo()` and `printInfo(bool)` | Separate functions: `printInfo(Person*)`, `printInfoHeight(Person*, bool)` |
| I/O | `std::cout` | `printf` |

Notes:
- The C++ default constructor sets `name = "Unknown"`; the C default init sets `name = "Hayk"` as a simple placeholder.
- In C, strings are fixed-size arrays (`char name[50]`), so init/setters use `strncpy` and manual null-termination.

### Build and run

```bash
# C++
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o cpp_person && ./cpp_person

# C
gcc -std=c17 -Wall -Wextra -O2 main.c -o c_person && ./c_person
```

### Key takeaways

- **Classes → structs + functions**: group related data and expose operations as a small, consistent API.
- **Constructors → init functions**: name them clearly; keep invariants in one place.
- **Overloads → separate functions**: encode intent in the function name when overloading is unavailable.
- **Streams → printf**: pick formatting wisely; consider helper functions for repeated formatting.

### Ideas to extend

- Add validation in setters (e.g., non-negative `age`, sensible `height`).
- Split the C API into `person.h`/`person.c` and reuse it across programs.
- Implement `printInfo` variants in C that mirror the C++ behavior more closely (e.g., a single function with a flag or format options).
- Add serialization (to/from text) for both versions.

Happy translating! 🛠️


