#include <iostream>
#include <assert.h>

const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    int nameSize = strlen(_Name);
    if (_BufferSize < nameSize + 1)
        assert(nullptr);

    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s", _Name);
    printf_s(" Status ");

    int size = LINECOUNT - strlen(_Name) - strlen(" Status ");

    for (int i = 0; i < size; i++)
        printf_s("-");

    printf_s("\n");

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
        printf_s("-");

    printf_s("\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

int main()
{
    CreatePlayer("TestPlaye", 10, 100);
    CreateMonster("Orc", 10, 50);

    PlayerStatusRender();
    MonsterStatusRender();

    CreatePlayer("23534624", 10, 100);
    PlayerStatusRender();
    CreatePlayer("erff", 10, 100);
    PlayerStatusRender();
    CreatePlayer("r", 10, 100);
    PlayerStatusRender();
    CreatePlayer("jkfdslhnv", 10, 100);
    PlayerStatusRender();
    CreatePlayer("gwe", 10, 100);
    PlayerStatusRender();
    CreatePlayer("123456789012345678901234567890123456789", 10, 100);
    PlayerStatusRender();

    MonsterStatusRender();

    return 0;
}

