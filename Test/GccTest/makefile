#makefile for SafeInt test harness using clang

all: SafeIntTest CompileTest CompileTest_C_HEADER CompileTest14 CompileTest14_NoEH

clean:
	rm -f SafeIntTest
	rm -f CompileTest
	rm -f CompileTest_C_Header
	rm -f CompileTest14
	rm -f *.err


SafeIntTest: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	g++ --std=c++11 -O3 ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest 2> SafeIntTest.err

CompileTest: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++11 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest 2> CompileTest.err

CompileTest_C_HEADER: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -D SAFEINT_USE_C_HEADERS -Wall --std=c++11 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest_C_Header 2> CompileTest_C_Header.err

CompileTest14: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++14 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest14 2> CompileTest14.err

CompileTest14_NoEH: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -fno-exceptions -Wall --std=c++14 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest14 2> CompileTest14_noEH.err
