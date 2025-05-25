cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)
option(COVERAGE "Enable code coverage" ON)

project(itog)

add_subdirectory(banking)
add_subdirectory(third-party/gtest)
add_subdirectory(tests)

if(COVERAGE)
    message(STATUS "Coverage build enabled")
    target_compile_options(banking PRIVATE -fprofile-arcs -ftest-coverage -O0)
    target_link_libraries(banking PRIVATE gcov)
endif()

if(COVERAGE)
    target_compile_options(banking_tests PRIVATE -fprofile-arcs -ftest-coverage -O0)
    target_link_libraries(banking_tests PRIVATE gcov)
endif()

#set(INSTALL_GTEST OFF)


#include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/tests)
#add_executable(testion tests/test1.cpp)
#target_link_libraries(testion banking gtest gmock)




