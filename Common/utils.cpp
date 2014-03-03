#include "utils.h"
using namespace primes;

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