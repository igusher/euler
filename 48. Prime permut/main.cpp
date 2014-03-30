#include<iostream>
#include<algorithm>
#include "..\Common\utils.cpp"

using namespace std;

int getDigit(int num, int dig)
{
	return (num / (int)pow(10.,dig)) % 10;
}
void myswap(int * num, int i,  int j)
{
	num[i] = num[j] + num[i];
	num[j] = num[i] - num[j];
	num[i] = num[i] - num[j];
}


int compare(const void * a, const void * b)
{
	return *(int*)a - *(int *)b;
}

int nextPermute(int num, int len)
{
	int maxD = getDigit(num , 0 );
	int maxPos = 0;
	/*for(int i = 1 ; i <= log10((double)num); i++)
	{
		int d2 = getDigit(i);
		if(d2 > 
		if(
	}*/
	return 1;
}




bool nextPerm(int * num , int len)
{
	for(int i = len -2; i >=0; i--)
	{
		if(num[i] < num[i+1])
		{
			int min = num[i+1];
			int minPos = i+1;
			for(int j = i+2 ; j < len; j++)
			{
				if((min>num[j]) && (num[j] > num[i]))
				{
					min = num[j];
					minPos = j;
				}
			}
			myswap(num,i,minPos);
			qsort(&num[i+1], len-1 - i, sizeof(int),compare);
			return true;
		}
	}
	return false;
}

int getInt(int *num , int len)
{
	int result = 0;
	for(int i = 0 ; i < len ; i++)
	{
		result *= 10;
		result += num [i];
	}
	return result;
}

bool isPermutation(int a, int b)
{
	int aa = 0;
	int bb = 0;

	while(a >0)
	{
		aa += 1 << ((a %10) -1);
		a /=10;
	}
	while(b >0)
	{
		bb += 1 << ((b %10) -1);
		b /=10;
	}
	return aa == bb;
}
void main()
{
	int num[] = {0,1,2,3};
	getInt(num,4);
	nextPerm(num,4);
	/*for(int i = 0 ; i < 24; i++)
	{
		if(nextPerm(num,4))
		{
		for(int j = 0 ; j < 4; j++)
			cout<<num[j];
		cout <<endl;
		}
	}*/

	const int len = 10000;
	bool primes2[len];
	timer::start();
	primes::eratBool2(primes2, len);
	cout << timer::finish()<< endl;

	int primeCount = 0;
	for(int i = 1001; i < 10000; i++)
	{
		if(primes2[i])
		{
			bool ok = true;
			for(int j = 1 ; j <= 2 ; j++)
			{
				int next = 3330*j + i;
				if (next > 10000)
				{
					ok = false;
					break;
				}

				if(!(primes2[next]) || !isPermutation(i,next))
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				cout << i;
			}
		}
	}
}