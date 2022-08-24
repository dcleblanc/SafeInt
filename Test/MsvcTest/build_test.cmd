cmake --build . --config Debug
cmake --build . --config Release
ctest -C Debug
ctest -C Release