Licensed under the MIT License.
Copyright David LeBlanc - dcl@dleblanc.net

# SafeInt Documentation
SafeInt is an integer overflow library that was originally created in Microsoft Office in 2003, and later was made open source on CodePlex using the MS-PL license. After CodePlex was deprecated, the project was moved to GitHub and is located at https://github.com/dcleblanc/SafeInt. The original code from CodePlex is located in the Archive folder. After moving the code to GitHub, the license was changed to the MIT license.

There is also now a C library based on the same code - safe_math.h. It has two sets of functions for each operation and pair of supported types - check_, and safe_ - the check versions return a bool to indicate whether the function succeeded, and the safe versions just abort if it did not. The failure function can be replaced, as is seen in the test harness.

The author is David LeBlanc (dcl@dleblanc.net), portions of the test harness have come from other contributors. Code written while employed by Microsoft is copyright Microsoft, code written by the author after leaving Microsoft is copyright David LeBlanc. Code written by other contributors may have copyright to that author or their organization.

## Overview
## Supported Compilers
SafeInt is fully supported on the Microsoft Visual Studio compiler (cl.exe), gcc and clang. It has been tested previously with the Intel reference compiler, and should still work. If issues are encountered with other compilers, please file an issue and these will be fixed on a best effort basis.

A best effort has been made to maintain backward compatibility with older versions of the above compilers, but have not been tested on these recently. If the compiler version is still supported and there is a problem, file an issue on GitHub.

### Compiler Features
Support for constexpr varies with compiler, version of compiler, and the version of the C++ standard used. The constexpr feature can result in far smaller code when some or all of the arguments are compile time constants. The library will determine the highest supported version, and use that. This feature is minimally supported in the C++11 standard, and is improved in the C++14 standard.
### Supported C++ Versions
This library was originally developed under a compiler which only supported the C++98 standard and should theoretically still compile under some very old compilers, assuming that template support was sufficient. Some of the compilers used circa 2003 didn't have enough template support, but hopefully you're not compiling your code with antique unsupported compilers.

Note that compilation with C++ versions higher than C++17 are not currently part of the test suite, but shouldn't cause issues. If problems do occur when compiling with more recent C++ versions, please file an issue on GitHub.

### Disabling Exceptions
Some environments do not support exceptions. The library will attempt to detect whether exceptions are enabled and if not enabled, will by default use the InvalidParameterExceptionHandler. The InvalidParameterExceptionHandler calls __failfast when compiled with the Microsoft Visual Studio Compiler, and calls abort() otherwise. If you would prefer some other mechanism, see User-supplied Exceptions.

### User-supplied Exceptions
Replacing the exception handler is a common customization. Many teams have their own well-developed exception classes and would like to use that infrastructure with SafeInt. For example, if you wanted std::runtime_error instead of SafeIntException, create a wrapper header with the following code:

    class my_safeint_exception
    {
    public:
        static __declspec(noreturn) void __stdcall SafeIntOnOverflow()
        {
            throw std::runtime_error("SafeInt overflow");
        }

        static __declspec(noreturn) void __stdcall SafeIntOnDivZero()
        {
            throw std::runtime_error("SafeInt div 0");
        }
    };
    
    #define SafeIntDefaultExceptionHandler my_safeint_exception
    #include "SafeInt.hpp"

Note: gcc and clang may not need the stdcall decoration, and noreturn is designated by an attribute, like so:
    `__attribute__((noreturn))`

## SafeInt
### Constructors
Constructors have the following signatures:

    SafeInt()
    SafeInt( const T& i )
    SafeInt( bool b )
    SafeInt(const SafeInt< U, E >& u)
    SafeInt( const U& i )

The default constructor initializes the internal integer type to 0. Initializing a SafeInt\<T\> with an integer of the same type is a non-throwing operation, and is not checked. Initialization from a bool will convert false to 0, and true to 1. Initialization from another type will be range checked. It is also possible to initialize a SafeInt from a floating point type:

    float f = 1.0;
    SafeInt<unsigned int> s(f);

While it is possible to initialize a SafeInt object from a boolean, it is not allowed to declare a SafeInt\<bool\>.

### Assignment Operators
Assignment operators have the following signatures:

    SafeInt< T, E >& operator =( const U& rhs )
    SafeInt< T, E >& operator =( const T& rhs )
    SafeInt< T, E >& operator =( const SafeInt< U, E >& rhs )
    SafeInt< T, E >& operator =( const SafeInt< T, E >& rhs )

