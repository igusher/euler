#include<iostream>
#include<math.h>

using namespace std;

long long triangle(long long n)
{
	return n * (n+1) / 2;
}

bool isTriangle(long long num)
{
	int n = (sqrt((double)(1 + 8*num)) - 1) / 2;
	return triangle(n) == num;
}

long long pentagonal(long long n)
{
	return n*(3*n - 1) / 2;
}

bool isPentagonal(long long num)
{
	long long n = (sqrt((double)(1+ 24 * num)) + 1) / 6;
	return pentagonal(n) == num;
}

long long hexagonal(long long n)
{
	return n * (2*n - 1);
}



int main()
{
	for(int i = 144; i < 500000; i++)
	{
		long long  next = hexagonal(i);
		if(isPentagonal(next) && isTriangle(next))
		{
			cout <<next;
			break;
		}
	}
	return 0;

}