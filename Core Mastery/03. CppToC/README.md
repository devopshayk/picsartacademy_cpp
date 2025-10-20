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

Итог: этот пример показывает, как идеи C++ переносятся в C: классы → структуры + функции, конструкторы → init-функции, перегрузка → отдельные функции. Дальше можно развивать API, валидацию и разбиение по файлам.
