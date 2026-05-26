# lodestone

## what is it

lodestone _is_ a physics engine to calculate 3D vector fields at high performance

## current architecture

* **language**: C++17
* **math**: eigen <br>
* * **note**: "eigen performs best with compilers based on GCC or LLVM/CLANG" [1]
* * with this information in mind, lodestone will be compiler agnostic with only GCC and CLANG to maximize performance

## inspiration(s)

a neodymium magnet i found stuck to a chair

# build
```bash

cmake -S . -B build
cmake --build build

```

```bash
.\build\Debug\lodestone.exe
```

## reference(s)

[1] [Eigen: A C++ template library for linear algebra](https://libeigen.gitlab.io/) <br>
_books that have influence the modularity of lodestone_
[2] [C++17 In Detail - _Bartłomiej Filipek_](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/)
[3] [Effective Modern C++ - _Scott Meyers_](https://www.cppindetail.com/)

