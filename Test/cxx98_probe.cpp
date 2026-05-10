// Minimal c++98 probe used by Test/{Gcc,Clang}Test/CMakeLists.txt to detect
// whether the toolchain's C++ standard library headers are still usable
// under -std=c++98.  As of libstdc++ 13, <cstdint> (and most other
// headers) hard-error under c++98, so the c++98 CompileTest targets are
// unbuildable on that toolchain.
#include <cstdint>
int main() { return 0; }
