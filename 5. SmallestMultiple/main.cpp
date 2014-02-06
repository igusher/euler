#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

void main()
{
	int divisors[21]= {0};
	int newDiv[21];
	memset(divisors, 0, sizeof(int) * 21);
	
	divisors[2] = 1;
	divisors[3] = 1;
	int n = 0;
	int prev = 0;
	for(int i = 4 ; i <= 20; i++)
	{
		n = i;
		memset(newDiv, 0, sizeof(int) * 21);
		prev = 2;
		for(int j = 2; j <= n;)
		{
			if(n % j == 0)
			{
				n = n/j;
				newDiv[j]++;
				j = prev;
			}
			else
			{
				j++;
				prev = j;
			}
		}
		for(int j = 2; j <= i; j++)
		{
			if(newDiv[j] > divisors[j])
				divisors[j] = newDiv[j];
		}
	}

	int result = 1;
	for(int j = 2; j <= 20; j++)
	{
		result *= pow((double)j, divisors[j]);
	}
	cout<<result<<endl;
}
