# renderer

Portable layout using CMake.

Structure:
- src/      : implementation files
- include/  : public headers
- test/     : (optional) tests

Build (Windows):
```
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

Run the produced `renderer` executable.