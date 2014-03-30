#include<iostream>
#include "..\Common\utils.cpp"

using namespace std;

void main()
{
	const int len = 1000000;
	bool prime[len];
	primes::eratBool2(prime, len);

	int last = 0;
	int sum = 2;
	int primeCount = 0;
	for(int i = 3 ; i < len ; i+=2)
	{
		if(prime[i])
			primeCount++;	
	}
	
	//+2 - '0' and '2'
	int * sums = new int[primeCount+2];
	sums[0] = 0;
	sums[1] = 2;
	int count = 2;
	for(int i = 3; i < len ; i++)
		if(prime[i])
		{
			sums[count]= sums[count-1] + i;
			count++;
		}

	int upperLimit = 0;
	int maxChain = 0;
	int maxChainPrime = 0;
	for(int i = primeCount - 1; i >= upperLimit ; i--)
	{
		for(int j = i-1; j >= 0; j--)
		{
			int consecSum = sums[i] - sums[j];
			if(consecSum >= len)
				break;
			if(prime[consecSum])
			{
				int chainLen = i-j;
				if(maxChain < chainLen)
				{
					maxChain = chainLen;
					maxChainPrime = consecSum;
					upperLimit = maxChain;
				}

			}
		}
	}

	cout << maxChainPrime << " " << maxChain;
}