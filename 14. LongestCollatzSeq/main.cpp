#include<iostream>
#include<stdio.h>

using namespace std;

unsigned long next(unsigned long);
unsigned long nextEven(unsigned long);
unsigned long nextOdd(unsigned long);
	
void main()
{
	const int limit = 1000000;
	bool nums[limit];
	memset(nums,0,sizeof(bool)*limit);
	unsigned long nextN = -1;
	int maxChainLen = -1;
	int chainLen = -1;
	int chainRoot = -1;
	int maxChainRoot = -2;
	for(int i = limit - 1; i > 0; i--)
	{
		if(!nums[i])
		{
			chainLen = 0;
			chainRoot = i;
			nextN = i;
			do{
				if(next(nextN) < 0)
					cout<<"";
				nextN = next(nextN);
				chainLen++;
				if (nextN < limit)
					nums[nextN] = true;

			} while(nextN != 1);
			if (chainLen > maxChainLen)
			{
				maxChainLen = chainLen;
				maxChainRoot = chainRoot;
			}
		}
	}

	cout << maxChainRoot;

}

unsigned long next(unsigned long num)
{
	if ((num & 1) == 0)
		return nextEven(num);
	return nextOdd(num);
}

unsigned long nextEven(unsigned long num)
{
	return num/2;
}

unsigned long nextOdd(unsigned long num)
{
	return num*3 + 1;
}
