#include <emscripten/bind.h>

#include "library.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module_name) {
  function("hello_world", &Library::hello_world);
  function("add", &Library::add);
  function("memory", &Library::memory);
}