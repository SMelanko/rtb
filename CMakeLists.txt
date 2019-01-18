cmake_minimum_required(VERSION 3.9.2)

project(rtb LANGUAGES CXX)

set(DEFAULT_BUILD_TYPE "Release")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}")
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE
        PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo"
    )
endif ()

option(ENABLE_TESTING "Run unit tests" ON)
option(ENABLE_BENCHMARKING "Run benchmark tests" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(conan)
conan_cmake_run(CONANFILE conanfile.txt
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(rtb/base)
add_subdirectory(rtb/proto)

if (ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test/unit/base)
    add_subdirectory(test/unit/proto)
endif ()

if (ENABLE_BENCHMARKING)
    add_subdirectory(test/data)
    add_subdirectory(test/bench/base)
    add_subdirectory(test/bench/proto)
endif ()
