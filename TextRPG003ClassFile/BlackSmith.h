#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	// �ȳ־��ָ� ������ �ȵ�.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

	void Enhance(UPlayer& _Player);

private:
	// class UZone& ParentZone;

	class UZone* ParentZone = nullptr;
};

// Ȯ���� ���δ� 2���� 1
// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
// 1~5������ ���а� ����Ȯ���� ������.
// �ٿ������ �ʴ´�.
// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
// 10~15�� 0���� �����ϸ� 0���� ��������.
// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.