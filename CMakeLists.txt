cmake_minimum_required(VERSION 3.0)

project(SafeInt CXX)

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

add_library(SafeInt INTERFACE)
target_include_directories(SafeInt INTERFACE .)
install(FILES SafeInt.hpp DESTINATION include)
install(FILES LICENSE DESTINATION share)

if(SAFEINT_TESTS)
    add_subdirectory(Test)
endif()