Assignment operators of the same type are non-throwing and are not checked. Assignment operators of a different type will be range checked.

### Casting Operators
Casting operators play an important role when a SafeInt object is passed into a function as an argument. The SafeInt will be cast to the type required by the function, and in the process of evaluating the cast, will be range checked. Integer casting operators have the following signatures:

    operator bool()
    operator char()
    operator signed char()
    operator unsigned char()
    operator short()
    operator unsigned short()
    operator int()
    operator unsigned int()
    operator long()
    operator unsigned long()
    operator long long()
    operator unsigned long long()

No assumptions are made about the sizes of each of these types, and will be checked properly even if the type's size varies across compilers or target architecture.

Note:
An operator size_t() can be enabled by defining SIZE_T_CAST_NEEDED. Older compilers sometimes needed this operator.

In addition to casting to integer types, casts are also available to cast to floating point types:

    operator float()
    operator double()
    operator long double()

### Unary Operators
#### Negation
The + operator is defined as follows, but effectively does nothing:

    const SafeInt< T, E >& operator +()

The - operator is defined as follows:

    SafeInt< T, E > operator -()

Negating an unsigned integer will perform the same bitwise manipulation as it does on a signed integer - (~x + 1), but this will rarely be what you meant to have happen. In the case of unsigned types smaller than an integer, negation results in the following standard behavior (explicit cast shown to illustrate operator cast):

    unsigned short s = 1;
    int x = -(int)s;

This class retains the type, and then truncates, which is not likely to be a desired behavior. If you want normal casting behavior, the following code will achieve that:

    SafeInt<unsigned short> ss = 0xffff;
    SafeInt<int> = -(SafeInt<int>(ss));

You will now have the correct value and bitfield. Because negating an unsigned type is unlikely to be correct, it can be prevented by setting this define:

    #define SAFEINT_DISALLOW_UNSIGNED_NEGATION 1

#### Prefix and Postfix Increment
Prefix and postfix increment and decrement operators have the following signatures:

    SafeInt< T, E >& operator ++()
    SafeInt< T, E >& operator --()
    SafeInt< T, E > operator ++( int )
    SafeInt< T, E > operator --( int )

Note: Dummy int argument designates to the compiler that this is a postfix operator.

### Supported Operators
#### Addition
Addition operators have the following signatures:

    SafeInt< T, E > operator +( SafeInt< T, E > rhs )
    SafeInt< T, E > operator +( U rhs )
    SafeInt< T, E >& operator +=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator +=( U rhs )
    SafeInt< T, E >& operator +=( SafeInt< U, E > rhs )

There is also an operator defined for the case where we have the SafeInt class on the right of the + operator:

    SafeInt< T, E > operator +( U lhs, SafeInt< T, E > rhs )

Another case which is provided for is where we have the following:

    SafeInt<int> x(2);
    int y(3) += x;

This operator has the following signature:

    T& operator +=( T& lhs, SafeInt< U, E > rhs )

#### Subtraction
Subtraction operators have the following signatures:

    SafeInt< T, E > operator -( SafeInt< T, E > rhs )
    SafeInt< T, E > operator -( U rhs )
    SafeInt< T, E >& operator -=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator -=( U rhs )
    SafeInt< T, E >& operator -=( SafeInt< U, E > rhs )

There is also an operator defined for the case where we have the SafeInt class on the right of the - operator:

    SafeInt< T, E > operator -( U lhs, SafeInt< T, E > rhs )

Another case which is provided for is where we have the following:

    SafeInt<int> x(2);
    int y(3) -= x;

This operator has the following signature:

    T& operator -=( T& lhs, SafeInt< U, E > rhs )

#### Multiplication
Multiplication operators have the following signatures:

    SafeInt< T, E > operator *( SafeInt< T, E > rhs )
    SafeInt< T, E > operator *( U rhs )
    SafeInt< T, E >& operator *=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator *=( U rhs )
    SafeInt< T, E >& operator *=( SafeInt< U, E > rhs )

There is also an operator defined for the case where we have the SafeInt class on the right of the * operator:

    SafeInt< T, E > operator *( U lhs, SafeInt< T, E > rhs )

Another case which is provided for is where we have the following:

    SafeInt<int> x(2);
    int y(3) *= x;

