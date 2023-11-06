cmake_minimum_required(VERSION 3.16)
project(EmscriptenTest)

if(EMSCRIPTEN)
    message(STATUS "EMSCRIPTEN is set!")
    add_executable(binding src/binding.cc)
    # -sENVIRONMENT=web
    set_target_properties(binding PROPERTIES LINK_FLAGS
        "-O3 \
        -g0 \
        -lembind \
        -sMODULARIZE=1 \
        -sEXPORT_NAME=MyLibrary \
        -sEXPORT_ES6=1 \
        -sSINGLE_FILE=1 \
        -sINITIAL_MEMORY=128MB \
        -sALLOW_MEMORY_GROWTH=1 \
        -sMEMORY_GROWTH_GEOMETRIC_STEP=1.0 \
        -sMEMORY_GROWTH_GEOMETRIC_CAP=0"
    )
else()
    message(FATAL_ERROR "EMSCRIPTEN is not set!")
    exit(1)
endif(EMSCRIPTEN)