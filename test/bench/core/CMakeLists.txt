cmake_minimum_required(VERSION 3.10)

project(benchmark-core LANGUAGES CXX)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "*.cpp")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCE}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::google-benchmark
        CONAN_PKG::boost
        CONAN_PKG::range-v3
        rtb::core
)
