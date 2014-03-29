#include "..\Common\utils.h"
#include "..\Common\utils.cpp"
#include<iostream>
#include <math.h>
using namespace std;

void main()
{
	int sum = 0;
	int count = 0;
	int limit = 1000000;
	int * primes = new int[100000];
	int size = primes::eratLimit(primes, 1000000, 100000);
	
	bool * primesBool = new bool[limit];
	memset(primesBool,0,sizeof(bool)*limit);
	for(int i = 0; i < size;i++)
	{
		primesBool[primes[i]] = true;
	}

	for(int i = 0 ; i < size ; i++)
	{
		if(primes[i] < 10) continue;
		bool isTruncable = true;
		int temp = primes[i];temp /= 10;
		do
		{
			
			if(!primesBool[temp])
			{
				isTruncable = false;
				break;
			}
			temp /= 10;
		}while(temp > 0);
		
		temp = primes[i];
		temp %= (int) pow(10., (int)log10((double)temp));
		do
		{
			
			if(!primesBool[temp])
			{
				isTruncable = false;
				break;
			}
			temp %= (int) pow(10., (int)log10((double)temp));
		}while(temp > 0);

		if(isTruncable)
		{
			sum += primes[i];
			count ++;
			if(count == 11) 
			{
				cout<<sum;
				break;
			}
			cout << primes[i] << endl;
		}
	}


	delete [] primesBool;

	delete []primes;
}