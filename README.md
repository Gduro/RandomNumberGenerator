# Random Number Generator

A simple C++ command-line tool that generates random integers within a user-defined range, with support for repeated generation sessions.

## Features

- Generate `n` random integers within a `[min, max]` range
- Repeat generation as many times as you want in one run
- Dynamic memory allocation via `realloc`
- Enter `0` to exit the loop cleanly

## Getting Started

### Prerequisites

- A C++ compiler (g++, clang++, MSVC, etc.)

### Build

```bash
g++ -o rand_gen main.cpp
```

### Run

```bash
./rand_gen
```

## Usage

```
Enter max of generated num:
100
Enter min of generated num:
1
How many numbers do u want to generate?
5
23 67 4 89 12
How many numbers do u want to generate?
3
55 7 41
How many numbers do u want to generate?
0
```

- Enter `max` and `min` once at startup — they apply to every generation session.
- Keep entering how many numbers you want; the program loops until you enter `0`.

## Known Limitations / Potential Issues

> These are worth fixing before using this in production or a larger project.

- **`realloc` result not reflected in caller** — `temps` is passed by value, so the reallocated pointer is lost after `genRand` returns. The `free(temps)` in `main` may free a stale (or null) pointer. To fix, pass `int **temps` or return the pointer.
- **No input validation** — no check that `max >= min`, or that `n` is positive before calling `realloc`.
- **`rand()` is not cryptographically secure** — fine for casual use, but not suitable for security-sensitive applications. Consider `<random>` from C++11 for better distribution quality.

## Project Structure

```
.
└── main.cpp    # Single-file implementation
```

## License

This project is unlicensed. Do whatever you want with it.
