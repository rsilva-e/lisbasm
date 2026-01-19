# 1. Compila Assembly e gera libasm.a
make

# 2. Compilar main.c e linkar com libasm.a
gcc main.c libasm.a -o test

# 3. Executar
./test


| Assembly    | C equivalente        | Exemplo em C                      |
| ----------- | -------------------- | --------------------------------- |
| `cmp a, b`  | `a - b` (comparação) | `if (a == b)`                     |
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


