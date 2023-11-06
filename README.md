# Emscripten/CMake example

This is an example for compiling a C++ library using CMake and Emscripten. It also provides an example of its usage on a html page.

## Install emscripten

```bash
sudo apt-get install emscripten
```

## Compile

```bash
emcmake cmake -B build/Release/ -D CMAKE_BUILD_TYPE=Release
cmake --build build/Release/
```

## Run

Just start a web server and navigate to `host:port/index.html`.
