cmake_minimum_required(VERSION 3.10)
project(SafeInt VERSION 3.0.26)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(GNUInstallDirs)

# Header-only INTERFACE library.  Consumers should link against the SafeInt
# target to pick up the include path automatically; the test subdirectories
# already do this via target_link_libraries(... PRIVATE SafeInt).
add_library(SafeInt INTERFACE)
target_include_directories(SafeInt INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Installation rules.  Restores the install behavior that was lost when the
# CMake setup was rewritten in 2022 (issue #67); conda-forge, vcpkg, and
# Linux package maintainers rely on the standard `cmake --install` flow to
# place the headers under the user's prefix.
install(TARGETS SafeInt)

install(FILES
    SafeInt.hpp
    safe_math.h
    safe_math_impl.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES LICENSE
    DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})

# Whether to build the test suite.  Defaults ON when SafeInt is the
# top-level project (developer workflow) and OFF when SafeInt is being
# consumed via add_subdirectory or installed by a packager.  Package
# builds can also pass -DSAFEINT_BUILD_TESTING=OFF explicitly; this is
# recommended for `ninja install`-style flows since they would otherwise
# build the entire test suite as a prerequisite of the install target.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    option(SAFEINT_BUILD_TESTING "Build the SafeInt test suite" ON)
else()
    option(SAFEINT_BUILD_TESTING "Build the SafeInt test suite" OFF)
endif()

if(SAFEINT_BUILD_TESTING)
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
endif()