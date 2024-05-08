cmake_minimum_required(VERSION 3.27)
project(Standard_library_enhancements)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(Standard_library_enhancements main.cpp)
target_link_libraries(Standard_library_enhancements fmt)