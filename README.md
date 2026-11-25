# C Programming Lab Experiments

C programs for the C Programming laboratory course, written by **Faizan Padiyar**.

All 15 programs are complete, compile warning-free with `-Wall -Wextra`, and have
been run against sample input.

## Contents

| File | Experiment |
| --- | --- |
| `Experiment 1.c` | Display a student profile using escape sequences (`\t`, `\n`, `\"`, `\\`) |
| `Experiment 1.2.c` | Read PCM marks, validate them, compute total / average and a result remark |
| `Experiment 2.1.c` | Check whether a number is even or odd |
| `Experiment 2.2.c` | Sum of all integers in a given range (with limit swapping) |
| `Experiment 3.c` | Menu-driven student record system using structures (add / display / search / delete / statistics) |
| `Experiment 4.c` | Prime numbers between two limits (trial division up to √n) |
| `Experiment 5.c` | Fibonacci series using recursion |
| `Experiment 6.c` | Storage classes in C — `static` variables retaining state between calls |
| `Experiment 7.1.c` | Arrays — input validation, sum / average / largest / smallest and bubble sort |
| `Experiment 7.2.c` | Addition of two matrices |
| `Experiment 8.1.c` | String length, reverse, vowel/consonant count and palindrome check |
| `Experiment 9.c` | Array of structures — read 5 student records and find the topper |
| `Experiment 10.1.c` | Pointers — sum of two numbers through pointers, plus pointer indirection |
| `Experiment 10.2.c` | Pointers — swap two values and reverse an array in place |
| `Experiment 11.c` | Menu-driven employee management system using structures and file I/O |

## Compiling and running

Each file is a standalone program. With GCC:

```sh
gcc "Experiment 2.1.c" -o exp2_1
./exp2_1
```

Compile all of them at once:

```sh
for f in *.c; do gcc -Wall -Wextra -std=c11 "$f" -o "${f%.c}"; done
```

`Experiment 11.c` stores its records in `employees.dat` in the working directory.

## Notes

Fifteen of the sixteen expected experiments are included; **Experiment 8.2** was not
present in the source material available, so it is not part of this repository.

**Author:** Faizan Padiyar
