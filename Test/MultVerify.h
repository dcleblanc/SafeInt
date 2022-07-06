
namespace mult_verify
{
	template <typename T, typename U>
	struct MultTest
	{
		const MultTest<T, U>& operator=(const MultTest<T, U>& in)
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

	template <typename T, typename U>
	class MultTestCase
	{
	public:
		MultTestCase();

		void Reset() { current = 0; }
		bool Done() const { return current >= count; }

		MultTest<T, U> GetNext()
		{
			const MultTest<T, U>* next = GetCase(current);
			current++;
			return *next;
		}

	private:
		const MultTest<T, U>* GetCase(size_t i)
		{
			if (i > count - 1)
				return nullptr;

			return &test_cases[i];
		}

		const MultTest<T, U>* test_cases;
		size_t count;
		size_t current;
	};

}