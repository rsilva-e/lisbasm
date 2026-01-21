# 1. Compile Assembly and generate libasm.a
make

# 2. Compile main.c and link with libasm.a
gcc main.c libasm.a -o test

# 3. Run
./test



| Assembly    | C equivalent         | Example in C                      |
| ----------- | -------------------- | --------------------------------- |
| `cmp a, b`  | `a - b` (comparison) | `if (a == b)`                     |
| `je label`  | `==`                 | `if (a == b)`                     |
| `jne label` | `!=`                 | `if (a != b)`                     |
| `jb label`  | `<` (unsigned)       | `if ((unsigned)a < (unsigned)b)`  |
| `jbe label` | `<=` (unsigned)      | `if ((unsigned)a <= (unsigned)b)` |
| `ja label`  | `>` (unsigned)       | `if ((unsigned)a > (unsigned)b)`  |
| `jae label` | `>=` (unsigned)      | `if ((unsigned)a >= (unsigned)b)` |
| `jl label`  | `<` (signed)         | `if (a < b)`                      |
| `jle label` | `<=` (signed)        | `if (a <= b)`                     |
| `jg label`  | `>` (signed)         | `if (a > b)`                      |
| `jge label` | `>=` (signed)        | `if (a >= b)`                     |



;| Tipo de retorno em C | Registo correto |
;| -------------------- | --------------- |
;| `int` / `int32_t`    | `eax`           |
;| `long` / ponteiro    | `rax`           |
;| `char` / `short`     | `al` / `ax`     |
