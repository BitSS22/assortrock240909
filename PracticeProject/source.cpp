#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <random>

using std::cout;
using std::endl;

void Func(__int64 _value, ...)
{
	__int64* ptr = &_value;

	__int64 otherPtr = (__int64)ptr;

	cout << *((__int64*)otherPtr) << endl;

	for (size_t i = 0; i < 30; i++)
	{
		otherPtr += 8;

		cout << *((__int64*)otherPtr) << endl;
	}


	return;
}

struct BIG
{
public:
	__int64 i64_0 = 1;
	__int64 i64_1 = 2;
	__int64 i64_2 = 3;
	__int64 i64_3 = 4;
};

class parent
{
public:
	int a = 0;
};

class child : parent
{
public:
	int i = 0;

public:
	void test()
	{
		set();
	};
	void set() const
	{
		test();
	};
};

int main()
{
	Func(__int64(30), BIG(), __int64(30));

	child temp;
	temp.a;
	return 0;
}