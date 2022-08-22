cmake_minimum_required(VERSION 3.10)
project(SafeInt VERSION 3.0.26)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Runtime tests are:
# - default
# - without built-in 128-bit support
# - without intrinsics

# Compile time tests are:
# - default C++11
# - C++14
# - TODO - consider adding in 17, 20 just to see if anything breaks
# - compile without exceptions

# Supported compilers:
# - Microsoft
# - clang
# - gcc
# - Intel (not regularly tested)
# other compilers on a best effort

add_subdirectory(Test/ClangTest)
add_subdirectory(Test/GccTest)
add_subdirectory(Test/MsvcTest)

enable_testing()