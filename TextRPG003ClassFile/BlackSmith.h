#pragma once
#include "Zone.h"

class BlackSmith
{
public:
	// 안넣어주면 생성이 안되.
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

// 확률은 전부다 2분의 1
// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.
// 1~5까지는 실패가 실패확률은 있지만.
// 다운되지는 않는다.
// 6~10까지는 실패하면 1씩 다운된다.
// 10~15는 0으로 실패하면 0으로 떨어진다.
// 15강 이상이면 강화를 못하게 해야해한다.