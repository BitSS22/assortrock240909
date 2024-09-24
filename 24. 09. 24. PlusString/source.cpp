#include <iostream>
#include <assert.h>

int GetStringLen(const char* const _str)
{
    int count = 0;
    while (_str[count])
        ++count;
    
    return count;
}

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    int str1Len = GetStringLen(_Value0);
    int str2Len = GetStringLen(_Value1);

    if (str1Len + str2Len + 1 > _BufferSize)
        assert(nullptr);

    int count = 0;

    while (count < str1Len)
    {
        _Buffer[count] = _Value0[count];
        ++count;
    }

    while (count < str1Len + str2Len)
    {
        _Buffer[count] = _Value1[count - str1Len];
        ++count;
    }

    _Buffer[str1Len + str2Len] = 0;
}

int main()
{
    char Arr[100] = "182396247856234234234923849231245235";

    PlusString(Arr, 100, "AAAA", "BBBB");
    std::cout << Arr << std::endl;

    PlusString(Arr, 3, "A", "B");
    std::cout << Arr << std::endl;

    PlusString(Arr, 60, "HELLO ", "WORLD");
    std::cout << Arr << std::endl;

    PlusString(Arr, 12, "HELLO ", "WORLD");
    std::cout << Arr << std::endl;

    PlusString(Arr, 50, "ABCDEFGHIJKLMNOPQR", "STUVWXYZ 알파벳");
    std::cout << Arr << std::endl;

    // 예외 처리 테스트
    // PlusString(Arr, 11, "HELLO ", "WORLD");
    // std::cout << Arr << std::endl;

    return 0;
}