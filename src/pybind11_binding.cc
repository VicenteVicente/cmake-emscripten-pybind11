#include <pybind11/pybind11.h>

#include "library.h"

namespace py = pybind11;

PYBIND11_MODULE(binding, m) {
    m.def("hello_world", &Library::hello_world);
    m.def("add", &Library::add);
    m.def("memory", &Library::memory);
}