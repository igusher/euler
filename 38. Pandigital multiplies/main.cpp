#include<iostream>
#include"../Common/utils.h"
#include"../Common/utils.cpp"


using namespace std;

void main()
{
	int max = 0;
	for(int n = 2 ; n < 9; n++)
	{
		int i = 1;
		unsigned int num = 0;
		do{
			num = 0;
			for(int j = 1;j <= n ; j++)
			{
				int next = i * j;
				num *= pow(10., (int)log10((double)next)+1);
				num+=next;
			}
			if(pandigital::isPandigital(num,9))
			{
				if(max < num)
					max = num;
			}
			i++;
		}while(num < 987654321);
	}
	cout<<max;
}