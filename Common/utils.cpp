#include "utils.h"
#include<memory>

using namespace primes;

bool primes::isPrime(int num)
{
	if(num < 2 ) return false;
	if(num == 2) return true;
	if(num % 2 == 0) return false;
	int maxDiv = sqrt((double)num);
	for(int i = 3 ; i <= maxDiv; i+=2)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}

void primes::eratBool(bool * primesBool, int limit)
{
	int *primes = new int[limit/4];
	int size = eratLimit(primes,limit, limit/4);
	if(size == 0)
		throw "not enough array size";
	memset(primesBool,0,sizeof(bool)*limit);
	for(int i = 0; i < size;i++)
	{
		primesBool[primes[i]] = true;
	}
	delete [] primes;
}

int primes::eratLimit(int * primes, int limit, int size)
{
	int n = 1;
	primes[0] = 2;
	for( int i = 3 ; i < limit; i+=2)
	{
		if(primes::completePrimeTest(i, primes, n))
		{
			primes[n] = i;
			n++;
			if(n == size)
				return 0;
		}
	}
	return n;
}

void primes::eratosthenes(int * primes, int size)
{
	int n = 1;
	primes[0] = 2;
	for( int i = 3 ; n < size;i+=2)
	{
		if(primes::completePrimeTest(i, primes, n))
		{
			primes[n] = i;
			n++;
		}
	}
}


bool pandigital::isPandigital(int num, int digits)
{
	//number doesn't contain all digits
	if(log10((double)num)+1 < digits)
		return false;
	int res = 0;
	while(num >0)
	{
		res += 1 << ((num %10) -1);
		num /=10;
	}
	if( res == ((1 << digits) - 1))
		return true;

	return false;

}

bool primes::completePrimeTest(int prime, int* divisors, int len)
{
	for(int i = 0 ; i < len ; i++)
	{
		if(prime % divisors[i] == 0)
			return false;
	}
	return true;
}

int search::binarySearch(int * arr, int size, int elem)
{
	return binarySearch(arr,size,0,size-1,elem);
}

int search::binarySearch(int * arr, int size, int l, int r, int elem)
{
	if(l>r)
		return -1;
	if(l == r)
	{
		if(elem == arr[l])
			return l;
		else
			return -1;
	}

	int middleId = (l+r) / 2;
	if(elem == arr[middleId])
		return middleId;
	if(elem > arr[middleId])
		return search::binarySearch(arr, size, middleId+1, r, elem);
	return search::binarySearch(arr, size, l, middleId-1, elem);
}

void integers::rotateLeft(int& num, int digits)
{
	
	num*=10;
	num += num / pow(10.,digits);
	num %= (int)pow(10.,digits);
}

void timer::start()
{
	startTime = std::clock();
}

long timer::finish()
{
	return (long)( std::clock() - startTime );
}