cmake_minimum_required(VERSION 3.10)

project(rtb LANGUAGES CXX)

option(ENABLE_TESTING "Run unit tests" OFF)
option(ENABLE_BENCHMARKING "Run benchmark tests" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(conan)
conan_cmake_run(CONANFILE conanfile.txt
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(rtb/core)

if (ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test/unit/core)
endif ()

if (ENABLE_BENCHMARKING)
    add_subdirectory(test/bench/core)
endif ()
