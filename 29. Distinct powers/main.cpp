#include<iostream>
#include<math.h>
#include<memory>

using namespace std;

void main()
{
	bool * powers;
	bool visited[101];
	memset(visited, 0, sizeof(bool)*101);
	unsigned int sum = 0;
	for(int a = 2; a <= 100; a++)
	{
		if(visited[a])
			continue;
		
		int j = 1;
		for(; pow((double)a,j+1) <= 100; j++)
			visited[(int)pow((double)a,j+1)] = true;
		if(j > 1)
		{
			powers = new bool[j * 100 + 1];
			memset(powers, 0 , sizeof(bool) * j * 100 + 1);
		}
		else
		{
			sum += 99;
			continue;
		}
		for(int b = 2; b<=100; b++)
		{
			for(int p = 1; p <= j; p++)
			{
				powers[b*p] = true;
			}
		}
		unsigned int count = 0;
		for(int b = 2;b <= j*100 ; b++)
			count += powers[b];
		sum+= count;

	}
	cout<<sum;

}