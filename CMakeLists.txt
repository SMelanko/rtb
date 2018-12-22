cmake_minimum_required(VERSION 3.10)

project(rtb LANGUAGES CXX)

option(ENABLE_TESTING "Run unit tests" ON)
option(ENABLE_BENCHMARKING "Run benchmark tests" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(conan)
conan_cmake_run(CONANFILE conanfile.txt
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(rtb/core)
add_subdirectory(rtb/proto)

if (ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test/unit/core)
    add_subdirectory(test/unit/proto)
endif ()

if (ENABLE_BENCHMARKING)
    add_subdirectory(test/data)
    add_subdirectory(test/bench/core)
    add_subdirectory(test/bench/proto)
endif ()
