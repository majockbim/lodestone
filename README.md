# lodestone

## what is it

lodestone _is_ a physics engine to calculate 3D vector fields at high performance

## physics

currently calculating magnetic field vector fields due to a single magnetic dipole.

the core equation used is:
```
B = (μ₀/4π) · (1/r³) · [3(m·r̂)r̂ - m]
```

## current architecture

* **language**: C++17
* **math**: eigen <br>
  * **note**: "eigen performs best with compilers based on GCC or LLVM/CLANG" [1]
  * with this information in mind, lodestone will be compiler agnostic with only GCC and CLANG to maximize performance

## inspiration(s)

a neodymium magnet i found stuck to a chair

# build

default compilation (uses your system's default compiler):
```bash
cmake -S . -B build
cmake --build build
```

force compilation with g++ (gcc):
```bash
cmake -G "MinGW Makefiles" -S . -B build
cmake --build build
```
run the engine:
```bash
.\build\Debug\lodestone.exe
```

run the tests:
```bash
cmake --build build --target lodestone_tests
cd build
ctest --output-on-failure
```

## reference(s)

[1] [Eigen: A C++ template library for linear algebra](https://libeigen.gitlab.io/) <br>

_books that have influence the modularity of lodestone_ <br>
[2] [C++17 In Detail - _Bartłomiej Filipek_](https://www.cppindetail.com/) <br>
[3] [Effective Modern C++ - _Scott Meyers_](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/)

_tutorials that have been helpful_ <br>
[4] [Learn OpenGL: Creating a window](https://learnopengl.com/Getting-started/Creating-a-window)
[5] [GLFW: Getting started](https://www.glfw.org/docs/latest/window_guide.html)
