cmake_minimum_required(VERSION 3.9.2)

project(unit-test-proto LANGUAGES CXX)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "*.cpp")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCE}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall -Wextra -Werror -pedantic -pedantic-errors -fPIC
    )
endif ()

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::gtest
        rtb::proto
        test::data
)
