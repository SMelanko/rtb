cmake_minimum_required(VERSION 3.10)

project(bench LANGUAGES CXX)

file(GLOB ${PROJECT_NAME}_SOURCES "*.cpp")

add_executable(${PROJECT_NAME}
    ${PROJECT_NAME}_SOURCES
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>:
            -Wall -Wextra -Werror -Wpedantic -pedantic-errors -pipe>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)
