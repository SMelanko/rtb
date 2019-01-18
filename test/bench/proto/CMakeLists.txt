cmake_minimum_required(VERSION 3.9.2)

project(benchmark-proto LANGUAGES CXX)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "*.cpp")

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCE}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::google-benchmark
        rtb::proto
        test::data
)
