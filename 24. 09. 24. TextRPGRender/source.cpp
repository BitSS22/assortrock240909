// TextRpg000.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// �������� 
// ��� �������� ������ ��ǻ�� ����� ���� ���´�.
// ���¿� 
int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

// ���� �߿���
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C��Ÿ�� ���� ���� �����ִ� �Լ�
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

// �Լ��� �׳� �ڱⰡ ����� ������ ����� ���̴�.
// �� ���� ������� �����մϴ�.

// �ൿ
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    // char[100] = 300����
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

// ��� ������ �ڵ带 ��ġ�� ���ؼ� �����ؿԽ��ϴ�.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status", _Name);
    int nameLineCount = LINECOUNT - strlen(_Name) - strlen(" Status");
    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
    printf_s("���ݷ� : %d\n", _Att);
    printf_s("ü�� : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    // printf_s("---------------------------------------------------\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

// ���Ǹ� ���ؼ� �����ߴٰ� �Ѵ�.
void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

// Ŭ������ �ʿ伺
// �Լ��� �پ��� ��Ȳ���� �����ְ� ������� ����.
// �Լ��� ���� ����� ���� ����� 
// �Լ��� �ѹ��� 1���� ���� �Ҽ��� ����.
// ������ ������ �и��ؾ� �Ѵ�.

void RenderStates()
{
    system("cls");
    PlayerStatusRender();
    MonsterStatusRender();
}

void Damage(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void DamegeRender(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s �� %s�� �����ؼ� %d�� �������� �������ϴ�.\n", _AttName, _DefName, _Att);
}

int main()
{
    char Input = ' ';

    CreatePlayer("1", 10, 100);
    CreateMonster("Orc", 10, 50);

    while (true)
    {
        // screen 1
        RenderStates();
        Input = _getch();

        // screen 2
        Damage(MonsterHp, PlayerAtt);
        RenderStates();
        DamegeRender(PlayerName, MonsterName, PlayerAtt);
        Input = _getch();

        // screen 3
        Damage(PlayerHp, MonsterAtt);
        RenderStates();
        DamegeRender(PlayerName, MonsterName, PlayerAtt);
        DamegeRender(MonsterName, PlayerName, MonsterAtt);
        Input = _getch();

        // end check
        if (0 >= MonsterHp || 0 >= PlayerHp)
            break;
    }

    // game over
    RenderStates();
    printf_s("���� ����");
}
