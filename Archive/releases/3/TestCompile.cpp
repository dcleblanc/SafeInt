#if defined __GNUC__
#include "SafeIntGcc.hpp"
#endif

#include "SafeInt3.hpp"

#if defined SAFEINT_VS_VERSION
using namespace Microsoft;
using namespace Utilities;
using namespace details;
#endif


#if !defined __GNUC__
// 4514 unreferenced inline function has been removed
#pragma warning(disable: 4189 4514)
#endif

template <typename T, typename U>
void TestCasts()
{
	SafeInt<T> st;
	U u = st;
	bool b = st;
#if !defined SAFEINT_VS_VERSION
	float f = st;
	double d = st;
	long double ld = st;
#endif
	u++;
}

template <typename T, typename U>
void TestConstructors()
{
	SafeInt<T> st;
	SafeInt<U> su;
	U u;
	SafeInt<T> st2(u);
	SafeInt<T> st3(su);
	// We can also construct from a bool
	bool b = false;
	SafeInt<T> st4(b);
#if !defined SAFEINT_VS_VERSION
	float f = 0;
	double d = 0;
	long double ld = 0;
	SafeInt<T> st5(f);
	SafeInt<T> st6(d);
	SafeInt<T> st7(ld);
#endif
}

template <typename T, typename U>
void TestModulus()
{
  SafeInt<T> st(1);
  T tmp;
  U u(1);
  tmp = st % u;
  SafeInt<T> st2(1);
  tmp = st % st2;
  tmp = u % st;
  st %= u;
  SafeInt<U> su(1);
  st = 1;
  st %= su;
}

template <typename T, typename U>
void TestMultiply()
{
  SafeInt<T> st(1);
  T tmp;
  U u(1);
  tmp = st * u;
  SafeInt<T> st2(1);
  tmp = st * st2;
  tmp = u * st;
  st *= u;
  SafeInt<U> su(1);
  st = 1;
  st *= su;
}

template <typename T, typename U>
void TestDivide()
{
  SafeInt<T> st(1);
  T tmp;
  U u(1);
  tmp = st / u;
  SafeInt<T> st2(1);
  tmp = st / st2;
  tmp = u / st;
  st /= u;
  SafeInt<U> su(1);
  st = 1;
  st /= su;
}

template <typename T, typename U>
void TestAddition()
{
  SafeInt<T> st(1);
  T tmp;
  U u(1);
  tmp = st + u;
  SafeInt<T> st2(1);
  tmp = st + st2;
  tmp = u + st;
  st += u;
  SafeInt<U> su(1);
  st = 1;
  st += su;
}

template <typename T, typename U>
void TestSubtract()
{
  SafeInt<T> st(1);
  T tmp;
  U u(1);
  tmp = st - u;
  SafeInt<T> st2(1);
  tmp = st - st2;
  tmp = u - st;
  st -= u;
  SafeInt<U> su(1);
  st = 1;
  st -= su;
}

template <typename T, typename U>
void TestCompare()
{
  T t(1);
  U u(1);
  SafeInt<T> st;
  SafeInt<U> su;

  bool b = ((st > su) && (st > u) && (u > st));
  bool b2 = ((st >= su) && (st >= u) && (u >= st));
  bool b3 = ((st < su) && (st < u) && (u < st));
  bool b4 = ((st <= su) && (st <= u) && (u <= st));
  bool b5 = ((st == su) && (st == u) && (u == st) && (b4 == st) && (st == b3));
  bool b6 = ((st != su) && (st != u) && (u != st) && (b4 != st) && (st != b3));
}

template <typename T, typename U>
void TestShift()
{
  SafeInt<T> st;
  U u(1);
  SafeInt<U> su(1);
  SafeInt<T> st2;

  st2 = st << u;
  st2 = st << su;
  st <<= u;
  st <<= su;

  st2 = st >> u;
  st2 = st >> su;
  st >>= u;
  st >>= su;
  u >>= su;
  u <<= su;
  st2 = u >> st;
  st2 = u << st;
}

template <typename T, typename U>
void TestBitwise()
{
   SafeInt<T> st;
   SafeInt<U> su;
   U u = 1;
   SafeInt<T> st2;

  // and
  st2 = st & u;
  st2 = u & st;
  st &= u;
  st &= su;
  
  // or
  st2 = st | u;
  st2 = u | st;
  st |= u;
  st |= su;


  // xor
  st2 = st ^ u;
  st2 = u ^ st;
  st ^= u;
  st ^= su;
}

