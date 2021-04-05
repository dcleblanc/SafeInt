#makefile for SafeInt test harness using clang

all: clean SafeIntTest SafeIntTest_NoIntrinsic SafeIntTest_NoInt128 CompileTest CompileTest14 test

clean:
	rm -f SafeIntTest
	rm -f SafeIntTest_NoIntrinsic
	rm -f SafeIntTest_NoInt128
	rm -f CompileTest
	rm -f CompileTest14
	rm -f *.err


SafeIntTest: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	g++ --std=c++11 -O3 ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest 2> SafeIntTest.err

SafeIntTest_NoIntrinsic: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	g++ --std=c++11 -O3 -D SAFEINT_USE_INTRINSICS=0 -fsanitize=undefined -ftrapv ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest_NoIntrinsic 2> SafeIntTest_NoIntrinsic.err

SafeIntTest_NoInt128: ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp ../TestMain.h ../../SafeInt.hpp
	g++ --std=c++11 -O3 -D SAFEINT_HAS_INT128=0 -fsanitize=undefined -ftrapv ../AddVerify.cpp ../CastVerify.cpp ../DivVerify.cpp ../IncDecVerify.cpp ../ModVerify.cpp ../MultVerify.cpp ../SubVerify.cpp ../TestMain.cpp -o SafeIntTest_NoInt128 2> SafeIntTest_NoInt128.err

CompileTest: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++11 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest 2> CompileTest.err

CompileTest14: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -Wall --std=c++14 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest14 2> CompileTest14.err

CompileTest14_NoEH: ../CompileTest.cpp ../../SafeInt.hpp ../ConstExpr.cpp ../CleanCompile.cpp
	g++ -fno-exceptions -Wall --std=c++14 -O3 ../CompileTest.cpp ../ConstExpr.cpp ../CleanCompile.cpp -o CompileTest14 2> CompileTest14_noEH.err

test:
	./SafeIntTest
	./SafeIntTest_NoIntrinsic
	./SafeIntTest_NoInt128