# cmake-cpp-project-template
Template for C++ CMake application

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

`ninja`:
```bash
❯ cmake --build build
[0/2] Re-checking globbed directories...
[14/14] Linking CXX executable test/project_template_test
cmake-project-template application* 8s
```

`Makefile`:
```bash
❯ cmake --build build
[  7%] Building CXX object src/CMakeFiles/project_template_lib.dir/lib.cpp.o
[ 14%] Linking CXX static library libproject_template_lib.a
[ 14%] Built target project_template_lib
[ 21%] Building CXX object app/CMakeFiles/project_template.dir/main.cpp.o
[ 28%] Linking CXX executable project_template
[ 28%] Built target project_template
[ 35%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 42%] Linking CXX static library ../../../lib/libgtest.a
[ 42%] Built target gtest
[ 50%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 57%] Linking CXX static library ../../../lib/libgtest_main.a
[ 57%] Built target gtest_main
[ 64%] Building CXX object test/CMakeFiles/project_template_test.dir/tst_lib.cpp.o
[ 71%] Linking CXX executable project_template_test
[ 71%] Built target project_template_test
[ 78%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
cmake-project-template application* 13s
```

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

## Reference
A more in depth example can be found [here](https://github.com/cpp-best-practices/cpp_starter_project).