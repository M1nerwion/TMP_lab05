cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(tests)

add_executable(test tests.cpp)

target_link_libraries(test banking gtest gmock)







