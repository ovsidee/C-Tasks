cmake_minimum_required(VERSION 3.27)
project(C_Tasks)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(C_Tasks BoxPrint/boxPrint.cpp)
target_link_libraries(C_Tasks fmt)

add_executable(larg largestGroupsOfAnagramsFrom/largestGroupsOfAnagramsFrom.cpp)
target_link_libraries(larg fmt)

add_executable(manipulate manipulatingTheDisplayFormatOfData/manipulatingTheDisplayFormatOfData.cpp)
target_link_libraries(manipulate fmt)

add_executable(newAlgorithms newAlgorithms/newAlgorithms.cpp)
target_link_libraries(newAlgorithms fmt)

add_executable(reversingWordsByTheirOrder reversingWordsByTheirOrder/reversingWords.cpp)
target_link_libraries(reversingWordsByTheirOrder fmt)

add_executable(splittingRangesIntoChunks splittingRangesIntoChunks/splittingRangesIntoChunks.cpp)
target_link_libraries(splittingRangesIntoChunks fmt)

add_executable(standardLibraryEnhancements standardLibraryEnhancements/standardLibraryEnhancements.cpp)
target_link_libraries(standardLibraryEnhancements fmt)