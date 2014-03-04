#include <iostream>
#include <fstream>
#include<memory.h>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	const int coinsCount = 8;
	int change[201];
	int coins[coinsCount] = {1,2,5,10,20,50,100,200};
	int money = 200;
	memset(change, 0, sizeof(int) * (money +1));

	change[0] = 1;
	change[1] = 0;
	for(int c = 0; c < coinsCount; c++)
	{
		for(int m = coins[c]; m <= money; m++)
		{
			change[m] += change[m-coins[c]];
		}
	}
	cout<<change[money] << endl;

	return 0;
}
