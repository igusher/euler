#include<iostream>

using namespace std;

void main()
{
	const int size = 1001;
	unsigned long sum = size * size;
	int current = sum;
	for(int i = 0 ; i < (size*2 - 1) / 4;i++)
	{
		for(int j = 0 ; j < 4; j++)
		{
			current = current - ((size - 1) - i * 2);
			sum += current;
		}
	}
	cout << sum << endl;
}