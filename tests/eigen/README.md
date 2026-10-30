# Eigen test

A small standalone test to check that the system-installed Eigen headers compile
and basic vector operations work. Requires `g++` and Eigen installed at
`/usr/include/eigen3`.

The `eigen_test.cpp` file is the C++ version. The original `eigen_test.c` is kept
for reference; its contents were already C++, compiled using `-x c++`.

## Compile and run

From the project root (`/home/mj/code/lodestone`):

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra \
  -I /usr/include/eigen3 \
  tests/eigen/eigen_test.cpp -o build/eigen_test

./build/eigen_test
```

- The `.cpp` extension selects C++ automatically; `-x c++` is unnecessary.
- `-std=c++17` selects the project's C++ standard.
- `-Wall -Wextra` enables compiler warnings.
- `-I /usr/include/eigen3` uses the system Eigen headers rather than the bundled
  copy in `inc/Eigen/`.
- `-o` writes the executable to `build/eigen_test`, inside the Git-ignored build folder.

## What the test does

Creates two double-precision vectors using `Eigen::Vector3d`:
`a = (3, 4, 0)` and `b = (1, 2, 3)`. It checks:

- **Addition:** `a + b` gives `(4, 6, 3)`.
- **Dot product:** `a.dot(b)` gives `3*1 + 4*2 + 0*3 = 11`.
- **Length:** `a.norm()` gives `sqrt(3*3 + 4*4 + 0*0) = 5`.

The sum is stored as a concrete vector. `.transpose()` prints it horizontally.
The checks use a tolerance of `1e-12` for floating-point comparisons and return
exit code `1` if any check fails, or `0` if all checks pass.

Expected output:

```text
a + b: 4 6 3
a dot b: 11
length of a: 5
Eigen test passed
```
