#include <iostream>

using namespace std;

long long fact(int num)
{
	long long res = num;
	for(int i = 2 ; i < num; i++)
		res *= i;
	return res;
}

long long factFrom(int num, int from)
{
	long long res = num;
	for(int i = from ; i < num; i++)
		res *= i;
	return res;
}

void main()
{
	const int threshold = 1000000;
	const int limit = 100;

	int count = 0;
	for(int n = 1 ; n <= limit ; n++)
	{

		for(int r = n-2; r >= n/2 ; r--)
		{
			if((factFrom(n,r+1) / fact(n-r)) >= threshold)
			{
				count+= (r - n/2) * 2 + (n+1)%2;
				break;
			}
		}
	}
	cout<<count<<endl;

}