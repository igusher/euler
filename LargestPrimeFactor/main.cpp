#include<iostream>
#include<stdio.h>

using namespace std;

bool isPrime(int);

void main()
{
	__int64 number = 600851475143;
	int result = 1;
	__int64 until = number/6;
	for(int i = 7; i <= number; i=i+2)
	{
		if (number % i == 0)
		{
			number /= i;
			if (isPrime(i) && result < i)
			{
				result = i;
			}
		}
	}
	cout << result;
}

bool isPrime(int number)
{ 
	int maxDivisor = sqrt((double)number);
	int dividendIndex = 1;
	int dividend = 5;
	for(int i = 3; i <= maxDivisor; i=i+2)
	{
		if(number % i == 0)
			return false;
	}
	return true;
}