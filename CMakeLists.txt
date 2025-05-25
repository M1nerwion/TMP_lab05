cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

project(itog)

add_subdirectory(banking)
#add_subdirectory(tests)

include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/tests)
add_executable(testion tests/tests_goida.cpp)
target_link_libraries(testion banking gtest gmock)




