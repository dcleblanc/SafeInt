// Licensed under the MIT License.
// Copyright David LeBlanc - dcl@dleblanc.net

#pragma once

#include <iostream>
#include <ios>
#include <iomanip>
#include <sstream>

enum OpType
{
	Mult,
	Div,
	Div2,
	Add,
	Sub
};

struct OpName
{
	static const char* op_name(int op) 
	{
		switch (op)
		{
		case OpType::Mult:
			return "Mult";
		case OpType::Div:
		case OpType::Div2:
			return "Div";
		case OpType::Add:
			return "Add";
		case OpType::Sub:
			return "Sub";
		default:
			return "";
		}
	};
};

template <typename T, typename U, int op>
struct TestCase
{
	const TestCase<T, U, op>& operator=(const TestCase<T, U, op>& in)
	{
		this->x = in.x;
		this->y = in.y;
		this->fExpected = in.fExpected;
		return *this;
	}

	T x;
	U y;
	bool fExpected;
};

template <typename T, typename U, int op>
class TestVector
{
public:
	TestVector();

	void Reset() { current = 0; }
	bool Done() const { return current >= count; }

	TestCase<T, U, op> GetNext()
	{
		const TestCase<T, U, op>* next = GetCase(current);
		current++;
		return *next;
	}

private:
	const TestCase<T, U, op>* GetCase(size_t i)
	{
		if (i > count - 1)
			return nullptr;

		return &test_cases[i];
	}

	const TestCase<T, U, op>* test_cases;
	size_t count;
	size_t current;
};

#if !defined(COUNTOF)
# if defined(_countof)
#  define COUNTOF(x) _countof(x)
# else
#  define COUNTOF(x) (sizeof(x)/sizeof((x)[0]))
# endif
#endif

template <typename T>
std::string to_hex(T t)
{
	std::ostringstream ostm;
	ostm << "0x" << std::setfill('0') << std::hex << std::setw(sizeof(t) <= 4 ? 8 : 16) << t;
	return ostm.str();
}

template <>
inline std::string to_hex< uint8_t >(uint8_t t)
{
	std::ostringstream ostm;
	ostm << "0x" << std::setfill('0') << std::hex << std::setw(2) << static_cast<uint16_t>(t);
	return ostm.str();
}

template <>
inline std::string to_hex< int8_t >(int8_t t)
{
	std::ostringstream ostm;
	ostm << "0x" << std::setfill('0') << std::hex << std::setw(2) << static_cast<uint16_t>(t);
	return ostm.str();
}

template <typename T, typename U>
void err_msg(const std::string& msg, T t, U u, bool expected)
{
	std::cerr << msg << to_hex(t) << ", " << to_hex(u) << ", expected = " << expected << std::endl;
}

template <typename T>
void err_msg(const std::string& msg, T t, bool expected)
{
	std::cerr << msg << to_hex(t) << ", expected = " << expected << std::endl;
}

class trace 
{
public:

	trace(bool f = false) : enable(f){}

	void trace_msg(const std::string& msg)
	{
		if(enable)
			std::cout << msg << std::endl;
	}

	void trace_msg(const char* msg)
	{
		if(enable)
			trace_msg(std::string(msg));
	}

	bool enable;
};

