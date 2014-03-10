#include<iostream>

using namespace std;

int fact(int num)
{
	int result = 1;
	for(int i = 2; i <= num; i++)
	 result *= i;
	return result;
}

int main()
{
	long long sum =0;
	for(int a = 11 ; a <999999; a++)
	{
		int next = 0;
		int temp = a;
		while(temp > 0)
		{
			next += fact(temp%10);
			temp /= 10;
		}
		if(next == a)
		{
			sum += a;
			cout << a << endl;		
		}
	}
	cout << sum;
	return 0;
}
