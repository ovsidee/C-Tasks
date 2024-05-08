cmake_minimum_required(VERSION 3.27)
project(Manipulating_the_display_format_of_data)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(Manipulating_the_display_format_of_data main.cpp)
target_link_libraries(Manipulating_the_display_format_of_data fmt)