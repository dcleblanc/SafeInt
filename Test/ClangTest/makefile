#makefile for SafeInt test harness using clang

all: SafeIntTest CompileTest CompileTest14

clean:
	rm -f SafeIntTest
	rm -f CompileTest
	rm -f CompileTest14
	rm -f *.err

SafeIntTest: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	clang++ --std=c++11 ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest 2> SafeIntTest.err

CompileTest: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	clang++ -Wall --std=c++11 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest 2> CompileTest.err

CompileTest14: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	clang++ -Wall --std=c++14 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest14 2> CompileTest14.err