This operator has the following signature:

    T& operator *=( T& lhs, SafeInt< U, E > rhs )

#### Division
Division operators have the following signatures:

    SafeInt< T, E > operator /( SafeInt< T, E > rhs )
    SafeInt< T, E > operator /( U rhs )
    SafeInt< T, E >& operator /=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator /=( U rhs )
    SafeInt< T, E >& operator /=( SafeInt< U, E > rhs )

There is also an operator defined for the case where we have the SafeInt class on the right of the / operator:

    SafeInt< T, E > operator /( U lhs, SafeInt< T, E > rhs )

Another case which is provided for is where we have the following:

    SafeInt<int> x(2);
    int y(3) /= x;

This operator has the following signature:

    T& operator /=( T& lhs, SafeInt< U, E > rhs )

#### Modulus

Modulus operators have the following signatures:

    SafeInt< T, E > operator %( SafeInt< T, E > rhs )
    SafeInt< T, E > operator %( U rhs )
    SafeInt< T, E >& operator %=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator %=( U rhs )
    SafeInt< T, E >& operator %=( SafeInt< U, E > rhs )

There is also an operator defined for the case where we have the SafeInt class on the right of the % operator:

    SafeInt< T, E > operator %( U lhs, SafeInt< T, E > rhs )

Note: In the modulus case, this may not be ideal behavior, and you might want to force this such that the left hand operand is the SafeInt type, like so:

    int x = fcn();
    SafeInt<unsigned int> y = fcn2();

    SafeInt<int> z = SafeInt<int>(x) % (unsigned int)y;

This method is only provided for completeness, you should evaluate what type you need.

Another case which is provided for is where we have the following:

    SafeInt<int> x(2);
    int y(3) %= x;

This operator has the following signature:

    T& operator %=( T& lhs, SafeInt< U, E > rhs )

#### Binary Operators
The one's complement binary operator is defined as:

    SafeInt< T, E > operator ~()

The remaining binary operators, &, |, and ^ are all supported with the following signatures:

    SafeInt< T, E > operator &( SafeInt< T, E > rhs )
    SafeInt< T, E > operator &( U rhs )
    SafeInt< T, E >& operator &=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator &=( U rhs )
    SafeInt< T, E >& operator &=( SafeInt< U, E > rhs )
    T& operator &=( T& lhs, SafeInt< U, E > rhs )
    SafeInt< T, E > operator &( U lhs, SafeInt< T, E > rhs )

    SafeInt< T, E > operator ^( SafeInt< T, E > rhs )
    SafeInt< T, E > operator ^( U rhs )
    SafeInt< T, E >& operator ^=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator ^=( U rhs )
    SafeInt< T, E >& operator ^=( SafeInt< U, E > rhs )
    T& operator ^=( T& lhs, SafeInt< U, E > rhs )
    SafeInt< T, E > operator ^( U lhs, SafeInt< T, E > rhs )

    SafeInt< T, E > operator |( SafeInt< T, E > rhs )
    SafeInt< T, E > operator |( U rhs )
    SafeInt< T, E >& operator |=( SafeInt< T, E > rhs )
    SafeInt< T, E >& operator |=( U rhs )
    SafeInt< T, E >& operator |=( SafeInt< U, E > rhs )
    T& operator |=( T& lhs, SafeInt< U, E > rhs )
    SafeInt< T, E > operator |( U lhs, SafeInt< T, E > rhs )

Note:
Binary operators are very tricky when dealing with mixed types. SafeInt doesn't do anything special with these, and you might get results that you don't entirely expect. For example, consider the following code:

    char x = fcn();
    char mask = 0x80;
    if ( x & mask == 0x80 ) // note - '0x80' is an int
        Do Something();

A literal numeric value is by default an int, and if you are using integer types smaller than an int, the operator will cast the operands to int first. After appling the casts, the code now looks like this (after inlining the mask variable):

    char x = fcn();
    if ( x & 0xffffff80 == 0x00000080 )
        Do Something();

If x is positive, the if statement evaluates to false, as one would expect. If x is negative, then upon casting to an int, it will sign extend, the result will be 0xffffff80, and the if statement also evaluates to false, which is likely unexpected. 

If your code has mixed types and binary operators, spend some time evaluating what the code really does, and what you'd like it to do. For best results, don't do binary operations on mixed length types.

#### Shift Operators

