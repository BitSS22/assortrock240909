#include <iostream>

const int NAMELEN = 10;

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;

};

class FightUnit : public StatusUnit
{
public:
    int GetDamage() const
    {
        return rand() % (MaxAtt + 1 - MinAtt) + MinAtt;
    }

    void DamageLogic(const FightUnit& _AttUnit)
    {
        Hp -= _AttUnit.GetDamage();
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    const char* GetName() const
    {
        return Name;
    }

private:
};

class Player : public FightUnit
{
};

class Monster : public FightUnit
{
};

int main()
{
    srand(time(nullptr));

    Player NewPlayer;
    Monster NewMonster;
    NewMonster.DamageLogic(NewPlayer);

    for (size_t i = 0; i < 5000; i++)
        std::cout << NewPlayer.GetDamage() << ' ';

    return 0;
}
