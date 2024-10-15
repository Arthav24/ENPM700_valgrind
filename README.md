# Valgrind Exercise

## Problems in the shell-app
- Memory leak at AnalogSensor.cpp:16. In the function memory is allocated at runtime on heap using new operator but delete was not called to free the memory on scope out.
    - Fix: Use delete function or use smart pointers
- Conditional jump or move depends on uninitialised value at main.cpp:5. terminator was declared as bool but was never initialised. At main.cpp:9 terminator variable is used in a condition which causes undesired behaviour.
    - Fix: Initialise the value of variable before use

## What happens when the executable is linked statically?  Does Valgrind still detect those same bugs?
When the executable is linked statically, valgrind is still able to find bugs which were not exactly same but pointed in similar direction. <br>
By default, no replacement is done for a statically linked binary or for alternative libraries, except for the allocation functions (malloc, free, calloc, memalign, realloc, operator new, operator delete, etc.) Such allocation functions are intercepted by default in any shared library or in the executable if they are exported as global symbols.

## Why and Why not?
For static linked apps valgrind works in a restricted manner i.e. only able to intercept allocation functions by default. However, in shared valgrind is able to intercept many more functions not just allocation functions.

```bash

#Command used to run valgrind
valgrind --track-origins=yes --leak-check=full --leak-resolution=high <execuatble path>

Details of files added

valgrind_output.txt
#contains the output of valgrind when app is not statically linked and produces above two errors

valgrind_output_fixed.txt
#contains the output of valgrind when app is not statically linked and produces no errors

valgrind_output_static.txt
#contains the output of valgrind when app is statically linked

```


## Standard install via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# To build with debugging information, do:
  cmake -S ./ -B build/ -D CMAKE_BUILD_TYPE=Debug
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scratch
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

