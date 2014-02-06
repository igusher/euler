#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

void main()
{
	double c = 0;
	for(int i = 100; i < 500; i++)
		for(int j = i+1; j < 500; j++)
		{
			c = sqrt((double)i*i + j*j);
			if(i+j+c == 1000)
			{
				cout<< i << " " << j << " " << c << endl;
				cout<< i * j * c << endl;
			}
		}

	cout<<"-1";
}