cmake_minimum_required(VERSION 3.16)
project(renderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(renderer ${SRC_FILES})

if (WIN32)
    target_compile_definitions(renderer PRIVATE NOMINMAX)
    # Link to Windows libraries automatically by MSVC
endif()