cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" ON)
option(COVERAGE "Check coverage" ON)

project(itog)

#add_subdirectory(banking)
#add_subdirectory(third-party/gtest)
#add_subdirectory(tests)

add_library(banking STATIC banking/Account.cpp banking/Transaction.cpp)
target_include_directories(banking PUBLIC banking/)

if(BUILD_TESTS)
	enable_testing()
	add_subdirectory(third-party/gtest)
	add_executable(check tests/test1.cpp)
	target_link_libraries(check banking gtest_main gmock_main)
	add_test(NAME check COMMAND check)
endif()

if (COVERAGE)
	target_compile_options(check PRIVATE --coverage)
	target_link_libraries(check --coverage)
endif()

#include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/tests)
#add_executable(testion tests/test1.cpp)
#target_link_libraries(testion banking gtest gmock)




