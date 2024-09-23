// 000_StringCount.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 지금만들라고 하는 함수들은
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
    Count = strlen("한글자");

    Count = StringCount("BBBB");
    Count = StringCount("cccjd");
    Count = StringCount("한글자");

    int a = 0;

    return 0;
}
