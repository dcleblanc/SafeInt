#makefile for SafeInt test harness using clang

all: SafeIntTest CompileTest

clean:
	rm SafeIntTest
	rm CompileTest

SafeIntTest: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	clang++ --std=c++11 ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest

CompileTest: ../CompileTest.cpp ../../SafeInt.hpp
	clang++ --std=c++11 ../CompileTest.cpp -o CompileTest
