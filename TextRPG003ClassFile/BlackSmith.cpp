#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
			Enhance(_Player);
			_getch();
			break;
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::Enhance(UPlayer& _Player)
{
	if (15 <= _Player.GetEquipAtt())
	{
		std::cout << "최대 강화 수치입니다." << std::endl;
		return;
	}

	int PlayerEquip = _Player.GetEquipAtt();
	int needGold = (PlayerEquip + 1) * 100;

	if (_Player.GetGold() < needGold)
	{
		std::cout << "골드가 부족합니다." << std::endl;
		return;
	}

	bool Succese = rand() & 1;


	if (Succese)
	{
		std::cout << "☆성공☆ 하였습니다." << std::endl;
		_Player.SetEquipAtt(++PlayerEquip);
	}
	else if (5 > PlayerEquip)
	{
		std::cout << "실패 하였습니다." << std::endl;
	}
	else if (10 > PlayerEquip)
	{
		std::cout << "실패 하였습니다." << std::endl << "강화 단계가 1단계 내려갑니다." << std::endl;
		_Player.SetEquipAtt(--PlayerEquip);
	}
	else if (15 > PlayerEquip)
	{
		std::cout << "실패 하였습니다." << std::endl << "강화 단계가 초기화 됩니다." << std::endl;
		_Player.SetEquipAtt(0);
	}

	std::cout << needGold << "Gold 감소." << std::endl;
	_Player.SetGold(_Player.GetGold() - needGold);
}
