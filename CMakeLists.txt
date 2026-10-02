cmake_minimum_required(VERSION 3.14)
project(CPractice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(docgia_lib
    src/DocGia.cpp
    src/Ngay.cpp
)

enable_testing()
add_executable(run_tests src/tests/test_docgia.cpp)
target_link_libraries(run_tests docgia_lib GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)