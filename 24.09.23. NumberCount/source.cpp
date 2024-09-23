#include <iostream>
#include <assert.h>

// 음수 안함
// 0 이외의 양수의 자릿수를 세자.
int NumberCount(int _Value)
{
    if (!_Value)
        return 1;

    int Result = 0;

    while (_Value)
    {
        _Value /= 10;
        ++Result;
    }

    return Result;
}

// 해도 되고 안해도 됩니다.
// 내 기준으로 지금
// _Value 를 넣어주면 Buffer에 
// 숫자를 문자열로 만드는 함수.
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int count = NumberCount(_Value);

    if (2 > BufferSize || count + 1 > BufferSize)
        assert(nullptr);

    Buffer[count] = 0;

    //if (0 == _Value)
    //{
    //    Buffer[0] = '0';
    //    Buffer[1] = 0;
    //    return;
    //}

    while (count)
    {
        --count;
        Buffer[count] = _Value % 10 + '0';
        _Value /= 10;
    }

    return;
}

void Test(int temp, ...)
{
    __int64 adress = (__int64)&temp;

    for (size_t i = 0; i < 100; i += 8)
    {
        std::cout << *((int*)(adress + i)) << std::endl;
    }

    return;
}

struct BIG
{
    int a = 2;
    int b = 3;
    int c = 4;
    int d = 5;
};
int main()
{
    // 5
    int Result0 = NumberCount(12358);
    // 4
    int Result1 = NumberCount(5258);
    // 7
    int Result2 = NumberCount(5258111);

    // 0은 영

    char Buffer[100] = "12373982463247912312412332122157878";

    NumberToString(Buffer, 100, 3000);
    NumberToString(Buffer, 100, 0);
    NumberToString(Buffer, 100, 52342341);
    NumberToString(Buffer, 5, 3712);
    // NumberToString(Buffer, 4, 7345);
    // NumberToString(Buffer, 1, 0);

    int size = sizeof(long double);

    Test(1, BIG(), 6, 7, 8);

    return 0;
}
