// 000_StringCount.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>

// ���ݸ����� �ϴ� �Լ�����
// strlen

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
        ++Count;

    return Count;
}

int main()
{
    // [B][B][B][B][0]
    int Count = 0;

    Count = strlen("BBBB");
    Count = strlen("cccjd");
    Count = strlen("�ѱ���");

    Count = StringCount("BBBB");
    Count = StringCount("cccjd");
    Count = StringCount("�ѱ���");

    int a = 0;

    return 0;
}
