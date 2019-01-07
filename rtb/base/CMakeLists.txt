cmake_minimum_required(VERSION 3.10)

project(base LANGUAGES CXX)

file(GLOB_RECURSE ${PROJECT_NAME}_INCLUDE "include/*.hpp")
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "source/*.cpp")

source_group("include" FILES ${${PROJECT_NAME}_INCLUDE})
source_group("source" FILES ${${PROJECT_NAME}_SOURCE})

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_INCLUDE}
    ${${PROJECT_NAME}_SOURCE}
)

add_library(rtb::base ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall -Wextra -Werror -pedantic -pedantic-errors
    )
endif ()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::fmt
        CONAN_PKG::range-v3
)
