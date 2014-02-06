#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;

void main()
{
	clock_t begin = clock();
	
	
	char addNum[500];
	char number[500];
	memset(number,0,sizeof(char)*500);
	const int power = 1000;
	const int base = 2;
	number[0] = 2;
	int numLength = 1;
	int remId =0;
	for(int i = 2 ; i <= power; i++)
	{
		memcpy(addNum,number,sizeof(char)*numLength);
		int remainder = 0;
		for(int j = 0; j < numLength; j++)
		{
			remainder += number[j] + addNum[j];
			number[j] = remainder % 10;
			remainder = remainder / 10;
			remId++;
		}
		while(remainder > 0)
		{
			number[numLength] = remainder % 10;
			remainder = remainder / 10;
			numLength++;
		}
	}
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout<<elapsed_secs << endl;
	int sum = 0;
	for(int i = numLength ; i >=0; i--)
	{
		cout << (int)number[i] ;
		sum += number[i];
	}

	cout<< endl << sum << endl;
}