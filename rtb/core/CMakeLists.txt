cmake_minimum_required(VERSION 3.10)

project(core LANGUAGES CXX)

include(cotire)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE "source/*.cpp")

set(${PROJECT_NAME}_PCH
    pch.hpp
)

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_SOURCE}
    ${${PROJECT_NAME}_PCH}
)

add_library(rtb::core ALIAS ${PROJECT_NAME})

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
    PRIVATE
        ${PROJECT_SOURCE_DIR} # Make pch.hpp visible
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${CONAN_LIBS}
)

set(COTIRE_MINIMUM_NUMBER_OF_TARGET_SOURCES 1)
set_target_properties(${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "pch.hpp")
cotire(${PROJECT_NAME})