The shift operators have the following signatures:

    SafeInt< T, E > operator <<( U bits )
    SafeInt< T, E > operator <<( SafeInt< U, E > bits )
    SafeInt< T, E >& operator <<=( U bits )
    SafeInt< T, E >& operator <<=( SafeInt< U, E > bits )
    T& operator <<=( T& lhs, SafeInt< U, E > rhs )
    SafeInt< U, E > operator <<( U lhs, SafeInt< T, E > bits )

    SafeInt< T, E > operator >>( U bits )
    SafeInt< T, E > operator >>( SafeInt< U, E > bits )
    SafeInt< T, E >& operator >>=( U bits )
    SafeInt< T, E >& operator >>=( SafeInt< U, E > bits )
    T& operator >>=( T& lhs, SafeInt< U, E > rhs )
    SafeInt< U, E > operator >>( U lhs, SafeInt< T, E > bits )

Note:
Shift operations where the right argument is larger than the number of bits in the left argument type minus 1 is implementation-defined behavior. SafeInt will attempt to help you avoid this by causing an assert in debug builds. If you prefer to have a stronger reaction, create a custom SAFEINT_ASSERT that throws or causes a fault in both debug and release builds. Shifting by a negative bit count also doesn't make sense, and is also trapped.

### Methods
SafeInt has a a small number of methods that help with common problems, such as aligning a value, getting a pointer to the raw integer type, and helping to manage pointer arithmetic.

#### Align
Aligning integer values to a power of two can be tricky and can be poorly optimized. Most typical implementations will overflow to zero. The SafeInt Align method has the following signature:

    template < alignBits bits > const SafeInt< T, E >& Align()

Where the alignBits argument is one of the following enum values:

    enum alignBits
    {
        align2 = 1,
        align4 = 2,
        align8 = 3,
        align16 = 4,
        align32 = 5,
        align64 = 6,
        align128 = 7,
        align256 = 8
    };

Specialized methods exist for the following common values:

    Align2()
    Align4()
    Align8()
    Align16()
    Align32()
    Align64() 

Note: The following constraints apply to Align:
 - Aligning to more bits than are available is implementation-defined behavior, and not supported by this library
 - Aligning a signed number to more than the number of bits - 1 is also not supported, for example aligning a signed char to 128.
 - Aligning a negative number is not currently supported.
 - Aligning to zero or negative bits doesn't make any sense, and isn't supported.

#### Pointer to Encapsulated Integer
Many functions have arguments that take pointers to an integer. SafeInt provides the following methods to obtain a raw pointer to the underlying integer:

    T* data_ptr()
    const T* data_ptr()

SafeInt originally supported this function using these methods:

    T* Ptr()
    const T* Ptr()

The latter is maintained only for backwards compatibility purposes, and may be removed in a future release.

Both of these methods allow the internal intger type to be changed in an unsafe manner.

There is also an overload for:

    T* operator &()

This means that it is not possible to get a SafeInt\<T\>* type, and overloading operator& was not a good design decision. It has been left enabled in case it is used by someone. If you prefer not to allow this in your code base, then set the following prior to including SafeInt.hpp:

    #define SAFEINT_DISABLE_ADDRESS_OPERATOR 1

#### Safe atoi
The standard library implementation of atoi often suffers from internal integer overflows. This version does not overflow, and supports both single-byte and wchar_t input strings. The signatures are:

    static SafeInt< T, E > SafeAtoI( const char* input )
    static SafeInt< T, E > SafeWtoI( const wchar_t* input )

#### Min, Max
The Min and Max methods have the following signature:

    SafeInt< T, E > Min( SafeInt< T, E > test, const T floor = std::numeric_limits<T>::min() )
    SafeInt< T, E > Max( SafeInt< T, E > test, const T upper = std::numeric_limits<T>::max() )

These methods return the minimum or maximum of either the internal m_int, the test argument, and the floor or upper limits, as applicable.
#### Swap
The Swap method has the following signature:

    void Swap( SafeInt< T, E >& with )

This method exchanges the internal integer value with the supplied argument.
### Helper Functions
The following friend functions help with useful tasks, such as converting pointer difference to a SafeInt, safe pointer arithmetic, and comparison operators.
#### SafePtrDiff
This method is helpful in converting the difference between two pointers to a SafeInt<ptrdiff_t>, which then ensures that further arithmetic operations on the result are checked. The friend method has the following signature:

    SafeInt<ptrdiff_t, SafeIntDefaultExceptionHandler> SafePtrDiff(const P* p1, const P* p2)

