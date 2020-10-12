add_executable(SafeInt_Test
    AddVerify.cpp
    CastVerify.cpp
    DivVerify.cpp
    IncDecVerify.cpp
    ModVerify.cpp
    MultVerify.cpp
    SubVerify.cpp
    TestMain.cpp
    TestMain.h)
target_link_libraries(SafeInt_Test PRIVATE SafeInt)

add_executable(SafeInt_CompileTest
    CleanCompile.cpp
    CompileTest.cpp
    ConstExpr.cpp)
target_link_libraries(SafeInt_CompileTest PRIVATE SafeInt)

if(SAFEINT_SANITIZE)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(SafeInt_Test PRIVATE -fsanitize=undefined -ftrapv)
        target_link_libraries(SafeInt_Test PRIVATE -fsanitize=undefined)
    endif()
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(SafeInt_CompileTest PRIVATE -Wall)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(SafeInt_Test PRIVATE /W4)
    target_compile_options(SafeInt_CompileTest PRIVATE /W4)

    # /Oi for "Generate Intrinsic Functions"
    target_compile_options(SafeInt_Test PRIVATE $<$<NOT:$<CONFIG:Debug>>:/Oi>)
    target_compile_options(SafeInt_CompileTest PRIVATE $<$<NOT:$<CONFIG:Debug>>:/Oi>)
endif()

install(TARGETS SafeInt_Test RUNTIME DESTINATION bin)
install(TARGETS SafeInt_CompileTest RUNTIME DESTINATION bin)
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    install(FILES "$<TARGET_PDB_FILE:SafeInt_Test>" DESTINATION bin OPTIONAL)
    install(FILES "$<TARGET_PDB_FILE:SafeInt_CompileTest>" DESTINATION bin OPTIONAL)
endif()
