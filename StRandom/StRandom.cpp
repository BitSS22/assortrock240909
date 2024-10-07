// StRandom.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int Arr[20];

	for (int i = 0; i < 20; i++)
	{
		Arr[i] = i;
	}

	// 8바이트
	__int64 Value = time(0);
	srand(Value);

	// [0][1][2][10][4][5][6][7][8][9]
	// [10][11][12][13][14][15][16][17][18][19]
	// 3;

	for (int i = 0; i < 1000; i++)
	{
		// 나머지법
		// 0에서부터 19까지 나오게하려면 %(모드) 20
		int Left = rand() % 20;
		int Right = rand() % 20;

		//           3
		int Temp = Arr[Left];
		// 3         10
		Arr[Left] = Arr[Right];
		// 10
		Arr[Right] = Temp;
	}
    

	int Result = Arr[0];

	
	int a = 0;
}