#### Comparison Operators
Friend methods exist for each of the six comparison operators for the case where an integer type is on the left hand side of the operator, for example:

    int x = fcn();
    SafeInt<unsigned long> y = fcn2();

    if( x <= y)
        DoSomething();

One method signature is as follows:

    bool operator <( U lhs, SafeInt< T, E > rhs )

Note:
Overloads exists specifically for cases where the base type is a bool, and the operators are == or !=.

#### Pointer Arithmetic
Pointer arithmetic is difficult because the count of elements is multiplied by the size of the object represented by the pointer, and this multiplication could overflow. Once the offset has been converted into a count of bytes, the addition can then overflow. The pointer arithmetic methods have the following signatures:

    T*& operator +=( T*& lhs, SafeInt< U, E > rhs )
    T*& operator -=( T*& lhs, SafeInt< U, E > rhs )

## Configuration Options
Alternative compilers that do not emulate any of the supported compilers (Microsoft Visual Studio, clang, or gcc) may be supported, but you will need to modify the feature detection code to work with your compiler.

Defines are:

CONSTEXPR_SUPPORT - define this to force support for constexpr to your needed value. Should not be needed unless you have an unknown compiler.

SAFE_INT_HAS_EXCEPTIONS - the class should detect whether exceptions are enabled, but in case it does not (or for testing), this can be set.

SAFEINT_REMOVE_NOTHROW - the noexcept attribute behavior varies across compilers. On the Visual Studio compiler, it is a silent warning. Other compilers may turn noexcept violations into exceptions at runtime. Setting this to 1 removes the attribute for the class.

SAFEINT_HAS_INT128, SAFEINT_USE_INTRINSICS - SafeInt has four approaches to 64-bit multiplication - upcast to int128, intrinsics on the Visual Studio compiler with x64 code, builtin functions on gcc and clang, and if all else fails, just do the math. If you would like to force an approach to this, these defines will allow you to that.

SAFEINT_ASSERT - SafeInt will assert various cases that might represent either implementation-dependent or behavior that should get inspected. The default is to use assert(), but you may replace this if your code base has a different set of assert functions.

SAFEINT_ASSERT_ON_EXCEPTION - defining this will cause an assert to be called before an exception is thrown, which may make issues easier to debug.

SafeIntDefaultExceptionHandler - see User Supplied Exceptions. This allows you to use the exception type you prefer.

SAFEINT_DISALLOW_UNSIGNED_NEGATION - attempting to negate an unsigned number seems like a mistake. If you would like to make it a compiler error, define this.

SAFEINT_DISABLE_BINARY_ASSERT - Binary operations on mixed types or types smaller than int can create unexpected behaviors. This assert attempts to find these behaviors so that you can inspect the code and ensure it really does what you want. See further documentation in Binary Operators. If you'd like to disable these asserts, defining this will allow that.

SIZE_T_CAST_NEEDED - some very old compilers need a specific cast for cases where a SafeInt is cast to size_t. Other compilers will complain if you do have one. If you happen to need `operator size_t()` implemented, define this value.

SAFEINT_DISABLE_ADDRESS_OPERATOR - there is a `T* operator &()` defined, which returns a pointer to the underlying integer. This likely isn't a good idea, and doesn't comply with modern C++ style. It also prevents being able to get a SafeInt\<T\>*. If it offends you, and you'd like to make it go away, define this value.

## Using SafeInt with std::unordered_set and std::unordered_map

To use the SafeInt class with the std::unordered_set and std::unordered_map, an easy work-around would be to simply extract the value, and make our declaration as follows:

```
SafeInt<uint64_t> s;
std::unordered_set<uint64_t> uset {(uint64_t)s};
```

This is a little inconvenient, we'd have to be careful to reconstruct a SafeInt when obtaining the value.

What is a nicer approach is to create a specialization for std::hash:

```
template<typename T>
struct std::hash< SafeInt<T> >
{
    std::size_t operator()(const SafeInt<T>& s) const
    {
        return std::hash<T>()(static_cast<const T>(s));
    }
};
```
## Examples
SafeInt is designed to be a drop-in replacement for any integer type, and because it is "sticky" and most operations on a SafeInt and other integer type will emit a temporary SafeInt, many cases can be solved merely by changing:

    int x = fcn();

to

    SafeInt<int> x = fcn();

