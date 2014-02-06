#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;

int countDivisors(int);
int plainApproach();
int primeFactor();

void main()
{
	clock_t begin = clock();
	cout<<plainApproach() << endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout<<elapsed_secs << endl;
}

int primeFactor()
{
	return -1;
}

int plainApproach()
{
	int b=1, a=1;
	int divCount = 0;
	int da = 1;
	int db = 1;
	//let's start from 1000th element
	for ( int i = 1000 ; ; i++)
	{
		int a = i + 1;
		if ((a % 2) == 0)
		{
			a = a >> 1;
		}
		
		da = countDivisors(a) + 1;
		
		// +1 in the end to add '1' as a divisor
		divCount = da * db + 1;
		//cout << i << " - " << divCount<< endl;
		if (divCount > 500)
		{
			return a*b;
		}
		db= da;
		b = a;
	}
}

int countDivisors(int num)
{
	int sqrOfNum = sqrt((double) num);
	int count = 0;
	for(int i = 2; i < sqrOfNum; i++)
	{
		if(num % i == 0)
			count+=2;
	}
	if(num % sqrOfNum == 0)
		count ++;
	return count;
}