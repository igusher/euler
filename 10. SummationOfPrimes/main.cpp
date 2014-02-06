#include<iostream>
#include<stdio.h>

using namespace std;

unsigned long long sumPrimes(int limit);
bool eratosthenesPrimeTest(int prime, int* divisors, int len);

void main()
{
	int limit = 485593;
	do {
		cin >> limit;
		cout << sumPrimes(limit) << endl;
		cout<<endl;
	} while(limit != 0);
}

unsigned long long sumPrimes(int limit)
{
	int * primes = new int[500000];
	int n = 1;
	primes[0] = 2;
	unsigned long long int  sum = 2;
	int  i = 3;
	for( ; i < limit; i+=2)
	{
		if(eratosthenesPrimeTest(i, primes, n))
		{
			primes[n] = i;
			n++;
			sum = sum + i;
			//cout<<n << " - " << i << endl;
		}
	}
	delete [] primes;
	return sum;
}

bool eratosthenesPrimeTest(int prime, int* divisors, int len)
{
	int sqrOfPrime = (int)sqrt((double)prime);
	for(int i = 0 ; (i < len) && (divisors[i] <= sqrOfPrime) ; i++)
	{
		if(prime % divisors[i] == 0)
			return false;
	}
	return true;
}