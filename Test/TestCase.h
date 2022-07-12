#pragma once

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