Further operations on variable x will be checked. 

### Variable length structure allocation
Consider the case where we have a variable length structure, and a user-supplied count of objects, and then wish to calculate the space needed. We might have code like the following:

```
    struct foo
    {
        unsigned int version;
        unsigned int count;
        short data[];
    };

    foo* alloc_foo(int count)
    {
        size_t cb = sizeof(short) * (count - 1) + sizeof(foo);
        return (foo*)malloc(cb);
    }
```
This code can be made safe simply by taking advantage of operator precedence:
```
    foo* alloc_foo(int count)
    {
        size_t cb = SafeInt<size_t>(sizeof(short)) * (count - 1) + sizeof(foo);
        return (foo*)malloc(cb);
    }
```
Here's what happens, step by step:
1) A `SafeInt<size_t>` is initialized with `sizeof(char)`, this is safe.
2) Multiplication is performed with (count - 1). Note that if count is not positive, the resulting temporary `SafeInt<size_t>` (which is unsigned) will throw because it cannot represent a negative number. If the multiplication were to overflow, this would also be checked.
3) The addition is performed and is checked, resulting in a temporary variable of type `SafeInt<size_t>`.
4) Assignment to cb is validated, in this case being a no-op because the types are the same.

Let's consider some alternatives - if we'd done this instead:

        size_t cb = sizeof(short) * (SafeInt<int>(count) - 1) + sizeof(foo);

We get the following:
1) The subtraction is checked - if count were INT_MIN, this would throw
2) Multiplication would be performed between the SafeInt<int> from the previous step and sizeof(short). The result could be negative, but a multiplication overflow would be prevented.
3) The addition would then be checked for overflow.
4) Assigning an int to a size_t causes a check for a negative value.

There's still a problem, which is that if count were zero, we'd try to allocate sizeof(foo)-2, which might not be enough. Even worse, if count were -3, the overall result would be zero, and we'd allocate a zero-length buffer, which is a typical exploit pattern. This depends on how the code treats the structure, some code might treat it as not having a data member. A better fix would might be:

        size_t cb = sizeof(short) * (SafeInt<size_t>(count) - 1) + sizeof(foo);

This would then prevent count \< 1 from being valid. Both approaches work, but have subtle differences, depending on whether count == 0 is considered valid.

Another approach is:

        size_t cb = sizeof(short) * (count - 1) + SafeInt<size_t>(sizeof(foo));

This is not correct, because the multiplication isn't checked, only the addition and assignment.

### Array index
Choice of type to use can have some interesting considerations. Let's look at the following code:
```
    char buffer[0x4000];
    int offset = fcn1();
    int advance = fcn2();

    char test = buffer[offset + advance];
```
This is clearly dangerous, depending on the values of offset and advance, we could be accessing memory well outside the buffer in both directions. It's sometimes good to use the same types as the compiler would, and the accessing an array takes a ptrdiff_t as an argument (32-bit or 64-bit signed). Consider this fix:

    char test = buffer[SafeInt<ptrdiff_t>(offset) + advance];

The addition is now checked, but if you're compiling for x64, ptrdiff_t is an int64_t, which can't overflow. Let's try again:

    char test = buffer[SafeInt<size_t>(offset) + advance];

This at least won't access memory before the buffer, but might go well beyond the buffer. A better fix would be:
```
    size_t index = SafeInt<size_t>(offset) + advance;
    char test = index < sizeof(buffer) ? buffer[index] : '\0';
```
Alternately, if offset and advance shouldn't be negative, and you'd like to throw if index is invalid, this works:
```
    SafeInt<size_t> index = SafeInt<size_t>(offset) + SafeInt<size_t>(advance);
    index = index < sizeof(buffer) ? index : -1; // force an exception
    char test = buffer[index];
```
### Counter-examples
It should go without saying, but this has been seen in code and doesn't check the addition:

    SafeInt<int> x(a+b);

A common (but untidy) thing a developer might do is to put the following in a header:

    #define BAD_ERROR -1

They then write a long function along these lines:
```
    unsigned long retval = 0;
    // many lines of code follow, we do math on retval
    // Check for errors
    if(SomethingBad())
        retval = BAD_ERROR;

    // Do some cleanup
    return retval;
```
You're worried about the math, so you just change retval to a `SafeInt<unsigned long>`, and don't notice that BAD_ERROR is a negative int. Now you've just changed the behavior of the function from having a legitimate handled error path to throwing an exception if SomethingBad() returns true. 

