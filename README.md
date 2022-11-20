# cmake-cpp-project-template
Template for C++ CMake header-only library

## Build
```bash
$ cmake -S . -B build
$ cmake --build build
```

### Build Options
I suggest to build all the application using `ninja` instead of `Makefiles` as CMake generator:
```bash
$ cmake -S . -B build -GNinja
$ cmake --build build
```

Time differences are noticible.

## Test
```bash
$ cmake -S . -B build -DENABLE_TESTING=ON
$ cmake --build build
$ cmake --build build --target test
```

### CTest
CMake test are handled by default by CTests; some usefull flags are `--rerun-failed` and `--output-on-failure`
```bash
$ cd build
$ ctest --rerun-failed --output-on-failure
```

## CMake Options
| OPTION                        | DESCRIPTION                                       |
|-------------------------------|---------------------------------------------------|
| WARNINGS_AS_ERRORS            | Treat compiler warnings as errors                 |
| ENABLE_TESTING                | Enable building test applications                 |
