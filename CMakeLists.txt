cmake_minimum_required(VERSION 3.14)
project(CPractice)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(docgia_lib
    src/DocGia.cpp
    src/Ngay.cpp
    src/DocGiaNguoiLon.cpp
    src/DocGiaTreEm.cpp
    src/ThuVien.cpp
)

# --- Your tests ---
enable_testing()
add_executable(run_tests src/tests/test_docgia.cpp)
target_link_libraries(run_tests docgia_lib GTest::gtest GTest::gtest_main)

# --- Your actual program ---
add_executable(quanlydocgia src/main.cpp)
target_link_libraries(quanlydocgia docgia_lib)

# --- API server ---
add_executable(api_server api/main.cpp)
target_link_libraries(api_server httplib::httplib)

include(GoogleTest)
gtest_discover_tests(run_tests)