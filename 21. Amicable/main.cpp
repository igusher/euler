#include<iostream>
#include<stdio.h>

using namespace std;

int sumOfDivisors(int);

void main()
{
	int limit = 10000;
	int p1[100];
	int p2[100];
	int n = 0;
	int sum = 0;
	for(int i = 2 ; i < limit; i ++)
	{
		int n2 = sumOfDivisors(i);
		int n1 = sumOfDivisors(n2);
		if ((i == n1) && (i > n2))
		{
			p1[n] = n1;
			p2[n] = n2;
			sum += n1+n2;
			n++;
		}
	}
	for(int i = 0 ; i < n;i++)
	{
		cout<<p1[i] << " - " << p2[i] << endl;
	}
	cout<<sum;
}

int sumOfDivisors(int num)
{
	if (num < 3) return num;
	int sum = 1;
	int sqrOfNum = sqrt((double) num);
	int count = 1;
	for(int i = 2; i < sqrOfNum; i++)
	{
		if(num % i == 0)
			count += i + (num/i);
	}
	if(num % sqrOfNum == 0)
		count += sqrOfNum;
	return count;
}