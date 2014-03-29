#include<iostream>

#include"..\Common\utils.cpp"

using namespace std;


long long pentagonal(long long n)
{
	return n*(3*n - 1) / 2;
}

bool isPentagonal(long long num)
{
	long long n = (sqrt((double)(1+ 24 * num)) + 1) / 6;
	return pentagonal(n) == num;
}

int closestPent(long long num)
{
	if(num < 0)
		return 1;
	long long n = (sqrt((double)(1+ 24 * num)) + 1) / 6;
	if (n == 0)
		return 1;
	if ( pentagonal(n) != num);
		return n+1;
	return n;
}


void main()
{
	timer::start();
	int i = 1;
	long long minDiff = (1 << 31) - 1;
	for(int n = 2; n < 10000; n++)
	{
		long long  n1 =pentagonal(n);
		int i = closestPent(n1 - minDiff);
		if(i == n)
			break;
		for( ; i < n ; i++)
		{
			
			int n2 = pentagonal(i);
			int diff = n1-n2;
			int sum = n1 + n2;
			if((diff < minDiff) && (isPentagonal(diff)) && (isPentagonal(sum)))
			{
				minDiff = diff;
			}
		}
	}
	cout<<"time: "<<timer::finish() << endl;
	cout << minDiff << endl;
}