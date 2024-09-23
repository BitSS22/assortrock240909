#include <iostream>
#include <assert.h>

// ���� ����
// 0 �̿��� ����� �ڸ����� ����.
int NumberCount(int _Value)
{
    int Result = 0;

    while (_Value)
    {
        _Value /= 10;
        ++Result;
    }

    return Result;
}

// �ص� �ǰ� ���ص� �˴ϴ�.
// �� �������� ����
// _Value �� �־��ָ� Buffer�� 
// ���ڸ� ���ڿ��� ����� �Լ�.
void NumberToString(char* Buffer, int BufferSize, int _Value)
{
    int count = NumberCount(_Value);

    if (2 > BufferSize|| count + 1 > BufferSize)
        assert(nullptr);

    Buffer[count] = 0;

    if (0 == _Value)
    {
        Buffer[0] = '0';
        Buffer[1] = 0;
        return;
    }

    while (count)
    {
        --count;
        Buffer[count] = _Value % 10 + '0';
        _Value /= 10;
    }

    return;
}

int main()
{
    // 5
    int Result0 = NumberCount(12358);
    // 4
    int Result1 = NumberCount(5258);
    // 7
    int Result2 = NumberCount(5258111);

    // 0�� ��

    char Buffer[100] = {3,45,1,23,52,5,4,6,23,4,4,25,3,4,4};

    NumberToString(Buffer, 100, 3000);
    NumberToString(Buffer, 100, 0);
    NumberToString(Buffer, 100, 52342341);
    NumberToString(Buffer, 5, 3712);
    // NumberToString(Buffer, 4, 7345);
    NumberToString(Buffer, 1, 0);


    return 0;
}
