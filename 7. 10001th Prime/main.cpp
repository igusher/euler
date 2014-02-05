#include<iostream>
#include<stdio.h>
#include<math.h>
#include<ctime>

using namespace std;

bool isPrime(int);
bool chinesePrimeTest(int);
bool fermatPrimeTest(int);
bool completePrimeTest(int, int*, int);
bool millerRabinTest(int);

int eratosthenes(int limit);

void main()
{
	//find 10001^th prime
	clock_t begin = clock();
	int n = 10001;
	int prime = eratosthenes(n);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout<<elapsed_secs << endl;
	cout << prime;

/*
	for(int i = 6; i < n; prime+=2)
	{
		if(isPrime(prime))
		{
			i++;
			cout<<i << " - " << prime << endl;
		}
	}
	cout << prime << endl;
	*/
}

int eratosthenes(int limit)
{
	int n = 1;
	int primes[10001];
	primes[0] = 2;
	for( int i = 3 ; n < limit;i+=2)
	{
		if(completePrimeTest(i, primes, n))
		{

			primes[n] = i;
			n++;
			//cout<<n << " - " << i << endl;
		}
	}
	return primes[10000];
}

bool completePrimeTest(int prime, int* divisors, int len)
{
	for(int i = 0 ; i < len ; i++)
	{
		if(prime % divisors[i] == 0)
			return false;
	}
	return true;
}

bool isPrime(int prime)
{
	//return millerRabinTest(prime);
	return chinesePrimeTest(prime) && fermatPrimeTest(prime) && millerRabinTest(prime);
}

bool chinesePrimeTest(int prime)
{
	int p = 1;
	for(int i = 0 ; i < prime-1; i++)
		p = (p * 2) % prime;

	return p == 1;
}

bool fermatPrimeTest(int prime)
{
	//a^(p-1) = 1 (mod p)
	//a - 3
	int a1 = 3; 
	int r1 = 1;
	for(int i = 0 ; i < prime-1; i++)
		r1 = (r1 * a1) % prime;

	return r1 == 1;
}

bool millerRabinTest(int prime)
{
	int m = prime - 1;
	int s=0;
	int d = prime - 1;
	do{
		d = d >> 1;
		++s;
	} while((d & 1) == 0);
	
	//2 rounds
	bool flag = false;
	int x;
	for(int a = 3; a<=7; a=a+2)
	{
		x = 1;
		flag = false;
		for(int i = 0; i < d; i++)
			x = (x * a )% prime;
		if ((x == 1) || (x == m)) continue;
		for(int j = 0; j < s; j++)
		{
			x = (x * x) % prime;
			if ( x == 1 ) return false;
			if ( x == m ) {
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}
