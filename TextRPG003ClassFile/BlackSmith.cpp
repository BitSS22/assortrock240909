#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
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
		std::cout << "�ִ� ��ȭ ��ġ�Դϴ�." << std::endl;
		return;
	}

	int PlayerEquip = _Player.GetEquipAtt();
	int needGold = (PlayerEquip + 1) * 100;

	if (_Player.GetGold() < needGold)
	{
		std::cout << "��尡 �����մϴ�." << std::endl;
		return;
	}

	bool Succese = rand() & 1;


	if (Succese)
	{
		std::cout << "�ټ����� �Ͽ����ϴ�." << std::endl;
		_Player.SetEquipAtt(++PlayerEquip);
	}
	else if (5 > PlayerEquip)
	{
		std::cout << "���� �Ͽ����ϴ�." << std::endl;
	}
	else if (10 > PlayerEquip)
	{
		std::cout << "���� �Ͽ����ϴ�." << std::endl << "��ȭ �ܰ谡 1�ܰ� �������ϴ�." << std::endl;
		_Player.SetEquipAtt(--PlayerEquip);
	}
	else if (15 > PlayerEquip)
	{
		std::cout << "���� �Ͽ����ϴ�." << std::endl << "��ȭ �ܰ谡 �ʱ�ȭ �˴ϴ�." << std::endl;
		_Player.SetEquipAtt(0);
	}

	std::cout << needGold << "Gold ����." << std::endl;
	_Player.SetGold(_Player.GetGold() - needGold);
}
