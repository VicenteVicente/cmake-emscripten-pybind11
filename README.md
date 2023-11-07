# CMake emsripten/pybind11 cross-compilation example

This is an example for compiling a C++ library using CMake and either pybind11 or emscripten. It also provides an example of its usage on a html page and a python module.

## Install emscripten

```bash
sudo apt-get install emscripten
```

## Compile to javascript

```bash
emcmake cmake -B build/ -DTARGET_TYPE="javascript"
cmake --build build/
```

## Install pybind11

```bash
pip3 install "pybind11[global]"
```

## Compile to python

```bash
cmake -B build/ -DTARGET_TYPE="python"
cmake --build build/
```

## Run javascript

Just start a web server on this directory and navigate to `host:port/index.html`.

## Run python

Move the compiled library and run `main.py`.

```bash
mv build/binding.<ext> binding.<ext>
python3 main.py
```
