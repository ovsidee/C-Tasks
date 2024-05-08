cmake_minimum_required(VERSION 3.27)
project(Splitting_ranges_into_chunks)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(Splitting_ranges_into_chunks main.cpp)
target_link_libraries(Splitting_ranges_into_chunks fmt)