template <typename T>
void TestAtoI()
{
#if !defined SAFEINT_VS_VERSION
  const char sz[3] = {'1', '2', 0};
  const wchar_t wz[3] = {'1', '2', 0};
  SafeInt<T> st;

  st = SafeInt<T>::SafeAtoI(sz);
  st = SafeInt<T>::SafeWtoI(wz);
#endif
}

template <typename T>
void TestAlign()
{
  SafeInt<T> st(1);
  st.Align2();
  st.Align4();
  st.Align8();
}

template <typename T, typename U>
void TestTopEqualSafeInt()
{
  T t(0);
  SafeInt<U> su(1);
  t += su;
  t -= su;
  t *= su;
  t /= su;
  t %= su;
  t &= su;
  t ^= su;
  t |= su;
  t <<= su;
  t >>= su;
  
  // Catch the pointer overrides here
  char buf[5];
  char* p = buf;
  p += su;
  p -= su;
}

template <typename T, typename U>
void TestCompileTU()
{
	TestConstructors<T, U>();
	TestCasts<T, U>();
	TestModulus<T, U>();
	TestMultiply<T, U>();
	TestDivide<T, U>();
	TestAddition<T, U>();
	TestSubtract<T, U>();
	TestCompare<T, U>();
	TestShift<T, U>();
	TestBitwise<T, U>();
	TestAtoI<T>();
	TestAlign<T>();
	TestTopEqualSafeInt<T, U>();
}

template <typename T>
void TestCompileIntTraits()
{
   bool fSigned = IntTraits<T>::isSigned;
   bool fis64bit = IntTraits<T>::is64Bit;
   bool fis32bit = IntTraits<T>::is32Bit;
   bool fis16bit = IntTraits<T>::is16Bit;
   bool fis8bit = IntTraits<T>::is8Bit;
   bool fisLT32Bit = IntTraits<T>::isLT32Bit;
   bool fisLT64Bit = IntTraits<T>::isLT64Bit;
   bool fisInt8 = IntTraits<T>::isInt8;
}

template <typename T>
void TestMinMax()
{
  SafeInt<T> st;
  SafeInt<T> st2 = st.Min(0);
  st2 = st.Max(0);
}

template <typename T>
void TestPtrRef()
{
  SafeInt<T> st;
  T* pt = st.Ptr();
  const T* ptc = st.Ptr();
  const T& tref = st.Ref();
#if !defined SAFEINT_VS_VERSION
  const T* ptc2 = &st;
  T* pt2 = &st;
#endif
}

template <typename T>
void TestUnary()
{
  SafeInt<T> st;
  T t = +st;
  // Note - if compiling with the option to force negation of an
  // unsigned number to fail, must comment this out as well
  t = -st;
  t = ~st;
}

template <typename T>
void TestPrefixPostfix()
{
  SafeInt<T> st;
  st++;
  st--;
  ++st;
  --st;
}

template <typename T>
void TestCompileT()
{
	TestCompileTU<T, char>();
	TestCompileTU<T, unsigned char>();
	TestCompileTU<T, signed char>();
	TestCompileTU<T, short>();
	TestCompileTU<T, unsigned short>();
	TestCompileTU<T, int>();
	TestCompileTU<T, unsigned int>();
	TestCompileTU<T, long>();
	TestCompileTU<T, unsigned long>();
	TestCompileTU<T, long long>();
	TestCompileTU<T, unsigned long long>();
	TestCompileTU<T, size_t>();
	TestCompileTU<T, ptrdiff_t>();
	TestCompileTU<T, uintptr_t>();
	TestCompileTU<T, intptr_t>();
	TestCompileIntTraits<T>();
	TestMinMax<T>();
        TestPtrRef<T>();
        TestUnary<T>();
        TestPrefixPostfix<T>();
}

void TestCompile()
{
	TestCompileT<char>();
	TestCompileT<unsigned char>();
	TestCompileT<signed char>();
	TestCompileT<short>();
	TestCompileT<unsigned short>();
	TestCompileT<int>();
	TestCompileT<unsigned int>();
	TestCompileT<long>();
	TestCompileT<unsigned long>();
	TestCompileT<long long>();
	TestCompileT<unsigned long long>();
	TestCompileT<size_t>();
	TestCompileT<ptrdiff_t>();
	TestCompileT<uintptr_t>();
	TestCompileT<intptr_t>();
}

int main(int /*argc*/, char* /*argv[]*/)
{
}
