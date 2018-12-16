cmake_minimum_required(VERSION 3.10)

project(core LANGUAGES CXX)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "source/*.cpp")

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_SOURCE}
        include/core/stl/String.hpp)

add_library(rtb::core ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)
