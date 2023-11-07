cmake_minimum_required(VERSION 3.16)
project(EmscriptenTest)

set(TARGET_TYPE "" CACHE STRING "Either python or javascript")

# Set common compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g0")

if(TARGET_TYPE STREQUAL "javascript")
    message(STATUS "EMSCRIPTEN is set!")
    add_executable(binding src/emscripten_binding.cc)
    set_target_properties(binding PROPERTIES LINK_FLAGS
        "-lembind \
        -sMODULARIZE=1 \
        -sENVIRONMENT=web \
        -sEXPORT_NAME=MyLibrary \
        -sEXPORT_ES6=1 \
        -sSINGLE_FILE=1 \
        -sINITIAL_MEMORY=128MB \
        -sALLOW_MEMORY_GROWTH=1 \
        -sMEMORY_GROWTH_GEOMETRIC_STEP=1.0 \
        -sMEMORY_GROWTH_GEOMETRIC_CAP=0"
    )
elseif(TARGET_TYPE STREQUAL "python")
    message(STATUS "PYTHON is set!")
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    find_package(pybind11 CONFIG REQUIRED)
    pybind11_add_module(binding MODULE src/pybind11_binding.cc)
else()
    message(FATAL_ERROR "Invalid TARGET_TYPE!")
    exit(1)
endif(TARGET_TYPE STREQUAL "javascript")