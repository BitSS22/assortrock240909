#include <iostream>
#include <Windows.h>
#include <vector>
#include <map>
#include <random>

using std::cout;
using std::endl;
using std::map;
using std::make_pair;
using std::vector;


int main()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution dist;
	
	while (true)
	{
		int seed = time(nullptr);
		srand(seed);
		std::cout << rand() << std::endl;
	}
	
	

	return 0;
}
