#makefile for SafeInt test harness using clang

all: SafeIntTest CompileTest

clean:
	rm -f SafeIntTest
	rm -f CompileTest

SafeIntTest: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	g++ --std=c++11 ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest

CompileTest: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++11 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest

CompileTest14: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++14 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest

