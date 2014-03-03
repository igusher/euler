#include<iostream>
#include"..\Common\utils.h"
#include"..\Common\utils.cpp"

using namespace std;
using namespace primes;

int quadraticPrime(int a, int b , int n);
bool isPrime(int num, int * primes, int size);

void main()
{
	const int primesCount = 3000;
	int primes[primesCount];
	primes::eratosthenes(primes, primesCount);
	int maxChain = 0;
	int abProd = 0;
	for(int a = -999 ; a < 1000; a+=2)
		for(int b = -999; b <1000; b+=2)
		{
			int n = 0;
			for(; isPrime(quadraticPrime(a,b,n),primes, primesCount); n++);
			if(maxChain < n)
			{
				maxChain = n;
				abProd = a * b;
			}

		}

	cout<<abProd<< " " << maxChain << endl;
}

int quadraticPrime(int a, int b , int n)
{
	return n*n + a * n + b;
}

bool isPrime(int num, int * primes , int size)
{
	//if num is found in *primes return true => num - prime
	return search::binarySearch(primes,size,num) != -1;
}