When you replace a base integer type with a SafeInt, be sure to review all the code that touches it. This could easily be fixed by changing the define to:

    #define BAD_ERROR ((unsigned long)-1) // or ULONG_MAX is cleaner

Here's a tricky variant on the same problem - code at the bottom of the function might be:

    return SomethingBad() ? BAD_ERROR : retval;

The ternary operator wants both values on each side of the ':' to be the same type. What it will do is try to construct a SafeInt\<unsigned long\>(BAD_ERROR), which then throws, and the line of code effectively becomes:

    return SomethingBad() ? throw SafeIntException() : retval;

This example is less of a problem, but will cause a performance degredation:
```
    const unsigned long foo_max = 0x4000;

    for(int i = 0; i < foo_max; ++i)
    {
        DoStuff(i);
    }
```
The compiler tells you that there's a signed/unsigned mis-match, and you've found that SafeInt is good at making warnings go away, so you do this:

    for(SafeInt<int> i = 0; i < foo_max; ++i)

The first problem is that this doesn't help anything, the code will never throw - there's no possibility of an integer overflow. Though the SafeInt class will check itself every time it goes through the loop to see if an overflow happened. It won't be a very expensive mistake, but it is a mistake. Just change the type to match foo_max.

Another potential way to make a mistake by using SafeInt would be if two lines of code needed to complete atomically, and one of them now throws. 

## Non-throwing functions
Non-throwing functions are provided for cases where an overflow might not be unusual, or for cases where the error path an exception would take isn't clear. Caller is responsible for checking the return. In the cases where a result is returned by a T&, if the return value of the function is false, then the value placed in the result is undefined, and may vary with code path.

These functions all have the signature of:

    bool Safe*Operator*( const T t, const U u ) - comparison operators
    bool Safe*Operator*( T t, U u, T& result )  - binary operators
    bool SafeNegation(T t, T& result)           - negation
    bool SafeCast( const T From, U& To )        - casting

Supported comparison operators are:
 - SafeEquals
 - SafeNotEquals
 - SafeGreaterThan
 - SafeGreaterThanEquals
 - SafeLessThan
 - SafeLessThanEquals

Supported binary operations are: 
 - SafeModulus
 - SafeMultiply
 - SafeDivide
 - SafeAdd
 - SafeSubtract


## safe_math C library
The safe_math library is a recent addition to SafeInt, and leverages much of the code within SafeInt to check integer operations. An important benefit from re-use of SafeInt code is that 64-bit multiplication uses the most efficient approach, whether that's 128-bit integers, builtin functions, or intrinsics. As a fallback there's also just doing the math. While the effect isn't as dramatic, other operations also benefit from performance improvements SafeInt offers.

A drawback to many integer overflow libraries for C is that they do not support mixed types. Unfortunately, mixed types happen often in everyday code, and the programmer is expected to understand casting behavior in order to use the library correctly. The safe_math library provides for the following types:

    uint64_t
    int64_t
    uint32_t
    int32_t

When combined, there's 16 functions for each of addition, subtraction, multiplication, and division. Casting checks do cover all types. In addition to providing for fixed-width types, the standard types of signed and unsigned int, long, and long long are also given wrappers. This is particularly useful for the long type, which varies in size by both architecture and platform. There are currently no wrappers for size_t or ptrdiff_t, but these can be added in an update if requested.

Each operation and type combination has two signatures:

    int32_t safe_add_int32_int32(int32_t a, int32_t b)
    bool check_add_int32_int32(int32_t a, int32_t b, int32_t* ret)

The safe_ will call abort (or your replacement) if the operation would overflow, and the check_ version just returns false if the operation would overflow.

Note: Do _not_ depend on the value placed in ret if the function returns false. Depending on the code flow, it might be the result of an overflow, or might be not set.

Note: An oddity of the C (and C++) standard is that the only guaranteed size type is char, which is 1 byte, and otherwise only guarantees that sizeof(char) \<= sizeof(short) \<= sizeof(int) \<= sizeof(long) \<= sizeof(long long). It would be within the standard to have all of these be 1 byte. SafeInt will sort out these issues and do the right thing. The safe_math library makes some assumptions in order to keep the code readable, which is that a short is 16-bit, an int is 32-bit, and a long long is 64-bit. In accordance with the most recent C standards, two's complement negative numbers are also assumed.

